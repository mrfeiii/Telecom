// Add_Delet.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "Add_Delet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CDXlistApp theApp;
/////////////////////////////////////////////////////////////////////////////
// Add_Delet dialog


Add_Delet::Add_Delet(CWnd* pParent /*=NULL*/)
	: CDialog(Add_Delet::IDD, pParent)
{
	//{{AFX_DATA_INIT(Add_Delet)
	//}}AFX_DATA_INIT
}


void Add_Delet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Add_Delet)
	DDX_Control(pDX, IDC_EDIT1, m_getmoney);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_date);
	DDX_Control(pDX, IDC_COMBO3, m_type);
	DDX_Control(pDX, IDC_COMBO2, m_product);
	DDX_Control(pDX, IDC_COMBO1, m_city);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Add_Delet, CDialog)
	//{{AFX_MSG_MAP(Add_Delet)
	ON_CBN_DROPDOWN(IDC_COMBO1, OnDropdownCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO2, OnDropdownCombo2)
	ON_CBN_DROPDOWN(IDC_COMBO3, OnDropdownCombo3)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Add_Delet message handlers

void Add_Delet::OnDropdownCombo1() 
{
	// TODO: Add your control notification handler code here

}

void Add_Delet::OnDropdownCombo2() 
{
	// TODO: Add your control notification handler code here
  
}

void Add_Delet::OnDropdownCombo3() 
{	
	// TODO: Add your control notification handler code here

}

void Add_Delet::OnChangeEdit1() 
{
    UpdateData(true);
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void Add_Delet::OnButton1() 
{
	CDialog::OnInitDialog();
	// TODO: Add your control notification handler code here

    
    CString add_city,add_product,add_type,add_date;
	int add_price=0;
	
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(add_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(add_product);
	((CComboBox*)GetDlgItem(IDC_COMBO3))->GetWindowText(add_type);
	
	
	CTime time;
	CString szDate;
	CDateTimeCtrl* pCtrl =&this->m_date;
	DWORD dwResult =pCtrl->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		szDate = time.Format(TEXT("%Y/%m"));
	}
	
	BOOL root; 
	
	add_price=GetDlgItemInt(IDC_EDIT1,&root,false);
	while( root == false) 			
	{ 	
		MessageBox("�۸��������") ;			
	}
   CDXlistApp *app = (CDXlistApp *)AfxGetApp(); //����ָ��Ӧ�ó������ָ�� 
  
    CString add2_price;
    add2_price.Format("%d", add_price);
 
    CString sql;
    sql="Insert Into income_account(my_date,my_city,my_product,my_type,my_price,my_user) Values('"+szDate+"','"+add_city+"','"+add_product+"','"+add_type+"',"+add2_price+",'"+app->USer_name+"')";

	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	MessageBox("��ӳɹ�");


//	MessageBox(city);

}

void Add_Delet::OnButton2() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

BOOL Add_Delet::OnInitDialog() 
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
	m_city.InsertString(0,"---��ѡ��---");
    m_city.SetCurSel(0);

    m_product.AddString("�̻�-��ֵҵ��-800-����");
    m_product.AddString("����-IP��-ʡ��IP�绰��-200��");
    m_product.AddString("����-IP��-ʡ��IP�绰��-300��");
    m_product.AddString("�̻�-����ҵ��-��ͨ�绰");    
	m_product.AddString("�̻�-����ҵ��-���õ绰-�������е绰");
	m_product.AddString("����ҵ��-�������������-�������-ADSL���Ⲧ��");
    m_product.AddString("����ҵ��-�������������-��������ͨר�߽���");
    m_product.AddString("����ҵ��-ƽ̨ҵ��-IDC-�����й�");
	m_product.InsertString(0,"---��ѡ��---");
    m_product.SetCurSel(0);

	m_type.AddString("��Ӫҵ������-���ڿͻ�-���������");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-��������ͨ����");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-���ز�������ͨ�ŷ�");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-��������ͨ����");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-���ڳ�;ͨ�ŷ�");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-���ʳ�;ͨ�ŷ�");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-�۰�̨��;ͨ�ŷ�");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-IP���ڳ�;ͨ�ŷ�");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-IP���ʳ�;ͨ�ŷ�");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-IP�۰�̨��;ͨ�ŷ�");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-װ�ƻ����Ϸ�����"); 
	m_type.AddString("��Ӫҵ������-���ڿͻ�-����������");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-����ʹ�÷�");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-һ���Է���");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-��׼�ʷ�����");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-��ֵҵ������");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-����������");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-�ۿ�������");
	m_type.InsertString(0,"---��ѡ��---");
    m_type.SetCurSel(0);

 SYSTEMTIME tem_ST ; 

 GetLocalTime(&tem_ST);

 m_date.SetFormat("yyyy-MM");

 m_date.SetTime(&tem_ST);

 UpdateData(TRUE);


	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
