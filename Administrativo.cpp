#include "Administrativo.h"

Administrativo::Administrativo(string id, string nombre, bool seguro): Empleado (id, nombre, seguro) {
	this->salarioBase=Administrativo::calcular_salarioBase();
	
}

Administrativo::~Administrativo() {
	cout << "[ELIMINANDO ADMINISTRATIVO]\n";
}

string Administrativo::toString ( ) {
	stringstream s;
	
	s << "---| DATOS DEL ADMINISTRATIVO |---\n" <<
		Empleado::toString() << endl 
		<< "Salario base" << salarioBase << " colones\n";
	
	return s.str();
}

void Administrativo::autoGuardar (ofstream & salida) {
	cout << "    <<Guardando>>" << endl;
	cout << toString() << endl;
	salida << id  << endl
		<< nombre << endl
		<< seguro << endl 
		<< salarioBase << endl;
}

Empleado * Administrativo::autoLeer (ifstream & entrada) {
	string id, nom;
	bool seguro;
	double salario;
	
	if (!(entrada >> id)) { return NULL; }
	if (!(entrada >> nom)) { return NULL; }
	if (!(entrada >> seguro)){ return NULL; }
	if (!(entrada >> salario)){ return NULL; }
	cout << "   --Cargando registro" << endl;
	return new Administrativo(id, nom, seguro);
}

double Administrativo::calcular_salarioBase ( ) {
	
}
