// Page1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyInformationHidding.h"
#include "Page1Dlg.h"
#include "Page11Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage1Dlg dialog


CPage1Dlg::CPage1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPage1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage1Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_page11=new CPage11Dlg();
}


void CPage1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage1Dlg)
	DDX_Control(pDX, IDC_STATIC_PAGE1, m_Static);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage1Dlg, CDialog)
	//{{AFX_MSG_MAP(CPage1Dlg)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage1Dlg message handlers

void CPage1Dlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect rect;
	GetClientRect(&rect);
	CBrush b(RGB(255,255,255));
	dc.FillRect(rect,&b);	
	// Do not call CDialog::OnPaint() for painting messages
}

HBRUSH CPage1Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
static HBRUSH hbrEdit = ::CreateSolidBrush( RGB(255, 255, 255) );
pDC->SetBkColor( RGB(255, 255, 255) );

if (pWnd->GetDlgCtrlID() == IDC_STATIC_PAGE1)
   pDC->SetTextColor(RGB(0,0,255));
else
   pDC->SetTextColor( RGB(153,0,204) );
return hbrEdit;	



// TODO: Return a different brush if the default is not desired	
}

void CPage1Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	m_page11->ShowWindow(true);
	this->ShowWindow(false);
	m_page11->flag=true;
	
    
}

BOOL CPage1Dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CButton *)GetDlgItem(IDC_RADIO4))->SetCheck(TRUE);//я║ио

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
