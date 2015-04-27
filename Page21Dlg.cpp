// Page21Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyInformationHidding.h"
#include<math.h>
#include "Page21Dlg.h"
#include "MyInformationHiddingDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage21Dlg dialog


CPage21Dlg::CPage21Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPage21Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage21Dlg)
	m_CoverFile = _T("");
	m_DestFile = _T("");
	m_passwd = _T("");
	//}}AFX_DATA_INIT
	flag2=false;
}


void CPage21Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage21Dlg)
	DDX_Text(pDX, IDC_EDIT4, m_CoverFile);
	DDX_Text(pDX, IDC_EDIT5, m_DestFile);
	DDX_Text(pDX, IDC_EDIT_PASSWD2, m_passwd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage21Dlg, CDialog)
	//{{AFX_MSG_MAP(CPage21Dlg)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_BACK2, OnButtonBack2)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE3, OnButtonBrowse3)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE4, OnButtonBrowse4)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR2, OnButtonClear2)
	ON_BN_CLICKED(IDC_BUTTON_UNHIDE, OnButtonUnhide)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage21Dlg message handlers

void CPage21Dlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	

	
	// TODO: Add your message handler code here
	CRect rect;
	GetClientRect(&rect);
	CBrush b(RGB(255,255,255));
	dc.FillRect(rect,&b);	
	// Do not call CDialog::OnPaint() for painting messages
}

HBRUSH CPage21Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
		
static HBRUSH hbrEdit = ::CreateSolidBrush( RGB(255, 255, 255) );
pDC->SetBkColor( RGB(255, 255, 255) );

if(nCtlColor == CTLCOLOR_EDIT)
     pDC->SetTextColor(RGB(0,0,0));
else
   pDC->SetTextColor( RGB(0,0,255) );
return hbrEdit;
}

void CPage21Dlg::OnButtonBack2() 
{
	// TODO: Add your control notification handler code here
		// TODO: Add your control notification handler code here
	flag2=false;

	this->ShowWindow(false);
  

    majorDlg->m_page2->ShowWindow(true);
}

void CPage21Dlg::OnButtonBrowse3() 
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

void CPage21Dlg::OnButtonBrowse4() 
{
	// TODO: Add your control notification handler code here
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

void CPage21Dlg::OnButtonClear2() 
{
	// TODO: Add your control notification handler code here
	m_CoverFile="";
	m_DestFile="";
	m_passwd="";
	UpdateData(false);
}

void CPage21Dlg::OnButtonUnhide() 
{
	// TODO: Add your control notification handler code here
		UpdateData(true);
       ImageDib dib;
	   int count=0;
       CString infomat="";
       dib.Read(m_CoverFile);
       unsigned char *imgData=dib.m_pImgData;
	   count=dib.bmfh.bfReserved2;
	   for(int i=0;i<count;i++)
	   {
		char unit=0;
		for(int j=0;j<8;j++)
		{   
			int temp=(*imgData)%2;
			unit+=temp*pow(2,j);
	        imgData++;

		}
	   
	    infomat+=unit;
	   }
	     infomat+='\0';
    if(m_DestFile==""){
			MessageBox(infomat);
   }
 else{
     CFile file;

     char *hiddeninfo=new char[infomat.GetLength()];
	 for(int i=0;i<infomat.GetLength();i++)
	 {
		 hiddeninfo[i]=infomat.GetAt(i);
	 }
     CString filePath=m_DestFile+"\\hidden.txt";
	 file.Open(filePath,CFile::modeCreate|CFile::modeReadWrite|CFile::shareExclusive);
     file.Write(hiddeninfo,infomat.GetLength());
	 AfxMessageBox("文件提取成功！请在您刚才选择的路径查找hidden.txt文件");
 }
    
}
