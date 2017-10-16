                   /****CLASE AUTO-REFERENCIADA NODE PARA LISTAS PILAS Y COLAS. © GABRIEL A. OLIVEIRA N.*****/
#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
using namespace std;

template <class type>
class Node{

public:
    Node<type>(type);
    Node<type>(type,Node<type>*, Node<type>*);
    ~Node<type>();

    void setData();
    void setNext(Node<type>*);
    void setData(type);
    void setPrev(Node<type>*);

    type getData();

    Node<type>* getNext();
    Node<type>* getPrev();

private:
    type data;
    Node<type> *prev,*next;

};


template <typename type>
Node<type>::Node(type info){setData(info); next = NULL; prev = NULL;}

template <typename type>
Node<type>::Node(type info,Node<type> *prev, Node<type> *next){ setData(info); setPrev(prev); setNext(next);}

template <typename type>
Node<type>::~Node(){prev = NULL; next = NULL; data = -1;}

template <typename type>
void Node<type>::setData(type info){data = info;}

template <typename type>
void Node< type >::setPrev(Node<type> *p){prev = p;} 

template <typename type>
void Node< type >::setNext(Node<type> *n){next = n;} 

template <typename type>
type Node<type>::getData(){return data;}

template <typename type>
Node<type>* Node<type>::getPrev(){return prev;}

template <typename type>
Node<type>* Node<type>::getNext(){return next;}

#endif