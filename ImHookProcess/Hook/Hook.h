// �U�C ifdef �϶��O�إߥ����H��U�q DLL �ץX���зǤ覡�C
// �o�� DLL �����Ҧ��ɮ׳��O�ϥΩR�O�C���ҩw�q HOOK_EXPORTS �Ÿ��sĶ���C
// ����ϥγo�� DLL ���M�׳������w�q�o�ӲŸ��C
// �o�ˤ@�ӡA��l�{���ɤ��]�t�o�ɮת������L�M��
// �|�N HOOK_API �禡�����q DLL �פJ���A�ӳo�� DLL �h�|�N�o�ǲŸ�����
// �ץX���C
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