#if !defined(AFX_JIHE_WANGJIAN_H__923CBB80_9F6A_4B7D_ABED_803B4922DBD4__INCLUDED_)
#define AFX_JIHE_WANGJIAN_H__923CBB80_9F6A_4B7D_ABED_803B4922DBD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// JiHe_wangjian.h : header file
//
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// JiHe_wangjian dialog
#include"JiHe_CHECK.h"
class JiHe_wangjian : public CDialog
{
// Construction
public:
	JiHe_wangjian(CWnd* pParent = NULL);   // standard constructor
	CString sql;
	ADOconn m_AdoConn;
	_RecordsetPtr m_pRs;
// Dialog Data
	//{{AFX_DATA(JiHe_wangjian)
	enum { IDD = IDD_JiHe_wangjian };
	CListCtrl	m_listctrl;
	CDateTimeCtrl	m_end_date;
	CDateTimeCtrl	m_start_date;
	CComboBox	m_JH_check;
	CComboBox	m_JH_type;
	CComboBox	m_JH_operator;
	CComboBox	m_JH_product;
	CComboBox	m_JH_city;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(JiHe_wangjian)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(JiHe_wangjian)
	virtual BOOL OnInitDialog();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIHE_WANGJIAN_H__923CBB80_9F6A_4B7D_ABED_803B4922DBD4__INCLUDED_)
