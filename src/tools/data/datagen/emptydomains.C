// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// Programmer: Jeremy Meredith
// Date:       June  7, 2005
//
// Purpose:    Make a dataset with empty domains, using the
//             new "EMPTY" keyword for the multi-objects.
//
//
// Modifications:
//
//   Mark C. Miller, Mon Jan 25 16:44:01 PST 2010
//   Made it work with either silo driver.

#include <silo.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// suppress the following since silo uses char * in its API
#if defined(__clang__)
# pragma clang diagnostic ignored "-Wwritable-strings"
#elif defined(__GNUC__)
# pragma GCC diagnostic ignored "-Wwrite-strings"
#endif

#define NX 12
#define NY 4
#define NZ 8
#define NPTS (NX*NY*NZ)
#define NZONES ((NX-1)*(NY-1)*(NZ-1))

int main(int argc, char **argv)
{
    int driver = DB_PDB;
    int i = 1;
    while (i < argc)
    {
        if (strcmp(argv[i], "DB_HDF5") == 0)
            driver = DB_HDF5;
        else if (strcmp(argv[i], "DB_PDB") == 0)
            driver = DB_PDB;
        else
           fprintf(stderr,"Uncrecognized driver name \"%s\"\n", argv[i]);
        i++;
    }

    char *meshnames[2] = { "EMPTY", "domain1/mesh" };
    int meshtypes[2] = { DB_QUADMESH, DB_QUADMESH };

    char *varnames[2] = { "EMPTY", "domain1/density" };
    int vartypes[2] = { DB_QUADVAR, DB_QUADVAR };

    char *matnames[2] = { "EMPTY", "domain1/mat" };

    char *specnames[2] = { "EMPTY", "domain1/spec" };

    int matnos[2] = {1, 5};
    int nmatspec[2] = {1, 2};
    float specmf[4] = {.1, .9, .4, .6};
    int *matlist;
    int *speclist;
    float *x, *y, *z, *v;
    float *coords[3];
    DBfile *db;
    int dims[3], zdims[3];
    int ndims;
    DBoptlist *opt;

    x = new float[NX];
    y = new float[NY];
    z = new float[NZ];
    v = new float[NPTS];
    matlist = new int[NZONES];
    speclist = new int[NZONES];
    coords[0] = x;
    coords[1] = y;
    coords[2] = z;

    for (i = 0 ; i < NX; i++)
        x[i] = i;

    for (i = 0 ; i < NY; i++)
        y[i] = i;

    for (i = 0 ; i < NZ; i++)
        z[i] = i;
    
    for (i = 0 ; i < NPTS; i++)
        v[i] = sqrt((float)(i));

    for (i = 0 ; i < NZONES; i++)
    {
        int matindex = (i/17)%2;
        matlist[i] = matnos[matindex];
        speclist[i] = matindex == 0 ? 0 : ((i > (NZONES/2)) ? 1 : 3);
    }

    dims[0] = NX;
    dims[1] = NY;
    dims[2] = NZ;
    zdims[0] = NX-1;
    zdims[1] = NY-1;
    zdims[2] = NZ-1;
    ndims = 3;

    db = DBCreate("emptydomains.silo", DB_CLOBBER, DB_LOCAL, "test empty domains", driver);

    DBMkDir(db, "domain1");
    DBSetDir(db, "domain1");
    DBPutQuadmesh(db, "mesh", NULL, coords, dims, ndims,
                  DB_FLOAT, DB_COLLINEAR, NULL);

    DBPutQuadvar1(db, "density", "mesh", v, dims, ndims, NULL,0,
                  DB_FLOAT, DB_NODECENT, NULL);
    DBPutMaterial(db, "mat", "mesh", 2,matnos, matlist, zdims, ndims, NULL,NULL,NULL,NULL,0,
                  DB_FLOAT, NULL);

    DBPutMatspecies(db, "spec", "mat", 2,nmatspec, speclist, zdims, ndims, 4,specmf, NULL,0,
                    DB_FLOAT, NULL);
    DBSetDir(db, "..");

#if 1
    DBPutMultimesh(db, "mesh", 2, meshnames, meshtypes, NULL);
    DBPutMultivar(db, "density", 2, varnames, vartypes, NULL);
    DBPutMultimat(db, "mat", 2, matnames, NULL);

    opt = DBMakeOptlist(1);
    char *matname = "mat";
    DBAddOption(opt, DBOPT_MATNAME, matname);
    DBPutMultimatspecies(db, "spec", 2, specnames, opt);
#endif

    DBClose(db);

    return 0;
}
