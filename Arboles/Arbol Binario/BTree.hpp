                        /****ESTRUCTURA DINAMICA ARBOL BINARIO. © GABRIEL A. OLIVEIRA N.*****/

#ifndef BTREE_H_
#define BTREE_H_
#include "TNode.hpp"
#include <list>
#include <iterator>
#include <string>
#include <cstdio>
using namespace std;

template <class type>
class BTree{

public:

    BTree();                                           /*Crea un arbol binario Nulo*/
    BTree(type);                                       /*Crea un arbol binario con su raiz */
    BTree(const BTree &);                             /*Copia un arbol dado en otro*/
    BTree(type,const BTree &, const BTree &);        /*Crea un arbol binario con su raiz, su hijo izquierdo y su hijo derecho*/
    BTree(string &, list<type> &, string &, list<type> &); /*Construye un arbol dados sus recoridos*/
    ~BTree();                                              /*Destruye un arbol binario*/
    
    bool isNull();                                          /*¿Es nulo?*/
    bool isLeave();                                         /*¿Es hoja?*/
    bool isLeftHanded();                                    /*¿Es zurdo?*/
    bool isComplete();                                      /*¿Es Completo?*/
    bool isSub(const BTree<type> &);                       /*Indica si un arbol B, es sub-arbol, de un arbol A*/
    bool search(type);                                      /*Devuelve true, si un elemento esta dentro de un arbol*/
    bool operator==(BTree<type> &);                        /*¿El arbol A es igual al arbol B?*/
    
    type getRoot();                                     /*Devuelve la raiz del arbol*/
    
    int getWeight();                                    /*Devuelve el peso del arbol*/
    int getHeight();                                    /*Devuelve la altura del arbol*/
    int Diameter();                                     /*Devuelve el diametro de un arbol*/
    
    BTree<type> mirror();                              /*Devuelve un arbol espejo del original*/
    BTree<type> getSonLeft();                          /*Devuelve el hijo izquierdo de un arbol*/
    BTree<type> getSonRight();                         /*Devuelve el hijo derecho de un arbol*/
    list<BTree<type> > getHijos();                     /*Devuelve una lista con ambos hijos*/
    
    void setRoot(type);
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
    TNode<type> *root;
    int weight;

private:

    /*Metodos utilitarios necesarios para construir 
    y recorrer la estructura*/

    TNode<type> * copyNodes(TNode<type> *);
    void removeNodes(TNode<type> *);
    inline void preorden(TNode<type> *, list<type> &);
    inline void inorden(TNode<type> *, list<type> &);
    inline void postorden(TNode<type> *, list<type> &);
    inline void levels(TNode<type> *, int *, int, list<type> &);
    void search(type, TNode<type> *, TNode<type> *&, bool *);
    void isLeftHanded(TNode<type> *, int *, bool *flag);
    void isComplete(TNode<type> *, bool *);
    TNode<type>* mirror(TNode<type> *);
    TNode<type>* construirPreIn(list<type> &, list<type> &, int, int);
    TNode<type>* construirPostIn(list<type> &, list<type> &, int ,int);
    int consult(list<type> &, type);
    void isEqual(TNode<type> *, TNode<type> *, bool *);
    void getHeight(TNode<type> *, int *, int *);
    
    int Diameter(TNode<type> *, int *);
    int max(int a, int b);

};


/*:::::::::::::::IMPLEMENTACIONES:::::::::::::*/


/***** CONSTRUCTORES *****/

template <typename type>
BTree<type>::BTree(){
    this->root = NULL;
    weight = 0;
}

template <typename type>
BTree<type>::BTree(type info){

    TNode<type> *New;

    New = new TNode<type>(info);
    root = New;
    weight = 1;
}


template <typename type>
BTree<type>::BTree(type r ,const BTree &izquierdo, const BTree &derecho){

    TNode<type> *New;

    New = new TNode<type>(r);
    root = New;
    root->setLeft(copyNodes(izquierdo.root));
    root->setRight(copyNodes(derecho.root));
    weight = izquierdo.weight + derecho.weight;
}

template <typename type>
BTree<type>::BTree(const BTree &copia){ 
    root = copyNodes(copia.root); 
    weight = copia.weight;
}

template <typename type>
BTree<type>::BTree(string &nombre1, list<type> &recorrido1, string &nombre2, list<type> &recorrido2){

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
BTree<type>::~BTree(){removeNodes(root);}



/***** INSERCIONES *****/

template <typename type>
void BTree<type>::setRoot(type R){

    if(this->root == NULL){
        TNode<type> *New;
        New = new TNode<type>(R);
        this->root = New;
        weight = 1;
    }
}

template <typename type>
void BTree<type>::setSonLeft(type padre, type dato){

    TNode<type> *New, *aux;
    bool flag = false;

    search(padre,root,aux,&flag);
    
    if(flag && aux->getLeft() == NULL){
        New = new TNode<type>(dato);
        aux->setLeft(New);
    }
    this->weight++;
}

template <typename type>
void BTree<type>::setSonRight(type padre, type dato){

    TNode<type> *New, *aux;
    bool flag = false;

    search(padre,root,aux,&flag);
    
    if(flag && aux->getRight() == NULL){
        New = new TNode<type>(dato);
        aux->setRight(New);
    }
    this->weight++;
}



/***** SEMANTICA OPERACIONAL *****/

template <typename type>
bool BTree<type>::isNull(){return this->root == NULL;}

template <typename type>
bool BTree<type>::isLeave(){return (root->getLeft() == NULL && root->getRight() == NULL);}

template <typename type>
type BTree<type>::getRoot(){return root->getData();}

template <typename type>
int BTree<type>::getWeight(){return weight;}




template <typename type>
void BTree<type>::remove(type element){

    TNode<type> *ptr;
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
BTree<type> BTree<type>::getSonLeft(){

    BTree<type> son;

    (root != NULL)? son.root = copyNodes(root->getLeft()) : son.root = NULL;
    return son;
}

template <typename type>
BTree<type> BTree<type>::getSonRight(){

    BTree<type> son;

    (root != NULL)? son.root = copyNodes(root->getRight()) : son.root = NULL;
    return son;
}

template <typename type>
bool BTree<type>::search(type elemento){

    TNode<type> *new_root;
    bool flag = false;

    search(elemento,root,new_root,&flag);
    return flag;

}

template <typename type>
void BTree<type>::search(type elemento,TNode<type> *root, TNode<type> *&ptr, bool *flag){

    if(root != NULL){
        if(root->getData() == elemento){
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
bool BTree<type>::isLeftHanded(){

    int totalWeight = 0;
    bool flag = false;

    isLeftHanded(root,&totalWeight,&flag);
    return flag;
}


template <typename type>
void BTree<type>::isLeftHanded(TNode<type> *ptr, int *n, bool *flag){

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
            rightWeight = 0;
            isLeftHanded(ptr->getLeft(),&leftWeight,&leftFlag);
            rightFlag = false;
            if(leftFlag)
                isLeftHanded(ptr->getRight(),&rightWeight,&rightFlag);

            *n = 1+leftWeight + rightWeight;
            *flag = (leftFlag && rightFlag && (leftWeight > rightWeight));

            /*ambos hijos deben ser zurdos y el peso izquierdo debe ser mayor al peso derecho*/
        }
    }

}

template <typename type>
BTree<type> BTree<type>::mirror(){
    BTree<type> esp;

    esp.root = mirror(root);
    return esp;
}

template <typename type>
TNode<type>* BTree<type>::mirror(TNode<type> *ptr){

    TNode<type> *New;

    if(ptr == NULL)
        return NULL;
    else
        New = new TNode<type>(ptr->getData(), mirror(ptr->getRight()), mirror(ptr->getLeft()));
    return New;

}

template <typename type>
bool BTree<type>::isComplete(){

    bool flag = true;
    isComplete(root,&flag);
    return flag;
}

template <typename type>
void BTree<type>::isComplete(TNode<type> *ptr, bool *flag){

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
bool BTree<type>::operator==(BTree<type> &sub){

    bool flag = true;

    if(this != &sub && this->weight == sub.weight)
        isEqual(this->root,sub.root,&flag);
    else
        flag = false;  

    return flag;
}

template <typename type>
bool BTree<type>::isSub(const BTree<type> &sub){

    bool flag = true;
    bool flagFind = false;
    TNode<type> *rootFound;

    /*busca la primera aparicion de la raiz del subarbol
    dentro del arbol actual y la envia a isEqual como la
    raiz actual del arbol. isEqual comprueba que sean isomorfos 
    y tengan los mismos datos*/

    search(sub.root->getData(),this->root,rootFound,&flagFind);

    if(flagFind)
        isEqual(rootFound,sub.root,&flag);
    else
        flag = false;

    return flag;
}

template <typename type>
void BTree<type>::isEqual(TNode<type> *ptrAct, TNode<type> *ptrSub, bool *flag){

    /*determina si un arbol es igual a otro, en elementos (Semejante) y en estructura (isomorfo)*/

    if(ptrAct != NULL && ptrSub != NULL)
    {
        if(ptrAct->getData() == ptrSub->getData()){

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
int BTree<type>::Diameter(){

    int level = 0;
    if(root != NULL) 
        return Diameter(root,&level);
    else
        return -1;   
}


template <typename type>
int BTree<type>::Diameter(TNode<type> *ptr, int *level){

    int lh,rh,alturaIzq, alturaDer, diameterSubTree, subtreeMax;

    lh = 0;
    rh = 0;

    if(ptr == NULL){
        *level = 0;
        return 0;
    }else{

        alturaIzq = Diameter(ptr->getLeft(),&lh);
        alturaDer = Diameter(ptr->getRight(),&rh);
        diameterSubTree = lh + rh;        
        *level = max(lh, rh)+1;                 
        subtreeMax = max(alturaIzq, alturaDer);
        return max(diameterSubTree,subtreeMax);
    }

}

template <typename type>
int BTree<type>::getHeight(){

    int acumulado, total;
    acumulado = 1;
    total = 0;

    if(root != NULL)
        getHeight(root,&acumulado,&total);
    else
        total = -1;

    return total;
}

template <typename type>
void BTree<type>::getHeight(TNode<type> *p, int *acumulado, int *total){

    if(p != NULL){

        if(p->getLeft() == NULL && p->getRight() == NULL){
            if(*acumulado > *total)
                *total = *acumulado;
        }else{
            *acumulado = *acumulado+1;
            getHeight(p->getLeft(),acumulado,total);            
            getHeight(p->getRight(),acumulado,total);
            *acumulado = *acumulado-1;
        }
    } 
}

template <typename type>
list<BTree<type> >BTree<type>::getHijos(){

    list<BTree<type> > H;
    BTree<type> L,R;

    if(root != NULL){
        BTree<type> L( this->getSonLeft());
        BTree<type> R(this->getSonRight());
        H.insert(H.end(),L);
        H.insert(H.end(),R);
    }   
    return H;   
}

template <typename type>
inline list<type> BTree<type>::levels(int levelA, int levelB){

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
inline void BTree<type>::levels(TNode<type> *p, int *acum, int level, list<type> &N){

    if(p != NULL){

        if(*acum == level)                /*calcula implicitamente la altura, si el contador de */
            N.push_back(p->getData());   /*altura es igual al nivel dado, quiere decir que el elemento*/
                                          /*se encuentra en ese nivel, por tanto, lo inserta en la lista.*/
        *acum = *acum+1;
        levels(p->getLeft(),acum,level,N);           
        levels(p->getRight(),acum,level,N);
        *acum = *acum-1;
        
    }
    
}

template <typename type>
TNode<type>* BTree<type>::copyNodes(TNode<type> *p){

    TNode<type> *New;

    if(p ==  NULL)
        return NULL;
    else
        return New = new TNode<type>(p->getData(),copyNodes(p->getLeft()), copyNodes(p->getRight()));
    
}

template <typename type>
void BTree<type>::removeNodes(TNode<type> *ptr){

    if(ptr != NULL){
        if(ptr->getLeft() != NULL)
            removeNodes(ptr->getLeft());
        if(ptr->getRight() != NULL)
            removeNodes(ptr->getRight());

        delete ptr;
        ptr = NULL;
    }
}


/********RECORRIDOS PUBLICOS**********/

template <typename type>
inline list<type> BTree<type>::preorden(){

    list<type> pre;
    if(root != NULL)
        preorden(root,pre);
    return pre;
}

template <typename type>
inline list<type> BTree<type>::inorden(){

    list<type> in;
    if(root != NULL)
        inorden(root,in);
    return in;
}

template <typename type>
inline list<type> BTree<type>::postorden(){

    list<type> post;
    if(root != NULL)
        postorden(root,post);
    return post;
}


template <typename type>
inline list<type> BTree<type>::levels(){

    /*iterativo*/

    list<type> L;
    list<TNode<type>* > C;

    if(root)
        C.insert(C.begin(),root);

    while(!C.empty()){

        L.insert(L.end(),C.front()->getData());

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
inline void BTree<type>::preorden(TNode<type> *ptr, list<type> &pre){

    TNode<type> *aux;

    if(ptr != NULL){
        pre.insert(pre.end(),ptr->getData());
        preorden(ptr->getLeft(),pre);
        preorden(ptr->getRight(),pre);
    }
}

template <typename type>
inline void BTree<type>::postorden(TNode<type> *ptr, list<type> &post){

    TNode<type> *aux;

    if(ptr != NULL){
        postorden(ptr->getLeft(),post);
        postorden(ptr->getRight(),post);
        post.insert(post.end(),ptr->getData());
    }
}

template <typename type>
inline void BTree<type>::inorden(TNode<type> *ptr, list<type> &in){

    TNode<type> *aux;

    if(ptr != NULL){
        inorden(ptr->getLeft(),in);
        in.insert(in.end(), ptr->getData());
        inorden(ptr->getRight(),in);
        
    }
}

/***************CONSTRUCCION DE ARBOLES MEDIANTE LISTAS DE SUS RECORRIDOS ************************/

template <typename type>
void BTree<type>::construirPreIn(list<type> &preorden, list<type> &inorden){

    this->weight = preorden.size();
    this->root = construirPreIn(preorden,inorden,1,preorden.size());
}

template <typename type>
TNode<type>* BTree<type>::construirPreIn(list<type> &preorden, list<type> &inorden, int inicio, int fin){

    int K;
    type root_aux;

    if(inicio <= fin && !preorden.empty()){
        root_aux = preorden.front();
        preorden.pop_front();
        K = consult(inorden,root_aux);
        return new TNode<type>(root_aux,
/*izq*/     construirPreIn(preorden,inorden,inicio,K-1),
/*der*/     construirPreIn(preorden,inorden,K+1,fin));
    }
    
}

template <typename type>
void BTree<type>::construirPostIn(list<type> &postorden, list<type> &inorden){

    postorden.reverse();
    this->weight = postorden.size();
    this->root = construirPostIn(postorden,inorden,1,postorden.size());

}


template <typename type>
TNode<type>* BTree<type>::construirPostIn(list<type> &postorden, list<type> &inorden, int inicio, int fin){

    int K;
    type root_aux;
    TNode<type> *R = 0;

    if(inicio <= fin && !postorden.empty()){
        root_aux = postorden.front();
        postorden.pop_front();
        K = consult(inorden,root_aux);
        R = new TNode<type>(root_aux);
        R->setRight(construirPostIn(postorden,inorden,K+1,fin));
        R->setLeft(construirPostIn(postorden,inorden,inicio,K-1));
    }
    return R;
}

template <typename type>
int BTree<type>::consult(list<type> &list, type element){


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
int BTree<type>::max(int a, int b){return (a>b)? a : b;}

#endif