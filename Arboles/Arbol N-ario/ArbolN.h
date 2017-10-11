                        /****ESTRUCTURA DINAMICA ARBOL N-ario. © GABRIEL A. OLIVEIRA N.*****/

#ifndef ARBOLN_H_
#define ARBOLN_H_
#include "NodoArbol.h"
#include <list>
#include <iostream>
#include <iomanip>
#include <iterator>
using namespace std;

template <class type>
class ArbolN{                                   /*****ARBOL N-ARIO*****/

public:

    ArbolN();                                   /*Construye un arbol nulo*/
    ArbolN(type);                               /*Construye un arbol con un elemento en la root*/
    ArbolN(type,const list<ArbolN<type> >&);    /*Construye una copia de un arbol*/
    ~ArbolN();                                  /*Destruye el arbol*/
    
    int getWeight();                            /*Devuelve el peso del arbol*/
    int getHeight();
    
    bool isNull();                              /*Indica si el arbol es vacio*/
    bool isLeave();                             /*Indica si el arbol es hoja*/
    bool isSub(const ArbolN<type> &);           /*Indica si un arbol B, es sub-arbol, de un arbol A*/
    bool search(type);                          /*Busca un elemento*/
    
    type getRoot();                             /*Devuelve el elemento raiz del arbol*/
    
    /**/list<ArbolN<type> > gethijos();             /*Devuelve una lista con todos los sub-arboles del arbol*/
    list<type> getSons();                       /*Devuelve una lista de los hijos de un nodo dado*/
    list<type> road(type);                      /*Devuelve una lista con los elementos desde la raiz hasta un elemento B*/
    list<type> getBrothers();                   /*Devuelve una lista con los hermanos de un elemento*/
    list<type> Border();                            /*Devuelve una lista con los elementos frontera de un arbol*/
    
    void insert(type);                          /*Inserta un elemento en la raiz*/
    void insert(const ArbolN &, type = -1);     /*Inserta un sub-arbol como hermano de un elemento dado, si no se envia el elemento en la llamada, se inserta el subarbol como hijo de la raiz*/
    void remove(int);                           /*Elimina un elemento del arbol y a toda su descendencia*/

    /*********RECORRIDOS********/

    list<type> preorden();
    list<type> inorden();
    list<type> postorden();
    list<type> levels();

private:

    Node<type>* copyNodes(Node<type> *);
    void removeNodes(Node<type>*);
    void preorden(Node<type> *, list<type> &);
    void inorden(Node<type> *, list<type> &);
    void postorden(Node<type> *, list<type> &);
    void levels(Node<type> *, list<type> &);
    void Border(Node<type> *, list<type> &);
    void search(type, Node<type> *, Node<type> *& , bool *);
    void isSub(Node<type> *, Node<type> *, bool *);
    void road(Node<type> *,type, bool *, list<type> &);
    int getHeight(Node<type> *ptr);

    Node<type> *root;
    int weight;

};


/*:::::::::::::::IMPLEMENTACIONES:::::::::::::*/


template <typename type>
ArbolN<type>::ArbolN(){ this->root = NULL; this->weight = 0;}

template <typename type>
ArbolN<type>::ArbolN(type r){ this->root = new Node<type>(r);this->weight = 1;}

template <typename type>
bool ArbolN<type>::isNull(){return (root == NULL);}

template <typename type>
bool ArbolN<type>::isLeave(){return (root->getSonLeft() == NULL && root->getSonRight() == NULL);}

template <typename type>
type ArbolN<type>::getRoot(){return root->getDatos();}

template <typename type>
int ArbolN<type>::getWeight(){return weight;}

template <typename type>
ArbolN<type>::~ArbolN(){ removeNodes(root);}

template <typename type>
ArbolN<type>::ArbolN(type dato, const list<ArbolN<type> > &L){

    Node<type> aux;
    root = new Node<type>(dato);

    if(!L.empty()){
        root->setSonLeft(copiarNodos(L.front().root));
        L.remove(L.begin());
        aux = root->getSonLeft();

        while(!L.empty()){
            aux->setBroRight(copiarNodos(L.front()).root);
            L.remove(L.begin());
            aux = aux->getBroRight();
        }
    }
}

template <typename type>
Node<type>* ArbolN<type>::copyNodes(Node<type> *N){

    if(N == NULL)
        return NULL;
    else
        return new Node<type>(N->getDatos(), copyNodes(N->getSonLeft()), copyNodes(N->getBroRight()));
}

template <typename type>
list<type> ArbolN<type>::getSons(){

    Node<type> *aux;
    list<type> L;

    aux = root->getSonLeft();
    while(aux != NULL){
        L.insert(L.end(),aux->getDatos()); // inserta una copia del arbol
        aux = aux->getBroRight();
    }

    return L;   // devuelve una lista de arboles
}


template <typename type>
void ArbolN<type>::insert(type info){

    Node<type> *New, *aux, *prev;

    New =  new Node<type>(info);

    if(weight == 0)
        root = New;
    else{
        if(weight == 1)
            root->setSonLeft(New);
        else{
            prev = root->getSonLeft();
            aux = prev->getBroRight();

            while(aux != NULL){
                prev = aux;
                aux = aux->getBroRight();
            }
            prev->setBroRight(New);
        }
    }
    weight = weight+1;
}


template <typename type>
void ArbolN<type>::insert(const ArbolN &sub, type elemento){

    Node<type> *aux;

    if(elemento == -1){          /*SI no se proporciona el valor, queda como el predeterminado (-1), lo inserta como hermano de la root*/
   
        if(root->getSonLeft() == NULL)
            root->setSonLeft(copiarNodos(sub.root));
        else{
            aux = root->getSonLeft();

            while(aux->getBroRight()!= NULL)
                aux = aux->getBroRight();
            aux->setBroRight(copyNodes(sub.root));
        }
    }
    this->weight = this->weight+sub.weight;
}


template <typename type>
void ArbolN<type>::removeNodes(Node<type> *P){

    if(P != NULL){

        if(P->getBroRight() != NULL)
            removeNodes(P->getBroRight());
        if(root->getSonLeft() != NULL)
            removeNodes(P->getSonLeft());

        delete P;
        P = NULL;
    }
}

template <typename type>
void ArbolN<type>::remove(int pos){

    Node<type> *aux, *del;
    int i;

    if(pos > 0 && pos <= weight){

        if(pos == 1){
            del = root->getSonLeft();
            root->setSonLeft(root->getSonLeft()->getBroRight());
        }
        else{

            aux = root->getSonLeft();
            for(int i = 2; i< pos-1; i++)
                aux = aux->getBroRight();

            del = aux->getBroRight();
            aux->setBroRight(aux->getBroRight()->getBroRight());
        }
        del->setBroRight(NULL);
        removeNodes(del);
    }
}

template <typename type>
list<type> ArbolN<type>::getBrothers(){

    list<type> bro;
    Node<type> *aux; 
    aux = root->getSonLeft();

    while(aux != NULL){
        bro.insert(bro.end(),aux->getDatos());
        aux= aux->getBroRight(); 
    }
    return bro;
}


/****** RECORRIDOS PUBLICOS *****/

template <typename type>
list<type> ArbolN<type>::preorden(){

    list<type> elements;
    if(root != NULL)
        preorden(root,elements);

    return elements;
}


template <typename type>
list<type> ArbolN<type>::inorden(){

    list<type> elements;

    if(root != NULL)
        inorden(root,elements);
    return elements;

}

template <typename type>
list<type> ArbolN<type>::postorden(){

    list<type> elements;

    if(root != NULL)
        postorden(root,elements);
    return elements;
}


/****** RECORRIDOS PRIVADOS *****/

template <typename type>
void ArbolN<type>::preorden(Node<type> *p, list<type> &L){

    Node<type> *aux;

    if(p != NULL){

        L.insert(L.end(),p->getDatos());
        aux = p->getSonLeft();

        while(aux != NULL){
            preorden(aux,L);
            aux = aux->getBroRight();
        }
    }

}


template<typename type>
void ArbolN<type>::inorden(Node<type> *p, list<type> &L){

    Node<type> *aux;

    if(p != NULL){
        inorden(p->getSonLeft(),L);
        L.insert(L.end(),p->getDatos());

        aux = p->getSonLeft();

        if(aux != NULL)
            aux = aux->getBroRight();

        while(aux != NULL){
            inorden(aux,L);
            aux = aux->getBroRight();
        }               
    }
}

template<typename type>
void ArbolN<type>::postorden(Node<type> *p, list<type> &L){

    Node<type> *aux;

    if(p != NULL){
        aux = p->getSonLeft();

        while(aux != NULL){
            postorden(aux,L);
            aux = aux->getBroRight();
        }
        L.insert(L.end(),p->getDatos());
    }
}

template <typename type>
list<type> ArbolN<type>::Border(){

    /*Todos los elementos, dentro de las hojas del arbol*/

    list<type> leaves;

    if(root != NULL)
        Border(root,leaves);
    return leaves;
}


template <typename type>
void ArbolN<type>::Border(Node<type> *p, list<type> &L){

    Node<type> *leave;

    if(p !=NULL)
    {
        if(p->getSonLeft() == NULL)
            L.insert(L.end(), p->getDatos());
        else
        {
            leave = p->getSonLeft();
            while(leave != NULL)
            {
                Border(leave,L);
                leave = leave->getBroRight();
            }

        }

    }
}

template <typename type>
list<type> ArbolN<type>::levels(){

    list<type> niv;
    if(root != NULL)
        levels(root,niv);
    return niv;
}

template <typename type>
void ArbolN<type>::levels(Node<type> *p, list<type> &L){

    Node<type> *auxiliar;

    if(p != NULL){

        L.insert(L.end(),p->getDatos());
        auxiliar = p->getBroRight();

        if(auxiliar == NULL)
            auxiliar = p->getSonLeft();

        while(auxiliar != NULL){
            levels(auxiliar,L);
            auxiliar = auxiliar->getSonLeft();
        }
    }
}

template <typename type>
bool ArbolN<type>::search(type e){

    bool res=false;
    Node<type> *prox;

    search(e,root,prox,&res);
    return res;
}

template <typename type>
void ArbolN<type>::search(type e, Node<type> *p, Node<type> *&prox, bool *flag){

    /*verifica si un elemento existe dentro del arbol, si el elemento existe,
    carga un valor booleano en "flag" indicando true y para hacer mas escalable 
    el procedimiento, carga un apuntador a nodo "prox", con la direccion de memoria
    del nodo donde se encuentra el elemento */

    Node<type> *aux;

    if(p != NULL){
        if(p->getDatos() == e){
            *flag = true;
            prox = p;
        }   
            aux = p->getSonLeft();
            while(aux != NULL && *flag == false){   
                search(e,aux,prox,flag);
                aux = aux->getBroRight();           
            }
    }   
}

template <typename type>
list<type> ArbolN<type>::road(type element){

    bool flag = true;
    list<type> L;

    camino(root,element,&flag,L);
    return L;
}

template <typename type>
void ArbolN<type>::road(Node<type> *ptr, type element, bool *flag, list<type> &L){

    
    if(ptr != NULL && *flag){

        L.insert(L.end(), ptr->getDatos());

        if(ptr->getDatos() == element)
            *flag = false;
        else{
            camino(ptr->getSonLeft(), element,flag, L);
            if(*flag && L.size() > 1)   
                L.pop_back();                           //entra primero aqui con el 1 y lo elimina
            camino(ptr->getBroRight(),element,flag,L);  // entra con el hermano, lo imprime, flag se hace false y listo
            if(*flag && L.size() > 1)
                L.pop_back();
            
            
        }
    }
}



template <typename type>
bool ArbolN<type>::isSub(const ArbolN<type> &sub){

    bool flag = true;
    bool flagFind = false;
    Node<type> *rootFound;

    search(sub.root->getDatos(),this->root,rootFound,&flagFind);

    if(flagFind)
        isSub(rootFound,sub.root,&flag);

    return flag;

}

template <typename type>
void ArbolN<type>::isSub(Node<type> *ptrAct, Node<type> *ptrSub, bool *flag){


    if(ptrAct != NULL && ptrSub != NULL)
    {

        if(ptrAct->getDatos() == ptrSub->getDatos())
        {
            if((ptrAct->getLeft() == NULL && ptrSub->getLeft() == NULL) || (ptrAct->getLeft() != NULL && ptrSub->getLeft() != NULL))
            {   // es subArbol si ambos hijos son nulos o si ambos hijos son distintos de nulo
                isSub(ptrAct->getLeft(), ptrSub->getLeft(), flag);
            }
            else
                *flag = false;

            if(*flag && (ptrAct->getRight() == NULL && ptrSub->getRight() == NULL) || (ptrAct->getRight() != NULL && ptrSub->getRight() != NULL))
            {   // si aun es subArbol luego de recorrer a los hijos, sigue siendo subArbol si ambos hermanos son nulos o si ambos hermanos son distintos de nulo
                isSub(ptrAct->getRight(), ptrSub->getRight(), flag);
            }

        }
        else
            *flag = false;

    }
}

template <typename type>
int ArbolN<type>::getHeight(){ return (this->isNull())? return -1: getHeight(root);} 


template <typename type>
int ArbolN<type>::getHeight(Node<type> *ptr){ 

    Node<type> *aux;

    if(ptr != NULL){
        aux = ptr->getSonLeft();

        while(aux != NULL){
            return 1 + getHeight(aux);
            aux = aux->getBroRight();
        }       
    }
}

#endif