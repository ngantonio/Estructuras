                        /****ESTRUCTURA DINAMICA ARBOL BINARIO. © GABRIEL A. OLIVEIRA N.*****/

#ifndef ARBOLB_H_
#define ARBOLB_H_
#include "NodoArbol.h"
#include <list>
#include <iterator>
#include <string>
#include <cstdio>
using namespace std;

template <class type>
class ArbolB{

public:

    ArbolB();                                           /*Crea un arbol binario Nulo*/
    ArbolB(type);                                       /*Crea un arbol binario con su raiz */
    ArbolB(const ArbolB &);                             /*Copia un arbol dado en otro*/
    ArbolB(type,const ArbolB &, const ArbolB &);        /*Crea un arbol binario con su raiz, su hijo izquierdo y su hijo derecho*/
    ArbolB(string &, list<type> &, string &, list<type> &); /*Construye un arbol dados sus recoridos*/
    ~ArbolB();                                              /*Destruye un arbol binario*/
    
    bool isNull();                                          /*¿Es nulo?*/
    bool isLeave();                                         /*¿Es hoja?*/
    bool isLeftHanded();                                    /*¿Es zurdo?*/
    bool isComplete();                                      /*¿Es Completo?*/
    bool isSub(const ArbolB<type> &);                       /*Indica si un arbol B, es sub-arbol, de un arbol A*/
    bool search(type);                                      /*Devuelve true, si un elemento esta dentro de un arbol*/
    bool operator==(ArbolB<type> &);                        /*¿El arbol A es igual al arbol B?*/
    
    type getRoot();                                     /*Devuelve la raiz del arbol*/
    
    int getWeight();                                    /*Devuelve el peso del arbol*/
    int getHeight();                                    /*Devuelve la altura del arbol*/
    int Diameter();                                     /*Devuelve el diametro de un arbol*/
    
    ArbolB<type> mirror();                              /*Devuelve un arbol espejo del original*/
    ArbolB<type> getSonLeft();                          /*Devuelve el hijo izquierdo de un arbol*/
    ArbolB<type> getSonRight();                         /*Devuelve el hijo derecho de un arbol*/
    list<ArbolB<type> > getHijos();                     /*Devuelve una lista con ambos hijos*/
    
    void setSonLeft(type,type);                         /*dado un padre, asigna un elemento como hijo izquierdo */
    void setSonRight(type,type);                        /*dado un padre, asigna un elemento como hijo derecho*/
    void remove(type);                                  /*dado un padre, elimina al padre y a su descendencia (si la tiene)*/
    void construirPreIn(list<type> &, list<type> &);    /*Construye un arbol dados sus recorridos en preorden e inorden*/
    void construirPostIn(list<type> &, list<type> &);   /*Construye un arbol dados sus recorridos en postorden e inorden*/
    

    /****RECORRIDOS EN ARBOLES****/

    inline list<type> preorden();
    inline list<type> postorden();
    inline list<type> inorden();
    inline list<type> levels();                        /*Devuelve una lista ordenada con los niveles del arbol*/
   
    inline list<type> levels(int, int = 0);            /*Dado un nivel devuelve una lista con los elementos de ese nivel,
                                                       /*pero dados 2 niveles, devuelve una lista con los elementos desde el nivel A*/
                                                       /*Hasta el nivel B, incluyendo a los extremos*/
protected:
    Node<type> *root;
    int weight;

private:

    /*Metodos privados necesarios para la implementacion con
    apuntadores*/

    Node<type> * copiarNodos(Node<type> *);
    void removeNodes(Node<type> *);
    inline void preorden(Node<type> *, list<type> &);
    inline void inorden(Node<type> *, list<type> &);
    inline void postorden(Node<type> *, list<type> &);
    inline void levels(Node<type> *, int *, int, list<type> &);
    void search(type, Node<type> *, Node<type> *&, bool *);
    void isLeftHanded(Node<type> *, int *, bool *flag);
    void isComplete(Node<type> *, bool *);
    Node<type>* mirror(Node<type> *);
    Node<type>* construirPreIn(list<type> &, list<type> &, int, int);
    Node<type>* construirPostIn(list<type> &, list<type> &, int ,int);
    int consult(list<type> &, type);
    void isEqual(Node<type> *, Node<type> *, bool *);
    void getHeight(Node<type> *, int *, int *);
    
    int Diameter(Node<type> *, int *);
    int max(int a, int b);

};

template <typename type>
ArbolB<type>::ArbolB(){
    this->root = NULL;
    weight = 0;
}

template <typename type>
ArbolB<type>::ArbolB(type info){

    Node<type> *New;

    New = new Node<type>(info);
    root = New;
    weight = 1;
}


template <typename type>
ArbolB<type>::ArbolB(type r ,const ArbolB &izquierdo, const ArbolB &derecho){

    ArbolB<type> binaryAux;
    Node<type> *New;

    New = new Node<type>(r);
    root = New;
    root->setLeft(copiarNodos(izquierdo.root));
    root->setRight(copiarNodos(derecho.root));
    weight = izquierdo.weight + derecho.weight;
}

template <typename type>
ArbolB<type>::ArbolB(const ArbolB &copia){ 
    root = copiarNodos(copia.root); 
    weight = copia.weight;
}

template <typename type>
ArbolB<type>::ArbolB(string &nombre1, list<type> &recorrido1, string &nombre2, list<type> &recorrido2){

    string PREORDEN("PREORDEN");
    string INORDEN("INORDEN");
    string POSTORDEN("POSTORDEN");

    if(nombre1 == PREORDEN && nombre2 == INORDEN)
        construirPreIn(recorrido1,recorrido2);
    else{
        if(nombre1 == INORDEN && nombre2 == PREORDEN)
            construirPreIn(recorrido2,recorrido1);
        else{
            if(nombre1 == POSTORDEN && nombre2 == INORDEN)
                construirPostIn(recorrido1,recorrido2);
            else{
                if(nombre1 == INORDEN && nombre2 == POSTORDEN)
                    construirPostIn(recorrido2,recorrido1);
                else
                    cout << endl<< "No se ha encontrado una coincidencia para la entrada de datos... "<< endl;
            }
        }
    }   
}

template <typename type>
ArbolB<type>::~ArbolB(){removeNodes(root);}

template <typename type>
bool ArbolB<type>::isNull(){return this->root == NULL;}

template <typename type>
bool ArbolB<type>::isLeave(){return (root->getLeft() == NULL && root->getRight() == NULL);}

template <typename type>
type ArbolB<type>::getRoot(){return root->getDatos();}

template <typename type>
int ArbolB<type>::getWeight(){return weight;}



template <typename type>
void ArbolB<type>::remove(type element){

    Node<type> *ptr;
    bool find = false;

    search(element,ptr,&find);
    if(find){
        removeNodes(ptr);
        ptr = NULL;
    }
    else
        cout << "El elemento " << element << " NO existe dentro del arbol" << endl;
}


template <typename type>
ArbolB<type> ArbolB<type>::getSonLeft(){

    ArbolB<type> son;

    (root != NULL)? son.root = copiarNodos(root->getLeft()) : son.root = NULL;
    return son;
}

template <typename type>
ArbolB<type> ArbolB<type>::getSonRight(){

    ArbolB<type> son;

    (root != NULL)? son.root = copiarNodos(root->getRight()) : son.root = NULL;
    return son;
}

template <typename type>
Node<type>* ArbolB<type>::copiarNodos(Node<type> *p){

    Node<type> *New;

    if(p ==  NULL)
        return NULL;
    else
        return New = new Node<type>(p->getDatos(),copiarNodos(p->getLeft()), copiarNodos(p->getRight()));
    
}

template <typename type>
void ArbolB<type>::removeNodes(Node<type> *ptr){

    if(ptr != NULL){
        if(ptr->getLeft() != NULL)
            removeNodes(ptr->getLeft());
        if(ptr->getRight() != NULL)
            removeNodes(ptr->getRight());

        delete ptr;
        ptr = NULL;
    }
}

template <typename type>
bool ArbolB<type>::search(type elemento){

    Node<type> *new_root;
    bool flag = false;

    search(elemento,root,new_root,&flag);
    return flag;

}


template <typename type>
void ArbolB<type>::search(type elemento,Node<type> *root, Node<type> *&ptr, bool *flag){

    if(root != NULL){
        if(root->getDatos() == elemento){
            *flag = true;
            ptr = root;
        }
        else{
            if(!*flag){
                search(elemento,root->getLeft(),ptr,flag);
                if(!*flag)
                    search(elemento,root->getRight(),ptr,flag);
            }
        }
    }

}

template <typename type>
void ArbolB<type>::setSonLeft(type padre, type dato){

    Node<type> *New, *aux;
    bool flag = false;

    search(padre,root,aux,&flag);
    
    if(flag && aux->getLeft() == NULL){
        New = new Node<type>(dato);
        aux->setLeft(New);
    }

}

template <typename type>
void ArbolB<type>::setSonRight(type padre, type dato){

    Node<type> *New, *aux;
    bool flag = false;

    search(padre,root,aux,&flag);
    
    if(flag && aux->getRight() == NULL){
        New = new Node<type>(dato);
        aux->setRight(New);
    }
}


template <typename type>
bool ArbolB<type>::isLeftHanded(){

    int totalWeight = 0;
    bool flag = false;

    isLeftHanded(root,&totalWeight,&flag);
    return flag;
}


template <typename type>
void ArbolB<type>::isLeftHanded(Node<type> *ptr, int *n, bool *flag){

    bool leftFlag,rightFlag;
    int leftWeight,rightWeight;

    if(ptr == NULL){
        *n = 0;
        *flag = true;
    }
    else{
        if(ptr->getLeft() == NULL && ptr->getRight() == NULL){  //si es hoja
            *flag = true;
            *n = 1;
        }
        else{
            leftWeight = 0;
            isLeftHanded(ptr->getLeft(),&leftWeight,&leftFlag);
            rightFlag = false;
            if(leftFlag)
                isLeftHanded(ptr->getRight(),&rightWeight,&rightFlag);

            *n = leftWeight + rightWeight+1;
            *flag = (leftFlag && rightFlag && (leftWeight > rightWeight));
            /*ambos hijos deben ser zurdos y el peso izquierdo debe ser mayor al peso derecho*/
        }
    }

}

template <typename type>
ArbolB<type> ArbolB<type>::mirror(){
    ArbolB<type> esp;

    esp.root = mirror(root);
    return esp;
}

template <typename type>
Node<type>* ArbolB<type>::mirror(Node<type> *ptr){

    Node<type> *New;

    if(ptr == NULL)
        return NULL;
    else
        New = new Node<type>(ptr->getDatos(), mirror(ptr->getRight()), mirror(ptr->getLeft()));
    return New;

}

template <typename type>
bool ArbolB<type>::isComplete(){

    bool flag = true;
    isComplete(root,&flag);
    return flag;
}

template <typename type>
void ArbolB<type>::isComplete(Node<type> *ptr, bool *flag){

    if(*flag == true && ptr != NULL){

        if((ptr->getLeft() == NULL && ptr->getRight() == NULL)){

        }         
        else{
            if(ptr->getLeft() == NULL || ptr->getRight() == NULL)
                *flag = false;
            else{
                isComplete(ptr->getLeft(),flag);
                isComplete(ptr->getRight(),flag);   
            }
        }
    }
}


template <typename type>
bool ArbolB<type>::operator==(ArbolB<type> &sub){

   return (this != &sub && this->weight == sub.weight)? isEqual(this->root,sub.root):false;  
}

template <typename type>
bool ArbolB<type>::isSub(const ArbolB<type> &sub){

    bool flag = true;
    bool flagFind = false;
    Node<type> *rootFound;

    /*busca la primera aparicion de la raiz del subarbol
    dentro del arbol actual y la envia a isEqual como la
    raiz actual del arbol. isEqual comprueba que sean isomorfos 
    y tengan los mismos datos*/

    search(sub.root->getDatos(),this->root,rootFound,&flagFind);

    (flagFind)? isEqual(rootFound,sub.root): flag = false;

    return flag;
}

template <typename type>
void ArbolB<type>::isEqual(Node<type> *ptrAct, Node<type> *ptrSub, bool *flag){

    /*determina si un arbol es igual a otro, en elementos (Semejante) y en estructura (isomorfo)*/

    if(ptrAct != NULL && ptrSub != NULL)
    {
        if(ptrAct->getDatos() == ptrSub->getDatos()){

            if((ptrAct->getLeft() == NULL && ptrSub->getLeft() == NULL) || (ptrAct->getLeft() != NULL && ptrSub->getLeft() != NULL))
                isEqual(ptrAct->getLeft(), ptrSub->getLeft(), flag);
            else
                *flag = false;

            if(*flag && (ptrAct->getRight() == NULL && ptrSub->getRight() == NULL) || (ptrAct->getRight() != NULL && ptrSub->getRight() != NULL))
                isEqual(ptrAct->getRight(), ptrSub->getRight(), flag);    
        }
        else
            *flag = false;

    }
}


template <typename type>
int ArbolB<type>::Diameter(){

    int level = 0;
    if(root != NULL) 
        return Diameter(root,&level);
    else
        return -1;   
}


template <typename type>
int ArbolB<type>::Diameter(Node<type> *ptr, int *level){

    int lh,rh,alturaIzq, alturaDer, diameterSubTree, subtreeMax;

    lh = 0;
    rh = 0;

    if(ptr == NULL){
        *level = 0;
        return 0;
    }else{

        alturaIzq = Diameter(ptr->getSonLeft(),&lh);
        alturaDer = Diameter(ptr->getRight(),&rh);
        diameterSubTree = lh + rh;        
        *level = max(lh, rh)+1;                 
        subtreeMax = max(alturaIzq, alturaDer);
        return max(diameterSubTree,subtreeMax);
    }

}

template <typename type>
int ArbolB<type>::getHeight(){

    int acumulado, total;
    acumulado = 1;
    total = 0;

    total = (root != NULL)? getHeight(root,&acumulado,&total): -1;

    return total;
}

template <typename type>
void ArbolB<type>::getHeight(Node<type> *p, int *acumulado, int *total){

    if(p != NULL){

        if(p->getLeft() == NULL && p->getRight() == NULL)
            if(*acumulado > *total)
                *total = *acumulado;
        else{
            *acumulado = *acumulado+1;
            getHeight(p->getLeft(),acumulado,total);            
            getHeight(p->getRight(),acumulado,total);
            *acumulado = *acumulado-1;
        }
    } 
}

template <typename type>
list<ArbolB<type> >ArbolB<type>::getHijos(){

    list<ArbolB<type> > H;
    ArbolB<type> L,R;

    if(root != NULL){
        ArbolB<type> L( this->getSonLeft());
        ArbolB<type> R(this->getSonRight());
        H.insert(H.end(),L);
        H.insert(H.end(),R);
    }   
    return H;   
}

template <typename type>
inline list<type> ArbolB<type>::levels(int levelA, int levelB){

    /*Retorna una lista con los elementos que estan en el NivelA de un arbol
    o entre los niveles A y B (ambos inclusive) si es invocada con dos parametros */

    int acum,H;
    list<type> N;
    bool band;

    acum = 1;
    H = this->getHeight();

    /*verifica que los datos enviados sean consistentes, retorna una lista vacia en caso contrario.*/
    (levelA > 0 && levelA <= H && levelB <= H)? band = true : band = false;

    /*si el arbol no es nulo y los niveles enviados son consistentes*/
    if(root != NULL && band){
        if(levelB == 0)                         /*si el nivel B queda en 0 (predeterminado)*/
            levels(root,&acum,levelA,N);        /*entonces se hace el recorrido del nivelA unicamente*/
        else{

            if(levelA <= levelB){               /*en caso contrario quiere decir que el metodo retornara*/
                int i = levelA;                 /*Una lista con los niveles entre A y B*/

                while(i <= levelB){             /*hace el recorrido por niveles para cada nivel entre A y B*/
                    levels(root,&acum,i,N);
                    i++;
                }
            }
        }

    }
    return N;
}

template <typename type>
inline void ArbolB<type>::levels(Node<type> *p, int *acum, int level, list<type> &N){

    if(p != NULL){

        if(*acum == level)                /*calcula implicitamente la altura, si el contador de */
            N.push_back(p->getDatos());   /*altura es igual al nivel dado, quiere decir que el elemento*/
                                          /*se encuentra en ese nivel, por tanto, lo inserta en la lista.*/
        *acum = *acum+1;
        levels(p->getLeft(),acum,level,N);           
        levels(p->getRight(),acum,level,N);
        *acum = *acum-1;
        
    }
    
}



/********RECORRIDOS PUBLICOS**********/

template <typename type>
inline list<type> ArbolB<type>::preorden(){

    list<type> pre;
    if(root != NULL)
        preorden(root,pre);
    return pre;
}

template <typename type>
inline list<type> ArbolB<type>::inorden(){

    list<type> in;
    if(root != NULL)
        inorden(root,in);
    return in;
}

template <typename type>
inline list<type> ArbolB<type>::postorden(){

    list<type> post;
    if(root != NULL)
        postorden(root,post);
    return post;
}


template <typename type>
inline list<type> ArbolB<type>::levels(){

    /*iterativo*/

    list<type> L;
    list<Node<type>* > C;

    if(root)
        C.insert(C.begin(),root);

    while(!C.empty()){

        L.insert(L.end(),C.front()->getDatos());

        if(C.front()->getLeft() != NULL)
            C.insert(C.end(),C.front()->getLeft());
        if(C.front()->getRight() != NULL)
            C.insert(C.end(),C.front()->getRight()); 

        C.pop_front();
    }

    return L;
}




/******** RECORRIDOS PRIVADOS**********/    

template <typename type>
inline void ArbolB<type>::preorden(Node<type> *ptr, list<type> &pre){

    Node<type> *aux;

    if(ptr != NULL){
        pre.insert(pre.end(),ptr->getDatos());
        preorden(ptr->getLeft(),pre);
        preorden(ptr->getRight(),pre);
    }
}

template <typename type>
inline void ArbolB<type>::postorden(Node<type> *ptr, list<type> &post){

    Node<type> *aux;

    if(ptr != NULL){
        postorden(ptr->getLeft(),post);
        postorden(ptr->getRight(),post);
        post.insert(post.end(),ptr->getDatos());
    }
}

template <typename type>
inline void ArbolB<type>::inorden(Node<type> *ptr, list<type> &in){

    Node<type> *aux;

    if(ptr != NULL){
        inorden(ptr->getLeft(),in);
        in.insert(in.end(), ptr->getDatos());
        inorden(ptr->getRight(),in);
        
    }
}

/***************CONSTRUCCION DE ARBOLES MEDIANTE LISTAS DE SUS RECORRIDOS ************************/

template <typename type>
void ArbolB<type>::construirPreIn(list<type> &preorden, list<type> &inorden){

    this->weight = preorden.size();
    this->root = construirPreIn(preorden,inorden,1,preorden.size());
}

template <typename type>
Node<type>* ArbolB<type>::construirPreIn(list<type> &preorden, list<type> &inorden, int inicio, int fin){

    int K;
    type root_aux;

    if(inicio <= fin && !preorden.empty()){
        root_aux = preorden.front();
        preorden.pop_front();
        K = consult(inorden,root_aux);
        return new Node<type>(root_aux,
/*izq*/     construirPreIn(preorden,inorden,inicio,K-1),
/*der*/     construirPreIn(preorden,inorden,K+1,fin));
    }
    
}

template <typename type>
void ArbolB<type>::construirPostIn(list<type> &postorden, list<type> &inorden){

    postorden.reverse();
    this->weight = postorden.size();
    this->root = construirPostIn(postorden,inorden,1,postorden.size());

}


template <typename type>
Node<type>* ArbolB<type>::construirPostIn(list<type> &postorden, list<type> &inorden, int inicio, int fin){

    int K;
    type root_aux;
    Node<type> *R = 0;

    if(inicio <= fin && !postorden.empty()){
        root_aux = postorden.front();
        postorden.pop_front();
        K = consult(inorden,root_aux);
        R = new Node<type>(root_aux);
        R->setRight(construirPostIn(postorden,inorden,K+1,fin));
        R->setLeft(construirPostIn(postorden,inorden,inicio,K-1));
    }
    return R;
}

template <typename type>
int ArbolB<type>::consult(list<type> &list, type element){


    typename list<type>::const_iterator i;
    int pos;
    bool flag;

    i = list.begin();
    pos = 0;
    flag = false;

    while(i != list.end() && !flag){

        if(*i == element)
            flag = true;
        i++;
        pos++;
    }
    return pos;
}

template <typename type>
int ArbolB<type>::max(int a, int b){return (a>b)? a : b;}

#endif