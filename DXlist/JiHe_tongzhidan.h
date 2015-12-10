#if !defined(AFX_JIHE_TONGZHIDAN_H__AD73AB31_30F7_4DD3_907D_B38BF63243DC__INCLUDED_)
#define AFX_JIHE_TONGZHIDAN_H__AD73AB31_30F7_4DD3_907D_B38BF63243DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// JiHe_tongzhidan.h : header file
//
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// JiHe_tongzhidan dialog
#include"JiHe_CHECK.h"
class JiHe_tongzhidan : public CDialog
{
// Construction
public:
	JiHe_tongzhidan(CWnd* pParent = NULL);   // standard constructor
	CString sql;
	ADOconn m_AdoConn;
	_RecordsetPtr m_pRs;
// Dialog Data
	//{{AFX_DATA(JiHe_tongzhidan)
	enum { IDD = IDD_JiHe_tongzhidan };
	CComboBox	m_TZD_notice;
	CListCtrl	m_listctrl;
	CDateTimeCtrl	m_end_date;
	CDateTimeCtrl	m_start_date;
	CComboBox	m_TZD_check;
	CComboBox	m_TZD_product;
	CComboBox	m_TZD_city;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(JiHe_tongzhidan)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(JiHe_tongzhidan)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelect();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIHE_TONGZHIDAN_H__AD73AB31_30F7_4DD3_907D_B38BF63243DC__INCLUDED_)
