// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                          avtMultiCurvePlot.C                              //
// ************************************************************************* //

#include <avtMultiCurvePlot.h>

#include <avtColorTables.h>
#include <avtLevelsLegend.h>
#include <avtLevelsMapper.h>
#include <avtLookupTable.h>
#include <avtMultiCurveFilter.h>
#include <avtMultiCurveLabelMapper.h>

#include <ColorAttribute.h>
#include <InvalidColortableException.h>

#include <string>
#include <vector>

// ****************************************************************************
//  Method: avtMultiCurvePlot constructor
//
//  Programmer: xml2avt
//  Creation:   omitted
//
//  Modifications:
//    Eric Brugger, Fri Feb 20 16:21:57 PST 2009
//    I added a legend to the plot.
//
// ****************************************************************************

avtMultiCurvePlot::avtMultiCurvePlot()
{
    MultiCurveFilter = new avtMultiCurveFilter(atts);

    levelsMapper     = new avtLevelsMapper;
    levelsLegend     = new avtLevelsLegend;
    decoMapper       = new avtMultiCurveLabelMapper();
    avtLUT           = new avtLookupTable;

    //
    // Set some legend properties.
    //
    levelsLegend->SetColorBarVisibility(0);
    levelsLegend->SetTitleVisibility(1);
    levelsLegend->SetLookupTable(avtLUT->GetLookupTable());

    //
    // This is to allow the legend to reference counted so the behavior can
    // still access it after the plot is deleted.  The legend cannot be
    // reference counted all of the time since we need to know that it is a
    // levelsLegend.
    //
    levelsLegendRefPtr = levelsLegend;
}


// ****************************************************************************
//  Method: avtMultiCurvePlot destructor
//
//  Programmer: xml2avt
//  Creation:   omitted
//
//  Modifications:
//    Eric Brugger, Fri Feb 20 16:21:57 PST 2009
//    I added a legend to the plot.
//
// ****************************************************************************

avtMultiCurvePlot::~avtMultiCurvePlot()
{
    if (levelsMapper != NULL)
    {
        delete levelsMapper;
        levelsMapper = NULL;
    }
    if (decoMapper != NULL)
    {
        delete decoMapper;
        decoMapper = NULL;
    }
    if (MultiCurveFilter != NULL)
    {
        delete MultiCurveFilter;
        MultiCurveFilter = NULL;
    }
    if (avtLUT != NULL)
    {
        delete avtLUT;
        avtLUT = NULL;
    }

    //
    // Do not delete the levelsLegend since it is being held by
    // levelsLegendRefPtr.
    //
}


// ****************************************************************************
//  Method:  avtMultiCurvePlot::Create
//
//  Purpose:
//    Call the constructor.
//
//  Programmer: xml2avt
//  Creation:   omitted
//
// ****************************************************************************

avtPlot*
avtMultiCurvePlot::Create()
{
    return new avtMultiCurvePlot;
}


// ****************************************************************************
//  Method: avtMultiCurvePlot::GetMapper
//
//  Purpose:
//      Gets a mapper for this plot, it is actually a variable mapper.
//
//  Returns:    The variable mapper typed as its base class mapper.
//
//  Programmer: xml2avt
//  Creation:   omitted
//
// ****************************************************************************

avtMapperBase *
avtMultiCurvePlot::GetMapper(void)
{
    return levelsMapper;
}


// ****************************************************************************
//  Method: avtMultiCurvePlot::GetDecorationsMapper
//
//  Purpose:
//      Gets a decorations mapper for this plot, in this case the
//      labeled curve mapper.
//
//  Returns:    The labeled curve mapper typed as its base class mapper.
//
//  Programmer: Eric Brugger
//  Creation:   December 12, 2008
//
// ****************************************************************************

avtDecorationsMapper *
avtMultiCurvePlot::GetDecorationsMapper(void)
{
    return decoMapper;
}


// ****************************************************************************
//  Method: avtMultiCurvePlot::ApplyOperators
//
//  Purpose:
//      Applies the operators associated with a MultiCurve plot.  
//      The output from this method is a query-able object.
//
//  Arguments:
//      input   The input data object.
//
//  Returns:    The data object after the MultiCurve plot has been applied.
//
//  Programmer: xml2avt
//  Creation:   omitted
//
// ****************************************************************************

avtDataObject_p
avtMultiCurvePlot::ApplyOperators(avtDataObject_p input)
{
    MultiCurveFilter->SetInput(input);
    return MultiCurveFilter->GetOutput();
}


// ****************************************************************************
//  Method: avtMultiCurvePlot::ApplyRenderingTransformation
//
//  Purpose:
//      Applies the rendering transformation associated with a MultiCurve plot.
//
//  Arguments:
//      input   The input data object.
//
//  Returns:    The data object after the MultiCurve plot has been applied.
//
//  Programmer: xml2avt
//  Creation:   omitted
//
// ****************************************************************************

avtDataObject_p
avtMultiCurvePlot::ApplyRenderingTransformation(avtDataObject_p input)
{
    return input;
}


// ****************************************************************************
//  Method: avtMultiCurvePlot::CustomizeBehavior
//
//  Purpose:
//      Customizes the behavior as appropriate for a MultiCurve plot.  This
//      includes behavior like shifting towards or away from the screen.
//
//  Programmer: xml2avt
//  Creation:   omitted
//
//  Modifications:
//    Eric Brugger, Fri Feb 20 16:21:57 PST 2009
//    I added a legend to the plot.
//
//    Eric Brugger, Tue Mar  3 15:07:09 PST 2009
//    I modified the routine to get the y axis tick spacing from the plot
//    information.
//
//    Eric Brugger, Mon Nov  5 16:31:16 PST 2012
//    I added the ability to display the parallel axes either horizontally
//    or vertically.
//
// ****************************************************************************

void
avtMultiCurvePlot::CustomizeBehavior(void)
{
    //
    // Set the window mode.
    //
    const MapNode *mNode = behavior->GetInfo().GetAttributes().GetPlotInformation().GetData().GetEntry("AxisOrientation");
    if (mNode != NULL)
    {
        if (mNode->GetEntry("vertical")->AsInt())
            behavior->GetInfo().GetAttributes().SetWindowMode(WINMODE_VERTPARALLELAXES);
        else
            behavior->GetInfo().GetAttributes().SetWindowMode(WINMODE_PARALLELAXES);
    }
    else
    {
        behavior->GetInfo().GetAttributes().SetWindowMode(WINMODE_PARALLELAXES);
    }

    //
    // Create the legend, which consists of the tick scale and any legend
    // text from the operators.
    //
    mNode = behavior->GetInfo().GetAttributes().GetPlotInformation().GetData().GetEntry("AxisTickSpacing");
    if (mNode != NULL)
    {
        char msg[80];
        sprintf(msg, "Each tick is %g", mNode->GetEntry("spacing")->AsDouble());
        levelsLegend->SetTitle(msg);
    }

    mNode = behavior->GetInfo().GetAttributes().GetPlotInformation().GetData().GetEntry("LegendMessage");
    if (mNode != NULL)
    {
        const std::string message = mNode->GetEntry("message")->AsString();
        levelsLegend->SetMessage(message.c_str());
    }

    behavior->SetShiftFactor(0.0);
    behavior->SetLegend(levelsLegendRefPtr);
}


// ****************************************************************************
//  Method: avtMultiCurvePlot::CustomizeMapper
//
//  Purpose:
//      A hook from the base class that allows the plot to change its mapper
//      based on the dataset input. 
//
//  Arguments:
//      doi     The data object information.
//
//  Programmer: xml2avt
//  Creation:   omitted
//
// ****************************************************************************

void
avtMultiCurvePlot::CustomizeMapper(avtDataObjectInformation &doi)
{
    return;
}


// ****************************************************************************
//  Method: avtMultiCurvePlot::SetAtts
//
//  Purpose:
//      Sets the atts for the MultiCurve plot.
//
//  Arguments:
//      atts    The attributes for this MultiCurve plot.
//
//  Programmer: xml2avt
//  Creation:   omitted
//
//  Modifications:
//    Eric Brugger, Wed Feb 18 12:13:03 PST 2009
//    I added the ability to display identifiers at each of the points.
//
//    Eric Brugger, Fri Feb 20 16:21:57 PST 2009
//    I added a legend to the plot.
//
//    Eric Brugger, Mon Mar  9 18:08:26 PDT 2009
//    I enhanced the plot so that the markers and identifiers displayed for
//    the points are in the same color as the curve, instead of always in
//    black.
//
//    Eric Brugger, Thu Feb 28 13:51:01 PST 2013
//    I added the ability to set a scale factor and the line width for the
//    markers.
//
//    Kathleen Biagas, Thu Oct 16 09:12:03 PDT 2014
//    Send 'needsRecalculation' flag to levelsMapper when setting colors.
//
// ****************************************************************************

void
avtMultiCurvePlot::SetAtts(const AttributeGroup *a)
{
    const MultiCurveAttributes *newAtts = (const MultiCurveAttributes *)a;

    needsRecalculation = atts.ChangesRequireRecalculation(*newAtts);

    atts = *newAtts;

    if (MultiCurveFilter != NULL)
        MultiCurveFilter->SetAttributes(*newAtts);

    if (atts.GetColorType() == MultiCurveAttributes::ColorBySingleColor)
    {
        const ColorAttribute ca = atts.GetSingleColor();
        ColorAttributeList cal;
        cal.AddColors(atts.GetSingleColor());
        avtLUT->SetLUTColorsWithOpacity(ca.GetColor(), 1);
        levelsMapper->SetColors(cal, needsRecalculation);
        decoMapper->SetColors(cal);
    }
    else // ColorByMultipleColors
    {
        const ColorAttributeList &cal = atts.GetMultiColor();
        unsigned char *colors = new unsigned char[cal.GetNumColors() * 4];
        unsigned char *cptr = colors;
        for(int i = 0; i < cal.GetNumColors(); i++)
        {
            *cptr++ = (char)cal[i].Red();
            *cptr++ = (char)cal[i].Green();
            *cptr++ = (char)cal[i].Blue();
            *cptr++ = (char)cal[i].Alpha();
        }

        avtLUT->SetLUTColorsWithOpacity(colors, cal.GetNumColors());
        levelsMapper->SetColors(cal, needsRecalculation);
        decoMapper->SetColors(cal);

        delete [] colors;
    }

    SetLineWidth(atts.GetLineWidth());
    SetLegend(atts.GetLegendFlag());

    //
    // Create the decorations.
    //
    decoMapper->SetMarkerVisibility(atts.GetDisplayMarkers());
    decoMapper->SetIdVisibility(atts.GetDisplayIds());

    SetMarkerScale(atts.GetMarkerScale());
    SetMarkerLineWidth(atts.GetMarkerLineWidth());
}


// ****************************************************************************
//  Method: avtMultiCurvePlot::SetLineWidth
//
//  Purpose:
//      Sets the line width for the MultiCurve plot.
//
//  Arguments:
//      lw      The line width for this MultiCurve plot.
//
//  Programmer: Eric Brugger
//  Creation:   December 12, 2008
//
// ****************************************************************************

void
avtMultiCurvePlot::SetLineWidth(int lw)
{
    levelsMapper->SetLineWidth(Int2LineWidth(lw));
}


// ****************************************************************************
//  Method: avtMultiCurvePlot::SetMarkerScale
//
//  Purpose:
//      Sets the marker scale for the MultiCurve plot.
//
//  Arguments:
//      ms      The marker scale for this MultiCurve plot.
//
//  Programmer: Eric Brugger
//  Creation:   February 19, 2013
//
// ****************************************************************************

void
avtMultiCurvePlot::SetMarkerScale(double ms)
{
    decoMapper->SetScale(ms);
}


// ****************************************************************************
//  Method: avtMultiCurvePlot::SetMarkerLineWidth
//
//  Purpose:
//      Sets the marker line width for the MultiCurve plot.
//
//  Arguments:
//      mw      The marker line width for this MultiCurve plot.
//
//  Programmer: Eric Brugger
//  Creation:   February 19, 2013
//
// ****************************************************************************

void
avtMultiCurvePlot::SetMarkerLineWidth(int mw)
{
    decoMapper->SetMarkerLineWidth(Int2LineWidth(mw));
}


// ****************************************************************************
//  Method: avtMultiCurvePlot::SetLegend
//
//  Purpose:
//      Turns the legend on or off.
//
//  Arguments:
//      on      True if the legend should be turned on, false otherwise.
//
//  Programmer: Eric Brugger
//  Creation:   February 20, 2009
//
// ****************************************************************************

void
avtMultiCurvePlot::SetLegend(bool on)
{
    if (on)
    {
        levelsLegend->LegendOn();
    }
    else
    {
        levelsLegend->LegendOff();
    }
}


// ****************************************************************************
//  Method: avtMultiCurvePlot::EnhanceSpecification
//
//  Purpose:
//      Enhance the contract to request the secondary variables.
//
//  Returns:    The new contract.
//
//  Arguments:
//      spec    The existing.
//
//  Programmer: Eric Brugger
//  Creation:   December 12, 2008
//
//  Modifications:
//    Eric Brugger, Thu Feb 26 17:49:02 PST 2009
//    I added code to also request the id variable.
//
// ****************************************************************************

avtContract_p
avtMultiCurvePlot::EnhanceSpecification(avtContract_p spec)
{
    std::string mv = atts.GetMarkerVariable();
    std::string iv = atts.GetIdVariable();
    if (mv == "default" && iv == "default")
    {
        return spec;
    }
    avtDataRequest_p ds = spec->GetDataRequest();
    const char *primaryVariable = ds->GetVariable();
    if ((mv == "default" || mv == primaryVariable) &&
        (iv == "default" || iv == primaryVariable))
    {
        //
        // Both variables are either "default" or the same as the plot
        // variable, so don't read it in again.
        //
        return spec;
    }

    //
    // The pipeline specification should really be const -- it is used
    // elsewhere, so we can't modify it and return it.  Make a copy and in
    // the new copy, add the secondary variables.
    //
    avtDataRequest_p nds = new avtDataRequest(primaryVariable,
                                      ds->GetTimestep(), ds->GetRestriction());
    if (mv != "default" && mv != primaryVariable)
        nds->AddSecondaryVariable(mv.c_str());
    if (iv != "default" && iv != primaryVariable && iv != mv)
        nds->AddSecondaryVariable(iv.c_str());
    avtContract_p rv = new avtContract(spec, nds);

    return rv;
}
