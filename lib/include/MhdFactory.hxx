/**
 * @file MhdFactory.hxx
 * @brief File containing the factory of MhdOrientations
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
#ifndef MHDFACTORY_HXX
#define MHDFACTORY_HXX 1

#include "MhdOrientation.hxx"
#include<map>
#include<stdexcept>
#include<memory>
#include<algorithm>
#include<iterator>

namespace Mhd
{

  using std::invalid_argument;
  using std::map;
  using std::unique_ptr;

  /**
   * @brief A typedef to the builder that returns a unique_ptr to a MhdOrientation object
   */
  typedef std::unique_ptr<MhdOrientation > (* MhdBuilder)();

  /**
   * @brief The factory tha collects different MhdOrientation
   */
  class MhdFactory
  {

    public:

      /**
       * @brief Collector of the orientations
       */
      typedef map<string,MhdBuilder> Collector;
      /**
       * @brief 
       *
       * @return 
       */
      static MhdFactory & Instance();
      /**
       * @brief Get an object of the factory
       *
       * @param Name Name of the orientation selected
       *
       * @return The orientation with the Name chosen
       *
       * @throw invalid_argument
       */
      unique_ptr<MhdOrientation> Get(string const & Name) const;
      /**
       * @brief Registers in the factory the orientation given
       *
       * @param Name Name of the orientation to be registered
       * @param Func The builder used
       *
       * @throw invalid_argument
       */
      void Register(string const & Name, MhdBuilder const & Func) throw(invalid_argument);
      /**
       * @brief List all the orientations contained in the factory
       *
       * @return a vector<string> containing the orientations
       */
      vector<string> Registered()const;
      /**
       * @brief Remove the given orientation from the factory
       *
       * @param Name Name of the orientation to be removed
       */
      void Unset(string const & Name); 
      ~MhdFactory();

    private:

      MhdFactory();
      MhdFactory(const MhdFactory &); 
      MhdFactory & operator =(const MhdFactory &); 
      /**
       * @brief The factory of orientations
       */
      Collector Collection;
  };
}

namespace
{
  /**
   * @brief A function used to extract from the pair returned by the Collector
   *
   *
   * @return The name of the orientation contained in the collector
   */
  std::string GetName(Mhd::MhdFactory::Collector::value_type const &);
}

#endif
