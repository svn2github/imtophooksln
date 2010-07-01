#define DIMCURVE 5

struct AppData {
    float3 Position	: POSITION;
	float3 Normal	: NORMAL;
    float2 UV		: TEXCOORD0;
    
};

struct VSOUT {
    float4 HPosition: SV_POSITION;
    float2 UV		: TEXCOORD0;
};
bool g_bInvWarp = false;
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


float g_tCurveCof[DIMCURVE] = {0.0, 0.0, 0.0, 0.0, 0.0};
float g_bCurveCof[DIMCURVE] = {1.0, 0.0, 0.0, 0.0, 0.0};
float g_xCurveCof[DIMCURVE] = {0.0, 1.0, 0.0, 0.0, 0.0};

float CurveFunc(float Xin, float pCof[DIMCURVE])
{
	float ret = 0;
	for (uint i =0; i < DIMCURVE; i++)
	{
		ret += pCof[i]*pow(Xin, i);
	}
	return ret;
}

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
	float4 ret = float4(0,0,0,0);
	float topCurveY = CurveFunc(uv.x, g_tCurveCof);
			
	float bottomCurveY = CurveFunc(uv.x, g_bCurveCof);		
	float CurveX = CurveFunc(uv.x, g_xCurveCof);	
	if (!g_bInvWarp)
	{
		uv.x = uv.x - CurveX;
		uv.y = (uv.y - topCurveY )/(bottomCurveY - topCurveY); 
	}
	else
	{
		uv.x = uv.x + CurveX;
		uv.y = uv.y*(bottomCurveY - topCurveY) + topCurveY; 
	}
	if (uv.y < 0 || uv.y > 1 || uv.x < 0 || uv.x > 1)
		ret = float4(0.0, 0.0, 0.0, 0.0);
	else
		ret = g_Texture.Sample(g_LinearSampler, uv);
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

