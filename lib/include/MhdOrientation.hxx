/**
 * @file MhdOrientation.hxx
 * @brief File containing the base class MhdOrientation
 * @author Matteo Manica
 *  
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

#ifndef MHDORIENTATION_HXX
#define MHDORIENTATION_HXX 1

#include<fstream>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<utility>

#define PI 3.14159265

/**
 * @brief Namespace Mhd referred to the classes and methods defined in the project MhdOrientation
 */
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


  /**
   * @brief Base class that contains methods to perform the RAS conversion
   */
  class MhdOrientation{

    protected:
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
      /**
       * @brief Read from a .mhd files the parameters
       *
       * @param InputFile Input .mhd file
       */
      void OrientationReader(char* InputFile);
      /**
       * @brief Write on a file the parameters in .mhd format
       *
       * @param OutputFile Output .mhd file
       */
      void OrientationWriter(char* OutputFile);
      /**
       * @brief Virtual declaration of the method used to convert the orientation to RAS orientation
       *
       * @param i Select the i-th angle to perform the conversion 
       */
      virtual void ConvertToRas(size_t i=1)=0;
      /**
       * @brief Virtual constructor
       *
       */
      virtual MhdOrientation * Create() const =0;
      /**
       * @brief Compute the rotation angles from the TransformMatrix
       */
      void ComputeAngles();
      /**
       * @brief Compute from the angle given the TransformMatrix
       *
       * @param angles The angle used to compute the TransformMatrix
       */
      void ComputeRotation(float* angles);
      /**
       * @brief Returns the element (i,j) of the TransformMatrix
       *
       * @param i Row index of the TransformMatrix
       * @param j Column index of the TransformMatrix
       *
       * @return float element of the TransformMatrix
       */
      float R(size_t i,size_t j){return TransformMatrix[(i*3)+j];}
      /**
       * @brief Returns i-th element of Offset
       *
       * @param i The i-th element of Offset
       *
       * @return float element of the Offset
       */
      float O(size_t i){return Offset[i];}
      /**
       * @brief Returns i-th element of CenterOfRotation
       *
       * @param i The i-th element of CenterOfRotation
       *
       * @return float element of the CenterOfRotation
       */
      float C(size_t i){return CenterOfRotation[i];}
      /**
       * @brief Returns the stored AnatomicalOrientaion
       *
       * @return the orientation
       */
      const char* AO(){return AnatomicalOrientation.c_str();}
      /**
       * @brief Overloading of the operator <<
       *
       * @param out Ostream for .mhd file writing
       * @param K The object used to write the .mhd file
       *
       * @return ofstream to write the object
       */
      friend ostream &operator<<( ostream &out, const MhdOrientation &K); 
  };
  
  /**
   * @brief Read from a file the AnatomicalOrientation parameter
   *
   * @param InputFile Input .mhd file
   *
   * @return a string containing the orientation
   */
  char* MhdFileReader(char * InputFile);

}

#endif
