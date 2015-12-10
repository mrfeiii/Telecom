#if !defined(AFX_LURU_KXS_DELET_H__41197724_492D_4494_9C94_1DA3C0430BDC__INCLUDED_)
#define AFX_LURU_KXS_DELET_H__41197724_492D_4494_9C94_1DA3C0430BDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LuRu_kxs_delet.h : header file
//
#include"ADOconn.h"

/////////////////////////////////////////////////////////////////////////////
// LuRu_kxs_delet dialog

class LuRu_kxs_delet : public CDialog
{
// Construction
public:

	LuRu_kxs_delet(CWnd* pParent = NULL);   // standard constructor
	CString date,city,product;
	double card_value,card_amount,card_discount_amount;
	int card_no;
// Dialog Data
	//{{AFX_DATA(LuRu_kxs_delet)
	enum { IDD = IDD_LuRu_kxs_Delet };
	CDateTimeCtrl	m_date;
	CComboBox	m_product;
	CComboBox	m_city;
	double	m_card_value;
	int		m_card_no;
	double	m_amount;
	double	m_discount_amount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LuRu_kxs_delet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LuRu_kxs_delet)
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

#endif // !defined(AFX_LURU_KXS_DELET_H__41197724_492D_4494_9C94_1DA3C0430BDC__INCLUDED_)
