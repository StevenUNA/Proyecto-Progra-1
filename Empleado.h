#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
class Empleado {
public:
	Empleado();
	Empleado(string id, string nombre, bool seguro);
	void setid(string id); 
	void setnombre(string nombre);
	void setseguro (bool seguro);
	string getid();
	string getnombre();
	double getsalarioBase();
	bool getseguro();
	
	virtual string  toString(); 
	virtual void autoGuardar (ofstream& salida)=0;
	virtual Empleado* autoLeer(ifstream& entrada)=0; 
	virtual ~Empleado()=0;
	virtual double  calcular_salarioBase()=0;
	
	
protected:
	string id;
	string nombre;
	double salarioBase; 
	bool seguro;
	
};

#endif

