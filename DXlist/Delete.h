#if !defined(AFX_DELETE_H__A8243870_8AD3_4F0A_9BAF_A94A769768EB__INCLUDED_)
#define AFX_DELETE_H__A8243870_8AD3_4F0A_9BAF_A94A769768EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Delete.h : header file
//
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// Delete dialog

class Delete : public CDialog
{
// Construction
public:
	CString date,city,product,type;
	int money;
	Delete(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(Delete)
	enum { IDD = IDD_Delet };
	CEdit	m_getmoney;
	CComboBox	m_type;
	CComboBox	m_product;
	CDateTimeCtrl	m_date;
	CComboBox	m_city;
	CString	m_money;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Delete)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Delete)
	virtual BOOL OnInitDialog();
	afx_msg void OnDropdownCombo1();
	afx_msg void OnDropdownCombo2();
	afx_msg void OnDropdownCombo3();
	afx_msg void OnDelete();
	afx_msg void OnModify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETE_H__A8243870_8AD3_4F0A_9BAF_A94A769768EB__INCLUDED_)
