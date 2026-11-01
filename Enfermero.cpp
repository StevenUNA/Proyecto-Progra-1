#include "Enfermero.h"

Enfermero::Enfermero(string id, string nombre, Departamento * dep, bool seguro): Empleado (id, nombre, dep, seguro) {
	this->salarioBase=Enfermero::calcular_salarioBase();
	
}

Enfermero::~Enfermero() {
	cout << "[ELIMINANDO ENFERMERO]\n";
	
}

string Enfermero::toString ( ) {
	stringstream s;
	
	s << "---| DATOS DEL ENFERMERO |---\n" <<
		Empleado::toString() << endl 
		<< "Salario base" << salarioBase << " colones\n";
	
	return s.str();
}


void Enfermero::autoGuardar (ofstream & salida) {
	cout << "    <<Guardando>>" << endl;
	cout << toString() << endl;
	salida << id  << endl
		<< nombre << endl
		<< *departamento << endl
		<< seguro << endl 
		<< salarioBase << endl;
}

Empleado * Enfermero::autoLeer (ifstream & entrada) {
	string id, nom;
	Departamento *dep=new Departamento();
	bool seguro;
	double salario;
	
	if (!(entrada >> id)) { return NULL; }
	if (!(entrada >> nom)) { return NULL; }
	if (!(entrada >> *dep)) { return NULL; }
	if (!(entrada >> seguro)){ return NULL; }
	if (!(entrada >> salario)){ return NULL; }
	cout << "   --Cargando registro" << endl;
	return new Enfermero(id, nom, dep, seguro);
}

double Enfermero::calcular_salarioBase ( ) {
	
}


