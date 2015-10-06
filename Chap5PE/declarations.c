#include <stdio.h>

void func(){
    x = 21;
    int x;
    x = 42;
    printf("X: %d\n", x);
}


int main(int argc, char const *argv[])
{
    func();
    return 0;
}

/*
Al compilar sale un error en func debido a que se utiliza x sin haberse declarado primero

declarations.c: In function ‘func’:
declarations.c:4:5: error: ‘x’ undeclared (first use in this function)
     x = 21;
     ^
declarations.c:4:5: note: each undeclared identifier is reported only once for each function it appears in


*/