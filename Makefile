include Makefile.in
all: clean testsorting

#Charm++ libraries to be used for Interoperation
LIBS=libmoduleHistSort.a
ifeq ("$(CHARM_ARCH)","")
  DEST=bin
else
  DEST=bin-$(CHARM_ARCH)
endif

SORTINGLIB=sortinglib

testsorting: testsorting.cpp $(LIBS)
	$(CXX) -c testsorting.cpp -o testsorting.o -I$(CHARMDIR)/include
	$(CHARMC) -mpi -o $(DEST)/testsorting  testsorting.o -L$(DEST) -lcharm -ltrace-projections -tracemode projections

$(LIBS):  
	echo "CHARM_ARCH is $(CHARM_ARCH)"
	cd $(SORTINGLIB);make;
	mkdir -p $(DEST);
	cp $(SORTINGLIB)/libmoduleHistSort.a $(DEST)/
	$(CHARMC) -language charm++ -mpi -o $(DEST)/libcharm.a -L$(DEST) -module HistSort -lstdc++
	mv ./charm_all_libs.sh $(DEST)/

clean: clear
	cd $(SORTINGLIB);make clean;cd ..;
	rm -f testsorting *.o *.a charmrun libmoduleHistSort.a libcharm.a charm_all_libs.sh

clear:
	rm -f PI*

test: all
	mpirun -np 16 ./testsorting 100 7

