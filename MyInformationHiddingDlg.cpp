// MyInformationHiddingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyInformationHidding.h"
#include "MyInformationHiddingDlg.h"
#include "PropSheet.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyInformationHiddingDlg dialog

CMyInformationHiddingDlg::CMyInformationHiddingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyInformationHiddingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyInformationHiddingDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_page1=new CPage1Dlg();
    m_page2=new CPage2Dlg();
	
}

void CMyInformationHiddingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyInformationHiddingDlg)
	DDX_Control(pDX, IDC_TAB1, m_Tab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyInformationHiddingDlg, CDialog)
	//{{AFX_MSG_MAP(CMyInformationHiddingDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyInformationHiddingDlg message handlers

BOOL CMyInformationHiddingDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	//设置头部标题字体
	CFont staticFont;
	staticFont.CreateFont(100,100,10,10,FW_BOLD,FALSE,FALSE,FALSE, DEFAULT_CHARSET,OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS,"@system");
    GetDlgItem(IDC_STATIC1)->SetFont(&staticFont);

	
	//插入标签名
	m_Tab.InsertItem(0,"Readme");  
    m_Tab.InsertItem(1,"Hiding"); 
    m_Tab.InsertItem(2,"UnHiding");
     m_Tab.InsertItem(3,"Help");
     m_Tab.InsertItem(4,"License");



//关联对话框,并且将IDC_TAB控件设为父窗口
m_page0.Create(IDD_DIALOG_Page0,GetDlgItem(IDC_TAB1));
m_page1->Create(IDD_DIALOG_PAGE1,GetDlgItem(IDC_TAB1));
m_page1->m_page11->Create(IDD_DIALOG_PAGE11,GetDlgItem(IDC_TAB1));
m_page2->Create(IDD_DIALOG_PAGE2,GetDlgItem(IDC_TAB1));
m_page2->m_page21->Create(IDD_DIALOG_PAGE21,GetDlgItem(IDC_TAB1));
m_page3.Create(IDD_DIALOG_PAGE3,GetDlgItem(IDC_TAB1));
m_page4.Create(IDD_DIALOG_PAGE4,GetDlgItem(IDC_TAB1));





m_page1->m_page11->majorDlg=this;
m_page2->m_page21->majorDlg=this;


//获得IDC_TAB1客户区大小
CRect rs;
m_Tab.GetClientRect(&rs);
//调整子对话框在父窗口中的位置
rs.top+=25; 
rs.bottom-=0; 
rs.left+=1; 
rs.right-=0; 
    
//设置子对话框尺寸并移动到指定位置
m_page0.MoveWindow(&rs);
m_page1->MoveWindow(&rs);
m_page1->m_page11->MoveWindow(&rs);
m_page2->MoveWindow(&rs);
m_page2->m_page21->MoveWindow(&rs);
m_page3.MoveWindow(&rs);
m_page4.MoveWindow(&rs);



//分别设置隐藏和显示
m_page0.ShowWindow(true);
m_page1->ShowWindow(false);
m_page1->m_page11->ShowWindow(false);
m_page2->ShowWindow(false);
m_page2->m_page21->ShowWindow(false);
m_page3.ShowWindow(false);
m_page4.ShowWindow(false);
    
//设置默认的选项卡
m_Tab.SetCurSel(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyInformationHiddingDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CMyInformationHiddingDlg::OnDestroy()
{
	WinHelp(0L, HELP_QUIT);
	CDialog::OnDestroy();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyInformationHiddingDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyInformationHiddingDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyInformationHiddingDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
   // TODO: Add your control notification handler code here
   int CurSel = m_Tab.GetCurSel();
    switch(CurSel)
    {
    case 0:
         m_page0.ShowWindow(true);
         m_page1->ShowWindow(false);
		 m_page1->m_page11->ShowWindow(false);
         m_page2->ShowWindow(false);
         m_page2->m_page21->ShowWindow(false);
         m_page3.ShowWindow(false);
         m_page4.ShowWindow(false);
        break;
    case 1:
          m_page0.ShowWindow(false);
         
		 if(m_page1->m_page11->flag){
		  m_page1->m_page11->ShowWindow(true);
		 
          m_page1->ShowWindow(false);
		 }
		 else{
  m_page1->m_page11->ShowWindow(false);
		     m_page1->ShowWindow(true);
		 }
         m_page2->ShowWindow(false);
 m_page2->m_page21->ShowWindow(false);
         m_page3.ShowWindow(false);
         m_page4.ShowWindow(false);
        break;
    case 2:
         m_page0.ShowWindow(false);
         m_page1->ShowWindow(false);
        m_page1->m_page11->ShowWindow(false);
        if(m_page2->m_page21->flag2){
		   m_page2->m_page21->ShowWindow(true);
          m_page2->ShowWindow(false);
		 }
        else{
		     m_page2->m_page21->ShowWindow(false);
          m_page2->ShowWindow(true);
		 }
         m_page3.ShowWindow(false);
         m_page4.ShowWindow(false);
        break;
    case 3:
          m_page0.ShowWindow(false);
         m_page1->ShowWindow(false);
		 m_page1->m_page11->ShowWindow(false);
         m_page2->ShowWindow(false);
         m_page2->m_page21->ShowWindow(false);
         m_page3.ShowWindow(true);
         m_page4.ShowWindow(false);
        break;
    case 4:
         m_page0.ShowWindow(false);
         m_page1->ShowWindow(false);
		 m_page1->m_page11->ShowWindow(false);
         m_page2->ShowWindow(false);
         m_page2->m_page21->ShowWindow(false);
         m_page3.ShowWindow(false);
         m_page4.ShowWindow(true);
        break;
    default:
         ;
     }    
    
    *pResult = 0;
}



//DEL void CMyInformationHiddingDlg::OnSelchangeTab2()
//DEL {
//DEL int CurSel = m_Tab.GetCurSel();
//DEL     switch(CurSel)
//DEL     {
//DEL     case 0:
//DEL          m_page0.ShowWindow(true);
//DEL          m_page1->ShowWindow(false);
//DEL 		 m_page1->m_page11->ShowWindow(false);
//DEL          m_page2.ShowWindow(false);
//DEL          m_page2.m_page21.ShowWindow(false);
//DEL          m_page3.ShowWindow(false);
//DEL          m_page4.ShowWindow(false);
//DEL         break;
//DEL     case 1:
//DEL           m_page0.ShowWindow(false);
//DEL          
//DEL 		 if(m_page1->m_page11->flag){
//DEL 		  m_page1->m_page11->ShowWindow(true);
//DEL           m_page1->ShowWindow(false);
//DEL 		 }
//DEL 		 else{
//DEL   m_page1->m_page11->ShowWindow(false);
//DEL 		     m_page1->ShowWindow(true);
//DEL 		 }
//DEL          m_page2.ShowWindow(false);
//DEL  m_page2.m_page21.ShowWindow(false);
//DEL          m_page3.ShowWindow(false);
//DEL          m_page4.ShowWindow(false);
//DEL         break;
//DEL     case 2:
//DEL          m_page0.ShowWindow(false);
//DEL          m_page1->ShowWindow(false);
//DEL         m_page1->m_page11->ShowWindow(false);
//DEL         if(m_page2.m_page21.flag2){
//DEL 		   m_page2.m_page21.ShowWindow(true);
//DEL           m_page2.ShowWindow(false);
//DEL 		 }
//DEL         else{
//DEL 		     m_page2.m_page21.ShowWindow(false);
//DEL           m_page2.ShowWindow(true);
//DEL 		 }
//DEL          m_page3.ShowWindow(false);
//DEL          m_page4.ShowWindow(false);
//DEL         break;
//DEL     case 3:
//DEL           m_page0.ShowWindow(false);
//DEL          m_page1->ShowWindow(false);
//DEL 		 m_page1->m_page11->ShowWindow(false);
//DEL          m_page2.ShowWindow(false);
//DEL          m_page2.m_page21.ShowWindow(false);
//DEL          m_page3.ShowWindow(true);
//DEL          m_page4.ShowWindow(false);
//DEL         break;
//DEL     case 4:
//DEL          m_page0.ShowWindow(false);
//DEL          m_page1->ShowWindow(false);
//DEL 		 m_page1->m_page11->ShowWindow(false);
//DEL          m_page2.ShowWindow(false);
//DEL          m_page2.m_page21.ShowWindow(false);
//DEL          m_page3.ShowWindow(false);
//DEL          m_page4.ShowWindow(true);
//DEL         break;
//DEL     default:
//DEL          ;
//DEL      }    
//DEL }
