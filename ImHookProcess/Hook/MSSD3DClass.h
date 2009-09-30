#ifndef _MSSD3DCLASS_H
#define _MSSD3DCLASS_H
#include <d3dx9.h>
#include <D3dx9math.h> 
#include <assert.h>
#include <vector>
#include <map>
using namespace std;

class IEventManager
{
protected:
	vector<IEventManager*> m_Children;
	IEventManager* m_pParent;
	BOOL m_bMouseOver;
	BOOL m_bStargDrag;
	virtual BOOL SetParent(IEventManager* parent);
	virtual BOOL AddChild(IEventManager* child);
	virtual BOOL RemoveChild(IEventManager* child);
public:
	IEventManager(){ m_pParent = NULL; m_bStargDrag = FALSE; m_bMouseOver = FALSE;}
	~IEventManager()
	{
		if (m_pParent != NULL)
			m_pParent->RemoveChild(this);
	}
	typedef BOOL (__stdcall* TaskFuncPtr)(void*, WPARAM, LPARAM, void*);
	virtual BOOL HitTest(D3DXVECTOR3& vPos, D3DXVECTOR3& vDir) = 0;
	virtual BOOL PassMouseMessage(UINT message, WPARAM wParam, LPARAM lParam, D3DXVECTOR3& vPos, D3DXVECTOR3& vDir) = 0;
	virtual BOOL WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;
	virtual BOOL Bind(WCHAR* msg, TaskFuncPtr pFunc , void* _THIS) = 0;
	virtual BOOL UnBind(WCHAR* msg, TaskFuncPtr pFunc, void* _THIS) = 0;
	virtual BOOL Invoke(WCHAR* msg, WPARAM wParam, LPARAM lParam, void* pData) = 0;
};

class MSEventManager : public IEventManager
{
protected:
	class cmp_wstr 
	{
	public:
		bool operator()(WCHAR const *a, WCHAR const *b) 
		{
			return wcscmp(a, b) < 0;
		}
	};


	struct EventTask
	{
		IEventManager::TaskFuncPtr funcPtr;
		void* _THIS;
		EventTask(IEventManager::TaskFuncPtr funcptr, void* _this)
		{
			funcPtr = funcptr; _THIS = _this;
		}
		bool operator == (const EventTask& e2)
		{
			if ((funcPtr == e2.funcPtr) && (_THIS == e2._THIS))
				return true;
			else
			{
				return false;
			}
		}
	};
	map<WCHAR*, vector<EventTask>, cmp_wstr > m_EventTable;

public:
	MSEventManager(IEventManager* parent = NULL);
	~MSEventManager();
	virtual BOOL HitTest(D3DXVECTOR3& vPos, D3DXVECTOR3& vDir);
	virtual BOOL WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL Bind(WCHAR* msg, TaskFuncPtr pFunc , void* _THIS);
	virtual BOOL UnBind(WCHAR* msg, TaskFuncPtr pFunc, void* _THIS);
	virtual BOOL Invoke(WCHAR* msg, WPARAM wParam, LPARAM lParam, void* pData);
	virtual BOOL PassMouseMessage(UINT message, WPARAM wParam, LPARAM lParam, D3DXVECTOR3& vPos, D3DXVECTOR3& vDir) ;
};
class MSDXBase
{
protected:
	IDirect3DDevice9* m_pDevice;
public:
	MSDXBase()
	{
		m_pDevice = NULL;
	}
	MSDXBase(IDirect3DDevice9* pDevice)
	{
		m_pDevice = pDevice;
		if (pDevice != NULL)
			m_pDevice->AddRef();
	}
	virtual ~MSDXBase()
	{
		if (m_pDevice != NULL)
		{
			m_pDevice->Release();
			m_pDevice = NULL;
		}
	}
};

class IRenderBase
{	
public:
	virtual BOOL Render() = 0;
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture) = 0;
};

class ITransformHierarchy
{
public:
	BOOL PushMatrix();
	BOOL PopMatrix();
	BOOL AddTransform(D3DXMATRIX* pmat);
	D3DXMATRIX GetTransform();
};


class IMS3DBase
{
public:
	virtual D3DXMATRIX GetTransform() = 0;
	virtual BOOL Translate(D3DXVECTOR3& t) = 0;
	virtual BOOL RotateAxis(CONST D3DXVECTOR3 * pV, FLOAT angle) = 0;
	virtual BOOL Scale(D3DXVECTOR3& s) = 0;
	virtual BOOL ResetTransform() = 0;
	virtual BOOL PushMatrix() = 0;
	virtual BOOL PopMatrix()= 0;
};

class MS3DObj : public IMS3DBase
{
protected:
	ID3DXMatrixStack* m_pMatrixStack;
public:
	MS3DObj();
	virtual ~MS3DObj();
	virtual D3DXMATRIX GetTransform();
	virtual BOOL Translate(D3DXVECTOR3& t);
	virtual BOOL RotateAxis(CONST D3DXVECTOR3 * pV, FLOAT angle);
	virtual BOOL Scale(D3DXVECTOR3& s);
	virtual BOOL ResetTransform();
	virtual BOOL PushMatrix();
	virtual BOOL PopMatrix();
	virtual BOOL SetPosition(D3DXVECTOR3 pos);
	virtual D3DXVECTOR3 GetPosition();
};

class IMeshBase
{
public: 
	virtual IDirect3DVertexBuffer9* GetVertexBuffer() = 0;
	virtual IDirect3DIndexBuffer9* GetIndexBuffer() = 0;
	virtual UINT GetVertexNumber() = 0;
	virtual UINT GetPrimitiveNumber() = 0;
};

class MSMeshBase : public IMeshBase, public MSDXBase, public IRenderBase
{
public:
	struct CUSTOMVERTEX
	{
		D3DXVECTOR3 position; // The position
		D3DXVECTOR3 normal;
		FLOAT       tu, tv;   // The texture coordinates
	};
protected:
	LPD3DXMESH m_pMesh;
	D3DCOLOR m_color;
protected:
	MSMeshBase();
public:
	virtual BOOL InitGeometry() 
	{ /* implement this function in the derived class*/ 
		assert(L"@@@@  InitGeometry doesn't been implemented!!");
		return FALSE;
	};
public:
	MSMeshBase(IDirect3DDevice9* pDevice);
	virtual ~MSMeshBase();
	virtual IDirect3DVertexBuffer9* GetVertexBuffer();
	virtual IDirect3DIndexBuffer9* GetIndexBuffer();
	virtual UINT GetVertexNumber();
	virtual UINT GetPrimitiveNumber();
	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	virtual BOOL GetVertex(UINT idx, CUSTOMVERTEX& vertex);
	virtual BOOL SetVertex(UINT idx, CUSTOMVERTEX& vertex);
	virtual LPD3DXMESH GetMesh();
};

class MS3DPlane : public MSMeshBase, public MS3DObj
{
private:
	virtual BOOL InitGeometry();
public:
	MS3DPlane(IDirect3DDevice9* pDevice);
	virtual ~MS3DPlane();
	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);

};

class IMSCamera
{
public:
	virtual BOOL SetEyePos(D3DXVECTOR3& vEyePt) = 0;
	virtual BOOL SetLookAt(D3DXVECTOR3& vLookPt) = 0;
	virtual BOOL SetUpVec(D3DXVECTOR3& vUpVec) = 0;
	virtual D3DXVECTOR3 GetEyePos() = 0;
	virtual D3DXVECTOR3 GetLookAt() = 0;
	virtual D3DXVECTOR3 GetUpVec() = 0;
	virtual BOOL CameraOn() = 0;
	virtual BOOL CameraOff() = 0;
	virtual D3DXMATRIX GetViewMatrix() = 0;
	virtual D3DXMATRIX GetProjMatrix() = 0;

};

class MSCamera : public MSDXBase, public IMSCamera
{
private:
	D3DXMATRIX m_BackupMatView;
	D3DXMATRIX m_BackupMatProj;
	BOOL init();
protected:
	D3DXVECTOR3 m_vEyePt;
	D3DXVECTOR3 m_vLookatPt;
	D3DXVECTOR3 m_vUpVec;
	float m_l ;//		[in] Minimum x-value of view volume. 
	float m_r ;//		[in] Maximum x-value of view volume. 
	float m_b ;//		[in] Minimum y-value of view volume. 
	float m_t ;//   	[in] Maximum y-value of view volume. 
	float m_zn;//		[in] Minimum z-value of the view volume. 
	float m_zf;//		[in] Maximum z-value of the view volume. 

public:
	MSCamera();
	MSCamera(IDirect3DDevice9* pDevice);
	virtual ~MSCamera();
	virtual BOOL SetEyePos(D3DXVECTOR3& vEyePt);
	virtual BOOL SetLookAt(D3DXVECTOR3& vLookPt);
	virtual BOOL SetUpVec(D3DXVECTOR3& vUpVec);
	virtual D3DXVECTOR3 GetEyePos();
	virtual D3DXVECTOR3 GetLookAt();
	virtual D3DXVECTOR3 GetUpVec();
	virtual BOOL CameraOn();
	virtual BOOL CameraOff();
	virtual D3DXMATRIX GetViewMatrix();
	virtual D3DXMATRIX GetProjMatrix();
	virtual BOOL Screen2World(HWND hwnd, int x, int y, D3DXVECTOR3& vPos, D3DXVECTOR3& vDir);
};

class MS3DButton : public MS3DPlane, public MSEventManager
{

public:
	MS3DButton(IDirect3DDevice9* pDevice, IEventManager* parent): MS3DPlane(pDevice), MSEventManager(parent)
	{
		
		Bind(L"WM_LBUTTONDOWN\0", MS3DButton::OnMouseLDown, this);
		Bind(L"WM_LBUTTONUP\0", MS3DButton::OnMouseLUp, this);
		Bind(L"WM_MOUSEMOVE\0", MS3DButton::OnMouseMove, this);
		Bind(L"WM_MOUSEENTER\0", MS3DButton::OnMouseEnter, this);
		Bind(L"WM_MOUSELEAVE\0", MS3DButton::OnMouseLeave, this);
		Bind(L"WM_MOUSEDRAGMOVE\0", MS3DButton::OnMouseDragMove, this);
	};
	virtual BOOL HitTest(D3DXVECTOR3& vPos, D3DXVECTOR3& vDir);
	static BOOL __stdcall OnMouseLDown(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);
	static BOOL __stdcall OnMouseLUp(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);
	static BOOL __stdcall OnMouseMove(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);
	static BOOL __stdcall OnMouseEnter(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);
	static BOOL __stdcall OnMouseLeave(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);
	static BOOL __stdcall OnMouseDragMove(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);
};

class MS3DDisplay : public IRenderBase, public MSEventManager, public MSDXBase
{
protected:
	HWND m_hDisplayWnd;
	IDirect3D9* m_pD3D;
	MS3DPlane* m_pDisplayPlane;
	MSCamera* m_pCamera;
	LPDIRECT3DTEXTURE9 m_pRenderTarget;
	vector<MS3DButton*> m_pWarpButtons;
	BOOL m_bStartDrag; 
	map<HWND, LPDIRECT3DTEXTURE9> m_winTextures;
	CRITICAL_SECTION m_CS;
private:
	HANDLE m_hRenderThread;
	BOOL m_bEditWarp;
	BOOL InitDevice();
	static BOOL _Run(void* _THIS);
	BOOL CreateTexture();
	BOOL CreateWarpButtons();
	BOOL ClearWarpButtons();
	BOOL IntersectWithPlane(D3DXVECTOR3 vPos, D3DXVECTOR3 vDir, BOOL& bHit, float& tU, float& tV);
public:
	MS3DDisplay(HWND hWnd, IDirect3D9* pD3D);
	virtual ~MS3DDisplay();
	virtual BOOL Run();
	virtual BOOL Stop();
	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	virtual BOOL SetEditWarpEnable(BOOL enable);
	virtual BOOL WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL HitTest(D3DXVECTOR3& vPos, D3DXVECTOR3& vDir);
	virtual BOOL DrawBitBlt(HDC hdc, int x, int y, int cx, int cy, int dcW, int dcH, HDC hdcSrc, int x1, int y1, DWORD rop);
public:
	static BOOL __stdcall onWarpButtonLDown(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);
	static BOOL __stdcall onWarpButtonLUp(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);
	static BOOL __stdcall onWarpButtonDragMove(void* _THIS, WPARAM wParam, LPARAM lParam, void* pData);


};









#endif

