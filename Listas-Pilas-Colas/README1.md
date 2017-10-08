## Estructuras Dinamicas Lineales:

#### Clase Lista (List.h) *Simplemente enlazada*
 - 
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
         
      - Sobrecarga de Operadores:
            
          - asignacion(Lista: L):Lista
          - igualdad(Lista: L):logico
          - desigualdad(Lista: L):logico
          - menor(Lista: L):Logico
          - mayor(Lista: L):Logico
          - busqueda(entero: posicion):elemento
          - concatenacion(Lista: L)
                
          
#### Clase Pila (Stack.h) *Hereda de Lista* , *Estructura LIFO*:
 -
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



#### Clase Cola (Queue.h) *Hereda de Lista* , *Estructura FIFO*:
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
          - buscar(elemento: e):Logico
  
 
