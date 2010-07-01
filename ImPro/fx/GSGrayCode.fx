
struct AppData {
    float3 Position	: POSITION;
	float3 Normal	: NORMAL;
    float2 UV		: TEXCOORD0;
    
};

struct VSOUT {
    float4 HPosition: SV_POSITION;
    float2 UV		: TEXCOORD0;
};
bool g_bInv = false;
uint g_dir = 0; // 0: horizontal 1: vertical
uint g_nColExp
<
    string UIWidget = "slider";
    float UIMin = 0;
    float UIMax = 20;
    float UIStep = 1;
    string UIName =  "nColExp";
> = 1;

float4x4 WorldViewProj : WorldViewProjection;

VSOUT mainVS(AppData appIn ) {
	VSOUT ret;
	ret.HPosition = mul(float4(appIn.Position.xyz, 1.0), WorldViewProj);
	ret.UV = appIn.UV;
	return ret;
}

float4 mainPS(VSOUT vin) : SV_Target {
	float decideV = vin.UV.x;
	uint nCol = 1;
	nCol = pow(2, g_nColExp);
	if (g_dir == 0)
	{
		decideV = vin.UV.x;
	}
	else 
	{
		decideV = vin.UV.y;
	}
		
	uint idx = decideV/(1.0/nCol);
	float4 ret = float4(1,1,1,1);
	if (idx%2)
	{
		ret = float4(0,0,0,1);
	}
	if (g_bInv)
	{
		ret = float4(1 - ret.x, 1 - ret.y, 1-ret.z, 1.0);
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

