

MvMp3.chm : *.htm MvMp3.hhp MvMp3.hhc App.css
  -1 "C:\Program Files (x86)\HTML Help Workshop\hhc" MvMp3


Clean.cln    :
  @echo "Cleaning"
  cd $(MAKEDIR)
  if exist MvMp3.chm del /F MvMp3.chm


$(TgtFolder)/MvMp3.chm : MvMp3.chm
  copy $(MAKEDIR)\MvMp3.chm  $(MAKEDIR)\..\$(TgtFolder)\MvMp3.chm


$(TgtFolder)/Clean.cln    : Clean.cln
  cd $(MAKEDIR)\..\$(TgtFolder)
  if exist MvMp3.chm del /F MvMp3.chm
  cd $(MAKEDIR)


$(TgtFolder)/Rebuild.rbd : $(TgtFolder)/Clean.cln $(TgtFolder)/MvMp3.chm



