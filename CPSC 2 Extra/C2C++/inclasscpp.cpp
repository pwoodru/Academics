#include <iomanip>
#include <iostream>
#include <fstream>
#define SIZE 5
using namespace std;

int main(int argc, char* argv[]) {

int numerator = 25;
int denominator = 10;
int sz;
int i = 0;

ifstream input(argv[1]);
ofstream output(argv[2]);

float result = (static_cast<float>(numerator))/denominator;

output << fixed << showpoint << "Result is " << setprecision(2) << result << endl;

float arr[SIZE];

for (auto& i : arr) {
input >> i;
output << fixed << setw(7) << setprecision(4) << i << endl;
}

input.close();
output.close();

return 0;
}
