#include "Lista_Departamento.h"
#include <iostream>
#include <fstream>

using namespace std;

Lista_Departamento::Lista_Departamento() {
    primero = nullptr;
}

Lista_Departamento::~Lista_Departamento() {
    Nodo_Departamento* actual = primero;

    while (actual != nullptr) {
        Nodo_Departamento* temporal = actual;
        actual = actual->getSiguiente();
        delete temporal;
    }
}

bool Lista_Departamento::estaVacia() {
    return primero == nullptr;
}

void Lista_Departamento::insertar(Departamento* departamento) {
    Nodo_Departamento* nuevo = new Nodo_Departamento(departamento);

    if (estaVacia()) {
        primero = nuevo;
    } else {
        Nodo_Departamento* actual = primero;

        while (actual->getSiguiente() != nullptr) {
            actual = actual->getSiguiente();
        }

        actual->setSiguiente(nuevo);
    }
}

Departamento* Lista_Departamento::buscar(int id) {
    Nodo_Departamento* actual = primero;

    while (actual != nullptr) {
        if (actual->getDato()->getId() == id) {
            return actual->getDato();
        }

        actual = actual->getSiguiente();
    }

    return nullptr;
}

bool Lista_Departamento::eliminar(int id) {
    if (primero == nullptr) {
        return false;
    }

    if (primero->getDato()->getId() == id) {
        Nodo_Departamento* temporal = primero;
        primero = primero->getSiguiente();
        delete temporal;
        return true;
    }

    Nodo_Departamento* actual = primero;

    while (actual->getSiguiente() != nullptr) {
        if (actual->getSiguiente()->getDato()->getId() == id) {
            Nodo_Departamento* temporal = actual->getSiguiente();
            actual->setSiguiente(temporal->getSiguiente());
            delete temporal;
            return true;
        }

        actual = actual->getSiguiente();
    }

    return false;
}

void Lista_Departamento::mostrar() {
    Nodo_Departamento* actual = primero;

    while (actual != nullptr) {
        actual->getDato()->mostrar();
        actual = actual->getSiguiente();
    }
}

void Lista_Departamento::autoGuardar() {
    ofstream archivo("departamentos.txt");

    Nodo_Departamento* actual = primero;

    while (actual != nullptr) {
        Departamento* departamento = actual->getDato();

        archivo << departamento->getId() << endl;
        archivo << departamento->getNombre() << endl;

        actual = actual->getSiguiente();
    }

    archivo.close();
}

void Lista_Departamento::autoLeer() {
    ifstream archivo("departamentos.txt");

    if (!archivo.is_open()) {
        return;
    }

    int id;
    string nombre;

    while (archivo >> id) {
        archivo.ignore();
        getline(archivo, nombre);

        Departamento* departamento = new Departamento(id, nombre);
        insertar(departamento);
    }

    archivo.close();
}
