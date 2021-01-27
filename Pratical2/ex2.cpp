#include <iostream>
using namespace std;

float myFunction(double a, double v, double t, double x_0)
{
  return x_0 + v * t + 1.0 / 2 * a * t * t;
}

int main()
{
  double a;
  double v;
  double t;
  double x_0;
  double delta;
  int times;
  float currentTime;
  
  cout << "Enter the acceleration: " << endl;
  cin >> a;
  cout << "Enter the speed: " << endl;
  cin >> v;
  cout << "How many times do you want to display the position of the moving body? " << endl;
  cin >> times;
  cout << "How often (in seconds) do you want to update the position of the moving object? "<< endl;
  cin >> delta;

  cout << endl
  << "Acceleration: " << a << " Initial speed: " << v << " Initial position: " << x_0 << " Number of times: " << times << " Delta: " << delta << endl;

  for (int i = 0, currentTime = 0.0; (i < times); i++, currentTime += delta){
    cout << "At time " << currentTime << " the position is " << myFunction(x_0, v, currentTime, a) << endl;
        
  }
  return 0;
}
