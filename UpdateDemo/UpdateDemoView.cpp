
// UpdateDemoView.cpp : CUpdateDemoView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "UpdateDemo.h"
#endif

#include "UpdateDemoDoc.h"
#include "UpdateDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUpdateDemoView

IMPLEMENT_DYNCREATE(CUpdateDemoView, CView)

BEGIN_MESSAGE_MAP(CUpdateDemoView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CUpdateDemoView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CUpdateDemoView ����/�Ҹ�

CUpdateDemoView::CUpdateDemoView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CUpdateDemoView::~CUpdateDemoView()
{
}

BOOL CUpdateDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CUpdateDemoView �׸���

void CUpdateDemoView::OnDraw(CDC* /*pDC*/)
{
	CUpdateDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CUpdateDemoView �μ�


void CUpdateDemoView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CUpdateDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CUpdateDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CUpdateDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CUpdateDemoView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CUpdateDemoView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CUpdateDemoView ����

#ifdef _DEBUG
void CUpdateDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CUpdateDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUpdateDemoDoc* CUpdateDemoView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUpdateDemoDoc)));
	return (CUpdateDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CUpdateDemoView �޽��� ó����
