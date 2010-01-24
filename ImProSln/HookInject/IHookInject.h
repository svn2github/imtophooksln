// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the HOOKINJECT_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// HOOKINJECT_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef HOOKINJECT_EXPORTS
#define HOOKINJECT_API __declspec(dllexport)
#else
#define HOOKINJECT_API __declspec(dllimport)
#endif

#define HOOKED_BITBLTCALLED_MSG L"HOOKED_BITBLTCALLED_MSG-797EC903-BBA7-473f-B671-EA34E8068ECB"
#define HOOKED_SETHOOKCLIENT_MSG L"HOOKED_RESETWNDPROC_MSG-49353183-2419-4f6a-AC41-C663EFDCEB1F"
#define HOOKED_WNDDESTORY_MSG L"HOOKED_WNDDESTORY_MSG-14407E4C-9A6E-4b85-A13E-01AC3F516964"
#define HOOKED_DOHOOKCREATEDEVICE_MSG L"HOOKED_WNDDESTORY_MSG-D9D9FDF7-C71B-43e2-8BCD-7D4952329221"

namespace HOOKINJECT
{

	HOOKINJECT_API class DrawBitBltCommand
	{
	public:
		HDC m_hdc;
		int m_x;
		int m_y;
		int m_width;
		int m_height;
		HDC m_hdcSrc;
		int m_x1;
		int m_y1;
		DWORD m_rop;
		HOOKINJECT_API DrawBitBltCommand();
		HOOKINJECT_API DrawBitBltCommand(HDC hdc,int x,int y,int width,
			int height, HDC hdcSrc, int x1, int y1, DWORD rop);
	};
	HOOKINJECT_API bool PushBitBltCmd(DrawBitBltCommand& cmd);
	HOOKINJECT_API bool PopBitBltCmd(DrawBitBltCommand& cmd);
	HOOKINJECT_API bool ClearBitBltCmd();

	HOOKINJECT_API bool SetHookServerProcID(DWORD procID);
	HOOKINJECT_API bool GetHookServerProcID(DWORD& procID);
	HOOKINJECT_API bool SetHookServer(HWND hServerWnd);
	HOOKINJECT_API bool GetHookServer(HWND& hServerWnd);
	HOOKINJECT_API bool SetHookClient(HWND hClientWnd);
	HOOKINJECT_API bool GetHookClient(HWND& hClientWnd);
};