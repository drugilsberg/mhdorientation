/**
 * @file MhdPythonOrientation.cxx
 * @brief Implementation of MhdPythonOrientation used for the Python interface
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
#include"MhdPythonOrientation.hxx"

namespace Mhd{

  void MhdPythonOrientation::OrientationReader(char* InputFile)
  {

    ifstream in(InputFile);
    char *tmp,*aux;
    char st[256];
    string handle;
    size_t pos;
    bool msb(0),nd(0),ao(0),ds(0),et(0),es(0),edf(0),tm(0),of(0),cr(0);//Minimal Parameters

    //Cleaning before Reading just in case the object must read another image with same orientation
    NDims=0;
    CompressedDataSize=0;
    ObjectType.clear();
    BinaryData.clear();
    BinaryDataByteOrderMSB.clear();
    CompressedData.clear();
    ElementType.clear();
    ElementDataFile.clear();
    Offset.clear();
    vector<float>(Offset).swap(Offset);
    TransformMatrix.clear();
    vector<float>(TransformMatrix).swap(TransformMatrix);
    CenterOfRotation.clear();
    vector<float>(CenterOfRotation).swap(CenterOfRotation);
    ElementSpacing.clear();
    vector<float>(ElementSpacing).swap(ElementSpacing);
    DimSize.clear();
    vector<size_t>(DimSize).swap(DimSize);
                   

    while(in.getline(st,256))
    {
      handle.assign(st);

      //OBJECT TYPE
      if(handle.find("ObjectType ")!=string::npos)
      {
        pos=handle.find_first_of("=");
        handle.erase(handle.begin(),handle.begin()+pos+2);
        ObjectType.assign(handle);
      }

      //NDIMS
      else if(handle.find("NDims ")!=string::npos)
      {
        pos=handle.find_first_of("=");
        handle.erase(handle.begin(),handle.begin()+pos+2);
        NDims=atoi(handle.c_str());
        nd=1;
      }

      //COMPRESSED DATA SIZE
      else if(handle.find("CompressedDataSize ")!=string::npos)
      {
        pos=handle.find_first_of("=");
        handle.erase(handle.begin(),handle.begin()+pos+2);
        NDims=atoi(handle.c_str());
      }

      //BINARY DATA
      else if(handle.find("BinaryData ")!=string::npos)
      {
        pos=handle.find_first_of("=");
        handle.erase(handle.begin(),handle.begin()+pos+2);
        BinaryData.assign(handle);
      }

      //BINARY DATA BYTE ORDER MSB
      else if(handle.find("BinaryDataByteOrderMSB ")!=string::npos)
      {
        pos=handle.find_first_of("=");
        handle.erase(handle.begin(),handle.begin()+pos+2);
        BinaryDataByteOrderMSB.assign(handle);
        msb=1;
      }

      //COMPRESSED DATA
      else if(handle.find("CompressedData ")!=string::npos)
      {
        pos=handle.find_first_of("=");
        handle.erase(handle.begin(),handle.begin()+pos+2);
        CompressedData.assign(handle);
      }

      //TRANSFORM MATRIX
      else if(handle.find("TransformMatrix ")!=string::npos)
      {
        pos=handle.find_first_of("=");
        handle.erase(handle.begin(),handle.begin()+pos+2);
        tmp=(char*)handle.c_str();
        aux=strtok(tmp," ");
        TransformMatrix.reserve(9);
        while(aux != NULL)
        {
          TransformMatrix.push_back(atof(aux));
          aux=strtok(NULL," ");
        }
        tm=1;
      }

      //OFFSET
      else if(handle.find("Offset ")!=string::npos)
      {
        pos=handle.find_first_of("=");
        handle.erase(handle.begin(),handle.begin()+pos+2);
        tmp=(char*)handle.c_str();
        aux=strtok(tmp," ");
        Offset.reserve(3);
        while(aux != NULL)
        {
          Offset.push_back(atof(aux));
          aux=strtok(NULL," ");
        }
        of=1;
      }

      //CENTER OF ROTATION
      else if(handle.find("CenterOfRotation ")!=string::npos)
      {
        pos=handle.find_first_of("=");
        handle.erase(handle.begin(),handle.begin()+pos+2);
        tmp=(char*)handle.c_str();
        aux=strtok(tmp," ");
        CenterOfRotation.reserve(3);
        while(aux != NULL)
        {
          CenterOfRotation.push_back(atof(aux));
          aux=strtok(NULL," ");
        }
        cr=1;
      }

      //ANATOMICAL ORIENTATION
      else if(handle.find("AnatomicalOrientation ")!=string::npos)
      {
        pos=handle.find_first_of("=");
        handle.erase(handle.begin(),handle.begin()+pos+2);
        AnatomicalOrientation.assign(handle);
        ao=1;
      }

      //ELEMENT SPACING
      else if(handle.find("ElementSpacing ")!=string::npos)
      {
        pos=handle.find_first_of("=");
        handle.erase(handle.begin(),handle.begin()+pos+2);
        tmp=(char*)handle.c_str();
        aux=strtok(tmp," ");
        ElementSpacing.reserve(3);
        while(aux != NULL)
        {
          ElementSpacing.push_back(atof(aux));
          aux=strtok(NULL," ");
        }
        es=1;
      }

      //DIM SIZE
      else if(handle.find("DimSize ")!=string::npos)
      {
        pos=handle.find_first_of("=");
        handle.erase(handle.begin(),handle.begin()+pos+2);
        tmp=(char*)handle.c_str();
        aux=strtok(tmp," ");
        DimSize.reserve(3);
        while(aux != NULL)
        {
          DimSize.push_back(atoi(aux));
          aux=strtok(NULL," ");
        }
        ds=1;
      }

      //ELEMENT TYPE
      else if(handle.find("ElementType ")!=string::npos)
      {
        pos=handle.find_first_of("=");
        handle.erase(handle.begin(),handle.begin()+pos+2);
        ElementType.assign(handle);
        et=1;
      }

      //ELEMENT DATA FILE
      else if(handle.find("ElementDataFile ")!=string::npos)
      {
        pos=handle.find_first_of("=");
        handle.erase(handle.begin(),handle.begin()+pos+2);
        ElementDataFile.assign(handle);
        edf=1;
      }

      //UNKNOWN PARAMETER
      else
      {
        cerr << "===================================================================================================" << endl;
        cerr << "Error: Unknown Parameter in .mhd file;" << endl;
        cerr << handle << endl;
        cerr << "Known fields are:" << endl;
        cerr << "ElementDataFile" << endl;
        cerr << "ElementType" << endl;
        cerr << "NDims" << endl;
        cerr << "BinaryData" << endl;
        cerr << "BinaryDataByteOrderMSB" << endl;
        cerr << "CompressedData" << endl;
        cerr << "CompressedDataSize" << endl;
        cerr << "TransformMatrix" << endl;
        cerr << "Offset" << endl;
        cerr << "CenterOfRotation" << endl;
        cerr << "AnatomicalOrientation" << endl;
        cerr << "ElementSpacing" << endl;
        cerr << "DimSize" << endl;
        cerr << "ObjectType" << endl;
        cerr << "===================================================================================================" << endl;
        exit(1);
      }

    }

    in.close();


    if((msb && nd && ao && ds && et && es && edf && tm && of && cr) == 1)
      ComputeAngles();
    else
    {
      cerr << "===================================================================================================" << endl;
      cerr << "Error: no minimal parameters in the input file;" << endl;
      cerr << "Minimal Parameters are:" << endl;
      cerr << "Parameters ==> Yes/No" << endl;
      cerr << "BinaryDataByteOrderMSB ==> " << msb <<  endl;
      cerr << "TransformMatrix ==> " << tm << endl;
      cerr << "Offset ==> " << of << endl;
      cerr << "CenterOfRotation ==> " << cr << endl;
      cerr << "AnatomicalOrientation ==> " << ao << endl;
      cerr << "ElementSpacing ==> " << es <<endl;
      cerr << "DimSize ==> " << ds << endl;
      cerr << "ElementDataFile ==> " << edf << endl;
      cerr << "ElementType ==> " << et << endl;
      cerr << "NDims ==> " << nd << endl;
      cerr << "===================================================================================================" << endl;
      exit(1);
    }

  }

  void MhdPythonOrientation::OrientationWriter(char* OutputFile)
  {
    ofstream out(OutputFile);

    if(!ObjectType.empty())
    {
      out << "ObjectType = ";
      out << ObjectType << endl;
    }

    out << "NDims = ";
    out << NDims << endl;

    if(!BinaryData.empty())
    {
      out << "BinaryData = ";
      out << BinaryData << endl;
    }

    out << "BinaryDataByteOrderMSB = ";
    out << BinaryDataByteOrderMSB << endl;

    if(!CompressedData.empty())
    {
      out << "CompressedData = ";
      out << CompressedData << endl;
    }

    if(!CompressedDataSize)
    {
      out << "CompressedDataSize = ";
      out << CompressedDataSize << endl;
    }

    out << "TransformMatrix = ";
    for(int i=0;i<9;++i)
      out << TransformMatrix[i] << " ";
    out << endl;

    out << "Offset = ";
    for(int i=0;i<3;++i)
      out << Offset[i] << " ";
    out << endl;

    out << "CenterOfRotation = ";
    for(int i=0;i<3;++i)
      out << CenterOfRotation[i] << " ";
    out << endl;

    out << "AnatomicalOrientation = ";
    out << AnatomicalOrientation << endl;

    out << "ElementSpacing = ";
    for(int i=0;i<3;++i)
      out << ElementSpacing[i] << " ";
    out << endl;

    out << "DimSize = ";
    for(int i=0;i<3;++i)
      out << DimSize[i] << " ";
    out << endl;

    out << "ElementType = ";
    out << ElementType << endl;

    out << "ElementDataFile = ";
    out << ElementDataFile << endl;

    out.close();

  }

  void MhdPythonOrientation::ComputeAngles()
  {

    vector<float> tern1,tern2;
    tern1.reserve(3);
    tern2.reserve(3);
    float ConvFactor = 180/PI;
    float th1,th2,ps1,ps2,ph1,ph2;

    if (abs(R(2,0)) != 1)
    {
      th1 = - asin(R(2,0));
      th2 = PI - th1;
      ps1 = atan2(R(2,1)/cos(th1),R(2,2)/cos(th1));
      ps2 = atan2(R(2,1)/cos(th2),R(2,2)/cos(th2));
      ph1 = atan2(R(1,0)/cos(th1),R(0,0)/cos(th1));
      ph2 = atan2(R(1,0)/cos(th2),R(0,0)/cos(th2));
      tern1.push_back(ps1*ConvFactor);
      tern1.push_back(th1*ConvFactor);
      tern1.push_back(ph1*ConvFactor);
      tern2.push_back(ps2*ConvFactor);
      tern2.push_back(th2*ConvFactor);
      tern2.push_back(ph2*ConvFactor);
    }
    else
    {
      ph1 = 0;
      if (R(2,0) == -1)
      {
        th1 = PI/2;
        ps1 = ph1 + atan2(R(0,1),R(0,2));
      }
      else
      {
        th1 = -PI/2;
        ps1 = -ph1 + atan2(-R(0,1),-R(0,2));
      } 
      tern1.push_back(ps1*ConvFactor);
      tern1.push_back(th1*ConvFactor);
      tern1.push_back(ph1*ConvFactor);
      tern2=tern1;
    }

    Angles=make_pair(tern1,tern2);
  }

  void MhdPythonOrientation::ComputeRotation(float* angles)
  {

    float x,y,z;
    float ConvFactor=PI/180;
    x=angles[0]*ConvFactor;
    y=angles[1]*ConvFactor;
    z=angles[2]*ConvFactor;
    TransformMatrix.erase(TransformMatrix.begin(),TransformMatrix.end());
    TransformMatrix.reserve(9);
    TransformMatrix.push_back(cos(y)*cos(z));
    TransformMatrix.push_back(cos(z)*sin(x)*sin(y) - cos(x)*sin(z));
    TransformMatrix.push_back(sin(x)*sin(z) + cos(x)*cos(z)*sin(y));
    TransformMatrix.push_back(cos(y)*sin(z));
    TransformMatrix.push_back(cos(x)*cos(z) + sin(x)*sin(y)*sin(z));
    TransformMatrix.push_back(cos(x)*sin(y)*sin(z) - cos(z)*sin(x));
    TransformMatrix.push_back(-sin(y));
    TransformMatrix.push_back(cos(y)*sin(x));
    TransformMatrix.push_back(cos(x)*cos(y));

  }

  void MhdPythonOrientation::ConvertToRas(size_t i)
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

    if(AnatomicalOrientation=="AIL")
    {

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

    if(AnatomicalOrientation=="ASL")
    {

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

    if(AnatomicalOrientation=="RAI")
    {

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

    if(AnatomicalOrientation=="LSA")
    {

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

  }

}
