// LuRu_tzd_Delet.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "LuRu_tzd_Delet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LuRu_tzd_Delet dialog


LuRu_tzd_Delet::LuRu_tzd_Delet(CWnd* pParent /*=NULL*/)
	: CDialog(LuRu_tzd_Delet::IDD, pParent)
{
	//{{AFX_DATA_INIT(LuRu_tzd_Delet)
	m_value = 0.0;
	//}}AFX_DATA_INIT
}


void LuRu_tzd_Delet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LuRu_tzd_Delet)
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_date);
	DDX_Control(pDX, IDC_COMBO3, m_notice);
	DDX_Control(pDX, IDC_COMBO2, m_product);
	DDX_Control(pDX, IDC_COMBO1, m_city);
	DDX_Text(pDX, IDC_EDIT1, m_value);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LuRu_tzd_Delet, CDialog)
	//{{AFX_MSG_MAP(LuRu_tzd_Delet)
	ON_BN_CLICKED(IDC_BUTTON1, OnDelete)
	ON_BN_CLICKED(IDC_BUTTON2, OnModify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LuRu_tzd_Delet message handlers

BOOL LuRu_tzd_Delet::OnInitDialog() 
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

	
	m_product.AddString("�̻�-��ֵҵ��-800-����");
	m_product.AddString("����-IP��-ʡ��IP�绰��-200��");
	m_product.AddString("����-IP��-ʡ��IP�绰��-300��");
	m_product.AddString("�̻�-����ҵ��-��ͨ�绰");
	m_product.AddString("�̻�-����ҵ��-���õ绰-�������е绰");
	m_product.AddString("����ҵ��-�������������-�������-ADSL���Ⲧ��");
	m_product.AddString("����ҵ��-�������������-��������ͨר�߽���");
	m_product.AddString("����ҵ��-ƽ̨ҵ��-IDC-�����й�");

		
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


    int nIndex = m_city.FindStringExact( -1 , city );
	m_city.SetCurSel(nIndex); 
	nIndex = m_product.FindStringExact( -1 , product );
	m_product.SetCurSel(nIndex); 
	nIndex = m_notice.FindStringExact( -1 , notice );
	m_notice.SetCurSel(nIndex); 

	m_value=value;
	UpdateData(FALSE); 
	
	m_date.SetFormat("yyyy-MM-dd");
	CString year,month,day;
	year=date.Left(4);
	month=date.Mid(6, 7);
	day=date.Right(2);
	int y=atoi(year);
	int m=atoi(month);
	int d=atoi(day);
	m=m+1;
	CTime time(y,m,d,0,0,0);
    
	m_date.SetTime(&time); 
	
	UpdateData(TRUE);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void LuRu_tzd_Delet::OnDelete() 
{
	// TODO: Add your control notification handler code here
	CString sql;
	CString value;
	value.Format("%lf",m_value);
	sql="Delete from notice where my_date='"+date+"' AND my_city='"+city+"' AND my_product='"+product+"' AND my_notice='"+notice+"' ";
	ADOconn m_AdoConn;
	_RecordsetPtr m_pRs;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	
    CDialog::OnOK();
}

void LuRu_tzd_Delet::OnModify() 
{
	// TODO: Add your control notification handler code here
	CString alter_city,alter_product,alter_notice;
	double alter_value;
	
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(alter_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(alter_product);
    ((CComboBox*)GetDlgItem(IDC_COMBO3))->GetWindowText(alter_notice);

	CTime time;
	CString szDate;
	CDateTimeCtrl* pCtrl =&this->m_date;
	DWORD dwResult =pCtrl->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		szDate = time.Format(TEXT("%Y/%m/%d"));
	}
	
	BOOL root; 	
	alter_value=GetDlgItemInt(IDC_EDIT1,&root,false);
 
	
					
	CString sql=_T("");
    sql.Format(_T("UPDATE [notice] SET  my_date='%s',my_city='%s',my_product='%s',my_notice='%s',my_income=%lf WHERE my_product='%s' and my_city='%s' and my_date='%s' "),\
                      szDate,alter_city,alter_product,alter_notice,alter_value,product,city,date);
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);

	MessageBox("�޸ĳɹ�");

	OnOK();
}
