                    /****ESTRUCTURA DINAMICA LISTA DOBLEMENTE ENLAZADA. © GABRIEL A. OLIVEIRA N.*****/

#ifndef LIST_H_
#define LIST_H_

#include "Node.hpp"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

template <class type>
class List{
    

    template <typename T> 
    friend ostream& operator<<(ostream&, const List<T> &);     /*Sobrecarga del operador estandar de salida*/

public:
    
    List();                                   /*Construye una lista vacia*/
    List(const List<type> &);                 /*Construye una copia de una lista*/
    List(int,int);                            /*Construye una lista de N elementos aleatorios, con una semilla M*/ 
    ~List();                                  /*Destruye los nodos de una lista*/

    bool empty();                             /*¿Es Vacia?*/
    bool consult(type);                       /*consulta un elemento, devuelve true si lo encuentra*/
    bool isOrdenate();                        /*¿La lista esta Ordenada?*/

    bool operator==(const List<type> &);      /*Sobrecarga del operador de igualdad*/
    bool operator!=(const List<type> &);      /*Sobrecarga del operador de desigualdad*/
    bool operator<(const List<type> &);       /*Indica si una lista es menor que otra*/
    bool operator>(const List<type> &);       /*Indica si una lista es mayor que otra*/
    bool removeForElement(type);              /*Elimina un elemento*/

    int getLength();                          /*devuelve la longitud de la lista*/

    void insert(type, int);                   /*Inserta un elemento dada su pocision*/ 
    void push_back(type);                     /*Inserta un elemento al final de la lista*/
    void reverse();                           /*Invierte la lista*/
    void swap(List<type> &);                  /*Intercambia dos listas*/ 
    void operator+=(const List<type> &);      /*Concatena una lista enviada a la lista actual*/ 

    type search(int);                         /*Busca un elemento en la posicion dada (si es valida) y lo retorna*/
    type operator[](int);                     /*Consulta una posicion dada y retorna el elemento, sobrecarga*/ 
    type removeForPosition(int);              /*Elimina un elemento de la lista dada su posicion*/

    List<type> zipped();                        /*Retorna la lista de forma comprimida (sin elementos repetidos)*/
    List<type> sub(type,type);                  /*Retorna una sub lista desde el Elemento A hasta el elemento B*/
    List<type> &operator=(const List<type> &);  /*Sobrecarga del operador de asignacion*/
    
protected:

    Node<type> *first;                      /*Apuntador al primer nodo de la lista, (protegido para efectos de herencia)*/

private:

    bool whoFirst(type,type);

    Node<type> *latest;
    int length;

};


template <typename type>
List<type>::List(){
    first = NULL;
    latest = NULL;
    length = 0;
}

template <typename type>
List<type>::List(const List<type> &L1):length(L1.length){
    
    Node<type> *aux, *New;
    aux = L1.first;
    int i = 1;

    while(i<= length){
        New = new Node<type>(aux->getData());

        if(i == 1){
            first = New;
            latest = New;
        }else{
            latest->setNext(New);
            latest = New;
        }
        aux = aux->getNext();
        i++;
    }    
}

template <typename type>
List<type>::List(int N, int M){

    srand(time(NULL));
    this->first = NULL;
    this->latest = NULL;
    int i = 1;

    while(i<= N){
        push_back(1+(rand()%M));
        i++;
    }

}

template <typename type>
List<type>::~List(){

    Node<type> *exist, *aux;

    if(!empty())
    {
        exist = first;
        while(exist != NULL){
            aux = exist;
            exist = exist->getNext();
            aux->setPrev(NULL);
            aux->setNext(NULL);
            delete aux; 
        }
        this->length = 0;
    }
}

template <typename type>
int List<type>::getLength(){return length;}

template <typename type>
bool List<type>::empty(){ return (first == NULL && latest == NULL && length == 0);}


template <typename type>
void List<type>::insert(type info, int pos){

    Node <type> *New, *prev, *next;

    if(pos > 0 && pos <= length+1){

        New = new Node<type>(info);
        if(pos == 1){
            New->setNext(this->first);
            this->first = New;
        }else{
            prev = this->first;
            next = prev->getNext();

            for(int i = 2; i<= pos-1; i++){
                prev = next;
                next = next->getNext();
            }
            prev->setNext(New);
            New->setNext(next);
            if(next != NULL)
                next->setPrev(New);
            New->setPrev(prev);
        
            
        }

        if(pos == length+1)
            this->latest = New;
    length++;
    }
}

template <typename type>
void List<type>::push_back(type e){

    Node<type> *aux, *New;
    New = new Node<type>(e);

    if(this->first == NULL && this->latest == NULL)        
        this->first = New;   
    else{
        aux = this->latest;      /*Asigno a aux el ultimo elemento de la lista*/
        aux->setNext(New);       /*Hago que el campo siguiente del ultimo elemento de la lista, apunte ahora al nuevo*/
        New->setPrev(aux);       /*Hago que el campo anterior del nuevo elemento apunte a aux*/ 
    }
    this->latest = New;
    this->length++;
}

template <typename type>
type List<type>::removeForPosition(int pos){ /*O(log(n))*/

    Node <type> *actual, *aux;
    int medium = this->length/2;
    type element;

    if(!empty() && pos <= length){

        if(pos == 1){
            actual = this->first;
            first = first->getNext();
            if(first == NULL)
                latest = NULL;
        }else{

            if(pos == length){
                actual = this->latest;
                this->latest = this->latest->getPrev();
                this->latest->setNext(NULL);
            }else if(pos <= medium){
                actual = this->first->getNext();  //coloco un ptr en el segundo nodo
                for(int i = 2; i < pos; i++)
                    actual = actual->getNext();
            }else{
                actual = this->latest->getPrev();   //coloco un ptr el el penultimo nodo
                for(int i = this->length-1; i > pos; i--)
                    actual = actual->getPrev();
            }
            aux = actual->getPrev();
            aux->setNext(actual->getNext());
            actual->getNext()->setPrev(aux);
        }
    element = actual->getData();
    delete actual;
    this->length--;
    }
    return element;     
}

template <typename type>
bool List<type>::removeForElement(type e){

    Node<type> *actual,*aux;
    bool flag = true,find = false;

    if(consult(e)){
        find = true;
        if(this->first->getData() == e){
            actual = this->first;
            this->first = actual->getNext();
            this->first->setPrev(NULL);
        }else if(this->latest->getData() == e){
            actual = this->latest;
            this->latest = actual->getPrev();
            this->latest->setNext(NULL);
        }else{
            actual = this->first->getNext();
            while(flag && actual != NULL){
                if(actual->getData() == e)
                    flag = false;
                else
                    actual = actual->getNext();
            }

            aux = actual->getPrev();
            aux->setNext(actual->getNext());
            actual->getNext()->setPrev(aux);
        }
    delete actual;
    this->length--;
    }
    return find;

}

template <typename type>
type List<type>::search(int pos){ //O(log(n))

    Node<type> *ptr;
    type res;
    int medium = this->length/2;

    if(!empty() && pos <= length){

        if(pos == 1)
            res = first->getData();
        else if(pos == length)
            res = latest->getData();
        else if(pos <= medium){
            ptr = first->getNext();
            for(int i = 2; i<pos; i++)
                ptr = ptr->getNext();
            res = ptr->getData();
        }else{
            ptr = latest->getPrev();
            for(int i = this->length-1; i>pos; i--)
                ptr = ptr->getPrev();
            res = ptr->getData();
        }
        
    }         
    return res;
}

template <typename type>
void List<type>::reverse(){

    Node<type> *previus, *actual, *prox;
    

    /*Parte 1: inicializando los apuntadores*/
    previus = this->first;              /*previus apunta al primer elemento de la lista*/
    actual = previus->getNext();        /*actual apunta al segundo elemento de la lista*/
    prox = this->latest;                /*prox apunta al ultimo elemento de la lista*/

    /*

        | previus |-> | actual | -> | elemento3 | -> | prox |-> NULL
    */

    /*parte 2: orientando los extremos*/

    this->first = prox;             /*oriento al apuntador al primer elemento de la lista hacia donde apunta prox*/
    //this->first->getPrev(NULL);
    this->latest = previus;         /*oriento al apuntador al ultimo elemento de la lista hacia donde apunta previus*/
    this->latest->setNext(NULL);    /*le asigno nulo a su campo next, porque ese nodo sera el ultimo*/
    this->latest->setPrev(actual);  /*asigno el segundo nodo de la lista(actual) al campo anterior*/
    prox = actual->getNext();       /*oriento a prox al tercer elemento de la lista*/

    /*ya intercambie los extremos y tengo a actual apuntando
    al segundo elemento y a prox al tercer elemento, puedo
    comenzar a intercambiar ahora el resto de apuntadores.
    Parte 3:  */

    while(actual != NULL){
        actual->setPrev(actual->getNext()); /*el ptr anterior del nodo actual, apunta al ptr siguiente del nodo actual*/
        actual->setNext(previus);           /*el ptr siguiente del nodo actual, apunta al ptr anterior del nodo actual*/
        previus= actual;                    /*avanza hacia adelante ambos apuntadores*/
        actual = prox;

        if(actual != NULL)
            prox = prox->getNext();
        else
            previus = NULL;

    }

}

template <typename type>
List<type> List<type>::sub(type a ,type b){

    List<type> sublist;
    Node<type> *auxA, *auxB, *New;
    type c;
    bool Afound, Bfound;

    Afound = consult(a);
    Bfound = consult(b);

    if(Afound && Bfound){
       
        if(!whoFirst(a,b)){  
            c = a; 
            a = b;
            b = c;
        }
    
        auxA = first;
        while(auxA->getData() != a)
            auxA=auxA->getNext();

        auxB = auxA;                    /*coloca el apuntador de b incialmente a donde encontro a A*/
        while(auxB->getData() != b) {

            New = new Node<type>(auxB->getData());

            if(sublist.first == NULL && sublist.latest == NULL){
                sublist.first = New;
                sublist.latest = New;
            }else{
                sublist.latest->setNext(New);
                New->setPrev(sublist.latest);
                sublist.latest = New;
            }
            sublist.length++;
             auxB =auxB->getNext();
         }
        sublist.push_back(auxB->getData());
        
    }else{

        if(Afound)
            sublist.push_back(a);
        if(Bfound)
            sublist.push_back(b);
    }
    return sublist;
}

template <typename type>
bool List<type>::whoFirst(type a ,type b){

    Node<type> *aux;
    int contA, contB;

    contA = 0;
    contB = 0;

        aux = first;
        while(aux->getData() != a){
            aux = aux->getNext();
              contA++;
        }

        aux = first;
        while(aux->getData() != b){
            aux= aux->getNext();
            contB++;
        }

        if(contA < contB)
            return true;        //A esta primero;
        else
            return false;       //B esta primero
}

template <typename type>
List<type>& List<type>::operator=(const List<type> &right){

    Node<type> *aux, *New;

    if(&right!= this){

        this->length = right.length;
        aux = right.first;
    
        int i = 1;
        while(i<= length)
        { 
            New = new Node<type>(aux->getData());
            if(i == 1){
                this->first = New;
                this->latest = New;
            }
            else{
                this->latest->setNext(New);
                New->setPrev(this->latest);
                this->latest = New;
            }
            aux = aux->getNext();
            i++;       
        }
    }
    return *this;
}

template <typename type>
bool List<type>::operator==(const List<type> &right){

    Node<type> *actual1, *actual2;
    bool flag = true;

    if(&right!= this && this->length != right.length)
        flag = false;
    else{
        actual1 = this->first;
        actual2 = right.first;

        while(flag && actual1 != NULL){
            if(actual1->getData() != actual2->getData())
                flag = false;

            actual1 = actual1->getNext();
            actual2 = actual2->getNext();
        }
    }
    return flag;
}

template <typename type>
bool List<type>::operator!=(const List<type> &right){

    if(&right!= this && this->length > 0)
        return !(*this == right);
}

template <typename type>
type List<type>::operator[](int subindice){

    Node<type> *exist;
    type res;

    if(subindice < 0 || subindice > this->length || !empty()){
        cout << "\t\n Error: subindice "<< subindice <<" fuera de rango"<< endl;
        res = 0;
    }
    else{
        if(subindice == 1)
            res = first->getData();
        else{

            if(subindice == length)
                res = latest->getData();
            else{
                exist = first->getNext();
                for(int i = 2; i<= subindice-1; i++)
                    exist = exist->getNext();
                res = exist->getData();
            }
        }
    }

    return res;
}

template <typename type>
bool List<type>::operator>(const List<type> &right){

    Node<type> *ptrThis, *ptrRight;
    bool flag = false;
    type higherLeft = -10000, higherRight = -10000;

    if(&right!= this && this->length > 0 && &right.length > 0){

        ptrThis = first;
        ptrRight = right.first;

        /*Busca el mayor elemento de la lista instancia*/

        while(ptrThis != NULL){
            if(ptrThis->getData() > higherLeft)
                higherLeft = ptrThis->getData();   
            ptrThis = ptrThis->getNext();
        }

        /*busca el mayor elemento de la lista derecha*/

        while(ptrRight != NULL){
            if(ptrRight->getData() > higherRight)
                higherRight = ptrRight->getData(); 
            ptrRight = ptrRight->getNext();
        }

        /*si el mayor elemento de la instancia, es mayor, 
        al mayor elemento de la lista derecha, retorna true*/
        if(higherLeft > higherRight)
            flag = true;
    }
   
    return flag;
}


template <typename type>
bool List<type>::operator<(const List<type> &right){

    if(&right!= this && this->length > 0)
        return (!this > right);
    else
        return false;
}

template <typename type>
void List<type>::operator+=(const List<type> &right){

    Node<type> *ptrThis, *ptrRight,*New;

    if(&right != this && right.first != NULL && right.latest != NULL ){

        ptrThis = this->latest;
        ptrRight = right.first;
        length = length + right.length;

        while(ptrRight != NULL){
            New = new Node<type>(ptrRight->getData());
            ptrThis->setNext(New);
            New->setPrev(ptrThis);
            ptrThis = New;
            ptrRight = ptrRight->getNext();
        }
        latest = New;
    }
}

template <typename type>
void List<type>::swap(List<type> &derecha){

     /*
        aux = instancia
        instancia = derecha
        derecha = aux
    */

    List<type> aux(*this);                  /*crea una copia de la instancia en aux*/
    Node<type> *ptr;
    
    while(first != NULL){                   /*Borra todos los nodos de la instancia*/ 
        ptr = first;
        first = ptr->getNext();
        delete ptr;     
    }

    this->latest = this->first;            /*iguala ambos apuntadores de la instancia a nulo*/

    *this = derecha;                       /*instancia <- derecha*/

    while(derecha.first != NULL){          /*borra todos los nodos de derecha*/
        ptr = derecha.first;
        derecha.first = ptr->getNext();
        delete ptr;     
    }
    derecha.latest = derecha.first;        /*iguala ambos apuntadores de la lista derecha a nulo*/

    derecha = aux;                         /*derecha <- aux*/

}

template <typename type>
bool List<type>::consult(type info){

    Node <type> *exist;
    bool find = false;
    if(!empty()){
        if(first->getData() == info || latest->getData() == info)
            find = true;
        else{
            exist = first->getNext();
            while(!find && exist != NULL){
                if(exist->getData() == info)
                    find = true;
                exist = exist->getNext();
            }
        }
    }
    return find;

}

template <typename type>
List<type> List<type>::zipped(){

    Node<type> *ptrAct;
    List<type> zip;
    type previus = -1;

    if(!this->empty()){

        ptrAct = this->first;
        while(ptrAct != NULL){
            if(previus != ptrAct->getData()){           /*si el elemento anterior coincide con*/
                if(!zip.consult(ptrAct->getData()))
                    zip.push_back(ptrAct->getData());
                previus = ptrAct->getData();
            }   
            ptrAct = ptrAct->getNext();
        }
    }
    return zip;
}

template <typename type>
bool List<type>::isOrdenate(){

    Node<type> *aux,*sig;
    bool flag = true;

    aux = first;
    sig = aux->getNext();

    while(flag && aux != NULL && sig != NULL){
        if(aux->getData() > sig->getData())
            flag = false;

        aux = aux->getNext();
        sig = sig->getNext();

    }
    return flag;
}

template <class type>
ostream& operator<<(ostream &output, const List<type> &Right){

    Node <type> *aux;
    aux = Right.first;

    while(aux != NULL){
        output << aux->getData() << " > ";
        aux = aux->getNext();

    }
    if(aux == NULL)
        output << "NULL" <<endl<< endl;

    return output;

}

#endif