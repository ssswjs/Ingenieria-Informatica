
   // CONVERSIÓN DE GRADOS A RADIANES

// Convierte una medida de ángulos en grados a radianes mediante el uso de
// constantes.

#include <iostream>
#include <cmath>
using namespace std;

int main() {
   // Constantes
   const double PI = 6 * asin(0.5);
   const double GRADOS_A_RADIANES = PI / 180;
   // Entrada
   double grados1, grados2;
   // Salida
   double radianes1, radianes2;

   cout << "Introduzca dos ángulos en grados separados por espacios: ";
   cin >> grados1 >> grados2;

   radianes1 = grados1 * GRADOS_A_RADIANES;
   radianes2 = grados2 * GRADOS_A_RADIANES;

   cout << "\nSu primer ángulo mide " << radianes1 << " radianes.";
   cout << "\nSu segundo ángulo mide " << radianes2 << " radianes.";
}
