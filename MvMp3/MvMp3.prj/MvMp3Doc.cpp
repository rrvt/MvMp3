// MvMp3Doc.cpp : implementation of the MvMp3Doc class


#include "stdafx.h"
#include "MvMp3Doc.h"
#include "ResourceExtra.h"
#include "filename.h"
#include "GetPathDlg.h"
#include "MessageBox.h"
#include "MoveTbl.h"
#include "NotePad.h"
#include "Resource.h"
#include "MvMp3.h"
#include "MvMp3View.h"
#include "MyToolBar.h"


//static int getDisk(String name, int k);


// MvMp3Doc

IMPLEMENT_DYNCREATE(MvMp3Doc, CDoc)

BEGIN_MESSAGE_MAP(MvMp3Doc, CDoc)
  ON_COMMAND(ID_NewMove,     &onNewMove)
  ON_COMMAND(ID_RenameFiles, &onRenameFiles)
END_MESSAGE_MAP()


// MvMp3Doc construction/destruction

MvMp3Doc::MvMp3Doc() noexcept : dataSource(NotePadSrc) { }

MvMp3Doc::~MvMp3Doc() { }


BOOL MvMp3Doc::OnNewDocument() {return CDocument::OnNewDocument();}


void MvMp3Doc::onNewMove() {
String path;

  notePad.clear();

  if (getDirPathDlg(TEXT("Set Directory"), path))
                {moveTbl.setTarget(path + _T("\\"));   moveTbl.findFiles(path);   moveTbl.display();}
  display(NotePadSrc);
  }


void MvMp3Doc::onRenameFiles() {notePad.clear();   moveTbl.moveFiles();   display(NotePadSrc);}


void MvMp3Doc::display(DataSource ds) {dataSource = ds; invalidate();}


// UglyDoc serialization

void MvMp3Doc::serialize(Archive& ar) {

  if (ar.isStoring())
    switch(dataSource) {
      case NotePadSrc : notePad.archive(ar); return;
      default         : return;
      }

  else
    switch(dataSource) {
      case NotePadSrc :
      default         : return;
      }
  }


// MvMp3Doc diagnostics

#ifdef _DEBUG
void MvMp3Doc::AssertValid() const
{
  CDocument::AssertValid();
}

void MvMp3Doc::Dump(CDumpContext& dc) const
{
  CDocument::Dump(dc);
}
#endif //_DEBUG

