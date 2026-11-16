#include "Empleado.h"
#include <string>

Empleado::Empleado() {
	this->id="N/A";
	this->nombre="N/A";
	this->salarioBruto=0.0;
	this->horasExtras=0.0;
	this->seguro=false;
	this->salarioNeto=0.0;
}

Empleado::Empleado (string id, string nombre, double salarioBruto, int horasExtras, bool seguro) {
	this->id=id;
	this->nombre=nombre;
	this->salarioBruto=salarioBruto;
	this->horasExtras=horasExtras;
	this->seguro=seguro;
	
}

Empleado::~Empleado() {
	cout << "ELIMINANDO EMPLEADO\n";
}


void Empleado::setid (string id) {
	this->id=id;
	
}

void Empleado::setnombre (string nombre) {
	this->nombre=nombre;
	
}


void Empleado::setseguro (bool seguro) {
	this->seguro=seguro;
}

void Empleado::sethorasExtras (int horasExtras) {
	this->horasExtras=horasExtras;
	
}

string Empleado::getid ( ) {
	return id;
}

string Empleado::getnombre ( ) {
	return nombre;
}



double Empleado::getsalarioNeto ( ) {
	return salarioNeto;
}

double Empleado::getsalarioBruto ( ) {
	return salarioBruto;
}

int Empleado::gethorasExtras ( ) {
	return horasExtras;
}

bool Empleado::getseguro ( ) {
	return seguro;
}

string Empleado::toString ( ) {
	stringstream s;
	string seguro_str=(seguro)? "Si":"No";
	
	s << "ID: " << id << endl;
	s << "Nombre: " << nombre << endl;
	s << "Salario Bruto: " << salarioBruto << endl;
	s << "Horas extras" << horasExtras << endl;
	s << "Seguro: " << seguro_str << endl;
	
	return s.str();
}
