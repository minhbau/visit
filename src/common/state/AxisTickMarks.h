// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef AXISTICKMARKS_H
#define AXISTICKMARKS_H
#include <state_exports.h>
#include <AttributeSubject.h>


// ****************************************************************************
// Class: AxisTickMarks
//
// Purpose:
//    Contains the tick mark properties for one axis.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

class STATE_API AxisTickMarks : public AttributeSubject
{
public:
    // These constructors are for objects of this class
    AxisTickMarks();
    AxisTickMarks(const AxisTickMarks &obj);
protected:
    // These constructors are for objects derived from this class
    AxisTickMarks(private_tmfs_t tmfs);
    AxisTickMarks(const AxisTickMarks &obj, private_tmfs_t tmfs);
public:
    virtual ~AxisTickMarks();

    virtual AxisTickMarks& operator = (const AxisTickMarks &obj);
    virtual bool operator == (const AxisTickMarks &obj) const;
    virtual bool operator != (const AxisTickMarks &obj) const;
private:
    void Init();
    void Copy(const AxisTickMarks &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();

    // Property setting methods
    void SetVisible(bool visible_);
    void SetMajorMinimum(double majorMinimum_);
    void SetMajorMaximum(double majorMaximum_);
    void SetMinorSpacing(double minorSpacing_);
    void SetMajorSpacing(double majorSpacing_);

    // Property getting methods
    bool   GetVisible() const;
    double GetMajorMinimum() const;
    double GetMajorMaximum() const;
    double GetMinorSpacing() const;
    double GetMajorSpacing() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;


    // IDs that can be used to identify fields in case statements
    enum {
        ID_visible = 0,
        ID_majorMinimum,
        ID_majorMaximum,
        ID_minorSpacing,
        ID_majorSpacing,
        ID__LAST
    };

private:
    bool   visible;
    double majorMinimum;
    double majorMaximum;
    double minorSpacing;
    double majorSpacing;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define AXISTICKMARKS_TMFS "bdddd"

#endif
