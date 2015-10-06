#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int sum = 0;
    for (int i = 0; i < 100; ++i)
    {
        sum += i;
    }
    cout<<i<<endl;
    return 0;
}
/*
Al compilar se genera lo siguiente:
for_scope.cpp: In function ‘int main(int, const char**)’:
for_scope.cpp:12:11: error: name lookup of ‘i’ changed for ISO ‘for’ scoping [-fpermissive]
     cout<<i<<endl;
           ^
for_scope.cpp:12:11: note: (if you use ‘-fpermissive’ G++ will accept your code)

Lo cual indica que las variables declaradas en un for statement, 
son solo validas dentro de ese bloque

Aun utilizando -fpremissive como indica el error de compilación,
se genera un error
for_scope.cpp: In function ‘int main(int, const char**)’:
for_scope.cpp:12:11: warning: name lookup of ‘i’ changed for ISO ‘for’ scoping [-fpermissive]
     cout<<i<<endl;
           ^
for_scope.cpp:8:14: warning:   using obsolete binding at ‘i’ [-fpermissive]
     for (int i = 0; i < 100; ++i)
              ^

*/