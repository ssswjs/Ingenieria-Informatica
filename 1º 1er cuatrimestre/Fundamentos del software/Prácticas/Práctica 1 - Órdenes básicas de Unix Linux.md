# ÓRDENES BÁSICAS DE UNIX/LINUX

## 0 - ÓRDENES LINUX

| **cat** | **cd** | **clear** | **cp** | **file** | **head** |
|:----:|:----:|:----:|:----:|:----:|:----:|
| **help** | **ls** | **man** | **mkdir** | **more** | **mv** |
| **pwd** | **rm** | **rmdir** | **sort** | **tail** | **touch** |

`cat` → Concatena y muestra archivos en la salida estándar
- `cat [source]` → Muestra el contenido de [source]
- `cat -E` → Muestra “$” al final de cada línea
- `cat -n` → Numera todas las líneas
- `cat -s` → Comprime múltiples líneas en blanco en una sola
- `cat -T` → Muestra todas las tabulaciones como “^I”

`cd` → Cambia el directorio de trabajo
- `cd [dir]` → Cambia el directorio de trabajo a [dir]
- `cd .` → Cambia el directorio de trabajo al actual
- `cd ..` → Cambia el directorio de trabajo al padre del actual

`clear` → Borra el contenido del terminal

`cp` → Copia archivos y directorios
- `cp [source] [destination]` → Copia [source] a [destination]. Si no existe, crea [destination]

`file` → Determina el tipo de un archivo especificado
- `file [file]` → Determina el tipo de [file]

`head` → Muestra las 10 primeras líneas de un archivo de texto
- `head [file]` → Muestra las 10 primeras líneas de [file]
- `head -[num]` → Muestra las [num] primeras líneas de un archivo de texto
- `head -c [num]` → Muestra los [num] primeros bytes de un archivo de texto

`help` → Muestra información sobre el uso de una orden
- `help [query]` → Muestra información sobre la orden [query]

`ls` → Muestra el contenido de un directorio
- `ls [dir]` → Muestra el contenido de [dir]
- `ls -a` → Muestra todos los elementos, incluso los precedidos de “.”
- `ls -h` → Muestra los datos numéricos con formato legible por humanos
- `ls -l` → Usa un formato de lista largo (con permisos)
- `ls -m` → Muestra los elementos en fila separados por una coma
- `ls -o` → Usa un formato de lista largo pero no muestra el grupo de usuarios
- `ls -r` → Muestra los elementos en orden inverso
- `ls -R` → Muestra los directorios recursivamente
- `ls -s` → Muestra el tamaño de cada elemento en KB
- `ls -S` → Muestra los elementos ordenados de mayor a menor tamaño
- `ls -t` → Muestra los elementos en orden cronológico inverso de modificación
- `ls -x` → Muestra los elementos ordenados en filas en vez de en columnas
- `ls -X` → Muestra los elementos ordenados alfabéticamente según su extensión
- `ls -1` → Muestra sólo un elemento por fila

`man` → Paginador del manual del sistema
- `man man` → muestra la primera página del manual
- `man [query]` → Muestra la página del manual referida a [query] si la hubiera

`mkdir` → Crea directorios
- `mkdir [dir]` → Crea un directorio de nombre [dir]. Pueden crearse varios en una misma orden
- `mkdir -p` → Crea un directorio con los ancestros necesarios para completar su ruta
- `mkdir -v` → Verboso

`more` → Muestra un archivo de texto fragmentado de pantalla a pantalla
- `more [file]` → Muestra el contenido de [file]
- `more -d` → Muestra texto de ayuda en lugar de alertar al pulsar teclas inválidas
- `more -f` → Cuenta las líneas lógicas en lugar de las mostradas en pantalla
- `more -s` → Comprime varias líneas vacías en una sola

`mv` → Mueve archivos y directorios
- `mv [source] [destination]` → Mueve [source] a [destination]. Si no existe, crea [destination], funcionando como un rename
- `mv -f` → No pregunta antes de sobreescribir
- `mv -i` → Pregunta antes de sobreescribir
- `mv -n` → No sobreescribe ningún archivo
   - Sólo se ejecuta el último de -f, -i y -n
- `mv -u` → Mueve el archivo sólo si es más nuevo que el destino o si no hay destino
- `mv -v` → Verboso

`pwd` → Muestra el nombre del directorio de trabajo actual

`rm` → Elimina archivos y directorios
- `rm [source]` → Elimina [source]
- `rm -d` → Elimina directorios vacíos
- `rm -i` → Pregunta antes de borrar
- `rm -I` → Pregunta antes de borrar más de tres archivos recursivamente
- `rm -r` → Elimina directorios y su contenido recursivamente
- `rm -v` → Verboso 

`rmdir` → Elimina directorios vacíos
- `rmdir [dir]` → Elimina el directorio [dir]
- `rmdir -p` → Elimina el directorio y los ancestros especificados en su ruta
- `rmdir -v` → Verboso

`sort` → Reordena las líneas de un archivo de texto según un criterio (números - mayúsculas - minúsculas por defecto)
- `sort [file]` → Reordena las líneas de [file]
- `sort -b` → Ignora los espacios en blanco al inicio de las líneas
- `sort -d` → Sólo considera espacios en blanco y caracteres alfanuméricos
- `sort -f` → Ignora si las letras son mayúsculas o minúsculas
- `sort -i` → Sólo considera caracteres imprimibles en pantalla
- `sort -r` → Muestra la reordenación en orden inverso

`tail` → Muestra las 10 últimas líneas de un archivo de texto
- `tail [file]` → Muestra las 10 últimas líneas de [file]
- `tail -[num]` → Muestra las [num] últimas líneas de un archivo de texto
- `tail -c [num]` → Muestra los [num] últimos bytes de un archivo de texto

`touch` → Actualiza la marca de tiempo de archivos
- `touch [file]` → Actualiza la marca de tiempo de [file]. Si no existe, crea [file]
- `touch -a` → Sólo actualiza la fecha de acceso
- `touch -c` → No crea ningún archivo
- `touch -d=[string]` → Asigna [string] como la marca de tiempo
- `touch -m` → Sólo actualiza la fecha de modificación
- `touch -r=[file]` → Asigna el tiempo de [file] como la marca de tiempo

## 1 - LOS INTÉRPRETES DE ÓRDENES

Un intérprete de órdenes, o shell en la terminología UNIX, es un programa normal de usuario capaz de ejecutar órdenes escritas en él. Existen diferentes shells, como Bourne Again Shell (bash), TC Shell (tcsh) y Z Shell (zsh). Al estar construidas como programas de usuario normales, tienen la ventaja de que se pueden elegir según las preferencias del usuario.

Todas las órdenes de estas prácticas están dirigidas para bash. Si al abrir una shell fuera de otro tipo, bastaría con ejecutar la orden `bash` en ella. Todas las shells instaladas en un sistema pueden verse en el archivo `/etc/shells`.

### 1.1 - LA ORDEN MAN

Como se ha comentado en el punto 0, `man` abre el paginador del manual del sistema. Al ejecutar la orden, `man` busca la página asociada a la consulta dada en forma de argumento y la muestra en caso de que exista. Si hubiera más de una página para dicha consulta, `man` sólo muestra la primera.

El paginador utiliza los siguientes comandos para buscar o desplazarse por el texto:
- `Ctrl + F` → Avanzar página
- `Ctrl + B` → Retrasar página
- `Ctrl + P` → Moverse una línea hacia arriba
- `Ctrl + N` → Moverse una línea hacia abajo
- `/[string]` → Busca la cadena [string] (incluyendo los espacios en blanco) desde la primera línea mostrada en la pantalla en adelante, marcando todas las ocurrencias encontradas
- `?[string]` → Busca la cadena [string] (incluyendo los huecos en blanco) desde la primera línea mostrada en la pantalla hacia atrás, marcando todas las ocurrencias encontradas
- `n` → Siguiente elemento en la búsqueda
- `N` → Elemento previo en la búsqueda
- `v` → Lanza (si es posible) el editor por defecto para editar el fichero que estamos viendo
- `q` → Cierra el manual

### 1.2 - LA JERARQUÍA DE PERMISOS

Al ejecutar la orden `ls -l` podemos ver que a la izquierda de los archivos se muestra una tabla de diez caracteres de ancho. Cada una de las filas representa los permisos de lectura, escritura y ejecución que tienen los diferentes usuarios sobre su respectivo archivo.

El primer carácter es `-` si se trata de un archivo y `d` si se trata de un directorio. Los nueve caracteres restantes están divididos en tres grupos de tres caracteres. El primer grupo representa los permisos del usuario creador del archivo, los tres siguientes los de los usuarios pertenecientes al grupo de usuarios del creador y los tres últimos los del resto de usuarios.

Cada uno de estos grupos define los siguentes permisos:

- `r` → Lectura (read)
- `w` → Escritura (write)
- `x` → Ejecución (execute)
- `-` → Falta de permiso en la posición correspondiente

```
$ ls -l
  -rw-rw-r--  1 groctel groctel 84831 sep 22 18:56 'Fisica.zip'
  drwxr-xr-x  4 groctel groctel  4096 sep 19 19:47  Games
  drwxr-xr-x  7 groctel groctel  4096 oct  6 21:19  UGR
```

## 2 - METACARACTERES DE ARCHIVO

A la hora de nombrar archivos y directorios es muy útil utilizar caracteres especiales que puedan servirnos de comodín para expresar combinaciones de caracteres o caracteres desconocidos en el momento, sobre todo si nos encontramos con muchos archivos con nombres similares. Hay cinco metacaracteres:
- `?` → Representa un sólo carácter cualquiera en la posición indicada
- `\*` → Representa de cero a infinitos caracteres cualesquiera en la posición indicada
- `[]` → Designan varios caracteres individuales que pueden ocupar el espacio en el que se declaran
- `{}` → Designan cadenas de caracteres separadas por comas que pueden ocupar el espacio en el que se declaran y rangos de caracteres separados por `..`
- `~` → Abrevia la ruta absoluta de `/home/[user]`

## 3 - EJERCICIOS

### EJERCICIO 1

Cree el siguiente árbol de directorios a partir de un directorio de su cuenta de usuario:
- ejercicio1
   - Ejer1
      - Ejer21
   - Ejer2
   - Ejer3

Indique también cómo sería posible crear toda esa estructura de directorios mediante una única orden (mire las opciones de la orden de creación de directorios mediante `man mkdir`). Posteriormente realice las siguientes acciones:
- En `Ejer1` cree los archivos `arch100.txt`, `filetags.txt`, `practFS.ext` y `robet201.me`.
- En `Ejer21` cree los archivos `robet202.me`, `ejer11sol.txt` y `blue.me`.
- En `Ejer2` cree los archivos `ejer2arch.txt`, `ejer2filetags.txt` y `readme2.pdf`.
- En `Ejer3` cree los archivos `ejer3arch.txt`, `ejer3filetags.txt` y `readme3.pdf`.

¿Podrían realizarse las acciones anteriores empleando una única orden? Indique cómo.

### EJERCICIO 2

Situados en el directorio `ejercicio1` creado anteriormente, realice las siguientes acciones:
- Mueva el directorio `Ejer21` al directorio `Ejer2`.
- Copie los archivos de `Ejer1` cuya extensión tenga una `x` al directorio `Ejer3`.
- Si estamos situado en el directorio `Ejer2` y ejecutamos la orden `ls -la ../Ejer3/*arch*`, ¿qué archivo/s, en su caso, debería mostrar?

### EJERCICIO 3

Si estamos situados en el directorio `Ejer2`, indique la orden necesaria para listar sólo los nombres de todos los archivos del directorio padre.

### EJERCICIO 4

Liste los archivos que estén en su directorio actual y fíjese en alguno que no disponga de la fecha y hora actualizada, es decir, la hora actual y el día de hoy. Ejecute la orden `touch` sobre dicho archivo y observe qué sucede sobre la fecha del citado archivo cuando se vuelva a listar.

### EJERCICIO 5

La organización del espacio en directorios es fundamental para poder localizar fácilmente aquello que estemos buscando. En ese sentido, realice las siguientes acciones dentro de su directorio `HOME` (es el directorio por defecto sobre el que trabajamos al entrar en el sistema):
- Obtenga en nombre de camino absoluto (absolute pathname) de su directorio `home`. ¿Es el mismo que el de su compañero/a?
- Cree un directorio para cada asignatura en la que se van a realizar prácticas de laboratorio y, dentro de cada directorio, nuevos directorios para cada una de las prácticas realizadas hasta el momento.
- Dentro del directorio de la asignatura fundamentos del software (llamado `fs`) y dentro del directorio creado para esta práctica, copie los archivos `hosts` y `passwd` que se encuentran dentro del directorio `/etc`.
- Muestre el contenido de cada uno de los archivos

### EJERCICIO 6

Situados en algún lugar de su directorio principal de usuario (directorio `HOME`), cree los directorios siguientes: `Sesion.1`, `Sesion.10`, `Sesion.2`, `Sesion.3`, `Sesion.4`, `Sesion.27`, `Prueba.1` y `Sintaxis.2` y realice las siguientes tareas:
- Borre el directorio `Sesion.4`.
- Liste todos aquellos directorios que empiecen por `Sesion.` y a continuación tengan un único carácter.
- Liste aquellos directorios cuyos nombres terminen en `.1`.
- Liste aquellos directorios cuyos nombres terminen en `.1` o `.2`.
- Liste aquellos directorios cuyos nombres contengan los caracteres `si`.
- Liste aquellos directorios cuyos nombres contengan los caracteres `si` y terminen en `.2`.

### EJERCICIO 7

Desplacémonos hasta el directorio `/bin`, genere los siguientes listados de archivos (siempre de la forma más compacta y utilizando los metacaracteres apropiados):
- Todos los archivos que contengan sólo cuatro caracteres en su nombre.
- Todos los archivos que comiencen por los caracteres `d`, `f`.
- Todos los archivos que comiencen por las parejas de caracteres `sa`, `se`, `ad`.
- Todos los archivos que comiencen por `t` y acaben en `r`.

### EJERCICIO 8

Liste todos los archivos que comiencen por `tem` y terminen por `.gz` o `.zip` :
- De su directorio `HOME`.
- Del directorio actual.
- ¿Hay alguna diferencia en el resultado de su ejecución? Razone la respuesta

### EJERCICIO 9

Muestre del contenido de un archivo regular que contenga texto:
- Las 10 primeras líneas
- Las 5 últimas líneas

### EJERCICIO 10

Cree un archivo empleando para ello cualquier editor de textos y escriba en el mismo varias palabras en diferentes líneas. A continuación trate de mostrar su contenido de manera ordenada empleando diversos criterios de ordenación.

### EJERCICIO 11

¿Cómo podría ver el contenido de todos los archivos del directorio actual que terminen en `.txt` o `.c`?

## 4 - SOLUCIONES

### EJERCICIO 1

```
$ mkdir ejercicio1 ejercicio1/Ejer1 ejercicio1/Ejer1/Ejer21 ejercicio1/Ejer2 ejercicio1/Ejer3
$ cd ejercicio1/Ejer1
$ touch arch100.txt filetags.txt practFS.ext robet201.me
$ cd Ejer21/
$ touch robet202.me ejerllsol.txt blue.me
$ cd ../../Ejer2
$ touch ejer2arch.txt ejer2filetags.txt readme2.pdf
$ cd ../Ejer3
$ touch ejer3arch.txt ejer3filetags.txt readme3.pdf
```

Todas las órdenes de `touch` y `mkdir` se pueden comprimir en una sola línea desde el directorio ancestro común especificando la ruta de cada archivo creado o mediante la expresión `../`

### EJERCICIO 2

```
$ mv Ejer1/Ejer21 Ejer2
$ mv Ejer1/*.*x* Ejer3
$ cd Ejer2
$ ls -la ../Ejer3/*arch*
  -rw-r--r-- 1 groctel groctel 0 oct  6 21:23 ../Ejer3/arch100. txt
  -rw-r--r-- 1 groctel groctel 0 oct  6 21:26 ../Ejer3/ejer3arc h.txt
```

### EJERCICIO 3

     ..

### EJERCICIO 4

```
$ ls -l
  total 4
  drwxr-xr-x 2 groctel groctel 4096 oct  6 21:25 Ejer21
  -rw-r--r-- 1 groctel groctel    0 oct  6 21:25 ejer2arch.txt
  -rw-r--r-- 1 groctel groctel    0 oct  6 21:25 ejer2filetags. txt
  -rw-r--r-- 1 groctel groctel    0 oct  6 21:25 readme2.pdf
$ touch readme2.pdf
$ ls -l readme2.pdf
  -rw-r--r-- 1 groctel groctel 0 oct  6 21:38 readme2.pdf
```

### EJERCICIO 5

```
$ pwd
  /home/groctel
$ mkdir lab lab/fs lab/fs/p1 lab/fp lab/fp/p1 lab/calculo lab/calculo/p1 lab/algebra
$ cp /etc/hosts lab/fs/p1
$ cp /etc/passwd lab/fs/p1
$ more lab/fs/p1/hosts
  127.0.0.1    localhost
  127.0.1.1    grocpc
  \# The following lines are desirable for IPv6 capable hosts
  ::1     ip6-localhost ip6-loopback
  fe00::0 ip6-localnet
  ff00::0 ip6-mcastprefix
  ff02::1 ip6-allnodes
  ff02::2 ip6-allrouters
$ more lab/fs/p1/hosts
  (Te sale un tocho impresionante no lo voy a copiar)
```

No es lo mismo el directorio `/home` que `/HOME`. El primero se refiere al directorio de ese nombre del árbol de archivos mientras que el segundo se refiere al directorio de usuario, cuyo nombre varía en función del nombre del usuario que esté utilizando la máquina.

### EJERCICIO 6

```
$ mkdir Sesion.1 Sesion.10 Sesion.2 Sesion.3 Sesion.4 Sesion. 27 Prueba.1
$ rm Sesion.4
$ ls Sesion.?
  Sesion.1  Sesion.2  Sesion.3
$ ls *.1 *.2
  Prueba.1  Sesion.1  Sesion.2
$ ls *si*.*
  Sesion.1  Sesion.10  Sesion.2  Sesion.27  Sesion.3
$ ls *si*.2
  Sesion.2
```

### EJERCICIO 7

```
$ cd /bin
$ ls ????
  bash  cpio  date  grep  kill  less  nano  ping  sync  vdir  zcmp
  chvt  dash  echo  gzip  kmod  more  open  stty  true  zcat  znew
$ ls d* f*
  dash  dd  dir  dnsdomainname  dumpkeys  fgconsole  findmnt  fusermount
  date  df  dmesg  domainname  false  fgrep  fuser
$ ls sa* se* ad*
  ls: cannot access 'sa*': No such file or directory
  ls: cannot access 'ad*': No such file or directory
  sed   setfacl   setfont   setupcon
$ ls t*r
  tar
```

Aunque es importante distinguir entre archivos y directorios, este ejercicio está resuelto también sobre los directorios, pues sólo con archivos no da ningún resultado visible.

### EJERCICIO 8

```
$ ls /home/tem*.gz /home/tem*.zip
  ls: cannot access '/home/tem*.gz': No such file or directory
  ls: cannot access '/home/tem*.zip': No such file or directory
$ ls tem*.gz tem*.zip
  ls: cannot access 'tem*.gz': No such file or directory
  ls: cannot access 'tem*.zip': No such file or directory
```

La única diferencia en este caso es la sintaxis. Siendo un rango de caracteres y tipo de archivos tan acotados me habría sorprendido ver que encontraba de los dos, pero ya vemos que ni uno hay. En cualquier otro caso, con otras restricciones más democráticas se conseguirían resultados similares a los del Ejercicio 2.

### EJERCICIO 9

```
$ cd /sbin
$ head alsa
  \#!/bin/sh
  \#
  \# alsa-base control script
  \#
  \# Description: Used to load and unload ALSA modules and
  \#              restore and store mixer levels. There is no
  \#              longer any need to run this script on bootup
  \#              or shutdown. It ships as /sbin/alsa.
  \### END INIT INFO
$ tail -5 alsa
  *)
  echo "Usage: $MYNAME {unload|reload|force-unload|force-reload|suspend|resume}" >&2
  exit 3
  ;;
  esac
```

### EJERCICIO 10

```
$ sort -f excelente.txt
  del
  del
  del
  Edén
  el
  embébese
  En
  Ester
  leve
  mecer
  relente
  vergel
$ sort -r excelente.txt
  vergel
  relente
  mecer
  leve
  Ester
  En
  embébese
  el
  Edén
  del
  del
  del
```

Texto empleado en `excelente.txt`: `En el vergel del Edén embébese Ester del leve mecer del relente`. Cada palabra se ha separado por un salto de línea, no por espacios.

### EJERCICIO 11

```
$ cat *.txt *.c
  En el vergel del Edén embébese Ester del leve mecer del relente.
  ¡Excelente! Vegeté tres meses en el Éter. ¡Fetén!
```

Usados los archivos `excelente.txt` con contenido `En el vergel del Edén embébese Ester del leve mecer del relente`. y `pepe.c` con contenido `¡Excelente! Vegeté tres meses en el Éter. ¡Fetén!`. Ambos están escritos en línea, al contrario que el archivo del ejercicio anterior.

