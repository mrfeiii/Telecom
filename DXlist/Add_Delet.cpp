// Add_Delet.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "Add_Delet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CDXlistApp theApp;
/////////////////////////////////////////////////////////////////////////////
// Add_Delet dialog


Add_Delet::Add_Delet(CWnd* pParent /*=NULL*/)
	: CDialog(Add_Delet::IDD, pParent)
{
	//{{AFX_DATA_INIT(Add_Delet)
	//}}AFX_DATA_INIT
}


void Add_Delet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Add_Delet)
	DDX_Control(pDX, IDC_EDIT1, m_getmoney);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_date);
	DDX_Control(pDX, IDC_COMBO3, m_type);
	DDX_Control(pDX, IDC_COMBO2, m_product);
	DDX_Control(pDX, IDC_COMBO1, m_city);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Add_Delet, CDialog)
	//{{AFX_MSG_MAP(Add_Delet)
	ON_CBN_DROPDOWN(IDC_COMBO1, OnDropdownCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO2, OnDropdownCombo2)
	ON_CBN_DROPDOWN(IDC_COMBO3, OnDropdownCombo3)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Add_Delet message handlers

void Add_Delet::OnDropdownCombo1() 
{
	// TODO: Add your control notification handler code here

}

void Add_Delet::OnDropdownCombo2() 
{
	// TODO: Add your control notification handler code here
  
}

void Add_Delet::OnDropdownCombo3() 
{	
	// TODO: Add your control notification handler code here

}

void Add_Delet::OnChangeEdit1() 
{
    UpdateData(true);
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void Add_Delet::OnButton1() 
{
	CDialog::OnInitDialog();
	// TODO: Add your control notification handler code here

    
    CString add_city,add_product,add_type,add_date;
	int add_price=0;
	
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(add_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(add_product);
	((CComboBox*)GetDlgItem(IDC_COMBO3))->GetWindowText(add_type);
	
	
	CTime time;
	CString szDate;
	CDateTimeCtrl* pCtrl =&this->m_date;
	DWORD dwResult =pCtrl->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		szDate = time.Format(TEXT("%Y/%m"));
	}
	
	BOOL root; 
	
	add_price=GetDlgItemInt(IDC_EDIT1,&root,false);
	while( root == false) 			
	{ 	
		MessageBox("价格输入错误") ;			
	}
   CDXlistApp *app = (CDXlistApp *)AfxGetApp(); //生成指向应用程序类的指针 
  
    CString add2_price;
    add2_price.Format("%d", add_price);
 
    CString sql;
    sql="Insert Into income_account(my_date,my_city,my_product,my_type,my_price,my_user) Values('"+szDate+"','"+add_city+"','"+add_product+"','"+add_type+"',"+add2_price+",'"+app->USer_name+"')";

	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	MessageBox("添加成功");


//	MessageBox(city);

}

void Add_Delet::OnButton2() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

BOOL Add_Delet::OnInitDialog() 
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
	m_city.InsertString(0,"---请选择---");
    m_city.SetCurSel(0);

    m_product.AddString("固话-增值业务-800-国内");
    m_product.AddString("卡类-IP卡-省内IP电话卡-200卡");
    m_product.AddString("卡类-IP卡-省内IP电话卡-300卡");
    m_product.AddString("固话-基础业务-普通电话");    
	m_product.AddString("固话-基础业务-公用电话-公话超市电话");
	m_product.AddString("数据业务-互联网接入服务-宽带接入-ADSL虚拟拨号");
    m_product.AddString("数据业务-互联网接入服务-互联网普通专线接入");
    m_product.AddString("数据业务-平台业务-IDC-主机托管");
	m_product.InsertString(0,"---请选择---");
    m_product.SetCurSel(0);

	m_type.AddString("主营业务收入-公众客户-月租费收入");
	m_type.AddString("主营业务收入-公众客户-本地区间通话费");
	m_type.AddString("主营业务收入-公众客户-本地拨号上网通信费");
	m_type.AddString("主营业务收入-公众客户-本地区内通话费");
	m_type.AddString("主营业务收入-公众客户-国内长途通信费");
	m_type.AddString("主营业务收入-公众客户-国际长途通信费");
	m_type.AddString("主营业务收入-公众客户-港澳台长途通信费");
	m_type.AddString("主营业务收入-公众客户-IP国内长途通信费");
	m_type.AddString("主营业务收入-公众客户-IP国际长途通信费");
	m_type.AddString("主营业务收入-公众客户-IP港澳台长途通信费");
	m_type.AddString("主营业务收入-公众客户-装移机工料费收入"); 
	m_type.AddString("主营业务收入-公众客户-开户费收入");
	m_type.AddString("主营业务收入-公众客户-网络使用费");
	m_type.AddString("主营业务收入-公众客户-一次性费用");
	m_type.AddString("主营业务收入-公众客户-标准资费收入");
	m_type.AddString("主营业务收入-公众客户-增值业务收入");
	m_type.AddString("主营业务收入-公众客户-其他类收入");
	m_type.AddString("主营业务收入-公众客户-折扣与折让");
	m_type.InsertString(0,"---请选择---");
    m_type.SetCurSel(0);

 SYSTEMTIME tem_ST ; 

 GetLocalTime(&tem_ST);

 m_date.SetFormat("yyyy-MM");

 m_date.SetTime(&tem_ST);

 UpdateData(TRUE);


	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
