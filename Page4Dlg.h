#if !defined(AFX_PAGE4DLG_H__E84003B0_5E52_43C4_B134_41140483DBEE__INCLUDED_)
#define AFX_PAGE4DLG_H__E84003B0_5E52_43C4_B134_41140483DBEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page4Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage4Dlg dialog

class CPage4Dlg : public CDialog
{
// Construction
public:
	CPage4Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage4Dlg)
	enum { IDD = IDD_DIALOG_PAGE4 };
	CEdit	m_ShowEdit4;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage4Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage4Dlg)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE4DLG_H__E84003B0_5E52_43C4_B134_41140483DBEE__INCLUDED_)
