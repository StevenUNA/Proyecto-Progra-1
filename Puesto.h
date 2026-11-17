
#ifndef PUESTO_H
#define PUESTO_H

#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

class Puesto {
private:
    string codigo;
    string nombre;

public:
    Puesto();
    Puesto(string codigo, string nombre);
    ~Puesto();

    string getCodigo();
    string getNombre();

    void setCodigo(string codigo);
    void setNombre(string nombre);
	
	void autoGuardar (ofstream & salida) ;
	static Puesto* autoLeer(ifstream& entrada) ;
	
    string toString();
};

#endif


