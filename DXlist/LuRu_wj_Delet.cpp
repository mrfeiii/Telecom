// LuRu_wj_Delet.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "LuRu_wj_Delet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LuRu_wj_Delet dialog


LuRu_wj_Delet::LuRu_wj_Delet(CWnd* pParent /*=NULL*/)
	: CDialog(LuRu_wj_Delet::IDD, pParent)
{
	//{{AFX_DATA_INIT(LuRu_wj_Delet)
	m_amount = 0.0;
	//}}AFX_DATA_INIT
}


void LuRu_wj_Delet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LuRu_wj_Delet)
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_date);
	DDX_Control(pDX, IDC_COMBO5, m_type);
	DDX_Control(pDX, IDC_COMBO3, m_operator);
	DDX_Control(pDX, IDC_COMBO2, m_product);
	DDX_Control(pDX, IDC_COMBO1, m_city);
	DDX_Text(pDX, IDC_EDIT1, m_amount);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LuRu_wj_Delet, CDialog)
	//{{AFX_MSG_MAP(LuRu_wj_Delet)
	ON_BN_CLICKED(IDC_BUTTON1, OnDelet)
	ON_BN_CLICKED(IDC_BUTTON2, OnModify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LuRu_wj_Delet message handlers

BOOL LuRu_wj_Delet::OnInitDialog() 
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

	
	m_operator.AddString("电信");
	m_operator.AddString("移动");
	m_operator.AddString("联通");

	
	m_type.AddString("结算支出");
	m_type.AddString("结算收入");


    int nIndex = m_city.FindStringExact( -1 , city );
	m_city.SetCurSel(nIndex); 
	nIndex = m_product.FindStringExact( -1 , product );
	m_product.SetCurSel(nIndex); 
	nIndex = m_operator.FindStringExact( -1 , my_operator );
	m_operator.SetCurSel(nIndex); 
	nIndex = m_type.FindStringExact( -1 , type );
	m_type.SetCurSel(nIndex); 

	m_amount=amount;
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
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void LuRu_wj_Delet::OnDelet() 
{
	// TODO: Add your control notification handler code here
	CString sql;
	sql="Delete from network where my_date='"+date+"' AND my_city='"+city+"' AND my_product='"+product+"' AND my_operator='"+my_operator+"' ";
	ADOconn m_AdoConn;
	_RecordsetPtr m_pRs;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	
    CDialog::OnOK();
}

void LuRu_wj_Delet::OnModify() 
{
	// TODO: Add your control notification handler code here
	CString alter_city,alter_product,alter_operator,alter_type;
	double alter_amount;
	
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(alter_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(alter_product);
    ((CComboBox*)GetDlgItem(IDC_COMBO3))->GetWindowText(alter_operator);
    ((CComboBox*)GetDlgItem(IDC_COMBO5))->GetWindowText(alter_type);

	CTime time;
	CString szDate;
	CDateTimeCtrl* pCtrl =&this->m_date;
	DWORD dwResult =pCtrl->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		szDate = time.Format(TEXT("%Y/%m"));
	}
	
	BOOL root; 	
	alter_amount=GetDlgItemInt(IDC_EDIT1,&root,false);

	
						
    CString sql=_T("");
    sql.Format(_T("UPDATE network SET  my_date='%s',my_city='%s',my_product='%s',my_operator='%s',my_type='%s', my_amount=%lf WHERE my_product='%s' and my_city='%s' and my_date='%s' "),\
                      szDate,alter_city,alter_product,alter_operator,alter_type,alter_amount,product,city,date);
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);

	MessageBox("修改成功");

	OnOK();
	
}
