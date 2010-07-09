
struct AppData {
    float3 Position	: POSITION;
	float3 Normal	: NORMAL;
    float2 UV		: TEXCOORD0;
    
};

struct VSOUT {
    float4 HPosition: SV_POSITION;
    float2 UV		: TEXCOORD0;
};

float4x4 WorldViewProj : WorldViewProjection;

Texture2D g_Texture : DIFFUSE <
    string ResourceName = "default_color.dds";
    string UIName =  "Diffuse Texture";
    string ResourceType = "2D";
>;

SamplerState g_Sampler = sampler_state {
    Filter = MIN_MAG_MIP_LINEAR;
    AddressU = Clamp;
    AddressV = Clamp;
};  
uint g_nChannel = 1;
float g_threshold <
	string UIName = "g_scaleValue";
    string UIWidget = "slider";
    float UIMin = 0.1;
    float UIMax = 1;
    float UIStep = 0.01;
> = 1.0;

VSOUT mainVS(AppData appIn ) {
	VSOUT ret;
	ret.HPosition = mul(float4(appIn.Position.xyz, 1.0), WorldViewProj);
	ret.UV = appIn.UV;
	return ret;
}

float4 mainPS(VSOUT vin) : SV_Target {
	float4 colorPt = g_Texture.Sample(g_Sampler, vin.UV);
	float gray = 0.0;
	if (g_nChannel == 1)
	{
		gray = colorPt.r;
	}
	else
	{
		gray = colorPt.r*0.3 + colorPt.g*0.59 + colorPt.b*0.11;
	}
	
	float4 colorRet = float4(0,0,0,0);
	
	if (gray < g_threshold)
	{
		colorRet = float4(0,0,0,1);
	}
	else
	{
		colorRet = float4(1,1,1,1);
	}
	
	return colorRet;
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

