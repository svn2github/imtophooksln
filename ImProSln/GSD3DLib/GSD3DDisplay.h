#pragma once
#include "GSD3DLib.h"
#include "GSD3DBaseClass.h"
#include "GSMesh.h"
#include "GSCamera.h"
#include "GSD3DDisplay.h"

class GSD3DLIB_API GS3DDisplay : public IGSRenderBase, public GSDXBase, public GSTextureBase
{
protected:
	GS3DPlane* m_pDisplayPlane;
	GSCamera* m_pCamera;

	virtual HRESULT CreateD3DWindow(UINT winW, UINT winH);
	virtual ATOM RegisterWndClass(HINSTANCE hInstance);
	virtual HRESULT CreateTexture(UINT rtWidth, UINT rtHeight);

private:
	vector<ID3D11RenderTargetView*> m_pBackupBackBuffer;
	BOOL m_bDeviceFromOthers;
	HWND m_hDisplayWnd;
	HRESULT InitDevice(UINT bufW = 0, UINT bufH = 0);
	HRESULT InitDevice(ID3D11Device* pDevice);
	HWND GetD3DWnd() { return m_hDisplayWnd;}

public:
	GS3DDisplay(UINT bufW, UINT bufH);
	GS3DDisplay(ID3D11Device* pDevice);
	virtual ~GS3DDisplay();
	HRESULT ShowDisplayWnd(BOOL bShow);
	HWND GetDisplayWindow() { return m_hDisplayWnd;}

	virtual HRESULT SetRenderTarget(ID3D11RenderTargetView* pRenderTarget);
	virtual HRESULT ResetRenderTarget();

	virtual HRESULT Render();
	virtual HRESULT Render(ID3D11Texture2D* pTexture);
	virtual BOOL IsDeviceFromOther();

	static LRESULT CALLBACK D3DDisplayWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};