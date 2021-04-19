// Get PrefixDlg for files

#pragma once
#include "Resource.h"


// Prefix dialog

class PrefixDlg : public CDialog {
  DECLARE_DYNAMIC(PrefixDlg)

public:

CString prefix;
CString path;

  PrefixDlg(CWnd* pParent = NULL);   // standard constructor
  virtual ~PrefixDlg();

// Dialog Data
  enum { IDD = IDD_PREFIX };

protected:
  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

  DECLARE_MESSAGE_MAP()
};
