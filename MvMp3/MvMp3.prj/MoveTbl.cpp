// Move Table -- contains all the old and new file names and paths


#include "stdafx.h"
#include "MoveTbl.h"
#include "MessageBox.h"
#include "NotePad.h"
#include "PrefixDlg.h"


MoveTbl moveTbl;


bool MoveTbl::findFiles(TCchar* path) {
CFileFind ff;
String    pth = path;  pth += _T("\\*.*");
bool      rslt;
bool      last;

  for (rslt = ff.FindFile(pth), last = !ff.FindNextFile(); rslt; last = !ff.FindNextFile()) {
    if (ff.IsDots()) continue;

    String    p = ff.GetFilePath().GetBuffer();
    MoveDatum dtm;   dtm.path = p;

    if (ff.IsDirectory()) {findFiles(p); dtm.directory = true;}

    else dtm.directory = false;

    data += dtm;

    if (last) break;
    }

  return !moveTbl.isEmpty();
  }


void MoveTbl::moveFiles() {
PrefixDlg dlg;
String    prefix;

  dlg.path = moveTbl.path;

  if (dlg.DoModal() != IDOK) return;

  prefix = dlg.prefix; prefix.trim();

  moveTbl.moveFiles(prefix);
  }


void MoveTbl::moveFiles(TCchar* prfx) {
MvIter     iter(*this);
MoveDatum* dtm;
int        i;
int        j;
String     prefix = prfx;

  for (i = j = 1, dtm = iter(); dtm; j++, dtm = iter++) {

    if (dtm->directory) {
      if (_trmdir(dtm->path))
                         {String msg = _T("Unable to delete directory ") + dtm->path;   messageBox(msg);}
      i++; j = 0; continue;
      }


    String s; s.format(_T("%s-%02i-%03i.mp3"), prefix.str(), i, j);

    s = path + s;

    if (_trename(dtm->path, s)) {
      String msg = _T("Unable to move: ") + dtm->path + _T(" to ") + s;
      messageBox(msg); continue;
      }

    notePad << dtm->path << _T(" ==> ") << s << nCrlf;
    }
  }


void MoveTbl::display() {
MvIter     iter(*this);
MoveDatum* dtm;

  for (dtm = iter(); dtm; dtm = iter++) {

    notePad << dtm->path;    if (dtm->directory) notePad << nTab << _T("Directory");
    notePad << nCrlf;
    }
  }

