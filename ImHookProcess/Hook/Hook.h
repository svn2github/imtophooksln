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
#define HOOKED_ENABLEEDITWARP_LOW_MSG L"HOOKED_ENABLEEDITWARP_LOW_MSG-9B837148-0CE0-4878-8B01-3C0A26B509B2"
#define HOOKED_ENABLEEDITTTS_LOW_MSG  L"HOOKED_ENABLEEDITTTS_LOW_MSG-E66750D3-847C-452e-B802-FA10EF6155CF"
#define HOOKED_ENABLEEDITWARP_HIGH_MSG L"HOOKED_ENABLEEDITWARP_HIGH_MSG-3BD120A6-1B2F-4af8-AED4-F7447113D442"
#define HOOKED_ENABLEEDITTTS_HIGH_MSG  L"HOOKED_ENABLEEDITTTS_HIGH_MSG-{98670294-C8DA-4913-89AD-2FAC1CE2F03E"


#define HOOKED_SETTTS_LOW_MSG  L"HOOKED_SETTTS_LOW_MSG-09D2A1A6-5E27-42a1-B003-85F92CA25896"
#define HOOKED_SETTTS_HIGH_MSG  L"HOOKED_SETTTS_HIGH_MSG-505210C2-861F-42bb-9419-CF69C5F32F98"

namespace HOOKAPI
{
	HOOK_API bool SetHookClient(HWND hClient);
	HOOK_API bool GetHookClient(HWND& clientWnd);
	HOOK_API bool SetTTSRegion_Low(float v1_x, float v1_y, float v2_x, float v2_y, 
		float v3_x, float v3_y, float v4_x, float v4_y);
	HOOK_API bool GetTTSRegion_Low(float& v1_x, float& v1_y, float& v2_x, float& v2_y, 
		float& v3_x, float& v3_y, float& v4_x, float& v4_y); 
	HOOK_API bool SetTTSRegion_High(float v1_x, float v1_y, float v2_x, float v2_y, 
		float v3_x, float v3_y, float v4_x, float v4_y);
	HOOK_API bool GetTTSRegion_High(float& v1_x, float& v1_y, float& v2_x, float& v2_y, 
		float& v3_x, float& v3_y, float& v4_x, float& v4_y);

}