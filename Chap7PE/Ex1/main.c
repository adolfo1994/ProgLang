#include <stdio.h>

int fun(int *k) {
    *k += 4;
    return 3 * (*k) - 1;
}

void main() {
    int i = 10;
    int j = 10;
    int sum1, sum2;
    sum1 = (i / 2) + fun(&i);
    printf("Sum1 is: %i\n", sum1);
    sum2 = fun(&j) + (j / 2);
    printf("Sum2 is: %i\n", sum2);
    /*
    Resultado:
    
    Sum1 is: 46
    Sum2 is: 48

    Se ve que la evaluacion es en orden por lo que en el 
    primer caso se hace lo siguiente:
    1.- i/2 = 5
    2.- El valor de i=14
    3.- fun(&i) = 41 
    4.- Finalmente el resultado es 46 porque se suma (1) y (3) 
    Mientras que en el segundo caso se llama primero a fun entonces
    se da lo siguiente
    1.-j = 14
    2.-fun(&j) = 41
    3.-j/2 = 7
    4.-Finalmente el resultado es 48 porque se suma (2) y (3)
    */
}