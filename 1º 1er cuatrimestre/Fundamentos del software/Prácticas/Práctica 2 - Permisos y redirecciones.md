# PERMISOS Y REDIRECCIONES

## 0 - ÓRDENES LINUX

| **chmod** | **date** |
| :---: | :---: |
| **echo** | **wc** |

`chmod` → Modifica los permisos de un archivo
  - `chmod [permissions][file]` → Cambia los permisos de [file] según el criterio de [permissions]
  - `chmod -c` → Verboso sólo cuando se produce un cambio
  - `chmod -f` → No muestra mensajes de error
  - `chmod -v` → Verboso

`date` → Muestra o determina la fecha y hora del sistema
  - `date` → Muestra la fecha y hora del sistema
  - `date -d=[string]` → Muestra la fecha y hora de [string], no la actual
  - `date -s=[string]` → Cambia la fecha y hora a [string]

`echo` → Muestra una línea de texto
  - `echo [string]` → Muestra [string] en pantalla
  - `echo -n` → No imprime un salto de línea al final
  - `echo -e` → Interpreta caracteres especiales con “\”
  - `echo -E` → No interpreta caracteres especiales con “\”

`wc` → Muestra el número de líneas, palabras y bytes de un archivo
  - `wc [file]` → Muestra el número de líneas, palabras y bytes de [file]
  - `wc -c` → Muestra el número de byes
  - `wc -m` → Muestra el número de caracteres
  - `wc -l` → Muestra el número de líneas
  - `wc -L` → Muestra el número máximo de columnas en una línea
  - `wc -w` → Muestra el número de palabras

## 1 - MODIFICACIÓN DE LOS PERMISOS DE ACCESO

La orden `chmod` permite cambiar los permisos de aquellos archivos de los que se es administrador. Existen dos formas de declarar dicha modificación de archivos:
- **Absoluta u octal:** Representa cada permiso rwx como un bit y da valor de 0 a 7 a los permisos de cada grupo de usuarios.

    rw-rw-r-- → 664 
    rwxr-xr-x → 755

- **Simbólica o textual:** Asigna a cada grupo de usuarios una modificación de los permisos sin afectar a los no determinados. Existen cuatro grupos de usuarios que pueden recibir modificaciones:
  - **u:** Usuario creador del archivo
  - **g:** Grupo de usuarios al que pertenece el creador
  - **o:** Otros usuarios
  - **a:** Todos los usuarios

Para declarar el tipo de cambio sobre los permisos se utiliza uno de dos modificadores:
- `+` → Añade los permisos siguientes
- `-` → Elimina los permisos siguientes

Para declarar el permiso a modificar utilizamos las letras `rwx` vistas anteriormente.

```shell
$ chmod u+x
$ chmod go+r-w
$ chmod a+r,o-w
```

## 2 - METACARACTERES DE REDIRECCIÓN

A la hora de establecer flujos de entrada y salida Linux utiliza por defecto las entradas y salidas estándar, como son el teclado y la consola. Los metacaracteres de redirección nos permiten determinar entradas y salidas alternativas.
- `< [file]` → Redirige la entrada al contenido del archivo [file]
- `> [file]` → Redirige la salida al contenido del archivo [file] sobreescribiendo
- `&> [file]` → Redirige la salida junto con los mensajes de error al contenido del archivo [file] sobreescribiendo
- `>> [file]` → Redirige la salida al contenido del archivo [file] añadiendo al final de su contenido
- `&>> [file]` → Redirige la salida junto con los mensajes de error al contenido del archivo [file] añadiéndola al final de su contenido
- `2> [file]` → Redirige sólo los mensajes de error al contenido del archivo [file] sobreescribiéndolo
- `2>> [file]` → Redirige sólo los mensajes de error al contenido del archivo [file] añadiéndolos al final de su contenido
- `[command1] | [command2]` → Utiliza la salida de la orden [command1] como entrada de la orden [command2] (creación de cauces)
- `[command1] |& [command2]` → Utiliza la salida junto con los mensajes de error de la orden [command1] como entrada de la orden [command2] (creación de cauces)

## 3 - METACARACTERES SINTÁCTICOS

Los metacaracteres sintácticos nos permiten combinar varias órdenes en una sola. Existen cuatro metacaracteres sintácticos:
- `;` → Separa órdenes que se ejecutan secuencialmente
- `&&` → Separa órdenes ejecutando la segunda sólo si la primera tiene éxito
- `||` → Separa órdenes ejecutando la segunda sólo si la primera falla
- `()` → Trata las órdenes entre paréntesis como una sola

```
$ echo Hola ; cat Saludo
  Hola
  Comostamo
$ cat saludo && echo Saludo ejecutado correctamente
  Comostamo
  Saludo ejecutado correctamente
$ cat adios || echo No hay despedida
  cat: adios: No such file or directory
  No hay despedida
$ (cat adios || echo No hay despedida) && echo Toca hacerla
  cat: adios: No such file or directory
  No hay despedida
  Toca hacerla
```

## 4 - EJERCICIOS

### EJERCICIO 1

Se debe utilizar solamente una vez la orden `chmod` en cada apartado. Los cambios se harán en un archivo concreto del directorio de trabajo (salvo que se indique otra cosa). Cambiaremos uno o varios permisos en cada apartado (independientemente de que el archivo ya tenga o no dichos permisos) y comprobaremos que funciona correctamente:
- Dar permiso de ejecución al “resto de usuarios”.
- Dar permiso de escritura y ejecución al “grupo”.
- Quitar el permiso de lectura al “grupo” y al “resto de usuarios”.
- Dar permiso de ejecución al “propietario” y permiso de escritura el “resto de usuarios”.
- Dar permiso de ejecución al “grupo” de todos los archivos cuyo nombre comience con la letra `e`. Nota: Si no hay más de dos archivos que cumplan esa condición, se deberán crear archivos que empiecen con `e` y/o modificar el nombre de archivos ya existentes para que cumplan esa condición.

### EJERCICIO 2

Utilizando solamente las órdenes de la práctica anterior y los metacaracteres de redirección de salida:
- Cree un archivo llamado `ej31`, que contendrá el nombre de los archivos del directorio padre del directorio de trabajo.
- Cree un archivo llamado `ej32`, que contendrá las dos últimas líneas del archivo creado en el ejercicio anterior.
- Añada al final del archivo `ej32`, el contenido del archivo `ej31`.

### EJERCICIO 3

Utilizando el metacarácter de creación de cauces y sin utilizar la orden `cd`:
- Muestre por pantalla el listado (en formato largo) de los últimos 6 archivos del directorio `/etc`.
- La orden `wc`muestra por pantalla el número de líneas, palabras y bytes de un archivo (consulta la orden man para conocer más sobre ella). Utilizando dicha orden, muestre por pantalla el número de caracteres (sólo ese número) de los archivos del directorio de trabajo que comiencen por los caracteres `e` o `f`.

### EJERCICIO 4

Resuelva cada uno de los siguientes apartados:
- Cree un archivo llamado `ejercicio1`, que contenga las 17 últimas líneas del texto que proporciona la orden man para la orden chmod (se debe hacer en una única línea de órdenes y sin utilizar el metacarácter `;` ).
- Al final del archivo `ejercicio1`, añada la ruta completa del directorio de trabajo actual.
- Usando la combinación de órdenes mediante paréntesis, cree un archivo llamado `ejercicio3` que contendrá el listado de usuarios conectados al sistema (orden `who`) y la lista de archivos del directorio actual.
- Añada, al final del archivo `ejercicio3`, el número de líneas, palabras y caracteres del archivo `ejercicio1`. Asegúrese de que, por ejemplo, si no existiera `ejercicio1`, los mensajes de error también se añadieran al final de `ejercicio3`.
- Con una sola orden `chmod`, cambie los permisos de los archivos `ejercicio1` y `ejercicio3`, de forma que se quite el permiso de lectura al “grupo” y se dé permiso de ejecución a las tres categorías de usuarios.

## 5 - SOLUCIONES

### EJERCICIO 1

```
$ chmod o+x practFS.ext
$ ls -l practFS.ext
  -rw-r--r-x 1 groctel groctel 0 oct  6 21:23 practFS.ext
$ chmod g+rx practFS.ext
$ ls -l practFS.ext
  -rw-r-xr-x 1 groctel groctel 0 oct  6 21:23 practFS.ext
$ chmod go-r practFS.ext
$ ls -l practFS.ext
  -rw---x--x 1 groctel groctel 0 oct  6 21:23 practFS.ext
$ chmod u+x,o+w practFS.ext
$ ls -l practFS.ext
  -rwx--x-wx 1 groctel groctel 0 oct  6 21:23 practFS.ext
$ chmod g+x e*
$ ls -l e*
  -rw-r-xr-- 1 groctel groctel 0 oct  6 21:26 ejer3arch.txt
  -rw-r-xr-- 1 groctel groctel 0 oct  6 21:26 ejer3filetags.txt
```

Todas las órdenes se han realizado en el directorio `ejercicio1/Ejer3` de la práctica anterior. Los cambios de permisos podrían haberse declarado en formato octal, pero debido a que sólo se deben cambiar unos permisos específicos es más sencillo hacerlo de forma textual.

### EJERCICIO 2

```
$ ls .. > Ej31
$ cat Ej31
  Ejer1
  Ejer2
  Ejer3
$ tail -2 Ejer31 > Ej32
$ cat Ej32
  Ejer2
  Ejer3
$ cat Ej31 >> Ej32
$ cat Ej32
  Ejer2
  Ejer3
  Ejer1
  Ejer2
  Ejer3
```

### EJERCICIO 3

```
$ ls -l /etc | head -6
  total 1196
  drwxr-xr-x  3 root root     4096 jul 25 05:08 acpi
  -rw-r--r--  1 root root     3028 jul 25 05:04 adduser.conf
  drwxr-xr-x  2 root root    12288 sep 23 09:58 alternatives
  -rw-r--r--  1 root root      401 may 29  2017 anacrontab
  -rw-r--r--  1 root root      433 oct  2  2017 apg.conf
$ ls e* f* | wc -m
  45
```

### EJERCICIO 4

```
$ (man chmod | tail -17) > ejercicio1
$ cat ejercicio1
  El tocho de 17 líneas que empieza por “GNU coreutils online help:”
$ pwd >> ejercicio1
$ cat ejercicio1
  El mismo tocho de ahora 18 líneas que acaba en /home/groctel
$ (who ; ls) > ejercicio3
$ cat ejercicio3
  groctel  :0           2018-10-08 15:47 (:0)
  robet201.me
$ wc ejercicio1 >> ejercicio3
$ cat ejercicio3
  groctel  :0           2018-10-08 15:47 (:0)
  robet201.me
  18  73 738 ejercicio1 
$ chmod g+r,a+x ejercicio1 ejercicio3
$ ls -l
  total 20
  drwxr-xr-x 2 groctel groctel 4096 oct  6 21:30 Ejer1
  drwxr-xr-x 3 groctel groctel 4096 oct  6 21:29 Ejer2
  drwxr-xr-x 2 groctel groctel 4096 oct  8 16:50 Ejer3
  -rwxr-xr-x 1 groctel groctel  738 oct  8 16:53 ejercicio1
  -rwxr-xr-x 1 groctel groctel  169 oct  8 16:54 ejercicio3
```