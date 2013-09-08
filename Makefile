CC = g++
SRCDIR = lib/src/
BUILDDIR = lib/build/
INCLUDEDIR = lib/include/
TESTDIR = test/
LIBDIR = lib/
SOURCES = $(shell find $(SRCDIR) -type f -name *.cxx)
OBJECTS = $(patsubst $(SRCDIR)%,$(BUILDDIR)%,$(SOURCES:.cxx=.o))
OBJFLAGS = -c -Wall -fPIC -std=c++11
LIBFLAGS = -shared -Wl,-soname,libMhdOrientation.so
TESTFLAGS = -ldl -L./$(LIBDIR) -lMhdOrientation -std=c++11 -Wall -fPIC

all: dynamiclib test


clean:
	@echo "Cleaning object files,dynamic library, and the tests"
	rm -f $(BUILDDIR)*.o *.so $(TESTDIR)Test $(TESTDIR)*.vtp $(TESTDIR)*.so $(TESTDIR)mhd.py*


dynamiclib: $(OBJECTS)
	@echo "Creating the dynamic library"
	$(CC) $(LIBFLAGS) $(BUILDDIR)*.o -o $(LIBDIR)libMhdOrientation.so


$(BUILDDIR)%.o: $(SRCDIR)%.cxx
	@echo "Building of the object file"
	$(CC) $(OBJFLAGS) -I./$(INCLUDEDIR) -o $@ $<

test: dynamiclib
	@cp $(LIBDIR)libMhdOrientation.so $(TESTDIR)
	@cp $(LIBDIR)pymodule/mhd.py $(TESTDIR)
	$(CC) $(TESTDIR)Test.cxx -I./$(INCLUDEDIR) $(TESTFLAGS) -o $(TESTDIR)Test

.PHONY: clean
