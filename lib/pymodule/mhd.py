#!/usr/bin/python
#Filename : mhd.py

#importing ctype to load the library in python
import ctypes
lib = ctypes.CDLL('./libMhdOrientation.so',mode=ctypes.RTLD_GLOBAL)

#creating a class in python from the dynamic library with the functions defined
#in MhdPythonOrientation.cxx
class MhdOrientation(object):
  def __init__(self):
    self.obj = lib.MhdOrientation_Python()

  def OrientationReader(self,InputFile):
    lib.MhdOrientation_OrientationReader(self.obj,InputFile)

  def OrientationWriter(self,OutputFile):
    lib.MhdOrientation_OrientationWriter(self.obj,OutputFile)

  def ConvertToRas(self,i=1):
    lib.MhdOrientation_ConvertToRas(self.obj,i)

  def ComputeAngles(self,InputFile):
    lib.MhdOrientation_ComputeAngles(self.obj)

  def ComputeRotation(self,angles):
    lib.MhdOrientation_ComputeRotation(self.obj,angles)

  def R(self,i,j):
    lib.MhdOrientation_R(self.obj,i,j)

  def O(self,i):
    lib.MhdOrientation_O(self.obj,i)

  def C(self,i):
    lib.MhdOrientation_C(self.obj,i)

#End of Module
