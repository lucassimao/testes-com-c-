#include <iostream>
#include <vector>
#include <complex>

using namespace std;

struct Vetor{
    int sz;
    double* elem;
};


void init_vetor(Vetor& v, int s){
    v.sz = s;
    v.elem = new double[s];
}

double read_and_sum(int s){
    Vetor v;
    init_vetor(v,s);
    for(int i=0;i< s;++i)
        cin >> v.elem[i];

    double sum;
    for(int i=0;i< s;++i)
        sum += v.elem[i];
    return sum;
}

int main(){
    Vetor v1;
    cout << read_and_sum(5) << endl;

    return 0;
}