
// ThreadCrashDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CThreadCrashDemoApp:
// �� Ŭ������ ������ ���ؼ��� ThreadCrashDemo.cpp�� �����Ͻʽÿ�.
//

class CThreadCrashDemoApp : public CWinApp
{
public:
	CThreadCrashDemoApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CThreadCrashDemoApp theApp;