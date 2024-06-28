// Move Table -- contains all the old and new file names and paths


#pragma once
#include "Expandable.h"
#include "IterT.h"


class MoveDatum {
public:

String path;
bool   directory;


  MoveDatum() : directory(false) { }
  MoveDatum(MoveDatum& md) {copy(md);}
 ~MoveDatum() { }

  MoveDatum& operator= (MoveDatum& md) {copy(md); return *this;}

private:

  void copy(MoveDatum& md) {path = md.path; directory = md.directory;}
  };


class MoveTbl;
typedef IterT<MoveTbl, MoveDatum> MvIter;


class MoveTbl {

Expandable<MoveDatum, 2> data;

String                   path;

public:

  MoveTbl() { }
 ~MoveTbl() { }

  void add(MoveDatum& md) {data += md;}

  bool isEmpty() {return nData() == 0;}

  void setTarget(TCchar* pth) {path = pth;}

  bool findFiles(TCchar* path);

  void moveFiles();

  void display();

private:

  void moveFiles(TCchar* prfx);

  // returns either a pointer to data (or datum) at index i in array or zero

  MoveDatum* datum(int i) {return 0 <= i && i < nData() ? &data[i] : 0;}       // or data[i].p

  int   nData()      {return data.end();}                  // returns number of data items in array

  void  removeDatum(int i) {if (0 <= i && i < nData()) data.del(i);}

  friend typename MvIter;
  };


extern MoveTbl moveTbl;

