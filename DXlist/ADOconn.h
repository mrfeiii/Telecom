// ADOconn.h: interface for the ADOconn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCONN_H__9F816E25_6844_4F2E_9C3A_CF8C52A73704__INCLUDED_)
#define AFX_ADOCONN_H__9F816E25_6844_4F2E_9C3A_CF8C52A73704__INCLUDED_
#import "C:\program files\common files\system\ado\msado15.dll"no_namespace rename("EOF","adoEOF")
//#include<icrsint.h>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ADOconn  
{
public:
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	void EXitConn();
	void OnInitADOConn();
	ADOconn();
	virtual ~ADOconn();
  _ConnectionPtr m_pCon;
	_RecordsetPtr m_pRs;
};

#endif // !defined(AFX_ADOCONN_H__9F816E25_6844_4F2E_9C3A_CF8C52A73704__INCLUDED_)
