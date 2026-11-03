#ifndef COMPROBANTE_PAGO_H
#define COMPROBANTE_PAGO_H
#include <iostream>
#include <sstream>
#include <fstream>
#include "Empleado.h"
#include "Departamento.h"

using namespace std;
class Comprobante_Pago {
public:
	Comprobante_Pago();
	Comprobante_Pago(int id, string fecha, double salario_bruto, double deducciones, Empleado *empleado, Departamento *departamento);
	
	void setId(int id);
	void setFecha(string fecha);
	void setSalario_bruto(double salario_bruto);
	void setDeducciones(double deducciones);
	
	int getId();
	string getFecha();
	double getSalario_bruto();
	double getDeducciones();
	string toString ();
	
	~Comprobante_Pago();
private:
	int id;
	string fecha;
	double salario_bruto;
	double deducciones;
	Empleado *empleado;
	Departamento *departamento;
	
};

#endif
