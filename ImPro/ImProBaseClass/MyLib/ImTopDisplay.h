#pragma once
#include "MSSD3DClass.h"

class ImTopDisplay : public MS3DDisplay
{
protected:
	D3DXMATRIX m_matMaskTransform;
	D3DXVECTOR2 m_captureRect[2];
	LPDIRECT3DTEXTURE9 m_pMaskTexture;
	D3DXMATRIX m_matTTS;

	vector<MS3DButton*> m_pWarpButtons;
	vector<MS3DButton*> m_pTTSButtons;
	BOOL m_bStartDrag; 

	BOOL m_bEditWarp;
	BOOL m_bEditTTS;
	BOOL m_bMaskEnable;
	virtual BOOL CreateWarpButtons();
	virtual BOOL ClearWarpButtons();
	virtual BOOL CreateTTSButtons();
	virtual BOOL ClearTTSButtons();
	virtual BOOL UpdateTTSByTTSButtons();
private:

	D3DXMATRIX ComputeTTS(const D3DXVECTOR2& v1, const D3DXVECTOR2& v2, const D3DXVECTOR2& v3, const D3DXVECTOR2& v4);
public:
	ImTopDisplay(HWND hWnd, IDirect3D9* pD3D);
	virtual ~ImTopDisplay();
	virtual BOOL SetEditWarpEnable(BOOL enable);
	virtual BOOL SetEditTTSEnable(BOOL enable);
	virtual BOOL SetTTS(const D3DXVECTOR2 v1, const D3DXVECTOR2 v2, const D3DXVECTOR2 v3, const D3DXVECTOR2 v4);
	virtual BOOL SetCaptureRegion(float l, float t, float r, float b);
	virtual BOOL GetCaptureRegion(float& l, float& t, float& r, float &b);
	virtual BOOL WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL DrawBitBlt(HDC hdc, int x, int y, int cx, int cy, int dcW, int dcH, HDC hdcSrc, int x1, int y1, int srcW, int srcH, DWORD rop);
	virtual BOOL LoadMaskTextureFromFile(WCHAR* path);
	virtual BOOL SetMaskPos(float tx, float ty, float sx, float sy);

	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect);
public:
	static BOOL __stdcall onWarpButtonLDown(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);
	static BOOL __stdcall onWarpButtonLUp(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);
	static BOOL __stdcall onWarpButtonDragMove(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);

	static BOOL __stdcall onTTSButtonLDown(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);
	static BOOL __stdcall onTTSButtonLUp(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);
	static BOOL __stdcall onTTSButtonDragMove(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);
};

