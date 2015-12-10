// GuiJi_tongzhidan.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "GuiJi_tongzhidan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// GuiJi_tongzhidan dialog


GuiJi_tongzhidan::GuiJi_tongzhidan(CWnd* pParent /*=NULL*/)
	: CDialog(GuiJi_tongzhidan::IDD, pParent)
{
	//{{AFX_DATA_INIT(GuiJi_tongzhidan)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void GuiJi_tongzhidan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GuiJi_tongzhidan)
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_end_date);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_start_date);
	DDX_Control(pDX, IDC_COMBO3, m_GJ_type);
	DDX_Control(pDX, IDC_COMBO2, m_GJ_product);
	DDX_Control(pDX, IDC_COMBO1, m_GJ_city);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(GuiJi_tongzhidan, CDialog)
	//{{AFX_MSG_MAP(GuiJi_tongzhidan)
	ON_BN_CLICKED(IDC_BUTTON3, OnSelect)
	ON_BN_CLICKED(IDC_BUTTON4, OnOutPutExcel)
	ON_BN_CLICKED(IDC_BUTTON5, OnOutPutTXT)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// GuiJi_tongzhidan message handlers

BOOL GuiJi_tongzhidan::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_GJ_city.AddString("江西本部");
	m_GJ_city.AddString("江西景德镇");
	m_GJ_city.AddString("江西南昌");
	m_GJ_city.AddString("江西吉安");
	m_GJ_city.AddString("江西赣州");
	m_GJ_city.AddString("江西新余");
    m_GJ_city.AddString("江西鹰潭");
	m_GJ_city.AddString("江西九江");	
	m_GJ_city.AddString("江西宜春");		
	m_GJ_city.AddString("江西上饶");			
	m_GJ_city.AddString("江西萍乡");		
	m_GJ_city.AddString("江西抚州");
	m_GJ_city.InsertString(0,"全部");
    m_GJ_city.SetCurSel(0);
	
	
	m_GJ_product.AddString("固话-增值业务-800-国内");
	m_GJ_product.AddString("卡类-IP卡-省内IP电话卡-200卡");
	m_GJ_product.AddString("卡类-IP卡-省内IP电话卡-300卡");
	m_GJ_product.AddString("固话-基础业务-普通电话");
	m_GJ_product.AddString("固话-基础业务-公用电话-公话超市电话");
	m_GJ_product.AddString("数据业务-互联网接入服务-宽带接入-ADSL虚拟拨号");
	m_GJ_product.AddString("数据业务-互联网接入服务-互联网普通专线接入");
	m_GJ_product.AddString("数据业务-平台业务-IDC-主机托管");
   	m_GJ_product.InsertString(0,"全部");
	m_GJ_product.SetCurSel(0);
	
		
	

	
    m_listctrl.SetBkColor(RGB(160,180,220)); 
    m_listctrl.SetTextBkColor(RGB(160,180,220));
	m_listctrl.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES); 
    m_listctrl.InsertColumn(1, "销售日期", LVCFMT_CENTER, 80,0);
    m_listctrl.InsertColumn(2, "城市", LVCFMT_CENTER, 100,1);
	m_listctrl.InsertColumn(3, "产品名称", LVCFMT_CENTER, 380);
    m_listctrl.InsertColumn(4, "卡单张面值", LVCFMT_CENTER,100);
    m_listctrl.InsertColumn(5, "销售数量", LVCFMT_CENTER, 80);
	m_listctrl.InsertColumn(6, "卡总金额", LVCFMT_CENTER, 80);
    m_listctrl.InsertColumn(7, "折扣后金额", LVCFMT_CENTER, 100);
    m_listctrl.InsertColumn(8, "录入人员", LVCFMT_CENTER, 80);
    m_listctrl.InsertColumn(9, "稽核状态", LVCFMT_CENTER, 80);

	
	try
	{
		
		m_AdoConn.OnInitADOConn();
		sql="select * from card_sale where my_check_state=1";//sql语句
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
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_sale_no") );
			m_listctrl.SetItemText(i,3,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_card_value") );
			m_listctrl.SetItemText(i,4,str);

			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_card_amount") );
			m_listctrl.SetItemText(i,5,str);

			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_discount_amount") );
			m_listctrl.SetItemText(i,6,str);


			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_user") );
			m_listctrl.SetItemText(i,7,str);		
			
            m_listctrl.SetItemText(i,8,"稽核通过");
	
			
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

	COleDateTime oletimeTime(2000, 10, 10, 0, 0, 0);
	m_start_date.SetFormat("yyyy-MM-dd");
	VERIFY(m_start_date.SetTime(oletimeTime));
	
	m_end_date.SetFormat("yyyy-MM-dd");
	m_end_date.SetTime(&tem_ST);
	
	UpdateData(TRUE);
	// TODO: Add extra initialization here
	//TODO: Add extra initialization here


	return TRUE;  
	             
}

void GuiJi_tongzhidan::OnSelect() 
{
	// TODO: Add your control notification handler code here
    CString select_city,select_product,select_notice,check;
   	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(select_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(select_product);
   	((CComboBox*)GetDlgItem(IDC_COMBO3))->GetWindowText(select_notice);
    CTime time;
	CString start_Date;
	CDateTimeCtrl* pCtrl =&this->m_start_date;
	DWORD dwResult =pCtrl->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		start_Date = time.Format(TEXT("%Y/%m/%d"));
	}
	CString end_Date;
	pCtrl=&this->m_end_date;
	dwResult=pCtrl->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		end_Date = time.Format(TEXT("%Y/%m/%d"));
	}
	
	m_listctrl.DeleteAllItems();

	try
	{
		
		m_AdoConn.OnInitADOConn();
		sql="select * from notice where my_date between '"+start_Date+"' and '"+end_Date+"' AND my_check_state=1 ";//sql语句
		 
		if(select_city.CompareNoCase("全部")!=0)
		{sql=sql+" AND my_city='"+select_city+"' ";}
		if(select_product.CompareNoCase("全部")!=0)
		{sql=sql+"  AND my_product='"+select_product+"' ";};

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
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_notice") );
			m_listctrl.SetItemText(i,3,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_income") );
			m_listctrl.SetItemText(i,4,str);


			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_user") );
			m_listctrl.SetItemText(i,5,str);		
			
			m_listctrl.SetItemText(i,6,"稽核通过");
	
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

void GuiJi_tongzhidan::OnOutPutExcel() 
{
	// TODO: Add your control notification handler code here

	ExportListToExcel(&m_listctrl,"通知单账单");
}

void GuiJi_tongzhidan::OnOutPutTXT() 
{
	// TODO: Add your control notification handler code here
	ExportListToTXT(&m_listctrl);
}
