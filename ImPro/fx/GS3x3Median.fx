
struct AppData {
    float3 Position	: POSITION;
	float3 Normal	: NORMAL;
    float2 UV		: TEXCOORD0;
    
};

struct VSOUT {
    float4 HPosition: SV_POSITION;
    float2 UV		: TEXCOORD0;
};


float g_pixelW = 1.0/(640.0-1.0);
float g_pixelH = 1.0/(480.0-1.0);
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

float findMedian(float a, float b, float c)
{
	float median;
	if( a < b )
	{
		if( b < c)
		{
			median = b;
		}
		else
		{
			median = max(a,c);
		}
	}
	else
	{
		if( a < c)
		{
			median = a;
		}
		else
		{
			median = max(b,c);
		}
	}
	return median;
}


float4 findMedian_4Channel(float4 a, float4 b, float4 c)
{
	float gray_a = a.r*0.3 + a.g*0.59 + a.b*0.11;
	float gray_b = b.r*0.3 + b.g*0.59 + b.b*0.11;
	float gray_c = c.r*0.3 + c.g*0.59 + c.b*0.11;

	float4 median;
	if( gray_a < gray_b )
	{
		if( gray_b < gray_c)
		{
			median = b;
		}
		else
		{
			if (gray_a > gray_c)
			{
				median = a;
			}
			else
			{
				median = c;
			}
		}
	}
	else
	{
		if( gray_a < gray_c)
		{
			median = a;
		}
		else
		{
			if ( gray_b > gray_c)
			{
				median = b; 
			}
			else
			{
				median = c;
			}
		}
	}
	return median;
}


VSOUT mainVS(AppData appIn ) {
	VSOUT ret;
	ret.HPosition = mul(float4(appIn.Position.xyz, 1.0), WorldViewProj);
	ret.UV = appIn.UV;
	return ret;
}

float4 mainPS(VSOUT vin) : SV_Target {	
	float candidateA[3];
	for (int y=-1; y<=1; y++)
	{
		float candidateB[3];
		for (int x = -1; x <= 1; x++)
		{
			float4 color = g_Texture.Sample(g_PointSampler, vin.UV + float2(x*g_pixelW, y*g_pixelH));
			candidateB[x+1] = color.r; 
		}
		candidateA[y+1] = findMedian(candidateB[0], candidateB[1], candidateB[2]);
	}
	float ret = findMedian(candidateA[0], candidateA[1], candidateA[2]);
	return float4(ret, ret, ret, 1.0);
}


float4 mainPS_4Channel(VSOUT vin) : SV_Target {	
	float4 candidateA[3];
	for (int y=-1; y<=1; y++)
	{
		float4 candidateB[3];
		for (int x = -1; x <= 1; x++)
		{
			candidateB[x+1] = g_Texture.Sample(g_PointSampler, vin.UV + float2(x*g_pixelW, y*g_pixelH)); 
		}
		candidateA[y+1] = findMedian_4Channel(candidateB[0], candidateB[1], candidateB[2]);
	}
	float4 ret = findMedian_4Channel(candidateA[0], candidateA[1], candidateA[2]);
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


technique10 tech4Channel <
	string Script = "Pass=p0;";
> {
    pass p0 <
	string Script = "Draw=geometry;";
    > {
        SetVertexShader( CompileShader( vs_4_0, mainVS() ) );
        SetGeometryShader( NULL );
        SetPixelShader( CompileShader( ps_4_0, mainPS_4Channel() ) );
                
        SetRasterizerState(DisableCulling);       
		SetDepthStencilState(DepthEnabling, 0);
		SetBlendState(DisableBlend, float4( 0.0f, 0.0f, 0.0f, 0.0f ), 0xFFFFFFFF);
    }
}
