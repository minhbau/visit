package llnl.visit.plots;

import llnl.visit.AttributeSubject;
import llnl.visit.CommunicationBuffer;
import llnl.visit.Plugin;
import llnl.visit.ColorControlPointList;
import llnl.visit.GaussianControlPointList;

// ****************************************************************************
// Class: VolumeAttributes
//
// Purpose:
//    This class contains the plot attributes for the volume plot.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   Thu Oct 2 12:43:22 PDT 2003
//
// Modifications:
//   
// ****************************************************************************

public class VolumeAttributes extends AttributeSubject implements Plugin
{
    // Constants
    public final static int RENDERER_SPLATTING = 0;
    public final static int RENDERER_TEXTURE3D = 1;

    public final static int GRADIENTTYPE_CENTEREDDIFFERENCES = 0;
    public final static int GRADIENTTYPE_SOBELOPERATOR = 1;


    public VolumeAttributes()
    {
        super(23);

        legendFlag = true;
        lightingFlag = true;
        colorControlPoints = new ColorControlPointList();
        opacityAttenuation = 1f;
        freeformFlag = true;
        opacityControlPoints = new GaussianControlPointList();
        resampleTarget = 50000;
        opacityVariable = new String("default");
        freeformOpacity = new byte[256];
        for (int i = 0; i < freeformOpacity.length; ++i)
            freeformOpacity[i] = 0;
        doSoftware = false;
        useColorVarMin = false;
        colorVarMin = 0f;
        useColorVarMax = false;
        colorVarMax = 0f;
        useOpacityVarMin = false;
        opacityVarMin = 0f;
        useOpacityVarMax = false;
        opacityVarMax = 0f;
        smoothData = false;
        samplesPerRay = 500;
        rendererType = RENDERER_SPLATTING;
        gradientType = GRADIENTTYPE_SOBELOPERATOR;
        num3DSlices = 200;
    }

    public VolumeAttributes(VolumeAttributes obj)
    {
        super(23);

        int i;

        legendFlag = obj.legendFlag;
        lightingFlag = obj.lightingFlag;
        colorControlPoints = new ColorControlPointList(obj.colorControlPoints);
        opacityAttenuation = obj.opacityAttenuation;
        freeformFlag = obj.freeformFlag;
        opacityControlPoints = new GaussianControlPointList(obj.opacityControlPoints);
        resampleTarget = obj.resampleTarget;
        opacityVariable = new String(obj.opacityVariable);
        freeformOpacity = new byte[256];
        for(i = 0; i < obj.freeformOpacity.length; ++i)
            freeformOpacity[i] = obj.freeformOpacity[i];

        doSoftware = obj.doSoftware;
        useColorVarMin = obj.useColorVarMin;
        colorVarMin = obj.colorVarMin;
        useColorVarMax = obj.useColorVarMax;
        colorVarMax = obj.colorVarMax;
        useOpacityVarMin = obj.useOpacityVarMin;
        opacityVarMin = obj.opacityVarMin;
        useOpacityVarMax = obj.useOpacityVarMax;
        opacityVarMax = obj.opacityVarMax;
        smoothData = obj.smoothData;
        samplesPerRay = obj.samplesPerRay;
        rendererType = obj.rendererType;
        gradientType = obj.gradientType;
        num3DSlices = obj.num3DSlices;

        SelectAll();
    }

    public boolean equals(VolumeAttributes obj)
    {
        int i;

        // Compare the freeformOpacity arrays.
        boolean freeformOpacity_equal = true;
        for(i = 0; i < 256 && freeformOpacity_equal; ++i)
            freeformOpacity_equal = (freeformOpacity[i] == obj.freeformOpacity[i]);

        // Create the return value
        return ((legendFlag == obj.legendFlag) &&
                (lightingFlag == obj.lightingFlag) &&
                (colorControlPoints == obj.colorControlPoints) &&
                (opacityAttenuation == obj.opacityAttenuation) &&
                (freeformFlag == obj.freeformFlag) &&
                (opacityControlPoints == obj.opacityControlPoints) &&
                (resampleTarget == obj.resampleTarget) &&
                (opacityVariable == obj.opacityVariable) &&
                freeformOpacity_equal &&
                true /* can ignore doSoftware */ &&
                (useColorVarMin == obj.useColorVarMin) &&
                (colorVarMin == obj.colorVarMin) &&
                (useColorVarMax == obj.useColorVarMax) &&
                (colorVarMax == obj.colorVarMax) &&
                (useOpacityVarMin == obj.useOpacityVarMin) &&
                (opacityVarMin == obj.opacityVarMin) &&
                (useOpacityVarMax == obj.useOpacityVarMax) &&
                (opacityVarMax == obj.opacityVarMax) &&
                (smoothData == obj.smoothData) &&
                (samplesPerRay == obj.samplesPerRay) &&
                (rendererType == obj.rendererType) &&
                (gradientType == obj.gradientType) &&
                (num3DSlices == obj.num3DSlices));
    }

    public String GetName() { return "Volume"; }
    public String GetVersion() { return "1.1"; }

    // Property setting methods
    public void SetLegendFlag(boolean legendFlag_)
    {
        legendFlag = legendFlag_;
        Select(0);
    }

    public void SetLightingFlag(boolean lightingFlag_)
    {
        lightingFlag = lightingFlag_;
        Select(1);
    }

    public void SetColorControlPoints(ColorControlPointList colorControlPoints_)
    {
        colorControlPoints = colorControlPoints_;
        Select(2);
    }

    public void SetOpacityAttenuation(float opacityAttenuation_)
    {
        opacityAttenuation = opacityAttenuation_;
        Select(3);
    }

    public void SetFreeformFlag(boolean freeformFlag_)
    {
        freeformFlag = freeformFlag_;
        Select(4);
    }

    public void SetOpacityControlPoints(GaussianControlPointList opacityControlPoints_)
    {
        opacityControlPoints = opacityControlPoints_;
        Select(5);
    }

    public void SetResampleTarget(int resampleTarget_)
    {
        resampleTarget = resampleTarget_;
        Select(6);
    }

    public void SetOpacityVariable(String opacityVariable_)
    {
        opacityVariable = opacityVariable_;
        Select(7);
    }

    public void SetFreeformOpacity(byte[] freeformOpacity_)
    {
        for(int i = 0; i < 256; ++i)
             freeformOpacity[i] = freeformOpacity_[i];
        Select(8);
    }

    public void SetDoSoftware(boolean doSoftware_)
    {
        doSoftware = doSoftware_;
        Select(9);
    }

    public void SetUseColorVarMin(boolean useColorVarMin_)
    {
        useColorVarMin = useColorVarMin_;
        Select(10);
    }

    public void SetColorVarMin(float colorVarMin_)
    {
        colorVarMin = colorVarMin_;
        Select(11);
    }

    public void SetUseColorVarMax(boolean useColorVarMax_)
    {
        useColorVarMax = useColorVarMax_;
        Select(12);
    }

    public void SetColorVarMax(float colorVarMax_)
    {
        colorVarMax = colorVarMax_;
        Select(13);
    }

    public void SetUseOpacityVarMin(boolean useOpacityVarMin_)
    {
        useOpacityVarMin = useOpacityVarMin_;
        Select(14);
    }

    public void SetOpacityVarMin(float opacityVarMin_)
    {
        opacityVarMin = opacityVarMin_;
        Select(15);
    }

    public void SetUseOpacityVarMax(boolean useOpacityVarMax_)
    {
        useOpacityVarMax = useOpacityVarMax_;
        Select(16);
    }

    public void SetOpacityVarMax(float opacityVarMax_)
    {
        opacityVarMax = opacityVarMax_;
        Select(17);
    }

    public void SetSmoothData(boolean smoothData_)
    {
        smoothData = smoothData_;
        Select(18);
    }

    public void SetSamplesPerRay(int samplesPerRay_)
    {
        samplesPerRay = samplesPerRay_;
        Select(19);
    }

    public void SetRendererType(int rendererType_)
    {
        rendererType = rendererType_;
        Select(20);
    }

    public void SetGradientType(int gradientType_)
    {
        gradientType = gradientType_;
        Select(21);
    }

    public void SetNum3DSlices(int num3DSlices_)
    {
        num3DSlices = num3DSlices_;
        Select(22);
    }

    // Property getting methods
    public boolean                  GetLegendFlag() { return legendFlag; }
    public boolean                  GetLightingFlag() { return lightingFlag; }
    public ColorControlPointList    GetColorControlPoints() { return colorControlPoints; }
    public float                    GetOpacityAttenuation() { return opacityAttenuation; }
    public boolean                  GetFreeformFlag() { return freeformFlag; }
    public GaussianControlPointList GetOpacityControlPoints() { return opacityControlPoints; }
    public int                      GetResampleTarget() { return resampleTarget; }
    public String                   GetOpacityVariable() { return opacityVariable; }
    public byte[]                   GetFreeformOpacity() { return freeformOpacity; }
    public boolean                  GetDoSoftware() { return doSoftware; }
    public boolean                  GetUseColorVarMin() { return useColorVarMin; }
    public float                    GetColorVarMin() { return colorVarMin; }
    public boolean                  GetUseColorVarMax() { return useColorVarMax; }
    public float                    GetColorVarMax() { return colorVarMax; }
    public boolean                  GetUseOpacityVarMin() { return useOpacityVarMin; }
    public float                    GetOpacityVarMin() { return opacityVarMin; }
    public boolean                  GetUseOpacityVarMax() { return useOpacityVarMax; }
    public float                    GetOpacityVarMax() { return opacityVarMax; }
    public boolean                  GetSmoothData() { return smoothData; }
    public int                      GetSamplesPerRay() { return samplesPerRay; }
    public int                      GetRendererType() { return rendererType; }
    public int                      GetGradientType() { return gradientType; }
    public int                      GetNum3DSlices() { return num3DSlices; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteBool(legendFlag);
        if(WriteSelect(1, buf))
            buf.WriteBool(lightingFlag);
        if(WriteSelect(2, buf))
            colorControlPoints.Write(buf);
        if(WriteSelect(3, buf))
            buf.WriteFloat(opacityAttenuation);
        if(WriteSelect(4, buf))
            buf.WriteBool(freeformFlag);
        if(WriteSelect(5, buf))
            opacityControlPoints.Write(buf);
        if(WriteSelect(6, buf))
            buf.WriteInt(resampleTarget);
        if(WriteSelect(7, buf))
            buf.WriteString(opacityVariable);
        if(WriteSelect(8, buf))
            buf.WriteByteArray(freeformOpacity, true);
        if(WriteSelect(9, buf))
            buf.WriteBool(doSoftware);
        if(WriteSelect(10, buf))
            buf.WriteBool(useColorVarMin);
        if(WriteSelect(11, buf))
            buf.WriteFloat(colorVarMin);
        if(WriteSelect(12, buf))
            buf.WriteBool(useColorVarMax);
        if(WriteSelect(13, buf))
            buf.WriteFloat(colorVarMax);
        if(WriteSelect(14, buf))
            buf.WriteBool(useOpacityVarMin);
        if(WriteSelect(15, buf))
            buf.WriteFloat(opacityVarMin);
        if(WriteSelect(16, buf))
            buf.WriteBool(useOpacityVarMax);
        if(WriteSelect(17, buf))
            buf.WriteFloat(opacityVarMax);
        if(WriteSelect(18, buf))
            buf.WriteBool(smoothData);
        if(WriteSelect(19, buf))
            buf.WriteInt(samplesPerRay);
        if(WriteSelect(20, buf))
            buf.WriteInt(rendererType);
        if(WriteSelect(21, buf))
            buf.WriteInt(gradientType);
        if(WriteSelect(22, buf))
            buf.WriteInt(num3DSlices);
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        for(int i = 0; i < n; ++i)
        {
            int index = (int)buf.ReadByte();
            switch(index)
            {
            case 0:
                SetLegendFlag(buf.ReadBool());
                break;
            case 1:
                SetLightingFlag(buf.ReadBool());
                break;
            case 2:
                colorControlPoints.Read(buf);
                Select(2);
                break;
            case 3:
                SetOpacityAttenuation(buf.ReadFloat());
                break;
            case 4:
                SetFreeformFlag(buf.ReadBool());
                break;
            case 5:
                opacityControlPoints.Read(buf);
                Select(5);
                break;
            case 6:
                SetResampleTarget(buf.ReadInt());
                break;
            case 7:
                SetOpacityVariable(buf.ReadString());
                break;
            case 8:
                SetFreeformOpacity(buf.ReadByteArray());
                break;
            case 9:
                SetDoSoftware(buf.ReadBool());
                break;
            case 10:
                SetUseColorVarMin(buf.ReadBool());
                break;
            case 11:
                SetColorVarMin(buf.ReadFloat());
                break;
            case 12:
                SetUseColorVarMax(buf.ReadBool());
                break;
            case 13:
                SetColorVarMax(buf.ReadFloat());
                break;
            case 14:
                SetUseOpacityVarMin(buf.ReadBool());
                break;
            case 15:
                SetOpacityVarMin(buf.ReadFloat());
                break;
            case 16:
                SetUseOpacityVarMax(buf.ReadBool());
                break;
            case 17:
                SetOpacityVarMax(buf.ReadFloat());
                break;
            case 18:
                SetSmoothData(buf.ReadBool());
                break;
            case 19:
                SetSamplesPerRay(buf.ReadInt());
                break;
            case 20:
                SetRendererType(buf.ReadInt());
                break;
            case 21:
                SetGradientType(buf.ReadInt());
                break;
            case 22:
                SetNum3DSlices(buf.ReadInt());
                break;
            }
        }
    }


    // Attributes
    private boolean                  legendFlag;
    private boolean                  lightingFlag;
    private ColorControlPointList    colorControlPoints;
    private float                    opacityAttenuation;
    private boolean                  freeformFlag;
    private GaussianControlPointList opacityControlPoints;
    private int                      resampleTarget;
    private String                   opacityVariable;
    private byte[]                   freeformOpacity;
    private boolean                  doSoftware;
    private boolean                  useColorVarMin;
    private float                    colorVarMin;
    private boolean                  useColorVarMax;
    private float                    colorVarMax;
    private boolean                  useOpacityVarMin;
    private float                    opacityVarMin;
    private boolean                  useOpacityVarMax;
    private float                    opacityVarMax;
    private boolean                  smoothData;
    private int                      samplesPerRay;
    private int                      rendererType;
    private int                      gradientType;
    private int                      num3DSlices;
}

