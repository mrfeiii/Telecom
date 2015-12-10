#if !defined(AFX_JIHE_KAXIAOSHOU_H__70ECF732_C1F3_4D17_98F2_778CADB0394B__INCLUDED_)
#define AFX_JIHE_KAXIAOSHOU_H__70ECF732_C1F3_4D17_98F2_778CADB0394B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// JiHe_kaxiaoshou.h : header file
//
#include"JiHe_CHECK.h"
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// JiHe_kaxiaoshou dialog

class JiHe_kaxiaoshou : public CDialog
{
// Construction
public:
	JiHe_kaxiaoshou(CWnd* pParent = NULL);   // standard constructor
	CString sql;
	ADOconn m_AdoConn;
	 _RecordsetPtr m_pRs;
// Dialog Data
	//{{AFX_DATA(JiHe_kaxiaoshou)
	enum { IDD = IDD_JiHe_kaxiaoshou };
	CListCtrl	m_listctrl;
	CDateTimeCtrl	m_end_date;
	CDateTimeCtrl	m_start_date;
	CComboBox	m_KXS_check;
	CComboBox	m_KXS_product;
	CComboBox	m_KXS_city;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(JiHe_kaxiaoshou)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(JiHe_kaxiaoshou)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelect();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIHE_KAXIAOSHOU_H__70ECF732_C1F3_4D17_98F2_778CADB0394B__INCLUDED_)
