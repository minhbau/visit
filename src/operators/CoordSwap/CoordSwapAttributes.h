#ifndef COORDSWAPATTRIBUTES_H
#define COORDSWAPATTRIBUTES_H
#include <string>
#include <AttributeSubject.h>

// ****************************************************************************
// Class: CoordSwapAttributes
//
// Purpose:
//    This class contains attributes for the coord swap operator.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Wed Feb 2 16:09:10 PST 2005
//
// Modifications:
//   
// ****************************************************************************

class CoordSwapAttributes : public AttributeSubject
{
public:
    enum Coord
    {
        Coord1,
        Coord2,
        Coord3
    };

    CoordSwapAttributes();
    CoordSwapAttributes(const CoordSwapAttributes &obj);
    virtual ~CoordSwapAttributes();

    virtual CoordSwapAttributes& operator = (const CoordSwapAttributes &obj);
    virtual bool operator == (const CoordSwapAttributes &obj) const;
    virtual bool operator != (const CoordSwapAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();

    // Property setting methods
    void SetNewCoord1(Coord newCoord1_);
    void SetNewCoord2(Coord newCoord2_);
    void SetNewCoord3(Coord newCoord3_);

    // Property getting methods
    Coord GetNewCoord1() const;
    Coord GetNewCoord2() const;
    Coord GetNewCoord3() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string Coord_ToString(Coord);
    static bool Coord_FromString(const std::string &, Coord &);
protected:
    static std::string Coord_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

private:
    int newCoord1;
    int newCoord2;
    int newCoord3;
};

#endif
