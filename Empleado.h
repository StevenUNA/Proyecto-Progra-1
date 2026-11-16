#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
class Empleado {
public:
	Empleado();
	Empleado(string id, string nombre, double salarioBruto, int horasExtras, bool seguro);
	void setid(string id); 
	void setnombre(string nombre);
	void setseguro (bool seguro);
	void sethorasExtras(int horasExtras);
	string getid();
	string getnombre();
	double getsalarioNeto();
	double getsalarioBruto();
	int gethorasExtras();
	bool getseguro();
	
	virtual string  toString()=0; 
	virtual void autoGuardar (ofstream& salida)=0;
	virtual Empleado* autoLeer(ifstream& entrada)=0; 
	virtual ~Empleado()=0;
	virtual double  calcular_salarioNeto()=0;
	
	
protected:
	string id;
	string nombre;
	double salarioNeto, salarioBruto;
	int horasExtras=0;
	bool seguro;
	
};

#endif
