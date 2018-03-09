#include <iostream>
#include <string.h>

using namespace std;

double square(double x){
    return x*x;
}

int count_char(char* p, char x){
    if (p == nullptr) return 0;
    int count = 0;
    while(*p){
        if (*p==x) ++count;
        ++p;
    }
    return count;
}

int main(){
    constexpr int primos[] = {1,3,5,7,11};
    double* pd = nullptr;

    for(auto& x : primos)
        cout << " square of " << x << " is " << square(x) << endl;
    
    string str = "lsimaocosta@trt22-ubuntu:~/workspace/c++_tests$ ./loop-do-mal";
    char* chr = strdup(str.c_str());
    cout << count_char(chr,'a') << endl;
    free(chr);
    return 0;
}