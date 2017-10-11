#ifndef LISTA_H_
#define LISTA_H_

#include "Nodo.h"
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

template <class type>
class List{
    

    template <typename T> 
    friend ostream& operator<<(ostream&, const List<T> &);

public:
    
    List();
    List(const List<type> &);
    ~List();

    bool empty();
    int getLength();
    void insert(type, int);
    void remove(int);
    type consult(int);  
    bool find(type);
    bool isOrdenate();  
    void invert();
    void swap(List<type> &);
    void sort();
    List<type> sub(type,type);
    List<type> &operator=(const List<type> &);  /*Asignacion*/
    bool operator==(const List<type> &);
    bool operator!=(const List<type> &);
    void operator+=(const List<type> &);
    bool operator<(const List<type> &);
    bool operator>(const List<type> &);
    type operator[](int);
    

    //void remove(type);
    
    
protected:

    Nodo<type> *first;

private:

    bool whoFirst(type,type);           /*¿Quien esta primero?*/

    Nodo<type> *latest;
    int length;

};

template <typename type>
List<type>::List(){
    first = NULL;
    latest = NULL;
    length = 0;
}

template <typename type>
List<type>::List(const List<type> &L1)
    :length(L1.length)
{
    Nodo<type> *aux, *New;
    aux = L1.first;
    
    int i = 1;
    while(i<= length)
    {
        New = new Nodo<type>(aux->getDatos());
        if(i == 1)
        {
            first = New;
            latest = New;
        }
        else
        {
            latest->setSiguiente(New);
            latest = New;
        }
        aux = aux->getSiguiente();
        i++;
    }
    
}


template <typename type>
int List<type>::getLength(){
    return length;

}

template <typename type>
bool List<type>::empty(){
    return (first == NULL && latest == NULL && length == 0);
}

template <typename type>
void List<type>::insert(type info, int pos){

    Nodo <type> *New, *prev, *next;

    if(pos > 0 && pos <= length+1)
    {
        New = new Nodo<type>(info);
        if(pos == 1)
        {
            New->setSiguiente(this->first);
            this->first = New;
        }
        else
        {
            prev = this->first;
            next = prev->getSiguiente();

            for(int i = 2; i<= pos-1; i++)
            {
                prev = next;
                next = next->getSiguiente();
            }
            prev->setSiguiente(New);
            New->setSiguiente(next);
        }

        if(pos == length+1)
            this->latest = New;
    length++;
    }
}

template <typename type>
void List<type>::remove(int pos){

    Nodo <type> *exist, *prev, *next;

    if(!empty() && pos <= length)
    {
        if(pos == 1)
        {
            exist = this->first;
            first = first->getSiguiente();
            if(first == NULL)
                latest = NULL;
        }
        else
        {
            prev = this->first;
            exist = prev->getSiguiente();
            next = exist->getSiguiente();
    
            for(int i = 2; i<= pos-1; i++)
            {
                prev = exist;
                exist = next;
                next = next->getSiguiente();
            }
            prev->setSiguiente(next);
            if(next == NULL)
                latest = NULL;
        }

        
    delete exist;
    length--;
    }
}

template <typename type>
type List<type>::consult(int pos){

    Nodo<type> *exist;
    type res;

    if(!empty() && pos <= length){

        if(pos == 1)
            res = first->getDatos();
        else{

            if(pos == length)
                res = latest->getDatos();
            else{
                exist = first->getSiguiente();
                for(int i = 2; i<=pos-1; i++)
                    exist = exist->getSiguiente();
                res = exist->getDatos();
            }
        }
    }
    return res;
}

template <typename type>
void List<type>::invert(){

    /*Nodo<type> *exist;
    type res;*/

}

template <typename type>
List<type> List<type>::sub(type a ,type b){

    List<type> sublist;
    Nodo<type> *auxA, *auxB, *New;

    if(find(a) && find(b) )
    {
        if(whoFirst(a,b) == true)
        {   

            auxA = first;
            while(auxA->getDatos() != a)
                auxA=auxA->getSiguiente();

            auxB = auxA;                    /*coloca el apuntador de b incialmente a donde encontro a A*/
            while(auxB->getDatos() != b)
            {
                New = new Nodo<type>(auxB->getDatos());

                if(sublist.first == NULL && sublist.latest == NULL)
                {
                    sublist.first = New;
                    sublist.latest = New;
                }
                else
                {
                    sublist.latest->setSiguiente(New);
                    sublist.latest = New;
                }

                sublist.length++;

                auxB =auxB->getSiguiente();
            }

            New = new Nodo<type>(auxB->getDatos());
            sublist.latest->setSiguiente(New);
            sublist.latest = New;
            sublist.length++;

        }
        else
        {
            auxB = first;
            while(auxB->getDatos() != b)
                auxB = auxB->getSiguiente();

            auxA = auxB;
            while(auxA->getDatos() != a)
            {
                New = new Nodo<type>(auxA->getDatos());

                if(sublist.first == NULL && sublist.latest == NULL)
                {
                    sublist.first = New;
                    sublist.latest = New;
                }
                else
                {
                    sublist.latest->setSiguiente(New);
                    sublist.latest = New;
                }

                auxA =auxA->getSiguiente();
                sublist.length++;
            }

            New = new Nodo<type>(auxA->getDatos());
            sublist.latest->setSiguiente(New);
            sublist.latest = New;
            sublist.length++;

        }
    }
    return sublist;
}

template <typename type>
bool List<type>::whoFirst(type a ,type b){

    Nodo<type> *aux;
    int contA, contB;

    contA = 0;
    contB = 0;

        aux = first;
        while(aux->getDatos() != a)
        {
            aux = aux->getSiguiente();
            contA++;
        }

        aux = first;
        while(aux->getDatos() != b)
        {
            aux= aux->getSiguiente();
            contB++;
        }

        if(contA < contB)
            return true;        //A esta primero;
        else
            return false;       //B esta primero
}


template <typename type>
List<type>::~List(){

    Nodo<type> *exist, *aux;

    if(!empty())
    {
        exist = first;
        while(exist != NULL){
            aux = exist;
            exist = exist->getSiguiente();
            delete aux; 
        }
    length = 0;
    }
    

}

template <typename type>
List<type>& List<type>::operator=(const List<type> &derecha){

    Nodo<type> *aux, *New;

    if(&derecha != this)
    {
        length = derecha.length;
        aux = derecha.first;
    
        int i = 1;
        while(i<= length)
        { 
            New = new Nodo<type>(aux->getDatos());
            if(i == 1)
            {
                first = New;
                latest = New;
            }
            else
            {
                latest->setSiguiente(New);
                latest = New;
            }
            aux = aux->getSiguiente();
            i++;
        }
    
    }
    return *this;
}

template <typename type>
bool List<type>::operator==(const List<type> &derecha){

    Nodo<type> *actual1, *actual2;
    bool flag = true;

    if(this->length != derecha.length)
        flag = false;
    else
    {
        actual1 = this->first;
        actual2 = derecha.first;

        while(flag && actual1 != NULL)
        {
            if(actual1->getDatos() != actual2->getDatos())
                flag = false;

            actual1 = actual1->getSiguiente();
            actual2 = actual2->getSiguiente();

        }
    }

    return flag;
}

template <typename type>
bool List<type>::operator!=(const List<type> &derecha){

    return !(*this == derecha);
}

template <typename type>
type List<type>::operator[](int subindice){

    Nodo<type> *exist;
    type res;

    if(subindice < 0 || subindice > this->length || !empty())
    {
        cout << "\t\n Error: subindice "<< subindice <<" fuera de rango"<< endl;
        res = 0;
    }
    else
    {
        if(subindice == 1)
            res = first->getDatos();
        else{

            if(subindice == length)
                res = latest->getDatos();
            else{
                exist = first->getSiguiente();
                for(int i = 2; i<= subindice-1; i++)
                    exist = exist->getSiguiente();
                res = exist->getDatos();
            }
        }
    }

    return res;

}

template <typename type>
bool List<type>::operator<(const List<type> &derecha){

    Nodo<type> *ptrThis, *ptrRight;
    bool flag = true;

    ptrThis = first;
    ptrRight = derecha.first;

    if(length != derecha.length)
        flag = false;
    else
    {
        while(flag && ptrThis != NULL)
        {
            if(ptrThis->getDatos() < ptrRight->getDatos())
            {
                ptrThis = ptrThis->getSiguiente();
                ptrRight = ptrRight->getSiguiente();
            }
            else
                flag = false;
        }
    }
    return flag;
}

template <typename type>
bool List<type>::operator>(const List<type> &derecha){

    Nodo<type> *ptrThis, *ptrRight;
    bool flag = true;

    ptrThis = first;
    ptrRight = derecha.first;

    if(length != derecha.length)
        flag = false;
    else
    {
        while(flag && ptrThis != NULL)
        {
            if(ptrThis->getDatos() > ptrRight->getDatos())
            {
                ptrThis = ptrThis->getSiguiente();
                ptrRight = ptrRight->getSiguiente();
            }
            else
                flag = false;
        }
    }
    return flag;
}


template <typename type>
void List<type>::operator+=(const List<type> &derecha){

    Nodo<type> *ptrThis, *ptrRight,*New;

    if(derecha.first != NULL && derecha.latest != NULL )
    {
        ptrThis = latest;
        ptrRight = derecha.first;
        length = length + derecha.length;

        while(ptrRight != NULL)
        {
            New = new Nodo<type>(ptrRight->getDatos());
            ptrThis->setSiguiente(New);
            ptrThis = New;
            ptrRight = ptrRight->getSiguiente();
        }
        latest = New;
    }
}

template <typename type>
void List<type>::swap(List<type> &derecha){

    List<type> aux(*this);                  /*crea una copia y aux <- instancia*/

    Nodo<type> *ptr;
    
    while(first != NULL)                    /*Borra todos los nodos de l1*/
    {
        ptr = first;
        first = ptr->getSiguiente();
        delete ptr;     
    }
    latest = first;

    *this = derecha;                        /*instancia <- derecha*/

    while(derecha.first != NULL)            /*borra todos los nodos de derecha*/
    {
        ptr = derecha.first;
        derecha.first = ptr->getSiguiente();
        delete ptr;     
    }
    derecha.latest = derecha.first;

    derecha = aux;                      /*derecha <- aux*/
}


template <typename type>
bool List<type>::find(type info){

    Nodo <type> *exist;
    bool find = false;

    if(!empty())
    {
        if(first->getDatos() == info || latest->getDatos() == info)
            find = true;
        else{
            exist = first->getSiguiente();

            while(!find && exist != NULL){
                if(exist->getDatos() == info)
                    find = true;
                exist = exist->getSiguiente();
            }
        }
    }
    return find;
}

template <typename type>
void List<type>::sort(){

    /*BubbleSort Algorithm O(n2)*/
    /*Empuja el mayor hasta el final, Ordena los apuntadores*/

    Nodo<type> *prev, *next, *aux;
    int n;
    bool flag,mayor;

    prev = first;
    next = prev->getSiguiente();
    aux = prev;
    n = getLength();
    
    flag = this->isOrdenate();      /*¿esta ordenada?*/
    
    while(n > 1 && mayor && !flag)
    {
        mayor = false;

        for(int i = 1; i<n; i++)
        {
            if(prev->getDatos() > next->getDatos())
            {
                if(prev == first)
                    first = next;
                if(next == latest)
                    latest = prev;

                aux->setSiguiente(next);
                prev->setSiguiente(next->getSiguiente());
                next->setSiguiente(prev);
                aux = next;
                next = prev->getSiguiente();
                mayor = true;               /*evita segir comparando innecesariamente*/
            }
            else
            {
                aux = prev;
                prev = next;
                next = next->getSiguiente();
            }
            //cout << endl<< *this << endl;

        }
        n = n-1;
        prev = first;
        aux = prev;
        next = prev->getSiguiente();
    }

}


template <typename type>
bool List<type>::isOrdenate(){

    Nodo<type> *aux,*sig;
    bool flag = true;

    aux = first;
    sig = aux->getSiguiente();

    while(flag && aux != NULL && sig != NULL){
        if(aux->getDatos() > sig->getDatos())
            flag = false;

        aux = aux->getSiguiente();
        sig = sig->getSiguiente();

    }
    return flag;
}

template <class type>
ostream& operator<<(ostream &output, const List<type> &Right){

    Nodo <type> *aux;
    aux = Right.first;

    cout << endl;
    while(aux != NULL){
    
        output << aux->getDatos() << " >> ";
        aux = aux->getSiguiente();

    }
    if(aux == NULL)
        output << "NULL" <<endl<< endl;

    return output;

}

#endif


