#include <iostream>

using namespace std;

enum TestEnum
{
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE
};

int main(int argc, char const *argv[])
{
    cout<< ONE + TWO <<endl; // 3
    cout<< SIX - THREE <<endl; // 3
    cout<< FIVE * EIGHT <<endl // 40
    cout<< SIX / TWO <<endl; // 3
    /*
    Los tipos enumerados soportan las operaciones
    basicas sobre numeros
    */
    TestEnum test = ONE;
    cout<< test<<endl; // 1
    test = TWO;
    cout<< test <<endl; // 2
    test = (TestEnum) 5;
    cout<< test <<endl; // 5

    /*
    Soportan instanciación y asignacion de valores
    definidos en la enumeración
    
    No soportan asignaciones de enteros de manera directa
    test = 5; genera un error
    */

    return 0;
}