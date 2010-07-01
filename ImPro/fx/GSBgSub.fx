
struct AppData {
    float3 Position	: POSITION;
	float3 Normal	: NORMAL;
    float2 UV		: TEXCOORD0;
    
};

struct VSOUT {
    float4 HPosition: SV_POSITION;
    float2 UV		: TEXCOORD0;
};

float g_blendWeight <
	string UIName = "g_SubS";
    string UIWidget = "slider";
    float UIMin = 0.1;
    float UIMax = 1;
    float UIStep = 0.1;
> = 0.1;
bool g_bSrcFlipY = false;
bool g_bSrcFlipX = false;
float g_SubS <
	string UIName = "g_SubS";
    string UIWidget = "slider";
    float UIMin = -1;
    float UIMax = 1;
    float UIStep = 0.02;
> = 0.0;

float4x4 WorldViewProj : WorldViewProjection;

Texture2D g_Texture : DIFFUSE <
    string ResourceName = "default_color.dds";
    string UIName =  "Diffuse Texture";
    string ResourceType = "2D";
>;

Texture2D g_BGTexture <
    string ResourceName = "default_color.dds";
    string UIName =  "BG Texture";
    string ResourceType = "2D";
>;

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
	if (g_bSrcFlipX)
	{
		uv.x = 1 - uv.x;
	}
	if (g_bSrcFlipY)
	{
		uv.y = 1 - uv.y;
	}
	float4 colorBG = g_BGTexture.Sample(g_PointSampler, vin.UV);
	float4 colorIn = g_Texture.Sample(g_PointSampler, uv);
	float4 ret = float4((colorIn - colorBG).rgb, 1.0);
	ret = ret - float4(g_SubS, g_SubS, g_SubS, 0);
	return ret;
}

float4 mainCaptureBG(VSOUT vin) : SV_Target {
	float2 uv = vin.UV;
	if (g_bSrcFlipX)
	{
		uv.x = 1 - uv.x;
	}
	if (g_bSrcFlipY)
	{
		uv.y = 1 - uv.y;
	}
	float4 colorBG = g_BGTexture.Sample(g_PointSampler, vin.UV);
	float4 colorIn = g_Texture.Sample(g_PointSampler, uv);
	float4 ret = float4((colorBG + colorIn*g_blendWeight).rgb, 1);
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

technique10 TechCaptureBG <
	string Script = "Pass=p0;";
> {
    pass p0 <
	string Script = "Draw=geometry;";
    > {
        SetVertexShader( CompileShader( vs_4_0, mainVS() ) );
        SetGeometryShader( NULL );
        SetPixelShader( CompileShader( ps_4_0, mainCaptureBG() ) );
                
        SetRasterizerState(DisableCulling);       
		SetDepthStencilState(DepthEnabling, 0);
		SetBlendState(DisableBlend, float4( 0.0f, 0.0f, 0.0f, 0.0f ), 0xFFFFFFFF);
    }
}

