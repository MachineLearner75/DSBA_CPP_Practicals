#include <iostream>
using namespace std;
#include <stdio.h>
#include <string> 

bool criteria = true;
void myfunction(string str){
    for(int i = 0; i < size(str); i++){
      if(str[i] < '0' || str[i] > '9'){
        criteria = false;
        break;

      }
      
    }
    if(criteria == false)
      cout << "Le string contient des lettres" << endl;
    else
      cout << "Le string ne contient que des chiffres" << endl;
}

int main(){

    string a {"5642567"};
    myfunction(a);
}