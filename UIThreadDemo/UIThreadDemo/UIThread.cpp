// UIThread.cpp : implementation file
//

#include "stdafx.h"
#include "UIThreadDemo.h"
#include "UIThread.h"
#include "MainFrm.h"


// CUIThread

IMPLEMENT_DYNCREATE(CUIThread, CWinThread)

CUIThread::CUIThread()
{
}

CUIThread::~CUIThread()
{
}

BOOL CUIThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;

	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);

	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();

	return TRUE;
}

int CUIThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	g_pUIThread = NULL;
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CUIThread, CWinThread)
END_MESSAGE_MAP()


// CUIThread message handlers
