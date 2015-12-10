// JiHe_CHECK.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "JiHe_CHECK.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// JiHe_CHECK dialog


JiHe_CHECK::JiHe_CHECK(CWnd* pParent /*=NULL*/)
	: CDialog(JiHe_CHECK::IDD, pParent)
{
	//{{AFX_DATA_INIT(JiHe_CHECK)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void JiHe_CHECK::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(JiHe_CHECK)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(JiHe_CHECK, CDialog)
	//{{AFX_MSG_MAP(JiHe_CHECK)
	ON_BN_CLICKED(IDC_BUTTON1, OnPASS)
	ON_BN_CLICKED(IDC_BUTTON2, OnNOTPASS)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// JiHe_CHECK message handlers

BOOL JiHe_CHECK::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void JiHe_CHECK::OnPASS() 
{
	// TODO: Add your control notification handler code here
   	CString sql=_T("");
  //  MessageBox(table_name);
    sql.Format(_T("UPDATE %s SET my_check_state=1 WHERE my_date='%s' and my_city='%s'and my_product='%s'"),table_name,date,city,product);
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);

	OnOK();
}

void JiHe_CHECK::OnNOTPASS() 
{
	// TODO: Add your control notification handler code here
   	CString sql=_T("");

    sql.Format(_T("UPDATE %s SET my_check_state=2 WHERE my_date='%s' and my_city='%s'and my_product='%s'"),table_name,date,city,product);
		ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);

	OnOK();
}
