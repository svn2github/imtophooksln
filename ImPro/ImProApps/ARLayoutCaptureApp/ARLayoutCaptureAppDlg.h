// ARLayoutCaptureAppDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "ARLayoutCameraDS.h"
#include "afxcmn.h"
#include <map>
using namespace std;
// CARLayoutCaptureAppDlg dialog
class CARLayoutCaptureAppDlg : public CDialog
{
// Construction
public:
	CARLayoutCaptureAppDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_ARLAYOUTCAPTUREAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	ARLayoutCameraDS* m_pDSCam;
	IplImage* m_pBG;
	IplImage* m_pCaptureFrame;
	IplImage* m_pDiff;
	IplImage* m_pCroppedDiff;
	IplImage* m_pTmpImage;
	IplImage* m_pROITmpImage;
	UINT m_CaptureTimer;
	int m_nAvgFrame;
	HICON m_hIcon;
	HWND m_hWndCaptureWnd;
	map<CString, int> m_CamDevice;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	int m_curTag;
	BOOL NextTag();
	BOOL LastTag();
	BOOL ShowCurTag();
	BOOL ClearTag();
	BOOL CaptureBG();
	BOOL CaptureTag();
	BOOL CaptureCamFrame(IplImage*& pFrame);
	BOOL GenerateDiff();
	BOOL ComputeDiffROI(int threshold, fRECT& roiRECT,BOOL bDrawOnDiff = false);
	BOOL GenerateCroppedDiff(fRECT* roi = NULL);
	BOOL GenerateCropDiff();
	BOOL GetSavePath(WCHAR* path, WCHAR* imageFolder, WCHAR* confName);
	BOOL SaveCroppedDiff(WCHAR* path);
	BOOL CaptureCurrentShot();
public:
	CButton m_btnOpenCam;
	CButton m_btnCloseCam;
	CButton m_btnPlay;
	CButton m_btnPause;
	CButton m_btnStop;
	CButton m_btnSaveGraph;
	CButton m_btnARProp;
	CButton m_btnARWarpProp;
	CButton m_btnDXRenderProp;
	CButton m_btnCamProp;
	CButton m_btnCamWarpProp;
	CButton m_btnCamPinProp;
	afx_msg void OnBnClickedbtnopencamera();
	afx_msg void OnDestroy();
	CStatic m_camView;

	afx_msg void OnBnClickedbtndestorycamera();
	afx_msg void OnBnClickedbtnplay();
	afx_msg void OnBnClickedbtnpasue();
	afx_msg void OnBnClickedbtnstop();
	afx_msg void OnBnClickedbtnsavegraph();
	afx_msg void OnBnClickedbtnarprop();
	afx_msg void OnBnClickedbtnarwarpprop();
	afx_msg void OnBnClickedbtndxrenderprop();
	afx_msg void OnBnClickedbtncamprop();
	afx_msg void OnBnClickedbtncampinprop();
	afx_msg void OnBnClickedbtncamwarp();
	CButton m_btnLastTag;
	CButton m_btnNextTag;
	CStatic m_txtCurTag;
	afx_msg void OnBnClickedbtnlasttag();
	afx_msg void OnBnClickedbtnnexttag();
	CButton m_btnClear;
	afx_msg void OnBnClickedbtnclear();
	CButton m_btnCaptureBG;
	CButton m_btnCaptureTag;
	afx_msg void OnBnClickedbtncapturebg();
	CComboBox m_cbAvgFrame;
	afx_msg void OnCbnSelchangecbavgframe();
	afx_msg void OnBnClickedbtncapturetag();
	CButton m_btnShowDiff;
	CButton m_btnCropDiff;
	afx_msg void OnBnClickedbtnshowdiff();
	CSliderCtrl m_slrROIThreshold;
	CStatic m_txtROIThreshold;
//	afx_msg void OnTRBNThumbPosChangingslrroithreshold(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnNMThemeChangedslrroithreshold(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawslrroithreshold(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedbtncropdiff();
	afx_msg void OnBnClickedbtnbrowse();
	CEdit m_edSavePath;
	CButton m_btnStartAutoCapture;
	afx_msg void OnBnClickedbtnstartautocapture();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CComboBox m_cbCam1;
	CButton m_btnSaveCurShot;
	afx_msg void OnBnClickedbtnsavecurshot();
	afx_msg void OnCbnSelendcancelcbcam1();
	CComboBox m_cbCam2;
	CComboBox m_cbCam3;
	CComboBox m_cbCam4;
	afx_msg void OnCbnSelchangecbcam2();
	CButton m_btnCamProp2;
	CButton m_btnCamProp3;
	CButton m_btnCamProp4;
	CButton m_btnCamPinProp2;
	CButton m_btnCamPinProp3;
	CButton m_btnCamPinProp4;
	CButton m_btnCamWarp2;
	CButton m_btnCamWarp3;
	CButton m_btnCamWarp4;
	afx_msg void OnBnClickedbtncamprop2();
	afx_msg void OnBnClickedbtncampinprop2();
	afx_msg void OnBnClickedbtncamwarp2();
	afx_msg void OnCbnSelchangecbcam3();
	afx_msg void OnCbnSelchangecbcam4();
	CButton m_btnDXBlendProp;
	afx_msg void OnBnClickedbtndxblendprop();
	CButton m_btnProjectSetting;
	afx_msg void OnBnClickedbtnprojectsetting();
	CButton m_btnBlendWarpProp;
	afx_msg void OnBnClickedbtnblendwarpprop();
	CButton m_btnUndist1;
	CButton m_btnUndist2;
	CButton m_btnUndist4;
	CButton m_btnUndist3;

	afx_msg void OnBnClickedbtnundist1();
	afx_msg void OnBnClickedbtnundist2();
};
