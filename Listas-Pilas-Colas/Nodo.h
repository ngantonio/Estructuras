#ifndef _NODO_H_
#define _NODO_H_

#include <iostream>
using namespace std;

template <class type>

class Nodo{

public:
    Nodo(type);
    void setDatos();
    void setSiguiente(Nodo *);
    void setDatos(type);
    type getDatos();
    Nodo<type>* getSiguiente();

private:

    type datos;
    Nodo <type> *sig;

};



template <typename type>
Nodo<type>::Nodo(type info)
{
    setDatos(info);
    sig = NULL;
}

template <typename type>
void Nodo<type>::setDatos(type info){
    datos = info;
}

template <typename type>
void Nodo< type >::setSiguiente(Nodo *next){
    sig = next;
} 

template <typename type>
type Nodo<type>::getDatos(){
    return datos;
}

template <typename type>
Nodo<type>* Nodo<type>::getSiguiente(){
    return sig;
}



#endif


