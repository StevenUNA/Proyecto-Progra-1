#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "Empleado.h"

class Administrativo : public Empleado {
public:
	Administrativo (string id, string nombre, bool seguro);
	~Administrativo();
	string toString ( ) override;
	void autoGuardar (ofstream & salida) override;
	Empleado * autoLeer (ifstream & entrada) override;
	double calcular_salarioBase ( ) override;
	
private:
};

#endif

