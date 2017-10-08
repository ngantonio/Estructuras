#include "Pila.h"
#include "Cola.h"
#include "Lista.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void intercambio();
void intercambio1(List<char> *L, int medio, int  n, int i);
void pila();
void lista();
void cola();

int main(){

	srand(time(NULL));

	//pila();
	lista();
	//cola();

	List<Queue<int> > L;



	
return 0;
}

void intercambio1(List<char> *L, int medio, int n, int i){

	char aux1, aux2;

	if(i <= medio)
	{
		if(i%2 == 0 && n%2 == 0)
		{
			aux1 = L->consult(i);
			aux2 = L->consult(n);
			L->remove(n);
			L->remove(i);
			L->insert(aux2,i);
			L->insert(aux1,n);
			intercambio1(L,medio,n-1, i+1);
		}
		else
		{
			if(i%2 == 0)
				intercambio1(L,medio,n-1, i);
			else
				intercambio1(L,medio,n, i+1);
		}

	}

}

void pila(){

	Stack<int> P1;

	int total,ele;

	cout <<"P1 Esta Vacia?: " << boolalpha << P1.empty()<<endl;

	cout << "\nIngresa el numero de elementos de la Pila 1: ";
	cin>> total;

	for(int i = 1; i<= total; i++)
	{
		cout <<"Ingresa el elemento: " << i << ": ";
		cin >> ele;
		P1.push(ele);
	}
	cout<<endl << P1<< endl;
	
	cout <<"P1 Esta Vacia?: " << boolalpha << P1.empty()<<endl;

	P1.pop();
	cout << "\nSe desapilo el tope de la pila 1, el tope ahora es:  " << P1.top()<< endl;

	cout<<endl << P1<< endl;

	cout << P1.ocurrencias(7) << endl;


}

void intercambio(){

	char entrada[50];
	int n,medio,j;
	List<char> L;

	cout <<"\n Ingresa una cadena de texto: ";
	cin.getline(entrada,50);
	n = strlen(entrada);
	
	cout << "la cadena fue: " << entrada << " y su longitud es de: " << n <<endl;

	for(int i = 1; i<=n; i++)
		L.insert(entrada[i-1],i);

	j = 1;
	medio = n/2;
	intercambio1(&L,medio,n,j);
	cout << endl << endl;
	cout<< L << endl;
	cout<< endl << endl;

}


void lista(){

	//intercambio();
	List<int> L;
	List<int> L1;
	List<int> aux;

	int j =1;


	for(int i = 1; i<=15; i++){
		if(i%2 == 0)
		{
			L.insert(i-1,j);
			L1.insert(i,j);
			j++;
		}
			
	}
		
	cout<< L << endl;
	cout<< L1 << endl;

	if(L == L1)
		cout << "son iguales" << endl;
	else
		cout << "Son distintas" << endl;


	if(L != L1)
		cout << "Son distintas" << endl;
	else
		cout << "son iguales" << endl;


	if(L< L1)
		cout << "L es menor a L1" << endl;
	else
		cout << "L no es menor a L1" << endl;


	aux = L;
	cout<< aux << endl;

	cout << endl << aux[20] << endl;


	L.swap(L1);
	cout << "L despues del intercambio es: " << endl;
	cout<< L << endl;
	cout << "L1 despues del intercambio es: " << endl;
	cout<< L1<< endl;

	cout << "concatenacion: " << endl;
	L+= L1;
	cout<< L << endl;



	cout << "Sublista de L: "<<endl;
	List<int> aux1(L.sub(14,4));
	cout<< aux1 << endl << endl;

	cout << boolalpha << aux1.isOrdenate() << endl;
	

	List<int> B;

	for(int i = 1; i<= 8 ; i++){
		B.insert(1+ rand() %20,i);
	}


	cout << boolalpha << B.isOrdenate() << endl;
	B.sort();

	cout << B << endl;



}

void cola(){

	Queue<int> cola1;
	Queue<int> c;


	for(int i = 1; i<= 10; i++){
		cola1.enqueue(1+ rand() %20);
	}

	//cout << cola1<< endl;
	cola1.sort();
	//cout << cola1<< endl;




}