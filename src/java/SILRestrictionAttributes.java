// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

package llnl.visit;

import java.lang.Byte;
import java.util.Vector;

// ****************************************************************************
// Class: SILRestrictionAttributes
//
// Purpose:
//    The class contains attributes for SIL restrictions.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

public class SILRestrictionAttributes extends AttributeSubject
{
    private static int SILRestrictionAttributes_numAdditionalAtts = 3;

    public SILRestrictionAttributes()
    {
        super(SILRestrictionAttributes_numAdditionalAtts);

        useSet = new Vector();
        topSet = -1;
        silAtts = new SILAttributes();
    }

    public SILRestrictionAttributes(int nMoreFields)
    {
        super(SILRestrictionAttributes_numAdditionalAtts + nMoreFields);

        useSet = new Vector();
        topSet = -1;
        silAtts = new SILAttributes();
    }

    public SILRestrictionAttributes(SILRestrictionAttributes obj)
    {
        super(obj);

        int i;

        useSet = new Vector(obj.useSet.size());
        for(i = 0; i < obj.useSet.size(); ++i)
        {
            Byte bv = (Byte)obj.useSet.elementAt(i);
            useSet.addElement(new Byte(bv.byteValue()));
        }

        topSet = obj.topSet;
        silAtts = new SILAttributes(obj.silAtts);

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return SILRestrictionAttributes_numAdditionalAtts;
    }

    public boolean equals(SILRestrictionAttributes obj)
    {
        int i;

        // Compare the elements in the useSet vector.
        boolean useSet_equal = (obj.useSet.size() == useSet.size());
        for(i = 0; (i < useSet.size()) && useSet_equal; ++i)
        {
            // Make references to Byte from Object.
            Byte useSet1 = (Byte)useSet.elementAt(i);
            Byte useSet2 = (Byte)obj.useSet.elementAt(i);
            useSet_equal = useSet1.equals(useSet2);
        }
        // Create the return value
        return (useSet_equal &&
                (topSet == obj.topSet) &&
                (silAtts.equals(obj.silAtts)));
    }

    // Property setting methods
    public void SetUseSet(Vector useSet_)
    {
        useSet = useSet_;
        Select(0);
    }

    public void SetTopSet(int topSet_)
    {
        topSet = topSet_;
        Select(1);
    }

    public void SetSilAtts(SILAttributes silAtts_)
    {
        silAtts = silAtts_;
        Select(2);
    }

    // Property getting methods
    public Vector        GetUseSet() { return useSet; }
    public int           GetTopSet() { return topSet; }
    public SILAttributes GetSilAtts() { return silAtts; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteByteVector(useSet);
        if(WriteSelect(1, buf))
            buf.WriteInt(topSet);
        if(WriteSelect(2, buf))
            silAtts.Write(buf);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetUseSet(buf.ReadByteVector());
            break;
        case 1:
            SetTopSet(buf.ReadInt());
            break;
        case 2:
            silAtts.Read(buf);
            Select(2);
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + ucharVectorToString("useSet", useSet, indent) + "\n";
        str = str + intToString("topSet", topSet, indent) + "\n";
        str = str + indent + "silAtts = {\n" + silAtts.toString(indent + "    ") + indent + "}\n";
        return str;
    }


    // Attributes
    private Vector        useSet; // vector of Byte objects
    private int           topSet;
    private SILAttributes silAtts;
}

