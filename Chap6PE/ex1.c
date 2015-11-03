#include <stdio.h>

int main(int argc, char const *argv[])
{
    int myInt = 1;
    long int myLong1 = 9876543210;
    long int myLong2 = myInt;
    myInt = myLong1;
    printf("myLong2: %d\n", myLong2 );
    printf("myInt: %d\n", myInt);
    /*
    El compilador no verifica los diferentes tipos de entero
    los cuales tienen diferentes capacidades por lo que se debe 
    tener cuidado en su uso ya que al desbordar, los valores cambian

    myLong2: 1
    myInt: 1286608618
    */



    float myFloat = 0.1;
    double myDouble = 0.123456789;
    double myDouble2 = myFloat;
    myFloat = myDouble;
    printf("myDouble2: %f\n", myDouble2 );
    printf("myFloat: %f\n", myFloat);
    /*
    Existe compatibilidad entre tipos float y double
    pero estos presentan diferente presicion por lo 
    que se debe ser cuidadoso al utilizar ambos tipos
    
    * myDouble2 = 0.100000 
    * float_ = 0.123457
    */


    return 0;
}