// DXlistDlg.h : header file
//

#if !defined(AFX_DXLISTDLG_H__B777E09A_AB25_4E22_8F52_279E141686A8__INCLUDED_)
#define AFX_DXLISTDLG_H__B777E09A_AB25_4E22_8F52_279E141686A8__INCLUDED_
#include "LogIn1.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include"JiHe_chuzhang.h"

#include"JiHe_kaxiaoshou.h"
#include"JiHe_tongzhidan.h"
/////////////////////////////////////////////////////////////////////////////
// CDXlistDlg dialog
class CDXlistDlg : public CDialog
{
// Construction
public:
	CDXlistDlg(CWnd* pParent = NULL);	// standard constructor
	int Log_flag;
	LogIn lg;
    BOOL m_bCreated;
	CDXlistApp *app; 
// Dialog Data
	//{{AFX_DATA(CDXlistDlg)
	enum { IDD = IDD_DXLIST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDXlistDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
    CMenu m_menu;
	// Generated message map functions
	//{{AFX_MSG(CDXlistDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMENULRkaxiaoshou();
	afx_msg void OnMENULRtongzhidan();
	afx_msg void OnMENLRchuzhang();
	afx_msg void OnMENULRwangjian();
	afx_msg void OnMENULRyucunzhuan();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLogNew();
	afx_msg void OnLogOut();
	afx_msg void OnMENUJHchuzhang();
	afx_msg void OnMENUJHkaxiaoshou();
	afx_msg void OnMENUJHtongzhidan();
	afx_msg void OnMENUGJchuzhang();
	afx_msg void OnMENUJHwangjian();
	afx_msg void OnMENUJHyucun();
	afx_msg void OnMENUGJkaxiaoshou();
	afx_msg void OnMENUGJtongzhidan();
	afx_msg void OnMENUGJwangjian();
	afx_msg void OnMENUGJyucunzhuan();
	afx_msg void OnMENAbout();
	afx_msg void OnCreatnewuser();
	afx_msg void OnModifypsw();
	afx_msg void OnModifyusertype();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DXLISTDLG_H__B777E09A_AB25_4E22_8F52_279E141686A8__INCLUDED_)
