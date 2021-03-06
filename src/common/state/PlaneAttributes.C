// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <PlaneAttributes.h>
#include <DataNode.h>

// ****************************************************************************
// Method: PlaneAttributes::PlaneAttributes
//
// Purpose:
//   Init utility for the PlaneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

void PlaneAttributes::Init()
{
    origin[0] = 0;
    origin[1] = 0;
    origin[2] = 0;
    normal[0] = 0;
    normal[1] = 0;
    normal[2] = 1;
    upAxis[0] = 0;
    upAxis[1] = 1;
    upAxis[2] = 0;
    haveRadius = false;
    radius = 1;
    threeSpace = false;

    PlaneAttributes::SelectAll();
}

// ****************************************************************************
// Method: PlaneAttributes::PlaneAttributes
//
// Purpose:
//   Copy utility for the PlaneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

void PlaneAttributes::Copy(const PlaneAttributes &obj)
{
    origin[0] = obj.origin[0];
    origin[1] = obj.origin[1];
    origin[2] = obj.origin[2];

    normal[0] = obj.normal[0];
    normal[1] = obj.normal[1];
    normal[2] = obj.normal[2];

    upAxis[0] = obj.upAxis[0];
    upAxis[1] = obj.upAxis[1];
    upAxis[2] = obj.upAxis[2];

    haveRadius = obj.haveRadius;
    radius = obj.radius;
    threeSpace = obj.threeSpace;

    PlaneAttributes::SelectAll();
}

// Type map format string
const char *PlaneAttributes::TypeMapFormatString = PLANEATTRIBUTES_TMFS;
const AttributeGroup::private_tmfs_t PlaneAttributes::TmfsStruct = {PLANEATTRIBUTES_TMFS};


// ****************************************************************************
// Method: PlaneAttributes::PlaneAttributes
//
// Purpose:
//   Default constructor for the PlaneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

PlaneAttributes::PlaneAttributes() :
    AttributeSubject(PlaneAttributes::TypeMapFormatString)
{
    PlaneAttributes::Init();
}

// ****************************************************************************
// Method: PlaneAttributes::PlaneAttributes
//
// Purpose:
//   Constructor for the derived classes of PlaneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

PlaneAttributes::PlaneAttributes(private_tmfs_t tmfs) :
    AttributeSubject(tmfs.tmfs)
{
    PlaneAttributes::Init();
}

// ****************************************************************************
// Method: PlaneAttributes::PlaneAttributes
//
// Purpose:
//   Copy constructor for the PlaneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

PlaneAttributes::PlaneAttributes(const PlaneAttributes &obj) :
    AttributeSubject(PlaneAttributes::TypeMapFormatString)
{
    PlaneAttributes::Copy(obj);
}

// ****************************************************************************
// Method: PlaneAttributes::PlaneAttributes
//
// Purpose:
//   Copy constructor for derived classes of the PlaneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

PlaneAttributes::PlaneAttributes(const PlaneAttributes &obj, private_tmfs_t tmfs) :
    AttributeSubject(tmfs.tmfs)
{
    PlaneAttributes::Copy(obj);
}

// ****************************************************************************
// Method: PlaneAttributes::~PlaneAttributes
//
// Purpose:
//   Destructor for the PlaneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

PlaneAttributes::~PlaneAttributes()
{
    // nothing here
}

// ****************************************************************************
// Method: PlaneAttributes::operator =
//
// Purpose:
//   Assignment operator for the PlaneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

PlaneAttributes&
PlaneAttributes::operator = (const PlaneAttributes &obj)
{
    if (this == &obj) return *this;

    PlaneAttributes::Copy(obj);

    return *this;
}

// ****************************************************************************
// Method: PlaneAttributes::operator ==
//
// Purpose:
//   Comparison operator == for the PlaneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

bool
PlaneAttributes::operator == (const PlaneAttributes &obj) const
{
    // Compare the origin arrays.
    bool origin_equal = true;
    for(int i = 0; i < 3 && origin_equal; ++i)
        origin_equal = (origin[i] == obj.origin[i]);

    // Compare the normal arrays.
    bool normal_equal = true;
    for(int i = 0; i < 3 && normal_equal; ++i)
        normal_equal = (normal[i] == obj.normal[i]);

    // Compare the upAxis arrays.
    bool upAxis_equal = true;
    for(int i = 0; i < 3 && upAxis_equal; ++i)
        upAxis_equal = (upAxis[i] == obj.upAxis[i]);

    // Create the return value
    return (origin_equal &&
            normal_equal &&
            upAxis_equal &&
            (haveRadius == obj.haveRadius) &&
            (radius == obj.radius) &&
            (threeSpace == obj.threeSpace));
}

// ****************************************************************************
// Method: PlaneAttributes::operator !=
//
// Purpose:
//   Comparison operator != for the PlaneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

bool
PlaneAttributes::operator != (const PlaneAttributes &obj) const
{
    return !(this->operator == (obj));
}

// ****************************************************************************
// Method: PlaneAttributes::TypeName
//
// Purpose:
//   Type name method for the PlaneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

const std::string
PlaneAttributes::TypeName() const
{
    return "PlaneAttributes";
}

// ****************************************************************************
// Method: PlaneAttributes::CopyAttributes
//
// Purpose:
//   CopyAttributes method for the PlaneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

bool
PlaneAttributes::CopyAttributes(const AttributeGroup *atts)
{
    if(TypeName() != atts->TypeName())
        return false;

    // Call assignment operator.
    const PlaneAttributes *tmp = (const PlaneAttributes *)atts;
    *this = *tmp;

    return true;
}

// ****************************************************************************
// Method: PlaneAttributes::CreateCompatible
//
// Purpose:
//   CreateCompatible method for the PlaneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

AttributeSubject *
PlaneAttributes::CreateCompatible(const std::string &tname) const
{
    AttributeSubject *retval = 0;
    if(TypeName() == tname)
        retval = new PlaneAttributes(*this);
    // Other cases could go here too.

    return retval;
}

// ****************************************************************************
// Method: PlaneAttributes::NewInstance
//
// Purpose:
//   NewInstance method for the PlaneAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

AttributeSubject *
PlaneAttributes::NewInstance(bool copy) const
{
    AttributeSubject *retval = 0;
    if(copy)
        retval = new PlaneAttributes(*this);
    else
        retval = new PlaneAttributes;

    return retval;
}

// ****************************************************************************
// Method: PlaneAttributes::SelectAll
//
// Purpose:
//   Selects all attributes.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

void
PlaneAttributes::SelectAll()
{
    Select(ID_origin,     (void *)origin, 3);
    Select(ID_normal,     (void *)normal, 3);
    Select(ID_upAxis,     (void *)upAxis, 3);
    Select(ID_haveRadius, (void *)&haveRadius);
    Select(ID_radius,     (void *)&radius);
    Select(ID_threeSpace, (void *)&threeSpace);
}

///////////////////////////////////////////////////////////////////////////////
// Persistence methods
///////////////////////////////////////////////////////////////////////////////

// ****************************************************************************
// Method: PlaneAttributes::CreateNode
//
// Purpose:
//   This method creates a DataNode representation of the object so it can be saved to a config file.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

bool
PlaneAttributes::CreateNode(DataNode *parentNode, bool completeSave, bool forceAdd)
{
    if(parentNode == 0)
        return false;

    PlaneAttributes defaultObject;
    bool addToParent = false;
    // Create a node for PlaneAttributes.
    DataNode *node = new DataNode("PlaneAttributes");

    if(completeSave || !FieldsEqual(ID_origin, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("origin", origin, 3));
    }

    if(completeSave || !FieldsEqual(ID_normal, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("normal", normal, 3));
    }

    if(completeSave || !FieldsEqual(ID_upAxis, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("upAxis", upAxis, 3));
    }

    if(completeSave || !FieldsEqual(ID_haveRadius, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("haveRadius", haveRadius));
    }

    if(completeSave || !FieldsEqual(ID_radius, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("radius", radius));
    }

    if(completeSave || !FieldsEqual(ID_threeSpace, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("threeSpace", threeSpace));
    }


    // Add the node to the parent node.
    if(addToParent || forceAdd)
        parentNode->AddNode(node);
    else
        delete node;

    return (addToParent || forceAdd);
}

// ****************************************************************************
// Method: PlaneAttributes::SetFromNode
//
// Purpose:
//   This method sets attributes in this object from values in a DataNode representation of the object.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

void
PlaneAttributes::SetFromNode(DataNode *parentNode)
{
    if(parentNode == 0)
        return;

    DataNode *searchNode = parentNode->GetNode("PlaneAttributes");
    if(searchNode == 0)
        return;

    DataNode *node;
    if((node = searchNode->GetNode("origin")) != 0)
        SetOrigin(node->AsDoubleArray());
    if((node = searchNode->GetNode("normal")) != 0)
        SetNormal(node->AsDoubleArray());
    if((node = searchNode->GetNode("upAxis")) != 0)
        SetUpAxis(node->AsDoubleArray());
    if((node = searchNode->GetNode("haveRadius")) != 0)
        SetHaveRadius(node->AsBool());
    if((node = searchNode->GetNode("radius")) != 0)
        SetRadius(node->AsDouble());
    if((node = searchNode->GetNode("threeSpace")) != 0)
        SetThreeSpace(node->AsBool());
}

///////////////////////////////////////////////////////////////////////////////
// Set property methods
///////////////////////////////////////////////////////////////////////////////

void
PlaneAttributes::SetOrigin(const double *origin_)
{
    origin[0] = origin_[0];
    origin[1] = origin_[1];
    origin[2] = origin_[2];
    Select(ID_origin, (void *)origin, 3);
}

void
PlaneAttributes::SetNormal(const double *normal_)
{
    normal[0] = normal_[0];
    normal[1] = normal_[1];
    normal[2] = normal_[2];
    Select(ID_normal, (void *)normal, 3);
}

void
PlaneAttributes::SetUpAxis(const double *upAxis_)
{
    upAxis[0] = upAxis_[0];
    upAxis[1] = upAxis_[1];
    upAxis[2] = upAxis_[2];
    Select(ID_upAxis, (void *)upAxis, 3);
}

void
PlaneAttributes::SetHaveRadius(bool haveRadius_)
{
    haveRadius = haveRadius_;
    Select(ID_haveRadius, (void *)&haveRadius);
}

void
PlaneAttributes::SetRadius(double radius_)
{
    radius = radius_;
    Select(ID_radius, (void *)&radius);
}

void
PlaneAttributes::SetThreeSpace(bool threeSpace_)
{
    threeSpace = threeSpace_;
    Select(ID_threeSpace, (void *)&threeSpace);
}

///////////////////////////////////////////////////////////////////////////////
// Get property methods
///////////////////////////////////////////////////////////////////////////////

const double *
PlaneAttributes::GetOrigin() const
{
    return origin;
}

double *
PlaneAttributes::GetOrigin()
{
    return origin;
}

const double *
PlaneAttributes::GetNormal() const
{
    return normal;
}

double *
PlaneAttributes::GetNormal()
{
    return normal;
}

const double *
PlaneAttributes::GetUpAxis() const
{
    return upAxis;
}

double *
PlaneAttributes::GetUpAxis()
{
    return upAxis;
}

bool
PlaneAttributes::GetHaveRadius() const
{
    return haveRadius;
}

double
PlaneAttributes::GetRadius() const
{
    return radius;
}

bool
PlaneAttributes::GetThreeSpace() const
{
    return threeSpace;
}

///////////////////////////////////////////////////////////////////////////////
// Select property methods
///////////////////////////////////////////////////////////////////////////////

void
PlaneAttributes::SelectOrigin()
{
    Select(ID_origin, (void *)origin, 3);
}

void
PlaneAttributes::SelectNormal()
{
    Select(ID_normal, (void *)normal, 3);
}

void
PlaneAttributes::SelectUpAxis()
{
    Select(ID_upAxis, (void *)upAxis, 3);
}

///////////////////////////////////////////////////////////////////////////////
// Keyframing methods
///////////////////////////////////////////////////////////////////////////////

// ****************************************************************************
// Method: PlaneAttributes::GetFieldName
//
// Purpose:
//   This method returns the name of a field given its index.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

std::string
PlaneAttributes::GetFieldName(int index) const
{
    switch (index)
    {
    case ID_origin:     return "origin";
    case ID_normal:     return "normal";
    case ID_upAxis:     return "upAxis";
    case ID_haveRadius: return "haveRadius";
    case ID_radius:     return "radius";
    case ID_threeSpace: return "threeSpace";
    default:  return "invalid index";
    }
}

// ****************************************************************************
// Method: PlaneAttributes::GetFieldType
//
// Purpose:
//   This method returns the type of a field given its index.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

AttributeGroup::FieldType
PlaneAttributes::GetFieldType(int index) const
{
    switch (index)
    {
    case ID_origin:     return FieldType_doubleArray;
    case ID_normal:     return FieldType_doubleArray;
    case ID_upAxis:     return FieldType_doubleArray;
    case ID_haveRadius: return FieldType_bool;
    case ID_radius:     return FieldType_double;
    case ID_threeSpace: return FieldType_bool;
    default:  return FieldType_unknown;
    }
}

// ****************************************************************************
// Method: PlaneAttributes::GetFieldTypeName
//
// Purpose:
//   This method returns the name of a field type given its index.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

std::string
PlaneAttributes::GetFieldTypeName(int index) const
{
    switch (index)
    {
    case ID_origin:     return "doubleArray";
    case ID_normal:     return "doubleArray";
    case ID_upAxis:     return "doubleArray";
    case ID_haveRadius: return "bool";
    case ID_radius:     return "double";
    case ID_threeSpace: return "bool";
    default:  return "invalid index";
    }
}

// ****************************************************************************
// Method: PlaneAttributes::FieldsEqual
//
// Purpose:
//   This method compares two fields and return true if they are equal.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

bool
PlaneAttributes::FieldsEqual(int index_, const AttributeGroup *rhs) const
{
    const PlaneAttributes &obj = *((const PlaneAttributes*)rhs);
    bool retval = false;
    switch (index_)
    {
    case ID_origin:
        {  // new scope
        // Compare the origin arrays.
        bool origin_equal = true;
        for(int i = 0; i < 3 && origin_equal; ++i)
            origin_equal = (origin[i] == obj.origin[i]);

        retval = origin_equal;
        }
        break;
    case ID_normal:
        {  // new scope
        // Compare the normal arrays.
        bool normal_equal = true;
        for(int i = 0; i < 3 && normal_equal; ++i)
            normal_equal = (normal[i] == obj.normal[i]);

        retval = normal_equal;
        }
        break;
    case ID_upAxis:
        {  // new scope
        // Compare the upAxis arrays.
        bool upAxis_equal = true;
        for(int i = 0; i < 3 && upAxis_equal; ++i)
            upAxis_equal = (upAxis[i] == obj.upAxis[i]);

        retval = upAxis_equal;
        }
        break;
    case ID_haveRadius:
        {  // new scope
        retval = (haveRadius == obj.haveRadius);
        }
        break;
    case ID_radius:
        {  // new scope
        retval = (radius == obj.radius);
        }
        break;
    case ID_threeSpace:
        {  // new scope
        retval = (threeSpace == obj.threeSpace);
        }
        break;
    default: retval = false;
    }

    return retval;
}

///////////////////////////////////////////////////////////////////////////////
// User-defined methods.
///////////////////////////////////////////////////////////////////////////////

