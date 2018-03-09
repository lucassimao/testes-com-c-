#include <iostream>
#include <vector>
#include <complex>

using namespace std;

enum Type { str, num };

Type& operator++(Type& t){

    switch(t){
        case Type::num: return t = Type::str;
        case Type::str: return t = Type::num;
    }
};

union Value {
    const char* s;
    int i;
};

struct Entry{
    const char* name;
    Type t;
    Value v;
};

int main(){

    Entry p;
    string s1 = "mjkjkljkljlk";
    p.name = s1.c_str();
    p.t = str;
    p.v.s = s1.c_str();
    // p.v.i = 22;
    cout << p.v.s << endl;
    return 0;
}