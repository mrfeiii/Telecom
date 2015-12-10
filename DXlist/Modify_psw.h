#if !defined(AFX_MODIFY_PSW_H__512C8D8C_4538_45A9_B310_5BD99FD70A24__INCLUDED_)
#define AFX_MODIFY_PSW_H__512C8D8C_4538_45A9_B310_5BD99FD70A24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Modify_psw.h : header file
//
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// Modify_psw dialog

class Modify_psw : public CDialog
{
// Construction
public:
	Modify_psw(CWnd* pParent = NULL);   // standard constructor
    ADOconn m_AdoConn;
	CString sql;
// Dialog Data
	//{{AFX_DATA(Modify_psw)
	enum { IDD = IDD_Modify_psw };
	CString	m_old_psw;
	CString	m_new_psw2;
	CString	m_new_psw1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Modify_psw)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Modify_psw)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODIFY_PSW_H__512C8D8C_4538_45A9_B310_5BD99FD70A24__INCLUDED_)
