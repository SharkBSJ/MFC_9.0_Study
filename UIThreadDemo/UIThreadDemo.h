
// UIThreadDemo.h : UIThreadDemo ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CUIThreadDemoApp:
// �� Ŭ������ ������ ���ؼ��� UIThreadDemo.cpp�� �����Ͻʽÿ�.
//

class CUIThreadDemoApp : public CWinApp
{
public:
	CUIThreadDemoApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CUIThreadDemoApp theApp;
