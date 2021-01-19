#include <iostream>
using namespace std;

 void Swap(int x, int y, int temp){
    temp = y;
    y = x;
    x = temp;

    cout << x << endl;
    cout << y << endl;
  }


int main() {
  
  Swap(2, 3, 0);
  
  return 0;
}