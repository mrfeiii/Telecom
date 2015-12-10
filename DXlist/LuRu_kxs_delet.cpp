// LuRu_kxs_delet.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "LuRu_kxs_delet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LuRu_kxs_delet dialog


LuRu_kxs_delet::LuRu_kxs_delet(CWnd* pParent /*=NULL*/)
	: CDialog(LuRu_kxs_delet::IDD, pParent)
{
	//{{AFX_DATA_INIT(LuRu_kxs_delet)
	m_card_value = 0.0;
	m_card_no = 0;
	m_amount = 0.0;
	m_discount_amount = 0.0;
	//}}AFX_DATA_INIT
}


void LuRu_kxs_delet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LuRu_kxs_delet)
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_date);
	DDX_Control(pDX, IDC_COMBO2, m_product);
	DDX_Control(pDX, IDC_COMBO1, m_city);
	DDX_Text(pDX, IDC_EDIT1, m_card_value);
	DDX_Text(pDX, IDC_EDIT2, m_card_no);
	DDX_Text(pDX, IDC_EDIT3, m_amount);
	DDX_Text(pDX, IDC_EDIT4, m_discount_amount);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LuRu_kxs_delet, CDialog)
	//{{AFX_MSG_MAP(LuRu_kxs_delet)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_EN_KILLFOCUS(IDC_EDIT1, OnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT2, OnKillfocusEdit2)
	ON_EN_KILLFOCUS(IDC_EDIT4, OnKillfocusEdit4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LuRu_kxs_delet message handlers

BOOL LuRu_kxs_delet::OnInitDialog() 
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
	
	m_product.AddString("固话-增值业务-800-国内");
	m_product.AddString("卡类-IP卡-省内IP电话卡-200卡");
	m_product.AddString("卡类-IP卡-省内IP电话卡-300卡");
	m_product.AddString("固话-基础业务-普通电话");
	m_product.AddString("固话-基础业务-公用电话-公话超市电话");
	m_product.AddString("数据业务-互联网接入服务-宽带接入-ADSL虚拟拨号");
	m_product.AddString("数据业务-互联网接入服务-互联网普通专线接入");
	m_product.AddString("数据业务-平台业务-IDC-主机托管");
	
    
    
    int nIndex = m_city.FindStringExact( -1 , city );
	m_city.SetCurSel(nIndex); 
	nIndex = m_product.FindStringExact( -1 , product );
	m_product.SetCurSel(nIndex); 

	
	m_card_value=card_value;
	m_card_no=card_no;
	m_amount=card_amount;
	m_discount_amount=card_discount_amount;
	UpdateData(FALSE); 
	
	m_date.SetFormat("yyyy-MM-dd");
	CString year,month,day;
	year=date.Left(4);
	month=date.Mid(6, 7);
	day=date.Right(2);
	int y=atoi(year);
	int m=atoi(month);
	int d=atoi(day);
	m=m+1;
	CTime time(y,m,d,0,0,0);
    
	m_date.SetTime(&time); 
	
	UpdateData(TRUE);
	
    
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void LuRu_kxs_delet::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString sql;
	CString no,value;
	no.Format("%d",m_card_no);
	value.Format("%lf",m_card_value);
	sql="Delete from card_sale where my_date='"+date+"' AND my_city='"+city+"' AND my_product='"+product+"' ";
	ADOconn m_AdoConn;
	_RecordsetPtr m_pRs;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);


	
    CDialog::OnOK();

}

void LuRu_kxs_delet::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CString alter_city,alter_product;
	int alter_no,alter_value,alter_amount,alter_discount_amount;
	
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(alter_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(alter_product);
	
	CTime time;
	CString szDate;
	CDateTimeCtrl* pCtrl =&this->m_date;
	DWORD dwResult =pCtrl->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		szDate = time.Format(TEXT("%Y/%m/%d"));
	}
	
	BOOL root; 	
	alter_value=GetDlgItemInt(IDC_EDIT1,&root,false);
 	alter_no=GetDlgItemInt(IDC_EDIT2,&root,false);
	alter_amount=GetDlgItemInt(IDC_EDIT3,&root,false);
	alter_discount_amount=GetDlgItemInt(IDC_EDIT4,&root,false);


	CString sql=_T("");
    sql.Format(_T("UPDATE card_sale SET  my_date='%s',my_city='%s',my_product='%s',my_sale_no=%d,my_card_value=%d,my_card_amount=%d,my_discount_amount=%d WHERE my_product='%s' and my_city='%s' and my_date='%s' "),\
                      szDate,alter_city,alter_product,alter_no,alter_value,alter_amount,alter_discount_amount,product,city,date);
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	MessageBox("修改成功");

	OnOK();
}



void LuRu_kxs_delet::OnKillfocusEdit1() 
{
	// TODO: Add your control notification handler code here
    m_amount=m_card_no*m_card_value;
    UpdateData(TRUE); 
	
	m_amount=m_card_no*m_card_value;
	UpdateData(FALSE);
}


void LuRu_kxs_delet::OnKillfocusEdit2() 
{
	// TODO: Add your control notification handler code here
    m_amount=m_card_no*m_card_value;
    UpdateData(TRUE); 
	
	m_amount=m_card_no*m_card_value;
	UpdateData(FALSE);
}

void LuRu_kxs_delet::OnKillfocusEdit4() 
{
    UpdateData(TRUE); 
	// TODO: Add your control notification handler code here
	if(m_discount_amount>m_amount)
		MessageBox("折扣后金额输入错误，请重新输入！");
}
