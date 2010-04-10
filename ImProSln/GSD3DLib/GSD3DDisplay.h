#pragma once
#include "GSD3DLib.h"
#include "GSD3DBaseClass.h"
#include "GSMesh.h"
#include "GSCamera.h"
#include "GSWnd.h"
#include "GSEffect.h"
#include "GSD3DDisplay.h"

class GSD3DLIB_API GS3DDisplay : public IGSD3DDisplay, public GSWnd, public GSRenderBase, public GSEffectBase, public GSDXBase
{
protected:
	BOOL m_bDeviceFromOthers;
	GS3DPlane* m_pDisplayPlane;
	GSCamera* m_pCamera;

	//from GSRenderBase
	virtual HRESULT SetEffectVariables(IGSEffectBase* pGSEffect);
private:
	
	HRESULT InitDevice(UINT bufW = 0, UINT bufH = 0);
	HRESULT InitDevice(ID3D11Device* pDevice);

public:
	GS3DDisplay(UINT bufW, UINT bufH);
	GS3DDisplay(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, IDXGISwapChain* pSwapChain);
	virtual ~GS3DDisplay();
	//from IDSD3DDisplay
	virtual HRESULT Render();
	virtual BOOL IsDeviceFromOther();

};