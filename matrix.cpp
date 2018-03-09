#include <iostream>
#include <sstream>
#include <stdexcept>
#include "matrix.h"

using namespace std;

Matrix::Matrix(const int rows, const int columns) : nrows{rows}, ncolumns{columns}, elements{new int[rows * columns]}
{
    if (rows < 0 || columns < 0)
        throw length_error {"rows and columns must be > 0"};
    for (int i = 0; i < rows * columns; ++i)
        this->elements[i] = 0;
};

Matrix::Matrix(const int rows, const int columns, const int value) : nrows{rows}, ncolumns{columns}, elements{new int[rows * columns]}
{
    for (int i = 0; i < rows * columns; ++i)
        this->elements[i] = value;
};

Matrix *Matrix::operator+(Matrix &another)
{

    if (another.nrows != this->nrows || another.ncolumns != this->ncolumns)
    {
        std::stringstream sstm;
        sstm << "wrong dimenssions for sum (" << this->nrows << "," << this->ncolumns << ") ";
        sstm << "with (" << another.nrows << "," << another.ncolumns << ")";
        throw out_of_range{sstm.str()};
    }

    Matrix *x = new Matrix(this->nrows, this->ncolumns);
    for (int i = 0; i < (this->nrows * this->ncolumns); ++i)
    {
        x->elements[i] = this->elements[i] + another.elements[i];
    }

    return x;
}

Matrix *Matrix::operator*(double n)
{
    Matrix *x = new Matrix(this->nrows, this->ncolumns);
    for (int i = 0; i < (this->nrows * this->ncolumns); ++i)
    {
        x->elements[i] = this->elements[i] * n;
    }

    return x;
}

void Matrix::set(int i, int j, int value)
{
    if (i > this->nrows)
        throw out_of_range{"number of rows must be lower than " + std::to_string(this->nrows)};

    if (j > this->ncolumns)
        throw out_of_range{"number of columns must be lower than " + std::to_string(this->ncolumns)};

    this->elements[this->nrows * (i - 1) + (j - 1)] = value;
}
int Matrix::get(int i, int j)
{
    if (i > this->nrows)
        throw out_of_range{"number of rows must be lower than " + std::to_string(this->nrows)};

    if (j > this->ncolumns)
        throw out_of_range{"number of columns must be lower than " + std::to_string(this->ncolumns)};
    
    return this->elements[this->nrows * (i - 1) + (j - 1)];
}

std::ostream &operator<<(std::ostream &os, Matrix &foo)
{
    for (int i = 0; i < (foo.nrows * foo.ncolumns); ++i)
    {
        os << foo.elements[i];
        if ((i + 1) % foo.ncolumns != 0)
            os << ',';
        else
            os << endl;
    }
    return os;
}
