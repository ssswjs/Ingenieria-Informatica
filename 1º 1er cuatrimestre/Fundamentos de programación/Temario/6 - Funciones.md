<center><h1>FUNCIONES</h1></center>
<center><b>Fundamentos de programación</b></center>

## INTRODUCCIÓN

Las funciones son estructuras que permiten agrupar en una sola pieza de código una serie de sentencias que se van ejecutar varias veces, ya sea de la misma manera o con algunas variaciones.

Por ejemplo, en lugar de tener que escribir siempre este tochazo:

```c++
if (x == 0 || x == 1) {
   result = x;
}
else {
   for (int i = 1, result = 1; result <= x; i++) {
      result = i * i;
   }
}
```

Podemos simplemente importar una función definida en una biblioteca:

```c++
#include <cmath>

...

result = sqrt(x);
```

Otro ejemplo, vamos a calcular el módulo de dos vectores:

```c++
int main() {
   int v1_A, v1_B, v2_A, v2_B;
   double modulo1, modulo2;
   
   ...
   
   modulo1 = sqrt(pow(v1_A, 2) + pow(v1_B, 2));
   modulo2 = sqrt(pow(v2_A, 2) + pow(v2_B, 2));
}
```

En este caso los cálculos son muy similares y pueden dar errores. Para evitar esto, trabajaremos con funciones.

## DEFINICIÓN

Para definir una función seguimos la siguiente estructura:

```
[tipo de dato] [nombre de la función]([parámetros formales]) {
   [sentencias]
   return [expresión];
}
```

###### Visto esto, podemos ver que `int main() {}` es una función.

Llamamos **cabecera** o *header* a línea de la función en la que se declaran su tipo, su nombre y sus parámetros.

La definición de funciones debe hacerse antes que la función `main`, ya que para poder llamar a una función esta debe haber sido declarada previamente en el código.

Por convención, nombramos las funciones con **UpperCamelCase**, excepto `main`, que va siempre en minúscula.

## PARÁMETROS DE UNA FUNCIÓN

Las funciones pueden tener dos tipos de parámetros:
- **Parámetros formales:** *Formal parameters*. Se especifican en la cabecera de la función y son aquellos con los que tratará la función. Se debe especificar su tipo de dato al declararlos y separarlos con comas si hubiera más de uno.
- **Parámetros reales:** *Actual parameters*. Son las expresiones que se pasan a la función cuando se la llama desde el código. También se separan por comas pero no se especifica su tipo.

Como ejemplo muy sencillo para diferenciar ambos parámetros, vamos a hacer una función que sume 1 a un entero:

```c++
int Funcion(int parametro_formal) {
   return ++parametro_formal;
}

int main() {
   int parametro_real, masuno;
   
   cin >> parametro_real; // Introducimos 5
   
   masuno = Funcion(parametro_real);
   
   cout << "\n" << masuno; // Devuelve 6
}
```

Fíjate en que `parametro_real` va a seguir valiendo `5`, porque no se ha producido ninguna asignación sobre su valor aunque se haya utilizado para trabajar en las funciones.

Como puedes ver, el programa evalúa qué parámetros reales corresponden a qué parámetros formales y opera con ellos. Si tenemos más de un parámetro formal, se evalúan en orden. Por ejemplo:

```c++
int RestaDos(int valor1, int valor2) {
   return valor1 - valor2;
}

int main() {
   int numero1, numero2, resultado;
   
   cin >> numero1 >> numero2; // 3 y 4 -- 4 y 3
   
   resultado = RestaDos(numero1, numero2);
   
   cout << "\n" << resultado; // -1 -- 1
}
```

Es muy importante que los nombre de los parámetros formales y los reales no coincidan y que se llame a las funciones con tantos parámetros reales como parámetros formales tengan declarados. Un fallo en cualquiera de estas partes resultará en un error de compilación.

Los parámetros reales deben ser **del mismo tipo o de un tipo compatible** a los formales para poder operar con ellos. De no serlo, se provocan errores lógicos.

También podemos realizar operaciones en los parámetros reales, pero esto es muy poco recomendable, pues parte el trabajo de la función en dos sectores completamente distintos del código.

```c++
double CalcHip(int valor1, int valor2) {
   return sqrt(valor1 + valor2); // Tenemos que confiar en que la
}                                // llamada a la función sea correcta

int main() {
   int lado1, lado2, hipotenusa;
   
   cin >> lado1 >> lado2;
   
   hipotenusa = CalcHip(pow(lado1, 2), pow(lado2, 2))
}
```

Dentro de una función no se pueden declarar otras funciones, pero sí se puede llamar a otras **previamente declaradas**, de otra forma se produce un error de compilación. Ampliemos el ejemplo anterior:

```c++
int Cuadrado(int factor) {
   return pow(factor, 2);
}

double CalcHip(int valor1, int valor2) {
   return sqrt(Cuadrado(valor1) + Cuadrado(valor2));
}

int main() {
   int lado1, lado2, hipotenusa;
   
   cin >> lado1 >> lado2;
   
   hipotenusa = CalcHip(lado1, lado2)
}
```

Las funciones **deben devolver siempre un valor**. Una función que tenga casos en los que

<center><h3>UNIVERSIDAD DE GRANDA</h3></center>