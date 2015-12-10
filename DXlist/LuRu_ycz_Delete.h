#if !defined(AFX_LURU_YCZ_DELETE_H__19256434_6D21_41EC_B004_8140B492D485__INCLUDED_)
#define AFX_LURU_YCZ_DELETE_H__19256434_6D21_41EC_B004_8140B492D485__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LuRu_ycz_Delete.h : header file
//
#include"ADOconn.h"

/////////////////////////////////////////////////////////////////////////////
// LuRu_ycz_Delete dialog

class LuRu_ycz_Delete : public CDialog
{
// Construction
public:
	LuRu_ycz_Delete(CWnd* pParent = NULL);   // standard constructor
   CString date,city,product,type;
	double amount;
// Dialog Data
	//{{AFX_DATA(LuRu_ycz_Delete)
	enum { IDD = IDD_LuRu_ycz_Delete };
	CDateTimeCtrl	m_date;
	CComboBox	m_type;
	CComboBox	m_product;
	CComboBox	m_city;
	double	m_amount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LuRu_ycz_Delete)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LuRu_ycz_Delete)
	virtual BOOL OnInitDialog();
	afx_msg void OnDelete();
	afx_msg void OnModify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LURU_YCZ_DELETE_H__19256434_6D21_41EC_B004_8140B492D485__INCLUDED_)
