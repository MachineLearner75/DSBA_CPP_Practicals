#include <cmath>
#include <iostream>
using namespace std;

void print_poly(double *c, int n) {
    int i;
    cout << c[0];
    if (n > 0)
        cout << " + ";
    for (i = 1; i < n; i++)
        cout << c[i] << "*x^" << i << " + ";
    if (n > 0)
        cout << c[n] << "*x^" << i;
    cout << endl;
}

double *read_poly(int &n) {
    cout << "Le degré: ";
    cin >> n;
    double *c = new double[n + 1];
    for (int i = 0; i <= n; i++) {
        cout << "Les coefficients du polynome " << i << ": ";
        cin >> c[i];
        //cout << c[i] << " ";
    }
    return c;
}

//double *create_poly(int &n, double *c) {
  //  double *d = new double[n + 1];
    //for (int i = 0; i <= n; i++) {
      //  for (int j = 0; j <= n; j++)
        //    d[j] = c[i] * pow(2, j);
        //cout << d[i] << " ";
    //}
   // return d;
//}

double *poly_sum(double *p1, int d1, double *p2, int d2, int &dr) {
    dr = max<int>(d1, d2);
    double *ret = new double[dr];
    int i;

    for (i = 0; i < dr; i++) {
        if (d1 >= i) {
            ret[i] += p1[i];
        }
        if (d2 >= i) {
            ret[i] += p2[i];
        }
    }

    if (dr > 0) {
        ret[i] += i <= d1 ? p1[i] : 0;
        ret[i] += i <= d2 ? p2[i] : 0;
    }

    return ret;
}

double image_x(double *c, int n, double x) {
    // avoid index out of bounds
    if (n < 1) return 0.0;

    int i;
    double ret = c[0];
    for (i = 1; i < n; i++)
        ret += c[i] * pow(x, i);
    if (n > 0)
        ret += c[n] * pow(x, i);

    return ret;
}

double *poly_product(double *p1, int d1, double *p2, int d2, int &dr) {
    dr = d1 + d2;
    double *ret = new double[dr];
    int i, j;

    for (i = 0; i <= d1; i++) {
        for (j = 0; j <= d2; j++) {
            ret[i + j] += p1[i] * p2[j];
        }
    }

    if (dr >= 0) {
        ret[i + j] += (i < d1 ? p1[i] : 0) * ((j < d2 ? p2[j] : 0));
    }

    return ret;
}

int main() {
    double *p1, *p2, *p3;
    int d1, d2, d3;
    
    //ex1 :
    int x;
    cout << "Entrez la valeur de x souhaitée : " << "";
    cin >> x; 
    p1 = read_poly(d1);
    print_poly(p1, d1);
    cout << endl;
    cout << image_x(p1, d1, x) << endl;

    delete[] p1;
    
    //ex2 :
    //p1 = read_poly(d1);
    //p2 = read_poly(d2);
    //print_poly(p1, d1);
    //print_poly(p2, d2);
    //p3 = poly_sum(p1, d1, p2, d2, d3);
    //print_poly(p3, d3);
    //delete[] p1;
    //delete[] p2;
    //delete[] p3;

    //ex3 :
    //p1 = read_poly(d1);
    //print_poly(p1, d1);
    //p2 = read_poly(d2);
    //print_poly(p2, d2);
    //cout << endl;
    //p3 = poly_product(p1, d1, p2, d2, d3);
    //print_poly(p3, d3);
    //delete[] p1;
    //delete[] p2;
    //delete[] p3;

    return 0;
}
