#ifndef _MSSD3DCLASS_H
#define _MSSD3DCLASS_H
#include <d3dx9.h>
#include <D3dx9math.h> 
#include <assert.h>

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
		pDevice->AddRef();
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
};

class IMeshBase
{
public: 
	virtual IDirect3DVertexBuffer9* GetVertexBuffer() = 0;
	virtual IDirect3DIndexBuffer9* GetIndexBuffer() = 0;
	virtual UINT GetVertexNumber() = 0;
	virtual UINT GetPrimitiveNumber() = 0;
	virtual DWORD GetVertexFMT() = 0;
	virtual D3DFORMAT GetIndexFMT() = 0;
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
	IDirect3DVertexBuffer9* m_pVertices;
	IDirect3DIndexBuffer9* m_pIndices;
	DWORD m_vertexFMT;
	D3DFORMAT m_indexFMT;
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
	virtual DWORD GetVertexFMT();
	virtual D3DFORMAT GetIndexFMT();
	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
	
};

class MS3DPlane : public MSMeshBase, public MS3DObj
{
public:
	MS3DPlane(IDirect3DDevice9* pDevice);
	virtual ~MS3DPlane();
	virtual BOOL InitGeometry();
	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);

};

class IMSCamera
{
public:
	virtual BOOL SetEyePos(D3DXVECTOR3& vEyePt) = 0;
	virtual BOOL SetLookAt(D3DXVECTOR3& vLookPt) = 0 ;
	virtual BOOL SetUpVec(D3DXVECTOR3& vUpVec) = 0;
	virtual D3DXVECTOR3 GetEyePos() = 0;
	virtual D3DXVECTOR3 GetLookAt() = 0;
	virtual D3DXVECTOR3 GetUpVec() = 0;
	virtual BOOL CameraOn() = 0;
	virtual BOOL CameraOff() = 0;
};

class MSCamera : public MSDXBase, public IMSCamera
{
private:
	D3DXMATRIX m_pBackupMatView;
	BOOL init();
protected:
	D3DXVECTOR3 m_vEyePt;
	D3DXVECTOR3 m_vLookatPt;
	D3DXVECTOR3 m_vUpVec;
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
};


class MS3DDisplay : IRenderBase
{
protected:
	HWND m_hDisplayWnd;
	IDirect3D9* m_pD3D;
	IDirect3DDevice9* m_pDevice;
	MS3DPlane* m_pDisplayPlane;
	IDirect3DBaseTexture9* m_pTexture;
	MSCamera* m_pCamera;


private:
	HANDLE m_hRenderThread;
	BOOL InitDevice();
	static BOOL _Run(void* _THIS);
public:
	MS3DDisplay(HWND hWnd, IDirect3D9* pD3D);
	virtual ~MS3DDisplay();
	virtual BOOL Run();
	virtual BOOL Stop();
	virtual BOOL Render();
	virtual BOOL Render(IDirect3DBaseTexture9* pTexture);
};









#endif

