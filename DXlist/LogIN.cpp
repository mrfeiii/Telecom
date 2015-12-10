// LogIN.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "LogIN.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LogIN dialog


LogIN::LogIN(CWnd* pParent /*=NULL*/)
	: CDialog(LogIN::IDD, pParent)
{
	//{{AFX_DATA_INIT(LogIN)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void LogIN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LogIN)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LogIN, CDialog)
	//{{AFX_MSG_MAP(LogIN)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LogIN message handlers
