#if !defined(AFX_LURU_WJ_ADD_H__BD565D11_DAFC_44DB_BFDB_CE82817F3F52__INCLUDED_)
#define AFX_LURU_WJ_ADD_H__BD565D11_DAFC_44DB_BFDB_CE82817F3F52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LuRu_wj_Add.h : header file
//
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// LuRu_wj_Add dialog

class LuRu_wj_Add : public CDialog
{
// Construction
public:
	LuRu_wj_Add(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(LuRu_wj_Add)
	enum { IDD = IDD_LuRu_wj_Add };
	CDateTimeCtrl	m_date;
	CComboBox	m_type;
	CComboBox	m_operator;
	CComboBox	m_product;
	CComboBox	m_city;
	double	m_amount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LuRu_wj_Add)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LuRu_wj_Add)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LURU_WJ_ADD_H__BD565D11_DAFC_44DB_BFDB_CE82817F3F52__INCLUDED_)
