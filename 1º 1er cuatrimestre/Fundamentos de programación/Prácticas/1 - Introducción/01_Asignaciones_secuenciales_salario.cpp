
   // ASIGNACIONES SECUENCIALES - SALARIO

// ¿El hecho de realizar la asignación "salario_final = salario_base;""
// hace que ambas variables estén ligadas durante todo el programa y que
// cualquier modificación posterior de salario_base afecte a salario_final?

#include <iostream>
using namespace std;

int main() {
   int salario_base;
   int salario_final;
   int incremento;

   salario_base = 1000;
   incremento = 200;

   salario_final = salario_base;
   salario_final = salario_final + incremento;

   salario_base = 3500;

   cout << "\nSalario base: " << salario_base;
   cout << "\nSalario final: " << salario_final;
}

/*
   La asignación "salario_final = salario_base" no liga ambas variables a lo
   largo del programa, sino que iguala el valor de salario_final al que tiene
   salario_base en el momento de ejecutarse la sentencia.
*/
