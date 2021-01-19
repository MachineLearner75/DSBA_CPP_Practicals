#include <iostream>
using namespace std;

int recursiveCall = 0;

long Power1(int a, unsigned int n){
  recursiveCall++;

  if (n == 0){
    return 1;
  }
  else{
    return a*Power1(a, n-1);
  }
}

long Power2(int a, unsigned int n){
  recursiveCall++;

  if (n == 0){
    return 1;
  }
  else if (n % 2 == 0){
    return Power2(a, n/2)*Power2(a, n/2);
  }
  else{
    return Power2(a, n/2)*Power2(a, n/2); //problem on recursion here
  }
}

int main() {
  int a = 5;
  unsigned int n = 3;
  cout << Power1(a, n)<< endl;
  
}