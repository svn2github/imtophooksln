
struct AppData {
    float3 Position	: POSITION;
	float3 Normal	: NORMAL;
    float2 UV		: TEXCOORD0;
    
};

struct VSOUT {
    float4 HPosition: SV_POSITION;
    float2 UV		: TEXCOORD0;
};

float4 g_minColor = float4(0.5, 0.5, 0.5, 1.0); 



int g_sampleType = 0;
bool g_bFlipY = false;
bool g_bFlipX = false;
float4x4 WorldViewProj : WorldViewProjection;

Texture2D g_Texture : DIFFUSE <
    string ResourceName = "default_color.dds";
    string UIName =  "Diffuse Texture";
    string ResourceType = "2D";
>;

SamplerState g_LinearSampler
{
    Filter = MIN_MAG_MIP_LINEAR;
    AddressU = Clamp;
    AddressV = Clamp;
};


SamplerState g_PointSampler = sampler_state {
    Filter = MIN_MAG_MIP_POINT;
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
	float2 uv = vin.UV;
	if (g_bFlipX)
	{
		uv.x = 1 - uv.x;
	}
	if (g_bFlipY)
	{
		uv.y = 1 - uv.y;
	}
	float4 colorPt = g_Texture.Sample(g_PointSampler, uv);
	float4 colorLn = g_Texture.Sample(g_LinearSampler, uv);
	float4 ret = float4(0,0,0,0);
	if (g_sampleType == 0)
	{
		ret = colorPt;
	}
	else
	{
		ret = colorLn;
	}
	return max(ret, g_minColor);
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

