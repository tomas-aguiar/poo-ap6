// matrix.h (header file)
#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>

using namespace std;

template <class T> 
class Matrix;

template <class T>
ostream& operator<<(ostream&, const Matrix<T>&);

template <class T>
class Matrix 
{
    private: 
        T **matrix;			// m é um array 2D a ser implementado como um ponteiro de ponteiros.
        int rowNum;         // número de linhas.
        int colNum;         // número de colunas.

    public: 
        // Contrutores
        Matrix();
        // Matrix(int rows, int cols, double elem = 2.5);
        Matrix(int rows, int cols);
        Matrix(int rows, int cols, const T& valor);
        Matrix(const Matrix &matrix);

        // Destrutor
        ~Matrix();

		friend ostream& operator<< <>(ostream&, const Matrix<T>&);

        // Basic getters
		void allocate(const int, const int);
        T rows() const;
        T cols() const;

        // Other methods
        Matrix transpose();
        void print() const;
        T& operator()(const int, const int) const;
		void zeros();
};

#endif
