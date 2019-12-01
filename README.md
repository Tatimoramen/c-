

#ifndef NODO_H
#define NODO_H

class Nodo {
public:
	Nodo();
	Nodo(short);
	~Nodo();
	short getDato();
	void setDato(short);
	Nodo * izq, * der;
private:
	short dato;
};
Nodo::Nodo(){
	dato = 0;
	izq = der = NULL;
}
Nodo::Nodo(short pDato){
	dato = pDato;
	izq = der = NULL;
}
Nodo::~Nodo(){
	
}
short Nodo::getDato(){
	return dato;
}
void Nodo::setDato(short pDato){
	dato = pDato;
}
#endif

