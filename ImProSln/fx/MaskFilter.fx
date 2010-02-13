int maskFlag = 1;

struct appdata {
    float3 Position	: POSITION;
    float4 UV		: TEXCOORD0;
    float4 Normal	: NORMAL;

};

/* data passed from vertex shader to pixel shader */
struct VSOUT {
    float4 HPosition	: POSITION;
    float2 UV		: TEXCOORD0;
};
texture g_Texture : DIFFUSE <
    string ResourceName = "default_color.dds";
    string UIName =  "Diffuse Texture";
    string ResourceType = "2D";
>;
texture g_MaskTexture : DIFFUSE <
    string ResourceName = "default_color.dds";
    string UIName =  "Mask Texture";
    string ResourceType = "2D";
>;

sampler2D g_Sampler = sampler_state {
    MinFilter = Linear;
    MagFilter = Linear;
    Texture = <g_Texture>;
	AddressU = Wrap;
    AddressV = Wrap;
}; 

sampler2D g_MaskSampler = sampler_state {
    MinFilter = Linear;
    MagFilter = Linear;
    Texture = <g_MaskTexture>;
	AddressU = Wrap;
    AddressV = Wrap;
}; 



float4x4 WorldViewProj : WorldViewProjection;

VSOUT mainVS(appdata appIn ) {
	VSOUT ret;
	ret.HPosition = mul(float4(appIn.Position.xyz, 1.0), WorldViewProj);
	ret.UV = appIn.UV;
	return ret;
}

float4 mainPS(VSOUT vin) : COLOR {
	if (maskFlag == 0)
	{
		return float4(0,0,0,0);
	}
	else if (maskFlag == 1)
	{
		return tex2D(g_Sampler, float2(vin.UV.x, vin.UV.y));
	}
	else
	{
		float4 texColor = tex2D(g_Sampler, vin.UV.xy);
		float4 maskColor = tex2D(g_MaskSampler, vin.UV.xy);
		float maskAlpha = maskColor.a;
		return texColor*(1.0 - maskAlpha) + maskColor*maskAlpha;
	}
	return float4(0,0,0,0);
}

technique technique0 {
	pass p0 {
		AlphaBlendEnable = false;
		CullMode = None;
		//VertexShader = compile vs_3_0 mainVS();
		PixelShader = compile ps_2_a  mainPS();
	}
}