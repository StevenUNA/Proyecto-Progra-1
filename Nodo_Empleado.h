#ifndef NODO_EMPLEADO_H
#define NODO_EMPLEADO_H
#include "Empleado.h"
class Nodo_Empleado {
public:
	Nodo_Empleado(Empleado *dato);
	~Nodo_Empleado();
	void setDato (Empleado *dato);
	void setSig (Nodo_Empleado *Sig);
	Empleado* getDato();
	Nodo_Empleado* getSig();
private:
	Empleado* dato;
	Nodo_Empleado* sig;
	
};

#endif

