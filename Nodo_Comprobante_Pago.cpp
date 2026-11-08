#include "Nodo_Comprobante_Pago.h"

Nodo_Comprobante_Pago::Nodo_Comprobante_Pago() {
	this->dato = nullptr;
	this->sig = nullptr;
}

Nodo_Comprobante_Pago::Nodo_Comprobante_Pago(Comprobante_Pago *dato) {
	this->dato = dato;
	this->sig = nullptr;
}

Nodo_Comprobante_Pago::~Nodo_Comprobante_Pago() {
	cout << "Borrando nodo comprobante de pago\n";
}

void Nodo_Comprobante_Pago::setDato(Comprobante_Pago *dato) {
	this->dato = dato;
}

void Nodo_Comprobante_Pago::setSig(Nodo_Comprobante_Pago *sig) {
	this->sig = sig;
}

Comprobante_Pago* Nodo_Comprobante_Pago::getDato() {
	return dato;
}

Nodo_Comprobante_Pago* Nodo_Comprobante_Pago::getSig() {
	return sig;
}

