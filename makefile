CC=g++
TLIBRARY=libjaogll.so
INCDIR=/usr/include/jaogll
LIBDIR=/usr/lib

jaogll: *.h src/*.cpp external/*.cpp external/*.h
	$(CC) -c src/*.cpp external/*.cpp -std=c++0x -fPIC
	$(CC) --shared -o $(TLIBRARY) *.o
	rm *.o

install:
	mkdir -p $(INCDIR)
	mv libjaogll.so $(LIBDIR)
	cp *.h $(INCDIR)

clean:
	rm $(TLIBRARY)

uninstall:
	rm -r $(INCDIR)
	rm $(LIBDIR)$(TLIBRARY)