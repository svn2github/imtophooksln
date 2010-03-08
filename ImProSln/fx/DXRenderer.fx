
bool bFlipX = false;
bool bFlipY = false;
int g_sampleType = 0;
	 
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
    MinFilter = Point;
    MagFilter = Point;
    Texture = <g_Texture>;
}; 

float4 mainPS(VSOUT vin) : COLOR {
	float2 uv = vin.UV;
	if (bFlipY)
	{
		uv.y = 1 - uv.y;
	}
	if (bFlipX)
	{
		uv.x = 1 - uv.x;
	}	

	if (g_sampleType == 0)		
	{
		return tex2D(g_PointSampler, float2(uv.x, uv.y));
	}
	else
	{
		return tex2D(g_LinearSampler, float2(uv.x, uv.y));
	}
}

technique technique0 {
	pass p0 {
		PixelShader = compile ps_2_0 mainPS();
	}
}
