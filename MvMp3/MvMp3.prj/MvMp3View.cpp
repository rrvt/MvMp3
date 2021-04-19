// MvMp3View.cpp : implementation of the MvMp3View class


#include "stdafx.h"
#include "MvMp3View.h"
#include "MvMp3.h"
#include "MvMp3Doc.h"
#include "Options.h"
#include "Resources.h"


// MvMp3View

IMPLEMENT_DYNCREATE(MvMp3View, CScrView)

BEGIN_MESSAGE_MAP(MvMp3View, CScrView)
END_MESSAGE_MAP()


MvMp3View::MvMp3View() noexcept : dspNote( dMgr.getNotePad()), prtNote( pMgr.getNotePad()) {
ResourceData res;
String       pn;
  if (res.getProductName(pn)) prtNote.setTitle(pn);
  }


BOOL MvMp3View::PreCreateWindow(CREATESTRUCT& cs) {

  return CScrView::PreCreateWindow(cs);
  }


void MvMp3View::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) {
uint   x;
double topMgn   = options.topMargin.stod(x);
double leftMgn  = options.leftMargin.stod(x);
double rightMgn = options.rightMargin.stod(x);
double botMgn   = options.botMargin.stod(x);

  setMgns(leftMgn,  topMgn,  rightMgn, botMgn, pDC);   CScrView::OnPrepareDC(pDC, pInfo);
  }


// Perpare output (i.e. report) then start the output with the call to SCrView

void MvMp3View::onPrepareOutput(bool printing) {
DataSource ds = doc()->dataSrc();

  if (printing)
    switch(ds) {
      case NotePadSrc : prtNote.print(*this);  break;
      }

  else
    switch(ds) {
      case NotePadSrc : dspNote.display(*this);  break;
      }


  CScrView::onPrepareOutput(printing);
  }


void MvMp3View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) {

  switch(doc()->dataSrc()) {
    case NotePadSrc : setOrientation(options.orient); break;    // Setup separate Orientation?
    case StoreSrc   : setOrientation(options.orient); break;
    }
  setPrntrOrient(theApp.getDevMode(), pDC);   CScrView::OnBeginPrinting(pDC, pInfo);
  }


// The footer is injected into the printed output, so the output goes directly to the device.
// The output streaming functions are very similar to NotePad's streaming functions so it should not
// be a great hardship to construct a footer.

void MvMp3View::printFooter(Device& dev, int pageNo) {
  switch(doc()->dataSrc()) {
    case NotePadSrc : prtNote.footer(dev, pageNo);  break;
    }
  }



void MvMp3View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo) {

  CScrView::OnEndPrinting(pDC, pInfo);

  switch(doc()->dataSrc()) {
    case NotePadSrc : break;
    case StoreSrc   : break;
    }
  }


void MvMp3View::OnSetFocus(CWnd* pOldWnd) {

  CScrView::OnSetFocus(pOldWnd);

  switch(doc()->dataSrc()) {
    case NotePadSrc : break;
    case StoreSrc   : break;
    }
  }


// MvMp3View diagnostics

#ifdef _DEBUG

void MvMp3View::AssertValid() const {CScrollView::AssertValid();}

void MvMp3View::Dump(CDumpContext& dc) const {CScrollView::Dump(dc);}
                                             // non-debug version is inline
MvMp3Doc* MvMp3View::GetDocument() const
  {ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(MvMp3Doc))); return (MvMp3Doc*)m_pDocument;}

#endif //_DEBUG
