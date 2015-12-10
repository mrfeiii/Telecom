#if !defined(AFX_LOGIN1_H__E8862ED5_0CBF_46B7_8E38_BEADD8AF732E__INCLUDED_)
#define AFX_LOGIN1_H__E8862ED5_0CBF_46B7_8E38_BEADD8AF732E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogIn1.h : header file
//
#include"ADOconn.h"
#include"User_Root.h"
/////////////////////////////////////////////////////////////////////////////
// LogIn dialog

class LogIn : public CDialog
{
// Construction
public:
	LogIn(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(LogIn)
	enum { IDD = IDD_DIALOG_LogIn };
	CString	m_name;
	CString	m_pwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LogIn)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LogIn)
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN1_H__E8862ED5_0CBF_46B7_8E38_BEADD8AF732E__INCLUDED_)
