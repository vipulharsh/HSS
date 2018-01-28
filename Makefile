include Makefile.in

# Charm++ libraries
LIBS=libmoduleHistSort.a
ifeq ("$(CHARM_ARCH)","")
  DEST=bin
else
  DEST=bin-$(CHARM_ARCH)
endif

all: clean $(DEST)/testsorting

$(DEST)/testsorting: $(LIBS) testsorting.ci testsorting.C
	$(CHARMC) -language charm++ testsorting.ci
	$(CHARMC) -language charm++ -o $@ testsorting.C -Lbin -module HistSort -lstdc++

$(LIBS):
	echo "CHARM_ARCH is $(CHARM_ARCH)"
	cd sortinglib; make;
	mkdir -p $(DEST);
	cp sortinglib/libmoduleHistSort.a $(DEST)/
	$(CHARMC)  -language charm++ -o $(DEST)/libcharm.a -L$(DEST) -module HistSort -lstdc++

clean: clear
	cd sortinglib;make clean;cd ..;
	rm -f testsorting *.o *.a charmrun libmoduleHistSort.a libcharm.a charm_all_libs.sh

clear:
	rm -f PI*

test: all
	mpirun -np 16 ./testsorting 100 7
