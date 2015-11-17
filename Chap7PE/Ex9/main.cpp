#include <iostream>
#include <random>
#include <chrono>

using namespace std;
#define ARRAY_SIZE 25000

int fun1(){
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, ARRAY_SIZE);

    int* randoms = new int[ARRAY_SIZE] ;
    int** mult_matrix = new int*[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        randoms[i] = dist(mt);
    }

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        mult_matrix[i] = new int[ARRAY_SIZE];
        for (int j = 0; j < ARRAY_SIZE; ++j)
        {
            mult_matrix[i][j] = randoms[i] * randoms[j]; 
        }
    }
    delete[] randoms;
    delete[] mult_matrix;

}

float fun2(){
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<float> dist(1, ARRAY_SIZE);

    float* randoms = new float[ARRAY_SIZE] ;
    float** mult_matrix = new float*[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        randoms[i] = dist(mt);
    }

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        mult_matrix[i] = new float[ARRAY_SIZE];
        for (int j = 0; j < ARRAY_SIZE; ++j)
        {
            mult_matrix[i][j] = randoms[i] * randoms[j]; 
        }
    }

    delete[] randoms;
    delete[] mult_matrix;

}


int main(int argc, char const *argv[])
{

    auto start_int =  chrono::steady_clock::now();
    fun1();
    auto end_int =  chrono::steady_clock::now();
    auto int_duration = end_int - start_int;
    cout<<"Int operations took: "<< chrono::duration <double, milli> (int_duration).count()<<"ms"<<endl;

    auto start_float =  chrono::steady_clock::now();
    fun2();
    auto end_float =  chrono::steady_clock::now();
    auto float_duration = end_float - start_float;
    cout<<"Float operations took: "<< chrono::duration <double, milli> (float_duration).count()<<"ms"<<endl;

    return 0;
}

/*
    Resultados:

    Int operations took: 2595.57ms
    Float operations took: 2630.8ms           1 int 0 float 

    Int operations took: 2564.42ms
    Float operations took: 2521.63ms           1 int 1 float

    Int operations took: 2524.66ms 
    Float operations took: 2529.48ms             2 int 1 float

    Int operations took: 2576.13ms
    Float operations took: 2577.41ms              3 int 1 float

    Int operations took: 3078.93ms
    Float operations took: 3056.69ms             3 int 2 float
    
    En base a varias pruebas se nota que a pesar que en la mayoria de pruebas las operaciones
    con enteros demoran menos, esta diferencia es casi negable y en algunos casos las de float
    fueron mas rapidas. 
*/