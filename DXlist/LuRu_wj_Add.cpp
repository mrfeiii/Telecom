// LuRu_wj_Add.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "LuRu_wj_Add.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LuRu_wj_Add dialog


LuRu_wj_Add::LuRu_wj_Add(CWnd* pParent /*=NULL*/)
	: CDialog(LuRu_wj_Add::IDD, pParent)
{
	//{{AFX_DATA_INIT(LuRu_wj_Add)
	m_amount = 0.0;
	//}}AFX_DATA_INIT
}


void LuRu_wj_Add::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LuRu_wj_Add)
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_date);
	DDX_Control(pDX, IDC_COMBO5, m_type);
	DDX_Control(pDX, IDC_COMBO3, m_operator);
	DDX_Control(pDX, IDC_COMBO2, m_product);
	DDX_Control(pDX, IDC_COMBO1, m_city);
	DDX_Text(pDX, IDC_EDIT1, m_amount);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LuRu_wj_Add, CDialog)
	//{{AFX_MSG_MAP(LuRu_wj_Add)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LuRu_wj_Add message handlers

BOOL LuRu_wj_Add::OnInitDialog() 
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
	
	m_operator.AddString("电信");
	m_operator.AddString("移动");
	m_operator.AddString("联通");
	m_operator.InsertString(0,"——请选择——");
    m_operator.SetCurSel(0);
	
	m_type.AddString("结算支出");
	m_type.AddString("结算收入");
	m_type.InsertString(0,"——请选择——");
    m_type.SetCurSel(0);

    SYSTEMTIME tem_ST ; 
	
	GetLocalTime(&tem_ST);
	
	m_date.SetFormat("yyyy-MM");
	m_date.SetTime(&tem_ST);
	
	UpdateData(TRUE);
	// TODO: Add extra initialization here
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void LuRu_wj_Add::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString add_city,add_product,add_operator,add_type;
	double add_amount;
	
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(add_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(add_product);
	((CComboBox*)GetDlgItem(IDC_COMBO3))->GetWindowText(add_operator);
	((CComboBox*)GetDlgItem(IDC_COMBO5))->GetWindowText(add_type);

	CTime time;
	CString szDate;
	CDateTimeCtrl* pCtrl =&this->m_date;
	DWORD dwResult =pCtrl->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		szDate = time.Format(TEXT("%Y/%m"));
	}
	
	BOOL root; 	
	add_amount=GetDlgItemInt(IDC_EDIT1,&root,false);

   CDXlistApp *app = (CDXlistApp *)AfxGetApp(); //生成指向应用程序类的指针 

   CString sql; 
   CString amount;

   amount.Format("%lf",add_amount);

   sql="INSERT INTO network(my_date,my_city,my_product,my_operator,my_type,my_amount,my_user) VALUES\
                       ('"+szDate+"','"+add_city+"','"+add_product+"','"+add_operator+"','"+add_type+"',"+amount+",'"+app->USer_name+"')";

    ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
 
	MessageBox("添加成功");
}

void LuRu_wj_Add::OnButton2() 
{
	// TODO: Add your control notification handler code here
		OnCancel();
}
