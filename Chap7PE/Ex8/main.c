#include <stdio.h>

int a, b;

int fun(){
    a += 10;
    return a;
}

int main(int argc, char const *argv[])
{

    a = 10;
    b = a + fun();
    printf("With the function call on the right, ");
    printf(" b is: %d\n", b);
    
    a = 10;
    b = fun() + a;
    printf("With the function call on the left, ");
    printf(" b is: %d\n", b);

    return 0;
}
/*
    Resultado:
    With the function call on the right,  b is: 40
    With the function call on the left,  b is: 40
    En C parece que se resuleve siempre primero la función
    entonces el valor de a era 10, se le suma 10 en la funcion y esta retorna 20
    luego se evalua a y esta tambien vale 20 por lo que el resultado final es 40    

*/