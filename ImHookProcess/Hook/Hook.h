// 下列 ifdef 區塊是建立巨集以協助從 DLL 匯出的標準方式。
// 這個 DLL 中的所有檔案都是使用命令列中所定義 HOOK_EXPORTS 符號編譯的。
// 任何使用這個 DLL 的專案都不應定義這個符號。
// 這樣一來，原始程式檔中包含這檔案的任何其他專案
// 會將 HOOK_API 函式視為從 DLL 匯入的，而這個 DLL 則會將這些符號視為
// 匯出的。
#ifdef HOOK_EXPORTS
#define HOOK_API __declspec(dllexport)
#else
#define HOOK_API __declspec(dllimport)
#endif

#define HOOKED_WNDDESTORY_MSG L"HOOKED_WNDDESTORY_MSG-14407E4C-9A6E-4b85-A13E-01AC3F516964"
#define HOOKED_DOHOOKCREATEDEVICE_MSG L"HOOKED_WNDDESTORY_MSG-D9D9FDF7-C71B-43e2-8BCD-7D4952329221"
#define HOOKED_ENABLEEDITWARP_MSG L"HOOKED_ENABLEEDITWARP_MSG-9B837148-0CE0-4878-8B01-3C0A26B509B2"

namespace HOOKAPI
{
	HOOK_API bool SetHookClient(HWND hClient);
	HOOK_API bool GetHookClient(HWND& clientWnd);
}