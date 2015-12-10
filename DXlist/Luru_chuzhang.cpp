// Luru_chuzhang.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "Luru_chuzhang.h"
#include "Add_Delet.h"
#include "Delete.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// Luru_chuzhang dialog


Luru_chuzhang::Luru_chuzhang(CWnd* pParent /*=NULL*/)
: CDialog(Luru_chuzhang::IDD, pParent)
{
	
	//{{AFX_DATA_INIT(Luru_chuzhang)
	//}}AFX_DATA_INIT
	
	
}


void Luru_chuzhang::Luru_Refresh()
{
	
	m_listctrl.DeleteAllItems();
	
	try
	{
		
		m_AdoConn.OnInitADOConn();
	//	CString sql="select * from income_account";//sql语句
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);//执行sql语句
		int i=0;
		
	//	m_pRs->MoveFirst();
		
		while(m_pRs->adoEOF==0)
		{
			CString str=(char*)(_bstr_t)m_pRs->GetCollect("my_date");
			m_listctrl.InsertItem(i,"");
			m_listctrl.SetItemText(i,0,str);
			
			str=(char*)(_bstr_t)m_pRs->GetCollect("my_city");
			m_listctrl.SetItemText(i,1,str);
			
			str=(char*)(_bstr_t)m_pRs->GetCollect("my_product");
			m_listctrl.SetItemText(i,2,str);
			
			str=(char*)(_bstr_t)m_pRs->GetCollect("my_type");
			m_listctrl.SetItemText(i,3,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_price") );
			m_listctrl.SetItemText(i,4,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_user") );
			m_listctrl.SetItemText(i,5,str);
			
			int check=atoi( (char*)(_bstr_t)m_pRs->GetCollect("my_check_state") );
			if(check==0)
			{
				m_listctrl.SetItemText(i,6,"未稽核");
			}
			else if(check==1)
			{
				m_listctrl.SetItemText(i,6,"稽核通过");
			}else
			{
                m_listctrl.SetItemText(i,6,"稽核失败");
			}
			
			m_pRs->MoveNext();
			i++;
		}
		
	}
	catch (_com_error& e)
	{
		CString strMsg;
		strMsg.Format(_T("错误描述：%s\n错误消息%s"), 
			(LPCTSTR)e.Description(),
			(LPCTSTR)e.ErrorMessage());
		AfxMessageBox(strMsg);
	}
	
	
	
	
}

void Luru_chuzhang::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Luru_chuzhang)
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_end_date);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_start_date);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
	DDX_Control(pDX, IDC_COMBO4, m_CZ_check);
	DDX_Control(pDX, IDC_COMBO3, m_CZ_type);
	DDX_Control(pDX, IDC_COMBO2, m_CZ_name);
	DDX_Control(pDX, IDC_COMBO1, m_CZ_city);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Luru_chuzhang, CDialog)
//{{AFX_MSG_MAP(Luru_chuzhang)
ON_CBN_DROPDOWN(IDC_COMBO1, OnDropdownCombo1)
ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
ON_CBN_DROPDOWN(IDC_COMBO2, OnDropdownCombo2)
ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
ON_CBN_DROPDOWN(IDC_COMBO3, OnDropdownCombo3)
ON_CBN_SELCHANGE(IDC_COMBO3, OnSelchangeCombo3)
ON_CBN_DROPDOWN(IDC_COMBO4, OnDropdownCombo4)
ON_CBN_SELCHANGE(IDC_COMBO4, OnSelchangeCombo4)
ON_BN_CLICKED(IDC_BUTTON1, OnButton1Add)
ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
ON_BN_CLICKED(IDC_BUTTON2, OnSelect)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Luru_chuzhang message handlers



void Luru_chuzhang::OnDropdownCombo1() 
{
	
	
	// TODO: Add your control notification handler code here
	
	
	
	
	
}

void Luru_chuzhang::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	No=m_CZ_city.GetCurSel();
	if(No>=0)
	{ m_CZ_city.GetLBText(No,city);
	No=-1;}
	
}

void Luru_chuzhang::OnDropdownCombo2() 
{
	// TODO: Add your control notification handler code here
	
	
}

void Luru_chuzhang::OnSelchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	No=m_CZ_name.GetCurSel();
	if(No>=0)
	{ m_CZ_name.GetLBText(No,name);
	No=-1;}
}

void Luru_chuzhang::OnDropdownCombo3() 
{
	// TODO: Add your control notification handler code here
	
	
	
}

void Luru_chuzhang::OnSelchangeCombo3() 
{
	// TODO: Add your control notification handler code here
	No=m_CZ_type.GetCurSel();
	if(No>=0)
	{ m_CZ_type.GetLBText(No,type);
	No=-1;}
}

void Luru_chuzhang::OnDropdownCombo4() 
{
	// TODO: Add your control notification handler code here
	
}

void Luru_chuzhang::OnSelchangeCombo4() 
{
	// TODO: Add your control notification handler code here
	   No=m_CZ_check.GetCurSel();
	   if(No>=0)
	   { m_CZ_check.GetLBText(No,check);
	   No=-1;}
}

void Luru_chuzhang::OnButton1Add() 
{
	// TODO: Add your control notification handler code here
	Add_Delet a_d;
	a_d.DoModal();
    Luru_Refresh();
}

BOOL Luru_chuzhang::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	
	m_CZ_city.AddString("江西本部");
	m_CZ_city.AddString("江西景德镇");
	m_CZ_city.AddString("江西南昌");
	m_CZ_city.AddString("江西吉安");
	m_CZ_city.AddString("江西赣州");
	m_CZ_city.AddString("江西新余");
    m_CZ_city.AddString("江西鹰潭");
	m_CZ_city.AddString("江西九江");	
	m_CZ_city.AddString("江西宜春");		
	m_CZ_city.AddString("江西上饶");			
	m_CZ_city.AddString("江西萍乡");		
	m_CZ_city.AddString("江西抚州");
	m_CZ_city.InsertString(0,"全部");
    m_CZ_city.SetCurSel(0);
	
	
	m_CZ_name.AddString("固话-增值业务-800-国内");
	m_CZ_name.AddString("卡类-IP卡-省内IP电话卡-200卡");
	m_CZ_name.AddString("卡类-IP卡-省内IP电话卡-300卡");
	m_CZ_name.AddString("固话-基础业务-普通电话");
	m_CZ_name.AddString("固话-基础业务-公用电话-公话超市电话");
	m_CZ_name.AddString("数据业务-互联网接入服务-宽带接入-ADSL虚拟拨号");
	m_CZ_name.AddString("数据业务-互联网接入服务-互联网普通专线接入");
	m_CZ_name.AddString("数据业务-平台业务-IDC-主机托管");
   	m_CZ_name.InsertString(0,"全部");
	m_CZ_name.SetCurSel(0);
	
	
	
	m_CZ_type.AddString("主营业务收入-公众客户-月租费收入");
	m_CZ_type.AddString("主营业务收入-公众客户-本地区间通话费");
	m_CZ_type.AddString("主营业务收入-公众客户-本地拨号上网通信费");
	m_CZ_type.AddString("主营业务收入-公众客户-本地区内通话费");
	m_CZ_type.AddString("主营业务收入-公众客户-国内长途通信费");
	m_CZ_type.AddString("主营业务收入-公众客户-国际长途通信费");
	m_CZ_type.AddString("主营业务收入-公众客户-港澳台长途通信费");
	m_CZ_type.AddString("主营业务收入-公众客户-IP国内长途通信费");
	m_CZ_type.AddString("主营业务收入-公众客户-IP国际长途通信费");
	m_CZ_type.AddString("主营业务收入-公众客户-IP港澳台长途通信费");
	m_CZ_type.AddString("主营业务收入-公众客户-装移机工料费收入");
	m_CZ_type.AddString("主营业务收入-公众客户-开户费收入");
	m_CZ_type.AddString("主营业务收入-公众客户-网络使用费");
	m_CZ_type.AddString("主营业务收入-公众客户-一次性费用");
	m_CZ_type.AddString("主营业务收入-公众客户-标准资费收入");
	m_CZ_type.AddString("主营业务收入-公众客户-增值业务收入");
	m_CZ_type.AddString("主营业务收入-公众客户-其他类收入");
	m_CZ_type.AddString("主营业务收入-公众客户-折扣与折让");
   	m_CZ_type.InsertString(0,"全部");
	m_CZ_type.SetCurSel(0);
	
	
	m_CZ_check.AddString("未稽核");
	m_CZ_check.AddString("稽核成功");
	m_CZ_check.AddString("稽核失败");
	m_CZ_check.InsertString(0,"全部");
    m_CZ_check.SetCurSel(0);
	
    m_listctrl.SetBkColor(RGB(160,180,220)); 
    m_listctrl.SetTextBkColor(RGB(160,180,220));
	m_listctrl.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES); 
    m_listctrl.InsertColumn(1, "出账月份", LVCFMT_CENTER, 80,0);
    m_listctrl.InsertColumn(2, "城市", LVCFMT_CENTER, 90,1);
	m_listctrl.InsertColumn(3, "产品名称", LVCFMT_CENTER, 380);
    m_listctrl.InsertColumn(4, "出账收入类型", LVCFMT_CENTER, 340);
	m_listctrl.InsertColumn(5, "出账金额", LVCFMT_CENTER, 80);
    m_listctrl.InsertColumn(6, "录入人员", LVCFMT_CENTER, 80);
    m_listctrl.InsertColumn(7, "稽核状态", LVCFMT_CENTER, 80);
	

	try
	{
		
		m_AdoConn.OnInitADOConn();
		sql="select * from income_account";//sql语句
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);//执行sql语句
		int i=0;
		
		
		while(m_pRs->adoEOF==0)
		{
			CString str=(char*)(_bstr_t)m_pRs->GetCollect("my_date");
			m_listctrl.InsertItem(i,"");
			m_listctrl.SetItemText(i,0,str);
			
			str=(char*)(_bstr_t)m_pRs->GetCollect("my_city");
			m_listctrl.SetItemText(i,1,str);
			
			str=(char*)(_bstr_t)m_pRs->GetCollect("my_product");
			m_listctrl.SetItemText(i,2,str);
			
			str=(char*)(_bstr_t)m_pRs->GetCollect("my_type");
			m_listctrl.SetItemText(i,3,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_price") );
			m_listctrl.SetItemText(i,4,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_user") );
			m_listctrl.SetItemText(i,5,str);
			
			int check=atoi( (char*)(_bstr_t)m_pRs->GetCollect("my_check_state") );
			if(check==0)
			{
				m_listctrl.SetItemText(i,6,"未稽核");
			}
			else if(check==1)
			{
				m_listctrl.SetItemText(i,6,"稽核通过");
			}else
			{
                m_listctrl.SetItemText(i,6,"稽核失败");
			}
			
			m_pRs->MoveNext();
			i++;
		}

		
		
	}
	catch (_com_error& e)
	{
		CString strMsg;
		strMsg.Format(_T("错误描述：%s\n错误消息%s"), 
			(LPCTSTR)e.Description(),
			(LPCTSTR)e.ErrorMessage());
		AfxMessageBox(strMsg);
	}
	

	

	SYSTEMTIME tem_ST ; 
	
	GetLocalTime(&tem_ST);

    //COleDateTime time(1999, 3, 19, 22, 15, 0);

	COleDateTime oletimeTime(2000, 10, 10, 0, 0, 0);
	m_start_date.SetFormat("yyyy-MM");
	VERIFY(m_start_date.SetTime(oletimeTime));
	
	m_end_date.SetFormat("yyyy-MM");
	m_end_date.SetTime(&tem_ST);
	
	UpdateData(TRUE);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void Luru_chuzhang::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	
    CString send_date,send_city,send_product,send_type;
	
	
    POSITION pos = m_listctrl.GetFirstSelectedItemPosition();//得到位置
	int i = m_listctrl.GetNextSelectedItem(pos);//得到此时的行数
    send_date = m_listctrl.GetItemText(i,0);//第i行0列
    send_city = m_listctrl.GetItemText(i,1);//第i行1列
    send_product = m_listctrl.GetItemText(i,2);
    send_type = m_listctrl.GetItemText(i,3);
	int send_money = atoi(m_listctrl.GetItemText(i,4));


	CString check;
	check=m_listctrl.GetItemText(i,6);

    if(check!="稽核通过")
	{
	Delete dlt;
	dlt.date=send_date;
	dlt.city=send_city;
	dlt.product=send_product;
	dlt.type=send_type;
	dlt.money=send_money;
	
	dlt.DoModal();
	
	Luru_Refresh();
	}
	else MessageBox("对不起，此数据已稽核通过不能修改！");
	
	
	*pResult = 0;
}

void Luru_chuzhang::OnSelect() 
{
	// TODO: Add your control notification handler code here
	CString select_city,select_product,select_type,check;
   	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(select_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(select_product);
	((CComboBox*)GetDlgItem(IDC_COMBO3))->GetWindowText(select_type);
	((CComboBox*)GetDlgItem(IDC_COMBO4))->GetWindowText(check);
    CTime time;
	CString start_Date;
	CDateTimeCtrl* pCtrl =&this->m_start_date;
	DWORD dwResult =pCtrl->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		start_Date = time.Format(TEXT("%Y/%m"));
	}
	CString end_Date;
	pCtrl=&this->m_end_date;
	dwResult=pCtrl->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		end_Date = time.Format(TEXT("%Y/%m"));
	}
	int select_check;
	if(check.CompareNoCase("未稽核") == 0 )
	{
		select_check=0;//未稽核标记为0
	}else if (check.CompareNoCase("稽核成功")==0)
	{
		select_check=1;//集合成功标记为1
	}else select_check=2;//集合失败标记为2
	
	m_listctrl.DeleteAllItems();

	CString select2_price,select2_check;
	select2_check.Format("%d",select_check);
	try
	{
		
		m_AdoConn.OnInitADOConn();
		sql="select * from income_account where my_date between '"+start_Date+"' and '"+end_Date+"' ";//sql语句
		 
		if(select_city.CompareNoCase("全部")!=0)
		{sql=sql+" AND my_city='"+select_city+"' ";}
		if(select_product.CompareNoCase("全部")!=0)
		{sql=sql+"  AND my_product='"+select_product+"' ";};
		if(select_type.CompareNoCase("全部")!=0)
		{sql=sql+" AND my_type='"+select_type+"' ";};
	     if(check.CompareNoCase("全部")!=0)
		 {sql=sql+" AND my_check_state="+select2_check+" ";}

		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);//执行sql语句
		int i=0;
		
		
		while(m_pRs->adoEOF==0)
		{
			CString str=(char*)(_bstr_t)m_pRs->GetCollect("my_date");
			m_listctrl.InsertItem(i,"");
			m_listctrl.SetItemText(i,0,str);
			
			str=(char*)(_bstr_t)m_pRs->GetCollect("my_city");
			m_listctrl.SetItemText(i,1,str);
			
			str=(char*)(_bstr_t)m_pRs->GetCollect("my_product");
			m_listctrl.SetItemText(i,2,str);
			
			str=(char*)(_bstr_t)m_pRs->GetCollect("my_type");
			m_listctrl.SetItemText(i,3,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_price") );
			m_listctrl.SetItemText(i,4,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_user") );
			m_listctrl.SetItemText(i,5,str);
			
			int check=atoi( (char*)(_bstr_t)m_pRs->GetCollect("my_check_state") );
			if(check==0)
			{
				m_listctrl.SetItemText(i,6,"未稽核");
			}
			else if(check==1)
			{
				m_listctrl.SetItemText(i,6,"稽核通过");
			}else
			{
                m_listctrl.SetItemText(i,6,"稽核失败");
			}
			m_pRs->MoveNext();
			i++;
		}
		
	}
	catch (_com_error& e)
	{
		CString strMsg;
		strMsg.Format(_T("错误描述：%s\n错误消息%s"), 
			(LPCTSTR)e.Description(),
			(LPCTSTR)e.ErrorMessage());
		AfxMessageBox(strMsg);
	}

}



