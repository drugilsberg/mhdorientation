/**
 * @file MhdFileReader.cxx
 * @brief File containing the function that reads a .mhd file to get the AnatomicalOrientation parameter
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
