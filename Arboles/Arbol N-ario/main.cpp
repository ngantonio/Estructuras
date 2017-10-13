                   /***** TEST PARA ARBOL N-ARIO. © GABRIEL A.OLIVEIRA N. */

#include "NTree.hpp"
#include <list>
#include <iostream>
#include <iterator>
using namespace std;

template <typename type> void viewList(const list<type> &);
template <typename type> void properties(NTree<type> &);
void buildTree(NTree<int> &);
void N_test();


int main(){ N_test(); return 0; }


void N_test(){

    NTree<int> T,Tsub(14),T2;
    buildTree(T);
    properties(T);

    /*Construyamos un sub arbol*/

    list<int> L1,L2,L3;
    L1.push_back(15);
    L1.push_back(16);
    L1.push_back(17);

    Tsub.insert(14,L1);
    
    cout << endl << "+ ¿es ""Tsub"" un subarbol de T? : " << boolalpha << T.isSub(Tsub) << endl;
    cout << "+ Los hijos del elemento 3: "; 
    viewList(T.getSons(3));
    cout << "+ ¿Que tal un camino desde la raiz hasta el elemento 17?: ";
    viewList(T.road(17));
    cout << "+ Hagamos una copia de T mediante el operador de asignacion llamada T2:"<< endl;
    T2 = T;
  
  
    cout <<endl<<"+ Construyamos dos nuevos Arboles y asignemoslos como hijos del elemento 12: "<< endl << endl;

    //Arbol 1*, raiz 20

    L2.push_back(21);
    L2.push_back(22);
    L2.push_back(23);

    NTree<int> T3(20,L2);
    T.insert(12,T3);

    //Arbol 2, raiz 24

    L3.push_back(25);
    L3.push_back(26);
    L3.push_back(27);

    NTree<int> T4(24,L3);
    T.insert(12,T4);

    cout << "\t Podemos verificar que se han insertado correctamente haciendole un recorrido en Preorden a T: "<< endl;
    cout << "\t";
    viewList(T.preorden());


/*
    Quedará de la siguiente forma:

                    .  1  .
                  .    .  .   .
               .      .     .    .
            .        .        .     .
           2     .  3 .  .     4      5
               .   .   .   .    
             .    .     .    .
           .     .       .     .
         6      7        8     9
                       . . .
                     .   .   .
                   .     .     .
                12      13      14
                . .             ...
               .   .           . . .
              .     .         .  .  .
            20       24     15  16  17
            ...      ...
           . . .    . . . 
          .  .  .  .  .  .
         21  22 23 25 26 27

*/

    cout <<"+ Eliminemos ahora toda la descendencia del elemento 8, hagamos un preorden para comprobar: "<< endl << endl;
    T.remove(8);
    viewList(T.preorden());

}


template <typename type>
void properties(NTree<type> &A){

    cout << "*******************************************************************"<< endl;
    cout << "...Propiedades Basicas de un Arbol N-ario.." << endl << endl;
    cout << "\t-¿es Nulo?: " << boolalpha << A.isNull() << endl;
    cout << "\t-Altura: " << A.getHeight() << endl;
    cout << "\t-Peso: " << A.getWeight() << endl;
    cout << "\t-¿es Hoja?: " << boolalpha << A.isLeave() << endl;
    cout << "\t- Los elementos frontera del arbol:\t";
    viewList(A.border());

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


void buildTree(NTree<int> &tree){


/*
    Representacion en Memoria para la estructura arbol N-ario:

          raiz
            |
            hijo->hermano->hermano->hermano
                     |
                    hijo->hermano->hermano
                                    |
                                    hijo  hermano



    La representacion tradicional seria de esta forma: 


                     .  1  .
                  .    .  .   .
               .      .     .    .
            .        .        .     .
           2     .  3 .  .     4      5
               .   .   .   .    
             .    .     .    .
           .     .       .     .
         6      7        8     9
                       . . .
                     .   .   .
                   .     .     .
                12      13      14
                                ...
                               . . .
                              .  .  .
                            15  16  17


    veamos como se insertan estos elementos a continuación:
*/



    tree.setRoot(1); /*construye un arbol con raiz 1*/
    
    list<int> level2,level3,level4;
    
    /*costruye una lista de hijos para el segundo nivel del arbol*/
    for(int i = 2; i<=5; i++)
        level2.insert(level2.end(),i);     

    /*costruye una lista de hijos para el tercer nivel del arbol*/
    for(int i = 6; i<=9; i++)      
        level3.insert(level3.end(),i);

    /*costruye una lista de hijos para el cuarto nivel del arbol*/
    for(int i = 12; i<=14; i++)         
        level4.insert(level4.end(),i);




    /************INSERCIONES***********/

    /*inserta el segundo nivel, como hijo del elemento 3*/
    tree.insert(1,level2);

    /*  1            

        |
        2 3 4 5 

    */  


    /*inserta el tercer nivel, como hijo del elemento 3*/
    tree.insert(3,level3);

    /*  
        1
        |
        2  3  4  5  
           |
           6  7  8  9
    */

    /*inserta el cuarto nivel como hijo del elemento 8*/

    tree.insert(8,level4);              
    /*
            
        1
        |
        2  3  4  5
           |
           6  7  8  9
                 |
                 12 13 14 
  
                        
    */ 


    //Insercion Individual dado un padre
    
    tree.insert(14,15);
    tree.insert(14,16);
    tree.insert(14,17);


    /*
            
        1
        |
        2  3  4  5
           |
           6  7  8  9
                 |
                 12 13 14 
                        |
                        15  16  17
  
                        
    */ 

}

template <typename type>
void viewList(const list<type> &list){

    if(!list.empty()){
        ostream_iterator<type> output(cout," ");
        copy(list.begin(), list.end(), output);
        cout<< endl <<endl;
    }
}