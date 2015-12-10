// JiHe_wangjian.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "JiHe_wangjian.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// JiHe_wangjian dialog


JiHe_wangjian::JiHe_wangjian(CWnd* pParent /*=NULL*/)
	: CDialog(JiHe_wangjian::IDD, pParent)
{
	//{{AFX_DATA_INIT(JiHe_wangjian)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void JiHe_wangjian::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(JiHe_wangjian)
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_end_date);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_start_date);
	DDX_Control(pDX, IDC_COMBO5, m_JH_check);
	DDX_Control(pDX, IDC_COMBO4, m_JH_type);
	DDX_Control(pDX, IDC_COMBO3, m_JH_operator);
	DDX_Control(pDX, IDC_COMBO2, m_JH_product);
	DDX_Control(pDX, IDC_COMBO1, m_JH_city);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(JiHe_wangjian, CDialog)
	//{{AFX_MSG_MAP(JiHe_wangjian)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON2, OnSelect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// JiHe_wangjian message handlers

BOOL JiHe_wangjian::OnInitDialog() 
{
	CDialog::OnInitDialog();
		
	m_JH_city.AddString("��������");
	m_JH_city.AddString("����������");
	m_JH_city.AddString("�����ϲ�");
	m_JH_city.AddString("��������");
	m_JH_city.AddString("��������");
	m_JH_city.AddString("��������");
    m_JH_city.AddString("����ӥ̶");
	m_JH_city.AddString("�����Ž�");	
	m_JH_city.AddString("�����˴�");		
	m_JH_city.AddString("��������");			
	m_JH_city.AddString("����Ƽ��");		
	m_JH_city.AddString("��������");
	m_JH_city.InsertString(0,"ȫ��");
    m_JH_city.SetCurSel(0);
	
	
	m_JH_product.AddString("�̻�-��ֵҵ��-800-����");
	m_JH_product.AddString("����-IP��-ʡ��IP�绰��-200��");
	m_JH_product.AddString("����-IP��-ʡ��IP�绰��-300��");
	m_JH_product.AddString("�̻�-����ҵ��-��ͨ�绰");
	m_JH_product.AddString("�̻�-����ҵ��-���õ绰-�������е绰");
	m_JH_product.AddString("����ҵ��-�������������-�������-ADSL���Ⲧ��");
	m_JH_product.AddString("����ҵ��-�������������-��������ͨר�߽���");
	m_JH_product.AddString("����ҵ��-ƽ̨ҵ��-IDC-�����й�");
   	m_JH_product.InsertString(0,"ȫ��");
	m_JH_product.SetCurSel(0);
	
	
	
	m_JH_operator.AddString("����");
	m_JH_operator.AddString("�ƶ�");
	m_JH_operator.AddString("��ͨ");
   	m_JH_operator.InsertString(0,"ȫ��");
	m_JH_operator.SetCurSel(0);
	
	m_JH_type.AddString("����֧��");
	m_JH_type.AddString("��������");
   	m_JH_type.InsertString(0,"ȫ��");
	m_JH_type.SetCurSel(0);

	m_JH_check.AddString("δ����");
	m_JH_check.AddString("���˳ɹ�");
	m_JH_check.AddString("����ʧ��");
	m_JH_check.InsertString(0,"ȫ��");
    m_JH_check.SetCurSel(0);
	
    m_listctrl.SetBkColor(RGB(160,180,220)); 
    m_listctrl.SetTextBkColor(RGB(160,180,220));
	m_listctrl.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_CHECKBOXES|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES); 
    m_listctrl.InsertColumn(1, "�����·�", LVCFMT_CENTER, 80,0);
    m_listctrl.InsertColumn(2, "�������", LVCFMT_CENTER, 90,1);
	m_listctrl.InsertColumn(3, "��Ʒ����", LVCFMT_CENTER, 380);
    m_listctrl.InsertColumn(4, "������Ӫ��", LVCFMT_CENTER, 340);
	m_listctrl.InsertColumn(5, "��������", LVCFMT_CENTER, 80);
	m_listctrl.InsertColumn(6, "������", LVCFMT_CENTER, 80);
    m_listctrl.InsertColumn(7, "¼����Ա", LVCFMT_CENTER, 80);
    m_listctrl.InsertColumn(8, "����״̬", LVCFMT_CENTER, 80);
	
	try
	{
		
		m_AdoConn.OnInitADOConn();
		sql="select * from network";//sql���
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
			
			str=(char*)(_bstr_t)m_pRs->GetCollect("my_operator");
			m_listctrl.SetItemText(i,3,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_type") );
			m_listctrl.SetItemText(i,4,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_amount") );
			m_listctrl.SetItemText(i,5,str);

			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_user") );
			m_listctrl.SetItemText(i,6,str);
			
			int check=atoi( (char*)(_bstr_t)m_pRs->GetCollect("my_check_state") );
			if(check==0)
			{
				m_listctrl.SetItemText(i,7,"δ����");
			}
			else if(check==1)
			{
				m_listctrl.SetItemText(i,7,"����ͨ��");
			}else
			{
                m_listctrl.SetItemText(i,7,"����ʧ��");
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
	m_start_date.SetFormat("yyyy-MM");
	VERIFY(m_start_date.SetTime(oletimeTime));
	
	m_end_date.SetFormat("yyyy-MM");
	m_end_date.SetTime(&tem_ST);
	
	UpdateData(TRUE);
	// TODO: Add extra initialization here
	// TODO: Add extra initialization here
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void JiHe_wangjian::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR); 

	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
		if((pNMLV->uOldState & INDEXTOSTATEIMAGEMASK(1)) /* old state : unchecked */ 
		&& (pNMLV->uNewState & INDEXTOSTATEIMAGEMASK(2)) /* new state : checked */ 
		) 
	{ 

	
    CString send_date,send_city,send_product;

    send_date = m_listctrl.GetItemText(pNMLV->iItem,0);//��i��0��
    send_city = m_listctrl.GetItemText(pNMLV->iItem,1);//��i��1��
    send_product = m_listctrl.GetItemText(pNMLV->iItem,2);
	
	JiHe_CHECK jh_ck;
	jh_ck.date=send_date;
	jh_ck.city=send_city;
	jh_ck.product=send_product;
	jh_ck.table_name="network";
	
	jh_ck.DoModal();
	
//	Luru_Refresh();
	
	
	} 
	else if((pNMLV->uOldState & INDEXTOSTATEIMAGEMASK(2)) /* old state : checked */ 
		&& (pNMLV->uNewState & INDEXTOSTATEIMAGEMASK(1)) /* new state : unchecked */ 
		) 
	{ 
	//	TRACE("Item %d is unchecked\n", pNMLV->iItem); 
     	 CString date,city,product;
         date = m_listctrl.GetItemText(pNMLV->iItem,0);//��i��0��
         city = m_listctrl.GetItemText(pNMLV->iItem,1);//��i��1��
         product = m_listctrl.GetItemText(pNMLV->iItem,2);
		CString sql=_T("");
        sql.Format(_T("UPDATE notice SET my_check_state=0 WHERE my_date='%s' and my_city='%s'and my_product='%s'"),date,city,product);
    	ADOconn m_AdoConn;
    	m_AdoConn.OnInitADOConn();
    	m_AdoConn.ExecuteSQL((_bstr_t)sql);
		MessageBox("��ȡ������");

	} 
	else 
	{ 
		TRACE("Item %d does't change the check-status\n", pNMLV->iItem); 
	} 
	*pResult = 0;
}

void JiHe_wangjian::OnSelect() 
{
	// TODO: Add your control notification handler code here
		CString select_city,select_product,select_operator,select_type,check;
   	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(select_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(select_product);
   	((CComboBox*)GetDlgItem(IDC_COMBO3))->GetWindowText(select_operator);
	((CComboBox*)GetDlgItem(IDC_COMBO5))->GetWindowText(check);
	((CComboBox*)GetDlgItem(IDC_COMBO4))->GetWindowText(select_type);

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

	CString select2_check;
	select2_check.Format("%d",select_check);
	try
	{
		
		m_AdoConn.OnInitADOConn();
		sql="select * from network where my_date between '"+start_Date+"' and '"+end_Date+"' ";//sql���
		 
		if(select_city.CompareNoCase("ȫ��")!=0)
		{sql=sql+" AND my_city='"+select_city+"' ";}
	
		if(select_product.CompareNoCase("ȫ��")!=0)
		{sql=sql+"  AND my_product='"+select_product+"' ";};
	   
		if(select_operator.CompareNoCase("ȫ��")!=0)
		{sql=sql+"  AND my_operator='"+select_operator+"' ";};
	
		if(select_type.CompareNoCase("ȫ��")!=0)
		{sql=sql+"  AND my_type='"+select_type+"' ";};

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
			
			str=(char*)(_bstr_t)m_pRs->GetCollect("my_operator");
			m_listctrl.SetItemText(i,3,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_type") );
			m_listctrl.SetItemText(i,4,str);
			
			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_amount") );
			m_listctrl.SetItemText(i,5,str);

			str=( (char*)(_bstr_t)m_pRs->GetCollect("my_user") );
			m_listctrl.SetItemText(i,6,str);
			
			int check=atoi( (char*)(_bstr_t)m_pRs->GetCollect("my_check_state") );
			if(check==0)
			{
				m_listctrl.SetItemText(i,7,"δ����");
			}
			else if(check==1)
			{
				m_listctrl.SetItemText(i,7,"����ͨ��");
			}else
			{
                m_listctrl.SetItemText(i,7,"����ʧ��");
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
