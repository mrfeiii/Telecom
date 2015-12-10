// DXlistDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DXlist.h"
#include "DXlistDlg.h"
#include "Luru_chuzhang.h"
#include "Luru_kaxiaoshou.h"
#include "Luru_tongzhiddan.h"
#include "Luru_wangjian.h"
#include "Luru_yucunzhuan.h"
#include "JiHe_wangjian.h"
#include "JiHe_yucunzhuan.h"
#include "GuiJi_kaxiaoshou.h"
#include "GuiJi_chuzhang.h"
#include "GuiJi_tongzhidan.h"
#include "GuiJi_yucunzhuan.h"
#include "GuiJi_wangjian.h"
#include "Modify_psw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDXlistDlg dialog

CDXlistDlg::CDXlistDlg(CWnd* pParent /*=NULL*/)
: CDialog(CDXlistDlg::IDD, pParent)
{
	Log_flag=0;
	//{{AFX_DATA_INIT(CDXlistDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	
}

void CDXlistDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDXlistDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDXlistDlg, CDialog)
//{{AFX_MSG_MAP(CDXlistDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_COMMAND(ID_MENU_LRkaxiaoshou, OnMENULRkaxiaoshou)
ON_COMMAND(ID_MENU_LRtongzhidan, OnMENULRtongzhidan)
ON_COMMAND(ID_MEN_LRchuzhang, OnMENLRchuzhang)
ON_COMMAND(ID_MENU_LRwangjian, OnMENULRwangjian)
ON_COMMAND(ID_MENU_LRyucunzhuan, OnMENULRyucunzhuan)
ON_WM_ERASEBKGND()
ON_COMMAND(ID_LogNew, OnLogNew)
ON_COMMAND(ID_LogOut, OnLogOut)
ON_COMMAND(ID_MENU_JHchuzhang, OnMENUJHchuzhang)
ON_COMMAND(ID_MENU_JHkaxiaoshou, OnMENUJHkaxiaoshou)
	ON_COMMAND(ID_MENU_JHtongzhidan, OnMENUJHtongzhidan)
	ON_COMMAND(ID_MENU_GJchuzhang, OnMENUGJchuzhang)
	ON_COMMAND(ID_MENU_JHwangjian, OnMENUJHwangjian)
	ON_COMMAND(ID_MENU_JHyucun, OnMENUJHyucun)
	ON_COMMAND(ID_MENU_GJkaxiaoshou, OnMENUGJkaxiaoshou)
	ON_COMMAND(ID_MENU_GJtongzhidan, OnMENUGJtongzhidan)
	ON_COMMAND(ID_MENU_GJwangjian, OnMENUGJwangjian)
	ON_COMMAND(ID_MENU_GJyucunzhuan, OnMENUGJyucunzhuan)
	ON_COMMAND(ID_MEN_About, OnMENAbout)
	ON_COMMAND(ID_Creat_newuser, OnCreatnewuser)
ON_WM_MOUSEACTIVATE()
	ON_COMMAND(ID_Modify_psw, OnModifypsw)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDXlistDlg message handlers

BOOL CDXlistDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    app = (CDXlistApp *)AfxGetApp(); 
	// Add "About..." menu item to system menu.	
    m_bCreated=false;
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_menu.LoadMenu(IDR_MENU1);
    
	SetMenu(&m_menu);
	/*    
	LogIn  *m_dlg;
	m_dlg=new LogIn;
	m_dlg->Create(IDD_DIALOG_LogIn);
	m_dlg->ShowWindow(1);
	return TRUE; // 除非将焦点设置到控件，否则返回 TRUE
	*/
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDXlistDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDXlistDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDXlistDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



void CDXlistDlg::OnMENULRkaxiaoshou() 
{
	// TODO: Add your command handler code here
	
	if(app->User_Root==1 || app->User_Root==2)
	{
		Luru_kaxiaoshou L_kxs;
		L_kxs.DoModal();
	}else MessageBox("对不起，您没有执行此操作的权利！");
}

void CDXlistDlg::OnMENULRtongzhidan() 
{
	// TODO: Add your command handler code here
	if(app->User_Root==1 || app->User_Root==2)
	{
		Luru_tongzhiddan L_tzd;
		L_tzd.DoModal();
	}else MessageBox("对不起，您没有执行此操作的权利！");
}

void CDXlistDlg::OnMENLRchuzhang() 
{
	// TODO: Add your command handler code here
	if(app->User_Root==1 || app->User_Root==2)
	{
		Luru_chuzhang L_cz;
		L_cz.DoModal();
	}else MessageBox("对不起，您没有执行此操作的权利！");
		
}

void CDXlistDlg::OnMENULRwangjian() 
{
	// TODO: Add your command handler code here
	if(app->User_Root==1 || app->User_Root==2)
	{
		Luru_wangjian L_wj;
		L_wj.DoModal();
	}else MessageBox("对不起，您没有执行此操作的权利！");
}

void CDXlistDlg::OnMENULRyucunzhuan() 
{
	// TODO: Add your command handler code here
	if(app->User_Root==1 || app->User_Root==2)
	{
		Luru_yucunzhuan L_ycz;
		L_ycz.DoModal();
	}else MessageBox("对不起，您没有执行此操作的权利！");
}


BOOL CDXlistDlg::OnEraseBkgnd(CDC* pDC) 
{
	CRect rect;
	GetClientRect(&rect); 
	
	
	CBitmap m_pBmp;
	BITMAP bm;
	CDC dcMem;
	
	
	m_pBmp.LoadBitmap(IDB_BITMAP2);
	m_pBmp.GetBitmap(&bm);//得到位图尺寸
	
	
	dcMem.CreateCompatibleDC(pDC);
	CBitmap* pOldBitmap = dcMem.SelectObject(&m_pBmp);
	
	pDC->SetStretchBltMode(COLORONCOLOR);//这个模式不设置的话会导致图片严重失真
	pDC->StretchBlt(0,0,rect.Width() ,rect.Height(),
		&dcMem,0,0,bm.bmWidth,bm.bmHeight,SRCCOPY);
	dcMem.SelectObject(pOldBitmap); 
	
	return TRUE;
	
	
}



BOOL CDXlistDlg::PreTranslateMessage(MSG* pMsg) 
{
	
	// TODO: Add your specialized code here and/or call the base class
	if (!m_bCreated)// 初始值为false
	{
		m_bCreated = true;
		LogIn dlgLog;
		dlgLog.DoModal();
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

void CDXlistDlg::OnLogNew() 
{
	// TODO: Add your command handler code here
	

}

void CDXlistDlg::OnLogOut() 
{
	// TODO: Add your command handler code here
	CDXlistApp *app = (CDXlistApp *)AfxGetApp(); //生成指向应用程序类的指针 
    app->USer_name="";
	app->User_Root=0;
    LogIn lg;
	lg.DoModal();
}

void CDXlistDlg::OnMENUJHchuzhang() 
{
	// TODO: Add your command handler code here
	if(app->User_Root==1 || app->User_Root==3)
	{
		JiHe_chuzhang J_cz;
		J_cz.DoModal();
	}else MessageBox("对不起，您没有执行此操作的权利！");
}

void CDXlistDlg::OnMENUJHkaxiaoshou() 
{
	// TODO: Add your command handler code here
	if(app->User_Root==1 || app->User_Root==3)
	{
		JiHe_kaxiaoshou J_kxs;
		J_kxs.DoModal();
	}else MessageBox("对不起，您没有执行此操作的权利！");
}

void CDXlistDlg::OnMENUJHtongzhidan() 
{
	// TODO: Add your command handler code here
	if(app->User_Root==1 || app->User_Root==3)
	{
		JiHe_tongzhidan J_tzd;
		J_tzd.DoModal();
	}else MessageBox("对不起，您没有执行此操作的权利！");
}

void CDXlistDlg::OnMENUGJchuzhang() 
{
	// TODO: Add your command handler code here
	if(app->User_Root==1 || app->User_Root==4)
	{
	GuiJi_chuzhang GJ_cz;
		GJ_cz.DoModal();
	}else MessageBox("对不起，您没有执行此操作的权利！");
}

void CDXlistDlg::OnMENUJHwangjian() 
{
	// TODO: Add your command handler code here
	if(app->User_Root==1 || app->User_Root==3)
	{
		JiHe_wangjian J_wj;
		J_wj.DoModal();
	}else MessageBox("对不起，您没有执行此操作的权利！");
}

void CDXlistDlg::OnMENUJHyucun() 
{
	// TODO: Add your command handler code here
	if(app->User_Root==1 || app->User_Root==3)
	{
		JiHe_yucunzhuan J_ycz;
		J_ycz.DoModal();
	}else MessageBox("对不起，您没有执行此操作的权利！");
}

void CDXlistDlg::OnMENUGJkaxiaoshou() 
{
	// TODO: Add your command handler code here
	if(app->User_Root==1 || app->User_Root==4)
	{
		GuiJi_kaxiaoshou GJ_kxs;
		GJ_kxs.DoModal();
	}else MessageBox("对不起，您没有执行此操作的权利！");
}

void CDXlistDlg::OnMENUGJtongzhidan() 
{
	// TODO: Add your command handler code here
		if(app->User_Root==1 || app->User_Root==4)
	{
		GuiJi_tongzhidan GJ_tzd;
		GJ_tzd.DoModal();
	}else MessageBox("对不起，您没有执行此操作的权利！");
}

void CDXlistDlg::OnMENUGJwangjian() 
{
	// TODO: Add your command handler code here
		if(app->User_Root==1 || app->User_Root==4)
	{
		GuiJi_wangjian GJ_wj;
		GJ_wj.DoModal();
	}else MessageBox("对不起，您没有执行此操作的权利！");
}

void CDXlistDlg::OnMENUGJyucunzhuan() 
{
	// TODO: Add your command handler code here
		if(app->User_Root==1 || app->User_Root==4)
	{
		GuiJi_yucunzhuan GJ_ycz;
		GJ_ycz.DoModal();
	}else MessageBox("对不起，您没有执行此操作的权利！");
}

void CDXlistDlg::OnMENAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg about;
		about.DoModal();
}

void CDXlistDlg::OnCreatnewuser() 
{
	// TODO: Add your command handler code here
	if(app->User_Root==1)
	{
		User_Root u_r;
		u_r.DoModal();
	}else
	{
		MessageBox("对不起，您没有注册新用户的权利！");
	}
}

void CDXlistDlg::OnModifypsw() 
{
	// TODO: Add your command handler code here

		Modify_psw mdf_p;
		mdf_p.DoModal();

}

void CDXlistDlg::OnModifyusertype() 
{
	// TODO: Add your command handler code here
	
}
