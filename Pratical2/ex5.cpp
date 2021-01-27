#include <iostream>
using namespace std;

long Fibonacci1(unsigned long n){
  int a=0;
  int b=1;
  int result;

  for(int i=0; i < n-1; i++){
    result = (a+b);
    a = b;
    b = result;
  }
  return result;
}

int main() {

  unsigned long n = 2;
  cout << Fibonacci1(n) << endl;
  
  return 0;

}