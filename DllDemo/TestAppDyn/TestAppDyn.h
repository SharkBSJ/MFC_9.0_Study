
// TestAppDyn.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CTestAppDynApp:
// �� Ŭ������ ������ ���ؼ��� TestAppDyn.cpp�� �����Ͻʽÿ�.
//

class CTestAppDynApp : public CWinApp
{
public:
	CTestAppDynApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CTestAppDynApp theApp;