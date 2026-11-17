
#ifndef LISTA_PUESTO_H
#define LISTA_PUESTO_H

#include "Nodo Puesto.h"
#include <string>

using namespace std;

class Lista_Puesto {
private:
	Nodo_Puesto* primero;
	
public:
	Lista_Puesto();
	~Lista_Puesto();
	
	bool insertar(Puesto* puesto);
	Puesto* buscar(string codigo);
	bool eliminar(string codigo);
	
	string mostrar();
	string toString();
	
	bool estaVacia();
	
};

#endif
