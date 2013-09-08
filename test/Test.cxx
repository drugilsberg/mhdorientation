/**
 * @file Test.cxx
 * @brief An example of the library used in C++
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
#include <iostream>
#include <fstream>
#include <dlfcn.h>
#include "MHD.hxx"

using namespace Mhd;
using std::cout;

int main(int argc, char* argv[]){

  //Check input arguments
  if(argc!=4 && argc!=3)
  {
    cerr << "===================================================================================================" << endl;
    cerr << "Error: wrong input parameters;" << endl;
    cerr << "Inpur parameters are:" << endl;
    cerr << "in.mhd[MANDATORY] out.mhd[MANDATORY] ang(int =1 or =2 referred to angle for conversion)[OPTIONAL]" << endl;
    cerr << "===================================================================================================" << endl;
  }
  else
  {
    //Dynamic library loading
    string OrienLib =  "libMhdOrientation.so";

    void * Dylib = dlopen( OrienLib.c_str(), RTLD_NOW );

    if (!Dylib)
    {
      cerr << "===================================================================================================" << endl;
      cerr<< "Can't find library" << OrienLib <<endl;
      cerr<< dlerror();
      cerr << "===================================================================================================" << endl;
      exit(1);
    }


    char* Mhdin=argv[1];
    ofstream Mhdout(argv[2]);
    string Anor;
    Anor.assign(MhdFileReader(Mhdin));
    size_t Ang;
    
    if(argc==4)Ang=atoi(argv[3]);

    //Factory of MhdOrientation
    MhdFactory & OrientationFactory( MhdFactory::Instance());

    unique_ptr<MhdOrientation> Orien = OrientationFactory.Get(Anor);
    
    //Factory check
    bool Check;

    if (!(Anor=="List Orientations"))
      if ((Check = !(OrientationFactory.Get(Anor))) ){
        cerr << "===================================================================================================" << endl;
        cerr << "Orientation " << Anor << " does not exist" << endl;
        cerr << "===================================================================================================" << endl;
        Anor="List Orientations";
      }
    if (Anor=="List Orientations")
    {
      vector<string> List = OrientationFactory.Registered();

      cerr << "===================================================================================================" << endl;
      cerr << " The following orientations are registered in " << OrienLib << endl;
      cerr << "===================================================================================================" << endl;

      for (auto i = List.begin(); i<List.end();++i)
        cerr << *i << endl;

      if (Check==false)
        exit(0);
      else
        exit(2);
      cerr << "===================================================================================================" << endl;
    }


    //Orientation reading from file
    Orien->OrientationReader(Mhdin);
    cout << "=============PRE-CONVERSION============="<< endl << *Orien;
    
    //Conversion
    if(argc == 4)
      Orien->ConvertToRas(Ang);
    else
      Orien->ConvertToRas();
    
    //New Orientation writing
    cout << "=============POST-CONVERSION============="<< endl << *Orien;
    Mhdout << *Orien;

    dlclose(Dylib);

  return 0;
  
  }
}
