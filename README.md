# Estructuras-
Estructuras de Datos Dinamicas, implementadas en el lenguaje de programacion C++.
Dynamic Data Structures, implemented in the C ++ programming language.

Son Librerias Desarrolladas por mi persona bajo el principio y los estandares de la Programacion Orientada a Objetos, con las buenas practicas de programacion adquiridas durante los 3 primeros años de estudio en ciencias Computacionales y de importantes textos como -C++ How to program, 6th edition, by Deitel & Deitel-. Implementadas con plantillas -templates- de manera que, pueden ser utilizadas con cualquier tipo de dato primitivo o definido por 

En cada libreria se encuentran desarrollados los algoritmos basicos que dan funcionamiento a cada una de las estructuras creadas, ademas de algoritmos que resuelven diversos problemas triviales y academicos que se presentan para cada estructura, encontrados en bibliografias destinadas al aprendizaje y la construccion de algoritmos.

A continuacion se especifica detalladamente cada Libreria y su semantica operacional:

Estructuras Dinamicas Lineales:

   - Clase Lista (List.h) -Simplemente enlazada-
      - Constructor
      - Constructor Copia
      - Destructor
      
      - Semantica Operacional:
          - esVacia():Logico
          - insertar(elemento: e, entero: posicion)
          - insertarFinal(elemento: e)
          - eliminar(entero: posicion)
          - obtenerLongitud():entero
          - consultar(entero: posicion):elemento
          - buscar(elemento: e):Logico
          - estaOrdenada():Logico
          - sublista(elemento: inicio, elemento: fin):Lista
          - invertir()
          - intercambiar(Lista: L)
          - ordenar()
         
              -Sobrecarga de Operadores:
             
                 - asignacion(Lista: L):Lista
                 - igualdad(Lista: L):logico
                 - desigualdad(Lista: L):logico
                 - menor(Lista: L):Logico
                 - mayor(Lista: L):Logico
                 - busqueda(entero: posicion):elemento
                 - concatenacion(Lista: L)
                
          
  - Clase Pila (Stack.h) -Hereda de Lista- , -Estructura LIFO-:
      - Constructor
      - Constructor Copia
      - Destructor
      
      - Semantica Operacional:
          - esVacia():Logico
          - obtenerLongitud():entero
          - apilar(elemento: e)
          - desapilar():elemento
          - consultarTope():elemento
          - buscar(elemento: e):Logico
  
  - Clase Cola (Queue.h) -Hereda de Lista- , -Estructura FIFO-:
      - Constructor
      - Constructor Copia
      - Destructor
      
      - Semantica Operacional:
          - esVacia():Logico
          - obtenerLongitud():entero
          - encolar(elemento: e)
          - desencolar():elemento
          - consultarFrente():elemento
          - buscar(elemento: e):Logico
  
 
  
Estructuras Dinamicas Jerarquicas:

  - Arbol N-ario (ArbolN.h):
      - Constructor
      - Constructor(elemento: raiz)
      - Constructor(elemento: raiz, Lista: hijos)
      - Constructor Copia
      - Destructor
      
      - Semantica Operacional:
         - esNulo():Logico
         - esHoja():Logico
         - esSubarbol(ArbolN: A2):Logico
         - obtenerRaiz():elemento
         - obtenerAltura():entero
         - obtenerPeso():entero
         - obtenerHijos():Lista(ArbolN)
         - obtenerHermanos():Lista(elemento)
         - insertar(ArbolN: subarbol, elemento: e)
         - insertar(Lista(elemento): hijos, elemento: e)
         - eliminar(elemento: e)
         - buscar(elemento: e)
         
       - Recorridos en Arboles:
         - Preorden():Lista(elemento)
         - Inorden():Lista(elemento)
         - Postorden():Lista(elemento)
         - Niveles():Lista(elemento)
         
         
       - Algoritmos clasicos de Arboles N-arios:
         - Frontera()
         - Camino(elemento: e):Lista(elemento)
          
                 
  - Arbol Binario:
  - Arbol Binario de Busqueda:
  
  
Estructuras DInamicas Multi-enlazadas:

  - Grafos
