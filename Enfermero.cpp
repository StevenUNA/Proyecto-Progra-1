#include "Enfermero.h"

Enfermero::Enfermero(string id, string nombre, bool seguro): Empleado (id, nombre, seguro) {
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
		<< seguro << endl 
		<< salarioBase << endl;
}

Empleado * Enfermero::autoLeer (ifstream & entrada) {
	string id, nom;
	bool seguro;
	double salario;
	
	if (!(entrada >> id)) { return NULL; }
	if (!(entrada >> nom)) { return NULL; }
	if (!(entrada >> seguro)){ return NULL; }
	if (!(entrada >> salario)){ return NULL; }
	cout << "   --Cargando registro" << endl;
	return new Enfermero(id, nom, seguro);
}

double Enfermero::calcular_salarioBase ( ) {
	
}


