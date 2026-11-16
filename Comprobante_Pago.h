#ifndef COMPROBANTE_PAGO_H
#define COMPROBANTE_PAGO_H
#include <iostream>
#include <sstream>
#include <fstream>
#include "Lista_Empleado.h"
#include "Lista_Departamento.h"

using namespace std;
class Comprobante_Pago {
public:
	Comprobante_Pago();
	Comprobante_Pago(int id, string fecha, double salario_bruto, double salario_neto, Empleado *empleado, Departamento *departamento);
	
	void setId(int id);
	void setFecha(string fecha);
	void setSalario_bruto(double salario_bruto);
	void setSalario_neto(double salario_neto);
	
	int getId();
	string getFecha();
	double getSalario_bruto();	double getSalario_neto();
	string toString();
	
	void autoGuardar (ofstream & salida) ;
	Comprobante_Pago* autoLeer(ifstream& entrada, Lista_Empleado &empleados, Lista_Departamento &departamentos) ;
	
	void calculardeducciones(Empleado *empleado);
	
	~Comprobante_Pago();
private:
	int id;
	string fecha;
	double salario_bruto, salario_neto;
	Empleado *empleado;
	Departamento *departamento;
	
};

#endif
