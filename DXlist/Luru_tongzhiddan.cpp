// Luru_tongzhiddan.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "Luru_tongzhiddan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Luru_tongzhiddan dialog


Luru_tongzhiddan::Luru_tongzhiddan(CWnd* pParent /*=NULL*/)
	: CDialog(Luru_tongzhiddan::IDD, pParent)
{
	//{{AFX_DATA_INIT(Luru_tongzhiddan)
	//}}AFX_DATA_INIT
}


void Luru_tongzhiddan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Luru_tongzhiddan)
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
	DDX_Control(pDX, IDC_COMBO4, m_TZD_check);
	DDX_Control(pDX, IDC_COMBO3, m_TZD_notice);
	DDX_Control(pDX, IDC_COMBO2, m_TZD_product);
	DDX_Control(pDX, IDC_COMBO1, m_TZD_city);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_end_date);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_start_date);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Luru_tongzhiddan, CDialog)
	//{{AFX_MSG_MAP(Luru_tongzhiddan)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_BN_CLICKED(IDC_BUTTON1, OnADD)
	ON_BN_CLICKED(IDC_BUTTON2, OnSelect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Luru_tongzhiddan message handlers

BOOL Luru_tongzhiddan::OnInitDialog() 
{
	CDialog::OnInitDialog();
	

    m_TZD_city.AddString("江西本部");
	m_TZD_city.AddString("江西景德镇");
	m_TZD_city.AddString("江西南昌");
	m_TZD_city.AddString("江西吉安");
	m_TZD_city.AddString("江西赣州");
	m_TZD_city.AddString("江西新余");
    m_TZD_city.AddString("江西鹰潭");
	m_TZD_city.AddString("江西九江");	
	m_TZD_city.AddString("江西宜春");		
	m_TZD_city.AddString("江西上饶");			
	m_TZD_city.AddString("江西萍乡");		
	m_TZD_city.AddString("江西抚州");
	m_TZD_city.InsertString(0,"全部");
    m_TZD_city.SetCurSel(0);
	
	
	m_TZD_product.AddString("固话-增值业务-800-国内");
	m_TZD_product.AddString("卡类-IP卡-省内IP电话卡-200卡");
	m_TZD_product.AddString("卡类-IP卡-省内IP电话卡-300卡");
	m_TZD_product.AddString("固话-基础业务-普通电话");
	m_TZD_product.AddString("固话-基础业务-公用电话-公话超市电话");
	m_TZD_product.AddString("数据业务-互联网接入服务-宽带接入-ADSL虚拟拨号");
	m_TZD_product.AddString("数据业务-互联网接入服务-互联网普通专线接入");
	m_TZD_product.AddString("数据业务-平台业务-IDC-主机托管");
   	m_TZD_product.InsertString(0,"全部");
	m_TZD_product.SetCurSel(0);
	
		
	m_TZD_notice.AddString("主业-公众-装移机工料费-普通电话");
	m_TZD_notice.AddString("主业-公众-开户费-普通电话");
	m_TZD_notice.AddString("主业-公众-一次性费用-普通电话");
	m_TZD_notice.AddString("预收账款-用户预存款-普通电话");
	m_TZD_notice.AddString("主业-公众-一次性费用-公用电话-公话超市电话");
	m_TZD_notice.AddString("预收账款-用户预存款-公用电话-公话超市电话");
	m_TZD_notice.AddString("主业-公众-开户费-公用电话-公话超市电话");
	m_TZD_notice.AddString("主业-公众-装移机工料费-公用电话-公话超市电话");
	m_TZD_notice.AddString("主业-公众-装移机工料费-IDC-主机托管");
	m_TZD_notice.AddString("主业-公众-开户费-IDC-主机托管");
	m_TZD_notice.AddString("主业-公众-一次性费用-IDC-主机托管");
	m_TZD_notice.AddString("主业-公众-装移机工料费-宽带-ADSL虚拟拨号");
	m_TZD_notice.AddString("主业-公众-一次性费用-宽带-ADSL虚拟拨号");
	m_TZD_notice.AddString("主业-公众-开户费-宽带-ADSL虚拟拨号");
	m_TZD_notice.AddString("主业-公众-装移机工料费-宽带-ADSL虚拟拨号");
	m_TZD_notice.AddString("预收账款-预付费卡款-面值-200卡");
	m_TZD_notice.AddString("预收账款-预付费卡款-销售折扣-200卡");
	m_TZD_notice.AddString("预收账款-预付费卡款-面值-300卡");
	m_TZD_notice.AddString("预收账款-预付费卡款-销售折扣-300卡");
	m_TZD_notice.InsertString(0,"全部");
    m_TZD_notice.SetCurSel(0);


	m_TZD_check.AddString("未稽核");
	m_TZD_check.AddString("稽核成功");
	m_TZD_check.AddString("稽核失败");
	m_TZD_check.InsertString(0,"全部");
    m_TZD_check.SetCurSel(0);

	
	
    m_listctrl.SetBkColor(RGB(160,180,220)); 
    m_listctrl.SetTextBkColor(RGB(160,180,220));
	m_listctrl.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES); 
    m_listctrl.InsertColumn(1, "收款日期", LVCFMT_CENTER, 80,0);
    m_listctrl.InsertColumn(2, "城市名称", LVCFMT_CENTER, 100,1);
	m_listctrl.InsertColumn(3, "产品名称", LVCFMT_CENTER, 380);
    m_listctrl.InsertColumn(4, "通知单类型", LVCFMT_CENTER,350);
    m_listctrl.InsertColumn(5, "通知单金额", LVCFMT_CENTER, 80);
    m_listctrl.InsertColumn(6, "录入人员", LVCFMT_CENTER, 80);
    m_listctrl.InsertColumn(7, "稽核状态", LVCFMT_CENTER, 80);

	
	try
	{
		
		m_AdoConn.OnInitADOConn();
		sql="select * from notice";//sql语句
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
	
	COleDateTime oletimeTime(2000, 10, 10, 0, 0, 0);
	m_start_date.SetFormat("yyyy-MM-dd");
	VERIFY(m_start_date.SetTime(oletimeTime));
	
	m_end_date.SetFormat("yyyy-MM-dd");
	m_end_date.SetTime(&tem_ST);
	
	UpdateData(TRUE);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Luru_tongzhiddan::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CString send_date,send_city,send_product,send_notice;
	
    POSITION pos = m_listctrl.GetFirstSelectedItemPosition();//得到位置
	int i = m_listctrl.GetNextSelectedItem(pos);//得到此时的行数
    send_date = m_listctrl.GetItemText(i,0);//第i行0列
    send_city = m_listctrl.GetItemText(i,1);//第i行1列
    send_product = m_listctrl.GetItemText(i,2);
    send_notice = m_listctrl.GetItemText(i,3);
	int send_value = atoi(m_listctrl.GetItemText(i,4));

	CString check;
	check=m_listctrl.GetItemText(i,6);
  
	if(check!="稽核通过")
	{


	LuRu_tzd_Delet dlt;
	dlt.date=send_date;
	dlt.city=send_city;
	dlt.product=send_product;
	dlt.notice=send_notice;
	dlt.value=send_value;
	dlt.DoModal();
	Refresh();
         }
	else MessageBox("对不起，此数据已稽核通过不能修改！");
	*pResult = 0;
}

void Luru_tongzhiddan::Refresh()
{
	m_listctrl.DeleteAllItems();

   try
	{
		
		m_AdoConn.OnInitADOConn();
	//	CString sql="select * from card_sale";//sql语句
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
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_notice") );
			m_listctrl.SetItemText(i,3,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_income") );
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


void Luru_tongzhiddan::OnADD() 
{
	// TODO: Add your control notification handler code here
		LuRu_tzd_Add a_d;
	a_d.DoModal();
    Refresh();
}

void Luru_tongzhiddan::OnSelect() 
{
	// TODO: Add your control notification handler code here
	CString select_city,select_product,select_notice,check;
   	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(select_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(select_product);
   	((CComboBox*)GetDlgItem(IDC_COMBO3))->GetWindowText(select_notice);
	((CComboBox*)GetDlgItem(IDC_COMBO4))->GetWindowText(check);
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
	int select_check;
	if(check.CompareNoCase("未稽核") == 0 )
	{
		select_check=0;//未稽核标记为0
	}else if (check.CompareNoCase("稽核成功")==0)
	{
		select_check=1;//集合成功标记为1
	}else select_check=2;//集合失败标记为2
	
	m_listctrl.DeleteAllItems();

	CString select2_check;
	select2_check.Format("%d",select_check);
	try
	{
		
		m_AdoConn.OnInitADOConn();
		sql="select * from notice where my_date between '"+start_Date+"' and '"+end_Date+"' ";//sql语句
		 
		if(select_city.CompareNoCase("全部")!=0)
		{sql=sql+" AND my_city='"+select_city+"' ";}
		if(select_product.CompareNoCase("全部")!=0)
		{sql=sql+"  AND my_product='"+select_product+"' ";};
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
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_notice") );
			m_listctrl.SetItemText(i,3,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_income") );
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
