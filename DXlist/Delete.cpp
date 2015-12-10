// Delete.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "Delete.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Delete dialog


Delete::Delete(CWnd* pParent /*=NULL*/)
: CDialog(Delete::IDD, pParent)
{
	
	//{{AFX_DATA_INIT(Delete)
	m_money = _T("");
	//}}AFX_DATA_INIT
}


void Delete::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Delete)
	DDX_Control(pDX, IDC_EDIT1, m_getmoney);
	DDX_Control(pDX, IDC_COMBO3, m_type);
	DDX_Control(pDX, IDC_COMBO2, m_product);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_date);
	DDX_Control(pDX, IDC_COMBO1, m_city);
	DDX_Text(pDX, IDC_EDIT1, m_money);
	//}}AFX_DATA_MAP
	
}


BEGIN_MESSAGE_MAP(Delete, CDialog)
//{{AFX_MSG_MAP(Delete)
ON_CBN_DROPDOWN(IDC_COMBO1, OnDropdownCombo1)
ON_CBN_DROPDOWN(IDC_COMBO2, OnDropdownCombo2)
ON_CBN_DROPDOWN(IDC_COMBO3, OnDropdownCombo3)
ON_BN_CLICKED(IDC_BUTTON1, OnDelete)
ON_BN_CLICKED(IDC_BUTTON2, OnModify)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Delete message handlers

BOOL Delete::OnInitDialog() 
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
	// TODO: Add extra initialization here
	//GetDlgItem(IDC_COMBO1)->SetWindowTest("aa");
    
    int nIndex = m_city.FindStringExact( -1 , city );
	m_city.SetCurSel(nIndex); 
	nIndex = m_product.FindStringExact( -1 , product );
	m_product.SetCurSel(nIndex); 
	nIndex = m_type.FindStringExact( -1 , type );
	m_type.SetCurSel(nIndex); 
	
	CString str;
	str.Format("%d",money);
	m_money=str;
	UpdateData(FALSE); 
	
	m_date.SetFormat("yyyy-MM");
	CString year,month;
	year=date.Left(4);
	month=date.Right(2);
	int y=atoi(year);
	int m=atoi(month);
	m=m+1;
	CTime time(y,m,0,0,0,0);
    
	m_date.SetTime(&time); 
	
	UpdateData(TRUE);
	
    
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}




void Delete::OnDropdownCombo1() 
{
	// TODO: Add your control notification handler code here
	/*	m_city.AddString("江西本部");
	
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
	*/
}

void Delete::OnDropdownCombo2() 
{
	// TODO: Add your control notification handler code here
	/*	m_product.AddString("固话-增值业务-800-国内");
	m_product.AddString("卡类-IP卡-省内IP电话卡-200卡");
	m_product.AddString("卡类-IP卡-省内IP电话卡-300卡");
	m_product.AddString("固话-基础业务-普通电话");
	m_product.AddString("固话-基础业务-公用电话-公话超市电话");
	m_product.AddString("数据业务-互联网接入服务-宽带接入-ADSL虚拟拨号");
	m_product.AddString("数据业务-互联网接入服务-互联网普通专线接入");
	m_product.AddString("数据业务-平台业务-IDC-主机托管");
	*/
}

void Delete::OnDropdownCombo3() 
{
	// TODO: Add your control notification handler code here
	/*	m_type.AddString("主营业务收入-公众客户-月租费收入");
	m_type.AddString("主营业务收入-公众客户-本地区间通话费 ");
	m_type.AddString("主营业务收入-公众客户-本地拨号上网通信费 ");
	m_type.AddString("主营业务收入-公众客户-本地区内通话费 ");
	m_type.AddString("主营业务收入-公众客户-国内长途通信费 ");
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
	m_type.AddString(" 主营业务收入-公众客户-其他类收入");
	m_type.AddString("主营业务收入-公众客户-折扣与折让");
	*/
}

void Delete::OnDelete() 
{
	//TODO: Add your control notification handler code here
	
	
	CString sql;
	sql="Delete from income_account where my_date='"+date+"'  AND my_city='"+city+"' AND my_product='"+product+"' AND my_type='"+type+"'  ";
	ADOconn m_AdoConn;
	_RecordsetPtr m_pRs;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	
	
    CDialog::OnOK();
	
	
	
}

void Delete::OnModify() 
{
	CString alter_city,alter_product,alter_type,alter_date;
	int alter_price=0;
	
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(alter_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(alter_product);
	((CComboBox*)GetDlgItem(IDC_COMBO3))->GetWindowText(alter_type);
	
	
	CTime time;
	CString szDate;
	CDateTimeCtrl* pCtrl =&this->m_date;
	DWORD dwResult =pCtrl->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		szDate = time.Format(TEXT("%Y/%m"));
	}
	
	BOOL root; 
	
	
	alter_price=GetDlgItemInt(IDC_EDIT1,&root,false);
	while( root == false) 			
	{ 	
		MessageBox("价格输入错误") ;			
	}




	CString sql=_T("");
    sql.Format(_T("UPDATE income_account SET my_date='%s',my_product='%s',my_type='%s',my_price=%d , my_city='%s' WHERE my_product='%s' and my_type='%s' and my_price=%d and my_product='%s'"),szDate,alter_product,alter_type,alter_price,alter_city,product,type,money,product);

	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	MessageBox("修改成功");

	OnOK();
	// TODO Add your control notification handler code here
	
}
