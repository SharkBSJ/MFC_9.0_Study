
// WorkThreadDemo.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CWorkThreadDemoApp:
// See WorkThreadDemo.cpp for the implementation of this class
//

class CWorkThreadDemoApp : public CWinApp
{
public:
	CWorkThreadDemoApp();

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int	 ExitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CWorkThreadDemoApp theApp;