include Makefile.in

#Charm++ libraries
LIBS=libmoduleHistSort.a
DEST=bin
all: clean $(DEST)/testsorting

$(DEST)/testsorting: $(LIBS) testsorting.ci testsorting.C  
	$(CHARMC) -language charm++ testsorting.ci
	$(CHARMC) -language charm++ -o $@ testsorting.C -Lbin -module HistSort -lstdc++

$(LIBS):  
	echo "CHARM_ARCH is $(CHARM_ARCH)"
	cd sortinglib;make;
	mkdir -p $(DEST);
	cp sortinglib/libmoduleHistSort.a $(DEST)/
	$(CHARMC)  -language charm++ -o $(DEST)/libcharm.a -L$(DEST) -module HistSort -lstdc++ sortinglib/empty.o


clean: clear
	cd sortinglib;make clean;cd ..;
	rm -f $(DEST)/testsorting *.o *.a charmrun $(DEST)/libmoduleHistSort.a $(DEST)/libcharm.a charm_all_libs.sh

clear:
	rm -f PI*




