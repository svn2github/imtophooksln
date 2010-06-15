
#define halfWndW 7
const unsigned int g_wndW = halfWndW*2+1;

//compute shader median filter by bitonicSort 

Texture2D<float4> g_Texture;

RWTexture2D<float4> g_OutTexture : register( u0 );

groupshared float minc = 0.0;
groupshared float maxc = 1.0;
groupshared float pivot = 0.5;
groupshared uint nSmall = 0;

[numthreads(halfWndW*2+1, halfWndW*2+1, 1)]
void mainCS_median(uint3 Gid : SV_GroupID, uint3 DTid : SV_DispatchThreadID, uint3 GTid : SV_GroupThreadID, uint GI : SV_GroupIndex)
{
	unsigned int texW =0, texH = 0;
	g_Texture.GetDimensions(texW, texH);
	float2 uv = Gid.xy + GTid.xy - uint2(halfWndW + 0.5, halfWndW + 0.5);
	float4 color = g_Texture[uv];
	float gray = color.r * 0.333 + color.g * 0.333 + color.b *0.333;
	uint nhalfCandidate = g_wndW*g_wndW*0.5;
	int localnSmall = 0;
	for (int i =0; i < 8; i++)
	{
		nSmall = 0;
		GroupMemoryBarrierWithGroupSync();
		if (gray < pivot)
		{
			localnSmall = nSmall;
			InterlockedAdd(nSmall, 1, localnSmall);
		}
		GroupMemoryBarrierWithGroupSync();
		
		if (GI == 0 )
		{
			localnSmall = nSmall;
			if (localnSmall > nhalfCandidate)
			{
				maxc = pivot;
				pivot = (maxc + minc)*0.5;
				
			}
			else
			{
				minc = pivot;
				pivot = (maxc + minc)*0.5;
				
			}
		}
		GroupMemoryBarrierWithGroupSync();
		
	}
	
	if (GI == 0)
		g_OutTexture[Gid.xy] = float4(pivot, pivot, pivot, 1.0);

}

technique11 Main_median <
	string Script = "Pass=p0;";
> {
   pass p0 
	{
        SetVertexShader( NULL );
        SetGeometryShader( NULL );
        SetPixelShader( NULL );
		SetComputeShader( CompileShader( cs_5_0, mainCS_median()));
    }
}

