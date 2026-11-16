#include "Medico.h"

Medico::Medico (string id, string nombre, double salarioBruto, int horasExtras, bool seguro, string especialidad, int cantidadGuardias): Empleado (id, nombre, salarioBruto, horasExtras, seguro) {
	this->especialidad=especialidad;
	this->cantidadGuardias=cantidadGuardias;
	this->salarioNeto=Medico::calcular_salarioNeto();
}

Medico::~Medico() {
	cout << "[ELIMINANDO MEDICO]\n";
}

string Medico::toString ( ) {
	stringstream s;
	
	s << "---| DATOS DEL MEDICO |---\n" <<
	Empleado::toString() << endl <<
	"Especialidad: " << especialidad << endl <<
	"Cantidad de Guardias: " << cantidadGuardias << endl <<
	"Salario Neto: " << salarioNeto << endl;
	
	return s.str();
}

void Medico::autoGuardar (ofstream & salida) {
	cout << "    <<Guardando>>" << endl;
	cout << toString() << endl;
	salida << id  << endl
		<< nombre << endl
		<< seguro << endl
		<< salarioBruto << endl
		<< horasExtras << endl
		<< salarioNeto << endl
		<< especialidad << endl
		<< cantidadGuardias << endl;
}


Empleado * Medico::autoLeer (ifstream & entrada) {
	string id, nom,esp;
	int guardias, extras;
	double salarioNeto, salarioBruto;
	bool seguro;
	
	
	if (!(entrada >> id)) { return NULL; }
	if (!(entrada >> nom)) { return NULL; }
	if (!(entrada >> seguro)){ return NULL; }
	if (!(entrada >> salarioBruto)){ return NULL; }
	if (!(entrada >> salarioNeto)){ return NULL; }
	if (!(entrada >> guardias)){ return NULL; }
	if (!(entrada >> extras)){ return NULL; }
	
	if (!(entrada >> esp)) { return NULL; }
	cout << "   --Cargando registro" << endl;
	return new Medico(id, nom, salarioBruto, extras, seguro, especialidad, cantidadGuardias) ;
}

double Medico::calcular_salarioNeto ( ) {
	
	//Datos Base
	double salarioBruto=Medico::getsalarioBruto();
	int Guardias=Medico::getcantidadGuardias();
	int horasExtras=Medico::gethorasExtras();
	double salarioNeto=0.0;
	
	//Bonificaciones y deducciones por ley
	double bonificacion_horasExtras=(salarioBruto*0.50)*horasExtras;
	double bonificacion_Guardias=(salarioBruto*0.50)*Guardias;
	float fcl=salarioBruto*0.015;
	float rop=salarioBruto*0.01;
	double ImpuestoSocial= salarioBruto * 0.1083;
	double impuestoRenta=0.0;
	
	//Suma de bonififcaciones al salario bruto
	salarioBruto+=bonificacion_horasExtras+bonificacion_Guardias;
	
	
	//Calculo de impuesto de renta
	double excedente=0.0;
	
	if (salarioBruto>918000&&salarioBruto<=1347000) {
		excedente=salarioBruto-918000;
		impuestoRenta=excedente*0.10;
		
	} else if (salarioBruto>1347000&&salarioBruto<=2364000) {
		excedente=salarioBruto-1347000;
		impuestoRenta=(429000*0.10)+(excedente*0.15);
		
	} else if (salarioBruto>2364000 && salarioBruto <= 4727000) {
		excedente=salarioBruto-2364000;
		impuestoRenta=(429000*0.10)+(1017000*0.15)+ (excedente*0.20);
		
		
	} else if (salarioBruto>4727000) {
		excedente=salarioBruto-4727000;
		impuestoRenta=(429000*0.10)+(1017000*0.15)+(2363000*0.20) + (excedente*0.25);
		
	}
	
	
	//Calculo de salario neto
	salarioNeto= salarioBruto - impuestoRenta - ImpuestoSocial - fcl - rop;
	
	return salarioNeto;
	
}


void Medico::setespecialidad (string especialidad) {
	this->especialidad=especialidad;
}

string Medico::getespecialidad ( ) {
	return especialidad;
}



void Medico::setcantidadGuardias (int cantidadGuardias) {
	this->cantidadGuardias=cantidadGuardias;
	
}

int Medico::getcantidadGuardias ( ) {
	return cantidadGuardias;
}
