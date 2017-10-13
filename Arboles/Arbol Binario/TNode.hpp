                    /****CLASE AUTO-REFERENCIADA TNODE PARA ARBOL BINARIO. © GABRIEL A. OLIVEIRA N.*****/
#ifndef TNODE_H_
#define TNODE_H_
#include <iostream>
using namespace std;

template <class type>
class TNode{

public:

    TNode();                                    /*Construye un Nodo con los campos de datos, hijoIzquierdo e hijoDerecho nulos*/
    TNode(type);                                /*Construye un Nodo con el campo de datos proporcionado y el ptr izquierdo y derecho nulos*/
    TNode(type,TNode<type>*, TNode<type> *);    /*Construye un Nodo con el campo de datos, el apuntador izquierdo y el apuntador derecho proporcionados*/
    void setData(type);                         /*Establece el campo de datos*/
    void setLeft(TNode<type> *);                /*Establece un apuntador a su hijo izquierdo)*/
    void setRight(TNode *);                     /*Establece un apuntador a su hijo derecho*/
    type getData();                             /*Obtiene el campo de datos*/

    TNode<type>* getLeft();                     /*Obtiene el apuntador izquierdo*/
    TNode<type>* getRight();                    /*Obtiene el apuntador derecho*/
private:

    type data;                                  /*elemento*/
    TNode<type> *left, *right;                  /*apuntador a TNode izquierdo y derecho*/
};


template <typename type>
TNode<type>::TNode(){
    setData(0);
    left = NULL;
    right = NULL;
}

template <typename type>
TNode<type>::TNode(type info){
    setData(info);
    left = NULL;
    right = NULL;
}

template <typename type>
TNode<type>::TNode(type info, TNode<type> *hijoIzq, TNode<type> *hnoDer){
    setData(info);
    setLeft(hijoIzq);
    setRight(hnoDer);
}


template <typename type>
void TNode<type>::setData(type info){
    data = info;
}

template <typename type>
void TNode<type>::setLeft(TNode<type> *hijoIzq){
    left = hijoIzq;
}

template <typename type>
void TNode<type>::setRight(TNode<type> *hnoDer){
    right = hnoDer;
}

template <typename type>
type TNode<type>::getData(){
    return data;
}

template <typename type>
TNode<type>* TNode<type>::getLeft(){
    return left;
}

template <typename type>
TNode<type>* TNode<type>::getRight(){
    return right;
}

#endif