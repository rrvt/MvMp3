// MvMp3.h : main header file for the MvMp3 application

#pragma once
#include "CApp.h"


class MvMp3Doc;
class MvMp3View;
class MainFrame;


// MvMp3:
// See MvMp3.cpp for the implementation of this class

class MvMp3 : public CApp {

public:

               MvMp3() noexcept : CApp(this) { }

  virtual BOOL InitInstance();
  virtual int  ExitInstance();

          MvMp3Doc*  doc()  {return (MvMp3Doc*)  CApp::getDoc();}
          MvMp3View* view() {return (MvMp3View*) CApp::getView();}
          MainFrame*       mainFrm() {return (MainFrame*) m_pMainWnd;}

  DECLARE_MESSAGE_MAP()

  afx_msg void OnFilePrintSetup();
  afx_msg void OnAppAbout();
  afx_msg void OnHelp();
  };


extern MvMp3 theApp;

inline void         invalidate() {theApp.invalidate();}
inline MvMp3Doc*  doc()  {return theApp.doc();}
inline MvMp3View* view() {return theApp.view();}

