
   // CÁLCULO DE PI A PARTIR DEL ARCO-SENO

// Demostración del cálculo de PI como constante a partir del arcocoseño de 1/2.

#include <iostream>
#include <cmath>
using namespace std;

int main() {
   const double PI = 6 * asin(0.5);

   cout << PI;
}
