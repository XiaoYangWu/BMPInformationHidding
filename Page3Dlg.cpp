// Page3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyInformationHidding.h"
#include "Page3Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage3Dlg dialog


CPage3Dlg::CPage3Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPage3Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage3Dlg)
	//}}AFX_DATA_INIT
}


void CPage3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage3Dlg)
	DDX_Control(pDX, IDC_EDIT_10, m_ShowEdit3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage3Dlg, CDialog)
	//{{AFX_MSG_MAP(CPage3Dlg)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage3Dlg message handlers

void CPage3Dlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect rect;
	GetClientRect(&rect);
	CBrush b(RGB(255,255,255));
	dc.FillRect(rect,&b);	
	// Do not call CDialog::OnPaint() for painting messages
}

BOOL CPage3Dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString page0String;
    page0String.LoadString(IDS_PAGE3); 
    m_ShowEdit3.SetWindowText(page0String);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CPage3Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);	



static HBRUSH hbrEdit = ::CreateSolidBrush( RGB(255, 255, 255) );
pDC->SetBkColor( RGB(255, 255, 255) );
pDC->SetTextColor( RGB(0,0, 0) );
return hbrEdit;	



// TODO: Return a different brush if the default is not desired
}
