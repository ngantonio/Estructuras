                    /****CLASE AUTO-REFERENCIADA TNODE PARA ARBOL N-ARIO. © GABRIEL A. OLIVEIRA N.*****/
#ifndef TNODE_H_
#define TNODE_H_
#include <iostream>
using namespace std;

template <class type>
class TNode{

public:

    TNode();                                    /*Construye un Nodo con los campos de datos, hijoIzquierdo e HermanoDerecho nulos*/
    TNode(type);                                /*Construye un Nodo con el campo de datos proporcionado y el ptr izquierdo y derecho nulos*/
    TNode(type,TNode<type>*, TNode<type> *);    /*Construye un Nodo con el campo de datos, el apuntador izquierdo y el apuntador derecho proporcionados*/
    void setData(type);                         /*Establece el campo de datos*/
    void setSonLeft(TNode<type> *);             /*Establece un apuntador a su primer hijo (hijo izquierdo)*/
    void setBroRight(TNode *);                  /*Establece un apuntador a su hermano derecho*/
    type getData();                             /*Obtiene el campo de datos*/

    TNode<type>* getSonLeft();                  /*Obtiene el apuntador izquierdo*/
    TNode<type>* getBroRight();                 /*Obtiene el apuntador derecho*/
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
    setSonLeft(hijoIzq);
    setBroRight(hnoDer);
}


template <typename type>
void TNode<type>::setData(type info){
    data = info;
}

template <typename type>
void TNode<type>::setSonLeft(TNode<type> *hijoIzq){
    left = hijoIzq;
}

template <typename type>
void TNode<type>::setBroRight(TNode<type> *hnoDer){
    right = hnoDer;
}

template <typename type>
type TNode<type>::getData(){
    return data;
}

template <typename type>
TNode<type>* TNode<type>::getSonLeft(){
    return left;
}

template <typename type>
TNode<type>* TNode<type>::getBroRight(){
    return right;
}

#endif