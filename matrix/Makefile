all: matrix main clean

matrix: matrix.h
	g++ -Wall -Werror -c matrix.cpp

main: matrix.o main.cpp
	g++ -Wall -Werror matrix.o main.cpp -o main

clean: matrix.o
	rm matrix.o
