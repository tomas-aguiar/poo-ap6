// matrix.cpp
#include <stdexcept>
#include <sstream>

#include "matrix.h"

using namespace std;

// Construtor default - cria uma matriz vazia
template<class T>
Matrix<T>::Matrix() 
{
    rowNum = 0;
    colNum = 0;
    matrix = NULL;
}

// Sobrecarga do construtor - cria uma matriz com:
//      rowNum = rows, colNum = cols 
//      e M[i][j] = elem, pra todos i e j.
// Matrix::Matrix(int rows, int cols, double elem) 
// {
//     rowNum = rows;
//     colNum = cols;

//     // Aloca memória para a matriz
//     matrix = new double*[rowNum];
//     for (int i = 0; i < rowNum; i++)
//         matrix[i] = new double[colNum];

//     // Assinala elem para toda a matriz
//     for (int i = 0; i < rowNum; i++)
//     {
//         for (int j = 0; j < colNum; j++)
//             matrix[i][j] = elem;
//     }
// }

template<class T>
void Matrix<T>::allocate(const int rows, const int cols)
{
    // Aloca memória para a matriz
    // matrix = new double*[rowNum];
	matrix = new T*[rowNum];
    for (int i = 0; i < rowNum; i++)
        // matrix[i] = new double[colNum];
		matrix[i] = new T[colNum];
}

template<class T>
Matrix<T>::Matrix(int rows, int cols)
{
    rowNum = rows;
    colNum = cols;
	allocate(rows, cols);
}

template<class T>
Matrix<T>::Matrix(int rows, int cols, const T& valor)
{
    rowNum = rows;
    colNum = cols;
	allocate(rows, cols);

    // Assinala elem para toda a matriz
    for (int i = 0; i < rowNum; i++)
    {
        for (int j = 0; j < colNum; j++)
            matrix[i][j] = valor;
    }
}

template<class T>
Matrix<T>::Matrix(const Matrix &matrix)
{
    rowNum = matrix.rows();
    colNum = matrix.cols();
    this->matrix = matrix.matrix;
}

// Destrutor
template<class T>
Matrix<T>::~Matrix() 
{
    // Desaloca memória da matriz
    if (rowNum > 0) 
    {
        for (int i = 0; i < rowNum; i++)
            delete [] matrix[i];
        delete [] matrix;
    }
}

// Obtem o número de linhas
template<class T>
T Matrix<T>::rows() const 
{
    return rowNum;
}

template<class T>
T Matrix<T>::cols() const
{
    return colNum;
}

// Retorna uma matriz transposta
template<class T>
Matrix<T> Matrix<T>::transpose()
{
    // Cria a nova matriz
    Matrix placeHolder(colNum, rowNum);

    // Transpõe a matriz antiga na nova
    for (int i = 0; i < colNum; i++)
    {
        for (int j = 0; j < rowNum; j++)
        {
            placeHolder.matrix[i][j] = matrix[j][i];
        }
    }

    return placeHolder;
}

// Imprime o conteúdo da matriz
// template<class T>
// void Matrix<T>::print() const 
// {
//     for (int i = 0; i < rowNum; i++)
//     {
//         for (int j = 0; j < colNum; j++)
//             cout << matrix[i][j] << " ";
//         cout << endl;
//     }
// }

template<class T>
T& Matrix<T>::operator()(const int row, const int col) const
{
    if ((rowNum <= row ) || (colNum <= col))
        throw std::invalid_argument("Index out of bounds.");

    return matrix[row][col];
}

template <class T>
void Matrix<T>::zeros()
{
	for (int i = 0; i < rowNum; i++)
	{
		for (int j = 0; j < colNum; j++)
			matrix[i][j] = 0;
	}
}

template <class T>
ostream& operator<<(ostream &os, const Matrix<T> &matrix)
{
    for (int i = 0; i < matrix.rows(); i++)
    {
        for (int j = 0; j < matrix.cols(); j++)
            os << matrix(i, j) << " ";
        os << endl;
    }

    return os;
}

template class Matrix<double>;
template class Matrix<float>;
template ostream& operator<<(ostream&, const Matrix<double>&);
template ostream& operator<<(ostream&, const Matrix<float>&);

