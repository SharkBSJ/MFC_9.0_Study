
// SemaphoreDemoView.h : CSemaphoreDemoView Ŭ������ �������̽�
//

#pragma once


class CSemaphoreDemoView : public CView
{
protected: // serialization������ ��������ϴ�.
	CSemaphoreDemoView();
	DECLARE_DYNCREATE(CSemaphoreDemoView)

// Ư���Դϴ�.
public:
	CSemaphoreDemoDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CSemaphoreDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // SemaphoreDemoView.cpp�� ����� ����
inline CSemaphoreDemoDoc* CSemaphoreDemoView::GetDocument() const
   { return reinterpret_cast<CSemaphoreDemoDoc*>(m_pDocument); }
#endif

