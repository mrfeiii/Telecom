#if !defined(AFX_GUIJI_KAXIAOSHOU_H__26FAE3E4_2698_41C3_9940_E4794DC6F1B5__INCLUDED_)
#define AFX_GUIJI_KAXIAOSHOU_H__26FAE3E4_2698_41C3_9940_E4794DC6F1B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GuiJi_kaxiaoshou.h : header file
//
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// GuiJi_kaxiaoshou dialog

class GuiJi_kaxiaoshou : public CDialog
{
// Construction
public:
	GuiJi_kaxiaoshou(CWnd* pParent = NULL);   // standard constructor
   ADOconn m_AdoConn;
	 _RecordsetPtr m_pRs;
	 CString sql;

// Dialog Data
	//{{AFX_DATA(GuiJi_kaxiaoshou)
	enum { IDD = IDD_GuiJi_kaxiaoshou };
	CListCtrl	m_listctrl;
	CDateTimeCtrl	m_end_date;
	CDateTimeCtrl	m_start_date;
	CComboBox	m_GJ_product;
	CComboBox	m_GJ_city;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(GuiJi_kaxiaoshou)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(GuiJi_kaxiaoshou)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelect();
	afx_msg void OnOutPutExcel();
	afx_msg void OnOutPutTXT();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GUIJI_KAXIAOSHOU_H__26FAE3E4_2698_41C3_9940_E4794DC6F1B5__INCLUDED_)
