////////////////////////////////////////////////////////////////////////////////
//
// Patient.h: Header file for class that holds a collection of values specific
// to determining how to display data for an individual prostate cancer patient.
//
// Author:    Steve Chall, RENCI
//
// Primary collaborators: 
//            Joseph Lo, Shiva Das, Vorakarn Chanyavanich, Duke Medical Center
//
// Copyright: The Renaissance Computing Institute (RENCI)
//
// License:   Licensed under the RENCI Open Source Software License v. 1.0
//
//            See http://www.renci.org/resources/open-source-software-license
//            for details.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef PATIENT_H
#define PATIENT_H


#include <QString>


class Patient
{

public:
  Patient();
  Patient(int n);
  ~Patient();

  enum
  {
    defaultPatientNumber = 12,  // Arbitrary mid value for prototype
    defaultGantryAngle   = 180  // Vorakarn's recommendation
  };

  enum SliceOrientation
  {
    X,  // Sagittal
    Y,  // Coronal
    Z   // Axial
  };

  int getNumber() { return number; };
  void setNumber(int n) { number = n; };

  int getIndex() { return index; };
  void setIndex(int i) { index = i; };

  int getSliceMin() { return sliceMin; };
  void setSliceMin(int min) { sliceMin = min; };

  int getSliceMax() { return sliceMax; };
  void setSliceMax(int max) { sliceMax = max; };

  SliceOrientation getSliceOrientation() { return sliceOrientation; };
  void setSliceOrientation(SliceOrientation orientation)
    { sliceOrientation = orientation; };

  QString &getDataDir() { return this->dataDir; };
  void setDataDir(const QString &dir) { this->dataDir = dir; };

  QString getPathToCTData();
  void setPathToCTData(const QString &path);

  QString getPathToDVHData();
  void setPathToDVHData(const QString &path);

  int getPTVSize() { return PTVSize; };
  int getRectumSize() { return rectumSize; };
  int getBladderSize() { return bladderSize; };
  int getPTVPlusRectum() { return PTVPlusRectum; };
  int getPTVPlusBladder() { return PTVPlusBladder; };
  int getPTVPlusRectumPlusBladder() { return PTVPlusRectumPlusBladder; };
  void setPTVSize(int s) { PTVSize = s; };
  void setRectumSize(int s) { rectumSize = s; };
  void setBladderSize(int s) { bladderSize = s; };
  void setPTVPlusRectum(int ppr) { PTVPlusRectum = ppr; };
  void setPTVPlusBladder(int ppb) { PTVPlusBladder = ppb; };
  void setPTVPlusRectumPlusBladder(int pprpb) { PTVPlusRectumPlusBladder = pprpb; };

protected:
  int number; // Patient number which is data-dependent
  int index;  // Index into the list of patients for a given institution:  application dependent
  int sliceMin;
  int sliceMax;
  SliceOrientation sliceOrientation;

  QString dataDir;
  QString projectionImagePath;
  QString CTDataPath;
  QString DVHDataPath;

  bool isShowingFemoralHeads;

  int PTVSize;
  int rectumSize;
  int bladderSize;
  int PTVPlusRectum;
  int PTVPlusBladder;
  int PTVPlusRectumPlusBladder;

private:
  Patient(const Patient&);        // Not implemented.
  void operator=(const Patient&); // Not implemented.
};

#endif