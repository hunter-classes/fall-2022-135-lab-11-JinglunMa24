main: main.o profile.o network.o
	g++ -o main main.o profile.o network.o -std=c++17

tests: tests.o profile.o network.o
	g++ -o tests tests.o profile.o network.o -std=c++17



main.o: main.cpp profile.cpp profile.h network.cpp network.h

tests.o: tests.cpp doctest.h profile.cpp profile.h network.cpp network.h

profile.o: profile.cpp profile.h

network.o: network.cpp network.h

clean:
	rm -f main.o tests.o profile.o network.o