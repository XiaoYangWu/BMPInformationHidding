// Page11Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "myinformationhidding.h"
#include "Page11Dlg.h"
#include "Prop1.h"
#include "Prop2.h"
#include <fstream>
#include "MyTabCtrl.h"
#include "MyInformationHiddingDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage11Dlg dialog

class CPage11Dlg;
CPage11Dlg::CPage11Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPage11Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage11Dlg)
	m_passwd = _T("");
	m_DestFile = _T("");
	m_CoverFile = _T("");
	m_HideMessage = _T("");
	m_HideFile = _T("");
	//}}AFX_DATA_INIT
   
	flag=false;
}


void CPage11Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage11Dlg)

	DDX_Control(pDX, IDC_TAB50, m_tab50);
	DDX_Control(pDX, IDC_BUTTON201, m_Button201);
	DDX_Control(pDX, IDC_EDIT201, m_Edit201);
	DDX_Control(pDX, IDC_EDIT200, m_Edit200);
	DDX_Text(pDX, IDC_EDIT_PASSWD, m_passwd);
	DDX_Text(pDX, IDC_EDIT3, m_DestFile);
	DDX_Text(pDX, IDC_EDIT2, m_CoverFile);
	DDX_Text(pDX, IDC_EDIT200, m_HideMessage);
	DDX_Text(pDX, IDC_EDIT201, m_HideFile);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage11Dlg, CDialog)
	//{{AFX_MSG_MAP(CPage11Dlg)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_Back1, OnBUTTONBack1)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE1, OnButtonBrowse1)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE2, OnButtonBrowse2)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_CLEAR1, OnButtonClear1)
	ON_BN_CLICKED(IDC_BUTTON201, OnButton201)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB50, OnSelchangeTab50)
	ON_BN_CLICKED(IDC_BUTTON_HIDE, OnButtonHide)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage11Dlg message handlers

void CPage11Dlg::OnPaint() 
{
		CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect rect;
	GetClientRect(&rect);
	CBrush b(RGB(255,255,255));
	dc.FillRect(rect,&b);
	//MessageBox("ddd");
	// Do not call CDialog::OnPaint() for painting messages
  
}



void CPage11Dlg::OnBUTTONBack1() 
{
	// TODO: Add your control notification handler code here
	flag=false;

	this->ShowWindow(false);
  

 majorDlg->m_page1->ShowWindow(true);
}

void CPage11Dlg::OnButtonBrowse1() 
{
	// TODO: Add your control notification handler code here
	
	CString filename;//保存路径
	
	CFileDialog opendlg (TRUE,NULL,NULL,OFN_OVERWRITEPROMPT, _T("所有文件(*.*;)|*.*||"),NULL);   
	if (opendlg.DoModal()==IDOK)
	{
		filename=opendlg.GetPathName();   
	} 

	m_CoverFile=filename;
	UpdateData(false);
}

void CPage11Dlg::OnButtonBrowse2() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	
	CString filepath = _T("");//用来保存文件路径
         BROWSEINFO bi;
         char Buffer[512];
         //初始化入口参数bi开始
         bi.hwndOwner = NULL;
         bi.pidlRoot = NULL;
         bi.pszDisplayName = Buffer;//此参数如为NULL则不能显示对话框
         bi.lpszTitle = "选择路径";
         bi.ulFlags = BIF_RETURNONLYFSDIRS;
         bi.lpfn = NULL;
         bi.iImage = 0;
         //初始化入口参数bi结束
         LPITEMIDLIST pIDList = SHBrowseForFolder(&bi);//调用显示选择对话框
         if(pIDList)//选择到路径(即：点了确定按钮)
         {
          SHGetPathFromIDList(pIDList, Buffer);
          //取得文件夹路径到Buffer里
          filepath = Buffer;//将路径保存在一个CString对象里
         }
         else//取消选择
           return;
	m_DestFile=filepath;
	UpdateData(false);
}

BOOL CPage11Dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_tab50.InsertItem(0,"Hide File");
	m_tab50.InsertItem(1,"Hide Message");
//prop1->Create(IDD_PROPPAGE_HFILE,GetDlgItem(IDC_TAB50));
//prop2->Create(IDD_PROPPAGE_HMESSAGE,GetDlgItem(IDC_TAB50));



m_tab50.SetCurSel(0);
m_Edit200.ShowWindow(false);

//	m_tab50.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CPage11Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
static HBRUSH hbrEdit = ::CreateSolidBrush( RGB(255, 255, 255) );


if(nCtlColor == CTLCOLOR_EDIT)
     pDC->SetTextColor(RGB(0,0,0));
else
   pDC->SetTextColor( RGB(0,0,255) );
pDC->SetBkColor( RGB(255, 255, 255) );
return hbrEdit;
}

void CPage11Dlg::OnButtonClear1() 
{
	// TODO: Add your control notification handler code here
	m_CoverFile="";
	m_DestFile="";
	m_passwd="";
	m_HideFile="";
	m_HideMessage="";
	UpdateData(false);
}

void CPage11Dlg::OnButton201() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	CString filename;//保存路径
	
	CFileDialog opendlg (TRUE,NULL,NULL,OFN_OVERWRITEPROMPT, _T("所有文件(*.*;)|*.*||"),NULL);   
	if (opendlg.DoModal()==IDOK)
	{
		filename=opendlg.GetPathName();   
	} 

	m_HideFile=filename;
	UpdateData(false);
}

void CPage11Dlg::OnSelchangeTab50(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	 int CurSel = m_tab50.GetCurSel();
    switch(CurSel)
    {
    case 0:
         m_Edit201.ShowWindow(true);
		 m_Button201.ShowWindow(true);
		 m_Edit200.ShowWindow(false);
        break;
    case 1:
         m_Edit201.ShowWindow(false);
		 m_Button201.ShowWindow(false);
		 m_Edit200.ShowWindow(true);
    default:
         ;
     }    
	*pResult = 0;
}

void CPage11Dlg::OnButtonHide() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
    ImageDib dib;
	int count=0;
   
    dib.Read(m_CoverFile);
	unsigned char *imgData=dib.m_pImgData;

    
	if(m_tab50.GetCurSel()==1){
	    char *pBuffer = m_HideMessage.GetBuffer(0);
        for(int i=0;i<m_HideMessage.GetLength();i++)
		{
	    	for(int j=0;j<8;j++)
			{   
		     	int temp=pBuffer[i]%2;
	     	
		    	if(temp==1)
				{
		       	   	*imgData=((*imgData)|1);

				}
			    else{
			       *imgData=((*imgData)&254);
				}
                pBuffer[i]/=2;
                *imgData++;
          
			    count++;
			}
	
		}
	}

	else{
	
	  char* content;
     // AfxMessageBox(m_HideFile);
	  CFile file;
	  
	  file.Open(m_HideFile,CFile::modeRead|CFile::shareDenyWrite);
      content=new char[file.GetLength()+1];
	  file.Read(content,file.GetLength());
      content[file.GetLength()]='\0';
      for(int i=0;i<file.GetLength();i++)
	  {
	   	for(int j=0;j<8;j++)
		{   
	    	int temp=content[i]%2;
	     	
		   	if(temp==1)
			{
		     	 	*imgData=((*imgData)|1);
			}
		    else{
			   *imgData=((*imgData)&254);
			}
            content[i]/=2;
            *imgData++;
          
			count++;
		}
	
	  }
	}
    dib.bmfh.bfReserved2=(count/8);
 
    dib.Write(m_DestFile+"\\steg.bmp");

	AfxMessageBox("隐藏成功!");
	
}
