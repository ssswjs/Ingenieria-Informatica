
   // CIRCUNFERENCIA

// Calcula el área y la longitud de una circunferencia a partir de su radio.

#include <iostream>
#include <cmath>
using namespace std;

int main() {
   // Constantes
   const double PI = 6 * asin(0.5);
   // Entrada
   double radio;
   // Salida
   double area, longitud;

   cout << "Introduzca el radio de la circunferencia: ";
   cin >> radio;

   longitud = 2 * PI * radio;
   area = PI * pow(radio,2);

   cout << "La circunferencia tiene una longitud de " << longitud
        << "unidades métricas y el cí­rculo que forma, un área de "
        << area << "unidades métricas.";
}
