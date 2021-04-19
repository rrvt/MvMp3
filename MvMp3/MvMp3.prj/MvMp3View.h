// MvMp3View.h : interface of the MvMp3View class


#pragma once
#include "CScrView.h"
#include "NotePadRpt.h"


class MvMp3Doc;


class MvMp3View : public CScrView {

NotePadRpt dspNote;
NotePadRpt prtNote;

protected: // create from serialization only

  MvMp3View() noexcept;

  DECLARE_DYNCREATE(MvMp3View)

public:

  virtual ~MvMp3View() { }

  virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

  virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
  virtual void onPrepareOutput(bool printing);

  virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
  virtual void printFooter(Device& dev, int pageNo);
  virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

  MvMp3Doc* GetDocument() const;

public:

#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

public:

  DECLARE_MESSAGE_MAP()

  afx_msg void OnSetFocus(CWnd* pOldWnd);
  };


#ifndef _DEBUG  // debug version in MvMp3View.cpp
inline MvMp3Doc* MvMp3View::GetDocument() const
   { return reinterpret_cast<MvMp3Doc*>(m_pDocument); }
#endif

