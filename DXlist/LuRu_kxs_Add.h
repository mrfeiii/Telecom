#if !defined(AFX_LURU_KXS_ADD_H__2B4ACEFC_579D_4959_BAB5_1C6CA877AD1F__INCLUDED_)
#define AFX_LURU_KXS_ADD_H__2B4ACEFC_579D_4959_BAB5_1C6CA877AD1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LuRu_kxs_Add.h : header file
//
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// LuRu_kxs_Add dialog

class LuRu_kxs_Add : public CDialog
{
// Construction
public:
	LuRu_kxs_Add(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(LuRu_kxs_Add)
	enum { IDD = IDD_LuRu_kxs_Add };
	CComboBox	m_product;
	CComboBox	m_city;
	CDateTimeCtrl	m_date;
	double	m_value;
	int		m_no;
	double	m_amount;
	double	m_discount_amount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LuRu_kxs_Add)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LuRu_kxs_Add)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnKillfocusEdit1();
	afx_msg void OnKillfocusEdit2();
	afx_msg void OnKillfocusEdit4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LURU_KXS_ADD_H__2B4ACEFC_579D_4959_BAB5_1C6CA877AD1F__INCLUDED_)
