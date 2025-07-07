

MvMp3.chm : *.htm MvMp3.hhp MvMp3.hhc App.css
  -1 "C:\Program Files (x86)\HTML Help Workshop\hhc" MvMp3


Clean.cln    :
  @echo "Cleaning"
  cd $(MAKEDIR)
  if exist MvMp3.chm del /F MvMp3.chm


Release/MvMp3.chm : MvMp3.chm
  copy $(MAKEDIR)\MvMp3.chm  $(MAKEDIR)\..\Release\MvMp3.chm


Release/Clean.cln    : Clean.cln
  cd $(MAKEDIR)\..\Release
  if exist MvMp3.chm del /F MvMp3.chm
  cd $(MAKEDIR)


Debug/MvMp3.chm : MvMp3.chm
  copy $(MAKEDIR)\MvMp3.chm  $(MAKEDIR)\..\Debug\MvMp3.chm


Debug/Clean.cln    : Clean.cln
  cd $(MAKEDIR)\..\Debug
  if exist MvMp3.chm del /F MvMp3.chm
  cd $(MAKEDIR)


Release/Rebuild.rbd : Release/Clean.cln Release/MvMp3.chm


Debug/Rebuild.rbd   : Debug/Clean.cln Debug/MvMp3.chm


