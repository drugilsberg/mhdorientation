/**
 * @file MhdFactory.cxx
 * @brief Implementation of the factory
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
#include "MhdFactory.hxx"

namespace Mhd
{

  MhdFactory & MhdFactory::Instance() {
    static MhdFactory theFactory;
    return theFactory;
  }

  unique_ptr<MhdOrientation> MhdFactory::Get(const string & Name) const {
    Collector::const_iterator f = Collection.find(Name);
    return (f == Collection.end()) ? unique_ptr<MhdOrientation>(): f->second();
  }

  void MhdFactory::Register(const string & Name, MhdBuilder const & Func)
    throw(invalid_argument) {
      pair<Collector::iterator, bool> f = Collection.insert(make_pair(Name, Func));
      if (f.second == false)
        throw invalid_argument("Error: Double registration is forbidden!");
    }

  void MhdFactory::Unset(const string & Name) {
    Collection.erase(Name);
  }

  vector<string> MhdFactory::Registered() const {
    vector<string> tmp(Collection.size());
    transform(Collection.begin(),Collection.end(),tmp.begin(),GetName);
    return tmp;
  }

  MhdFactory::MhdFactory() {
  }

  MhdFactory::MhdFactory(const MhdFactory & MhdFactory) {
  }

  MhdFactory & MhdFactory::operator =(const MhdFactory & MhdFactory) {
    return *this;
  }

  MhdFactory::~MhdFactory() {
  }
}

namespace
{
  std::string GetName(Mhd::MhdFactory::Collector::value_type const & P){return P.first;}
}
