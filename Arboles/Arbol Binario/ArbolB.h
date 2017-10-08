                        /****ESTRUCTURA DINAMICA ARBOL BINARIO. © GABRIEL A. OLIVEIRA N.*****/

#ifndef ARBOLB_H_
#define ARBOLB_H_
#include "NodoArbol.h"
#include <list>
#include <iterator>
#include <string>
#include <cstdio>
using namespace std;

template <class type>
class ArbolB{

public:

	ArbolB();                                           /*Crea un arbol binario Nulo*/
	ArbolB(type);                                       /*Crea un arbol binario con su raiz */
	ArbolB(const ArbolB &);                             /*Copia un arbol dado en otro*/
	ArbolB(type,const ArbolB &, const ArbolB &);        /*Crea un arbol binario con su raiz, su hijo izquierdo y su hijo derecho*/
	ArbolB(string &, list<type> &, string &, list<type> &); /*Construye un arbol dados sus recoridos*/
	~ArbolB();                                              /*Destruye un arbol binario*/
	
	bool isNull();                                          /*¿Es nulo?*/
	bool isLeave();                                         /*¿Es hoja?*/
	bool isLeftHanded();                                         /*¿Es zurdo?*/
	bool isComplete();                                      /*¿Es Completo?*/
	bool isSub(const ArbolB<type> &);                       /*Indica si un arbol B, es sub-arbol, de un arbol A*/
	bool search(type);                                      /*Devuelve true, si un elemento esta dentro de un arbol*/
	bool operator==(ArbolB<type> &);                        /*¿El arbol A es igual al arbol B?*/
	
	type getRoot();                                     /*Devuelve la raiz del arbol*/
	
	int getWeight();                                      /*Devuelve el peso del arbol*/
	int getHeight();                                    /*Devuelve la altura del arbol*/
	int Diameter();
	
	ArbolB<type> mirror();                              /*Devuelve un arbol espejo del original*/
	ArbolB<type> getSonLeft();                          /*Devuelve el hijo izquierdo de un arbol*/
	ArbolB<type> getSonRight();                         /*Devuelve el hijo derecho de un arbol*/
	list<ArbolB<type> > getHijos();                     /*Devuelve una lista con ambos hijos*/
	
	void setSonLeft(type,type);                         /*dado un padre, asigna un elemento como hijo izquierdo */
	void setSonRight(type,type);                        /*dado un padre, asigna un elemento como hijo derecho*/
	void remove(type);                                  /*dado un padre, elimina al padre y a su descendencia (si la tiene)*/
	void construirPreIn(list<type> &, list<type> &);    /*Construye un arbol dados sus recorridos en preorden e inorden*/
	void construirPostIn(list<type> &, list<type> &);   /*Construye un arbol dados sus recorridos en postorden e inorden*/
	

	/***TOURS****/

	list<type> preorden();
	list<type> postorden();
	list<type> inorden();
	list<type> niveles();                               /*Devuelve una lista ordenada con los niveles del arbol*/
	list<type> niveles(int, int = 0);                   /*Dado un nivel devuelve una lista con los elementos de ese nivel*/
	                                                    /*Dados 2 niveles, devuelve una lista con los elementos desde el nivel A*/
	                                                    /*Hasta el nivel B, incluyendo a los extremos*/
protected:
	Node<type> *root;
	int weight;

private:

	Node<type> * copiarNodos(Node<type> *);
	void removeNodes(Node<type> *);
	void preorden(Node<type> *, list<type> &);
	void inorden(Node<type> *, list<type> &);
	void postorden(Node<type> *, list<type> &);
	void search(type, Node<type> *, Node<type> *&, bool *);
	void isLeftHanded(Node<type> *, int *, bool *flag);
	void isComplete(Node<type> *, bool *);
	Node<type>* mirror(Node<type> *);
	Node<type>* construirPreIn(list<type> &, list<type> &, int, int);
	Node<type>* construirPostIn(list<type> &, list<type> &, int ,int);
	int consultar(list<type> &, type);
	void isEqual(Node<type> *, Node<type> *, bool *);
	void getHeight(Node<type> *, int *, int *);
	void niveles(Node<type> *, int *, int, list<type> &);
	int Diameter(Node<type> *, int *);
	int max(int a, int b);

	

};

template <typename type>
ArbolB<type>::ArbolB(){
	root = NULL;
	weight = 0;
}

template <typename type>
ArbolB<type>::ArbolB(type info){

	Node<type> *New;

	New = new Node<type>(info);
	root = New;
	weight = 1;
}


template <typename type>
ArbolB<type>::ArbolB(type r ,const ArbolB &izquierdo, const ArbolB &derecho){

	ArbolB<type> binaryAux;
	Node<type> *New;

	New = new Node<type>(r);
	root = New;
	root->setLeft(copiarNodos(izquierdo.root));
	root->setRight(copiarNodos(derecho.root));
	weight = izquierdo.weight + derecho.weight;
}

template <typename type>
ArbolB<type>::ArbolB(const ArbolB &copia){

	root = copiarNodos(copia.root);
	weight = copia.weight;
}

template <typename type>
ArbolB<type>::ArbolB(string &nombre1, list<type> &recorrido1, string &nombre2, list<type> &recorrido2){

	string PREORDEN("PREORDEN");
	string INORDEN("INORDEN");
	string POSTORDEN("POSTORDEN");


	if(nombre1 == PREORDEN && nombre2 == INORDEN)
		construirPreIn(recorrido1,recorrido2);
	else{

		if(nombre1 == INORDEN && nombre2 == PREORDEN)
			construirPreIn(recorrido2,recorrido1);
		else{
			if(nombre1 == POSTORDEN && nombre2 == INORDEN)
				construirPostIn(recorrido1,recorrido2);
			else{
				if(nombre1 == INORDEN && nombre2 == POSTORDEN)
					construirPostIn(recorrido2,recorrido1);
				else
					cout << endl<< "No se ha encontrado una coincidencia para la entrada de datos... "<< endl;
			}
		}
	}

	
}

template <typename type>
ArbolB<type>::~ArbolB(){
	removeNodes(root);
}


template <typename type>
void ArbolB<type>::remove(type elemento){

	Node<type> *ptr;
	bool find = false;

	search(elemento,ptr,&find);
	if(find){
		removeNodes(ptr);
		ptr = NULL;
	}
	else
		cout << "El elemento " << elemento << " NO existe dentro del arbol" << endl;
}


template <typename type>
bool ArbolB<type>::isNull(){
	return root == NULL;
}

template <typename type>
bool ArbolB<type>::isLeave(){
	return (root->getLeft() == NULL && root->getRight() == NULL);
}

template <typename type>
type ArbolB<type>::getRoot(){
	return root->getDatos();
}

template <typename type>
int ArbolB<type>::getWeight(){
	return weight;
}

template <typename type>
ArbolB<type> ArbolB<type>::getSonLeft(){

	ArbolB<type> son;

	if(root != NULL)
		son.root = copiarNodos(root->getLeft());
	else
		son.root = NULL;

	return son;
}

template <typename type>
ArbolB<type> ArbolB<type>::getSonRight(){

	ArbolB<type> son;

	if(root != NULL)
		son.root = copiarNodos(root->getRight());
	else
		son.root = NULL;

	return son;
}

template <typename type>
Node<type>* ArbolB<type>::copiarNodos(Node<type> *p){

	Node<type> *New;

	if(p ==  NULL)
		return NULL;
	else
		return New = new Node<type>(p->getDatos(),copiarNodos(p->getLeft()), copiarNodos(p->getRight()));
	
}

template <typename type>
void ArbolB<type>::removeNodes(Node<type> *ptr){

	if(ptr != NULL){
		if(ptr->getLeft() != NULL)
			removeNodes(ptr->getLeft());
		if(ptr->getRight() != NULL)
			removeNodes(ptr->getRight());

		delete ptr;
		ptr = NULL;
	}
}

template <typename type>
bool ArbolB<type>::search(type elemento){

	Node<type> *new_root;
	bool flag = false;

	search(elemento,root,new_root,&flag);
	return flag;

}


template <typename type>
void ArbolB<type>::search(type elemento,Node<type> *root, Node<type> *&ptr, bool *flag){

	if(root != NULL){

		if(root->getDatos() == elemento){
			*flag = true;
			ptr = root;
		}
		else{
			if(!*flag){
				search(elemento,root->getLeft(),ptr,flag);
				if(!*flag)
					search(elemento,root->getRight(),ptr,flag);
			}
		}
	}

}

template <typename type>
void ArbolB<type>::setSonLeft(type padre, type dato){

	Node<type> *New, *aux;
	bool flag = false;

	search(padre,root,aux,&flag);
	
	if(flag && aux->getLeft() == NULL)
	{
		New = new Node<type>(dato);
		aux->setLeft(New);
	}

}

template <typename type>
void ArbolB<type>::setSonRight(type padre, type dato){

	Node<type> *New, *aux;
	bool flag = false;

	search(padre,root,aux,&flag);
	
	if(flag && aux->getRight() == NULL)
	{
		New = new Node<type>(dato);
		aux->setRight(New);
	}

}



template <typename type>
bool ArbolB<type>::isLeftHanded(){

	int totalWeight = 0;
	bool flag = false;

	isLeftHanded(root,&totalWeight,&flag);
	return flag;
}


template <typename type>
void ArbolB<type>::isLeftHanded(Node<type> *ptr, int *n, bool *flag){

	bool leftFlag,rightFlag;
	int leftWeight,rightWeight;

	if(ptr == NULL){
		*n = 0;
		*flag = true;
	}
	else{
		if(ptr->getLeft() == NULL && ptr->getRight() == NULL){	//si es hoja
			*flag = true;
			*n = 1;
		}
		else{
			leftWeight = 0;
			isLeftHanded(ptr->getLeft(),&leftWeight,&leftFlag);
			rightFlag = false;
			if(leftFlag)
				isLeftHanded(ptr->getRight(),&rightWeight,&rightFlag);

			*n = leftWeight + rightWeight+1;
			*flag = (leftFlag && rightFlag && (leftWeight > rightWeight));
			/*ambos hijos deben ser zurdos y el peso izquierdo debe ser mayor al peso derecho*/
		}
	}

}



template <typename type>
ArbolB<type> ArbolB<type>::mirror(){
	ArbolB<type> esp;

	esp.root = mirror(root);
	return esp;
}


template <typename type>
Node<type>* ArbolB<type>::mirror(Node<type> *ptr){

	Node<type> *New;

	if(ptr == NULL)
		return NULL;
	else
		New = new Node<type>(ptr->getDatos(), mirror(ptr->getRight()), mirror(ptr->getLeft()));
	return New;

}




template <typename type>
bool ArbolB<type>::isComplete(){

	bool flag = true;
	isComplete(root,&flag);

	return flag;
}

template <typename type>
void ArbolB<type>::isComplete(Node<type> *ptr, bool *flag){

	if(*flag == true && ptr != NULL){

		if((ptr->getLeft() == NULL && ptr->getRight() == NULL))
				
		else{
			if(ptr->getLeft() == NULL || ptr->getRight() == NULL)
				*flag = false;
			else{
				isComplete(ptr->getLeft(),flag);
				isComplete(ptr->getRight(),flag);	
			}
		}
	}
}


template <typename type>
bool ArbolB<type>::operator==(ArbolB<type> &sub){

	if(this != &sub && this->weight == sub.weight)
		return isEqual(this->root,sub.root);
	else
		return false;	
}


template <typename type>
bool ArbolB<type>::isSub(const ArbolB<type> &sub){

	bool flag = true;
	bool flagFind = false;
	Node<type> *rootEncontrada;

	/*busca la primera aparicion de la raiz del subarbol
	dentro del arbol actual y la envia a isEqual como la
	raiz actual del arbol. isEqual comprueba que sean isomorfos 
	y tengan los mismos datos*/

	search(sub.root->getDatos(),this->root,raizEncontrada,&flagFind);
	

	if(flagFind)
		isEqual(raizEncontrada,sub.root);
	else
		flag = false;

	return flag;

}

template <typename type>
void ArbolB<type>::isEqual(Node<type> *ptrAct, Node<type> *ptrSub, bool *flag){

	/*determina si un arbol es igual a otro, en elementos (Semejante) y en estructura (isomorfo)*/

	if(ptrAct != NULL && ptrSub != NULL)
	{

		if(ptrAct->getDatos() == ptrSub->getDatos())
		{
			if((ptrAct->getLeft() == NULL && ptrSub->getLeft() == NULL) || (ptrAct->getLeft() != NULL && ptrSub->getLeft() != NULL))
			{	// es subArbol si ambos hijos son nulos o si ambos hijos son distintos de nulo
				isEqual(ptrAct->getLeft(), ptrSub->getLeft(), flag);
			}
			else
				*flag = false;

			if(*flag && (ptrAct->getRight() == NULL && ptrSub->getRight() == NULL) || (ptrAct->getRight() != NULL && ptrSub->getRight() != NULL))
			{	// si aun es subArbol luego de recorrer a los hijos, sigue siendo subArbol si ambos hermanos son nulos o si ambos hermanos son distintos de nulo
				isEqual(ptrAct->getRight(), ptrSub->getRight(), flag);
			}

		}
		else
			*flag = false;

	}
}


template <typename type>
int ArbolB<type>::Diameter(){

	int nivel = 0;

	if(root != NULL){
		return Diameter(root,&nivel);
	}else{
		return -1;
	}
}


template <typename type>
int ArbolB<type>::Diameter(Node<type> *ptr, int *level){

	int lh,rh,alturaIzq, alturaDer, diameterSubTree, subtreeMax;

	lh = 0;
	rh = 0;

	if(ptr == NULL){
		*level = 0;
		return 0;
	}else{


		alturaIzq = Diameter(ptr->getSonLeft(),&lh);
		alturaDer = Diameter(ptr->getRight(),&rh);
		diameterSubTree = lh + rh;				/*calcula el diametro del hijo*/		
		*level = max(lh, rh)+1;					/*va sumando 1 */

		subtreeMax = max(alturaIzq, alturaDer); /*calcula el nivel maximo entre ambos hijos*/
		return max(diameterSubTree,subtreeMax);
	}

}

template <typename type>
int ArbolB<type>::getHeight(){

	int acumulado, total;

	acumulado = 1;
	total = 0;

	if(root != NULL)
		getHeight(root,&acumulado,&total);
	else
		total = -1;

	return total;
}

template <typename type>
void ArbolB<type>::getHeight(Node<type> *p, int *acumulado, int *total){

	if(p != NULL){
		if(p->getLeft() == NULL && p->getRight() == NULL){
			if(*acumulado > *total)
				*total = *acumulado;
		}
		else{
			*acumulado = *acumulado+1;
			getHeight(p->getLeft(),acumulado,total);			
			getHeight(p->getRight(),acumulado,total);
			*acumulado = *acumulado-1;

		}
	}
	
}

template <typename type>
list<ArbolB<type> >ArbolB<type>::getHijos(){

	list<ArbolB<type> > H;
	ArbolB<type> L,R;

	if(root != NULL){
		ArbolB<type> L( this->getSonLeft());
		ArbolB<type> R(this->getSonRight());
		H.insert(H.end(),L);
		H.insert(H.end(),R);
	}	

	return H;	
}


template <typename type>
list<type> ArbolB<type>::niveles(int nivelA, int nivelB){

	int acumulado,altura;
	list<type> N;
	bool band;

	acumulado = 1;
	altura = this->getHeight();

	if(nivelA > 0 && nivelA <= altura && nivelB <= altura)
		band = true;
	else
		band = false;

	if(root != NULL && band){
		if(nivelB == 0)
			niveles(root,&acumulado,nivelA,N);
		else{

			if(nivelA <= nivelB){
				int i = nivelA;

				while(i <= nivelB){
					niveles(root,&acumulado,i,N);
					i++;
				}
			}
		}

	}
	return N;
}

template <typename type>
void ArbolB<type>::niveles(Node<type> *p, int *acumulado, int nivelA, list<type> &N){

	if(p != NULL){

		if(*acumulado == nivelA)
			N.push_back(p->getDatos());
		
		*acumulado = *acumulado+1;
		niveles(p->getLeft(),acumulado,nivelA,N);			
		niveles(p->getRight(),acumulado,nivelA,N);
		*acumulado = *acumulado-1;
		
	}
	
}


/********RECORRIDOS PUBLICOS**********/

template <typename type>
list<type> ArbolB<type>::preorden(){

	list<type> pre;
	if(root != NULL)
		preorden(root,pre);
	return pre;
}

template <typename type>
list<type> ArbolB<type>::inorden(){

	list<type> in;
	if(root != NULL)
		inorden(root,in);
	return in;

}

template <typename type>
list<type> ArbolB<type>::postorden(){

	list<type> post;
	if(root != NULL)
		postorden(root,post);
	return post;
}


template <typename type>
list<type> ArbolB<type>::niveles(){

	list<type> L;
	list<Node<type>* > C;

	if(root)
		C.insert(C.begin(),root);

	while(!C.empty()){

		L.insert(L.end(),C.front()->getDatos());

		if(C.front()->getLeft() != NULL)
			C.insert(C.end(),C.front()->getLeft());

		if(C.front()->getRight() != NULL)
			C.insert(C.end(),C.front()->getRight());
		
		C.pop_front();
	}

	return L;
}




/******** RECORRIDOS PRIVADOS**********/	

template <typename type>
void ArbolB<type>::preorden(Node<type> *ptr, list<type> &pre){

	Node<type> *aux;

	if(ptr != NULL){
		pre.insert(pre.end(),ptr->getDatos());
		preorden(ptr->getLeft(),pre);
		preorden(ptr->getRight(),pre);
	}
}

template <typename type>
void ArbolB<type>::postorden(Node<type> *ptr, list<type> &post){

	Node<type> *aux;

	if(ptr != NULL){
		postorden(ptr->getLeft(),post);
		postorden(ptr->getRight(),post);
		post.insert(post.end(),ptr->getDatos());
	}
}

template <typename type>
void ArbolB<type>::inorden(Node<type> *ptr, list<type> &in){

	Node<type> *aux;

	if(ptr != NULL){
		inorden(ptr->getLeft(),in);
		in.insert(in.end(), ptr->getDatos());
		inorden(ptr->getRight(),in);
		
	}
}

/***************CONSTRUCCION DE ARBOLES MEDIANTE LISTAS DE SUS RECORRIDOS ************************/

template <typename type>
void ArbolB<type>::construirPreIn(list<type> &preorden, list<type> &inorden){

	this->weight = preorden.size();
	this->root = construirPreIn(preorden,inorden,1,preorden.size());
}

template <typename type>
Node<type>* ArbolB<type>::construirPreIn(list<type> &preorden, list<type> &inorden, int inicio, int fin){

	int K;
	type root_aux;


	if(inicio <= fin && !preorden.empty())
	{
		root_aux = preorden.front();
		preorden.pop_front();
		K = consultar(inorden,root_aux);
		return new Node<type>(root_aux,
/*izq*/		construirPreIn(preorden,inorden,inicio,K-1),
/*der*/		construirPreIn(preorden,inorden,K+1,fin));
	}
	
}

template <typename type>
void ArbolB<type>::construirPostIn(list<type> &postorden, list<type> &inorden){

	postorden.reverse();	// invierte la lista
	this->weight = postorden.size();
	this->root = construirPostIn(postorden,inorden,1,postorden.size());

}


template <typename type>
Node<type>* ArbolB<type>::construirPostIn(list<type> &postorden, list<type> &inorden, int inicio, int fin){

	int K;
	type root_aux;
	Node<type> *R = 0;

	if(inicio <= fin && !postorden.empty())
	{
		root_aux = postorden.front();
		postorden.pop_front();
		K = consultar(inorden,root_aux);
		R = new Node<type>(root_aux);
		R->setRight(construirPostIn(postorden,inorden,K+1,fin));
		R->setLeft(construirPostIn(postorden,inorden,inicio,K-1));
	}
	return R;
}

template <typename type>
int ArbolB<type>::consultar(list<type> &lista, type elemento){


	typename list<type>::const_iterator i;
	int posicion;
	bool flag;

	i = lista.begin();
	posicion = 0;
	flag = false;

	while(i != lista.end() && !flag)
	{
		if(*i == elemento)
			flag = true;

		i++;
		posicion++;
	}
	return posicion;
}

template <typename type>
int ArbolB<type>::max(int a, int b){

	if(a>b)
		return a;
	else
		return b;
}



#endif