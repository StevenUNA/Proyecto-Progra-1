
#include "Departamento.h"

using namespace std;

Departamento::Departamento(string codigo, string nombre, Lista_Puesto listaPuestos) {
	this->codigo = codigo;
	this->nombre = nombre;
	this->listaPuestos = listaPuestos;
	
}

Departamento::~Departamento() {
}

string Departamento::getCodigo() {
	return codigo;
}

string Departamento::getNombre() {
	return nombre;
}

void Departamento::agregarPuesto(Puesto* dato) {
	listaPuestos.insertar(dato);
}

int Departamento::eliminarPuesto(string codigo) {
	return listaPuestos.eliminar(codigo) ? 1 : 0;
}

string Departamento::consultarPuesto(string codigo) {
	Puesto* puesto = listaPuestos.buscar(codigo);
	
	if (puesto == nullptr) {
		return "Puesto no encontrado";
	}
	
	return puesto->toString();
}

string Departamento::listarPuestos() {
	return listaPuestos.mostrar();
}

string Departamento::toString() {
	stringstream s;
	
	s << "Codigo: " << codigo << endl;
	s << "Nombre: " << nombre << endl;
	s << "Puestos:" << endl;
	s << listarPuestos();
	
	return s.str();
}

void Departamento::autoGuardar(ofstream& salida) {
	cout << "--Guardando--" << endl;
	cout << toString() << endl;
	salida << codigo << endl;
	salida << nombre << endl;
	

}

Departamento* Departamento::autoLeer(ifstream& entrada) {
	string codigo;
	string nombre;
	Lista_Puesto listaPuestos;
	
	if (!getline(entrada, codigo)) {
		return nullptr;
	}
	
	if (!getline(entrada, nombre)) {
		return nullptr;
	}
	
	return new Departamento(codigo, nombre, listaPuestos);
}

