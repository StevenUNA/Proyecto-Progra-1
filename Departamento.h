#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "Lista_Puesto.h"

using namespace std;
class Departamento {
public:
	
	Departamento(string codigo, string nombre); 
	~Departamento();
	string getCodigo();
	string getNombre();
	
	void agregarPuesto(Puesto *dato);
	int eliminarPuesto(string codigo);
	
	string consultarPuesto(string codigo);
	string listarPuestos();
	
	string toString();
	
	void autoGuardar(ofstream &salida);
	static Departamento* autoLeer(ifstream &entrada);
	
private:
	string codigo;
	string nombre;
	Lista_Puesto listaPuestos;
};

#endif

