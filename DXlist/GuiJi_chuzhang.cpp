// GuiJi_chuzhang.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "GuiJi_chuzhang.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// GuiJi_chuzhang dialog


GuiJi_chuzhang::GuiJi_chuzhang(CWnd* pParent /*=NULL*/)
	: CDialog(GuiJi_chuzhang::IDD, pParent)
{
	//{{AFX_DATA_INIT(GuiJi_chuzhang)
	//}}AFX_DATA_INIT
}


void GuiJi_chuzhang::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GuiJi_chuzhang)
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_end_date);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_start_date);
	DDX_Control(pDX, IDC_COMBO3, m_GJ_type);
	DDX_Control(pDX, IDC_COMBO2, m_GJ_product);
	DDX_Control(pDX, IDC_COMBO1, m_GJ_city);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(GuiJi_chuzhang, CDialog)
	//{{AFX_MSG_MAP(GuiJi_chuzhang)
	ON_BN_CLICKED(IDC_BUTTON2, OnOut)
	ON_BN_CLICKED(IDC_BUTTON3, OnPutoutTXT)
	ON_BN_CLICKED(IDC_BUTTON1, OnSelect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// GuiJi_chuzhang message handlers

void GuiJi_chuzhang::OnOut() 
{
	// TODO: Add your control notification handler code here
	ExportListToExcel(&m_listctrl,"�����˵�");
  
}

BOOL GuiJi_chuzhang::OnInitDialog() 
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
	
	
	
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-���������");
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-��������ͨ����");
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-���ز�������ͨ�ŷ�");
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-��������ͨ����");
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-���ڳ�;ͨ�ŷ�");
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-���ʳ�;ͨ�ŷ�");
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-�۰�̨��;ͨ�ŷ�");
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-IP���ڳ�;ͨ�ŷ�");
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-IP���ʳ�;ͨ�ŷ�");
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-IP�۰�̨��;ͨ�ŷ�");
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-װ�ƻ����Ϸ�����");
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-����������");
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-����ʹ�÷�");
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-һ���Է���");
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-��׼�ʷ�����");
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-��ֵҵ������");
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-����������");
	m_GJ_type.AddString("��Ӫҵ������-���ڿͻ�-�ۿ�������");
   	m_GJ_type.InsertString(0,"ȫ��");
	m_GJ_type.SetCurSel(0);
	
	
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
			int check=atoi( (char*)(_bstr_t)m_pRs->GetCollect("my_check_state") );
			if(check==1)
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
			
        	m_listctrl.SetItemText(i,6,"����ͨ��");
				
			m_pRs->MoveNext();
			i++;
			}else {	m_pRs->MoveNext();}
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
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void GuiJi_chuzhang::OnPutoutTXT() 
{
	// TODO: Add your control notification handler code here
	   ExportListToTXT(&m_listctrl);
}

void GuiJi_chuzhang::OnSelect() 
{
	// TODO: Add your control notification handler code here
	CString select_city,select_product,select_type;
   	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(select_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(select_product);
	((CComboBox*)GetDlgItem(IDC_COMBO3))->GetWindowText(select_type);
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

	m_listctrl.DeleteAllItems();
	
	CString select2_price,select2_check;

	try
	{
		
		m_AdoConn.OnInitADOConn();
		sql="select * from income_account where my_date between '"+start_Date+"' and '"+end_Date+"' AND my_check_state=1 ";//sql���
		
		if(select_city.CompareNoCase("ȫ��")!=0)
		{sql=sql+" AND my_city='"+select_city+"' ";}
		if(select_product.CompareNoCase("ȫ��")!=0)
		{sql=sql+"  AND my_product='"+select_product+"' ";};
		if(select_type.CompareNoCase("ȫ��")!=0)
		{sql=sql+" AND my_type='"+select_type+"' ";};
	
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
