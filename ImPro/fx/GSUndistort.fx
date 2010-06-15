
struct AppData {
    float3 Position	: POSITION;
	float3 Normal	: NORMAL;
    float2 UV		: TEXCOORD0;
    
};

struct VSOUT {
    float4 HPosition: SV_POSITION;
    float2 UV		: TEXCOORD0;
};

bool g_bFlipX = false;
bool g_bFlipY = false;
bool g_bEnable = true;

float4x4 WorldViewProj : WorldViewProjection;

Texture2D g_Texture : DIFFUSE <
    string ResourceName = "default_color.dds";
    string UIName =  "Diffuse Texture";
    string ResourceType = "2D";
>;

Texture2D g_MapX 
<
    string ResourceName = "default_color.dds";
    string UIName =  "MapX Texture";
    string ResourceType = "2D";
>;

Texture2D g_MapY 
<
    string ResourceName = "default_color.dds";
    string UIName =  "MapY Texture";
    string ResourceType = "2D";
>;


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
	float2 mapUV = float2(0,0);
	
	uint mapXWidth = 0;
	uint mapXHeight = 0;
	uint mapYWidth = 0;
	uint mapYHeight = 0;
	g_MapX.GetDimensions(mapXWidth, mapXHeight);
	g_MapY.GetDimensions(mapYWidth, mapYHeight);
	mapUV.x = g_MapX.Sample(g_LinearSampler, uv).r / mapXWidth;
	mapUV.y = g_MapY.Sample(g_LinearSampler, uv).r / mapYHeight;

	float2 usingUV = float2(0,0);
	if (g_bEnable)
	{
		usingUV = mapUV;
	}
	else
	{
		usingUV = uv;
	}

	float4 colorLn = g_Texture.Sample(g_LinearSampler, usingUV);
	return colorLn;
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

