all: fibonacci clean

fibonacci: fibonacci.h fibonacci.cpp
	g++ -Wall -Werror -pedantic -c fibonacci.cpp

clean: *.o
	rm *.o
