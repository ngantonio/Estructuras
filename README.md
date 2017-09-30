# Estructuras-
Estructuras de Datos Dinamicas, implementadas en el lenguaje de programacion C++.
Dynamic Data Structures, implemented in the C ++ programming language.

Son Librerias Desarrolladas por mi persona bajo el principio y los estandares de la Programacion Orientada a Objetos, con las buenas practicas de programacion adquiridas durante los 3 primeros años de estudio en ciencias Computacionales y de importantes textos como -C++ How to program, 6th edition, by Deitel & Deitel-. Implementadas con plantillas -templates- de manera que, pueden ser utilizadas con cualquier tipo de dato primitivo o definido por 

En cada libreria se encuentran desarrollados los algoritmos basicos que dan funcionamiento a cada una de las estructuras creadas, ademas de algoritmos que resuelven diversos problemas triviales y academicos que se presentan para cada estructura, encontrados en bibliografias destinadas al aprendizaje y la construccion de algoritmos.

A continuacion se especifica detalladamente cada Libreria y su semantica operacional:

Estructuras Dinamicas Lineales:

  - Clase Lista (List.h)
      - Constructor
      - Constructor Copia
      - Destructor
      
      - Semantica Operacional:
          - esVacia():Logico
          - obtenerLongitud():entero
          - consultar(entero: posicion):elemento
          - buscar(elemento: e):logico
          - estaOrdenada():logico
          - sublista(elemento: inicio, elemento: fin):Lista
          - invertir()
          - intercambiar(Lista: L)
          - ordenar()
             - Sobrecarga de Operadores:
                 - asignacion(Lista: L):Lista
                 - igualdad(Lista: L):logico
                 - desigualdad(Lista: L):logico
                 - menor(Lista: L):logico
                 - mayor(Lista: L):logico
                 - busqueda(entero: posicion):elemento
                 - concatenacion(Lista: L)
                
          
  - Clase Pila (Stack.h) -Hereda de Lista-:
  
  
  
  - Colas (Hereda de Lista):
  
Estructuras Dinamicas Jerarquicas:

  - Arbol N-ario:
  - Arbol Binario:
  - Arbol Binario de Busqueda:
  
  
Estructuras DInamicas Multi-enlazadas:

  - Grafos
