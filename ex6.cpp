#include <iostream>
using namespace std;

int callCount = 0;

long Fibonacci2(unsigned long n){
  
  callCount++;
  if (n == 0){
    return 0;
  }
  else if (n == 1){
    return 1;
  }
  else{
    return Fibonacci2(n - 1) + Fibonacci2(n - 2);
  }  
}

int main() {
  unsigned long n = 5;

  cout << "The " << n << " th number of the Fibonacci sequence is : " << Fibonacci2(n) << endl;
  cout << "To compute it, we called the function " << callCount << " times" << endl; 


  return 0;
}