// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ****************************************************************************
//  File: MoleculePluginInfo.C
// ****************************************************************************

#include <MoleculePluginInfo.h>
#include <MoleculeAttributes.h>

#include <visit-config.h>
VISIT_PLUGIN_VERSION(Molecule,PLOT_EXPORT)

VISIT_PLOT_PLUGIN_ENTRY(Molecule,General)

// ****************************************************************************
//  Method: MoleculeGeneralPluginInfo::GetName
//
//  Purpose:
//    Return the name of the plot plugin.
//
//  Returns:    A pointer to the name of the plot plugin.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

const char *
MoleculeGeneralPluginInfo::GetName() const
{
    return "Molecule";
}

// ****************************************************************************
//  Method: MoleculeGeneralPluginInfo::GetVersion
//
//  Purpose:
//    Return the version of the plot plugin.
//
//  Returns:    A pointer to the version of the plot plugin.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

const char *
MoleculeGeneralPluginInfo::GetVersion() const
{
    return "1.0";
}

// ****************************************************************************
//  Method: MoleculeGeneralPluginInfo::GetID
//
//  Purpose:
//    Return the id of the plot plugin.
//
//  Returns:    A pointer to the id of the plot plugin.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

const char *
MoleculeGeneralPluginInfo::GetID() const
{
    return "Molecule_1.0";
}
// ****************************************************************************
//  Method: MoleculeGeneralPluginInfo::EnabledByDefault
//
//  Purpose:
//    Return true if this plugin should be enabled by default; false otherwise.
//
//  Returns:    true/false
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

bool
MoleculeGeneralPluginInfo::EnabledByDefault() const
{
    return true;
}
