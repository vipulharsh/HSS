include Makefile.in

#Charm++ libraries
LIBS=libmoduleHistSort.a
ifeq ("$(CHARM_ARCH)","")
  DEST=bin
else
  DEST=bin-$(CHARM_ARCH)
endif



all: clean $(DEST)/testsorting


$(DEST)/testsorting: $(LIBS) testsorting.ci testsorting.C  
#	chmod 755 $(DEST)/charm_all_libs.sh
#	. $(DEST)/charm_all_libs.sh && $(CHARMC) -mpi -o $(DEST)/testsorting  testsorting.o -L$(DEST) -lcharm $(MPI_LIBS) -ltrace-projections -tracemode projections
	$(CHARMC) -language charm++ testsorting.ci
	$(CHARMC) -language charm++ -o $@ testsorting.C -Lbin -module HistSort -lstdc++
#	. $(DEST)/charm_all_libs.sh && $(CXX)  -o $(DEST)/testsorting testsorting.o -L$(DEST) $$CHARM_ALL_LIBS -lcharm $(MPI_LIBS) -ltrace-projections 

$(LIBS):  
	echo "CHARM_ARCH is $(CHARM_ARCH)"
	cd sortinglib;make;
	mkdir -p $(DEST);
	cp sortinglib/libmoduleHistSort.a $(DEST)/
	$(CHARMC)  -language charm++ -o $(DEST)/libcharm.a -L$(DEST) -module HistSort -lstdc++ 
#	mv ./charm_all_libs.sh $(DEST)/

clean: clear
	cd sortinglib;make clean;cd ..;
	rm -f testsorting *.o *.a charmrun libmoduleHistSort.a libcharm.a charm_all_libs.sh

clear:
	rm -f PI*

test: all
	mpirun -np 16 ./testsorting 100 7




