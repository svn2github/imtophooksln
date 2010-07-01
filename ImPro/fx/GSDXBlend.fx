
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

Texture2D g_SrcTexture : DIFFUSE <
    string ResourceName = "default_color.dds";
    string UIName =  "Src Texture";
    string ResourceType = "2D";
>;

Texture2D g_DestTexture : DIFFUSE <
    string ResourceName = "default_color.dds";
    string UIName =  "Dest Texture";
    string ResourceType = "2D";
>;


Texture2D g_WeightTexture : DIFFUSE <
    string ResourceName = "default_color.dds";
    string UIName =  "Weight Texture";
    string ResourceType = "2D";
>;

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
	float4 destColor = float4(0,0,0,0);
	float4 weightColor = float4(0,0,0,0);
	
	srcColor = g_SrcTexture.Sample(g_LinearSampler, vin.UV.xy);
	destColor = g_DestTexture.Sample(g_LinearSampler, vin.UV.xy);
	weightColor = g_WeightTexture.Sample(g_LinearSampler, vin.UV.xy);
	
	float w = weightColor.r;
	return w*srcColor + destColor;
	
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

