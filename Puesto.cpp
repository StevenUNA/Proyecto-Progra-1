
#include "Puesto.h"
#include <sstream>

using namespace std;

Puesto::Puesto() {
    codigo = 0;
    nombre = "";
}

Puesto::Puesto(int codigo, string nombre) {
    this->codigo = codigo;
    this->nombre = nombre;
}

Puesto::~Puesto() {
}

int Puesto::getCodigo() {
    return codigo;
}

string Puesto::getNombre() {
    return nombre;
}

void Puesto::setCodigo(int codigo) {
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
