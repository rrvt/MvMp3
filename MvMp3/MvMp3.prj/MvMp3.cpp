// MvMp3.cpp : Defines the class behaviors for the application.


#include "stdafx.h"
#include "MvMp3.h"
#include "About.h"
#include "ExtraResource.h"
#include "IniFile.h"
#include "MainFrame.h"
#include "NotePad.h"
#include "Options.h"
#include "MvMp3Doc.h"
#include "MvMp3View.h"


MvMp3 theApp;                       // The one and only MvMp3 object
IniFile     iniFile;


// MvMp3

BEGIN_MESSAGE_MAP(MvMp3, CWinAppEx)
  ON_COMMAND(ID_FILE_PRINT_SETUP, &OnFilePrintSetup)
  ON_COMMAND(ID_Help,             &OnHelp)
  ON_COMMAND(ID_App_About,        &OnAppAbout)
END_MESSAGE_MAP()


// MvMp3 initialization

BOOL MvMp3::InitInstance() {

  CWinAppEx::InitInstance();

  iniFile.setAppDataPath(m_pszHelpFilePath, *this);

  notePad.clear();

  SetRegistryKey(appID);

  LoadStdProfileSettings(0);  // Load standard INI file options (including MRU)

  // Register the application's document templates.  Document templates
  // serve as the connection between documents, frame windows and views

  CSingleDocTemplate* pDocTemplate;

  pDocTemplate = new CSingleDocTemplate(
    IDR_MAINFRAME,
    RUNTIME_CLASS(MvMp3Doc),
    RUNTIME_CLASS(MainFrame),       // main SDI frame window
    RUNTIME_CLASS(MvMp3View));

  if (!pDocTemplate) return FALSE;

  AddDocTemplate(pDocTemplate);

//  EnableShellOpen(); RegisterShellFileTypes(TRUE);       // Enable DDE Execute open

  // Parse command line for standard shell commands, DDE, file open

  CCommandLineInfo cmdInfo;   ParseCommandLine(cmdInfo);

  // Dispatch commands specified on the command line.  Will return FALSE if
  // app was launched with /RegServer, /Register, /Unregserver or /Unregister.

  if (!ProcessShellCommand(cmdInfo)) return FALSE;

  setAppName(_T("Move Mp3")); setTitle(_T("Move Files"));

  view()->setFont(_T("Arial"), 12.0);

  options.load();    view()->setOrientation(options.orient);

  m_pMainWnd->ShowWindow(SW_SHOW);   m_pMainWnd->UpdateWindow();   return TRUE;
  }



void MvMp3::OnFilePrintSetup() {
PrtrOrient orient;

  view()->setPrntrOrient(getDevMode());

    CWinApp::OnFilePrintSetup();

  orient = view()->getPrntrOrient(getDevMode());

  options.setOrient(orient);   view()->setOrientation(options.orient);
  }


int MvMp3::ExitInstance() {

#ifdef DebugMemoryLeaks
  _CrtDumpMemoryLeaks();
#endif

  return CApp::ExitInstance();
  }


void MvMp3::OnHelp() {
String topic = m_pszHelpFilePath; topic += _T(">Introduction");

  ::HtmlHelp(m_pMainWnd->m_hWnd, topic,  HH_DISPLAY_TOC, 0);
  }


void MvMp3::OnAppAbout() {CAboutDlg aboutDlg; aboutDlg.DoModal();}

