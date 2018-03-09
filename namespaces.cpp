#include <iostream>
#include <vector>
#include <complex>

using namespace std;

double square(double x){
    return x*x;
}

int main(){
    vector<int> xpto {1,2,3,4,5};
    complex<double> z {4,-4};
    auto test = z;

    cout << "square of 100 is " << square(100) << endl;
    cout << "size of char " << sizeof(char) << endl;
    cout << "size of int " << sizeof(int) << endl;
    cout << "size of double " << sizeof(double) << endl;
    cout << "complex " << z << endl;
    
    
    return 0;
}