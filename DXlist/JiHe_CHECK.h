#if !defined(AFX_JIHE_CHECK_H__8F865C16_E502_4178_A6FC_5B5FAEA085A5__INCLUDED_)
#define AFX_JIHE_CHECK_H__8F865C16_E502_4178_A6FC_5B5FAEA085A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// JiHe_CHECK.h : header file
//
#include"ADOconn.h"

/////////////////////////////////////////////////////////////////////////////
// JiHe_CHECK dialog

class JiHe_CHECK : public CDialog
{
// Construction
public:
	JiHe_CHECK(CWnd* pParent = NULL);   // standard constructor
    CString date,city,product;
    CString table_name;

// Dialog Data
	//{{AFX_DATA(JiHe_CHECK)
	enum { IDD = IDD_CHECK };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(JiHe_CHECK)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(JiHe_CHECK)
	virtual BOOL OnInitDialog();
	afx_msg void OnPASS();
	afx_msg void OnNOTPASS();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIHE_CHECK_H__8F865C16_E502_4178_A6FC_5B5FAEA085A5__INCLUDED_)
