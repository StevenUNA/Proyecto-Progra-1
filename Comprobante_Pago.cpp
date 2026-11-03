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
	this -> id=id;
	this -> fecha=fecha; 
	this -> salario_bruto=salario_bruto;
	this -> deducciones=deducciones;
	this -> empleado = empleado;
	this-> departamento = departamento;
}

Comprobante_Pago::~Comprobante_Pago() {
	cout << "Borrando comprobante de pago\n";
}

void Comprobante_Pago::setId (int id) {
	this -> id=id;
	
}

void Comprobante_Pago::setFecha (string fecha) {
	this -> fecha=fecha; 
	
}

void Comprobante_Pago::setSalario_bruto (double salario_bruto) {
	this -> salario_bruto=salario_bruto;
	
}

void Comprobante_Pago::setDeducciones (double deducciones) {
	this -> deducciones=deducciones;
}

int Comprobante_Pago::getId ( ) {
	return id;
}

string Comprobante_Pago::getFecha ( ) {
	return fecha;
}

double Comprobante_Pago::getSalario_bruto ( ) {
	return salario_bruto;
}

double Comprobante_Pago::getDeducciones ( ) {
	return deducciones;
}


string Comprobante_Pago::toString(){
	stringstream s;
	s << "Comprobante de Pago\n";
	s << "ID: " << id << endl;
	s << "Fecha: " << fecha << endl;
	s << "Salario Bruto: " << salario_bruto << endl;
	s << "Deducciones: " << deducciones << endl;
	s << "Empleado: " << empleado->toString() << endl;
	s << "Departamento: " << departamento->toString()<< endl;
	
	return s.str();
}
