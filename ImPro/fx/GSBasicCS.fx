
Texture2D<float4> g_Texture;
RWTexture2D<float4> g_OutTexture : register( u0 );

SamplerState g_PointSampler = sampler_state {
    Filter = MIN_MAG_MIP_POINT;
    AddressU = Clamp;
    AddressV = Clamp;
};  
const float g_pixW = 1.0/(640.0-1.0);
const float g_pixH = 1.0/(480.0-1.0);
 
[numthreads(1, 1, 1)]
void mainCS(uint3 Gid : SV_GroupID, uint3 DTid : SV_DispatchThreadID, uint3 GTid : SV_GroupThreadID, uint GI : SV_GroupIndex)
{
	float2 fGID = float2(Gid.x*g_pixW, Gid.y*g_pixH);
	float4 color = g_Texture.Gather(g_PointSampler, fGID.xy, int2(0, 0));
	g_OutTexture[Gid.xy] = color;
}

technique11 Main <
	string Script = "Pass=p0;";
> {
   pass p0 
	{
        SetVertexShader( NULL );
        SetGeometryShader( NULL );
        SetPixelShader( NULL );
		SetComputeShader( CompileShader( cs_5_0, mainCS()));
    }
}

