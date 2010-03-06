
bool bFlipX = false;
bool bFlipY = false;

int g_sampleType = 1;

float4x4 g_matTexTransform   
<
	string UIWidget="matTTS";
> = {1.0f, 0.0f, 0.0f, 0.0f, 
     0.0f, 1.0f, 0.0f, 0.0f,
	 0.0f, 0.0f, 1.0f, 0.0f,
	 0.0f, 0.0f, 0.0f, 1.0f}; 
	 
struct VSOUT {
    float4 pos	: POSITION;
	float4 normal : NORMAL;
    float2 UV		: TEXCOORD0;
};

texture g_Texture : DIFFUSE <
    string ResourceName = "default_color.dds";
    string UIName =  "Diffuse Texture";
    string ResourceType = "2D";
>;


sampler2D g_LinearSampler = sampler_state {
    MinFilter = Linear;
    MagFilter = Linear;
    Texture = <g_Texture>;
}; 

sampler2D g_PointSampler = sampler_state {
    MinFilter = Linear;
    MagFilter = Linear;
    Texture = <g_Texture>;
}; 

float4 mainPS(VSOUT vin) : COLOR {
	float2 inUV = vin.UV;
	if (bFlipY)
	{
		inUV.y = 1 - inUV.y;
	}
	if (bFlipX)
	{
		inUV.x = 1 - inUV.x;
	}	 
	float4 uv = mul(float4(inUV, 1.0, 1.0), g_matTexTransform );
	uv.x /= uv.z;
	uv.y /= uv.z;
	uv.z = 1;
	if (uv.x > 1.0 || uv.x < 0 || uv.y > 1.0 || uv.y < 0 )
		return float4(0,0,0,0);
	else
	{		
		if (g_sampleType == 0)	
		{
			return tex2D(g_PointSampler, float2(uv.x, uv.y));
		}
		else
		{
			return tex2D(g_LinearSampler, float2(uv.x, uv.y));
		}
	}
	
}

technique technique0 {
	pass p0 {
		PixelShader = compile ps_2_0 mainPS();
	}
}
