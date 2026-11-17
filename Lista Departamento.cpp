
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

    if (departamento == nullptr) {
        return;
    }

    if (buscar(departamento->getCodigo()) != nullptr) {
        delete departamento;
        return;
    }

    Nodo_Departamento* nuevo = new Nodo_Departamento(departamento);

    if (estaVacia()) {
        primero = nuevo;
    }
    else {
        Nodo_Departamento* actual = primero;

        while (actual->getSiguiente() != nullptr) {
            actual = actual->getSiguiente();
        }

        actual->setSiguiente(nuevo);
    }
}

Departamento* Lista_Departamento::buscar(string codigo) {

    Nodo_Departamento* actual = primero;

    while (actual != nullptr) {

        if (actual->getDato()->getCodigo() == codigo) {
            return actual->getDato();
        }

        actual = actual->getSiguiente();
    }

    return nullptr;
}

bool Lista_Departamento::eliminar(string codigo) {

    if (primero == nullptr) {
        return false;
    }

    if (primero->getDato()->getCodigo() == codigo) {

        Nodo_Departamento* temporal = primero;
        primero = primero->getSiguiente();

        delete temporal;

        return true;
    }

    Nodo_Departamento* actual = primero;

    while (actual->getSiguiente() != nullptr) {

        if (actual->getSiguiente()->getDato()->getCodigo() == codigo) {

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

        cout << actual->getDato()->toString() << endl;

        actual = actual->getSiguiente();
    }
}

void Lista_Departamento::autoGuardar() {

    ofstream archivo("departamentos.txt");

    if (!archivo.is_open()) {
        return;
    }

    Nodo_Departamento* actual = primero;

    while (actual != nullptr) {

        actual->getDato()->autoGuardar(archivo);

        actual = actual->getSiguiente();
    }

    archivo.close();
}

void Lista_Departamento::autoLeer() {

    ifstream archivo("departamentos.txt");

    if (!archivo.is_open()) {
        return;
    }

    while (true) {

        Departamento* departamento = Departamento::autoLeer(archivo);

        if (departamento == nullptr) {
            break;
        }

        insertar(departamento);
    }

    archivo.close();
}

