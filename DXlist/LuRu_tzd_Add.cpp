// LuRu_tzd_Add.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "LuRu_tzd_Add.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LuRu_tzd_Add dialog


LuRu_tzd_Add::LuRu_tzd_Add(CWnd* pParent /*=NULL*/)
	: CDialog(LuRu_tzd_Add::IDD, pParent)
{
	//{{AFX_DATA_INIT(LuRu_tzd_Add)
	m_income = 0.0;
	//}}AFX_DATA_INIT
}


void LuRu_tzd_Add::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LuRu_tzd_Add)
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_date);
	DDX_Control(pDX, IDC_COMBO3, m_notice);
	DDX_Control(pDX, IDC_COMBO2, m_product);
	DDX_Control(pDX, IDC_COMBO1, m_city);
	DDX_Text(pDX, IDC_EDIT1, m_income);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LuRu_tzd_Add, CDialog)
	//{{AFX_MSG_MAP(LuRu_tzd_Add)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LuRu_tzd_Add message handlers

BOOL LuRu_tzd_Add::OnInitDialog() 
{
	CDialog::OnInitDialog();
	 m_city.AddString("��������");
	m_city.AddString("����������");
	m_city.AddString("�����ϲ�");
	m_city.AddString("��������");
	m_city.AddString("��������");
	m_city.AddString("��������");
    m_city.AddString("����ӥ̶");
	m_city.AddString("�����Ž�");	
	m_city.AddString("�����˴�");		
	m_city.AddString("��������");			
	m_city.AddString("����Ƽ��");		
	m_city.AddString("��������");
	m_city.InsertString(0,"������ѡ�񡪡�");
    m_city.SetCurSel(0);
	
	
	m_product.AddString("�̻�-��ֵҵ��-800-����");
	m_product.AddString("����-IP��-ʡ��IP�绰��-200��");
	m_product.AddString("����-IP��-ʡ��IP�绰��-300��");
	m_product.AddString("�̻�-����ҵ��-��ͨ�绰");
	m_product.AddString("�̻�-����ҵ��-���õ绰-�������е绰");
	m_product.AddString("����ҵ��-�������������-�������-ADSL���Ⲧ��");
	m_product.AddString("����ҵ��-�������������-��������ͨר�߽���");
	m_product.AddString("����ҵ��-ƽ̨ҵ��-IDC-�����й�");
   	m_product.InsertString(0,"������ѡ�񡪡�");
	m_product.SetCurSel(0);
	
		
	m_notice.AddString("��ҵ-����-װ�ƻ����Ϸ�-��ͨ�绰");
	m_notice.AddString("��ҵ-����-������-��ͨ�绰");
	m_notice.AddString("��ҵ-����-һ���Է���-��ͨ�绰");
	m_notice.AddString("Ԥ���˿�-�û�Ԥ���-��ͨ�绰");
	m_notice.AddString("��ҵ-����-һ���Է���-���õ绰-�������е绰");
	m_notice.AddString("Ԥ���˿�-�û�Ԥ���-���õ绰-�������е绰");
	m_notice.AddString("��ҵ-����-������-���õ绰-�������е绰");
	m_notice.AddString("��ҵ-����-װ�ƻ����Ϸ�-���õ绰-�������е绰");
	m_notice.AddString("��ҵ-����-װ�ƻ����Ϸ�-IDC-�����й�");
	m_notice.AddString("��ҵ-����-������-IDC-�����й�");
	m_notice.AddString("��ҵ-����-һ���Է���-IDC-�����й�");
	m_notice.AddString("��ҵ-����-װ�ƻ����Ϸ�-���-ADSL���Ⲧ��");
	m_notice.AddString("��ҵ-����-һ���Է���-���-ADSL���Ⲧ��");
	m_notice.AddString("��ҵ-����-������-���-ADSL���Ⲧ��");
	m_notice.AddString("��ҵ-����-װ�ƻ����Ϸ�-���-ADSL���Ⲧ��");
	m_notice.AddString("Ԥ���˿�-Ԥ���ѿ���-��ֵ-200��");
	m_notice.AddString("Ԥ���˿�-Ԥ���ѿ���-�����ۿ�-200��");
	m_notice.AddString("Ԥ���˿�-Ԥ���ѿ���-��ֵ-300��");
	m_notice.AddString("Ԥ���˿�-Ԥ���ѿ���-�����ۿ�-300��");
	m_notice.InsertString(0,"������ѡ�񡪡�");
    m_notice.SetCurSel(0);

    SYSTEMTIME tem_ST ; 
	
	GetLocalTime(&tem_ST);
	
	m_date.SetFormat("yyyy-MM-dd");
	m_date.SetTime(&tem_ST);
	
	UpdateData(TRUE);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void LuRu_tzd_Add::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString add_city,add_product,add_notice;
	double add_value;
	
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(add_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(add_product);
	((CComboBox*)GetDlgItem(IDC_COMBO3))->GetWindowText(add_notice);

	CTime time;
	CString szDate;
	CDateTimeCtrl* pCtrl =&this->m_date;
	DWORD dwResult =pCtrl->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		szDate = time.Format(TEXT("%Y/%m/%d"));
	}
	
	BOOL root; 	
	add_value=GetDlgItemInt(IDC_EDIT1,&root,false);

   CDXlistApp *app = (CDXlistApp *)AfxGetApp(); //����ָ��Ӧ�ó������ָ�� 

   CString sql; 
   CString value;

   value.Format("%lf",add_value);

   sql="INSERT INTO notice(my_date,my_city,my_product,my_notice,my_income,my_user) VALUES\
                       ('"+szDate+"','"+add_city+"','"+add_product+"','"+add_notice+"',"+value+",'"+app->USer_name+"')";

    ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
 
	MessageBox("��ӳɹ�");
}

void LuRu_tzd_Add::OnButton2() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}
