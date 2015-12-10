#if !defined(AFX_ADD_DELET_H__896930D2_2307_4EB0_A3E6_AFA8FF8BACD5__INCLUDED_)
#define AFX_ADD_DELET_H__896930D2_2307_4EB0_A3E6_AFA8FF8BACD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Add_Delet.h : header file
//
#include"ADOconn.h"
/////////////////////////////////////////////////////////////////////////////
// Add_Delet dialog

class Add_Delet : public CDialog
{
// Construction
public:
	Add_Delet(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Add_Delet)
	enum { IDD = IDD_Add_Delet };
	CEdit	m_getmoney;
	CDateTimeCtrl	m_date;
	CComboBox	m_type;
	CComboBox	m_product;
	CComboBox	m_city;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Add_Delet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Add_Delet)
	afx_msg void OnDropdownCombo1();
	afx_msg void OnDropdownCombo2();
	afx_msg void OnDropdownCombo3();
	afx_msg void OnChangeEdit1();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADD_DELET_H__896930D2_2307_4EB0_A3E6_AFA8FF8BACD5__INCLUDED_)
