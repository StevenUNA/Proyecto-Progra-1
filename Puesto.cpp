#include "Puesto.h"
#include <sstream>

using namespace std;

Puesto::Puesto() {
    codigo = "";
    nombre = "";
}

Puesto::Puesto(string codigo, string nombre) {
    this->codigo = codigo;
    this->nombre = nombre;
}

Puesto::~Puesto() {
}

string Puesto::getCodigo() {
    return codigo;
}

string Puesto::getNombre() {
    return nombre;
}

void Puesto::setCodigo(string codigo) {
    this->codigo = codigo;
}

void Puesto::setNombre(string nombre) {
    this->nombre = nombre;
}

string Puesto::toString() {
    stringstream ss;

    ss << "Codigo: " << codigo
       << " | Nombre: " << nombre;

    return ss.str();
}

void Puesto::autoGuardar (ofstream & salida) {
	cout << "--Guardando--" << endl;
	cout << toString() << endl;
	salida << codigo << endl
	<< nombre << endl;
}

Puesto * Puesto::autoLeer (ifstream & entrada) {
	string codigo, nom;
	
	
	if (!(entrada >> codigo)) { return NULL; }
	if (!(entrada >> nom)) { return NULL; }
	cout << "   --Cargando registro" << endl;
	return new Puesto(codigo,nom);
}

