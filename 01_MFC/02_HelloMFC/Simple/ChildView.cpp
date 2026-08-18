
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "Simple.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;

	// 사용자가 전달한 정보를 바탕으로 윈도우 클래스를 운영체제에 등록하고,
	// 내부에서 자동으로 생성한  윈도우 클래스 이름을 문자열 형태로 리턴한다.
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
	dc.TextOutW(50, 50, CString(_T("안녕하세요.")));

	// WM_PAINT메시지가 발생할 때마다 
	// OnPaint() 함수가 호출되므로 윈도우 크기가 변경되거나 윈도우가 가려지는 상황에서도 
	// 출력 내용이 지워지지 않고 항상 표시된다.
	dc.Rectangle(0, 0, 200, 100);
	dc.Ellipse(200, 100, 500, 200);
}

