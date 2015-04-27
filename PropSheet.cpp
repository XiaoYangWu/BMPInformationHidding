// PropSheet.cpp : implementation file
//

#include "stdafx.h"
#include "myinformationhidding.h"
#include "PropSheet.h"
#include "Prop1.h"
#include "Prop2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropSheet

IMPLEMENT_DYNAMIC(CPropSheet, CPropertySheet)

CPropSheet::CPropSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_prop1);
	AddPage(&m_prop2);
}

CPropSheet::CPropSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
AddPage(&m_prop1);
	AddPage(&m_prop2);

}

CPropSheet::~CPropSheet()
{
}


BEGIN_MESSAGE_MAP(CPropSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CPropSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropSheet message handlers
