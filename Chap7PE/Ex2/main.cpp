#include <iostream>

using namespace std;

int fun(int *k) {
    *k += 4;
    return 3 * (*k) - 1;
}

int main() {
    int i = 10;
    int j = 10;
    int sum1, sum2;
    sum1 = (i / 2) + fun(&i);
    cout << "Sum1 is: " << sum1 << endl;
    sum2 = fun(&j) + (j / 2);
    cout << "Sum2 is: " << sum2 << endl;
    return 1;
    /*
    Resultado:
    
    Sum1 is: 46
    Sum2 is: 48

    En C++ es el mismo caso que en C, los operando se 
    evaluan en orden por lo que el resultado es el 
    mismo.

    Primer Caso
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