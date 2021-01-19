#include <iostream>
#include <cmath>
using namespace std;

int main() {
  float cx, cy, r, x, y, d;
  cout << "Entrez la coordonnée x du centre" <<endl;
  cin >> cx;
  cout << "Entrez la coordonnée y du centre" <<endl;
  cin >> cy;
  cout << "Entrez le radius du cercle" << endl;
  cin >> r;
  cout << "Entrez la coordonnée x du point" << endl;
  cin >> x;
  cout << "Entrez la coordonnée y du point" << endl;
  cin >> y;

  d = sqrt((cx - x) * (cx - x) + (cy - y) * (cy - y ));
  cout << "La distance entre le centre et le point est :" << d << endl;

  if( d <= r)
    cout << "Le point est dans le cercle " << endl; 
  else 
    cout << "Le point n'est pas dans le cercle" << endl;
}




