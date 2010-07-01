
struct AppData {
    float3 Position	: POSITION;
	float3 Normal	: NORMAL;
    float2 UV		: TEXCOORD0;
    
};

struct VSOUT {
    float4 HPosition: SV_POSITION;
    float2 UV		: TEXCOORD0;
};

int g_sampleType = 1;
bool g_bFlipY = false;
float4x4 WorldViewProj : WorldViewProjection;

float4x4 g_matTexTransform   
<
	string UIName="matTTS";
> = {1.0f, 0.0f, 0.0f, 0.0f, 
     0.0f, 1.0f, 0.0f, 0.0f,
	 0.0f, 0.0f, 1.0f, 0.0f,
	 0.0f, 0.0f, 0.0f, 1.0f}; 

SamplerState g_LinearSampler
{
    Filter = MIN_MAG_MIP_LINEAR;
    AddressU = Clamp;
    AddressV = Clamp;
};

SamplerState g_PointSampler
{
    Filter = MIN_MAG_MIP_POINT;
    AddressU = Clamp;
    AddressV = Clamp;
};  


Texture2D g_Texture : DIFFUSE <
    string ResourceName = "default_color.dds";
    string UIName =  "Diffuse Texture";
    string ResourceType = "2D";
>;

VSOUT mainVS(AppData appIn ) {
	VSOUT ret;
	ret.HPosition = mul(float4(appIn.Position.xyz, 1.0), WorldViewProj);
	ret.UV = appIn.UV;
	return ret;
}

float4 mainPS(VSOUT vin) : SV_Target{
	float2 preUV = vin.UV;
	if (g_bFlipY)
	{
		preUV.y = 1- preUV.y;
	} 
	float4 uv = mul(float4(preUV , 1.0, 1.0), g_matTexTransform );
	
	uv.x /= uv.z;
	uv.y /= uv.z;
	uv.z = 1;
	
	float4 colorPt = g_Texture.Sample(g_PointSampler, uv);
	float4 colorLn = g_Texture.Sample(g_LinearSampler, uv);
	float4 colorBlack = float4(0,0,0,0);
	float4 ret = float4(0,0,0,0);
	if (uv.x > 1.0 || uv.x < 0 || uv.y > 1.0 || uv.y < 0 )
		ret = colorBlack;
	else
	{			
		if (g_sampleType == 0)
		{
			ret = colorPt;
		}
		else
		{
			ret = colorLn;
		}
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
