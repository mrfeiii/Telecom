#if !defined(AFX_LURU_WJ_DELET_H__3A9BBD69_CB00_4764_8072_D1F2E48DF0B5__INCLUDED_)
#define AFX_LURU_WJ_DELET_H__3A9BBD69_CB00_4764_8072_D1F2E48DF0B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LuRu_wj_Delet.h : header file
//
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// LuRu_wj_Delet dialog

class LuRu_wj_Delet : public CDialog
{
// Construction
public:
	LuRu_wj_Delet(CWnd* pParent = NULL);   // standard constructor
    CString date,city,product,my_operator,type;
	double amount;
// Dialog Data
	//{{AFX_DATA(LuRu_wj_Delet)
	enum { IDD = IDD_LuRu_wj_Delete };
	CDateTimeCtrl	m_date;
	CComboBox	m_type;
	CComboBox	m_operator;
	CComboBox	m_product;
	CComboBox	m_city;
	double	m_amount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LuRu_wj_Delet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LuRu_wj_Delet)
	virtual BOOL OnInitDialog();
	afx_msg void OnDelet();
	afx_msg void OnModify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LURU_WJ_DELET_H__3A9BBD69_CB00_4764_8072_D1F2E48DF0B5__INCLUDED_)
