
struct AppData {
    float3 Position	: POSITION;
	float3 Normal	: NORMAL;
    float2 UV		: TEXCOORD0;
    
};

struct VSOUT {
    float4 HPosition: SV_POSITION;
    float2 UV		: TEXCOORD0;
};

bool g_bFlipMaskX = false;
bool g_bFlipMaskY = false;

int g_maskFlag = 2;

float4x4 g_MaskTransform   
<
	string UIName="maskTTS";
> = {1.0f, 0.0f, 0.0f, 0.0f, 
     0.0f, 1.0f, 0.0f, 0.0f,
	 0.0f, 0.0f, 1.0f, 0.0f,
	 0.0f, 0.0f, 0.0f, 1.0f}; 
	 
float4x4 WorldViewProj : WorldViewProjection;

Texture2D g_Texture : DIFFUSE <
    string ResourceName = "default_color.dds";
    string UIName =  "Src Texture";
    string ResourceType = "2D";
>;

Texture2D g_Mask <
    string ResourceName = "default_color.dds";
    string UIName =  "Mask Texture";
    string ResourceType = "2D";
>;


SamplerState g_PointSampler
{
    Filter = MIN_MAG_MIP_POINT;
    AddressU = Clamp;
    AddressV = Clamp;
};

SamplerState g_LinearSampler
{
    Filter = MIN_MAG_MIP_LINEAR;
    AddressU = Clamp;
    AddressV = Clamp;
};

VSOUT mainVS(AppData appIn ) {
	VSOUT ret;
	ret.HPosition = mul(float4(appIn.Position.xyz, 1.0), WorldViewProj);
	ret.UV = appIn.UV;
	return ret;
}

float4 mainPS(VSOUT vin) : SV_Target {
	float4 srcColor = float4(0,0,0,0);
	float4 MaskColor = float4(0,0,0,0);
	float4 tmpmaskUV = mul(float4(vin.UV , 1.0, 1.0), g_MaskTransform );
	
	tmpmaskUV.x /= tmpmaskUV.z;
	tmpmaskUV.y /= tmpmaskUV.z;
	tmpmaskUV.z = 1;
	
	float2 maskUV = tmpmaskUV.xy;
	
	if (g_bFlipMaskX)
	{
		maskUV.x = 1 - maskUV.x;
	}
	if (g_bFlipMaskY)
	{
		maskUV.y = 1 - maskUV.y; 
	}
	
	srcColor = g_Texture.Sample(g_PointSampler, vin.UV.xy);
	MaskColor = g_Mask.Sample(g_LinearSampler, maskUV);
	if (maskUV.x < 0 || maskUV.x > 1 || maskUV.y < 0 || maskUV.y > 1)
	{
		MaskColor = float4(0,0,0,0);
	}
	float4 ret = float4(0,0,0,0);
	if (g_maskFlag == 0)
	{
		ret = float4(0,0,0,1);
	}
	else if(g_maskFlag == 1)
	{
		ret = srcColor;
	}
	else
	{
		ret = srcColor*(1 - MaskColor.a) + float4((MaskColor*MaskColor.a).rgb, MaskColor.a);
	}
	
	return ret;
	
}


///// TECHNIQUES /////////////////////////////
RasterizerState DisableCulling
{
    CullMode = NONE;
};

DepthStencilState DepthEnabling
{
	DepthEnable = FALSE;
};

BlendState DisableBlend
{
	BlendEnable[0] = FALSE;
};

technique10 Main10 <
	string Script = "Pass=p0;";
> {
    pass p0 <
	string Script = "Draw=geometry;";
    > {
        SetVertexShader( CompileShader( vs_4_0, mainVS() ) );
        SetGeometryShader( NULL );
        SetPixelShader( CompileShader( ps_4_0, mainPS() ) );
                
        SetRasterizerState(DisableCulling);       
		SetDepthStencilState(DepthEnabling, 0);
		SetBlendState(DisableBlend, float4( 0.0f, 0.0f, 0.0f, 0.0f ), 0xFFFFFFFF);
    }
}

