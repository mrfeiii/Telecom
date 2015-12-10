#if !defined(AFX_LURU_CHUZHANG_H__4FCA8823_7FE6_4D12_9AAE_EAB33A36552A__INCLUDED_)
#define AFX_LURU_CHUZHANG_H__4FCA8823_7FE6_4D12_9AAE_EAB33A36552A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Luru_chuzhang.h : header file
//
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// Luru_chuzhang dialog

class Luru_chuzhang : public CDialog
{
// Construction
public:
	Luru_chuzhang(CWnd* pParent = NULL);   // standard constructor
	CString city;
	CString name;
	CString type;
	CString check;
	CString sql;
	ADOconn m_AdoConn;
	 _RecordsetPtr m_pRs;
	void Luru_Refresh();
	int No;

// Dialog Data
	//{{AFX_DATA(Luru_chuzhang)
	enum { IDD = IDD_LuRu_chuzhang };
	CDateTimeCtrl	m_end_date;
	CDateTimeCtrl	m_start_date;
	CListCtrl	m_listctrl;
	CComboBox	m_CZ_check;
	CComboBox	m_CZ_type;
	CComboBox	m_CZ_name;
	CComboBox	m_CZ_city;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Luru_chuzhang)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Luru_chuzhang)

	afx_msg void OnDropdownCombo1();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnDropdownCombo2();
	afx_msg void OnSelchangeCombo2();
	afx_msg void OnDropdownCombo3();
	afx_msg void OnSelchangeCombo3();
	afx_msg void OnDropdownCombo4();
	afx_msg void OnSelchangeCombo4();
	afx_msg void OnButton1Add();
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelect();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LURU_CHUZHANG_H__4FCA8823_7FE6_4D12_9AAE_EAB33A36552A__INCLUDED_)
