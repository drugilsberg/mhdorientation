#include"MhdPythonOrientation.hxx"


//Declaration of the function that will be exported to be used in python interface
extern "C" {
  Mhd::MhdPythonOrientation *MhdOrientation_Python(){return new Mhd::MhdPythonOrientation();}
  void MhdOrientation_OrientationReader(Mhd::MhdPythonOrientation* mo, char* InputFile) {mo->OrientationReader(InputFile);}
  void MhdOrientation_OrientationWriter(Mhd::MhdPythonOrientation* mo, char* OutputFile) {mo->OrientationWriter(OutputFile);}
  void MhdOrientation_ConvertToRas(Mhd::MhdPythonOrientation* mo,size_t i) {mo->ConvertToRas(i);}
  void MhdOrientation_ComputeAngles(Mhd::MhdPythonOrientation* mo) {mo->ComputeAngles();}
  void MhdOrientation_ComputeRotation(Mhd::MhdPythonOrientation* mo, float* angles){mo->ComputeRotation(angles);}
  void MhdOrientation_R(Mhd::MhdPythonOrientation* mo,size_t i,size_t j){mo->R(i,j);}
  void MhdOrientation_O(Mhd::MhdPythonOrientation* mo,size_t i){mo->O(i);}
  void MhdOrientation_C(Mhd::MhdPythonOrientation* mo,size_t i){mo->C(i);}
}
