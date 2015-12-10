#if !defined(AFX_LOGIN_H__23D8D412_C4BD_407A_A7A6_23AC3D41CB3C__INCLUDED_)
#define AFX_LOGIN_H__23D8D412_C4BD_407A_A7A6_23AC3D41CB3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogIN.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// LogIN dialog

class LogIN : public CDialog
{
// Construction
public:
	LogIN(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(LogIN)
	enum { IDD = IDD_DIALOG_LogIn };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LogIN)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LogIN)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__23D8D412_C4BD_407A_A7A6_23AC3D41CB3C__INCLUDED_)
