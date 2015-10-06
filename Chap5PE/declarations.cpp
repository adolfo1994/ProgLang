#include <iostream>

using namespace std;

void func(){
    x = 21;
    int x;
    x = 42;
    cout<< "X: "<< x<<endl;
}


int main(int argc, char const *argv[])
{
    func();
    return 0;
}
/*

Igual que en C, se genera un error debido a que se referencia a x sin haberse declarado antes.

declarations.cpp: In function ‘void func()’:
declarations.cpp:6:5: error: ‘x’ was not declared in this scope
     x = 21;
     ^


*/