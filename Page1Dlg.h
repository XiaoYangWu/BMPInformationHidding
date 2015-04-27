#if !defined(AFX_PAGE1DLG_H__D3BD9135_5215_47AF_B4DF_192D9389985D__INCLUDED_)
#define AFX_PAGE1DLG_H__D3BD9135_5215_47AF_B4DF_192D9389985D__INCLUDED_

#include "Page11Dlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page1Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage1Dlg dialog

class CPage11Dlg;
class CPage1Dlg : public CDialog
{
// Construction
public:
	
	CPage11Dlg* m_page11;
	CPage1Dlg(CWnd* pParent = NULL);   // standard constructor
	CFont m_Font;
// Dialog Data
	//{{AFX_DATA(CPage1Dlg)
	enum { IDD = IDD_DIALOG_PAGE1 };
	CStatic	m_Static;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage1Dlg)
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButton1();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE1DLG_H__D3BD9135_5215_47AF_B4DF_192D9389985D__INCLUDED_)
