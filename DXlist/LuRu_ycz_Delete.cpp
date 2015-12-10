// LuRu_ycz_Delete.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "LuRu_ycz_Delete.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LuRu_ycz_Delete dialog


LuRu_ycz_Delete::LuRu_ycz_Delete(CWnd* pParent /*=NULL*/)
	: CDialog(LuRu_ycz_Delete::IDD, pParent)
{
	//{{AFX_DATA_INIT(LuRu_ycz_Delete)
	m_amount = 0.0;
	//}}AFX_DATA_INIT
}


void LuRu_ycz_Delete::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LuRu_ycz_Delete)
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_date);
	DDX_Control(pDX, IDC_COMBO5, m_type);
	DDX_Control(pDX, IDC_COMBO2, m_product);
	DDX_Control(pDX, IDC_COMBO1, m_city);
	DDX_Text(pDX, IDC_EDIT1, m_amount);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LuRu_ycz_Delete, CDialog)
	//{{AFX_MSG_MAP(LuRu_ycz_Delete)
	ON_BN_CLICKED(IDC_BUTTON1, OnDelete)
	ON_BN_CLICKED(IDC_BUTTON2, OnModify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LuRu_ycz_Delete message handlers

BOOL LuRu_ycz_Delete::OnInitDialog() 
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

	
	m_type.AddString("Ԥ���˿�-�û�Ԥ���");
	m_type.AddString("Ԥ���˿�-�ɷѿ���");
	m_type.AddString("Ԥ���˿�-Ԥ���ѿ���-��ֵ");
	m_type.AddString("Ԥ���˿�-Ԥ���ѿ���-�����ۿ�");
	m_type.AddString("Ԥ���˿�-Ԥ�ճ�����Ʒ���");
	m_type.AddString("Ԥ���˿�-Ԥ�մ��칤�̿�");
	m_type.AddString("Ԥ���˿�-����-����");


    int nIndex = m_city.FindStringExact( -1 , city );
	m_city.SetCurSel(nIndex); 
	nIndex = m_product.FindStringExact( -1 , product );
	m_product.SetCurSel(nIndex); 
	nIndex = m_type.FindStringExact( -1 , type );
	m_type.SetCurSel(nIndex); 

	m_amount=amount;
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

void LuRu_ycz_Delete::OnDelete() 
{
	// TODO: Add your control notification handler code here
	CString sql;
	sql="Delete from writeoff where my_date='"+date+"' AND my_city='"+city+"' AND my_product='"+product+"' AND my_type='"+type+"' ";
	ADOconn m_AdoConn;
	_RecordsetPtr m_pRs;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	
    CDialog::OnOK();
}

void LuRu_ycz_Delete::OnModify() 
{
	// TODO: Add your control notification handler code here
	CString alter_city,alter_product,alter_type;
	double alter_amount;
	
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetWindowText(alter_city);
    ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetWindowText(alter_product);
    ((CComboBox*)GetDlgItem(IDC_COMBO5))->GetWindowText(alter_type);

	CTime time;
	CString szDate;
	CDateTimeCtrl* pCtrl =&this->m_date;
	DWORD dwResult =pCtrl->GetTime(time);
	if (dwResult == GDT_VALID)
	{
		szDate = time.Format(TEXT("%Y/%m/%d"));
	}
	
	BOOL root; 	
	alter_amount=GetDlgItemInt(IDC_EDIT1,&root,false);

	
						
    CString sql=_T("");
    sql.Format(_T("UPDATE writeoff SET  my_date='%s',my_city='%s',my_product='%s',my_type='%s', my_amount=%lf WHERE my_product='%s' and my_city='%s' and my_date='%s' "),\
                      szDate,alter_city,alter_product,alter_type,alter_amount,product,city,date);
	ADOconn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);

	MessageBox("�޸ĳɹ�");

	OnOK();
}
