// MyInformationHiddingDlg.h : header file
//

#if !defined(AFX_MYINFORMATIONHIDDINGDLG_H__5AD2ACD1_0F01_4CCC_9F77_D49455CE1CCE__INCLUDED_)
#define AFX_MYINFORMATIONHIDDINGDLG_H__5AD2ACD1_0F01_4CCC_9F77_D49455CE1CCE__INCLUDED_

#include "Page3Dlg.h"	// Added by ClassView
#include "Page0Dlg.h"	// Added by ClassView
#include "Page1Dlg.h"	// Added by ClassView
#include "Page2Dlg.h"	// Added by ClassView
#include "Page4Dlg.h"	// Added by ClassView



#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyInformationHiddingDlg dialog

class CPage1Dlg;
class CMyInformationHiddingDlg : public CDialog
{
// Construction
public:



	CPage4Dlg m_page4;
    CPage3Dlg m_page3;
	CPage2Dlg *m_page2;
	CPage1Dlg *m_page1;
	CPage0Dlg m_page0;
	CMyInformationHiddingDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyInformationHiddingDlg)
	enum { IDD = IDD_MYINFORMATIONHIDDING_DIALOG };
	CTabCtrl	m_Tab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyInformationHiddingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyInformationHiddingDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYINFORMATIONHIDDINGDLG_H__5AD2ACD1_0F01_4CCC_9F77_D49455CE1CCE__INCLUDED_)
