
// SharedMemDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.
#include "afxmt.h"


// CSharedMemDemoApp:
// �� Ŭ������ ������ ���ؼ��� SharedMemDemo.cpp�� �����Ͻʽÿ�.
//

class CSharedMemDemoApp : public CWinApp
{
public:
	CSharedMemDemoApp();
	HANDLE m_hMap;
	TCHAR* m_pSharedMemory;
	CMutex m_Mutex;
	CEvent m_ExitEvent;
	CEvent m_ReadEvent;

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	DECLARE_MESSAGE_MAP()
	BOOL InitSharedMemory(void);
	int ExitInstance(void);
	static UINT ThreadReadSharedMemory(LPVOID nParam);
};

extern CSharedMemDemoApp theApp;