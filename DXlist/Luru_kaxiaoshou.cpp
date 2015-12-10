// Luru_kaxiaoshou.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "Luru_kaxiaoshou.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Luru_kaxiaoshou dialog


Luru_kaxiaoshou::Luru_kaxiaoshou(CWnd* pParent /*=NULL*/)
	: CDialog(Luru_kaxiaoshou::IDD, pParent)
{
	//{{AFX_DATA_INIT(Luru_kaxiaoshou)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Luru_kaxiaoshou::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Luru_kaxiaoshou)
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_end_date);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_start_date);
	DDX_Control(pDX, IDC_COMBO4, m_KXS_check);
	DDX_Control(pDX, IDC_COMBO2, m_KXS_product);
	DDX_Control(pDX, IDC_COMBO1, m_KXS_city);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Luru_kaxiaoshou, CDialog)
	//{{AFX_MSG_MAP(Luru_kaxiaoshou)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton_Add)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton_Select)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Luru_kaxiaoshou message handlers

BOOL Luru_kaxiaoshou::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
		
	m_KXS_city.AddString("��������");
	m_KXS_city.AddString("����������");
	m_KXS_city.AddString("�����ϲ�");
	m_KXS_city.AddString("��������");
	m_KXS_city.AddString("��������");
	m_KXS_city.AddString("��������");
    m_KXS_city.AddString("����ӥ̶");
	m_KXS_city.AddString("�����Ž�");	
	m_KXS_city.AddString("�����˴�");		
	m_KXS_city.AddString("��������");			
	m_KXS_city.AddString("����Ƽ��");		
	m_KXS_city.AddString("��������");
	m_KXS_city.InsertString(0,"ȫ��");
    m_KXS_city.SetCurSel(0);
	
	
	m_KXS_product.AddString("�̻�-��ֵҵ��-800-����");
	m_KXS_product.AddString("����-IP��-ʡ��IP�绰��-200��");
	m_KXS_product.AddString("����-IP��-ʡ��IP�绰��-300��");
	m_KXS_product.AddString("�̻�-����ҵ��-��ͨ�绰");
	m_KXS_product.AddString("�̻�-����ҵ��-���õ绰-�������е绰");
	m_KXS_product.AddString("����ҵ��-�������������-�������-ADSL���Ⲧ��");
	m_KXS_product.AddString("����ҵ��-�������������-��������ͨר�߽���");
	m_KXS_product.AddString("����ҵ��-ƽ̨ҵ��-IDC-�����й�");
   	m_KXS_product.InsertString(0,"ȫ��");
	m_KXS_product.SetCurSel(0);
	
		
	
	
	m_KXS_check.AddString("δ����");
	m_KXS_check.AddString("���˳ɹ�");
	m_KXS_check.AddString("����ʧ��");
	m_KXS_check.InsertString(0,"ȫ��");
    m_KXS_check.SetCurSel(0);
	
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
		sql="select * from card_sale";//sql���
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
			
			int check=atoi( (char*)(_bstr_t)m_pRs->GetCollect("my_check_state") );
			if(check==0)
			{
				m_listctrl.SetItemText(i,8,"δ����");
			}
			else if(check==1)
			{
				m_listctrl.SetItemText(i,8,"����ͨ��");
			}else
			{
                m_listctrl.SetItemText(i,8,"����ʧ��");
			}
			
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
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Luru_kaxiaoshou::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CString send_date,send_city,send_product;
	
	
    POSITION pos = m_listctrl.GetFirstSelectedItemPosition();//�õ�λ��
	int i = m_listctrl.GetNextSelectedItem(pos);//�õ���ʱ������
    send_date = m_listctrl.GetItemText(i,0);//��i��0��
    send_city = m_listctrl.GetItemText(i,1);//��i��1��
    send_product = m_listctrl.GetItemText(i,2);
    int send_card_value = atoi(m_listctrl.GetItemText(i,3));
	int send_card_no = atoi(m_listctrl.GetItemText(i,4));
	int send_card_amount = atoi(m_listctrl.GetItemText(i,5));
	int send_card_discount_amount = atoi(m_listctrl.GetItemText(i,6));

	CString check;
	check=m_listctrl.GetItemText(i,8);
  
	if(check!="����ͨ��")
	{


	LuRu_kxs_delet dlt;
	dlt.date=send_date;
	dlt.city=send_city;
	dlt.product=send_product;
	dlt.card_value=send_card_value;
	dlt.card_no=send_card_no;
	dlt.card_amount=send_card_amount;
	dlt.card_discount_amount=send_card_discount_amount;
	
	dlt.DoModal();
	
	Refresh();
         }
	else MessageBox("�Բ��𣬴������ѻ���ͨ�������޸ģ�");

	*pResult = 0;
}

void Luru_kaxiaoshou::Refresh()
{
	m_listctrl.DeleteAllItems();

try
	{
		m_AdoConn.OnInitADOConn();
	//	CString sql="select * from card_sale";//sql���
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);//ִ��sql���
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
			
			int check=atoi( (char*)(_bstr_t)m_pRs->GetCollect("my_check_state") );
			if(check==0)
			{
				m_listctrl.SetItemText(i,8,"δ����");
			}
			else if(check==1)
			{
				m_listctrl.SetItemText(i,8,"����ͨ��");
			}else
			{
                m_listctrl.SetItemText(i,8,"����ʧ��");
			}
			
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

void Luru_kaxiaoshou::OnButton_Add() 
{
	// TODO: Add your control notification handler code here
	LuRu_kxs_Add a_d;
	a_d.DoModal();
    Refresh();
}

void Luru_kaxiaoshou::OnButton_Select() 
{
	// TODO: Add your control notification handler code here
	CString select_city,select_product,check;
   	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(select_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(select_product);
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
	if(check.CompareNoCase("δ����") == 0 )
	{
		select_check=0;//δ���˱��Ϊ0
	}else if (check.CompareNoCase("���˳ɹ�")==0)
	{
		select_check=1;//���ϳɹ����Ϊ1
	}else select_check=2;//����ʧ�ܱ��Ϊ2
	
	m_listctrl.DeleteAllItems();

	CString select2_check;
	select2_check.Format("%d",select_check);
	try
	{
		
		m_AdoConn.OnInitADOConn();
		sql="select * from card_sale where my_date between '"+start_Date+"' and '"+end_Date+"' ";//sql���
		 
		if(select_city.CompareNoCase("ȫ��")!=0)
		{sql=sql+" AND my_city='"+select_city+"' ";}
		if(select_product.CompareNoCase("ȫ��")!=0)
		{sql=sql+"  AND my_product='"+select_product+"' ";};
	     if(check.CompareNoCase("ȫ��")!=0)
		 {sql=sql+" AND my_check_state="+select2_check+" ";}

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
			
			int check=atoi( (char*)(_bstr_t)m_pRs->GetCollect("my_check_state") );
			if(check==0)
			{
				m_listctrl.SetItemText(i,8,"δ����");
			}
			else if(check==1)
			{
				m_listctrl.SetItemText(i,8,"����ͨ��");
			}else
			{
                m_listctrl.SetItemText(i,8,"����ʧ��");
			}
			
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
