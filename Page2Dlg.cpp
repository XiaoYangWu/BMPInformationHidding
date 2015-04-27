// Page2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyInformationHidding.h"
#include "Page2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage2Dlg dialog


CPage2Dlg::CPage2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPage2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage2Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_page21=new CPage21Dlg();
}


void CPage2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage2Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage2Dlg, CDialog)
	//{{AFX_MSG_MAP(CPage2Dlg)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage2Dlg message handlers

void CPage2Dlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect rect;
	GetClientRect(&rect);
	CBrush b(RGB(255,255,255));
	dc.FillRect(rect,&b);	
	// Do not call CDialog::OnPaint() for painting messages
}

HBRUSH CPage2Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	
static HBRUSH hbrEdit = ::CreateSolidBrush( RGB(255, 255, 255) );
pDC->SetBkColor( RGB(255, 255, 255) );

if (pWnd->GetDlgCtrlID() == IDC_STATIC_PAGE3)
   pDC->SetTextColor(RGB(0,0,255));
else
   pDC->SetTextColor( RGB(153,0,204) );
return hbrEdit;	

}

void CPage2Dlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
		m_page21->ShowWindow(true);
	this->ShowWindow(false);
	m_page21->flag2=true;
}

BOOL CPage2Dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CButton *)GetDlgItem(IDC_RADIO8))->SetCheck(TRUE);//я║ио

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
