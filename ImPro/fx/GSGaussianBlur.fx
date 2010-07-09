
#define MAXHWNDSIZE 5
#define MAXWNDAREA (MAXHWNDSIZE*2+1)*(MAXHWNDSIZE*2+1)
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

float g_pixelW = 1.0/(640.0-1.0);
float g_pixelH = 1.0/(480.0-1.0);
int g_halfWndW0 = 3;
float g_smoothWnd0[MAXWNDAREA];

SamplerState g_Sampler = sampler_state {
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

float4 mainPS_Gaussian(VSOUT vin) : SV_Target {
	float2 uv = float2(0,0);
	uint wArea0 = (g_halfWndW0*2+1)*(g_halfWndW0*2+1);
	int nIdx = 0;
	float4 color0 = float4(0,0,0,0);
	int nx =0;
	int ny = 0;
	int wndW0 = g_halfWndW0*2 + 1;
	
	for (ny = -g_halfWndW0; ny <= g_halfWndW0; ny++)
	{
		for (nx = -g_halfWndW0; nx <= g_halfWndW0; nx++)
		{
			nIdx = (ny+g_halfWndW0)*wndW0 + (nx+g_halfWndW0);
			uv.x = vin.UV.x + nx*g_pixelW;
			uv.y = vin.UV.y + ny*g_pixelH;
			color0 += g_Texture.Sample(g_Sampler, uv) * g_smoothWnd0[nIdx];
		}
	}
	
	
	return float4(color0.rgb, 1.0);
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

technique10 techGaussian <
	string Script = "Pass=p0;";
> {
    pass p0 <
	string Script = "Draw=geometry;";
    > {
        SetVertexShader( CompileShader( vs_4_0, mainVS() ) );
        SetGeometryShader( NULL );
        SetPixelShader( CompileShader( ps_4_0, mainPS_Gaussian() ) );
                
        SetRasterizerState(DisableCulling);       
		SetDepthStencilState(DepthEnabling, 0);
		SetBlendState(DisableBlend, float4( 0.0f, 0.0f, 0.0f, 0.0f ), 0xFFFFFFFF);
    }
}


