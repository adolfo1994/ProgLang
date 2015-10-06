#include <iostream>
#include <chrono>

using namespace std;


void static_array(){
    int myArray [10000];
}
void stack_array(int n){
    int myArray[n];
}
void heap_array(int n){
    int* myArray = new int[n];
    delete[] myArray;
}


int main(int argc, char const *argv[])
{
    auto static_start =  chrono::steady_clock::now();
    for (int i = 0; i < 100000; ++i)
    {
        static_array();
    }
    auto static_end =  chrono::steady_clock::now();
    auto diff = static_end - static_start;
    std::cout<<"Static Array example took: "<< chrono::duration <double, milli> (diff).count()<<"ms"<<endl;

    auto stack_start =  chrono::steady_clock::now();
    for (int i = 0; i < 100000; ++i)
    {
        stack_array(10000);
    }
    auto stack_end =  chrono::steady_clock::now();
    auto diff2 = stack_end - stack_start;
    std::cout<<"Stack Array example took: "<< chrono::duration <double, milli> (diff2).count()<<"ms"<<endl;

    auto heap_start =  chrono::steady_clock::now();
    for (int i = 0; i < 100000; ++i)
    {
        heap_array(10000);
    }
    auto heap_end =  chrono::steady_clock::now();
    auto diff3 = heap_end - heap_start;
    std::cout<<"Heap Array example took: "<< chrono::duration <double, milli> (diff3).count()<<"ms"<<endl;

    return 0;
}

/*
Los tiempo requeridos son:
Static Array example took: 0.243218ms
Stack Array example took: 1.40731ms
Heap Array example took: 5.93191ms

Al parecer los arrays estaticos son los mas eficientes ya que al compilar permiten hacer 
optimizaciones, ya que se sabe que no van a cambiar.
Luego los stack arrays siguen en velocidad ya que su acceso es mas rapido que en los arrays en heap,
cuya asignación es mas lenta y ademas van a implicar un borrado manual usando delete 
*/