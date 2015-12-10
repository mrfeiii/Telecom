#if !defined(AFX_LURU_TZD_ADD_H__C7AF44C6_54F8_4579_B04E_E3BD377F2998__INCLUDED_)
#define AFX_LURU_TZD_ADD_H__C7AF44C6_54F8_4579_B04E_E3BD377F2998__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LuRu_tzd_Add.h : header file
//
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// LuRu_tzd_Add dialog

class LuRu_tzd_Add : public CDialog
{
// Construction
public:
	LuRu_tzd_Add(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(LuRu_tzd_Add)
	enum { IDD = IDD_LuRu_tzd_Add };
	CDateTimeCtrl	m_date;
	CComboBox	m_notice;
	CComboBox	m_product;
	CComboBox	m_city;
	double	m_income;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LuRu_tzd_Add)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LuRu_tzd_Add)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LURU_TZD_ADD_H__C7AF44C6_54F8_4579_B04E_E3BD377F2998__INCLUDED_)
