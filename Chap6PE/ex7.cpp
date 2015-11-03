#include <iostream>
#include <chrono>

#define N 10000

using namespace std;

int my_array[N][N] = {0};

/**
La diferencia en ejecución es bastante similar, con la aritmetica de punteros siendo
marginalmente mejor, pero esta genera menor legibilidad y confiabilidad

Index access took: 204.231ms
Pointer access took: 206.996ms
**/

void index_access() {
  for(int i = 0; i < N ; ++i){
    for(int j = 0; j < N ; ++j){
      my_array[i][j];
    }
  }
  return;
}

void pointer_access() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      *(my_array + i * N + j);
    }
  }
  return;
}

int main() {
  auto start_index =  chrono::steady_clock::now();
  index_access();
  auto end_index =  chrono::steady_clock::now();
  auto index_duration = end_index - start_index;
  cout<<"Index access took: "<< chrono::duration <double, milli> (index_duration).count()<<"ms"<<endl;


  auto start_pointer =  chrono::steady_clock::now();
  pointer_access();
  auto end_pointer =  chrono::steady_clock::now();
  auto pointer_duration = end_pointer - start_pointer;
  cout<<"Pointer access took: "<< chrono::duration <double, milli> (pointer_duration).count()<<"ms"<<endl;


  return 0;
}