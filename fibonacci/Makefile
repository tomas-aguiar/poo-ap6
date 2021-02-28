all: fibonacci main clean

main: main.cpp fibonacci.o
	g++ -Wall -Werror -pedantic main.cpp fibonacci.o -o main

fibonacci: fibonacci.h fibonacci.cpp
	g++ -Wall -Werror -pedantic -c fibonacci.cpp

clean: *.o
	rm *.o
