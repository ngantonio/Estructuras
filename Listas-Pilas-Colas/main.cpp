                     /***** TEST LISTAS PILAS Y COLAS. © GABRIEL A.OLIVEIRA N. */
#include "List.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

void test_stack();
void test_list();
void test_queue();

int main(){


    test_list();
    //test_stack();
    //test_queue();
return 0;
}

void test_list(){

    cout << endl << endl << "*************************************************************************************"<< endl;
    cout << endl <<"+ Construyamos una lista de elementos aleatorios con 10 elementos y una semilla de 15 llamada Lrand: "<< endl;
    List<int> Lrand(10,15);
        cout << Lrand;

    cout << endl <<"+ Construyamos una lista de elementos repetidos con 10 elementos llamada Lrep: " << endl;
    List<int> Lrep;

    Lrep.push_back(1);
    Lrep.push_back(18);
    Lrep.push_back(3);
    Lrep.push_back(3);
    Lrep.push_back(5);
    Lrep.push_back(20);
    Lrep.push_back(18);
    Lrep.push_back(15);
    Lrep.push_back(1);
    Lrep.push_back(12);
    Lrep.push_back(20);
    Lrep.push_back(3);
        cout << Lrep;

    cout << endl<< "+ Construyamos una lista de los numeros pares del 1 al 30 llamada Lpair: " << endl;
    List<int> Lpair;
    int pos = 1;
    for(int i = 1; i<=30; i++){
        if(i%2 == 0){
            Lpair.insert(i,pos);
            pos++;
        }
    }
        cout << Lpair;

   cout << endl<< "- Invirtamos a Lrep: " << endl;
   Lrep.reverse();
   cout << Lrep;

   cout << endl<< "- Comprimamos a Lrep: " << endl;
   List<int> LrepZipped;
   LrepZipped = Lrep.zipped();
   cout << LrepZipped;

    cout << endl<< "- Lrep y LrepZipped son iguales?: " << boolalpha << (LrepZipped == Lrep) << endl;

    cout << endl<< "- Lrep y Lrep son iguales?: "<< boolalpha<< (Lrep == Lrep) << endl;

    cout << endl<< " -Obtengamos una Sub lista de Lpair, desde el numero 8 hasta el numero 24: " << endl;
    cout << Lpair.sub(8,24);

    cout << endl<< " -Obtengamos una Sub lista de Lpair, desde el numero 24 hasta el numero 8: " << endl;
    cout << Lpair.sub(24,8);

    cout << endl<< "- Lpair esta ordenada?: " <<boolalpha << Lpair.isOrdenate() << endl << endl;
    

    cout << endl<< "- El elemento 20 se encuentra dentro de Lpair?: " << boolalpha << Lpair.consult(20) << endl;

    cout << endl<< "- Cual es el elemento dentro dela posicion 11 de Lpair?: "<< Lpair.search(11) << endl;

    cout << endl<< "- El elemento 50 se encuentra dentro de Lpair?: " << Lpair.consult(50) << endl;
    
    cout << endl<< "- Intercambiemos a Lrand con Lpair: " << endl;
    Lrand.swap(Lpair);
    cout << "\t Lrand ahora es: " << Lrand <<"\t Lpair ahora es: " << Lpair << endl;

    cout << "- Eliminemos el elemento 24 de Lrand: " << endl;
    Lrand.removeForElement(24);
    cout << "\t Lrand: "  << Lrand; 

    cout << "- Eliminemos al elemento que esta en la posicion 7 de Lrand. el elemento eliminado fue: " << Lrand.removeForPosition(7)<< endl;
    cout << "\t Lrand: "  << Lrand; 

    cout << "-Lrand es mayor a Lpair?: " << boolalpha << (Lrand > Lpair)<< endl << endl;

    cout << "- Concatenemos a Lrand con Lpair: " << endl;
    Lrand+=Lpair;
    cout << "\t Lrand: "  << Lrand; 
    cout << endl << endl << "*************************************************************************************"<< endl << endl << endl;

}



void test_stack(){

    Stack<int> P;

    int total,ele;

    cout << endl << endl << "*************************************************************************************"<< endl;
    
    P.push(6);
    P.push(5);
    P.push(4);
    P.push(4);
    P.push(4);
    P.push(4);
    P.push(3);
    P.push(2);
    P.push(1);
    cout << P<< endl;

    cout << endl <<"- P esta Vacia?: "<< boolalpha << P.empty()<< endl;
    cout << "- El tope de la Pila es: " << P.top()<< endl;
    cout << "- Cuantas veces aparece el elemento 4?: " << P.occurrences(4) << endl;
    cout << "- Desapilando hasta vaciar: " << endl;

    while(!P.empty()){
        cout << endl << "*************************************"<< endl;
        int e = P.pop();
        cout << "\tSe desapilo el elemento: " << e << endl;
        cout << P ;
    }
    cout << endl <<"- P esta Vacia?: "<< boolalpha << P.empty()<< endl;
    cout << endl << "*************************************************************************************"<< endl << endl <<endl;



}


void test_queue(){

    Queue<int> Q;

    cout << endl << endl << "*************************************************************************************"<< endl;
    
    Q.enqueue(10);
    Q.enqueue(9);
    Q.enqueue(8);
    Q.enqueue(7);
    Q.enqueue(6);
    Q.enqueue(5);
    Q.enqueue(4);
    Q.enqueue(3);
    Q.enqueue(2);
    Q.enqueue(1);

    cout << Q<< endl;

    cout << endl <<"- Q esta Vacia?: "<< boolalpha << Q.empty()<< endl;
    cout << "- El frente de la cola es es: " << Q.front()<< endl;
    cout << "- Desencolando hasta vaciar: " << endl;

    while(!Q.empty()){
        cout << endl << "*************************************"<< endl;
        int e = Q.dequeue();
        cout << "\tSe desencoló el elemento: " << e << endl;
        cout << Q ;
    }
    cout << endl <<"- Q esta Vacia?: "<< boolalpha << Q.empty()<< endl;
    cout << endl << "*************************************************************************************"<< endl << endl <<endl;

}