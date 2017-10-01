# Estructuras


## Estructuras de Datos Dinamicas, implementadas en el lenguaje de programacion C++.

## Dynamic Data Structures, implemented in the C ++ programming language.

Son Librerias Desarrolladas por mi persona bajo el principio y los estandares de la Programacion Orientada a Objetos, con las buenas practicas de programacion adquiridas durante los 3 primeros años de estudio en ciencias Computacionales y de importantes textos como *C++ How to program, 6th edition, by Deitel & Deitel*. Implementadas con plantillas *(templates)* de manera que, pueden ser utilizadas con cualquier tipo de dato primitivo o definido por el usuario, haciedo uso de apuntadores como la forma de enlace para cada nodo de las mismas.

En cada libreria se encuentran desarrollados los algoritmos basicos que dan funcionamiento a cada una de las estructuras creadas, ademas de algoritmos que resuelven diversos problemas triviales y academicos que se presentan para cada estructura, encontrados en bibliografias destinadas al aprendizaje y la construccion de algoritmos.

A continuacion se especifica detalladamente cada Libreria y su semantica operacional:

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
  
 
  
## Estructuras Dinamicas Jerarquicas:


#### Arbol N-ario. *clase ArbolN.h*:

Se define un Arbol N-ario A, como un grafo conexo y aciclico, que puede tener N ramas o hijos. Su definicion es estrictamente recursiva para cada hijo, la representacion en memoria se realiza mediante listas de nodos enlazadas por apuntadores, donde cada nodo tiene un apuntador a su primer hijo (hijo de más a la izquierda) y otro a su hermano derecho.

   - Constructor
   - Constructor(elemento: raiz)
   - Constructor(elemento: raiz, Lista: hijos)
   - Constructor Copia
   - Destructor


##### Semantica Operacional:
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
   - buscar(elemento: e):Logico

   - Recorridos en un arbol N-ario:
    
     - Preorden():Lista(elemento)
     - Inorden():Lista(elemento)
     - Postorden():Lista(elemento)
     - Niveles():Lista(elemento)
                
   - Algoritmos clasicos de Arboles N-arios: 
    
     - Frontera()
     - Camino(elemento: e):Lista(elemento)
          
          
#### Arbol Binario. *clase ArbolB.h*:

Se define un Arbol Binario A, como un grafo conexo y aciclico que solamente posee 2 ramas o hijos, hijo Izquierdo e hijo derecho. Su definicion es estrictamente recursiva para cada hijo. La representacion en memoria se realiza mediante listas enlazadas de nodos, donde cada nodo esta autoreferenciado 2 veces. (apuntador a nodo: hijoIzq, hijoDer)

   - Constructor
   - Constructor(elemento: raiz)
   - Constructor(elemento: raiz, ArbolB: HijoIzq, ArbolB: HijoDer)
   - Constructor(Cadena: "PREORDEN"; Lista: recorridoPre; Cadena: "INOREDEN"; Lista: recorridoIn)
   - Constructor(Cadena: "INORDEN"; Lista: recorridoIn; Cadena: "POSTORDEN"; Lista: recorridoPost)
   - Constructor Copia
   - Destructor


##### Semantica Operacional:
   - esNulo():Logico
   - esHoja():Logico
   - esCompleto():Logico
   - esSubarbol(ArbolN: A2):Logico
   - obtenerRaiz():elemento
   - obtenerAltura():entero
   - obtenerPeso():entero
   - obtenerHijoIzq():ArbolB
   - obtenerHijoDer():ArbolB
   - obtenerHijos():Lista<ArbolB>
   - establecerHijoIzq(elemento: elementoPadre, elementoHijoIzq)
   - establecerHijoDer(elemento: elementoPadre, elementoHijoDer)
   - eliminar(elemento: e)
   - buscar(elemento: e):Logico

   - Recorridos en un arbol Binario:
    
     - Preorden():Lista(elemento)
     - Inorden():Lista(elemento)
     - Postorden():Lista(elemento)
     - Niveles():Lista(elemento)
     - Niveles(entero: nivelA, nivelB):Lista(elementos desde nivelA hasta nivelB)
                
   - Algoritmos clasicos de Arboles binarios: 
    
     - espejo():ArbolB
     - diametro():entero
     - Completo():Logico
     - zurdo():Logico
     - hoja():Logico
     - menor(ArbolB: A2):Logico
     - isomorfo():Logico
     - igual():Logico
          
          
## Estructuras Dinamicas Multi-enlazadas:

#### Digrafo. *clase Digrafo.h*  

Se define a *G(V,A,λ)* como un grafo Dirigido pesado. Para el caso de esta implementacion, si el peso se omite sera establecido en 0.0. Su representacion en memoria es mediante listas enlazadas de adyacencia. Donde, existe una lista principal de vertices (nodos), y cada vertice *V* de esa lista, tiene un apuntador a una lista que guarda informacion sobre sus vertices adyacentes. De esta manera se representan las aristas del grafo *<V,W>*

   - Constructor
   - Constructor(Lista<elemento>: vertices)
   - Constructor copia
   - Destructor


##### Semantica Operacional:
   - esVacio():Logico
   - existeVertice(vertice: v):Logico
   - existeArco(vertice: v,w):Logico
   - obtenerOrden():entero
   - obtenerVertices():Lista<vertice>
   - obtenerVerticesFuente():Lista<vertice>
   - obtenerVerticesSumideros():Lista<vertice>
   - obtenerArcos():Lista<arcos>
   - establecerVertice(vertice: v)
   - establecerArco(vertice: v,w)
   - establecerArco(Arco<vertice>: Ei)
   - borrarVertice(elemento: v)
   - borrarArco(elemento: v,w)
   - borrarArco(Arco<vertice>: Ei)
   - obtenerPredecesores(vertice: v)
   - obtenerSucesores(vertice: v)
   

   - Recorridos en en un Grafo:
    
     - DFS():Lista<(vertices)
     - BFS():Lista(vertices)
  
                
   - Algoritmos clasicos de Grafos: 
    
     - grafoCompleto():Logico
