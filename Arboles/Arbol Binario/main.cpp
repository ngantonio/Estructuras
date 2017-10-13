                /***** TEST PARA ARBOL BINARIO. © GABRIEL A.OLIVEIRA N. */
#include "BTree.hpp"
#include <iostream>
#include <iterator>
#include <string>
#include <list>
using namespace std;

template <typename type> void viewList(const list<type> &);
template <typename type> void properties(BTree<type> &A);

void binaryTest();
void build_A1(BTree<int> &);
void build_A2(BTree<int> &);
void build_list_tree();

int main(){

    binaryTest();

    return 0;
}

template <typename type>
void properties(BTree<type> &A){

    cout << "*******************************************************************"<< endl;
    cout << "...Propiedades Basicas de un Arbol Binario..." << endl << endl;
    cout << "\t-¿es Nulo?: " << boolalpha << A.isNull() << endl;
    cout << "\t-Altura: " << A.getHeight() << endl;
    cout << "\t-Peso: " << A.getWeight() << endl;
    cout << "\t-Diametro: " << A.Diameter() << endl;
    cout << "\t-¿es Hoja?: " << boolalpha << A.isLeave() << endl;
    cout << "\t-¿es Zurdo?: " << boolalpha << A.isLeftHanded() << endl;
    cout << "\t-¿es completo?: " << boolalpha << A.isComplete() << endl;
    cout << "\t-Arbol espejo en preorden: \t";
    viewList((A.mirror()).preorden());

    cout << endl << "\t******** RECORRIDOS ********" << endl << endl;
    cout << "\t::En Preorden:: \t";
    viewList(A.preorden());

    cout << "\t::En Inorden:: \t";
    viewList(A.inorden());

    cout << "\t::En Postorden:: \t";
    viewList(A.postorden());

    cout << "\t::Recorrido en Niveles:: \t";
    viewList(A.levels());
     cout << "*******************************************************************"<< endl;

}


void binaryTest(){

    BTree<int> A1,A2,A1Sub;

    cout << endl << "\t...:::Construyendo A1::..."<< endl;
    cout << "\tAntes de construir, ¿A1 Es Nulo?: " << boolalpha << A1.isNull() << endl << endl;
    build_A1(A1);

    //Muestra las propiedades que tiene A1
    properties(A1);

    //Creamos un subarbol de A1

    A1Sub.setRoot(90);
    A1Sub.setSonLeft(90,12);
    A1Sub.setSonRight(90,15);

    cout << endl << "+ ¿es ""A1Sub"" un subarbol de A1? : " << boolalpha << A1.isSub(A1Sub) << endl;

    //Creamos una copia de A1
    BTree<int> A1Equal(A1);

    cout << "+ ¿es ""A1Equal"" igual a  A1? : " << (A1==A1Equal) << endl;
    cout << "+ ¿es ""A1Sub"" igual a  A1? : " << (A1==A1Sub)<< endl;

    
    cout << "+ ¿Cuales son los elementos del nivel 3 de A1? : ";
    list<int> level3 = A1.levels(3);
    viewList(level3);



    cout << "\t...:::Construyendo A2:::..."<< endl << endl << endl;
    build_A2(A2);
    properties(A2);

    cout << endl<<"\t ...Bien! ahora hagamos operaciones interesantes con ambos Arboles: " << endl<< endl;

    cout << "+ ¿es ""A1"" igual a  A2?: " << (A2 == A2) << endl;
    cout << "+ ¿es ""A1"" un subarbol de A2?: " << A2.isSub(A1)<< endl;

    cout << endl<< "- Construyamos ahora un Arbol B, cuyo hijo izquierdo sea A1 y cuyo hijo derecho sea A2 y su raiz sea 70. " << endl;


    cout << endl <<"\t...:::Construyendo B :::..."<< endl << endl << endl;
    BTree<int> B(70,A1,A2);
    properties(B);

    //Busquemos un elemento que exista.. que tal el 47?
    cout << endl <<"+ ¿El elemento 47 se encuentra dentro de B? : " << B.search(47) << endl;

    //Busquemos ahora un elemento que no exista 
    cout << "+ ¿El elemento 500 se encuentra dentro de B? : " << B.search(500) << endl;

    cout << "+ Obtengamos Ahora a todos los elementos de B que esten entre el nivel 3 y el nivel 4 de B:  "; 
    viewList(B.levels(3,4));

    //build_list_tree();

cout << endl << endl;
}


void build_list_tree(){

    cout << endl<< endl<<"___________________________________________________________________________________________"<< endl << endl;
    cout << "Construyamos ahora un arbol dadas dos listas de sus recorridos en Preorden e Inorden "<< endl << endl;
    
    list<int> P, I;
        P.push_back(4);
        P.push_back(3);
        P.push_back(2);
        P.push_back(1);
        P.push_back(4);

        I.push_back(4);
        I.push_back(1);
        I.push_back(2);
        I.push_back(3);
        I.push_back(4);

        /*recorrido preorden = 4 3 2 1 4, recorrido inorden= 4 1 2 3 4*/

    string PRE("PREORDEN"),IN("INORDEN");
    BTree<int> C(PRE,P,IN,I);
    properties(C);



}


void build_A1(BTree<int> &A1){

    A1.setRoot(20);

    /*
                20
    */

    A1.setSonLeft(20,10);

    /*
                20

            10
    */

    A1.setSonRight(20,90);

    /*
                20

            10      90
    */

    A1.setSonLeft(10,30);

    /*
                20

            10      90

        30
    */

    A1.setSonRight(10,45);

    /*
                20

            10          90

        30      45
    */


    A1.setSonLeft(90,12);

    /*
                    20

            10              90

        30      45      12
    */


    A1.setSonRight(90,15);

    /*
                    20

            10              90

        30      45      12      15

    */



}

void build_A2(BTree<int> &A2){


    A2.setRoot(40);

    /*
            40
    */

    A2.setSonLeft(40,30);
    A2.setSonRight(40,45);

    /*
                         .40.
                       .      . 
                     .           .    
                   .               .
                 30                 45

    */

    A2.setSonLeft(30,25);
    A2.setSonRight(30,35);

      /*
                         .40.
                       .      . 
                     .           .    
                   .               .
                .30.                45
              .      .
          25.          .35

    */


    A2.setSonLeft(45,43);
    A2.setSonRight(45,50);


     
    /*
                         .40.
                       .      . 
                     .           .    
                   .               .
                .30.              .45.
              .      .           .     .
          25.          .35    43.        .50

    */


    A2.setSonLeft(25,15);
    A2.setSonRight(25,17);

   
    /*
                         .40.
                       .      . 
                     .           .    
                   .                .
                .30.              .45.
              .      .           .     .
         .25.          .35    43.        .50
        .    .
      .       .
     15        17

    */



    A2.setSonLeft(35,32);

      
        /*
                         .40.
                       .      . 
                     .           .    
                   .                .
                .30.              .45.
              .      .           .     .
         .25.          .35    43.        .50
        .    .        .
      .        .     .
     15        17  32


    */


    A2.setSonLeft(50,47);
    A2.setSonRight(50,100);


        /*
                         .40.
                       .      . 
                     .           .    
                   .                .
                .30.              .45.
              .      .           .     .
         .25.          .35    43.        .50.
        .    .        .                 .     .
      .        .     .                 .       .
     15        17  32                47        100


    */


    A2.setSonLeft(15,10);

    /*
                         .40.
                       .      . 
                     .           .    
                   .                .
                .30.              .45.
              .      .           .     .
         .25.          .35    43.        .50.
        .    .        .                 .    .
      .        .     .                 .      .
    .15        17  32                47        100
  .
10

 */



}



template <typename type>
void viewList(const list<type> &lista){

    if(!lista.empty())
    {
        ostream_iterator<type> output(cout," ");
        copy(lista.begin(), lista.end(), output);
        cout<< endl <<endl;

    }
}
