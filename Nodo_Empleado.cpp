#include "Nodo_Empleado.h"

Nodo_Empleado::Nodo_Empleado (Empleado * dato) {
	this->setDato(dato);
	this->sig=NULL;
}

Nodo_Empleado::~Nodo_Empleado ( ) {
}


void Nodo_Empleado::setDato (Empleado * dato) {
	this->dato=dato;
}

Empleado * Nodo_Empleado::getDato ( ) {
	return this->dato;
}

void Nodo_Empleado::setSig (Nodo_Empleado * Sig) {
	this->sig=Sig;
}

Nodo_Empleado * Nodo_Empleado::getSig ( ) {
	return this->sig;
}

