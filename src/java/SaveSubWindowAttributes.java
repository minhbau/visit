// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

package llnl.visit;


// ****************************************************************************
// Class: SaveSubWindowAttributes
//
// Purpose:
//    The attributes for saving a sub window
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

public class SaveSubWindowAttributes extends AttributeSubject
{
    private static int SaveSubWindowAttributes_numAdditionalAtts = 5;

    public SaveSubWindowAttributes()
    {
        super(SaveSubWindowAttributes_numAdditionalAtts);

        position = new int[2];
        position[0] = 0;
        position[1] = 0;
        size = new int[2];
        size[0] = 128;
        size[1] = 128;
        layer = 0;
        transparency = 0;
        omitWindow = false;
    }

    public SaveSubWindowAttributes(int nMoreFields)
    {
        super(SaveSubWindowAttributes_numAdditionalAtts + nMoreFields);

        position = new int[2];
        position[0] = 0;
        position[1] = 0;
        size = new int[2];
        size[0] = 128;
        size[1] = 128;
        layer = 0;
        transparency = 0;
        omitWindow = false;
    }

    public SaveSubWindowAttributes(SaveSubWindowAttributes obj)
    {
        super(obj);

        int i;

        position = new int[2];
        position[0] = obj.position[0];
        position[1] = obj.position[1];

        size = new int[2];
        size[0] = obj.size[0];
        size[1] = obj.size[1];

        layer = obj.layer;
        transparency = obj.transparency;
        omitWindow = obj.omitWindow;

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return SaveSubWindowAttributes_numAdditionalAtts;
    }

    public boolean equals(SaveSubWindowAttributes obj)
    {
        int i;

        // Compare the position arrays.
        boolean position_equal = true;
        for(i = 0; i < 2 && position_equal; ++i)
            position_equal = (position[i] == obj.position[i]);

        // Compare the size arrays.
        boolean size_equal = true;
        for(i = 0; i < 2 && size_equal; ++i)
            size_equal = (size[i] == obj.size[i]);

        // Create the return value
        return (position_equal &&
                size_equal &&
                (layer == obj.layer) &&
                (transparency == obj.transparency) &&
                (omitWindow == obj.omitWindow));
    }

    // Property setting methods
    public void SetPosition(int[] position_)
    {
        position[0] = position_[0];
        position[1] = position_[1];
        Select(0);
    }

    public void SetPosition(int e0, int e1)
    {
        position[0] = e0;
        position[1] = e1;
        Select(0);
    }

    public void SetSize(int[] size_)
    {
        size[0] = size_[0];
        size[1] = size_[1];
        Select(1);
    }

    public void SetSize(int e0, int e1)
    {
        size[0] = e0;
        size[1] = e1;
        Select(1);
    }

    public void SetLayer(int layer_)
    {
        layer = layer_;
        Select(2);
    }

    public void SetTransparency(double transparency_)
    {
        transparency = transparency_;
        Select(3);
    }

    public void SetOmitWindow(boolean omitWindow_)
    {
        omitWindow = omitWindow_;
        Select(4);
    }

    // Property getting methods
    public int[]   GetPosition() { return position; }
    public int[]   GetSize() { return size; }
    public int     GetLayer() { return layer; }
    public double  GetTransparency() { return transparency; }
    public boolean GetOmitWindow() { return omitWindow; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteIntArray(position);
        if(WriteSelect(1, buf))
            buf.WriteIntArray(size);
        if(WriteSelect(2, buf))
            buf.WriteInt(layer);
        if(WriteSelect(3, buf))
            buf.WriteDouble(transparency);
        if(WriteSelect(4, buf))
            buf.WriteBool(omitWindow);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetPosition(buf.ReadIntArray());
            break;
        case 1:
            SetSize(buf.ReadIntArray());
            break;
        case 2:
            SetLayer(buf.ReadInt());
            break;
        case 3:
            SetTransparency(buf.ReadDouble());
            break;
        case 4:
            SetOmitWindow(buf.ReadBool());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + intArrayToString("position", position, indent) + "\n";
        str = str + intArrayToString("size", size, indent) + "\n";
        str = str + intToString("layer", layer, indent) + "\n";
        str = str + doubleToString("transparency", transparency, indent) + "\n";
        str = str + boolToString("omitWindow", omitWindow, indent) + "\n";
        return str;
    }


    // Attributes
    private int[]   position;
    private int[]   size;
    private int     layer;
    private double  transparency;
    private boolean omitWindow;
}

