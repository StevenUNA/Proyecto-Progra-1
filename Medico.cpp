#include "Medico.h"

Medico::Medico(string id, string nombre, bool seguro, string especialidad): Empleado (id, nombre, seguro) {
	this->especialidad=especialidad;
	this->salarioBase=Medico::calcular_salarioBase();
	
}

Medico::~Medico() {
	cout << "[ELIMINANDO MEDICO]\n";
}

string Medico::toString ( ) {
	stringstream s;
	
	s << "---| DATOS DEL MEDICO |---\n" <<
	Empleado::toString() <<
	"Salario base" << salarioBase << " colones\n" <<
	"Especialidad" << especialidad << endl;
	
	return s.str();
}

void Medico::autoGuardar (ofstream & salida) {
	cout << "    <<Guardando>>" << endl;
	cout << toString() << endl;
	salida << id  << endl
		<< nombre << endl
		<< seguro << endl 
		<< salarioBase << endl
		<< especialidad << endl;
}


Empleado * Medico::autoLeer (ifstream & entrada) {
	string id, nom, esp;
	bool seguro;
	double salario;
	
	if (!(entrada >> id)) { return NULL; }
	if (!(entrada >> nom)) { return NULL; }
	if (!(entrada >> seguro)){ return NULL; }
	if (!(entrada >> salario)){ return NULL; }
	if (!(entrada >> esp)) { return NULL; }
	cout << "   --Cargando registro" << endl;
	return new Medico(id, nom,seguro, esp) ;
}

double Medico::calcular_salarioBase ( ) {
	
}


void Medico::setespecialidad (string especialidad) {
	this->especialidad=especialidad;
}

string Medico::getespecialidad ( ) {
	return especialidad;
}

