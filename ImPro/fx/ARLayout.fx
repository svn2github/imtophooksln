float4 minColor = (0.0, 0.0, 0.0, 0.0);
	 
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
    MinFilter = POINT;
    MagFilter = POINT;
    Texture = <g_Texture>;
}; 


float4 mainPS(VSOUT vin) : COLOR {
	float4 ret = tex2D(g_Sampler, float2(vin.UV.x, vin.UV.y));
	ret.a = max(ret.a, minColor.a);
	ret.r = max(ret.r, minColor.r);
	ret.g = max(ret.g, minColor.g);
	ret.b = max(ret.b, minColor.b);
	return ret;
}

float4 maskPS(VSOUT vin) : COLOR {
	return float4(0,0,0,1);
}

technique technique0 {
	pass p0 {
		PixelShader = compile ps_2_0 mainPS();
	}
}

technique techniqueARMask {
	pass p0 {
		PixelShader = compile ps_2_0 maskPS();
	}
}
