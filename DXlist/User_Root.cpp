// User_Root.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "User_Root.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// User_Root dialog


User_Root::User_Root(CWnd* pParent /*=NULL*/)
	: CDialog(User_Root::IDD, pParent)
{
	//{{AFX_DATA_INIT(User_Root)
	m_user_name = _T("");
	m_user_pwd = _T("");
	//}}AFX_DATA_INIT
}


void User_Root::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(User_Root)
	DDX_Control(pDX, IDC_COMBO1, m_user_type);
	DDX_Text(pDX, IDC_EDIT1, m_user_name);
	DDX_Text(pDX, IDC_EDIT5, m_user_pwd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(User_Root, CDialog)
	//{{AFX_MSG_MAP(User_Root)
	ON_BN_CLICKED(IDC_BUTTON1, OnAdd)
	ON_BN_CLICKED(IDC_BUTTON2, OnCancel_my)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT5, OnChangeEdit5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// User_Root message handlers

BOOL User_Root::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_user_type.AddString("录入人员");			
	m_user_type.AddString("稽核人员");		
	m_user_type.AddString("归集人员");
	m_user_type.InsertString(0,"--请选择--");
    m_user_type.SetCurSel(0);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void User_Root::OnAdd() 
{
	// TODO: Add your control notification handler code here

	CString sql;
    CString type;
	int root;
    ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(type);

	if( strcmp(type,"录入人员")==0 )
	{root=2;}
	else if( strcmp(type,"稽核人员")==0 )
	{root=3;}
	else if( strcmp(type,"归集人员")==0 )
	{root=4;}

	type.Format("%d",root);
    
	sql="INSERT INTO admin_table(admin_id,admin_pwd,admin_root) VALUES ('"+m_user_name+"','"+m_user_pwd+"',"+type+")";

    ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
 
	MessageBox("添加成功");
    OnOK();
}

void User_Root::OnCancel_my() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void User_Root::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
		UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	
}

void User_Root::OnChangeEdit5() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
		UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	
}
