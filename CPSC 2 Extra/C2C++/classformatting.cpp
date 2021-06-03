#include <iostream>
#include <iomanip>
using namespace std;

int main () {

  double first = 10.5673849;
  double second = 357.950;
  double third = 16451589.09;

  cout << setw(11) << first << setw(10) << second << endl;
  cout << third << endl;
  cout << showpoint << second << endl;
  cout <<setprecision(4) << first << endl;
  cout << third << endl;
  cout << fixed << third << endl;

return 0;



}
