// MSPersist.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MSPersist.h"
#include <vector>
#include <algorithm>
using namespace std;
vector<IMSPersist*> g_pInstances;
CMSPersist::CMSPersist()
{
	g_pInstances.push_back(this);
	return;
}

CMSPersist::~CMSPersist()
{
	vector<IMSPersist*>::iterator iter = ::find(g_pInstances.begin(), g_pInstances.end(), this );
	if (iter != g_pInstances.end())
	{
		g_pInstances.erase(iter);
	}
	return;
}

int CMSPersist::GetNumPersistInstance()
{
	return g_pInstances.size();
}
HRESULT CMSPersist::GetPersistInstance(UINT idx, IMSPersist*& pInst)
{
	if (idx >= g_pInstances.size())
		return S_FALSE;
	pInst = g_pInstances.at(idx);
	return S_OK;
}
