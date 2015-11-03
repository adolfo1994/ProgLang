#include <stdio.h>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;
/**
  $ ./nocheckrange.out 
  The operation took: 3797.66ms
  $ ./checkrange.out 
  The operation took: 11214ms
  
  Como se puede observar, al usar el flag en el compilador que realize 
  verificaciones, se agrega un overhead considerable al tiempo de 
  ejecución 

**/


int main() {

  std::vector< std::vector<int> > test(
    25000,
    std::vector<int>(25000)
  );
  auto start_time =  chrono::steady_clock::now();

  for (int i = 0; i < 25000; ++i) {
    for (int j = 0; j < 25000; ++j) {
      test[i][j] += i * j;
    }
  }
  auto end_time =  chrono::steady_clock::now();
  auto diff = end_time - start_time;
  cout<<"The operation took: "<< chrono::duration <double, milli> (diff).count()<<"ms"<<endl;

  return 0;
}