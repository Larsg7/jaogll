jaogll: *.h src/*.cpp external/*
	g++ -c src/*.cpp external/*.cpp -fpic -std=c++0x
	g++ --shared -o libjaogll.so *.o -lSDL2 -lGL -lGLEW -std=c++0x
	rm *.o

all: jaogll

clean:
	rm *.o *.gch external/*.gch
