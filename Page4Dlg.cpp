// Page4Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyInformationHidding.h"
#include "Page4Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage4Dlg dialog


CPage4Dlg::CPage4Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPage4Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage4Dlg)
	//}}AFX_DATA_INIT
}


void CPage4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage4Dlg)
	DDX_Control(pDX, IDC_EDIT11, m_ShowEdit4);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage4Dlg, CDialog)
	//{{AFX_MSG_MAP(CPage4Dlg)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage4Dlg message handlers

void CPage4Dlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect rect;
	GetClientRect(&rect);
	CBrush b(RGB(255,255,255));
	dc.FillRect(rect,&b);	
	// Do not call CDialog::OnPaint() for painting messages
}

BOOL CPage4Dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString page0String;
page0String.LoadString(IDS_PAGE4); 
m_ShowEdit4.SetWindowText(page0String);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CPage4Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);	



static HBRUSH hbrEdit = ::CreateSolidBrush( RGB(255, 255, 255) );
pDC->SetBkColor( RGB(255, 255, 255) );
pDC->SetTextColor( RGB(0,0, 0) );
return hbrEdit;	



// TODO: Return a different brush if the default is not desired
}
