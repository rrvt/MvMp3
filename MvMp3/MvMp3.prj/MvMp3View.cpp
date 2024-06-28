// MvMp3View.cpp : implementation of the MvMp3View class


#include "stdafx.h"
#include "MvMp3View.h"
#include "MvMp3.h"
#include "MvMp3Doc.h"
#include "OptionsDlg.h"
#include "Resource.h"
#include "Resources.h"
#include "RptOrientDlgOne.h"


// MvMp3View

IMPLEMENT_DYNCREATE(MvMp3View, CScrView)

BEGIN_MESSAGE_MAP(MvMp3View, CScrView)
  ON_COMMAND(ID_Options,     &onOptions)
  ON_COMMAND(ID_Orientation, &onRptOrietn)
END_MESSAGE_MAP()


MvMp3View::MvMp3View() noexcept {
ResourceData res;
String       pn;
  if (res.getProductName(pn)) prtNote.setTitle(pn);
  }


BOOL MvMp3View::PreCreateWindow(CREATESTRUCT& cs) {

  return CScrView::PreCreateWindow(cs);
  }


void MvMp3View::onOptions() {
OptionsDlg dlg;

  if (printer.name.isEmpty()) printer.load(0);

  if (dlg.DoModal() == IDOK) pMgr.setFontScale(printer.scale);
  }


void MvMp3View::onRptOrietn() {
RptOrietnDlg dlg;

  dlg.lbl00 = _T("Media:");

  dlg.ntpd = printer.toStg(prtNote.prtrOrietn);

  if (dlg.DoModal() == IDOK) {prtNote.prtrOrietn = printer.toOrient(dlg.ntpd);   saveNoteOrietn();}
  }


// Perpare output (i.e. report) then start the output with the call to SCrView

void MvMp3View::onBeginPrinting() {prtNote.onBeginPrinting(*this);}


void MvMp3View::onDisplayOutput() {dspNote.display(*this);}


// The footer is injected into the printed output, so the output goes directly to the device.
// The output streaming functions are very similar to NotePad's streaming functions so it should
// not be a great hardship to construct a footer.

void MvMp3View::printFooter(DevBase& dev, int pageNo) {
  switch(doc()->dataSrc()) {
    case NotePadSrc : prtNote.prtFooter(dev, pageNo);  break;
    }
  }



void MvMp3View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo) {

  CScrView::OnEndPrinting(pDC, pInfo);

  switch(doc()->dataSrc()) {
    case NotePadSrc : break;
    }
  }


void MvMp3View::OnSetFocus(CWnd* pOldWnd) {

  CScrView::OnSetFocus(pOldWnd);

  switch(doc()->dataSrc()) {
    case NotePadSrc : break;
    }
  }


// MvMp3View diagnostics

#ifdef _DEBUG
void MvMp3View::AssertValid() const          {CScrollView::AssertValid();}
void MvMp3View::Dump(CDumpContext& dc) const {CScrollView::Dump(dc);}
                                                                    // non-debug version is inline
MvMp3Doc* MvMp3View::GetDocument() const
           {ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(MvMp3Doc))); return (MvMp3Doc*)m_pDocument;}
#endif //_DEBUG
