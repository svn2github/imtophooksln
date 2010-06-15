
struct AppData {
    float3 Position	: POSITION;
	float3 Normal	: NORMAL;
    float2 UV		: TEXCOORD0;
    
};

struct VSOUT {
    float4 HPosition: SV_POSITION;
    float2 UV		: TEXCOORD0;
};

#define GRAYLEVEL 256

uint g_winHalfW = 10;

float4x4 WorldViewProj : WorldViewProjection;

Texture2D g_Texture : DIFFUSE <
    string ResourceName = "default_color.dds";
    string UIName =  "Diffuse Texture";
    string ResourceType = "2D";
>;


SamplerState g_PointSampler {
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
	uint texW =0, texH = 0;
	float4 ret = float4(0,0,0,0);
	float covConst = 1.0/(GRAYLEVEL-1);
	g_Texture.GetDimensions(texW, texH);
	
	float xstep = 1.0/texW;
	float ystep = 1.0/texH;
	
	uint nCandidate = (g_winHalfW+1)*(g_winHalfW+1);
	uint winW = g_winHalfW*2 + 1;
	
	/////////////////////////////////
	uint ny = 0;
	uint nx = 0;
	float2 tmpUV = float2(0, 0);
	//for type conversion in for loop
	float fnx = 0;
	float fny = 0;
	float fwinW = g_winHalfW;
	float dx = 0;
	float dy = 0;
	float4 color = float4(0,0,0,0); 
	int histogramIdx = 0;
	// take histogram
	float kernal[500];
	for ( ny = 0; ny < winW; ny++)
	{
		for (nx = 0; nx < winW; nx++)
		{
			fnx = nx;
			fny = ny;
			dx = (fnx - fwinW)*xstep;
			dy = (fny - fwinW)*ystep;
			tmpUV.x = uv.x + dx;
			tmpUV.y = uv.y + dy;
			color = g_Texture.Sample(g_PointSampler, tmpUV);
			kernal[ny*winW + nx] = color.r*0.33 + color.g*0.33 + color.b*0.33;
		}
	}
	////////////////
	float guessMin = 0;
	float guessMax = 1.0;
	float curGuess = 0.5;
	
	uint count = 0;
	for (uint i = 0; i < 8; i++)
	{
		count = 0;
		for ( uint j = 0; j < nCandidate; j++)
		{
			if (kernal[j] > curGuess)
			{
				count++;
			}
		}
	
		if (count < nCandidate/2)
		{
			guessMax = curGuess;
		}
		else
		{
			guessMin = curGuess;
			
		}
		curGuess = (guessMax + guessMin)*0.5;
	}
	
	return float4(curGuess, curGuess, curGuess, 1.0);
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

