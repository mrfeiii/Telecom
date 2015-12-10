// ADOconn.cpp: implementation of the ADOconn class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DXlist.h"
#include "ADOconn.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ADOconn::ADOconn()
{

}

ADOconn::~ADOconn()
{

}

void ADOconn::OnInitADOConn()
{

	if ( FAILED( CoInitialize(NULL) ) )
	{
		AfxMessageBox("初始化COM支持库失败！");
		exit(1);
	}
	try
	{
	   m_pCon.CreateInstance("ADODB.Connection");
    	m_pCon->ConnectionTimeout=3;
       m_pCon->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=db.mdb","","",adModeUnknown);
		
	}
	catch(_com_error e)
	{
   
	 AfxMessageBox(e.Description());
	}
m_pRs.CreateInstance(__uuidof(Recordset));

}

void ADOconn::EXitConn()
{
	if(m_pRs!=NULL)
		m_pRs->Close();
	m_pRs->Close();
	::CoUninitialize();

}

_RecordsetPtr& ADOconn::GetRecordSet(_bstr_t bstrSQL)
{
	try
	{
		if(m_pCon==NULL)
			OnInitADOConn();
		m_pRs.CreateInstance("ADODB.Recordset");
		m_pRs->Open(bstrSQL,m_pCon.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
	return m_pRs;

}

BOOL ADOconn::ExecuteSQL(_bstr_t bstrSQL)
{
	try
	{
		if(m_pCon==NULL)
			OnInitADOConn();
		m_pCon->Execute(bstrSQL,NULL,adCmdText);
		return true;
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
		return false;
	}

}
