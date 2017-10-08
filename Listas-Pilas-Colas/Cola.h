#ifndef COLA_H_
#define COLA_H_
#include <iostream>
#include "Nodo.h"
#include "Lista.h"
#include <iomanip>
using namespace std;

template <class type>
class Queue: public List<type>{

	template <typename T> 
	friend ostream& operator<<(ostream&, const Queue<T> &);	

public:

	Queue();
	Queue(const Queue<type> &);
	int getLength();		
	bool empty();
	bool find(type);		
	type front();
	void sort();
	void enqueue(type);
	void dequeue();
	void view();

	Queue<type> sub(type,type);	

};

template <typename type>
Queue<type>::Queue():List<type>::List() { }

template <typename type>
Queue<type>::Queue(const Queue<type> &right) :List<type>::List(right) { }

template <typename type>
bool Queue<type>::empty(){
	return List<type>::empty(); 
}

template <typename type>
void Queue<type>::enqueue(type element){
	List<type>::insert(element, List<type>::getLength()+1); 
}

template <typename type>
void Queue<type>::dequeue(){
	List<type>::remove(1); 
}

template <typename type>
void Queue<type>::sort(){
	List<type>::sort(); 
}

template <typename type>
type Queue<type>::front(){
	return List<type>::consult(1); 
}


template <typename type>
Queue<type> sub(type a,type b){
	return List<type>::sub(a,b);
}


template <class type>
ostream& operator<<(ostream &output, const Queue<type> &Right){

	Nodo<type> *aux;
	aux = Right.first;

	cout << endl;
	while(aux != NULL)
	{
		cout << "| " << aux->getDatos() << " | ->";
		aux = aux->getSiguiente();
	}

	if(aux == NULL)
		cout << "NULL"<< endl << endl;
	return output;

}

#endif