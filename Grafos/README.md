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
