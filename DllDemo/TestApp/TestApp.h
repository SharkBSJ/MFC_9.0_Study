
// TestApp.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CTestAppApp:
// �� Ŭ������ ������ ���ؼ��� TestApp.cpp�� �����Ͻʽÿ�.
//

class CTestAppApp : public CWinApp
{
public:
	CTestAppApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CTestAppApp theApp;