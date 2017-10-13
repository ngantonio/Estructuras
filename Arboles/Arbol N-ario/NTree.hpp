                         /****ESTRUCTURA DINAMICA ARBOL N-ario. © GABRIEL A. OLIVEIRA N.*****/

#ifndef NTREE_H_
#define NTREE_H_
#include "TNode.hpp"
#include <list>
#include <iostream>
#include <iomanip>
#include <iterator>
using namespace std;

template <class type>
class NTree{

public:

    NTree();                                   /*Construye un arbol nulo*/
    NTree(type);                               /*Construye un arbol con un elemento en la raiz*/
    NTree(type,const list<NTree<type> >&);     /*Construye un arbol dado un elemento raiz y una lista de un arboles*/
    NTree(type,const list<type> &s);           /*Construye un arbol dado un elemento raiz y una lista de hijos*/
    NTree(NTree<type> &);                      /*Construye una copia de un arbol dado*/
    ~NTree();                                  /*Destruye el arbol*/
    
    int getWeight();                           /*Devuelve el peso del arbol*/
    int getHeight();                           /*Devuelve la altura del arbol*/
    
    bool isNull();                             /*Indica si el arbol es vacio*/
    bool isLeave();                            /*Indica si el arbol es hoja*/
    bool isSub(const NTree<type> &);           /*Indica si un arbol B, es sub-arbol, de un arbol A*/
    bool search(type);                         /*Busca un elemento*/
    
    type getRoot();                            /*Devuelve el elemento raiz del arbol*/

    list<type> getSons(type);                     /*Devuelve una lista con todos hijos de un elemento dado*/
    list<type> road(type);                        /*Devuelve una lista con los elementos desde la raiz hasta un elemento B*/
    list<type> border();                          /*Devuelve una lista con los elementos frontera de un arbol*/
    NTree<type> &operator=(const NTree<type> &);  /*Devuelve true si dos arboles son iguales*/
    
    void setRoot(type);                        /*Establece el elemento raiz del arbol*/
    void insert(type,type);                    /*Dado un elemento padre, le inserta un elemento hijo*/
    void insert(type,const NTree &);           /*Inserta un sub-arbol como hijo o hermano de un elemento dado*/
    void insert(type ,const list<type> &);     /*Dado un elemento padre, le inserta una lista de hijos (si este existe)*/
    void remove(type);                         /*Elimina a toda la descendencia de un elemento en el arbol*/

    

    /*********RECORRIDOS********/

    inline list<type> preorden();
    inline list<type> inorden();
    inline list<type> postorden();
    inline list<type> levels();

private:

    /*Metodos utilitarios necesarios para construir 
    y recorrer la estructura*/

    TNode<type>* copyNodes(TNode<type> *);
    void removeNodes(TNode<type>*);
    inline void preorden(TNode<type> *, list<type> &);
    inline void inorden(TNode<type> *, list<type> &);
    inline void postorden(TNode<type> *, list<type> &);
    inline void levels(TNode<type> *, list<type> &);
    void border(TNode<type> *, list<type> &);
    void search(type, TNode<type> *, TNode<type> *& , bool *);
    void isSub(TNode<type> *, TNode<type> *, bool *);
    void road(TNode<type> *,type, bool *, list<type> &);
    void getHeight(TNode<type> *, int *, int *); 

    TNode<type> *root;
    int weight;

};


/*:::::::::::::::IMPLEMENTACIONES:::::::::::::*/


/***** CONSTRUCTORES *****/

template <typename type>
NTree<type>::NTree(){ this->root = NULL; this->weight = 0;}

template <typename type>
NTree<type>::NTree(type r){ this->root = new TNode<type>(r); this->weight = 1;}

template <typename type>
NTree<type>::NTree(type r, const list<NTree<type> > &sons){

    TNode<type> *aux;
    typename list<type>::const_iterator i;  /*Iterador constante para poder recorrer la lista*/
    this->root = new TNode<type>(r);         /*construye la raiz*/

    if(!sons.empty()){

        i= sons.begin();                                    /*inicia el iterador con el primer arbol de la lista.*/
        this->root->setSonLeft(copyNodes(sons.front().root));  /*establece el hijo izquierdo con el primer arbol de la lista*/
        aux = root->getSonLeft();                           /*Obtiene el ptr hacia el hijo que se acaba de insertar para acceder a su hermano*/
        i++;                                                /*aumenta el iterador hacia el segundo arbol en la lista*/
        this->weight = this->weight+ sons.front().weight;      /*suma al peso del arbol, el peso del primer arbol de la lista*/

        while(i != sons.end()){
            aux->setBroRight(copyNodes(*i.root));           /*mientras queden arboles en la lista, copia cada uno como*/
            aux = aux->getBroRight();                       /*hijo de la raiz (hermano del anterior)*/
            this->weight = this->weight+(*i.weight);        /*aumenta el peso del arbol*/
            i++;                                            /*aumenta el iterador*/
        }
    }
}

template <typename type>
NTree<type>::NTree(type father,const list<type> &sons){
    this->setRoot(father);
    this->insert(father,sons);

}

template <typename type>
NTree<type>::NTree(NTree<type> &sub){

    if(sub.root != NULL){
        this->root = copyNodes(sub.root);
        this->weight = sub.weight;
    }
}

template <typename type>
NTree<type>::~NTree(){ removeNodes(this->root);}



/***** INSERCIONES *****/

template <typename type>
void NTree<type>::insert(type father, type son){

    TNode<type> *New, *aux, *newRoot;
    bool flag = false;

    /*Pre-procesamiento, si el elemento enviado es igual a la raiz
    no tiene que hacer una llamada a la funcion de busqueda*/

    if(this->root != NULL){
        if(father == this->root->getData()){
            newRoot = this->root;
            flag = true;
        }else
            search(father,this->root,newRoot,&flag);
    }

    if(flag){
        New =  new TNode<type>(son);
        if(newRoot->getSonLeft() == NULL)
            newRoot->setSonLeft(New);
        else{

            aux = newRoot->getSonLeft();
            while(aux->getBroRight() != NULL)
                aux = aux->getBroRight();

            aux->setBroRight(New);
        }
        this->weight++;
    }
}

template <typename type>
void NTree<type>::insert(type father,const NTree<type> &sub){

    /*Es trivial pensar que se va a insertar un arbol como hijo de
    un elemento dado, sin embargo para efectos de este modelo de estructura
    es un poco mas complejo: */

    TNode<type> *aux;
    bool flag = false;

    /*Pre-procesamiento, si el elemento enviado es igual a la raiz
    no tiene que hacer una llamada a la funcion de busqueda*/

    if(this->root != NULL && sub.root != NULL){
        if(father == this->root->getData()){
            aux = this->root;
            flag = true;
        }else
            search(father,this->root,aux,&flag);
    }

    if(flag){
        if(aux->getSonLeft() == NULL)              /*si el elemento no tiene un nodo hijo, inserta a la raiz del*/
            aux->setSonLeft(copyNodes(sub.root));  /*sub arbol como nodo hijo, y copia el resto del arbol*/
        else{
            aux = aux->getSonLeft();               /*En caso de que tenga un hijo, se obtiene ese nodo para luego acceder a los hermanos de el*/        
            
            while(aux->getBroRight()!= NULL)       /*mueve el apuntador hasta que ya no tenga hermanos*/
                 aux =aux->getBroRight();

            aux->setBroRight(copyNodes(sub.root)); /*inserta a la raiz del sub arbol como un nuevo hermano y copia a sus elementos hijo*/
        }
    this->weight = this->weight+sub.weight;        /*suma  al peso del arbol, el peso del sub arbol*/
    }
}

template <typename type>
void NTree<type>::insert(type father ,const list<type> &sons){

    TNode<type> *rootFound,*New,*aux;
    bool flag = false;
    typename list<type>::const_iterator i;  /*Iterador constante para poder recorrer la lista*/

    /*Pre-procesamiento, si el elemento enviado es igual a la raiz
    no tiene que hacer una llamada a la funcion de busqueda*/

    if(this->root != NULL && !sons.empty()){
        if(father == this->root->getData()){
            rootFound = root;
            flag = true;
        }else
            search(father,this->root,rootFound,&flag);
    }
    
    if(flag){
        i = sons.begin();              /*coloca a i en el primer elemento de la lista*/
        New = new TNode<type>(*i);      /*crea un nuevo nodo con el primer elemento de la lista*/
        rootFound->setSonLeft(New);    /*Inserta al primer elemento de la lista como el unico hijo del elemento encontrado*/
        i++;                           /*aumenta el iterador al segundo elemento de la lista de hijos*/
        aux = rootFound->getSonLeft(); /*coloca en un ptr auxiliar al nodo hijo creado, para mediante el, comenzar a establecer a sus hermanos*/

        while(i != sons.end()){         /*mientras existan elementos en la lista*/

            New = new TNode<type>(*i);
            aux->setBroRight(New);      /*inserta al siguiente elemento un hermano*/ 
            aux = aux->getBroRight();   /*mueve el apuntador hacia el nuevo hermano insertado en la linea anterior*/ 
            i++;                        /*se mueve la lista hacia el siguiente elemento*/
        }
        this->weight = this->weight+sons.size();    /*aumenta el peso del arbol sumando la longitud de la lista*/ 
    }
}


/***** SEMANTICA OPERACIONAL *****/

template <typename type>
bool NTree<type>::isNull(){return (root == NULL);}

template <typename type>
bool NTree<type>::isLeave(){return (root->getSonLeft() == NULL && root->getBroRight() == NULL);}

template <typename type>
type NTree<type>::getRoot(){return root->getData();}

template <typename type>
int NTree<type>::getWeight(){return weight;}

template <typename type>
void NTree<type>::setRoot(type r){this->root = new TNode<type>(r);this->weight = 1;}


template <typename type>
list<type> NTree<type>::getSons(type father){

    TNode<type> *aux, *rootFound;
    bool flag = false;
    list<type> S;

    if(this->root != NULL){
        if(father == this->root->getData()){
            rootFound = root;
            flag = true;
        }else
            search(father,this->root,rootFound,&flag);
    }

    if(flag){
        aux = rootFound->getSonLeft();
        while(aux != NULL){
            S.insert(S.end(),aux->getData());  
            aux = aux->getBroRight();
        }
    }

   return S;
}

template <typename type>
NTree<type> &NTree<type>::operator=(const NTree<type> &sub){

    if(sub.root != NULL){
        this->root = copyNodes(sub.root);
        this->weight = sub.weight;
    }
    return *this;
}

template <typename type>
void NTree<type>::remove(type father){

    TNode<type> *aux, *d;
    bool flag = false;

    if(this->root != NULL){
        if(father == this->root->getData()){
            aux = this->root;
            flag = true;
        }else
            search(father,this->root,aux,&flag);
    }

    if(flag){
        if(aux->getSonLeft() != NULL){
            removeNodes(aux->getSonLeft());
            aux->setSonLeft(NULL); 
        }

    }
}


template <typename type>
list<type> NTree<type>::border(){

    /*Todos los elementos, dentro de las hojas del arbol*/

    list<type> leaves;

    if(root != NULL)
        border(root,leaves);
    return leaves;
}


template <typename type>
void NTree<type>::border(TNode<type> *p, list<type> &L){

    TNode<type> *leave;

    if(p !=NULL){
        if(p->getSonLeft() == NULL)
            L.insert(L.end(), p->getData());
        else{
            leave = p->getSonLeft();
            while(leave != NULL){
                border(leave,L);
                leave = leave->getBroRight();
            }
        }
    }
}

template <typename type>
bool NTree<type>::search(type e){

    bool res=false;
    TNode<type> *prox;

    search(e,root,prox,&res);
    return res;
}

template <typename type>
void NTree<type>::search(type e, TNode<type> *p, TNode<type> *&prox, bool *flag){

    /*verifica si un elemento existe dentro del arbol, si el elemento existe,
    carga un valor booleano en "flag" indicando true y para hacer mas escalable 
    el procedimiento, carga un apuntador a nodo "prox", con la direccion de memoria
    del nodo donde se encuentra el elemento */

    TNode<type> *aux;

    if(p != NULL){
        if(p->getData() == e){
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
list<type> NTree<type>::road(type element){

    bool flag = true;
    list<type> L;

    road(root,element,&flag,L);
    return L;
}

template <typename type>
void NTree<type>::road(TNode<type> *ptr, type element, bool *flag, list<type> &L){

    
    if(ptr != NULL && *flag){

        L.insert(L.end(), ptr->getData());

        if(ptr->getData() == element)
            *flag = false;
        else{
            road(ptr->getSonLeft(), element,flag, L);
            if(*flag && L.size() > 1)   
                L.pop_back();                           //entra primero aqui con el 1 y lo elimina
            road(ptr->getBroRight(),element,flag,L);  // entra con el hermano, lo imprime, flag se hace false y listo
            if(*flag && L.size() > 1)
                L.pop_back();
            
            
        }
    }
}

template <typename type>
bool NTree<type>::isSub(const NTree<type> &sub){

    bool flag = true;
    bool flagFind = false;
    TNode<type> *rootFound;

    search(sub.root->getData(),this->root,rootFound,&flagFind);

    if(flagFind)
        isSub(rootFound,sub.root,&flag);

    return flag;

}

template <typename type>
void NTree<type>::isSub(TNode<type> *ptrAct, TNode<type> *ptrSub, bool *flag){


    if(ptrAct != NULL && ptrSub != NULL)
    {

        if(ptrAct->getData() == ptrSub->getData())
        {
            if((ptrAct->getSonLeft() == NULL && ptrSub->getSonLeft() == NULL) || (ptrAct->getSonLeft() != NULL && ptrSub->getSonLeft() != NULL))
            {   // es subArbol si ambos hijos son nulos o si ambos hijos son distintos de nulo
                isSub(ptrAct->getSonLeft(), ptrSub->getSonLeft(), flag);
            }
            else
                *flag = false;

            if(*flag && (ptrAct->getBroRight() == NULL && ptrSub->getBroRight() == NULL) || (ptrAct->getBroRight() != NULL && ptrSub->getBroRight() != NULL))
            {   // si aun es subArbol luego de recorrer a los hijos, sigue siendo subArbol si ambos hermanos son nulos o si ambos hermanos son distintos de nulo
                isSub(ptrAct->getBroRight(), ptrSub->getBroRight(), flag);
            }

        }
        else
            *flag = false;

    }
}

template <typename type>
int NTree<type>::getHeight(){

    int acum = 1, total= 0;

    if(this->root != NULL)
        getHeight(root,&acum,&total);
    else
        total = -1;
    return total;

} 

template <typename type>
void NTree<type>::getHeight(TNode<type> *ptr, int *count, int *total){ 

    TNode<type> *aux;

    if(ptr != NULL){
        if(ptr->getSonLeft() == NULL && ptr->getBroRight() == NULL){ //estamos en una hoja
            if(*count > *total)
                *total = *count;
        }else{
            aux = ptr->getSonLeft();

            while(aux != NULL){
                *count = *count+1;
                getHeight(aux,count,total);
                *count = *count-1;
                aux = aux->getBroRight();
            }       
        }
    }     
}

template <typename type>
void NTree<type>::removeNodes(TNode<type> *P){

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
TNode<type>* NTree<type>::copyNodes(TNode<type> *N){

    if(N == NULL)
        return NULL;
    else
        return new TNode<type>(N->getData(), copyNodes(N->getSonLeft()), copyNodes(N->getBroRight()));
}



/****** RECORRIDOS PUBLICOS *****/

template <typename type>
inline list<type> NTree<type>::preorden(){

    list<type> elements;
    if(root != NULL)
        preorden(root,elements);

    return elements;
}


template <typename type>
inline list<type> NTree<type>::inorden(){

    list<type> elements;

    if(root != NULL)
        inorden(root,elements);
    return elements;

}

template <typename type>
inline list<type> NTree<type>::postorden(){

    list<type> elements;

    if(root != NULL)
        postorden(root,elements);
    return elements;
}

template <typename type>
inline list<type> NTree<type>::levels(){

    list<type> niv;
    if(root != NULL)
        levels(root,niv);
    return niv;
}


/****** RECORRIDOS PRIVADOS *****/

template <typename type>
inline void NTree<type>::preorden(TNode<type> *p, list<type> &L){

    TNode<type> *aux;

    if(p != NULL){

        L.insert(L.end(),p->getData());
        aux = p->getSonLeft();

        while(aux != NULL){
            preorden(aux,L);
            aux = aux->getBroRight();
        }
    }
}

template<typename type>
inline void NTree<type>::inorden(TNode<type> *p, list<type> &L){

    TNode<type> *aux;

    if(p != NULL){
        inorden(p->getSonLeft(),L);
        L.insert(L.end(),p->getData());

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
inline void NTree<type>::postorden(TNode<type> *p, list<type> &L){

    TNode<type> *aux;

    if(p != NULL){
        aux = p->getSonLeft();

        while(aux != NULL){
            postorden(aux,L);
            aux = aux->getBroRight();
        }
        L.insert(L.end(),p->getData());
    }
}

template <typename type>
inline void NTree<type>::levels(TNode<type> *p, list<type> &L){

    TNode<type> *auxiliar;

    if(p != NULL){

        L.insert(L.end(),p->getData());
        auxiliar = p->getBroRight();

        if(auxiliar == NULL)
            auxiliar = p->getSonLeft();

        while(auxiliar != NULL){
            levels(auxiliar,L);
            auxiliar = auxiliar->getSonLeft();
        }
    }
}

#endif