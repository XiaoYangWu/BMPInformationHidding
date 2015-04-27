#if !defined(AFX_PAGE11DLG_H__5C7AA843_A2CA_4847_8BF1_4D8E6CBF075D__INCLUDED_)
#define AFX_PAGE11DLG_H__5C7AA843_A2CA_4847_8BF1_4D8E6CBF075D__INCLUDED_

#include "MyInformationHiddingDlg.h"	// Added by ClassView
#include "MyTabCtrl.h"
#include "ImageDib.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page11Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage11Dlg dialog
class CMyInformationHiddingDlg;

class CMyTabCtrl;
class CPage11Dlg : public CDialog
{
// Construction
public:
	
	CMyInformationHiddingDlg* majorDlg;

	boolean flag;
	CPage11Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage11Dlg)
	enum { IDD = IDD_DIALOG_PAGE11 };
	
	CMyTabCtrl	m_tab50;
	CButton	m_Button201;
	CEdit	m_Edit201;
	CEdit	m_Edit200;
	CString	m_passwd;
	CString	m_DestFile;
	CString	m_CoverFile;
	CString	m_HideMessage;
	CString	m_HideFile;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage11Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage11Dlg)
	afx_msg void OnPaint();
	afx_msg void OnBUTTONBack1();
	afx_msg void OnButtonBrowse1();
	afx_msg void OnButtonBrowse2();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButtonClear1();
	afx_msg void OnButton201();
	afx_msg void OnSelchangeTab50(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonHide();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE11DLG_H__5C7AA843_A2CA_4847_8BF1_4D8E6CBF075D__INCLUDED_)
