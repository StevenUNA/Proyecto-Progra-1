#include "Nodo_Departamento.h"

Nodo_Departamento::Nodo_Departamento(Departamento* dato) {
    this->dato = dato;
    siguiente = nullptr;
}

Nodo_Departamento::~Nodo_Departamento() {
    delete dato;
}

Departamento* Nodo_Departamento::getDato() {
    return dato;
}

Nodo_Departamento* Nodo_Departamento::getSiguiente() {
    return siguiente;
}

void Nodo_Departamento::setSiguiente(Nodo_Departamento* siguiente) {
    this->siguiente = siguiente;
}
