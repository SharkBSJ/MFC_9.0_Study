
// stdafx.cpp : ǥ�� ���� ���ϸ� ��� �ִ� �ҽ� �����Դϴ�.
// ThreadCrashDemo.pch�� �̸� �����ϵ� ����� �˴ϴ�.
// stdafx.obj���� �̸� �����ϵ� ���� ������ ���Ե˴ϴ�.

#include "stdafx.h"

CCriticalSection	g_CS;
TCHAR*				g_pszBuffer = NULL;

void SetString(TCHAR* pszData)
{
	g_CS.Lock();
	int nLength = lstrlen(pszData) + 1;
	if (g_pszBuffer != NULL) 
		free(g_pszBuffer);

	g_pszBuffer = (TCHAR*)malloc(sizeof(TCHAR) * nLength);
	swprintf_s(g_pszBuffer, nLength, _T("%s"), pszData);
	g_CS.Unlock();
}

BOOL GetString(TCHAR* pszData)
{
	g_CS.Lock();
	if (pszData != NULL && g_pszBuffer != NULL) 
	{
		int nLength = lstrlen(g_pszBuffer);
		swprintf_s(pszData, nLength + 1, _T("%s"), g_pszBuffer);

		g_CS.Unlock();
		return TRUE;
	}

	g_CS.Unlock();
	return FALSE;
}

UINT ThreadFunc1(LPVOID nParam)
{
	while (TRUE)
	{
		::Sleep(1);
		SetString(_T("ThreadFunc1"));
	}

	return 0;
}

UINT ThreadFunc2(LPVOID nParam)
{
	while (TRUE)
	{
		::Sleep(1);
		SetString(_T("ThreadFunc2"));
	}

	return 0;
}