#include "MhdOrientationRules.hxx"

namespace Mhd
{

  //AIL orientation
  AIL::AIL(){AnatomicalOrientation="AIL";}

  void AIL::ConvertToRas(size_t i)
  {

    if(i!=1 && i!=2)
    {
      cerr << "===================================================================================================" << endl;
      cerr << "Error: in angle selection in function ConvertToRas, argument must be 1 or 2, or default value"<<endl;
      exit(1);
      cerr << "===================================================================================================" << endl;
    }

    if (AnatomicalOrientation=="RAS")
    {
      cerr << "===================================================================================================" << endl;
      cerr << "Error: the .mhd file is yet RAS-oriented"<<endl;
      cerr << "===================================================================================================" << endl;
      exit(1);
    }

    vector <float> tmp;
    vector <float> a_ras1,a_ras2;

    tmp.reserve(3);
    a_ras1.reserve(3);
    a_ras2.reserve(3);

    AnatomicalOrientation.erase(AnatomicalOrientation.begin(),AnatomicalOrientation.end());
    AnatomicalOrientation="RAS";
    tmp.push_back(-Offset[2]);
    tmp.push_back(Offset[0]);
    tmp.push_back(-Offset[1]);

    Offset.erase(Offset.begin(),Offset.end());
    Offset.push_back(tmp[0]);
    Offset.push_back(tmp[1]);
    Offset.push_back(tmp[2]);

    a_ras1.push_back(-Angles.first[2]);
    a_ras1.push_back(Angles.first[0]);
    a_ras1.push_back(-Angles.first[1]);

    a_ras2.push_back(-Angles.second[2]);
    a_ras2.push_back(Angles.second[0]);
    a_ras2.push_back(-Angles.second[1]);

    if (i==1)
      ComputeRotation(a_ras1.data());
    else
      ComputeRotation(a_ras2.data());
  }

  MhdOrientation * AIL::Create()const { return new AIL(*this);}


  //ASL orientation
  ASL::ASL(){AnatomicalOrientation="ASL";}

  void ASL::ConvertToRas(size_t i)
  {

    if(i!=1 && i!=2)
    {
      cerr << "===================================================================================================" << endl;
      cerr << "Error: in angle selection in function ConvertToRas, argument must be 1 or 2, or default value"<<endl;
      exit(1);
      cerr << "===================================================================================================" << endl;
    }

    if (AnatomicalOrientation=="RAS")
    {
      cerr << "===================================================================================================" << endl;
      cerr << "Error: the .mhd file is yet RAS-oriented"<<endl;
      cerr << "===================================================================================================" << endl;
      exit(1);
    }

    vector <float> tmp;
    vector <float> a_ras1,a_ras2;

    tmp.reserve(3);
    a_ras1.reserve(3);
    a_ras2.reserve(3);

    AnatomicalOrientation.erase(AnatomicalOrientation.begin(),AnatomicalOrientation.end());
    AnatomicalOrientation="RAS";
    tmp.push_back(-Offset[2]);
    tmp.push_back(Offset[0]);
    tmp.push_back(Offset[1]);

    Offset.erase(Offset.begin(),Offset.end());
    Offset.push_back(tmp[0]);
    Offset.push_back(tmp[1]);
    Offset.push_back(tmp[2]);

    a_ras1.push_back(Angles.first[2]);
    a_ras1.push_back(-Angles.first[0]);
    a_ras1.push_back(-Angles.first[1]);

    a_ras2.push_back(Angles.second[2]);
    a_ras2.push_back(-Angles.second[0]);
    a_ras2.push_back(-Angles.second[1]);

    if (i==1)
      ComputeRotation(a_ras1.data());
    else
      ComputeRotation(a_ras2.data());
  }

  MhdOrientation * ASL::Create()const { return new ASL(*this);}


  //RAI orientation
  RAI::RAI(){AnatomicalOrientation="RAI";}

  void RAI::ConvertToRas(size_t i)
  {

    if(i!=1 && i!=2)
    {
      cerr << "===================================================================================================" << endl;
      cerr << "Error: in angle selection in function ConvertToRas, argument must be 1 or 2, or default value"<<endl;
      exit(1);
      cerr << "===================================================================================================" << endl;
    }

    if (AnatomicalOrientation=="RAS")
    {
      cerr << "===================================================================================================" << endl;
      cerr << "Error: the .mhd file is yet RAS-oriented"<<endl;
      cerr << "===================================================================================================" << endl;
      exit(1);
    }

    vector <float> tmp;
    vector <float> a_ras1,a_ras2;

    tmp.reserve(3);
    a_ras1.reserve(3);
    a_ras2.reserve(3);

    AnatomicalOrientation.erase(AnatomicalOrientation.begin(),AnatomicalOrientation.end());
    AnatomicalOrientation="RAS";
    tmp.push_back(Offset[0]);
    tmp.push_back(Offset[1]);
    tmp.push_back(-Offset[2]);

    Offset.erase(Offset.begin(),Offset.end());
    Offset.push_back(tmp[0]);
    Offset.push_back(tmp[1]);
    Offset.push_back(tmp[2]);

    a_ras1.push_back(-Angles.first[0]);
    a_ras1.push_back(-Angles.first[1]);
    a_ras1.push_back(Angles.first[2]);

    a_ras2.push_back(-Angles.second[0]);
    a_ras2.push_back(-Angles.second[1]);
    a_ras2.push_back(Angles.second[2]);

    if (i==1)
      ComputeRotation(a_ras1.data());
    else
      ComputeRotation(a_ras2.data());
  }

  MhdOrientation * RAI::Create()const { return new RAI(*this);}


  //LSA orientation
  LSA::LSA(){AnatomicalOrientation="LSA";}

  void LSA::ConvertToRas(size_t i)
  {

    if(i!=1 && i!=2)
    {
      cerr << "===================================================================================================" << endl;
      cerr << "Error: in angle selection in function ConvertToRas, argument must be 1 or 2, or default value"<<endl;
      exit(1);
      cerr << "===================================================================================================" << endl;
    }

    if (AnatomicalOrientation=="RAS")
    {
      cerr << "===================================================================================================" << endl;
      cerr << "Error: the .mhd file is yet RAS-oriented"<<endl;
      cerr << "===================================================================================================" << endl;
      exit(1);
    }

    vector <float> tmp;
    vector <float> a_ras1,a_ras2;

    tmp.reserve(3);
    a_ras1.reserve(3);
    a_ras2.reserve(3);

    AnatomicalOrientation.erase(AnatomicalOrientation.begin(),AnatomicalOrientation.end());
    AnatomicalOrientation="RAS";
    tmp.push_back(-Offset[0]);
    tmp.push_back(Offset[2]);
    tmp.push_back(Offset[1]);

    Offset.erase(Offset.begin(),Offset.end());
    Offset.push_back(tmp[0]);
    Offset.push_back(tmp[1]);
    Offset.push_back(tmp[2]);

    a_ras1.push_back(-Angles.first[0]);
    a_ras1.push_back(Angles.first[2]);
    a_ras1.push_back(Angles.first[1]);

    a_ras2.push_back(-Angles.second[0]);
    a_ras2.push_back(Angles.second[2]);
    a_ras2.push_back(Angles.second[1]);

    if (i==1)
      ComputeRotation(a_ras1.data());
    else
      ComputeRotation(a_ras2.data());
  }

  MhdOrientation * LSA::Create()const { return new LSA(*this);}
}

namespace
{
  using namespace Mhd;
  //Registration of the orientation type
  MhdProxy<AIL> OA("AIL");
  MhdProxy<ASL> OB("ASL");
  MhdProxy<RAI> OC("RAI");
  MhdProxy<LSA> OD("LSA");
}
