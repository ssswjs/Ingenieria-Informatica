# INTRODUCCIÓN A UNIX Y LINUX

## 0 - INSTALACIÓN DE LINUX

Este punto es el único que difiere del temario original, ya que en él se explica cómo instalar Linux en una máquina virtual. Si alguna vez te has sentado delante de una máquina virtual estarás de acuerdo en que es lo más cercano a un interrogatorio del FBI que has experimentado en tu vida y no quieres volver a pasar por ahí. Por eso, en este punto te explico yo, personalmente como autor de estos apuntes, cómo instalar Linux en tu disco duro o en un disco externo que puedas transportar a cualquier lado.

### 0.1 - ELECCIÓN DEL SISTEMA OPERATIVO

Linux como tal es sólo el núcleo del sistema operativo. A la hora de instalar Linux hay cientos (si no miles) de distribuciones (o distros) entre las que elegir, cada una con su forma de trabajar y de concebir el sistema. Aquí vemos algunas de ellas:
- Las distros basadas en **Debian** como Ubuntu, Kali, Guadalinex (sí), Mint Debian Edition, SteamOS o el propio Debian son las más sencillas de utilizar para principiantes o usuarios que no desempeñen tareas técnicas.
- Las distros basadas en **Arch** como Manjaro, Antergos, Aparicity, Chakra o el propio Arch toman su software de un repositorio mantenido por la comunidad llamado AUR. Al contrario que las basadas en Debian, se actualizan instantáneamente y no cambian de versión cada dos o tres años.
- También existen otras distros como las basadas en **Fedora** o **RedHat** o para propósitos específicos como **Raspbian**, que está desarrollada para la aprovechar al máximo el hardware de la [Raspberry Pi](https://www.raspberrypi.org/).

### 0.2 - INICIANDO LINUX DESDE UN USB

Tras elegir la distro y hacer una copia de seguridad de todos los datos del sistema operativo actual, accede a la página oficial de la distro y descarga la versión que más acorde veas con tus necesidades, coge un dispositivo de almacenamiento externo USB de **al menos 4GB**  y descarga el programa gratuito [Etcher](https://www.balena.io/etcher/) para tu sistema operativo, que te guiará durante la instalación de Linux en tu dispositivo.

###### En el momento de escritura de esta página existe un error en la descarga de Etcher que no permite descargar el programa pulsando el botón de descarga. Para solucionarlo, inspecciona el elemento de dicho botón y copia el enlace que aparece en él en una nueva pestaña.

Reinicia el ordenador con el dispositivo USB conectado y, si arranca Windows en vez de Linux, configura tu BIOS para que arranque primero los dispositivos USB. Cada BIOS es diferente, por lo que escribir unas instrucciones específicas para cada una sería absurdamente largo. Al acceder a ella asegúrate de que, aparte de cambiar de preferencia de arranque, deshabilitas el fastboot y el secure boot para evitar problemas con los drivers más adelante.

Cuando se inicie Linux te aparecerá una pantalla pidiendo confirmación para la siguiente acción. Elige **probar la distro antes de instalarla**, cuando se inicie la distro, ejecuta el instalador, que estará o en el escritorio o en un botón en el mensaje de bienvenida.

### 0.3 - TIPOS DE INSTALACIÓN

![img](https://imgur.com/OH9TtfX.png)

En este punto se plantean varias opciones de instalación:
- **Borrar disco e instalar la distro** → Instala la distro como único sistema operativo, eliminando cualquier otra instalación previa en el sistema.
- **Otra cosa** →Permite al usuario elegir dónde instalar la distro y en qué partes de qué disco instalar cada uno de los componentes de la distro.

### 0.4 - INSTALACIÓN EN PARTICIÓN (DUAL BOOT)

Si quieres mantener otros sistemas operativos o quieres instalar tu distro en un disco externo, elige **otra cosa** y entrarás al menú de las particiones.

![img](https://imgur.com/dCtZjzc.jpg)

Las particiones de un disco duro son diferentes secciones que cumplen propósitos distintos. Generalmente, los ordenadores vienen con una partición de arranque, una partición primaria de almacenamiento y una de recuperación.

Si no has reducido la partición primaria de tu sistema operativo anterior, éste es el momento de hacerlo. Vuelve a tu sistema operativo, desfragmenta el disco si fuese necesario y utiliza la herramienta de gestión de discos que tengas disponible para liberar espacio de la partición en la que quieras instalar tu distro. También puedes hacer esto desde el usb, pero es más recomendable hacerlo desde el sistema operativo en el que tienes tus datos.

Cuando hayas liberado el espacio necesario y estés de vuelta en el menú de la figura, selecciona la partición marcada por espacio vacío y añade las siguientes particiones:
- `swap - lógica` → Tantos GB como tu memoria RAM, al final del espacio vacío.
- `ext4 - primaria - /` → El resto del espacio o el destinado a la instalación de programas, al comienzo del espacio vacío restante.
- `ext4 - primaria - /home` → (Opcional) El espacio destinado al almacenamiento de datos personales, al comienzo del espacio vacío restante.

La principal ventaja de tener una partición montada en `/` y otra en `/home` es que, si en algún momento tuviéramos que hacer una reinstalación del sistema operativo, sólo tendríamos que cambiar la partición `/` y no perderíamos los datos guardamos en en el directorio `/home` y sus descendientes.

Por último, selecciona como partición de arranque la que esté indicada en tu ordenador.

### 0.5 - INSTALACIÓN EN UN DISCO EXTERNO

La instalación de una distro en un disco externo se lleva a cabo de la misma manera que la instalación en una partición secundaria, con la diferencia de que las particiones se encuentran en un disco externo (posiblemente estén en otro menú de la pantalla de particiones) y se debe configurar una partición de arranque al inicio del disco para poder abrirlo como si de un disco duro interno se tratase.

## 1 - INTRODUCCIÓN A LA INTERFAZ

En Linux, al contrario que en otros sistemas operativos, las interfaces no son comunes para todos los dispositivos, sino que varían en función del gestor de ventanas y el entorno de escritorio utilizado.

### 1.1 - GESTORES DE VENTANAS
Los gestores de ventanas son los encargados de manejar la posición y jerarquía de las diferentes ventanas que aparecen en pantalla. El más común es X Windows, aunque existen otros como Kwin, Metacity, WindowMaker o Fvwm.

### 1.2 - ENTORNOS DE ESCRITORIO

Los entornos de escritorio son los encargados de presentar el sistema operativo como una experiencia visual y no meramente textual. El más común es GNOME, aunque existen otros como KDE, CDE, XFCE, LXDE o Budgie.

## 2 - EL ÁRBOL DE DIRECTORIOS

En Linux absolutamente todo lo que pasa en el ordenador está representado en directorios. El árbol de directorios empieza en la carpeta raíz `/` y se expande en varios subdirectorios, cada uno con un propósito específico:

![img](https://i.imgur.com/EEFlBgo.png)


- `/` → Directorio raíz del que parten el resto
   - `bin` → Programas del sistema que no son críticos para el arranque.
   - `boot` → Archivos necesarios para el arranque del sistema operativo.
   - `dev` → Archivos que apuntan a los dispositivos conectados al sistema.
   - `etc` → Archivos de configuración del sistema operativo.
   - `home` → Carpeta principal que alberga las carpetas de los usuarios del sistema.
   - `lib` → Bibliotecas del sistema.
   - `media` → Unidades adicionales montadas dinámicamente en el sistema.
   - `mnt` → Unidades adicionales montadas permanentemente en el sistema.
   - `opt` → Carpetas con programas añadidos o configurados posteriormente a la instalación del sistema y que no forman parte de la distribución, también se suele usar como carpeta “otros”.
   - `proc` → Carpeta que contiene archivos con información de dispositivos, también permite configurarlos y procesarlos.
   - `root` → Carpeta del usuario que administra el sistema.
   - `sbin` → Programas del sistema que son críticos para el arranque y reservados para el administrador del sistema.
   - `srv` → A veces se crea esta carpeta para la gestión de servidores no nativos del sistema o para compartir información con el exterior.
   - `tmp` → Carpeta con los ficheros temporales, se suele borrar al reiniciar el sistema.
   - `usr` → Archivos con programas, bibliotecas, código y documentación de paquetes del sistema.
   - `var` → Archivos de log del sistema.

## 3 - TIPOS DE ARCHIVOS Y PROPIEDADES

Desde Linux se pueden editar los tipos **MIME** (Multipurpose Internet Mail Extensions), que es una convención que determina de qué tipo es un archivo, y sus propiedades. Las propiedades que puede tener un archivo son:
- **Nombre** → El nombre por el que se identifica el archivo
- **Tipo** → Define cómo debe tratarse el archivo
- **Tamaño** → El espacio que el archivo ocupa en el disco
- **Permisos** → Definen qué acciones pueden realizar los usuarios con el archivo
   - **Lectura** → Acceso al archivo y visualización de su contenido
   - **Escritura** → Modificación del contenido del archivo
   - **Ejecución** → Interpretación del archivo como si fuera un programa, en carpetas permite o deniega el acceso a la misma

Los permisos están definidos para tres grupos de usuarios:
- **Propietario** → El creador del archivo
- **Grupo** → Usuarios del mismo grupo que el propietario
- **Otros** → El resto de usuarios

Esta jerarquía de permisos se explorará con más profundidad en la práctica 2.

## 4 - EDITORES DE TEXTO

Los editores de texto de Linux pueden ser ejecutado tanto en la terminal como en una interfaz externa. Los más comunes son Nano (terminal) y Gedit (externo). Se utilizan tanto para escribir scripts como para modificar archivos de configuración.