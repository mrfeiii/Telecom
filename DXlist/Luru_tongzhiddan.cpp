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
	

    m_TZD_city.AddString("��������");
	m_TZD_city.AddString("����������");
	m_TZD_city.AddString("�����ϲ�");
	m_TZD_city.AddString("��������");
	m_TZD_city.AddString("��������");
	m_TZD_city.AddString("��������");
    m_TZD_city.AddString("����ӥ̶");
	m_TZD_city.AddString("�����Ž�");	
	m_TZD_city.AddString("�����˴�");		
	m_TZD_city.AddString("��������");			
	m_TZD_city.AddString("����Ƽ��");		
	m_TZD_city.AddString("��������");
	m_TZD_city.InsertString(0,"ȫ��");
    m_TZD_city.SetCurSel(0);
	
	
	m_TZD_product.AddString("�̻�-��ֵҵ��-800-����");
	m_TZD_product.AddString("����-IP��-ʡ��IP�绰��-200��");
	m_TZD_product.AddString("����-IP��-ʡ��IP�绰��-300��");
	m_TZD_product.AddString("�̻�-����ҵ��-��ͨ�绰");
	m_TZD_product.AddString("�̻�-����ҵ��-���õ绰-�������е绰");
	m_TZD_product.AddString("����ҵ��-�������������-�������-ADSL���Ⲧ��");
	m_TZD_product.AddString("����ҵ��-�������������-��������ͨר�߽���");
	m_TZD_product.AddString("����ҵ��-ƽ̨ҵ��-IDC-�����й�");
   	m_TZD_product.InsertString(0,"ȫ��");
	m_TZD_product.SetCurSel(0);
	
		
	m_TZD_notice.AddString("��ҵ-����-װ�ƻ����Ϸ�-��ͨ�绰");
	m_TZD_notice.AddString("��ҵ-����-������-��ͨ�绰");
	m_TZD_notice.AddString("��ҵ-����-һ���Է���-��ͨ�绰");
	m_TZD_notice.AddString("Ԥ���˿�-�û�Ԥ���-��ͨ�绰");
	m_TZD_notice.AddString("��ҵ-����-һ���Է���-���õ绰-�������е绰");
	m_TZD_notice.AddString("Ԥ���˿�-�û�Ԥ���-���õ绰-�������е绰");
	m_TZD_notice.AddString("��ҵ-����-������-���õ绰-�������е绰");
	m_TZD_notice.AddString("��ҵ-����-װ�ƻ����Ϸ�-���õ绰-�������е绰");
	m_TZD_notice.AddString("��ҵ-����-װ�ƻ����Ϸ�-IDC-�����й�");
	m_TZD_notice.AddString("��ҵ-����-������-IDC-�����й�");
	m_TZD_notice.AddString("��ҵ-����-һ���Է���-IDC-�����й�");
	m_TZD_notice.AddString("��ҵ-����-װ�ƻ����Ϸ�-���-ADSL���Ⲧ��");
	m_TZD_notice.AddString("��ҵ-����-һ���Է���-���-ADSL���Ⲧ��");
	m_TZD_notice.AddString("��ҵ-����-������-���-ADSL���Ⲧ��");
	m_TZD_notice.AddString("��ҵ-����-װ�ƻ����Ϸ�-���-ADSL���Ⲧ��");
	m_TZD_notice.AddString("Ԥ���˿�-Ԥ���ѿ���-��ֵ-200��");
	m_TZD_notice.AddString("Ԥ���˿�-Ԥ���ѿ���-�����ۿ�-200��");
	m_TZD_notice.AddString("Ԥ���˿�-Ԥ���ѿ���-��ֵ-300��");
	m_TZD_notice.AddString("Ԥ���˿�-Ԥ���ѿ���-�����ۿ�-300��");
	m_TZD_notice.InsertString(0,"ȫ��");
    m_TZD_notice.SetCurSel(0);


	m_TZD_check.AddString("δ����");
	m_TZD_check.AddString("���˳ɹ�");
	m_TZD_check.AddString("����ʧ��");
	m_TZD_check.InsertString(0,"ȫ��");
    m_TZD_check.SetCurSel(0);

	
	
    m_listctrl.SetBkColor(RGB(160,180,220)); 
    m_listctrl.SetTextBkColor(RGB(160,180,220));
	m_listctrl.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES); 
    m_listctrl.InsertColumn(1, "�տ�����", LVCFMT_CENTER, 80,0);
    m_listctrl.InsertColumn(2, "��������", LVCFMT_CENTER, 100,1);
	m_listctrl.InsertColumn(3, "��Ʒ����", LVCFMT_CENTER, 380);
    m_listctrl.InsertColumn(4, "֪ͨ������", LVCFMT_CENTER,350);
    m_listctrl.InsertColumn(5, "֪ͨ�����", LVCFMT_CENTER, 80);
    m_listctrl.InsertColumn(6, "¼����Ա", LVCFMT_CENTER, 80);
    m_listctrl.InsertColumn(7, "����״̬", LVCFMT_CENTER, 80);

	
	try
	{
		
		m_AdoConn.OnInitADOConn();
		sql="select * from notice";//sql���
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
	
    POSITION pos = m_listctrl.GetFirstSelectedItemPosition();//�õ�λ��
	int i = m_listctrl.GetNextSelectedItem(pos);//�õ���ʱ������
    send_date = m_listctrl.GetItemText(i,0);//��i��0��
    send_city = m_listctrl.GetItemText(i,1);//��i��1��
    send_product = m_listctrl.GetItemText(i,2);
    send_notice = m_listctrl.GetItemText(i,3);
	int send_value = atoi(m_listctrl.GetItemText(i,4));

	CString check;
	check=m_listctrl.GetItemText(i,6);
  
	if(check!="����ͨ��")
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
	else MessageBox("�Բ��𣬴������ѻ���ͨ�������޸ģ�");
	*pResult = 0;
}

void Luru_tongzhiddan::Refresh()
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
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_notice") );
			m_listctrl.SetItemText(i,3,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_income") );
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
		sql="select * from notice where my_date between '"+start_Date+"' and '"+end_Date+"' ";//sql���
		 
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
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_notice") );
			m_listctrl.SetItemText(i,3,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_income") );
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
