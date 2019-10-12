
// SemaphoreDemoView.cpp : CSemaphoreDemoView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "SemaphoreDemo.h"
#endif

#include "SemaphoreDemoDoc.h"
#include "SemaphoreDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSemaphoreDemoView

IMPLEMENT_DYNCREATE(CSemaphoreDemoView, CView)

BEGIN_MESSAGE_MAP(CSemaphoreDemoView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSemaphoreDemoView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CSemaphoreDemoView ����/�Ҹ�

CSemaphoreDemoView::CSemaphoreDemoView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CSemaphoreDemoView::~CSemaphoreDemoView()
{
}

BOOL CSemaphoreDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CSemaphoreDemoView �׸���

void CSemaphoreDemoView::OnDraw(CDC* /*pDC*/)
{
	CSemaphoreDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CSemaphoreDemoView �μ�


void CSemaphoreDemoView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSemaphoreDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CSemaphoreDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CSemaphoreDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CSemaphoreDemoView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSemaphoreDemoView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSemaphoreDemoView ����

#ifdef _DEBUG
void CSemaphoreDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CSemaphoreDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSemaphoreDemoDoc* CSemaphoreDemoView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSemaphoreDemoDoc)));
	return (CSemaphoreDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CSemaphoreDemoView �޽��� ó����


int CSemaphoreDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	SetTimer(100, 1000, NULL);

	return 0;
}


void CSemaphoreDemoView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	dc.FillSolidRect(0, 0, 300, 300, RGB(255, 255, 255));
	for (int i=0; i<10; i++)
	{
		if (g_arString[i].GetAt(0) == '#')
			dc.SetTextColor(RGB(192, 0, 0));
		else 
			dc.SetTextColor(RGB(192, 192, 192));

		dc.TextOutW(30, 20 * i + 10, g_arString[i]);
	}

	CView::OnTimer(nIDEvent);
}
