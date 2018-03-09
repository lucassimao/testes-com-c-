#include <iostream>
#include "matrix.h"

using namespace std;

int main(){
    Matrix A(30,3);
    Matrix B(3,3,100);
    Matrix *C = B * 3;
    

    A.set(1,1,1);
    A.set(2,2,1);
    A.set(3,3,1);
    A.get(3,3);

    cout << A << endl;
    cout << B << endl;
    cout << *C << endl;
    
    
    Matrix *soma = A + B;
    soma = *soma + *C;
    cout << *soma << endl;
    return 0;
}