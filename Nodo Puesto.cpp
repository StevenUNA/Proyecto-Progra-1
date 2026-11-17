#include "Nodo Puesto.h"

Nodo_Puesto::Nodo_Puesto(Puesto* dato) {
	this->dato = dato;
	siguiente = nullptr;
}

Nodo_Puesto::~Nodo_Puesto() {
	delete dato;
}

Puesto* Nodo_Puesto::getDato() {
	return dato;
}

Nodo_Puesto* Nodo_Puesto::getSiguiente() {
	return siguiente;
}

void Nodo_Puesto::setSiguiente(Nodo_Puesto* siguiente) {
	this->siguiente = siguiente;
}
