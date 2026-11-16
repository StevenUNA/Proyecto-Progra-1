#ifndef LISTA_EMPLEADO_H
#define LISTA_EMPLEADO_H
#include "Nodo_Empleado.h"

class Lista_Empleado {
public:
	Lista_Empleado();
	~Lista_Empleado();
	bool vacio();
	void insertarEmpleado(Empleado *dato);
	int eliminarEmpleado (string id);
	int modificarEmpleado (string id, Empleado *dato);
	Empleado* buscarEmpleado (string id);
	
	string consultarEmpleado (string id);
	string ListarEmpleado ();
private:
	Nodo_Empleado *cabeza, *actual;
};

#endif

