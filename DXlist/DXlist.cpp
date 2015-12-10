// DXlist.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "DXlist.h"
#include "DXlistDlg.h"
#include <io.h>
#include <odbcinst.h>
#include <afxdb.h>
#include <fstream.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDXlistApp

BEGIN_MESSAGE_MAP(CDXlistApp, CWinApp)
//{{AFX_MSG_MAP(CDXlistApp)
// NOTE - the ClassWizard will add and remove mapping macros here.
//    DO NOT EDIT what you see in these blocks of generated code!
//}}AFX_MSG
ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDXlistApp construction
CDXlistApp theApp;


CDXlistApp::CDXlistApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDXlistApp object


/////////////////////////////////////////////////////////////////////////////
// CDXlistApp initialization

BOOL CDXlistApp::InitInstance()
{
	AfxEnableControlContainer();
	
	
	
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
	
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	
	CDXlistDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
CString GetExcelDriver()
{
    char szBuf[2001];
    WORD cbBufMax = 2000;
    WORD cbBufOut;
    char *pszBuf = szBuf;
    CString sDriver;
	
    // ��ȡ�Ѱ�װ����������(������odbcinst.h��)
    if (!SQLGetInstalledDrivers(szBuf, cbBufMax, &cbBufOut))
        return "";
    
    // �����Ѱ�װ�������Ƿ���Excel...
    do
    {
        if (strstr(pszBuf, "Excel") != 0)
        {
            //���� !
            sDriver = CString(pszBuf);
            break;
        }
        pszBuf = strchr(pszBuf, '\0') + 1;
    }
    while (pszBuf[1] != '\0');
	
    return sDriver;
}

///////////////////////////////////////////////////////////////////////////////
//	BOOL MakeSurePathExists( CString &Path,bool FilenameIncluded)
//	������
//		Path				·��
//		FilenameIncluded	·���Ƿ�����ļ���
//	����ֵ:
//		�ļ��Ƿ����
//	˵��:
//		�ж�Path�ļ�(FilenameIncluded=true)�Ƿ����,���ڷ���TURE�������ڷ���FALSE
//		�Զ�����Ŀ¼
//
///////////////////////////////////////////////////////////////////////////////
BOOL MakeSurePathExists( CString &Path,
						bool FilenameIncluded)
{
	int Pos=0;
	while((Pos=Path.Find('\\',Pos+1))!=-1)
		CreateDirectory(Path.Left(Pos),NULL);
	if(!FilenameIncluded)
		CreateDirectory(Path,NULL);
	//	return ((!FilenameIncluded)?!_access(Path,0):
	//	!_access(Path.Left(Path.ReverseFind('\\')),0));
	
	return !_access(Path,0);
}

//���Ĭ�ϵ��ļ���
BOOL GetDefaultXlsFileName(CString& sExcelFile)
{
	///Ĭ���ļ�����yyyymmddhhmmss.xls
	CString timeStr;
	CTime day;
	day=CTime::GetCurrentTime();
	int filenameday,filenamemonth,filenameyear,filehour,filemin,filesec;
	filenameday=day.GetDay();//dd
	filenamemonth=day.GetMonth();//mm�·�
	filenameyear=day.GetYear();//yyyy
	filehour=day.GetHour();//hh
	filemin=day.GetMinute();//mm����
	filesec=day.GetSecond();//ss
	timeStr.Format("%04d%02d%02d%02d%02d%02d",filenameyear,filenamemonth,filenameday,filehour,filemin,filesec);
	
	sExcelFile =  timeStr + ".xls";
	// prompt the user (with all document templates)
	CFileDialog dlgFile(FALSE,".xls",sExcelFile);
	CString title;
	CString strFilter;
	
	title = "����";
	strFilter = "Excel�ļ�(*.xls)";
	strFilter += (TCHAR)'\0';   // next string please
	strFilter += _T("*.xls");
	strFilter += (TCHAR)'\0';   // last string
	dlgFile.m_ofn.nMaxCustFilter++;
	dlgFile.m_ofn.nFilterIndex = 1;
	// append the "*.*" all files filter
	CString allFilter;
	VERIFY(allFilter.LoadString(AFX_IDS_ALLFILTER));
	strFilter += allFilter;
	strFilter += (TCHAR)'\0';   // next string please
	strFilter += _T("*.*");
	strFilter += (TCHAR)'\0';   // last string
	dlgFile.m_ofn.nMaxCustFilter++;
	
	dlgFile.m_ofn.lpstrFilter = strFilter;
	dlgFile.m_ofn.lpstrTitle = title;
	
	if (dlgFile.DoModal()==IDCANCEL)
		return FALSE; // open cancelled
	sExcelFile.ReleaseBuffer();
	if (MakeSurePathExists(sExcelFile,true)) {
		if(!DeleteFile(sExcelFile)) {    // delete the file
			AfxMessageBox("�����ļ�ʱ����");
			return FALSE;
		}
	}
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
//	void GetExcelDriver(CListCtrl* pList, CString strTitle)
//	������
//		pList		��Ҫ������List�ؼ�ָ��
//		strTitle	���������ݱ����
//	˵��:
//		����CListCtrl�ؼ���ȫ�����ݵ�Excel�ļ���Excel�ļ������û�ͨ�������Ϊ��
//		�Ի�������ָ����������ΪstrTitle�Ĺ�������List�ؼ��ڵ��������ݣ�����
//		��������������ı�����ʽ���浽Excel�������С��������й�ϵ��
//	
//
///////////////////////////////////////////////////////////////////////////////
void ExportListToExcel(CListCtrl* pList, CString strTitle)
{
	CString warningStr;
	if (pList->GetItemCount()>0) {	
		CDatabase database;
		CString sDriver;
		CString sExcelFile; 
		CString sSql;
		CString tableName = strTitle;
		
		// �����Ƿ�װ��Excel���� "Microsoft Excel Driver (*.xls)" 
		sDriver = GetExcelDriver();
		if (sDriver.IsEmpty())
		{
			// û�з���Excel����
			AfxMessageBox("û�а�װExcel!\n���Ȱ�װExcel�������ʹ�õ�������!");
			return;
		}
		
		///Ĭ���ļ���
		if (!GetDefaultXlsFileName(sExcelFile))
			return;
		
		// �������д�ȡ���ַ���
		sSql.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s",sDriver, sExcelFile, sExcelFile);
		
		// �������ݿ� (��Excel����ļ�)
		if( database.OpenEx(sSql,CDatabase::noOdbcDialog) )
		{
			// ������ṹ
			int i;
			LVCOLUMN columnData;
			CString columnName;
			int columnNum = 0;
			CString strH;
			CString strV;
			
			sSql = "";
			strH = "";
			columnData.mask = LVCF_TEXT;
			columnData.cchTextMax =100;
			columnData.pszText = columnName.GetBuffer (100);
			for(i=0;pList->GetColumn(i,&columnData);i++)
			{
				if (i!=0)
				{
					sSql = sSql + ", " ;
					strH = strH + ", " ;
				}
				sSql = sSql + " " + columnData.pszText +" TEXT";
				strH = strH + " " + columnData.pszText +" ";
			}
			columnName.ReleaseBuffer ();
			columnNum = i;
			
			sSql = "CREATE TABLE " + tableName + " ( " + sSql +  " ) ";
			database.ExecuteSQL(sSql);
			
			// ����������
			int nItemIndex;
			for (nItemIndex=0;nItemIndex<pList->GetItemCount ();nItemIndex++){
				strV = "";
				for(i=0;i<columnNum;i++)
				{
					if (i!=0)
					{
						strV = strV + ", " ;
					}
					strV = strV + " '" + pList->GetItemText(nItemIndex,i) +"' ";
				}
				
				sSql = "INSERT INTO "+ tableName 
					+" ("+ strH + ")"
					+" VALUES("+ strV + ")";
				database.ExecuteSQL(sSql);
			}
			
		}      
		
		// �ر����ݿ�
		database.Close();
		
		warningStr.Format("�����ļ�������%s!",sExcelFile);
		AfxMessageBox(warningStr);
	}
}

BOOL GetDefaultTXTFileName(CString& sExcelFile)
{
	///Ĭ���ļ�����yyyymmddhhmmss.xls
	CString timeStr;
	CTime day;
	day=CTime::GetCurrentTime();
	int filenameday,filenamemonth,filenameyear,filehour,filemin,filesec;
	filenameday=day.GetDay();//dd
	filenamemonth=day.GetMonth();//mm�·�
	filenameyear=day.GetYear();//yyyy
	filehour=day.GetHour();//hh
	filemin=day.GetMinute();//mm����
	filesec=day.GetSecond();//ss
	timeStr.Format("%04d%02d%02d%02d%02d%02d",filenameyear,filenamemonth,filenameday,filehour,filemin,filesec);
	
	sExcelFile =  timeStr + ".txt";
	// prompt the user (with all document templates)
	CFileDialog dlgFile(FALSE,".txt",sExcelFile);
	CString title;
	CString strFilter;
	
	title = "����";
	strFilter = "txt�ļ�(*.txt)";
	strFilter += (TCHAR)'\0';   // next string please
	strFilter += _T("*.txt");
	strFilter += (TCHAR)'\0';   // last string
	dlgFile.m_ofn.nMaxCustFilter++;
	dlgFile.m_ofn.nFilterIndex = 1;
	// append the "*.*" all files filter
	CString allFilter;
	VERIFY(allFilter.LoadString(AFX_IDS_ALLFILTER));
	strFilter += allFilter;
	strFilter += (TCHAR)'\0';   // next string please
	strFilter += _T("*.*");
	strFilter += (TCHAR)'\0';   // last string
	dlgFile.m_ofn.nMaxCustFilter++;
	
	
	
	dlgFile.m_ofn.lpstrFilter = strFilter;
	dlgFile.m_ofn.lpstrTitle = title;
	if (dlgFile.DoModal()==IDCANCEL)
		return FALSE; // open cancelled
	sExcelFile.ReleaseBuffer();
	if (MakeSurePathExists(sExcelFile,true)) {
		if(!DeleteFile(sExcelFile)) {    // delete the file
			AfxMessageBox("�����ļ�ʱ����");
			return FALSE;
		}
	}
	
	return TRUE;
}

void ExportListToTXT(CListCtrl* pList)
{
	CString strV,warningStr;
	int i;
	int columnNum = 0;
	CString sExcelFile; 
	if (pList->GetItemCount ()>0)
	{	
	
		
		///Ĭ���ļ���
		if (!GetDefaultTXTFileName(sExcelFile))
			return;
		ofstream SaveFile(sExcelFile, ios::ate);
		
		LVCOLUMN columnData;
		CString columnName;
		int columnNum = 0;
		CString strH;
		CString strV;
		
		columnData.mask = LVCF_TEXT;
		columnData.cchTextMax =100;
		columnData.pszText = columnName.GetBuffer (100);
		
		
		for(i=0;pList->GetColumn(i,&columnData);i++)
		{
			if (i!=0)
				{

					strH = strH + ", " ;
				}
			
				strH = strH + "     " + columnData.pszText +"     ";
			}
        SaveFile<<strH<<endl;
		columnName.ReleaseBuffer ();
		columnNum = i;
		
		int nItemIndex;
		for (nItemIndex=0;nItemIndex<pList->GetItemCount ();nItemIndex++){
			strV = "";
			for(i=0;i<columnNum;i++)
			{
				if (i!=0)
				{
					strV = strV + ", " ;
				}
				strV = strV + "   " + pList->GetItemText(nItemIndex,i) +"   ";
			}
			SaveFile<<strV<<endl;
			
			
		}
		
		
		SaveFile.close();
		
	}
	
	warningStr.Format("�����ļ�������%s!",sExcelFile);
	AfxMessageBox(warningStr);
}