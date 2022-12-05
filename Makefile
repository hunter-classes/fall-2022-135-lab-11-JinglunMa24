main: main.o profile.o
	g++ -o main main.o profile.o -std=c++17

tests: tests.o profile.o
	g++ -o tests tests.o profile.o -std=c++17



main.o: main.cpp profile.cpp profile.h

tests.o: tests.cpp doctest.h profile.cpp profile.h

profile.o: profile.cpp profile.h

clean:
	rm -f main.o tests.o profile.o