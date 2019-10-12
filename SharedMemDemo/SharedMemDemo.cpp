
// SharedMemDemo.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "SharedMemDemo.h"
#include "SharedMemDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSharedMemDemoApp

BEGIN_MESSAGE_MAP(CSharedMemDemoApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CSharedMemDemoApp ����

CSharedMemDemoApp::CSharedMemDemoApp()
	: m_pSharedMemory(NULL),
	m_hMap(NULL),
	m_Mutex(FALSE, TEXT("IPC_TEST_MUTEX")),
	m_ExitEvent(FALSE, TRUE),
	m_ReadEvent(FALSE, TRUE, _T("IPC_READ_SHAREDMEMORY"))
{
	// �ٽ� ���� ������ ����
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CSharedMemDemoApp ��ü�Դϴ�.

CSharedMemDemoApp theApp;


// CSharedMemDemoApp �ʱ�ȭ

BOOL CSharedMemDemoApp::InitInstance()
{
	if (!InitSharedMemory())
		return FALSE;
	AfxBeginThread(CSharedMemDemoApp::ThreadReadSharedMemory, NULL);

	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControlsEx()�� �ʿ��մϴ�.
	// InitCommonControlsEx()�� ������� ������ â�� ���� �� �����ϴ�.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ���� ���α׷����� ����� ��� ���� ��Ʈ�� Ŭ������ �����ϵ���
	// �� �׸��� �����Ͻʽÿ�.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ��ȭ ���ڿ� �� Ʈ�� �� �Ǵ�
	// �� ��� �� ��Ʈ���� ���ԵǾ� �ִ� ��� �� �����ڸ� ����ϴ�.
	CShellManager *pShellManager = new CShellManager;

	// ǥ�� �ʱ�ȭ
	// �̵� ����� ������� �ʰ� ���� ���� ������ ũ�⸦ ���̷���
	// �Ʒ����� �ʿ� ���� Ư�� �ʱ�ȭ
	// ��ƾ�� �����ؾ� �մϴ�.
	// �ش� ������ ����� ������Ʈ�� Ű�� �����Ͻʽÿ�.
	// TODO: �� ���ڿ��� ȸ�� �Ǵ� ������ �̸��� ����
	// ������ �������� �����ؾ� �մϴ�.
	SetRegistryKey(_T("���� ���� ���α׷� �����翡�� ������ ���� ���α׷�"));

	CSharedMemDemoDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ���⿡ [Ȯ��]�� Ŭ���Ͽ� ��ȭ ���ڰ� ������ �� ó����
		//  �ڵ带 ��ġ�մϴ�.
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ���⿡ [���]�� Ŭ���Ͽ� ��ȭ ���ڰ� ������ �� ó����
		//  �ڵ带 ��ġ�մϴ�.
	}

	// ������ ���� �� �����ڸ� �����մϴ�.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ��ȭ ���ڰ� �������Ƿ� ���� ���α׷��� �޽��� ������ �������� �ʰ�  ���� ���α׷��� ���� �� �ֵ��� FALSE��
	// ��ȯ�մϴ�.
	return FALSE;
}



BOOL CSharedMemDemoApp::InitSharedMemory(void)
{
	m_hMap = ::CreateFileMapping(INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		sizeof(TCHAR) * 128,
		_T("IPC_TEST_SHARED_MEMORY"));
	if (::GetLastError() == ERROR_ALREADY_EXISTS)
	{
		m_hMap = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE,
			_T("IPC_TEST_SHARED_MEMORY"));
	}
	if (m_hMap == NULL)
	{
		AfxMessageBox(_T("ERROR: Failed to create(open) file mapping objects!"));
		return FALSE;
	}

	m_pSharedMemory = (TCHAR*)::MapViewOfFile(m_hMap,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		sizeof(TCHAR) * 128);
	if (m_pSharedMemory == NULL)
	{
		AfxMessageBox(_T("ERROR: Failed to get shared memory!"));
		return FALSE;
	}

	return TRUE;
}


int CSharedMemDemoApp::ExitInstance(void)
{
	if (m_pSharedMemory != NULL) 
		::UnmapViewOfFile(m_pSharedMemory);
	if (m_hMap != NULL)
		::CloseHandle(m_hMap);

	m_ExitEvent.SetEvent();
	::Sleep(100);

	return CWinApp::ExitInstance();
}


UINT CSharedMemDemoApp::ThreadReadSharedMemory(LPVOID nParam)
{
	DWORD dwResult = WAIT_OBJECT_0 + 1;
	HANDLE arhList[2];
	arhList[0] = theApp.m_ExitEvent;
	arhList[1] = theApp.m_ReadEvent;

	while (dwResult == WAIT_OBJECT_0 + 1)
	{
		dwResult = ::WaitForMultipleObjects(2, arhList, FALSE, INFINITE);
		if (dwResult == WAIT_OBJECT_0)
		{
			break;
		}
		else if (dwResult == WAIT_OBJECT_0 + 1)
		{
			theApp.m_pMainWnd->PostMessage(UM_RECV_EVENT);
			::Sleep(10);
		}
	}

	return 0;
}
