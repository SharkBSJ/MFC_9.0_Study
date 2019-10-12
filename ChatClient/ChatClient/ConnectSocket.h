#pragma once

// CConnectSocket command target

class CConnectSocket : public CSocket
{
public:
	CConnectSocket();
	virtual ~CConnectSocket();
	void OnClose(int nErrorCode);
	void OnReceive(int nErrorCode);
};


