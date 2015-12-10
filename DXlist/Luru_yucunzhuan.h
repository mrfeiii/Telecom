#if !defined(AFX_LURU_YUCUNZHUAN_H__6578F3F6_4E22_4695_9B5C_0C9F41AB985B__INCLUDED_)
#define AFX_LURU_YUCUNZHUAN_H__6578F3F6_4E22_4695_9B5C_0C9F41AB985B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Luru_yucunzhuan.h : header file
//
#include"ADOconn.h"
#include"LuRu_ycz_Delete.h"
#include"LuRu_ycz_Add.h"
/////////////////////////////////////////////////////////////////////////////
// Luru_yucunzhuan dialog

class Luru_yucunzhuan : public CDialog
{
// Construction
public:
	void Refresh();
	Luru_yucunzhuan(CWnd* pParent = NULL);   // standard constructor

	CString sql;
	ADOconn m_AdoConn;
	_RecordsetPtr m_pRs;

// Dialog Data
	//{{AFX_DATA(Luru_yucunzhuan)
	enum { IDD = IDD_LuRu_yucunzhuan };
	CComboBox	m_ycz_check;
	CListCtrl	m_listctrl;
	CDateTimeCtrl	m_end_date;
	CDateTimeCtrl	m_start_date;
	CComboBox	m_ycz_type;
	CComboBox	m_ycz_product;
	CComboBox	m_ycz_city;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Luru_yucunzhuan)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Luru_yucunzhuan)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd();
	afx_msg void OnSelect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LURU_YUCUNZHUAN_H__6578F3F6_4E22_4695_9B5C_0C9F41AB985B__INCLUDED_)
