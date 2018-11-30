
   // LEY DE OHM

// Calcula el voltaje según la Ley de Ohm: voltaje = intensidad * resistencia

#include <iostream>
using namespace std;

int main() {
   // Entrada
   double intensidad, resistencia;
   // Salida
   double voltaje;

   cout << "Introduzca la intensidad: ";
   cin >> intensidad;
   cout << "Introduzca la resistencia: ";
   cin >> resistencia;

   voltaje = intensidad * resistencia;

   cout << "\nEl voltaje vale " << voltaje << ".";
}
