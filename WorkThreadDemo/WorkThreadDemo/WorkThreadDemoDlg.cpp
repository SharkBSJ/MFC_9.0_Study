
// WorkThreadDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WorkThreadDemo.h"
#include "WorkThreadDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CWorkThreadDemoDlg dialog




CWorkThreadDemoDlg::CWorkThreadDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWorkThreadDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWorkThreadDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWorkThreadDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_RunNotepad, &CWorkThreadDemoDlg::OnBnClickedButtonRunnotepad)
END_MESSAGE_MAP()


// CWorkThreadDemoDlg message handlers

BOOL CWorkThreadDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWorkThreadDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWorkThreadDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWorkThreadDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

UINT ThreadWaitNotepad(LPVOID pParam)
{
	TCHAR szWinPath[MAX_PATH];
	::GetWindowsDirectory(szWinPath, MAX_PATH);
	lstrcat(szWinPath, _T("\\notepad.exe"));

	SHELLEXECUTEINFO sei;
	::ZeroMemory(&sei, sizeof(sei));
	sei.cbSize	= sizeof(sei);
	sei.hwnd	= NULL;
	sei.lpFile	= szWinPath;
	sei.nShow	= SW_SHOW;
	sei.fMask	= SEE_MASK_NOCLOSEPROCESS | SEE_MASK_NO_CONSOLE;
	sei.lpVerb	= __TEXT("open");
	sei.lpParameters	= NULL;

	if (::ShellExecuteEx(&sei))
	{
		HANDLE arhList[2];
		arhList[0] = sei.hProcess;
		arhList[1] = (HANDLE)g_ExitEvent;

		DWORD dwResult = ::WaitForMultipleObjects(2, arhList, FALSE, 
			INFINITE);

		if (dwResult == WAIT_OBJECT_0)
		{
			AfxMessageBox(_T("메모장이 종료되었습니다."));
		}
		else if (dwResult == WAIT_OBJECT_0 + 1)
		{
			OutputDebugString(_T("WorkerThreadDemo 예제가 종료되었습니다!\n"));
		}
	}

	g_pThread = NULL;
	return 0;
}


void CWorkThreadDemoDlg::OnBnClickedButtonRunnotepad()
{
	// TODO: Add your control notification handler code here
	if (g_pThread != NULL)
	{
		AfxMessageBox(_T("메모장 감시 스레드가 이미 실행중입니다."));
		return;
	}

	g_pThread = AfxBeginThread(ThreadWaitNotepad, NULL);
	if (g_pThread == NULL)
	{
		AfxMessageBox(_T("ERROR: Failed to begin worker-thread!"));
	}
}