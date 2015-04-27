#if !defined(AFX_PAGE21DLG_H__5D5A3B14_292C_4118_A95A_5F9DDBB436A8__INCLUDED_)
#define AFX_PAGE21DLG_H__5D5A3B14_292C_4118_A95A_5F9DDBB436A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page21Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage21Dlg dialog
class 	CMyInformationHiddingDlg;
class CPage21Dlg : public CDialog
{
// Construction
public:
	CMyInformationHiddingDlg* majorDlg;
	boolean flag2;
	CPage21Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage21Dlg)
	enum { IDD = IDD_DIALOG_PAGE21 };
	CString	m_CoverFile;
	CString	m_DestFile;
	CString	m_passwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage21Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage21Dlg)
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButtonBack2();
	afx_msg void OnButtonBrowse3();
	afx_msg void OnButtonBrowse4();
	afx_msg void OnButtonClear2();
	afx_msg void OnButtonUnhide();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE21DLG_H__5D5A3B14_292C_4118_A95A_5F9DDBB436A8__INCLUDED_)
