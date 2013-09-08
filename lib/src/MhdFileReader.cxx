#include"MhdOrientation.hxx"


//A function to read .mhd files that returns the anatomical orientation parameter
namespace Mhd
{
  char* MhdFileReader(char * InputFile)
  {
    ifstream in(InputFile);
    char st[256];
    string handle;
    size_t pos;
    


    while(in.getline(st,256))
    {
      handle.assign(st);

      //ANATOMICAL ORIENTATION
      if(handle.find("AnatomicalOrientation ")!=string::npos)
      {
        pos=handle.find_first_of("=");
        handle.erase(handle.begin(),handle.begin()+pos+2);
        if(handle=="RAS")
        {
          cerr << "===================================================================================================" << endl;
          cerr << "Error: Image yet RAS oriented;" << endl;
          cerr << "===================================================================================================" << endl;
          exit(1);
        }
        return (char *)handle.c_str();
      }
    }

    cerr << "===================================================================================================" << endl;
    cerr << "Error: No Anatomical Orientation Parameter in .mhd file;" << endl;
    cerr << "===================================================================================================" << endl;
    exit(1);
  }
}
