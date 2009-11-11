/*

% Description of my shader.
% Second line of description for my shader.

keywords: material classic

date: YYMMDD

*/
bool g_bMaskEnable = false;
float4x4 g_matTexTransform   
<
	string UIWidget="matTTS";
> = {1.0f, 0.0f, 0.0f, 0.0f, 
     0.0f, 1.0f, 0.0f, 0.0f,
	 0.0f, 0.0f, 1.0f, 0.0f,
	 0.0f, 0.0f, 0.0f, 1.0f};
	 
float4x4 g_invMatMaskTransform   
<
	string UIWidget="matTTS";
> = {1.0f, 0.0f, 0.0f, 0.0f, 
     0.0f, 1.0f, 0.0f, 0.0f,
	 0.0f, 0.0f, 1.0f, 0.0f,
	 0.0f, 0.0f, 0.0f, 1.0f};
	 
	 
float4x4 WorldViewProj : WorldViewProjection;
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
texture g_MaskTexture
<
    string ResourceName = "default_color.dds";
    string UIName =  "Mask Texture";
    string ResourceType = "2D";
> = NULL;
sampler2D g_Sampler = sampler_state {
    Texture = <g_Texture>;
}; 
sampler2D g_MaskSampler = sampler_state {
    Texture = <g_MaskTexture>;
}; 
VSOUT mainVS(float3 pos: POSITION, float3 normal:NORMAL, float2 UV : TEXCOORD0) {
	VSOUT vout;
	vout.pos = mul(float4(pos.xyz, 1.0), WorldViewProj);
	vout.UV = UV;
	vout.normal = float4(normal.xyz, 1);
	return vout;
}

float4 mainPS(VSOUT vin) : COLOR {
	float4 uv = mul(float4(vin.UV , 1.0, 1.0), g_matTexTransform );
	
	uv.x /= uv.z;
	uv.y /= uv.z;
	uv.z = 1;
	if (uv.x > 1.0 || uv.x < 0 || uv.y > 1.0 || uv.y < 0 )
		return float4(0,0,0,0);
	else
	{		
		if (!g_bMaskEnable)
			return tex2D(g_Sampler, float2(uv.x, uv.y));
		float4 muv = mul(float4(vin.UV , 0.0, 1.0), g_invMatMaskTransform);
		float4 mcolor = tex2D(g_MaskSampler, float2(muv.x, muv.y));
		float4 tcolor = tex2D(g_Sampler, float2(uv.x, uv.y));
		if (muv.x <0 || muv.x > 1 || muv.y < 0 || muv.y > 1)
			return tcolor; 
		else
			return mcolor * tcolor;
	}
	
}

technique technique0 {
	pass p0 {
		CullMode = CW;
		ZEnable = true;
		ZWriteEnable = true;
		ZFunc = LessEqual;
		AlphaBlendEnable = false;
		VertexShader = compile vs_3_0 mainVS();
		PixelShader = compile ps_3_0 mainPS();
	}
}
