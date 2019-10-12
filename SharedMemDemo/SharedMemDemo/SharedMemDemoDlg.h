
// SharedMemDemoDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CSharedMemDemoDlg ��ȭ ����
class CSharedMemDemoDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CSharedMemDemoDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SHAREDMEMDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
