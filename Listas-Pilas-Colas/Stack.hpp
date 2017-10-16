                        /****ESTRUCTURA DINAMICA PILA. © GABRIEL A. OLIVEIRA N.*****/

#ifndef STACK_H_
#define STACK_H_
#include "Node.hpp"
#include "List.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

template <class type>
class Stack: public List<type>{

    template <typename T> 
    friend ostream& operator<<(ostream&, const Stack<T> &);

public:
    Stack();                    /*Constructor*/
    
    int getLength();            /*Retorna la longitud de la Pila*/
    int occurrences(type dato);  /*Devuelve la cantidad de veces que aparece un elemento*/
    void push(type);            /*Apilar*/
    bool empty();               /*Esta la pila vacia?*/
    type pop();                 /*Desapilar*/
    type top();                 /*Devuelve el tope de la Pila*/
};

template <typename type>
Stack<type>::Stack():List<type>::List(){}

template <typename type>
int Stack<type>::getLength(){return List<type>::getLength();}

template <typename type>
void Stack<type>::push(type info){List<type>::insert(info,1);}

template <typename type>
type Stack<type>::pop(){return List<type>::removeForPosition(1);}

template <typename type>
type Stack<type>::top(){return List<type>::search(1);}

template <typename type>
bool Stack<type>::empty(){return List<type>::empty();}

template <class type>
ostream& operator<<(ostream &output, const Stack<type> &Right){
    Node<type> *aux;
    aux =  Right.first;

    while(aux != NULL){
        cout << "| "<<  aux->getData() << setw(3)<< "|"<< endl;
        aux = aux->getNext();
    }
    if(aux == NULL)
        cout << " NULL"<< endl << endl;

    return output;
}


template <typename type>
int Stack<type>::occurrences(type dato){

    int cont = 0;

    if(!this->empty() && List<type>::consult(dato)){
        Node<type> *aux;
        aux = List<type>::first;

        while( aux != NULL)
        {
            if(dato == aux->getData())
                cont++;
            aux= aux->getNext();
        }
    }
    return cont;
}

#endif