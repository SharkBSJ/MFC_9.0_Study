
// stdafx.cpp : source file that includes just the standard includes
// WorkThreadDemo.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

CWinThread*	g_pThread = NULL;
CEvent		g_ExitEvent;