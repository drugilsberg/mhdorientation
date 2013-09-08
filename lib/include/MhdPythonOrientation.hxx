#ifndef MHDPYTHONORIENTATION_HXX
#define MHDPYTHONORIENTATION_HXX 1

#include<fstream>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<utility>

#define PI 3.14159265

namespace Mhd{

  using std::vector;
  using std::cerr;
  using std::endl;
  using std::string;
  using std::pair;
  using std::asin;
  using std::atan2;
  using std::ostream;
  using std::ofstream;
  using std::ifstream;

  class MhdPythonOrientation{

    private:
      vector<float> TransformMatrix;
      vector<float> Offset;
      vector<float> CenterOfRotation;
      string AnatomicalOrientation;
      string ObjectType;
      size_t NDims;
      size_t CompressedDataSize;
      string BinaryData;
      string BinaryDataByteOrderMSB;
      string CompressedData;
      vector<float> ElementSpacing;
      vector<size_t> DimSize;
      string ElementType;
      string ElementDataFile;
      pair< vector<float>, vector<float> > Angles;
    public:
      void OrientationReader(char* InputFile);//file reader
      void OrientationWriter(char* OutputFile);//file writer
      void ConvertToRas(size_t i=1);//orientation converter
      void ComputeAngles();//angles
      void ComputeRotation(float* angles);//rotation
      float R(size_t i,size_t j){return TransformMatrix[(i*3)+j];}
      float O(size_t i){return Offset[i];}
      float C(size_t i){return CenterOfRotation[i];}
  };

}
#endif
