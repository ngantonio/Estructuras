## Estructuras Dinamicas Lineales:

#### Clase Lista (List.hpp) *Doblemente enlazada*
 - 
      - Constructor
      - Constructor de elementos alataorios
      - Constructor Copia
      - Destructor
      
      - Semantica Operacional:
          - esVacia():Logico
          - insertar(elemento: e, entero: posicion)
          - insertarFinal(elemento: e)
          - eliminar(entero: posicion):elemento
          - eliminar(elemento e):logico
          - obtenerLongitud():entero
          - consultar(entero: posicion):elemento
          - buscar(elemento: e):Logico
          - estaOrdenada():Logico
          - sublista(elemento: inicio, elemento: fin):Lista
          - invertir()
          - comprimir():Lista
          - intercambiar(Lista: L)
         
      - Sobrecarga de Operadores:
            
          - asignacion(Lista: L):Lista
          - igualdad(Lista: L):logico
          - desigualdad(Lista: L):logico
          - menor(Lista: L):Logico
          - mayor(Lista: L):Logico
          - busqueda(entero: posicion):elemento
          - concatenacion(Lista: L)
                
          
#### Clase Pila (Stack.hpp) *Hereda de Lista* , *Estructura LIFO*:
 -
      - Constructor
      - Destructor
      
      - Semantica Operacional:
          - esVacia():Logico
          - obtenerLongitud():entero
          - apilar(elemento: e)
          - desapilar():elemento
          - consultarTope():elemento



#### Clase Cola (Queue.hpp) *Hereda de Lista* , *Estructura FIFO*:
 -
      - Constructor
      - Constructor Copia
      - Destructor
      
      - Semantica Operacional:
          - esVacia():Logico
          - obtenerLongitud():entero
          - encolar(elemento: e)
          - desencolar():elemento
          - consultarFrente():elemento
  
 
