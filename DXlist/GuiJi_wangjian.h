#if !defined(AFX_GUIJI_WANGJIAN_H__89A35F2D_456F_4733_BC44_897300E43162__INCLUDED_)
#define AFX_GUIJI_WANGJIAN_H__89A35F2D_456F_4733_BC44_897300E43162__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GuiJi_wangjian.h : header file
//
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// GuiJi_wangjian dialog

class GuiJi_wangjian : public CDialog
{
// Construction
public:
	GuiJi_wangjian(CWnd* pParent = NULL);   // standard constructor
   ADOconn m_AdoConn;
	 _RecordsetPtr m_pRs;
	 CString sql;
// Dialog Data
	//{{AFX_DATA(GuiJi_wangjian)
	enum { IDD = IDD_GuiJi_wangjian };
	CListCtrl	m_listctrl;
	CDateTimeCtrl	m_end_date;
	CDateTimeCtrl	m_start_date;
	CComboBox	m_GJ_type;
	CComboBox	m_GJ_operator;
	CComboBox	m_GJ_product;
	CComboBox	m_GJ_city;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(GuiJi_wangjian)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(GuiJi_wangjian)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelect();
	afx_msg void OnOutPutExcel();
	afx_msg void OnOutPutTXT();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GUIJI_WANGJIAN_H__89A35F2D_456F_4733_BC44_897300E43162__INCLUDED_)
