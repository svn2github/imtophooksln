#ifndef _MSSD3DCLASS_H
#define _MSSD3DCLASS_H
#include <d3dx9.h>
#include <stack>
using namespace std;
class IMS3DObj
{
public:
	virtual D3DXMATRIX GetTransform() = 0;
	virtual BOOL Translate(D3DXVECTOR3& t) = 0;
	virtual BOOL Rotate(D3DXVECTOR3& rot) = 0;
	virtual BOOL Scale(D3DXVECTOR3& s) = 0;
	virtual BOOL ResetTransform() = 0;
	virtual BOOL PushMatrix() = 0;
	virtual BOOL PopMatrix()= 0;
};

class MS3DObj : public IMS3DObj
{
protected:
	D3DXMATRIX m_matWorld;
	stack<D3DXMATRIX> m_matStack;
public:
	MS3DObj();
	~MS3DObj();
	virtual D3DXMATRIX GetTransform();
	virtual BOOL Translate(D3DXVECTOR3& t);
	virtual BOOL Rotate(D3DXVECTOR3& rot);
	virtual BOOL Scale(D3DXVECTOR3& s);
	virtual BOOL ResetTransform();
	virtual BOOL PushMatrix();
	virtual BOOL PopMatrix();
};

class IMeshObj
{
public:
	virtual IDirect3DVertexBuffer9* GetVertexBuffer() = 0;
	virtual IDirect3DIndexBuffer9* GetIndexBuffer() = 0;
	virtual UINT GetVertexNumber() = 0;
	virtual UINT GetPrimitiveNumber() = 0;
	virtual DWORD GetVertexFMT() = 0;
	virtual D3DFORMAT GetIndexFMT() = 0;
};

class MS3DPlane : public IMeshObj, public MS3DObj
{
public:
	struct CUSTOMVERTEX
	{
		D3DXVECTOR3 position; // The position
		D3DXVECTOR3 normal;
		FLOAT       tu, tv;   // The texture coordinates
	};
private:
	void ReleaseResource();
protected:
	IDirect3DDevice9* m_pDevice;
	IDirect3DVertexBuffer9* m_pVertices;
	IDirect3DIndexBuffer9* m_pIndices;
	DWORD m_vertexFMT;
	D3DFORMAT m_indexFMT;
public:
	MS3DPlane(IDirect3DDevice9* pDevice);
	~MS3DPlane();

	virtual BOOL InitGeometry();
	virtual IDirect3DVertexBuffer9* GetVertexBuffer();
	virtual IDirect3DIndexBuffer9* GetIndexBuffer();
	virtual UINT GetVertexNumber();
	virtual UINT GetPrimitiveNumber();
	virtual DWORD GetVertexFMT();
	virtual D3DFORMAT GetIndexFMT();

};
#endif

