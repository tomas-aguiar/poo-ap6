// matrix.cpp
#include <stdexcept>

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
Matrix<T>::Matrix(int rows, int cols)
{
    rowNum = rows;
    colNum = cols;

    // Aloca memória para a matriz
    matrix = new double*[rowNum];
    for (int i = 0; i < rowNum; i++)
        matrix[i] = new double[colNum];
}

template<class T>
Matrix<T>::Matrix(int rows, int cols, const T& valor)
{
    rowNum = rows;
    colNum = cols;

    // Aloca memória para a matriz
    matrix = new double*[rowNum];
    for (int i = 0; i < rowNum; i++)
        matrix[i] = new double[colNum];

    // Assinala elem para toda a matriz
    for (int i = 0; i < rowNum; i++)
    {
        for (int j = 0; j < colNum; j++)
            matrix[i][j] = *valor;
    }
}

template<class T>
Matrix<T>::Matrix(const Matrix &matrix)
{
    rowNum = matrix.getRows();
    colNum = matrix.getCols();
    this.matrix = matrix;
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
T& Matrix<T>::operator()(cont int row, cont int col) const
{
    if ((rowNum <= row) || (colNum <= col))
        throw std::invalid_argument("Index out of bounds.");

    return *(matrix[row][col]);
}

template <class T>
ostream& operator<<(ostream &os, const Matrix<T> &matrix)
{
    for (int i = 0; i < rowNum; i++)
    {
        for (int j = 0; j < colNum; j++)
            os << matrix(i, j) << " ";
        os << endl;
    }

    return os;
}
