#include <iostream>

using namespace std;

class Matrix{
    public:
        Matrix* operator*(double n);   
        Matrix(int rows, int columns);
        Matrix(int rows, int columns,int defaultValue);
        Matrix* operator+(Matrix& another);
        void set(int i, int j, int value);
        int get(int i, int j); 
        friend ostream& operator<<(ostream& os, Matrix& mtx);  
    private:
        int nrows, ncolumns;
        int *elements;   
};