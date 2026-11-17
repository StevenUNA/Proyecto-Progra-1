
#include "Lista_Puesto.h"
#include <sstream>

using namespace std;

Lista_Puesto::Lista_Puesto() {
	primero = nullptr;
}

Lista_Puesto::~Lista_Puesto() {
	Nodo_Puesto* actual = primero;
	
	while (actual != nullptr) {
		Nodo_Puesto* temporal = actual;
		actual = actual->getSiguiente();
		delete temporal;
	}
}

bool Lista_Puesto::insertar(Puesto* puesto) {
	
	if (puesto == nullptr) {
		return false;
	}
	
	if (buscar(puesto->getCodigo()) != nullptr) {
		return false;
	}
	
	Nodo_Puesto* nuevo = new Nodo_Puesto(puesto);
	
	if (primero == nullptr) {
		primero = nuevo;
	}
	else {
		Nodo_Puesto* actual = primero;
		
		while (actual->getSiguiente() != nullptr) {
			actual = actual->getSiguiente();
		}
		
		actual->setSiguiente(nuevo);
	}
	
	return true;
}

Puesto* Lista_Puesto::buscar(string codigo) {
	
	Nodo_Puesto* actual = primero;
	
	while (actual != nullptr) {
		
		if (actual->getDato()->getCodigo() == codigo) {
			return actual->getDato();
		}
		
		actual = actual->getSiguiente();
	}
	
	return nullptr;
}

bool Lista_Puesto::eliminar(string codigo) {
	
	if (primero == nullptr) {
		return false;
	}
	
	if (primero->getDato()->getCodigo() == codigo) {
		
		Nodo_Puesto* temporal = primero;
		primero = primero->getSiguiente();
		
		delete temporal;
		
		return true;
	}
	
	Nodo_Puesto* actual = primero;
	
	while (actual->getSiguiente() != nullptr) {
		
		if (actual->getSiguiente()->getDato()->getCodigo() == codigo) {
			
			Nodo_Puesto* temporal = actual->getSiguiente();
			
			actual->setSiguiente(temporal->getSiguiente());
			
			delete temporal;
			
			return true;
		}
		
		actual = actual->getSiguiente();
	}
	
	return false;
}

string Lista_Puesto::mostrar() {
	
	stringstream ss;
	
	Nodo_Puesto* actual = primero;
	
	while (actual != nullptr) {
		
		ss << actual->getDato()->toString() << "\n";
		
		actual = actual->getSiguiente();
	}
	
	return ss.str();
}

string Lista_Puesto::toString() {
	return mostrar();
}

bool Lista_Puesto::estaVacia() {
	return primero == nullptr;
}
