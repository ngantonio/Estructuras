#ifndef NODOARBOL_H_
#define NODOARBOL_H_
#include <iostream>
using namespace std;

template <class type>
class Node{

public:

	Node();
	Node(type);
	Node(type,Node<type>*, Node<type> *);
	void setDatos(type);
	void setSonLeft(Node<type> *);
	void setBroRight(Node *);
	void setLeft(Node<type> *);
	void setRight(Node<type> *);
	type getDatos();

	Node<type>* getSonLeft();
	Node<type>* getBroRight();
	Node<type>* getLeft();
	Node<type>* getRight();

private:

	type datos;
	Node<type> *left, *right;
	/*Hijo izquierdo, hermano derecho*/

};


template <typename type>
Node<type>::Node(){
	setDatos(0);
	left = NULL;
	right = NULL;
}

template <typename type>
Node<type>::Node(type info){
	setDatos(info);
	left = NULL;
	right = NULL;
}

template <typename type>
Node<type>::Node(type info, Node<type> *hijoIzq, Node<type> *hnoDer){
	setDatos(info);
	setSonLeft(hijoIzq);
	setBroRight(hnoDer);
}


template <typename type>
void Node<type>::setDatos(type info){
	datos = info;
}

template <typename type>
void Node<type>::setSonLeft(Node<type> *hijoIzq){
	left = hijoIzq;
}

template <typename type>
void Node<type>::setBroRight(Node<type> *hnoDer){
	right = hnoDer;
}

template <typename type>
void Node<type>::setLeft(Node<type> *hijoIzq){
	left = hijoIzq;
}

template <typename type>
void Node<type>::setRight(Node<type> *hnoDer){
	right = hnoDer;
}




template <typename type>
type Node<type>::getDatos(){
	return datos;
}

template <typename type>
Node<type>* Node<type>::getSonLeft(){
	return left;
}

template <typename type>
Node<type>* Node<type>::getBroRight(){
	return right;
}

template <typename type>
Node<type>* Node<type>::getLeft(){
	return left;
}

template <typename type>
Node<type>* Node<type>::getRight(){
	return right;
}


#endif
