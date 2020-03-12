// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ****************************************************************************
//  File: ThreeSlicePluginInfo.h
// ****************************************************************************

#ifndef THREESLICE_PLUGIN_INFO_H
#define THREESLICE_PLUGIN_INFO_H
#include <OperatorPluginInfo.h>
#include <operator_plugin_exports.h>

class ThreeSliceAttributes;

// ****************************************************************************
//  Class: ThreeSlicePluginInfo
//
//  Purpose:
//    Five classes that provide all the information about an ThreeSlice operator
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
//  Modifications:
//
// ****************************************************************************

class ThreeSliceGeneralPluginInfo : public virtual GeneralOperatorPluginInfo
{
  public:
    virtual const char *GetName() const;
    virtual const char *GetVersion() const;
    virtual const char *GetID() const;
    virtual bool  EnabledByDefault() const;
    virtual const char *GetCategoryName() const;
};

class ThreeSliceCommonPluginInfo : public virtual CommonOperatorPluginInfo, public virtual ThreeSliceGeneralPluginInfo
{
  public:
    virtual AttributeSubject *AllocAttributes();
    virtual void CopyAttributes(AttributeSubject *to, AttributeSubject *from);
};

class ThreeSliceGUIPluginInfo : public virtual GUIOperatorPluginInfo, public virtual ThreeSliceCommonPluginInfo
{
  public:
    virtual QString *GetMenuName() const;
    virtual QvisPostableWindowObserver *CreatePluginWindow(int type,
        AttributeSubject *attr, const QString &caption, const QString &shortName,
        QvisNotepadArea *notepad);
    virtual const char **XPMIconData() const;
};

class ThreeSliceViewerEnginePluginInfo : public virtual ViewerEngineOperatorPluginInfo, public virtual ThreeSliceCommonPluginInfo
{
  public:
    virtual AttributeSubject *GetClientAtts();
    virtual AttributeSubject *GetDefaultAtts();
    virtual void SetClientAtts(AttributeSubject *atts);
    virtual void GetClientAtts(AttributeSubject *atts);

    virtual void InitializeOperatorAtts(AttributeSubject *atts,
                                        const avtPlotMetaData &plot,
                                        const bool fromDefault);
    virtual void UpdateOperatorAtts(AttributeSubject *atts,
                                    const avtPlotMetaData &plot);
    virtual const char *GetMenuName() const;

    static void InitializeGlobalObjects();
  private:
    static ThreeSliceAttributes *defaultAtts;
    static ThreeSliceAttributes *clientAtts;
};

class ThreeSliceViewerPluginInfo : public virtual ViewerOperatorPluginInfo, public virtual ThreeSliceViewerEnginePluginInfo
{
  public:
    virtual const char **XPMIconData() const;
};

class ThreeSliceEnginePluginInfo : public virtual EngineOperatorPluginInfo, public virtual ThreeSliceViewerEnginePluginInfo
{
  public:
    virtual avtPluginFilter *AllocAvtPluginFilter();
};

class ThreeSliceScriptingPluginInfo : public virtual ScriptingOperatorPluginInfo, public virtual ThreeSliceCommonPluginInfo
{
  public:
    virtual void InitializePlugin(AttributeSubject *subj, void *data);
    virtual void *GetMethodTable(int *nMethods);
    virtual bool TypesMatch(void *pyobject);
    virtual char *GetLogString();
    virtual void SetDefaults(const AttributeSubject *atts);
};

#endif
