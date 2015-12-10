// Delete.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "Delete.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Delete dialog


Delete::Delete(CWnd* pParent /*=NULL*/)
: CDialog(Delete::IDD, pParent)
{
	
	//{{AFX_DATA_INIT(Delete)
	m_money = _T("");
	//}}AFX_DATA_INIT
}


void Delete::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Delete)
	DDX_Control(pDX, IDC_EDIT1, m_getmoney);
	DDX_Control(pDX, IDC_COMBO3, m_type);
	DDX_Control(pDX, IDC_COMBO2, m_product);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_date);
	DDX_Control(pDX, IDC_COMBO1, m_city);
	DDX_Text(pDX, IDC_EDIT1, m_money);
	//}}AFX_DATA_MAP
	
}


BEGIN_MESSAGE_MAP(Delete, CDialog)
//{{AFX_MSG_MAP(Delete)
ON_CBN_DROPDOWN(IDC_COMBO1, OnDropdownCombo1)
ON_CBN_DROPDOWN(IDC_COMBO2, OnDropdownCombo2)
ON_CBN_DROPDOWN(IDC_COMBO3, OnDropdownCombo3)
ON_BN_CLICKED(IDC_BUTTON1, OnDelete)
ON_BN_CLICKED(IDC_BUTTON2, OnModify)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Delete message handlers

BOOL Delete::OnInitDialog() 
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
	
	m_product.AddString("�̻�-��ֵҵ��-800-����");
	m_product.AddString("����-IP��-ʡ��IP�绰��-200��");
	m_product.AddString("����-IP��-ʡ��IP�绰��-300��");
	m_product.AddString("�̻�-����ҵ��-��ͨ�绰");
	m_product.AddString("�̻�-����ҵ��-���õ绰-�������е绰");
	m_product.AddString("����ҵ��-�������������-�������-ADSL���Ⲧ��");
	m_product.AddString("����ҵ��-�������������-��������ͨר�߽���");
	m_product.AddString("����ҵ��-ƽ̨ҵ��-IDC-�����й�");
	
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
	// TODO: Add extra initialization here
	//GetDlgItem(IDC_COMBO1)->SetWindowTest("aa");
    
    int nIndex = m_city.FindStringExact( -1 , city );
	m_city.SetCurSel(nIndex); 
	nIndex = m_product.FindStringExact( -1 , product );
	m_product.SetCurSel(nIndex); 
	nIndex = m_type.FindStringExact( -1 , type );
	m_type.SetCurSel(nIndex); 
	
	CString str;
	str.Format("%d",money);
	m_money=str;
	UpdateData(FALSE); 
	
	m_date.SetFormat("yyyy-MM");
	CString year,month;
	year=date.Left(4);
	month=date.Right(2);
	int y=atoi(year);
	int m=atoi(month);
	m=m+1;
	CTime time(y,m,0,0,0,0);
    
	m_date.SetTime(&time); 
	
	UpdateData(TRUE);
	
    
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}




void Delete::OnDropdownCombo1() 
{
	// TODO: Add your control notification handler code here
	/*	m_city.AddString("��������");
	
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
	*/
}

void Delete::OnDropdownCombo2() 
{
	// TODO: Add your control notification handler code here
	/*	m_product.AddString("�̻�-��ֵҵ��-800-����");
	m_product.AddString("����-IP��-ʡ��IP�绰��-200��");
	m_product.AddString("����-IP��-ʡ��IP�绰��-300��");
	m_product.AddString("�̻�-����ҵ��-��ͨ�绰");
	m_product.AddString("�̻�-����ҵ��-���õ绰-�������е绰");
	m_product.AddString("����ҵ��-�������������-�������-ADSL���Ⲧ��");
	m_product.AddString("����ҵ��-�������������-��������ͨר�߽���");
	m_product.AddString("����ҵ��-ƽ̨ҵ��-IDC-�����й�");
	*/
}

void Delete::OnDropdownCombo3() 
{
	// TODO: Add your control notification handler code here
	/*	m_type.AddString("��Ӫҵ������-���ڿͻ�-���������");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-��������ͨ���� ");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-���ز�������ͨ�ŷ� ");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-��������ͨ���� ");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-���ڳ�;ͨ�ŷ� ");
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
	m_type.AddString(" ��Ӫҵ������-���ڿͻ�-����������");
	m_type.AddString("��Ӫҵ������-���ڿͻ�-�ۿ�������");
	*/
}

void Delete::OnDelete() 
{
	//TODO: Add your control notification handler code here
	
	
	CString sql;
	sql="Delete from income_account where my_date='"+date+"'  AND my_city='"+city+"' AND my_product='"+product+"' AND my_type='"+type+"'  ";
	ADOconn m_AdoConn;
	_RecordsetPtr m_pRs;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	
	
    CDialog::OnOK();
	
	
	
}

void Delete::OnModify() 
{
	CString alter_city,alter_product,alter_type,alter_date;
	int alter_price=0;
	
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(alter_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(alter_product);
	((CComboBox*)GetDlgItem(IDC_COMBO3))->GetWindowText(alter_type);
	
	
	CTime time;
	CString szDate;
	CDateTimeCtrl* pCtrl =&this->m_date;
	DWORD dwResult =pCtrl->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		szDate = time.Format(TEXT("%Y/%m"));
	}
	
	BOOL root; 
	
	
	alter_price=GetDlgItemInt(IDC_EDIT1,&root,false);
	while( root == false) 			
	{ 	
		MessageBox("�۸��������") ;			
	}




	CString sql=_T("");
    sql.Format(_T("UPDATE income_account SET my_date='%s',my_product='%s',my_type='%s',my_price=%d , my_city='%s' WHERE my_product='%s' and my_type='%s' and my_price=%d and my_product='%s'"),szDate,alter_product,alter_type,alter_price,alter_city,product,type,money,product);

	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	MessageBox("�޸ĳɹ�");

	OnOK();
	// TODO Add your control notification handler code here
	
}
