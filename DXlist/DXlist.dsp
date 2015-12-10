# Microsoft Developer Studio Project File - Name="DXlist" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=DXlist - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "DXlist.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DXlist.mak" CFG="DXlist - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DXlist - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /profile /machine:I386
# Begin Target

# Name "DXlist - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Add_Delet.cpp
# End Source File
# Begin Source File

SOURCE=.\ADOconn.cpp
# End Source File
# Begin Source File

SOURCE=.\Delete.cpp
# End Source File
# Begin Source File

SOURCE=.\DXlist.cpp
# End Source File
# Begin Source File

SOURCE=.\DXlist.rc
# End Source File
# Begin Source File

SOURCE=.\DXlistDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GuiJi_chuzhang.cpp
# End Source File
# Begin Source File

SOURCE=.\GuiJi_kaxiaoshou.cpp
# End Source File
# Begin Source File

SOURCE=.\GuiJi_tongzhidan.cpp
# End Source File
# Begin Source File

SOURCE=.\GuiJi_wangjian.cpp
# End Source File
# Begin Source File

SOURCE=.\GuiJi_yucunzhuan.cpp
# End Source File
# Begin Source File

SOURCE=.\JiHe_CHECK.cpp
# End Source File
# Begin Source File

SOURCE=.\JiHe_chuzhang.cpp
# End Source File
# Begin Source File

SOURCE=.\JiHe_kaxiaoshou.cpp
# End Source File
# Begin Source File

SOURCE=.\JiHe_tongzhidan.cpp
# End Source File
# Begin Source File

SOURCE=.\JiHe_wangjian.cpp
# End Source File
# Begin Source File

SOURCE=.\JiHe_yucunzhuan.cpp
# End Source File
# Begin Source File

SOURCE=.\LogIn1.cpp
# End Source File
# Begin Source File

SOURCE=.\Luru_chuzhang.cpp
# End Source File
# Begin Source File

SOURCE=.\Luru_kaxiaoshou.cpp
# End Source File
# Begin Source File

SOURCE=.\LuRu_kxs_Add.cpp
# End Source File
# Begin Source File

SOURCE=.\LuRu_kxs_delet.cpp
# End Source File
# Begin Source File

SOURCE=.\Luru_tongzhiddan.cpp
# End Source File
# Begin Source File

SOURCE=.\LuRu_tzd_Add.cpp
# End Source File
# Begin Source File

SOURCE=.\LuRu_tzd_Delet.cpp
# End Source File
# Begin Source File

SOURCE=.\Luru_wangjian.cpp
# End Source File
# Begin Source File

SOURCE=.\LuRu_wj_Add.cpp
# End Source File
# Begin Source File

SOURCE=.\LuRu_wj_Delet.cpp
# End Source File
# Begin Source File

SOURCE=.\LuRu_ycz_Add.cpp
# End Source File
# Begin Source File

SOURCE=.\LuRu_ycz_Delete.cpp
# End Source File
# Begin Source File

SOURCE=.\Luru_yucunzhuan.cpp
# End Source File
# Begin Source File

SOURCE=.\Modify_psw.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\User_Root.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Add_Delet.h
# End Source File
# Begin Source File

SOURCE=.\ADOconn.h
# End Source File
# Begin Source File

SOURCE=.\Delete.h
# End Source File
# Begin Source File

SOURCE=.\DXlist.h
# End Source File
# Begin Source File

SOURCE=.\DXlistDlg.h
# End Source File
# Begin Source File

SOURCE=.\GuiJi_chuzhang.h
# End Source File
# Begin Source File

SOURCE=.\GuiJi_kaxiaoshou.h
# End Source File
# Begin Source File

SOURCE=.\GuiJi_tongzhidan.h
# End Source File
# Begin Source File

SOURCE=.\GuiJi_wangjian.h
# End Source File
# Begin Source File

SOURCE=.\GuiJi_yucunzhuan.h
# End Source File
# Begin Source File

SOURCE=.\JiHe_CHECK.h
# End Source File
# Begin Source File

SOURCE=.\JiHe_chuzhang.h
# End Source File
# Begin Source File

SOURCE=.\JiHe_kaxiaoshou.h
# End Source File
# Begin Source File

SOURCE=.\JiHe_tongzhidan.h
# End Source File
# Begin Source File

SOURCE=.\JiHe_wangjian.h
# End Source File
# Begin Source File

SOURCE=.\JiHe_yucunzhuan.h
# End Source File
# Begin Source File

SOURCE=.\LogIn1.h
# End Source File
# Begin Source File

SOURCE=.\Luru_chuzhang.h
# End Source File
# Begin Source File

SOURCE=.\Luru_kaxiaoshou.h
# End Source File
# Begin Source File

SOURCE=.\LuRu_kxs_Add.h
# End Source File
# Begin Source File

SOURCE=.\LuRu_kxs_delet.h
# End Source File
# Begin Source File

SOURCE=.\Luru_tongzhiddan.h
# End Source File
# Begin Source File

SOURCE=.\LuRu_tzd_Add.h
# End Source File
# Begin Source File

SOURCE=.\LuRu_tzd_Delet.h
# End Source File
# Begin Source File

SOURCE=.\Luru_wangjian.h
# End Source File
# Begin Source File

SOURCE=.\LuRu_wj_Add.h
# End Source File
# Begin Source File

SOURCE=.\LuRu_wj_Delet.h
# End Source File
# Begin Source File

SOURCE=.\LuRu_ycz_Add.h
# End Source File
# Begin Source File

SOURCE=.\LuRu_ycz_Delete.h
# End Source File
# Begin Source File

SOURCE=.\Luru_yucunzhuan.h
# End Source File
# Begin Source File

SOURCE=.\Modify_psw.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\User_Root.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=".\res\16cd940057e70bc756118232bee45247 (1).ico"
# End Source File
# Begin Source File

SOURCE=.\res\16cd940057e70bc756118232bee45247.ico
# End Source File
# Begin Source File

SOURCE=.\res\3227203_135018057_2.ico
# End Source File
# Begin Source File

SOURCE=.\res\DXlist.ico
# End Source File
# Begin Source File

SOURCE=.\res\DXlist.rc2
# End Source File
# Begin Source File

SOURCE=.\res\main.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\Master.manifest
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
