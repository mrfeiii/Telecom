#if !defined(AFX_LURU_YCZ_ADD_H__B1002534_710E_4837_A1BE_ECDF6A4FB977__INCLUDED_)
#define AFX_LURU_YCZ_ADD_H__B1002534_710E_4837_A1BE_ECDF6A4FB977__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LuRu_ycz_Add.h : header file
//
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// LuRu_ycz_Add dialog

class LuRu_ycz_Add : public CDialog
{
// Construction
public:
	LuRu_ycz_Add(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(LuRu_ycz_Add)
	enum { IDD = IDD_LuRu_ycz_Add };
	CDateTimeCtrl	m_date;
	CComboBox	m_type;
	CComboBox	m_product;
	CComboBox	m_city;
	double	m_amount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LuRu_ycz_Add)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LuRu_ycz_Add)
	afx_msg void OnAdd();
	virtual BOOL OnInitDialog();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LURU_YCZ_ADD_H__B1002534_710E_4837_A1BE_ECDF6A4FB977__INCLUDED_)
