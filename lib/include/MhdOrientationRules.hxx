#ifndef MHDORIENTATIONRULES_HXX
#define MHDIORIENTATIONRULES_HXX 1

#include "MhdOrientation.hxx"
#include "MhdProxy.hxx"

namespace Mhd{

  class AIL : public MhdOrientation{

    public:
      AIL();
      void ConvertToRas(size_t i=1);
      virtual MhdOrientation *  Create() const;
  };

  class ASL : public MhdOrientation{

    public:
      ASL();
      void ConvertToRas(size_t i=1);
      virtual MhdOrientation *  Create() const;
  };

  class RAI : public MhdOrientation{

    public:
      RAI();
      void ConvertToRas(size_t i=1);
      virtual MhdOrientation *  Create() const;
  };

  class LSA : public MhdOrientation{

    public:
      LSA();
      void ConvertToRas(size_t i=1);
      virtual MhdOrientation *  Create() const;
  };
}

#endif
