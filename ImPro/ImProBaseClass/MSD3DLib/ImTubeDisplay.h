#pragma once

#include "ImTopDisplay.h"

class ImTubeDisplay : public ImTopDisplay
{
	struct FAN
	{
		D3DXVECTOR2 center;
		D3DXVECTOR2 point[5];
		float r;
		float distance;
		int parallel; // 0 == 平行 1 == 上半圓 -1 == 下半圓
		float start;
		float eqA,eqB,eqC,eqD,eqE,eqF; // 紀錄二次曲線的參數
	};

protected:
	float cofA1, cofB1, cofC1, cofD1, cofE1, cofA2, cofB2, cofC2, cofD2, cofE2;
	float cofAx, cofBx, cofCx, cofDx, cofEx; 
	virtual ID3DXEffect* GetEffect();
private:
	BOOL CreateTTSButtons();
	BOOL ClearTTSButtons();
	BOOL UpdateTTSByTTSButtons();
	BOOL ComputeTTSCurve(const D3DXVECTOR2& v1, const D3DXVECTOR2& v2, const D3DXVECTOR2& v3, const D3DXVECTOR2& v4, const D3DXVECTOR2& v5,
		float& cofA,float& cofB, float& cofC, float& cofD, float& cofE);
	//void Cal_Center(struct FAN *a); 
	void SolveCurve(D3DXVECTOR2 v1, D3DXVECTOR2 v2,D3DXVECTOR2 v3,D3DXVECTOR2 v4, D3DXVECTOR2 v5,
		float& cofA, float& cofB, float& cofC, float& cofD, float& cofE);
	float CurveFunc(float Xin, float cofA, float cofB, float cofC, 
		float cofD, float cofE);
public:
	ImTubeDisplay(HWND hWnd, IDirect3D9* pD3D);
	virtual ~ImTubeDisplay();

	virtual BOOL WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture, ID3DXEffect* pEffect);
public:

	static BOOL __stdcall onTTSButtonLDown(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);
	static BOOL __stdcall onTTSButtonLUp(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);
	static BOOL __stdcall onTTSButtonDragMove(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);
};

