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
	
	m_GJ_city.AddString("��������");
	m_GJ_city.AddString("����������");
	m_GJ_city.AddString("�����ϲ�");
	m_GJ_city.AddString("��������");
	m_GJ_city.AddString("��������");
	m_GJ_city.AddString("��������");
    m_GJ_city.AddString("����ӥ̶");
	m_GJ_city.AddString("�����Ž�");	
	m_GJ_city.AddString("�����˴�");		
	m_GJ_city.AddString("��������");			
	m_GJ_city.AddString("����Ƽ��");		
	m_GJ_city.AddString("��������");
	m_GJ_city.InsertString(0,"ȫ��");
    m_GJ_city.SetCurSel(0);
	
	
	m_GJ_product.AddString("�̻�-��ֵҵ��-800-����");
	m_GJ_product.AddString("����-IP��-ʡ��IP�绰��-200��");
	m_GJ_product.AddString("����-IP��-ʡ��IP�绰��-300��");
	m_GJ_product.AddString("�̻�-����ҵ��-��ͨ�绰");
	m_GJ_product.AddString("�̻�-����ҵ��-���õ绰-�������е绰");
	m_GJ_product.AddString("����ҵ��-�������������-�������-ADSL���Ⲧ��");
	m_GJ_product.AddString("����ҵ��-�������������-��������ͨר�߽���");
	m_GJ_product.AddString("����ҵ��-ƽ̨ҵ��-IDC-�����й�");
   	m_GJ_product.InsertString(0,"ȫ��");
	m_GJ_product.SetCurSel(0);
	
		
	

	
    m_listctrl.SetBkColor(RGB(160,180,220)); 
    m_listctrl.SetTextBkColor(RGB(160,180,220));
	m_listctrl.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES); 
    m_listctrl.InsertColumn(1, "��������", LVCFMT_CENTER, 80,0);
    m_listctrl.InsertColumn(2, "����", LVCFMT_CENTER, 100,1);
	m_listctrl.InsertColumn(3, "��Ʒ����", LVCFMT_CENTER, 380);
    m_listctrl.InsertColumn(4, "��������ֵ", LVCFMT_CENTER,100);
    m_listctrl.InsertColumn(5, "��������", LVCFMT_CENTER, 80);
	m_listctrl.InsertColumn(6, "���ܽ��", LVCFMT_CENTER, 80);
    m_listctrl.InsertColumn(7, "�ۿۺ���", LVCFMT_CENTER, 100);
    m_listctrl.InsertColumn(8, "¼����Ա", LVCFMT_CENTER, 80);
    m_listctrl.InsertColumn(9, "����״̬", LVCFMT_CENTER, 80);

	
	try
	{
		
		m_AdoConn.OnInitADOConn();
		sql="select * from card_sale where my_check_state=1";//sql���
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);//ִ��sql���
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
			
            m_listctrl.SetItemText(i,8,"����ͨ��");
	
			
			m_pRs->MoveNext();
			i++;
		}
		
	}
	catch (_com_error& e)
	{
		CString strMsg;
		strMsg.Format(_T("����������%s\n������Ϣ%s"), 
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
		sql="select * from notice where my_date between '"+start_Date+"' and '"+end_Date+"' AND my_check_state=1 ";//sql���
		 
		if(select_city.CompareNoCase("ȫ��")!=0)
		{sql=sql+" AND my_city='"+select_city+"' ";}
		if(select_product.CompareNoCase("ȫ��")!=0)
		{sql=sql+"  AND my_product='"+select_product+"' ";};

		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);//ִ��sql���
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
			
			m_listctrl.SetItemText(i,6,"����ͨ��");
	
			m_pRs->MoveNext();
			i++;
		}
		
	}
	catch (_com_error& e)
	{
		CString strMsg;
		strMsg.Format(_T("����������%s\n������Ϣ%s"), 
		(LPCTSTR)e.Description(),
		(LPCTSTR)e.ErrorMessage());
		AfxMessageBox(strMsg);
	}
}

void GuiJi_tongzhidan::OnOutPutExcel() 
{
	// TODO: Add your control notification handler code here

	ExportListToExcel(&m_listctrl,"֪ͨ���˵�");
}

void GuiJi_tongzhidan::OnOutPutTXT() 
{
	// TODO: Add your control notification handler code here
	ExportListToTXT(&m_listctrl);
}
