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
	CString filename;//����·��
	
	CFileDialog opendlg (TRUE,NULL,NULL,OFN_OVERWRITEPROMPT, _T("�����ļ�(*.*;)|*.*||"),NULL);   
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
	CString filepath = _T("");//���������ļ�·��
         BROWSEINFO bi;
         char Buffer[512];
         //��ʼ����ڲ���bi��ʼ
         bi.hwndOwner = NULL;
         bi.pidlRoot = NULL;
         bi.pszDisplayName = Buffer;//�˲�����ΪNULL������ʾ�Ի���
         bi.lpszTitle = "ѡ��·��";
         bi.ulFlags = BIF_RETURNONLYFSDIRS;
         bi.lpfn = NULL;
         bi.iImage = 0;
         //��ʼ����ڲ���bi����
         LPITEMIDLIST pIDList = SHBrowseForFolder(&bi);//������ʾѡ��Ի���
         if(pIDList)//ѡ��·��(��������ȷ����ť)
         {
          SHGetPathFromIDList(pIDList, Buffer);
          //ȡ���ļ���·����Buffer��
          filepath = Buffer;//��·��������һ��CString������
         }
         else//ȡ��ѡ��
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
	 AfxMessageBox("�ļ���ȡ�ɹ����������ղ�ѡ���·������hidden.txt�ļ�");
 }
    
}
