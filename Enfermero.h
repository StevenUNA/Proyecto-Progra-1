#ifndef ENFERMERO_H
#define ENFERMERO_H
#include "Empleado.h"

class Enfermero : public Empleado {
public:
	Enfermero(string id, string nombre, Departamento * dep, bool seguro);
	~Enfermero();
	void autoGuardar (ofstream & salida) override;
	Empleado * autoLeer (ifstream & entrada) override;
	double calcular_salarioBase ( ) override;
	string toString ( ) override;
private:
};

#endif

