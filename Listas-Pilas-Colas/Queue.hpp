                        /****ESTRUCTURA DINAMICA COLA. © GABRIEL A. OLIVEIRA N.*****/

#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
#include "Node.hpp"
#include "List.hpp"
#include <iomanip>
using namespace std;

template <class type>
class Queue: public List<type>{

    template <typename T> 
    friend ostream& operator<<(ostream&, const Queue<T> &); 

public:

    Queue();                        /*Constructor*/
    Queue(const Queue<type> &);     /*Costructor Copia*/

    int getLength();                /*devuelve la longitud de la cola*/
    bool empty();                   /*Esta vacia la cola?*/
    type front();                   /*Devuelve el frente de la cola*/
    type dequeue();                 /*Desencolar un elemento*/
    void enqueue(type);             /*Encolar un elemento*/
};

template <typename type>
Queue<type>::Queue():List<type>::List() { }

template <typename type>
Queue<type>::Queue(const Queue<type> &right) :List<type>::List(right) { }

template <typename type>
int Queue<type>::getLength(){return List<type>::getLength();}

template <typename type>
bool Queue<type>::empty(){return List<type>::empty(); }

template <typename type>
void Queue<type>::enqueue(type element){List<type>::push_back(element); }

template <typename type>
type Queue<type>::dequeue(){return List<type>::removeForPosition(1);}

template <typename type>
type Queue<type>::front(){return List<type>::search(1);}

template <class type>
ostream& operator<<(ostream &output, const Queue<type> &Right){

    Node<type> *aux;
    aux = Right.first;

    cout << endl;
    while(aux != NULL){
        cout << " | " << aux->getData();
        aux = aux->getNext();
    }
    if(aux == NULL)
        cout << " | NULL"<< endl << endl;
    return output;
}
#endif