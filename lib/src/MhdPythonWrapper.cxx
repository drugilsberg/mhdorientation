/**
 * @file MhdPythonWrapper.cxx
 * @brief Implementation of the wrapping in Python
 * @author Matteo Manica
 * @date 2013-09-08
 */

/* This program is free software: you can redistribute it and/or modify 
 *  it under the terms of the GNU General Public License as published by 
 *  the Free Software Foundation, either version 3 of the License, or 
 *  (at your option) any later version. 
 *  
 *  This program is distributed in the hope that it will be useful, 
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of 
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 *  GNU General Public License for more details. 
 *  
 *  You should have received a copy of the GNU General Public License 
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include"MhdPythonOrientation.hxx"


/**
 * @brief Declaration of the functions that will be exported in Python using ctypes
 */
extern "C" {
  /**
   * @brief Constructor of MhdPythonOrientation
   *
   * @return Pointer to MhdPythonOrientation
   */
  Mhd::MhdPythonOrientation *MhdOrientation_Python(){return new Mhd::MhdPythonOrientation();}
  /**
   * @brief MhdPythonOrientation::OrientationReader in Python
   *
   * @param mo Object MhdPythonOrientation
   * @param InputFile Input .mhd file
   */
  void MhdOrientation_OrientationReader(Mhd::MhdPythonOrientation* mo, char* InputFile) {mo->OrientationReader(InputFile);}
  /**
   * @brief MhdPythonOrientation::OrientatioWriter in Python
   *
   * @param mo Object MhdPythonOrientation
   * @param OutputFile Output in .mhd format
   */
  void MhdOrientation_OrientationWriter(Mhd::MhdPythonOrientation* mo, char* OutputFile) {mo->OrientationWriter(OutputFile);}
  /**
   * @brief MhdPythonOrientation::ConvertToRas in Python
   *
   * @param mo Object MhdPythonOrientation
   * @param i Angle selected for the conversion
   */
  void MhdOrientation_ConvertToRas(Mhd::MhdPythonOrientation* mo,size_t i) {mo->ConvertToRas(i);}
  /**
   * @brief MhdPythonOrientation::ComputeAngles in Python
   *
   * @param mo Object MhdPythonOrientation
   */
  void MhdOrientation_ComputeAngles(Mhd::MhdPythonOrientation* mo) {mo->ComputeAngles();}
  /**
   * @brief MhdPythonOrientation::ComputeRotation in Python
   *
   * @param mo Object MhdPythonOrientation
   * @param angles Angle used to compute the rotation
   */
  void MhdOrientation_ComputeRotation(Mhd::MhdPythonOrientation* mo, float* angles){mo->ComputeRotation(angles);}
  /**
   * @brief MhdPythonOrientation::R in Python
   *
   * @param mo Object MhdPythonOrientation
   * @param i i-th row of the TransformMatrix
   * @param j j-th column of the TransformMatrix
   */
  void MhdOrientation_R(Mhd::MhdPythonOrientation* mo,size_t i,size_t j){mo->R(i,j);}
  /**
   * @brief MhdPythonOrientation::O in Python
   *
   * @param mo Object MhdPythonOrientation
   * @param i i-th element of Offset
   */
  void MhdOrientation_O(Mhd::MhdPythonOrientation* mo,size_t i){mo->O(i);}
  /**
   * @brief MhdPythonOrientation::C in Python
   *
   * @param mo Object MhdPythonOrientation
   * @param i i-th element of CenterOfRotation
   */
  void MhdOrientation_C(Mhd::MhdPythonOrientation* mo,size_t i){mo->C(i);}
  /**
   * @brief MhdPythonOrientation::AO in Python
   *
   * @param mo Object MhdPythonOrientation
   */
  void MhdOrientation_AO(Mhd::MhdPythonOrientation* mo){mo->AO();}
}
