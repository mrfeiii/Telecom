#if !defined(AFX_GUIJI_CHUZHANG_H__12BE2591_B1CC_451E_9F21_F9E8DE6286F8__INCLUDED_)
#define AFX_GUIJI_CHUZHANG_H__12BE2591_B1CC_451E_9F21_F9E8DE6286F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GuiJi_chuzhang.h : header file
//
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// GuiJi_chuzhang dialog

class GuiJi_chuzhang : public CDialog
{
// Construction
public:
	GuiJi_chuzhang(CWnd* pParent = NULL);   // standard constructor
   ADOconn m_AdoConn;
	 _RecordsetPtr m_pRs;
	 CString sql;
// Dialog Data
	//{{AFX_DATA(GuiJi_chuzhang)
	enum { IDD = IDD_GuiJi_chuzhang };
	CListCtrl	m_listctrl;
	CDateTimeCtrl	m_end_date;
	CDateTimeCtrl	m_start_date;
	CComboBox	m_GJ_type;
	CComboBox	m_GJ_product;
	CComboBox	m_GJ_city;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(GuiJi_chuzhang)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(GuiJi_chuzhang)
	afx_msg void OnOut();
	virtual BOOL OnInitDialog();
	afx_msg void OnPutoutTXT();
	afx_msg void OnSelect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GUIJI_CHUZHANG_H__12BE2591_B1CC_451E_9F21_F9E8DE6286F8__INCLUDED_)
