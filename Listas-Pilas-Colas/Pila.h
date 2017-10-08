#ifndef PILA_H_
#define PILA_H_

#include "Nodo.h"
#include "Lista.h"
#include <iostream>
#include <iomanip>
using namespace std;

template <class type>
class Stack: public List<type>{

	template <typename T> 
	friend ostream& operator<<(ostream&, const Stack<T> &);

public:
	Stack();
	void push(type);
	void pop();
	bool empty();
	type top();
	int ocurrencias(int dato);

};

template <typename type>
Stack<type>::Stack()
	:List<type>::List()
{

}


template <typename type>
void Stack<type>::push(type info){
	List<type>::insert(info,1);
}

template <typename type>
void Stack<type>::pop(){
	List<type>::remove(1);
}

template <typename type>
type Stack<type>::top(){
	return List<type>::consult(1);
}

template <typename type>
bool Stack<type>::empty(){
	return List<type>::empty();
}

template <class type>
ostream& operator<<(ostream &output, const Stack<type> &Right){

	Nodo<type> *aux;
	aux =  Right.first;

	while(aux != NULL)
	{
		cout << "| "<<  aux->getDatos() << setw(3)<< "|"<< endl;
		aux = aux->getSiguiente();
	}
	if(aux == NULL)
		cout << "NULL" << endl << endl;

	return output;
}


template <typename type>
int Stack<type>::ocurrencias(int dato){

	int cont = 0;

	if(!this->empty())
	{
		Nodo<type> *aux;
		aux = List<type>::first;

		while( aux != NULL)
		{
			if(dato == aux->getDatos())
				cont++;
			aux= aux->getSiguiente();
		}
	}
	return cont;
}

#endif