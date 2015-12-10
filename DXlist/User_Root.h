#if !defined(AFX_USER_ROOT_H__1E3047A7_6B75_4A39_88D1_658718C9D7C2__INCLUDED_)
#define AFX_USER_ROOT_H__1E3047A7_6B75_4A39_88D1_658718C9D7C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// User_Root.h : header file
//
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// User_Root dialog

class User_Root : public CDialog
{
// Construction
public:
	User_Root(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(User_Root)
	enum { IDD = IDD_Root };
	CComboBox	m_user_type;
	CString	m_user_name;
	CString	m_user_pwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(User_Root)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(User_Root)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	afx_msg void OnCancel_my();
	afx_msg void OnChangeEdit1();
	afx_msg void OnChangeEdit5();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USER_ROOT_H__1E3047A7_6B75_4A39_88D1_658718C9D7C2__INCLUDED_)
