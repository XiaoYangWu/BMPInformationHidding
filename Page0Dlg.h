#if !defined(AFX_PAGE0DLG_H__08AF278A_FBED_4A00_B279_2F9BB0654382__INCLUDED_)
#define AFX_PAGE0DLG_H__08AF278A_FBED_4A00_B279_2F9BB0654382__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page0Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage0Dlg dialog

class CPage0Dlg : public CDialog
{
// Construction
public:
	CPage0Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage0Dlg)
	enum { IDD = IDD_DIALOG_Page0 };
	CEdit	m_ShowEdit;

	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage0Dlg)
	public:
	
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage0Dlg)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE0DLG_H__08AF278A_FBED_4A00_B279_2F9BB0654382__INCLUDED_)
