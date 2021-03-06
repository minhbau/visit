// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                             avtDatasetSource.C                            //
// ************************************************************************* //

#include <avtDatasetSource.h>


// ****************************************************************************
//  Method: avtDatasetSource constructor
//
//  Programmer: Hank Childs
//  Creation:   May 29, 2001
//      
// ****************************************************************************

avtDatasetSource::avtDatasetSource()
{
    dataset = new avtDataset(this);
}


// ****************************************************************************
//  Method: avtDatasetSource destructor
//
//  Purpose:
//      Defines the destructor.  Note: this should not be inlined in the header
//      because it causes problems for certain compilers.
//
//  Programmer: Hank Childs
//  Creation:   February 5, 2004
//
// ****************************************************************************

avtDatasetSource::~avtDatasetSource()
{
    ;
}


// ****************************************************************************
//  Method: avtDatasetSource::GetOutput
//
//  Purpose:
//      Returns the dataset as a base type data object, with ref_ptr type
//      issues resolved.
//
//  Returns:    This source's dataset, typed as a data object.
//
//  Programmer: Hank Childs
//  Creation:   May 29, 2001
//
//  Modifications:
//    Brad Whitlock, Thu Apr 4 14:59:26 PST 2002
//    Changed CopyTo so it is an inline template function.
//
// ****************************************************************************

avtDataObject_p
avtDatasetSource::GetOutput(void)
{
    avtDataObject_p rv;
    CopyTo(rv, dataset);

    return rv;
}


// ****************************************************************************
//  Method: avtDatasetSource::SetOutputDataTree
//
//  Purpose:
//      Uses avtDatasetSource's friend status with avtDataset to set the top
//      level data tree.  This is defined so any of the derived types can take
//      advantage of the base type's friend status.
//
//  Arguments:
//      dt      The avtDataTree object that makes up the output.
//
//  Programmer: Hank Childs
//  Creation:   July 24, 2000
//
// ****************************************************************************

void
avtDatasetSource::SetOutputDataTree(const avtDataTree_p dt)
{
    dataset->SetDataTree(dt);
}


