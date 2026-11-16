#ifndef ENFERMERO_H
#define ENFERMERO_H
#include "Empleado.h"

class Enfermero : public Empleado {
public:
	Enfermero(string id, string nombre, string turno, double salarioBruto, int horasExtras, bool seguro);
	~Enfermero();
	void autoGuardar (ofstream & salida) override;
	Empleado * autoLeer (ifstream & entrada) override;
	double calcular_salarioNeto ( ) override;
	string toString ( ) override;
private:
	string turno;
};

#endif
