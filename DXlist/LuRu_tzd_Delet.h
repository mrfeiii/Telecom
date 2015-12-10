#if !defined(AFX_LURU_TZD_DELET_H__63481AAA_DD36_4818_9E1F_39D1D6CD6F04__INCLUDED_)
#define AFX_LURU_TZD_DELET_H__63481AAA_DD36_4818_9E1F_39D1D6CD6F04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LuRu_tzd_Delet.h : header file
//
#include"ADOconn.h"

/////////////////////////////////////////////////////////////////////////////
// LuRu_tzd_Delet dialog

class LuRu_tzd_Delet : public CDialog
{
// Construction
public:
	LuRu_tzd_Delet(CWnd* pParent = NULL);   // standard constructor
    CString date,city,product,notice;
	double value;
// Dialog Data
	//{{AFX_DATA(LuRu_tzd_Delet)
	enum { IDD = IDD_LuRu_tzd_Delete };
	CDateTimeCtrl	m_date;
	CComboBox	m_notice;
	CComboBox	m_product;
	CComboBox	m_city;
	double	m_value;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LuRu_tzd_Delet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LuRu_tzd_Delet)
	virtual BOOL OnInitDialog();
	afx_msg void OnDelete();
	afx_msg void OnModify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LURU_TZD_DELET_H__63481AAA_DD36_4818_9E1F_39D1D6CD6F04__INCLUDED_)
