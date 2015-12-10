#if !defined(AFX_JIHE_CHUZHANG_H__88F84F5A_220E_4D5F_9DD4_0F6641CA0A31__INCLUDED_)
#define AFX_JIHE_CHUZHANG_H__88F84F5A_220E_4D5F_9DD4_0F6641CA0A31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// JiHe_chuzhang.h : header file
//
#include"JiHe_CHECK.h"
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// JiHe_chuzhang dialog

class JiHe_chuzhang : public CDialog
{
// Construction
public:
	JiHe_chuzhang(CWnd* pParent = NULL);   // standard constructor
   ADOconn m_AdoConn;
	 _RecordsetPtr m_pRs;
	 CString sql;
// Dialog Data
	//{{AFX_DATA(JiHe_chuzhang)
	enum { IDD = IDD_JiHe_chuzhang };
	CListCtrl	m_listctrl;
	CDateTimeCtrl	m_end_date;
	CDateTimeCtrl	m_start_date;
	CComboBox	m_JH_check;
	CComboBox	m_JH_type;
	CComboBox	m_JH_product;
	CComboBox	m_JH_city;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(JiHe_chuzhang)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(JiHe_chuzhang)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelect();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIHE_CHUZHANG_H__88F84F5A_220E_4D5F_9DD4_0F6641CA0A31__INCLUDED_)
