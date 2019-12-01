#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"
#include <iostream>
using namespace std;

class Arbol {
public:
	Arbol(void);
	~Arbol();
	Nodo * raiz;
	Nodo *insertar(Nodo*, short);
	void preOrden(Nodo *);
	void inOrden(Nodo *);
	void postOrden(Nodo *);
	void mostrarArbol(Nodo *, int);
	bool buscarNodo(Nodo *, short);
	Nodo * eliminarNodo(Nodo *, short);
	Nodo * eliminarArbol(Nodo *);
	bool validarArbol(Nodo *);
private:
	Nodo * aux, * temp;
};

Arbol::Arbol(){
	raiz = aux = temp = NULL;
}

Arbol::~Arbol(){
	
}
bool Arbol::validarArbol(Nodo * pRaiz){
	if(pRaiz == NULL){
		return true;
	}else{
		return false;
	}
}

Nodo * Arbol::insertar(Nodo * pRaiz, short pDato){
	if(pRaiz == NULL){
		aux = new Nodo(pDato); 
		pRaiz = aux;
	}else{
		if(pDato < pRaiz->getDato()){
			pRaiz->izq = insertar(pRaiz->izq, pDato);
		
		}else if(pDato > pRaiz->getDato()){
			pRaiz->der = insertar(pRaiz ->der, pDato);
			
		}else{
			cout<<"El nodo ya se encuentra en el arbol"<<endl;
		}
	}
	aux = NULL;
	return pRaiz;
}

void Arbol::preOrden(Nodo * pRaiz){
	if(pRaiz != NULL){
		cout<<pRaiz->getDato()<< " - ";
		preOrden(pRaiz ->izq);
		preOrden(pRaiz ->der);
	}else{
		return;
	}
}

void Arbol::inOrden(Nodo * pRaiz){
	if(pRaiz != NULL){
		inOrden(pRaiz ->izq);
		cout<<pRaiz->getDato()<<" - ";
		inOrden(pRaiz ->der);
	}else{
		return;
	}
}

void Arbol::postOrden(Nodo * pRaiz){
	if(pRaiz != NULL){
		postOrden(pRaiz->izq);
		postOrden(pRaiz->der);
		cout<<pRaiz->getDato()<<" - ";
	}
}

void Arbol::mostrarArbol(Nodo * pRaiz, int cont){
	if(pRaiz != NULL){
		mostrarArbol(pRaiz->der,cont+1);
		
		for(int i=0; i <cont; i++){
			cout<<"    ";
		}
		cout<<pRaiz->getDato()<<"\n";
		mostrarArbol(pRaiz -> izq, cont+1);
	}
}

bool Arbol::buscarNodo(Nodo * pRaiz, short pDato){
	if(pRaiz == NULL){
		return false;
	
	}else if(pRaiz->getDato() == pDato){
		return true;
	
	}else if(pDato < pRaiz->getDato()){
		return buscarNodo(pRaiz->izq, pDato);
	}else{
		return buscarNodo(pRaiz->der, pDato);
	}
}

Nodo * Arbol::eliminarNodo(Nodo * pRaiz, short pDato){
	if(pRaiz != NULL){
		if(pDato < pRaiz->getDato()){ 
			pRaiz->izq = eliminarNodo(pRaiz -> izq,pDato); 
		}
		else if(pDato > pRaiz->getDato()){ 
			pRaiz->der = eliminarNodo(pRaiz->der,pDato); 
			
		}
		else if((pRaiz -> izq == NULL) && (pRaiz -> der == NULL)){
			delete pRaiz;
			return NULL;
			
		}
		else if((pRaiz -> izq != NULL) && (pRaiz -> der == NULL)){
			aux = pRaiz -> izq;
			delete pRaiz;
			return aux;
			
		}
		else if((pRaiz -> izq == NULL) && (pRaiz -> der != NULL)){
			aux = pRaiz -> der;
			delete pRaiz;
			return aux;
			
		}else{
			aux = pRaiz -> izq;
			if(aux -> der != NULL){
				while(aux->der != NULL){
					temp = aux;
					aux = aux -> der;
				}
				temp -> der = aux -> izq;
			}else {
				pRaiz -> izq = aux -> izq;
			}
			pRaiz -> setDato(aux -> getDato());
		}
		delete aux;
		aux = NULL;
		temp = NULL;
	}
	return pRaiz;
}

Nodo * Arbol::eliminarArbol(Nodo * pRaiz){
	if(pRaiz != NULL){
		eliminarArbol(pRaiz->izq);
		eliminarArbol(pRaiz->der);
		delete pRaiz;
		pRaiz = NULL;
	}
	return pRaiz;
}

#endif

