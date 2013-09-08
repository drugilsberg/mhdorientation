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
