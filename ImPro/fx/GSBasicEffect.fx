
struct AppData {
    float3 Position	: POSITION;
	float3 Normal	: NORMAL;
    float2 UV		: TEXCOORD0;
    
};

struct VSOUT {
    float4 HPosition	: SV_POSITION;
    float2 UV		: TEXCOORD0;
};

int g_sampleType = 0;
bool g_bFlipY = false;
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
	if (g_bFlipY)
	{
		uv.y = 1 - uv.y;
	}
	if (g_sampleType == 0)
	{
		return g_Texture.Sample(g_PointSampler, uv);
	}
	else
	{
		return g_Texture.Sample(g_LinearSampler, uv);
	}
}


///// TECHNIQUES /////////////////////////////
RasterizerState DisableCulling
{
    CullMode = NONE;
};

DepthStencilState DepthEnabling
{
	DepthEnable = TRUE;
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

technique Main <
	string Script = "Pass=p0;";
> {
    pass p0 <
	string Script = "Draw=geometry;";
    > {
        VertexShader = compile vs_2_0 mainVS();
		ZEnable = true;
		ZWriteEnable = true;
		ZFunc = LessEqual;
		AlphaBlendEnable = false;
		CullMode = None;
        PixelShader = compile ps_2_a mainPS();
    }
}

