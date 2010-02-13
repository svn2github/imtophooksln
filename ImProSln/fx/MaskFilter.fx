	 
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

sampler2D g_Sampler = sampler_state {
    MinFilter = Linear;
    MagFilter = Linear;
    Texture = <g_Texture>;
}; 

float4 mainPS(VSOUT vin) : COLOR {
	return tex2D(g_Sampler, float2(vin.UV.x, vin.UV.y));
	
}

technique technique0 {
	pass p0 {
		PixelShader = compile ps_2_0 mainPS();
	}
}
