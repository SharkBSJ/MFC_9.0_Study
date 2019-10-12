
// SharedMemDemoDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CSharedMemDemoDlg 대화 상자
class CSharedMemDemoDlg : public CDialogEx
{
// 생성입니다.
public:
	CSharedMemDemoDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SHAREDMEMDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnRecvEvent(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	CListBox m_List;
public:
	afx_msg void OnBnClickedButtonSend();
	CString m_csMessage;
};
