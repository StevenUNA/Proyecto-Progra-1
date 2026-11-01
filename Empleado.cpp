#include "Empleado.h"

Empleado::Empleado() {
	this->id="N/A";
	this->nombre="N/A";
	this->departamento=new Departamento();
	this->seguro=false;
}

Empleado::Empleado (string id, string nombre, Departamento * dep, bool seguro) {
	this->id=id;
	this->nombre=nombre;
	this->departamento=new Departamento(*dep);
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

void Empleado::setdepartamento (Departamento *dep) {
	this->departamento=new Departamento(*dep);	
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

Departamento* Empleado::getdepartamento ( ) {
	return departamento;
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
	s << "Departamento: " << *departamento << endl;
	s << "Seguro: " << seguro_str << endl;
	
	return s.str();
}


void Empleado::ingresarDepartamento (string codigo) {
	
	
}

