// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//  File: avtSurfaceNormalFilter.h
// ************************************************************************* //

#ifndef AVT_SurfaceNormal_FILTER_H
#define AVT_SurfaceNormal_FILTER_H


#include <avtPluginFilter.h>
#include <avtDeferExpressionBaseFilter.h>
#include <SurfaceNormalAttributes.h>


class vtkDataSet;


// ****************************************************************************
//  Class: avtSurfaceNormalFilter
//
//  Purpose:
//      A plugin operator for SurfaceNormal.
//
//  Programmer: hchilds -- generated by xml2avt
//  Creation:   Thu Sep 23 14:25:44 PST 2010
//
// ****************************************************************************

class avtSurfaceNormalFilter : virtual public avtPluginFilter,
                               virtual public avtDeferExpressionBaseFilter
{
  public:
                         avtSurfaceNormalFilter();
    virtual             ~avtSurfaceNormalFilter();

    static avtFilter    *Create();

    virtual const char  *GetType(void)  { return "avtSurfaceNormalFilter"; };
    virtual const char  *GetDescription(void)
                             { return "SurfaceNormal"; };

    virtual void         SetAtts(const AttributeGroup*);
    virtual bool         Equivalent(const AttributeGroup*);

  protected:
    SurfaceNormalAttributes   atts;
    std::string               varname;

    virtual void              InferVariableNameFromContract(avtContract_p);
    virtual void              GetCustomExpressions(std::vector<Expression> &);
    virtual void              GetVariablesToEvaluate(std::vector<std::string> &);

    virtual void              UpdateDataObjectInfo(void);
};


#endif


