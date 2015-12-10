// DXlist.h : main header file for the DXLIST application
//

#if !defined(AFX_DXLIST_H__1C9D5B36_B762_4F6E_894F_53AE18752112__INCLUDED_)
#define AFX_DXLIST_H__1C9D5B36_B762_4F6E_894F_53AE18752112__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDXlistApp:
// See DXlist.cpp for the implementation of this class
//

class CDXlistApp : public CWinApp
{
public:
	CDXlistApp();
	CString USer_name;
	CString User_psw;
    int User_Root;
//  / ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDXlistApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDXlistApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CString		GetExcelDriver();
BOOL		MakeSurePathExists( CString &Path,	bool FilenameIncluded=true);
void		ExportListToExcel(CListCtrl* pList, CString strTitle);
void		ExportListToTXT(CListCtrl* pList);
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DXLIST_H__1C9D5B36_B762_4F6E_894F_53AE18752112__INCLUDED_)
