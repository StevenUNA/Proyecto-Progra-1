#ifndef MEDICO_H
#define MEDICO_H
#include "Empleado.h"

class Medico : public Empleado {
public:
	Medico(string id, string nombre, Departamento * dep, bool seguro, string especialidad);
	~Medico();
	
	void setespecialidad (string especialidad);
	string getespecialidad ();
	
	void autoGuardar (ofstream & salida) override;
	Empleado* autoLeer(ifstream& entrada) override;
	double calcular_salarioBase ( ) override;
	string toString ( ) override;
	
private:
	string especialidad;
};

#endif

