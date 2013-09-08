#ifndef MHDPROXY_HXX
#define MHDPROXY_HXX 1

#include "MhdFactory.hxx"
#include "MhdOrientation.hxx"
#include <typeinfo>

namespace Mhd{

  template <typename T> class MhdProxy{

    public:
      MhdProxy(char const * const &); 
      ~MhdProxy(){};
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
