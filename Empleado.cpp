#include "Empleado.h"

Empleado::Empleado() {
	this->id="N/A";
	this->nombre="N/A";
	this->seguro=false;
}

Empleado::Empleado (string id, string nombre, bool seguro) {
	this->id=id;
	this->nombre=nombre;
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

string Empleado::getid ( ) {
	return id;
}

string Empleado::getnombre ( ) {
	return nombre;
}

double Empleado::getsalarioBase ( ) {
	return salarioBase;
}



bool Empleado::getseguro ( ) {
	return seguro;
}

string Empleado::toString ( ) {
	stringstream s;
	string seguro_str=(seguro)? "Si":"No";
	
	s << "ID: " << id << endl;
	s << "Nombre: " << nombre << endl;
	s << "Salario Base: " << salarioBase << endl;
	s << "Seguro: " << seguro_str << endl;
	
	return s.str();
}




