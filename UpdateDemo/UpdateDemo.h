
// UpdateDemo.h : UpdateDemo ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.
#include "afxmt.h"


// CUpdateDemoApp:
// �� Ŭ������ ������ ���ؼ��� UpdateDemo.cpp�� �����Ͻʽÿ�.
//

class CUpdateDemoApp : public CWinAppEx
{
public:
	CUpdateDemoApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	CEvent m_ExitEvent;
	CEvent m_UpdateEvent;
	static UINT ThreadUpdate(LPVOID nParam);
};

extern CUpdateDemoApp theApp;
