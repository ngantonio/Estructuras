#include "ArbolB.h"
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

template <typename type> void viewList(const list<type> &);
void binario();

int main(){

	binario();

	return 0;
}


void binario() {

	
	ArbolB<int> A(1);

	cout << "¿Es Nulo?: " << boolalpha << A.isNull() << endl;

	A.setSonLeft(1,5);
	cout << "¿Es Hoja?: " << boolalpha << A.isLeave() << endl;
	cout << "Altura de A: " << A.getWeight() << endl;

	/*AB.setSonLeft(20,10);
	AB.setSonRight(20,90);
	AB.setSonLeft(10,30);
	AB.setSonRight(10,45);
	AB.setSonLeft(90,12);
	AB.setSonRight(90,15);

	ArbolB<int> AB1(20);

	AB1.setSonLeft(20,10);
	AB1.setSonRight(20,90);
	AB1.setSonLeft(10,30);
	AB1.setSonRight(10,45);
	AB1.setSonLeft(90,12);
	AB1.setSonRight(90,15);



	cout << endl <<"EL arbol AB creado es: "<< endl;

	cout << "Preorden"<< endl;
	list<int> Preorden = AB.preorden();
	viewList(Preorden);

	cout << "inorden"<< endl;
	list<int> inorden = AB.inorden();
	viewList(inorden);

	cout << "Postorden"<< endl;
	list<int> postorden = AB.postorden();
	viewList(postorden);

	cout << "Su espejo es: " << endl;

	ArbolB<int> espejo(AB.mirror());

	list<int> E = espejo.preorden();
	viewList(E);

	cout << "¿Es Hoja?: " << boolalpha << AB.isLeave() << endl;
	cout << "¿Es Zurdo?: " << boolalpha << AB.isZurdo() << endl;
	cout << "¿Es completo?: " << boolalpha << AB.isComplete() << endl;
	cout << endl << endl << endl;

	ArbolB<int> A1(4), A2(2),A3(4);

	A1.setSonLeft(4,2);
	A1.setSonRight(4,6);
	A1.setSonLeft(2,1);
	A1.setSonRight(2,3);
	A1.setSonLeft(6,5);
	A1.setSonRight(6,7);

	A2.setSonLeft(2,1);
	A2.setSonRight(2,3);

	A3.setSonLeft(4,40);
	A3.setSonRight(4,6);
	A3.setSonLeft(40,1);
	A3.setSonRight(40,3);
	A3.setSonLeft(6,5);
	A3.setSonRight(6,7);

	cout << boolalpha << A1.isSub(A2)<< endl;



	if(A1<AB)
		cout << true << endl;
	else
		cout << false << endl;

	if(AB == AB1)
		cout << true << endl;
	else
		cout << false << endl;


	
	cout << AB.getAltura() << endl;
	viewList(AB.niveles(2,3));


*/

}

template <typename type>
void viewList(const list<type> &lista){

	if(!lista.empty())
	{
		cout << endl;
		ostream_iterator<type> output(cout," -> ");
		copy(lista.begin(), lista.end(), output);
		cout<< endl <<endl;

	}
}
