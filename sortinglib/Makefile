include ../Makefile.in
default: libmoduleHistSort.a

libmoduleHistSort.a: sortinglib.h
	touch empty.C
	$(CHARMC) -language charm++ -c empty.C
	$(CHARMC) -language charm++ -o $@ empty.o

sortinglib.h: Sorter.h Bucket.h HistSort.decl.h Sorter.C Bucket.C defs.h

HistSort.decl.h HistSort.def.h : HistSort.ci
	$(CHARMC)  HistSort.ci

clean:
	rm -f libmoduleHistSort.a *.decl.h *.def.h *.o empty.C
	rm -f charmrun                        