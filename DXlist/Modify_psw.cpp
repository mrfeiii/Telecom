// Modify_psw.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "Modify_psw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Modify_psw dialog


Modify_psw::Modify_psw(CWnd* pParent /*=NULL*/)
	: CDialog(Modify_psw::IDD, pParent)
{
	//{{AFX_DATA_INIT(Modify_psw)
	m_old_psw = _T("");
	m_new_psw2 = _T("");
	m_new_psw1 = _T("");
	//}}AFX_DATA_INIT
}


void Modify_psw::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Modify_psw)
	DDX_Text(pDX, IDC_EDIT1, m_old_psw);
	DDX_Text(pDX, IDC_EDIT6, m_new_psw2);
	DDX_Text(pDX, IDC_EDIT5, m_new_psw1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Modify_psw, CDialog)
	//{{AFX_MSG_MAP(Modify_psw)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Modify_psw message handlers

void Modify_psw::OnButton1() 
{
    CDXlistApp *app = (CDXlistApp *)AfxGetApp();
    UpdateData(TRUE);
	if(app->User_psw!=m_old_psw)
	{
		MessageBox("您输入的旧密码不对，请重新输入!","警告");
	}
	else
	{
       if(m_new_psw1!=m_new_psw2)
	   {
		   MessageBox("您两次输入的密码不一致，请重新输入","错误");
	   }
	   else
	   {
	m_AdoConn.OnInitADOConn();
	sql="UPDATE admin_table SET admin_pwd='"+m_new_psw1+"'  WHERE admin_id='"+app->USer_name+"' ";
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	MessageBox("密码已修改！","修改成功");
    OnOK();
	   }

	}
	// TODO: Add your control notification handler code here
	
}

void Modify_psw::OnButton2() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}
