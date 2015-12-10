// LuRu_ycz_Add.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "LuRu_ycz_Add.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LuRu_ycz_Add dialog


LuRu_ycz_Add::LuRu_ycz_Add(CWnd* pParent /*=NULL*/)
	: CDialog(LuRu_ycz_Add::IDD, pParent)
{
	//{{AFX_DATA_INIT(LuRu_ycz_Add)
	m_amount = 0.0;
	//}}AFX_DATA_INIT
}


void LuRu_ycz_Add::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LuRu_ycz_Add)
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_date);
	DDX_Control(pDX, IDC_COMBO5, m_type);
	DDX_Control(pDX, IDC_COMBO2, m_product);
	DDX_Control(pDX, IDC_COMBO1, m_city);
	DDX_Text(pDX, IDC_EDIT1, m_amount);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LuRu_ycz_Add, CDialog)
	//{{AFX_MSG_MAP(LuRu_ycz_Add)
	ON_BN_CLICKED(IDC_BUTTON1, OnAdd)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LuRu_ycz_Add message handlers

void LuRu_ycz_Add::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CString add_city,add_product,add_type;
	double add_amount;
	
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(add_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(add_product);
	((CComboBox*)GetDlgItem(IDC_COMBO5))->GetWindowText(add_type);

	CTime time;
	CString szDate;
	CDateTimeCtrl* pCtrl =&this->m_date;
	DWORD dwResult =pCtrl->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		szDate = time.Format(TEXT("%Y/%m"));
	}
	
	BOOL root; 	
	add_amount=GetDlgItemInt(IDC_EDIT1,&root,false);

   CDXlistApp *app = (CDXlistApp *)AfxGetApp(); //����ָ��Ӧ�ó������ָ�� 

   CString sql; 
   CString amount;

   amount.Format("%lf",add_amount);

   sql="INSERT INTO writeoff(my_date,my_city,my_product,my_type,my_amount,my_user) VALUES\
                       ('"+szDate+"','"+add_city+"','"+add_product+"','"+add_type+"',"+amount+",'"+app->USer_name+"')";

    ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
 
	MessageBox("��ӳɹ�");
}



BOOL LuRu_ycz_Add::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
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
	
	m_type.AddString("Ԥ���˿�-�û�Ԥ���");
	m_type.AddString("Ԥ���˿�-�ɷѿ���");
	m_type.AddString("Ԥ���˿�-Ԥ���ѿ���-��ֵ");
	m_type.AddString("Ԥ���˿�-Ԥ���ѿ���-�����ۿ�");
	m_type.AddString("Ԥ���˿�-Ԥ�ճ�����Ʒ���");
	m_type.AddString("Ԥ���˿�-Ԥ�մ��칤�̿�");
	m_type.AddString("Ԥ���˿�-����-����");
   	m_type.InsertString(0,"������ѡ�񡪡�");
	m_type.SetCurSel(0);
	
    SYSTEMTIME tem_ST ; 
	
	GetLocalTime(&tem_ST);
	
	m_date.SetFormat("yyyy-MM-dd");
	m_date.SetTime(&tem_ST);
	
	UpdateData(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void LuRu_ycz_Add::OnButton2() 
{
	// TODO: Add your control notification handler code here
			OnCancel();
}
