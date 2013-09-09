/**
 * @file MhdOrientationRules.hxx
 * @brief File containing the derived classes to perform the orientation starting from the string
 * AnatomicalOrientation stored
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

#ifndef MHDORIENTATIONRULES_HXX
#define MHDIORIENTATIONRULES_HXX 1

#include "MhdOrientation.hxx"
#include "MhdProxy.hxx"

namespace Mhd{

  /**
   * @brief Derived class to perform AIL->RAS conversion
   */
  class AIL : public MhdOrientation{

    public:
      AIL();
      ~AIL();
      /**
       * @brief Perform orientation to RAS
       *
       * @param i i-th angle of rotation
       */
      void ConvertToRas(size_t i=1);
      /**
       * @brief Construction of the object returning a pointer to the base class
       *
       * @return Pointer to the base class 
       */
      virtual MhdOrientation *  Create() const;
  };

  class ASL : public MhdOrientation{

    public:
      ASL();
      ~ASL();
      /**
       * @brief Perform orientation to RAS
       *
       * @param i i-th angle of rotation
       */
      void ConvertToRas(size_t i=1);
      /**
       * @brief Construction of the object returning a pointer to the base class
       *
       * @return Pointer to the base class 
       */
      virtual MhdOrientation *  Create() const;
  };

  class RAI : public MhdOrientation{

    public:
      RAI();
      ~RAI();
      /**
       * @brief Perform orientation to RAS
       *
       * @param i i-th angle of rotation
       */
      void ConvertToRas(size_t i=1);
      /**
       * @brief Construction of the object returning a pointer to the base class
       *
       * @return Pointer to the base class 
       */
      virtual MhdOrientation *  Create() const;
  };

  class LAS : public MhdOrientation{

    public:
      LAS();
      ~LAS();
      /**
       * @brief Perform orientation to RAS
       *
       * @param i i-th angle of rotation
       */
      void ConvertToRas(size_t i=1);
      /**
       * @brief Construction of the object returning a pointer to the base class
       *
       * @return Pointer to the base class 
       */
      virtual MhdOrientation *  Create() const;
  };
}

#endif
