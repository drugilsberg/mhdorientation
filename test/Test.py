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

#another orientation
q=mhd.MhdOrientation()
q.OrientationReader("ASL.mhd")
q.ConvertToRas()
q.OrientationWriter("ASLRASpython.mhd")
