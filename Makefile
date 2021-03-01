all: matrix main clean

matrix: matrix.h
	g++ -Wall -Werror -c matrix.cpp
main: matrix.o main.cpp
	g++ -Wall -Werror -o main matrix.o main.cpp
clean: matrix.o
	rm matrix.o