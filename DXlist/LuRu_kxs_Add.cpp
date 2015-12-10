// LuRu_kxs_Add.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "LuRu_kxs_Add.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LuRu_kxs_Add dialog


LuRu_kxs_Add::LuRu_kxs_Add(CWnd* pParent /*=NULL*/)
	: CDialog(LuRu_kxs_Add::IDD, pParent)
{
	//{{AFX_DATA_INIT(LuRu_kxs_Add)
	m_value = 0.0;
	m_no = 0;
	m_amount = 0.0;
	m_discount_amount = 0.0;
	//}}AFX_DATA_INIT
}


void LuRu_kxs_Add::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LuRu_kxs_Add)
	DDX_Control(pDX, IDC_COMBO2, m_product);
	DDX_Control(pDX, IDC_COMBO1, m_city);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_date);
	DDX_Text(pDX, IDC_EDIT1, m_value);
	DDX_Text(pDX, IDC_EDIT2, m_no);
	DDX_Text(pDX, IDC_EDIT3, m_amount);
	DDX_Text(pDX, IDC_EDIT4, m_discount_amount);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LuRu_kxs_Add, CDialog)
	//{{AFX_MSG_MAP(LuRu_kxs_Add)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_EN_KILLFOCUS(IDC_EDIT1, OnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT2, OnKillfocusEdit2)
	ON_EN_KILLFOCUS(IDC_EDIT4, OnKillfocusEdit4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LuRu_kxs_Add message handlers

BOOL LuRu_kxs_Add::OnInitDialog() 
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
	

 SYSTEMTIME tem_ST ; 

 GetLocalTime(&tem_ST);

 m_date.SetFormat("yyyy-MM-dd");

 m_date.SetTime(&tem_ST);

 UpdateData(TRUE);


	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void LuRu_kxs_Add::OnButton1() 
{

	
	// TODO: Add your control notification handler code here
	CString add_city,add_product;
	int add_no,add_value,add_amount,add_discount_amount;
	
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(add_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(add_product);
	
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
 	add_no=GetDlgItemInt(IDC_EDIT2,&root,false);
	add_amount=GetDlgItemInt(IDC_EDIT3,&root,false);
	add_discount_amount=GetDlgItemInt(IDC_EDIT4,&root,false);

   CDXlistApp *app = (CDXlistApp *)AfxGetApp(); //生成指向应用程序类的指针 

	/*CString sql=_T("");
    sql.Format(_T("INSERT INTO card_sale(my_date,my_city,my_product,my_sale_no,my_card_value,my_card_amount,my_discount_amount,my_user) VALUES('%s','%s','%s',%d,%d,%d,%d,'%s')",\
                       szDate,add_city,add_product,add_no,add_value,add_amount,add_discount_amount,app->USer_name));
	*/
   CString sql; 
   CString no,value,amount,discount;
   no.Format("%d",add_no);
   value.Format("%d",add_value);
   amount.Format("%d",add_amount);
   discount.Format("%d",add_discount_amount);
   sql="INSERT INTO card_sale(my_date,my_city,my_product,my_sale_no,my_card_value,my_card_amount,my_discount_amount,my_user) VALUES\
                       ('"+szDate+"','"+add_city+"','"+add_product+"',"+no+","+value+","+amount+","+discount+",'"+app->USer_name+"')";

    ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
 
	MessageBox("添加成功");

}

void LuRu_kxs_Add::OnButton2() 
{
	// TODO: Add your control notification handler code here
		OnCancel();
}

void LuRu_kxs_Add::OnKillfocusEdit1() 
{
	// TODO: Add your control notification handler code here
    m_amount=m_no*m_value;
    UpdateData(TRUE); 
	
    m_amount=m_no*m_value;
	UpdateData(FALSE);
}

void LuRu_kxs_Add::OnKillfocusEdit2() 
{
	// TODO: Add your control notification handler code here
    m_amount=m_no*m_value;
    UpdateData(TRUE); 
	
    m_amount=m_no*m_value;
	UpdateData(FALSE);
}

void LuRu_kxs_Add::OnKillfocusEdit4() 
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE); 

	if(m_discount_amount>m_amount)
		MessageBox("折扣后金额输入错误，请重新输入！");
}
