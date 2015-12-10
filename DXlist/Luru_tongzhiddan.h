#if !defined(AFX_LURU_TONGZHIDDAN_H__E8E7F1B0_0201_43D5_91BB_1B9795762DF1__INCLUDED_)
#define AFX_LURU_TONGZHIDDAN_H__E8E7F1B0_0201_43D5_91BB_1B9795762DF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Luru_tongzhiddan.h : header file
//
#include"ADOconn.h"
#include"LuRu_tzd_Delet.h"
#include"LuRu_tzd_Add.h"
/////////////////////////////////////////////////////////////////////////////
// Luru_tongzhiddan dialog

class Luru_tongzhiddan : public CDialog
{
// Construction
public:
	void Refresh();
	Luru_tongzhiddan(CWnd* pParent = NULL);   // standard constructor
	CString sql;
	ADOconn m_AdoConn;
	_RecordsetPtr m_pRs;
// Dialog Data
	//{{AFX_DATA(Luru_tongzhiddan)
	enum { IDD = IDD_LuRu_tongzhidan };
	CListCtrl	m_listctrl;
	CComboBox	m_TZD_check;
	CComboBox	m_TZD_notice;
	CComboBox	m_TZD_product;
	CComboBox	m_TZD_city;
	CDateTimeCtrl	m_end_date;
	CDateTimeCtrl	m_start_date;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Luru_tongzhiddan)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Luru_tongzhiddan)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnADD();
	afx_msg void OnSelect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LURU_TONGZHIDDAN_H__E8E7F1B0_0201_43D5_91BB_1B9795762DF1__INCLUDED_)
