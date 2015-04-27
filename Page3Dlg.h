#if !defined(AFX_PAGE3DLG_H__855F1DDD_9842_4D80_ADC5_0A137B373FAD__INCLUDED_)
#define AFX_PAGE3DLG_H__855F1DDD_9842_4D80_ADC5_0A137B373FAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page3Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage3Dlg dialog

class CPage3Dlg : public CDialog
{
// Construction
public:
	CPage3Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage3Dlg)
	enum { IDD = IDD_DIALOG_PAGE3 };
	CEdit	m_ShowEdit3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage3Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage3Dlg)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE3DLG_H__855F1DDD_9842_4D80_ADC5_0A137B373FAD__INCLUDED_)
