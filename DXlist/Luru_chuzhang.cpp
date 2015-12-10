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
	//	CString sql="select * from income_account";//sql���
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
			
			str=(char*)(_bstr_t)m_pRs->GetCollect("my_type");
			m_listctrl.SetItemText(i,3,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_price") );
			m_listctrl.SetItemText(i,4,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_user") );
			m_listctrl.SetItemText(i,5,str);
			
			int check=atoi( (char*)(_bstr_t)m_pRs->GetCollect("my_check_state") );
			if(check==0)
			{
				m_listctrl.SetItemText(i,6,"δ����");
			}
			else if(check==1)
			{
				m_listctrl.SetItemText(i,6,"����ͨ��");
			}else
			{
                m_listctrl.SetItemText(i,6,"����ʧ��");
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
	
	
	m_CZ_city.AddString("��������");
	m_CZ_city.AddString("����������");
	m_CZ_city.AddString("�����ϲ�");
	m_CZ_city.AddString("��������");
	m_CZ_city.AddString("��������");
	m_CZ_city.AddString("��������");
    m_CZ_city.AddString("����ӥ̶");
	m_CZ_city.AddString("�����Ž�");	
	m_CZ_city.AddString("�����˴�");		
	m_CZ_city.AddString("��������");			
	m_CZ_city.AddString("����Ƽ��");		
	m_CZ_city.AddString("��������");
	m_CZ_city.InsertString(0,"ȫ��");
    m_CZ_city.SetCurSel(0);
	
	
	m_CZ_name.AddString("�̻�-��ֵҵ��-800-����");
	m_CZ_name.AddString("����-IP��-ʡ��IP�绰��-200��");
	m_CZ_name.AddString("����-IP��-ʡ��IP�绰��-300��");
	m_CZ_name.AddString("�̻�-����ҵ��-��ͨ�绰");
	m_CZ_name.AddString("�̻�-����ҵ��-���õ绰-�������е绰");
	m_CZ_name.AddString("����ҵ��-�������������-�������-ADSL���Ⲧ��");
	m_CZ_name.AddString("����ҵ��-�������������-��������ͨר�߽���");
	m_CZ_name.AddString("����ҵ��-ƽ̨ҵ��-IDC-�����й�");
   	m_CZ_name.InsertString(0,"ȫ��");
	m_CZ_name.SetCurSel(0);
	
	
	
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-���������");
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-��������ͨ����");
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-���ز�������ͨ�ŷ�");
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-��������ͨ����");
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-���ڳ�;ͨ�ŷ�");
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-���ʳ�;ͨ�ŷ�");
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-�۰�̨��;ͨ�ŷ�");
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-IP���ڳ�;ͨ�ŷ�");
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-IP���ʳ�;ͨ�ŷ�");
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-IP�۰�̨��;ͨ�ŷ�");
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-װ�ƻ����Ϸ�����");
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-����������");
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-����ʹ�÷�");
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-һ���Է���");
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-��׼�ʷ�����");
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-��ֵҵ������");
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-����������");
	m_CZ_type.AddString("��Ӫҵ������-���ڿͻ�-�ۿ�������");
   	m_CZ_type.InsertString(0,"ȫ��");
	m_CZ_type.SetCurSel(0);
	
	
	m_CZ_check.AddString("δ����");
	m_CZ_check.AddString("���˳ɹ�");
	m_CZ_check.AddString("����ʧ��");
	m_CZ_check.InsertString(0,"ȫ��");
    m_CZ_check.SetCurSel(0);
	
    m_listctrl.SetBkColor(RGB(160,180,220)); 
    m_listctrl.SetTextBkColor(RGB(160,180,220));
	m_listctrl.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES); 
    m_listctrl.InsertColumn(1, "�����·�", LVCFMT_CENTER, 80,0);
    m_listctrl.InsertColumn(2, "����", LVCFMT_CENTER, 90,1);
	m_listctrl.InsertColumn(3, "��Ʒ����", LVCFMT_CENTER, 380);
    m_listctrl.InsertColumn(4, "������������", LVCFMT_CENTER, 340);
	m_listctrl.InsertColumn(5, "���˽��", LVCFMT_CENTER, 80);
    m_listctrl.InsertColumn(6, "¼����Ա", LVCFMT_CENTER, 80);
    m_listctrl.InsertColumn(7, "����״̬", LVCFMT_CENTER, 80);
	

	try
	{
		
		m_AdoConn.OnInitADOConn();
		sql="select * from income_account";//sql���
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
			
			str=(char*)(_bstr_t)m_pRs->GetCollect("my_type");
			m_listctrl.SetItemText(i,3,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_price") );
			m_listctrl.SetItemText(i,4,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_user") );
			m_listctrl.SetItemText(i,5,str);
			
			int check=atoi( (char*)(_bstr_t)m_pRs->GetCollect("my_check_state") );
			if(check==0)
			{
				m_listctrl.SetItemText(i,6,"δ����");
			}
			else if(check==1)
			{
				m_listctrl.SetItemText(i,6,"����ͨ��");
			}else
			{
                m_listctrl.SetItemText(i,6,"����ʧ��");
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
	
	
    POSITION pos = m_listctrl.GetFirstSelectedItemPosition();//�õ�λ��
	int i = m_listctrl.GetNextSelectedItem(pos);//�õ���ʱ������
    send_date = m_listctrl.GetItemText(i,0);//��i��0��
    send_city = m_listctrl.GetItemText(i,1);//��i��1��
    send_product = m_listctrl.GetItemText(i,2);
    send_type = m_listctrl.GetItemText(i,3);
	int send_money = atoi(m_listctrl.GetItemText(i,4));


	CString check;
	check=m_listctrl.GetItemText(i,6);

    if(check!="����ͨ��")
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
	else MessageBox("�Բ��𣬴������ѻ���ͨ�������޸ģ�");
	
	
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
	if(check.CompareNoCase("δ����") == 0 )
	{
		select_check=0;//δ���˱��Ϊ0
	}else if (check.CompareNoCase("���˳ɹ�")==0)
	{
		select_check=1;//���ϳɹ����Ϊ1
	}else select_check=2;//����ʧ�ܱ��Ϊ2
	
	m_listctrl.DeleteAllItems();

	CString select2_price,select2_check;
	select2_check.Format("%d",select_check);
	try
	{
		
		m_AdoConn.OnInitADOConn();
		sql="select * from income_account where my_date between '"+start_Date+"' and '"+end_Date+"' ";//sql���
		 
		if(select_city.CompareNoCase("ȫ��")!=0)
		{sql=sql+" AND my_city='"+select_city+"' ";}
		if(select_product.CompareNoCase("ȫ��")!=0)
		{sql=sql+"  AND my_product='"+select_product+"' ";};
		if(select_type.CompareNoCase("ȫ��")!=0)
		{sql=sql+" AND my_type='"+select_type+"' ";};
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
			
			str=(char*)(_bstr_t)m_pRs->GetCollect("my_type");
			m_listctrl.SetItemText(i,3,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_price") );
			m_listctrl.SetItemText(i,4,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_user") );
			m_listctrl.SetItemText(i,5,str);
			
			int check=atoi( (char*)(_bstr_t)m_pRs->GetCollect("my_check_state") );
			if(check==0)
			{
				m_listctrl.SetItemText(i,6,"δ����");
			}
			else if(check==1)
			{
				m_listctrl.SetItemText(i,6,"����ͨ��");
			}else
			{
                m_listctrl.SetItemText(i,6,"����ʧ��");
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



