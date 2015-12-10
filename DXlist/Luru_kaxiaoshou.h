#if !defined(AFX_LURU_KAXIAOSHOU_H__2ABE5826_1127_48E0_879F_1CECC850A8EE__INCLUDED_)
#define AFX_LURU_KAXIAOSHOU_H__2ABE5826_1127_48E0_879F_1CECC850A8EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Luru_kaxiaoshou.h : header file
//
#include"ADOconn.h"
#include"LuRu_kxs_delet.h"
#include"LuRu_kxs_Add.h"
/////////////////////////////////////////////////////////////////////////////
// Luru_kaxiaoshou dialog

class Luru_kaxiaoshou : public CDialog
{
// Construction
public:
	void Refresh();
	Luru_kaxiaoshou(CWnd* pParent = NULL);   // standard constructor
	CString sql;
	ADOconn m_AdoConn;
	 _RecordsetPtr m_pRs;
// Dialog Data
	//{{AFX_DATA(Luru_kaxiaoshou)
	enum { IDD = IDD_LuRu_kaxiaoshou };
	CDateTimeCtrl	m_end_date;
	CDateTimeCtrl	m_start_date;
	CComboBox	m_KXS_check;
	CComboBox	m_KXS_product;
	CComboBox	m_KXS_city;
	CListCtrl	m_listctrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Luru_kaxiaoshou)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Luru_kaxiaoshou)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton_Add();
	afx_msg void OnButton_Select();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LURU_KAXIAOSHOU_H__2ABE5826_1127_48E0_879F_1CECC850A8EE__INCLUDED_)
