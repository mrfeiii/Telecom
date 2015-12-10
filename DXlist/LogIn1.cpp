// LogIn1.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "LogIn1.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LogIn dialog


LogIn::LogIn(CWnd* pParent /*=NULL*/)
: CDialog(LogIn::IDD, pParent)
{
	
	//{{AFX_DATA_INIT(LogIn)
	m_name = _T("");
	m_pwd = _T("");
	//}}AFX_DATA_INIT
}


void LogIn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LogIn)
	DDX_Text(pDX, IDC_EDIT_name, m_name);
	DDX_Text(pDX, IDC_EDIT_pwd, m_pwd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LogIn, CDialog)
//{{AFX_MSG_MAP(LogIn)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LogIn message handlers

void LogIn::OnCancel() 
{
	// TODO: Add extra cleanup here
	
    exit(0);
}

void LogIn::OnOK() 
{
	ADOconn m_AdoConn;
	// TODO: Add extra validation here
	UpdateData();
	if(!m_name.IsEmpty()&&!m_pwd.IsEmpty()||true)
	{
		CString sql="select * from admin_table where admin_id='"+m_name+"' and admin_pwd='"+m_pwd+"' ";
		
		_RecordsetPtr m_pRs;
		
		CDXlistApp *app = (CDXlistApp *)AfxGetApp(); 
		
		m_AdoConn.OnInitADOConn();
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		if(m_pRs->adoEOF)
		{
			MessageBox("用户名或密码错误！","登录失败");
			m_name="";
			m_pwd="";
			UpdateData(false);
		}
		else
		{
			app->USer_name=m_name;
            app->User_psw=m_pwd;
			CString str=(char*)(_bstr_t)m_pRs->GetCollect("admin_root");
			app->User_Root=atoi(str);
			CString name;
			if(app->User_Root==1)
			{
				name="登陆成功，超级管理员：";
			}
			else if(app->User_Root==2)
			{
				name="登陆成功，录入人员：";
			}
			else if(app->User_Root==3)
			{
				name="登陆成功，稽核人员：";
			}
			else if(app->User_Root==4)
			{
				name="登陆成功，归集人员：";
			}
			name=name+m_name;
			name=name+" 欢迎您使用！";
			MessageBox(name,"登陆成功");
			CDialog::OnOK();
			return;
		}
	}
	else
	{
		MessageBox("用户名和密码不能为空","登录失败");
	}
	
}
