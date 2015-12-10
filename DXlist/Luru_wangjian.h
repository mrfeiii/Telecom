#if !defined(AFX_LURU_WANGJIAN_H__98E185AB_7FA7_480E_986A_0C07469E0E97__INCLUDED_)
#define AFX_LURU_WANGJIAN_H__98E185AB_7FA7_480E_986A_0C07469E0E97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Luru_wangjian.h : header file
//
#include"ADOconn.h"
#include"LuRu_wj_Delet.h"
#include"LuRu_wj_Add.h"
/////////////////////////////////////////////////////////////////////////////
// Luru_wangjian dialog

class Luru_wangjian : public CDialog
{
// Construction
public:
	void Refresh();
	Luru_wangjian(CWnd* pParent = NULL);   // standard constructor
	CString sql;
	ADOconn m_AdoConn;
	_RecordsetPtr m_pRs;
// Dialog Data
	//{{AFX_DATA(Luru_wangjian)
	enum { IDD = IDD_LuRu_wangjian };
	CComboBox	m_WJ_check;
	CComboBox	m_WJ_type;
	CComboBox	m_WJ_operator;
	CComboBox	m_WJ_product;
	CComboBox	m_WJ_city;
	CListCtrl	m_listctrl;
	CDateTimeCtrl	m_end_date;
	CDateTimeCtrl	m_start_date;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Luru_wangjian)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Luru_wangjian)
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	afx_msg void OnSelect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LURU_WANGJIAN_H__98E185AB_7FA7_480E_986A_0C07469E0E97__INCLUDED_)
