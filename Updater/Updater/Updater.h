
// Updater.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CUpdaterApp:
// �� Ŭ������ ������ ���ؼ��� Updater.cpp�� �����Ͻʽÿ�.
//

class CUpdaterApp : public CWinApp
{
public:
	CUpdaterApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CUpdaterApp theApp;