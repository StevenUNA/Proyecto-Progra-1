#include "Comprobante_Pago.h"

Comprobante_Pago::Comprobante_Pago() {
	this -> id=0;
	this -> fecha=""; 
	this -> salario_bruto=0;
	this -> deducciones=0;
	this -> empleado = nullptr;
	this-> departamento = nullptr;
}

Comprobante_Pago::Comprobante_Pago( int id, string fecha, double salario_bruto, double deducciones, Empleado *empleado, Departamento *departamento){
	
}

Comprobante_Pago::~Comprobante_Pago() {
	
}
