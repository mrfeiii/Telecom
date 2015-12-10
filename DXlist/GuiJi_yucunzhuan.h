#if !defined(AFX_GUIJI_YUCUNZHUAN_H__2A3A528E_D7EB_4A16_86AB_6C3297886AB4__INCLUDED_)
#define AFX_GUIJI_YUCUNZHUAN_H__2A3A528E_D7EB_4A16_86AB_6C3297886AB4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GuiJi_yucunzhuan.h : header file
//
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// GuiJi_yucunzhuan dialog

class GuiJi_yucunzhuan : public CDialog
{
// Construction
public:
	GuiJi_yucunzhuan(CWnd* pParent = NULL);   // standard constructor
  ADOconn m_AdoConn;
	 _RecordsetPtr m_pRs;
	 CString sql;
// Dialog Data
	//{{AFX_DATA(GuiJi_yucunzhuan)
	enum { IDD = IDD_GuiJi_yucunzhuan };
	CListCtrl	m_listctrl;
	CDateTimeCtrl	m_end_date;
	CDateTimeCtrl	m_start_date;
	CComboBox	m_GJ_type;
	CComboBox	m_GJ_product;
	CComboBox	m_GJ_city;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(GuiJi_yucunzhuan)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(GuiJi_yucunzhuan)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelect();
	afx_msg void OnOutPutExcel();
	afx_msg void OnOutPutTXT();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GUIJI_YUCUNZHUAN_H__2A3A528E_D7EB_4A16_86AB_6C3297886AB4__INCLUDED_)
