# MhdOrientation

A library used to orient images that works on .mhd header files to convert
the anatomical orientation present in the header, into a RAS one. The operation
is performed to allow the elaboration of the image using software like VTK and vmtk
without losing information about its position when working in the physical space
