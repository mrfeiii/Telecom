// LuRu_tzd_Add.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "LuRu_tzd_Add.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LuRu_tzd_Add dialog


LuRu_tzd_Add::LuRu_tzd_Add(CWnd* pParent /*=NULL*/)
	: CDialog(LuRu_tzd_Add::IDD, pParent)
{
	//{{AFX_DATA_INIT(LuRu_tzd_Add)
	m_income = 0.0;
	//}}AFX_DATA_INIT
}


void LuRu_tzd_Add::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LuRu_tzd_Add)
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_date);
	DDX_Control(pDX, IDC_COMBO3, m_notice);
	DDX_Control(pDX, IDC_COMBO2, m_product);
	DDX_Control(pDX, IDC_COMBO1, m_city);
	DDX_Text(pDX, IDC_EDIT1, m_income);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LuRu_tzd_Add, CDialog)
	//{{AFX_MSG_MAP(LuRu_tzd_Add)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LuRu_tzd_Add message handlers

BOOL LuRu_tzd_Add::OnInitDialog() 
{
	CDialog::OnInitDialog();
	 m_city.AddString("江西本部");
	m_city.AddString("江西景德镇");
	m_city.AddString("江西南昌");
	m_city.AddString("江西吉安");
	m_city.AddString("江西赣州");
	m_city.AddString("江西新余");
    m_city.AddString("江西鹰潭");
	m_city.AddString("江西九江");	
	m_city.AddString("江西宜春");		
	m_city.AddString("江西上饶");			
	m_city.AddString("江西萍乡");		
	m_city.AddString("江西抚州");
	m_city.InsertString(0,"——请选择——");
    m_city.SetCurSel(0);
	
	
	m_product.AddString("固话-增值业务-800-国内");
	m_product.AddString("卡类-IP卡-省内IP电话卡-200卡");
	m_product.AddString("卡类-IP卡-省内IP电话卡-300卡");
	m_product.AddString("固话-基础业务-普通电话");
	m_product.AddString("固话-基础业务-公用电话-公话超市电话");
	m_product.AddString("数据业务-互联网接入服务-宽带接入-ADSL虚拟拨号");
	m_product.AddString("数据业务-互联网接入服务-互联网普通专线接入");
	m_product.AddString("数据业务-平台业务-IDC-主机托管");
   	m_product.InsertString(0,"——请选择——");
	m_product.SetCurSel(0);
	
		
	m_notice.AddString("主业-公众-装移机工料费-普通电话");
	m_notice.AddString("主业-公众-开户费-普通电话");
	m_notice.AddString("主业-公众-一次性费用-普通电话");
	m_notice.AddString("预收账款-用户预存款-普通电话");
	m_notice.AddString("主业-公众-一次性费用-公用电话-公话超市电话");
	m_notice.AddString("预收账款-用户预存款-公用电话-公话超市电话");
	m_notice.AddString("主业-公众-开户费-公用电话-公话超市电话");
	m_notice.AddString("主业-公众-装移机工料费-公用电话-公话超市电话");
	m_notice.AddString("主业-公众-装移机工料费-IDC-主机托管");
	m_notice.AddString("主业-公众-开户费-IDC-主机托管");
	m_notice.AddString("主业-公众-一次性费用-IDC-主机托管");
	m_notice.AddString("主业-公众-装移机工料费-宽带-ADSL虚拟拨号");
	m_notice.AddString("主业-公众-一次性费用-宽带-ADSL虚拟拨号");
	m_notice.AddString("主业-公众-开户费-宽带-ADSL虚拟拨号");
	m_notice.AddString("主业-公众-装移机工料费-宽带-ADSL虚拟拨号");
	m_notice.AddString("预收账款-预付费卡款-面值-200卡");
	m_notice.AddString("预收账款-预付费卡款-销售折扣-200卡");
	m_notice.AddString("预收账款-预付费卡款-面值-300卡");
	m_notice.AddString("预收账款-预付费卡款-销售折扣-300卡");
	m_notice.InsertString(0,"——请选择——");
    m_notice.SetCurSel(0);

    SYSTEMTIME tem_ST ; 
	
	GetLocalTime(&tem_ST);
	
	m_date.SetFormat("yyyy-MM-dd");
	m_date.SetTime(&tem_ST);
	
	UpdateData(TRUE);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void LuRu_tzd_Add::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString add_city,add_product,add_notice;
	double add_value;
	
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(add_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(add_product);
	((CComboBox*)GetDlgItem(IDC_COMBO3))->GetWindowText(add_notice);

	CTime time;
	CString szDate;
	CDateTimeCtrl* pCtrl =&this->m_date;
	DWORD dwResult =pCtrl->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		szDate = time.Format(TEXT("%Y/%m/%d"));
	}
	
	BOOL root; 	
	add_value=GetDlgItemInt(IDC_EDIT1,&root,false);

   CDXlistApp *app = (CDXlistApp *)AfxGetApp(); //生成指向应用程序类的指针 

   CString sql; 
   CString value;

   value.Format("%lf",add_value);

   sql="INSERT INTO notice(my_date,my_city,my_product,my_notice,my_income,my_user) VALUES\
                       ('"+szDate+"','"+add_city+"','"+add_product+"','"+add_notice+"',"+value+",'"+app->USer_name+"')";

    ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
 
	MessageBox("添加成功");
}

void LuRu_tzd_Add::OnButton2() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}
