// Prefix Dialog
//

#include "stdafx.h"
#include "MvMp3.h"
#include "PrefixDlg.h"


// PrefixDlg dialog

IMPLEMENT_DYNAMIC(PrefixDlg, CDialog)

PrefixDlg::PrefixDlg(CWnd* pParent) : CDialog(PrefixDlg::IDD, pParent) { }

PrefixDlg::~PrefixDlg() { }


void PrefixDlg::DoDataExchange(CDataExchange* pDX) {
  CDialog::DoDataExchange(pDX);
  DDX_Text(pDX, IDC_Path, path);
  DDX_Text(pDX, IDC_Prefix, prefix);
  }


BEGIN_MESSAGE_MAP(PrefixDlg, CDialog)
END_MESSAGE_MAP()

