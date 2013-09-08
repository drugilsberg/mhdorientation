/**
 * @file MhdProxy.hxx
 * @brief File containing a proxy to build the object MhdOrientation and that manage its automatic registration
 * in the factory
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
#ifndef MHDPROXY_HXX
#define MHDPROXY_HXX 1

#include "MhdFactory.hxx"
#include "MhdOrientation.hxx"
#include <typeinfo>

namespace Mhd{

  /**
   * @brief A proxy used to build an object MhdOrientation and to
   * register it in the factory 
   *
   * @tparam T The string indicating thr orientation rule to be build and to be registered
   */
  template <typename T> class MhdProxy{

    public:
      /**
       * @brief Constructor of the MhdProxy that perform the ragistration of the MhdOrientation in the class
       *
       * @param Name String containing the name of the orientation to be registered
       */
      MhdProxy(char const * const & Name); 
      ~MhdProxy(){};
      /**
       * @brief The builder of the object
       *
       * @return A static unique_ptr<MhdOrientation>
       */
      static unique_ptr<MhdOrientation> Build();
    private:
      MhdProxy(MhdProxy const &) {}; 
      MhdProxy & operator=(MhdProxy const &) {}; 

  };

  template<typename T>
    unique_ptr<MhdOrientation> MhdProxy<T>::Build() {
      return unique_ptr<MhdOrientation>(new T); 
    }

  template<typename T>
    MhdProxy<T>::MhdProxy(char const * const & Name) {
      MhdFactory & factory(MhdFactory::Instance());
      factory.Register(string(Name),MhdProxy<T>::Build);
    }
}

#endif
