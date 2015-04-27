#if !defined(AFX_PAGE2DLG_H__DCB89B66_E537_4E4E_A38C_BE0C4F1B9B25__INCLUDED_)
#define AFX_PAGE2DLG_H__DCB89B66_E537_4E4E_A38C_BE0C4F1B9B25__INCLUDED_

#include "Page21Dlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page2Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage2Dlg dialog

class CPage2Dlg : public CDialog
{
// Construction
public:
	
	CPage21Dlg *m_page21;
	CPage2Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage2Dlg)
	enum { IDD = IDD_DIALOG_PAGE2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage2Dlg)
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButton2();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE2DLG_H__DCB89B66_E537_4E4E_A38C_BE0C4F1B9B25__INCLUDED_)
