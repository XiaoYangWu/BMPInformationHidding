// Page0Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyInformationHidding.h"
#include "Page0Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage0Dlg dialog


CPage0Dlg::CPage0Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPage0Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage0Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPage0Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage0Dlg)
	DDX_Control(pDX, IDC_EDIT1, m_ShowEdit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage0Dlg, CDialog)
	//{{AFX_MSG_MAP(CPage0Dlg)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage0Dlg message handlers

void CPage0Dlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	
	// TODO: Add your message handler code here
	CRect rect;
	GetClientRect(&rect);
	CBrush b(RGB(255,255,255));
	dc.FillRect(rect,&b);
	// Do not call CDialog::OnPaint() for painting messages
}



BOOL CPage0Dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString page0String;
page0String.LoadString(IDS_PAGE0); 
m_ShowEdit.SetWindowText(page0String);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CPage0Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{




static HBRUSH hbrEdit = ::CreateSolidBrush( RGB(255, 255, 255) );
pDC->SetBkColor( RGB(255, 255, 255) );
pDC->SetTextColor( RGB(0,0, 0) );
return hbrEdit;	



// TODO: Return a different brush if the default is not desired

}
