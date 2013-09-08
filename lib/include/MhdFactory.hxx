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

  typedef std::unique_ptr<MhdOrientation > (* MhdBuilder)();

  class MhdFactory
  {

    public:

      typedef map<string,MhdBuilder> Collector;
      static MhdFactory & Instance();
      unique_ptr<MhdOrientation> Get(string const & Name) const;
      void Register(string const &, MhdBuilder const &) throw(invalid_argument);
      vector<string> Registered()const;
      void Unset(string const &); 
      ~MhdFactory();
      MhdFactory();

    private:

      MhdFactory(const MhdFactory &); 
      MhdFactory & operator =(const MhdFactory &); 
      Collector Collection;
  };
}

namespace
{
  std::string GetName(Mhd::MhdFactory::Collector::value_type const &);
}

#endif
