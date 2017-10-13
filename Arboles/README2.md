## Estructuras Dinamicas Jerarquicas:


#### Arbol N-ario. *clase NTree.hpp*:

Se define un Arbol N-ario A, como un grafo conexo y aciclico, que puede tener N ramas o hijos. Su definicion es estrictamente recursiva para cada hijo, la representacion en memoria se realiza mediante listas de nodos enlazadas por apuntadores, donde cada nodo tiene un apuntador a su primer hijo (hijo de más a la izquierda) y otro a su hermano derecho.

   - Constructor
   - Constructor(elemento: raiz)
   - Constructor(elemento: raiz, Lista(elemento): hijos)
   - Constructor(elemento: raiz, Lista(ArbolN): hijos)
   - Constructor Copia
   - Destructor


##### Semantica Operacional:
   - esNulo():Logico
   - esHoja():Logico
   - esSubarbol(ArbolN: A2):Logico
   - obtenerRaiz():elemento
   - obtenerAltura():entero
   - obtenerPeso():entero
   - obtenerHijos():Lista(elemento)
   - insertar(elemento: padre, elemento: hijo)
   - insertar(elemento: padre, ArbolN: subarbol)
   - insertar(elemento: padre, Lista(elemento): hijos)
   - eliminar(elemento: padre)
   - buscar(elemento: e):Logico

   - Recorridos en un arbol N-ario:
    
     - Preorden():Lista(elemento)
     - Inorden():Lista(elemento)
     - Postorden():Lista(elemento)
     - Niveles():Lista(elemento)
                
   - Algoritmos clasicos de Arboles N-arios: 
    
     - Frontera()
     - Camino(elemento: extremo):Lista(elemento) desde raiz hasta el elemento extremo.
          
          
#### Arbol Binario. *clase BTree.h*:

Se define un Arbol Binario A, como un grafo conexo y aciclico que solamente posee 2 ramas o hijos, hijo Izquierdo e hijo derecho. Su definicion es estrictamente recursiva para cada hijo. La representacion en memoria se realiza mediante listas enlazadas de nodos, donde cada nodo esta autoreferenciado 2 veces. (apuntador a nodo: hijoIzq, hijoDer)

   - Constructor
   - Constructor(elemento: raiz)
   - Constructor(elemento: raiz, ArbolB: HijoIzquierdo, ArbolB: HijoDerecho)
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
     - igual():Logico
        