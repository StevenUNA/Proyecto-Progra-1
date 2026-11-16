#ifndef MEDICO_H
#define MEDICO_H
#include "Empleado.h"

class Medico : public Empleado {
public:
	Medico(string id, string nombre, double salarioBruto, int horasExtras, bool seguro, string especialidad, int cantidadGuardias);
	~Medico();
	
	void setespecialidad (string especialidad);
	string getespecialidad ();
	void setcantidadGuardias (int cantidadGuardias);
	int getcantidadGuardias();
	
	void autoGuardar (ofstream & salida) override;
	Empleado* autoLeer(ifstream& entrada) override;
	double calcular_salarioNeto ( ) override;
	string toString ( ) override;
	
private:
	string especialidad="";
	int cantidadGuardias=0;
};

#endif
