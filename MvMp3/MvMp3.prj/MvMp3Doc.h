// MvMp3Doc.h : interface of the MvMp3Doc class


#pragma once
#include "CDoc.h"
#include "MainFrame.h"
#include "TBComboBox.h"
#include "TBEditBox.h"


enum DataSource {NotePadSrc, StoreSrc, FontSrc};


class MvMp3Doc : public CDoc {

DataSource  dataSource;

protected: // create from serialization only

  MvMp3Doc() noexcept;
  DECLARE_DYNCREATE(MvMp3Doc)

public:

  virtual ~MvMp3Doc();

  virtual BOOL OnNewDocument();

  DataSource dataSrc() {return dataSource;}
  void       display(DataSource ds);

  virtual void serialize(Archive& ar);

#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

private:

//  bool findFiles(TCchar* path);

// Generated message map functions

protected:

  DECLARE_MESSAGE_MAP()

public:

  afx_msg void onNewMove();
  afx_msg void onRenameFiles();
  afx_msg void OnOptions();
  };
