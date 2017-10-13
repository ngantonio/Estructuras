# Estructuras


## Estructuras de Datos Dinamicas, implementadas en el lenguaje de programacion C++.

## Dynamic Data Structures, implemented in the C ++ programming language.

Son Librerias Desarrolladas por mi persona bajo el principio y los estandares de la Programacion Orientada a Objetos, con las buenas practicas de programacion adquiridas durante los 3 primeros años de estudio en ciencias Computacionales y de importantes textos como *C++ How to program, 6th edition, by Deitel & Deitel*. Implementadas con plantillas *(templates)* de manera que, pueden ser utilizadas con cualquier tipo de dato primitivo o definido por el usuario, haciedo uso de apuntadores como la forma de enlace para cada nodo de las mismas.

En cada libreria se encuentran desarrollados los algoritmos basicos que dan funcionamiento a cada una de las estructuras creadas, ademas de algoritmos que resuelven diversos problemas triviales y academicos que se presentan para cada estructura, encontrados en bibliografias destinadas al aprendizaje y la construccion de algoritmos.

Cada directorio contiene un archivo README donde se especifica detalladamente cada Libreria y su semantica operacional.


### ¿Que necesito tener instalado para compilar y ejecutar las librerias?

	1. Instalacion del compilador gcc: para ello abrimos la terminal e ingresamos y escribimos el siguiente comando:

#### $ sudo apt-get install gcc 
*(en caso de que tu gestor de paquetes sea apt), Puedes comprobar que se instaló corectamente ejecutando el comando *gcc -v*

	2. Una vez instalado gcc, procedemos a instalar la compilacion de librerias estandar de C++, utilizando el comando:

#### $ sudo apt-get install build-essential

	3. Descarga los archivos de este repositorio y situate en el directorio de la estructura que quieres compilar.
		3.1 Escribe *make* en la terminal, para compilar todos los codigos fuente existentes en el fichero.
		3.2 El paso anterior generará un ejecutable llamado *main*, para ejecutarlo, escribe *./main*.
