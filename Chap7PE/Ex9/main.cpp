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