
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
texture g_SrcTexture : DIFFUSE <
    string ResourceName = "default_color.dds";
    string UIName =  "Src Texture";
    string ResourceType = "2D";
>;
texture g_DestTexture <
    string ResourceName = "default_color.dds";
    string UIName =  "Dest Texture";
    string ResourceType = "2D";
>;
texture g_WeightMap <
    string ResourceName = "default_color.dds";
    string UIName =  "Weight Map";
    string ResourceType = "2D";
>;

sampler2D g_SrcSampler = sampler_state {
    MinFilter = Linear;
    MagFilter = Linear;
    Texture = <g_SrcTexture>;
	AddressU = Wrap;
    AddressV = Wrap;
}; 

sampler2D g_DestSampler = sampler_state {
    MinFilter = Linear;
    MagFilter = Linear;
    Texture = <g_DestTexture>;
	AddressU = Wrap;
    AddressV = Wrap;
}; 
sampler2D g_WeightSampler = sampler_state {
    MinFilter = Linear;
    MagFilter = Linear;
    Texture = <g_WeightMap>;
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
	float4 srcColor = float4(0,0,0,0);
	float4 destColor = float4(0,0,0,0);
	float4 weightColor = float4(0,0,0,0);
	srcColor = tex2D(g_SrcSampler, vin.UV.xy);
	destColor = tex2D(g_DestSampler, vin.UV.xy);
	weightColor = tex2D(g_WeightSampler, vin.UV.xy);
	float4 result = float4(0,0,0,0);
	float w = (weightColor.r + weightColor.g + weightColor.b)/3.0;
	
	return w*srcColor + destColor;
	
}

float4 SimplePS(VSOUT vin) : COLOR {
	float4 srcColor = float4(0,0,0,0);
	srcColor = tex2D(g_SrcSampler, vin.UV.xy);
	return srcColor;
	
}
technique technique0 {
	pass p0 {
		ZENABLE = false;
		AlphaBlendEnable = false;
		CullMode = None;
		//VertexShader = compile vs_3_0 mainVS();
		PixelShader = compile ps_2_a  mainPS();
	}
}

technique technique1 {
	pass p0 {
		ZENABLE = false;
		AlphaBlendEnable = false;
		CullMode = None;
		//VertexShader = compile vs_3_0 mainVS();
		PixelShader = compile ps_2_a  SimplePS();
	}
}

