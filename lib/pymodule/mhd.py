##
# @file mhd.py
# @brief Module for the interface with Python using ctypes
# @author Matteo Manica
# @date 2013-09-08

# This program is free software: you can redistribute it and/or modify 
#  it under the terms of the GNU General Public License as published by 
#  the Free Software Foundation, either version 3 of the License, or 
#  (at your option) any later version. 
#  
#  This program is distributed in the hope that it will be useful, 
#  but WITHOUT ANY WARRANTY; without even the implied warranty of 
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
#  GNU General Public License for more details. 
#  
#  You should have received a copy of the GNU General Public License 
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.



##
# @brief Importing the dynamic library using ctypes
import ctypes
lib = ctypes.CDLL('./libMhdOrientation.so',mode=ctypes.RTLD_GLOBAL)


##
# @brief Class MhdOrientation imported in Python
class MhdOrientation(object):
  ##
  # @brief Constructor
  #
  def __init__(self):
    self.obj = lib.MhdOrientation_Python()

  ##
  # @brief MhdPythonOrientation::OrientationReader in Python
  #
  # @param InputFile Input .mhd file
  #
  def OrientationReader(self,InputFile):
    lib.MhdOrientation_OrientationReader(self.obj,InputFile)

  ##
  # @brief MhdPythonOrientation::OrientationWriter in Python
  #
  # @param OutputFile Output .mhd file
  #
  def OrientationWriter(self,OutputFile):
    lib.MhdOrientation_OrientationWriter(self.obj,OutputFile)

  ##
  # @brief MhdPythonOrientation::ConvertToRas in Python
  #
  # @param i Angle chosen
  def ConvertToRas(self,i=1):
    lib.MhdOrientation_ConvertToRas(self.obj,i)

  ##
  # @brief MhdPythonOrientation::ComputeAngles in Python
  def ComputeAngles(self):
    lib.MhdOrientation_ComputeAngles(self.obj)

  ##
  # @brief MhdPythonOrientation::ComputeRotation in Python
  #
  # @param angles Angle chosen
  def ComputeRotation(self,angles):
    lib.MhdOrientation_ComputeRotation(self.obj,angles)

  ##
  # @brief MhdPythonOrientation::R in Python
  #
  # @param i i-th row of TransformMatrix
  # @param j j-th column of TransformMatrix
  def R(self,i,j):
    lib.MhdOrientation_R(self.obj,i,j)

  ##
  # @brief MhdPythonOrientation::O in Python
  #
  # @param i i-th element of Offset
  def O(self,i):
    lib.MhdOrientation_O(self.obj,i)

  ##
  # @brief MhdPythonOrientation::C in Python
  #
  # @param i i-th element of CenterOfRotation
  def C(self,i):
    lib.MhdOrientation_C(self.obj,i)

  ##
  # @brief MhdPythonOrientation::AO in Python
  def AO(self):
    lib.MhdOrientation_AO(self.obj)

#End of Module
