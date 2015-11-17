#include <iostream>

using namespace std;

int func(int &a){
    a += 1;
    return (a * (a+1))/2;
}

int main(int argc, char const *argv[])
{
    int a = 5;
    cout<< a + func(a)<<endl; // 5 + 21 = 26 o 6 + 21 = 27 
    /*
    Imprime 27
    ya que primero llama a la funcion antes de resolver a los operandos
    a incrementa en 1 en la función y despues se usa el valor alterado de a
    para hacer la suma en main
    */  
    return 0;
}