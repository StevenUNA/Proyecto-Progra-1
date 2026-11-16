#include "Administrativo.h"

Administrativo::Administrativo(string id, string nombre, string turno, double salarioBruto, int horasExtras, bool seguro):Empleado (id, nombre, salarioBruto, horasExtras, seguro) {
	this->turno=turno;
	this->salarioNeto=Administrativo::calcular_salarioNeto();
	
}

Administrativo::~Administrativo() {
	cout << "[ELIMINANDO ADMINISTRATIVO]\n";
}

string Administrativo::toString ( ) {
	stringstream s;
	
	s << "---| DATOS DEL ADMINISTRATIVO |---\n" <<
		Empleado::toString() << endl 
		<< "Turno (20% de bonififcacion): "<< turno << endl
		<< "Salario Neto: " << salarioNeto << " colones\n";
	
	return s.str();
}

void Administrativo::autoGuardar (ofstream & salida) {
	cout << "    <<Guardando>>" << endl;
	cout << toString() << endl;
	salida << id  << endl
		<< nombre << endl
		<< turno << endl
		<< seguro << endl
		<< salarioBruto << endl
		<< horasExtras << endl
		<< salarioNeto << endl;
}

Empleado * Administrativo::autoLeer (ifstream & entrada) {
	string id, nom, turno, esp;
	int  extras;
	double salarioNeto, salarioBruto;
	bool seguro;
	
	
	if (!(entrada >> id)) { return NULL; }
	if (!(entrada >> nom)) { return NULL; }
	if (!(entrada >> seguro)){ return NULL; }
	if (!(entrada >> salarioBruto)){ return NULL; }
	if (!(entrada >> salarioNeto)){ return NULL; }
	if (!(entrada >> extras)){ return NULL; }
	if (!(entrada >> esp)) { return NULL; }
	cout << "   --Cargando registro" << endl;
	return new Administrativo(id, nom, turno, salarioBruto, horasExtras, seguro);
}

double Administrativo::calcular_salarioNeto ( ) {
	//Datos Base
	double salarioBruto=Administrativo::getsalarioBruto();
	double salarioNeto=0.0;
	int horasExtras=Administrativo::gethorasExtras();
	
	//Bonificaciones y deducciones por ley
	double bonificacion_horasExtras=(salarioBruto*0.50)*horasExtras;
	double bonificacion_turno=salarioBruto*0.20;
	float fcl=salarioBruto*0.015;
	float rop=salarioBruto*0.01;
	double ImpuestoSocial= salarioBruto * 0.1083;
	double impuestoRenta=0.0;
	
	//Suma de bonififcaciones al salario bruto
	salarioBruto+=bonificacion_turno+bonificacion_horasExtras;
	
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
	
	cout << "---Desglose de salario---\n";
	cout << "Salario bruto: " << salarioBruto << "colones\n";
	cout << "Turno (20% de bonificacion): " << turno << endl;
	cout << "Horas extra (50% de bonificacion por guardia): " << horasExtras << endl;
	cout << "Impuesto Social (SEM 5.50% + IVM 4.33% + Banco Popular 1.00%): " << ImpuestoSocial << "colones\n";
	cout << "Fondo de Capitalizacion (FCL 1.5%): " << fcl << "colones\n";
	cout << "Regimen Obligatorio De Pensiones Complementarias: " << rop << "colones\n";
	cout << "Salario Neto: " << salarioNeto << " colones\n";
	return salarioNeto;
}
