// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef QUERYOVERTIMEATTRIBUTES_H
#define QUERYOVERTIMEATTRIBUTES_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>

#include <QueryAttributes.h>
#include <PickAttributes.h>

// ****************************************************************************
// Class: QueryOverTimeAttributes
//
// Purpose:
//    Attributes for queries over time.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class STATE_API QueryOverTimeAttributes : public AttributeSubject
{
public:
    enum TimeType
    {
        Cycle,
        DTime,
        Timestep
    };

    // These constructors are for objects of this class
    QueryOverTimeAttributes();
    QueryOverTimeAttributes(const QueryOverTimeAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    QueryOverTimeAttributes(private_tmfs_t tmfs);
    QueryOverTimeAttributes(const QueryOverTimeAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~QueryOverTimeAttributes();

    virtual QueryOverTimeAttributes& operator = (const QueryOverTimeAttributes &obj);
    virtual bool operator == (const QueryOverTimeAttributes &obj) const;
    virtual bool operator != (const QueryOverTimeAttributes &obj) const;
private:
    void Init();
    void Copy(const QueryOverTimeAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectQueryAtts();
    void SelectPickAtts();
    void SelectCachedCurvePts();

    // Property setting methods
    void SetTimeType(TimeType timeType_);
    void SetStartTimeFlag(bool startTimeFlag_);
    void SetStartTime(int startTime_);
    void SetEndTimeFlag(bool endTimeFlag_);
    void SetEndTime(int endTime_);
    void SetStrideFlag(bool strideFlag_);
    void SetStride(int stride_);
    void SetCreateWindow(bool createWindow_);
    void SetWindowId(int windowId_);
    void SetQueryAtts(const QueryAttributes &queryAtts_);
    void SetPickAtts(const PickAttributes &pickAtts_);
    void SetCachedCurvePts(const doubleVector &cachedCurvePts_);
    void SetUseCachedPts(bool useCachedPts_);
    void SetCanUseDirectDatabaseRoute(bool canUseDirectDatabaseRoute_);

    // Property getting methods
    TimeType              GetTimeType() const;
    bool                  GetStartTimeFlag() const;
    int                   GetStartTime() const;
    bool                  GetEndTimeFlag() const;
    int                   GetEndTime() const;
    bool                  GetStrideFlag() const;
    int                   GetStride() const;
    bool                  GetCreateWindow() const;
    int                   GetWindowId() const;
    const QueryAttributes &GetQueryAtts() const;
          QueryAttributes &GetQueryAtts();
    const PickAttributes  &GetPickAtts() const;
          PickAttributes  &GetPickAtts();
    const doubleVector    &GetCachedCurvePts() const;
          doubleVector    &GetCachedCurvePts();
    bool                  GetUseCachedPts() const;
    bool                  GetCanUseDirectDatabaseRoute() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string TimeType_ToString(TimeType);
    static bool TimeType_FromString(const std::string &, TimeType &);
protected:
    static std::string TimeType_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;


    // IDs that can be used to identify fields in case statements
    enum {
        ID_timeType = 0,
        ID_startTimeFlag,
        ID_startTime,
        ID_endTimeFlag,
        ID_endTime,
        ID_strideFlag,
        ID_stride,
        ID_createWindow,
        ID_windowId,
        ID_queryAtts,
        ID_pickAtts,
        ID_cachedCurvePts,
        ID_useCachedPts,
        ID_canUseDirectDatabaseRoute,
        ID__LAST
    };

protected:
    doubleVector    cachedCurvePts;
    bool            useCachedPts;
    bool            canUseDirectDatabaseRoute;
private:
    int             timeType;
    bool            startTimeFlag;
    int             startTime;
    bool            endTimeFlag;
    int             endTime;
    bool            strideFlag;
    int             stride;
    bool            createWindow;
    int             windowId;
    QueryAttributes queryAtts;
    PickAttributes  pickAtts;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define QUERYOVERTIMEATTRIBUTES_TMFS "ibibibibiaad*bb"

#endif
