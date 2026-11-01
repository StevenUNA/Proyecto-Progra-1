#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "Departamento.h"

using namespace std;
class Empleado {
public:
	Empleado();
	Empleado(string id, string nombre, Departamento* dep, bool seguro);
	void setid(string id); 
	void setnombre(string nombre);
	void setdepartamento (Departamento* dep); 
	void setseguro (bool seguro);
	string getid();
	string getnombre();
	double getsalarioBase();
	Departamento* getdepartamento();
	bool getseguro();
	
	void ingresarDepartamento(string codigo);
	
	virtual string  toString(); 
	virtual void autoGuardar (ofstream& salida)=0;
	virtual Empleado* autoLeer(ifstream& entrada)=0; 
	virtual ~Empleado()=0;
	virtual double  calcular_salarioBase()=0;
	
	
protected:
	string id;
	string nombre;
	double salarioBase; 
	Departamento* departamento; 
	bool seguro;
	
};

#endif

