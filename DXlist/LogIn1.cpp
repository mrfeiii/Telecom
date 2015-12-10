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
			MessageBox("�û������������","��¼ʧ��");
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
				name="��½�ɹ�����������Ա��";
			}
			else if(app->User_Root==2)
			{
				name="��½�ɹ���¼����Ա��";
			}
			else if(app->User_Root==3)
			{
				name="��½�ɹ���������Ա��";
			}
			else if(app->User_Root==4)
			{
				name="��½�ɹ����鼯��Ա��";
			}
			name=name+m_name;
			name=name+" ��ӭ��ʹ�ã�";
			MessageBox(name,"��½�ɹ�");
			CDialog::OnOK();
			return;
		}
	}
	else
	{
		MessageBox("�û��������벻��Ϊ��","��¼ʧ��");
	}
	
}
