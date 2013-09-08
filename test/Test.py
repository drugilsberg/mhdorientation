
##
# @file Test.py
# @brief An example of the library used in Python
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

#import the module
import mhd

p=mhd.MhdOrientation()

p.OrientationReader("AIL.mhd")
p.ConvertToRas()
p.OrientationWriter("AILRASpython.mhd")

#trial of reading on the same object
p.OrientationReader("AIL.mhd")
p.ConvertToRas()
p.OrientationWriter("2AILRASpython.mhd")
