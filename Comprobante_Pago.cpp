#include "Comprobante_Pago.h"

Comprobante_Pago::Comprobante_Pago() {
	this -> id=0;
	this -> fecha=""; 
	this -> salario_bruto=0;
	this -> salario_neto=0;
	this -> empleado = nullptr;
	this-> departamento = nullptr;
}

Comprobante_Pago::Comprobante_Pago( int id, string fecha, double salario_bruto, double salario_neto, Empleado *empleado, Departamento *departamento){
	this -> id=id;
	this -> fecha=fecha; 
	this -> salario_bruto=salario_bruto;
	this -> salario_neto=salario_neto;
	this -> empleado = empleado;
	this-> departamento = departamento;
	
	if (empleado != nullptr) {
		this -> salario_bruto=empleado->getsalarioBruto();
		this -> salario_neto=empleado->getsalarioNeto();
	}
}

Comprobante_Pago::~Comprobante_Pago() {
	cout << "Borrando comprobante de pago\n";
}

void Comprobante_Pago::setId (int id) {
	this -> id=id;
	
}

void Comprobante_Pago::setFecha (string fecha) {
	this -> fecha=fecha; 
	
}

void Comprobante_Pago::setSalario_bruto (double salario_bruto) {
	this -> salario_bruto=salario_bruto;
	
}

void Comprobante_Pago::setSalario_neto (double salario_neto) {
	this -> salario_neto=salario_neto;
}

int Comprobante_Pago::getId ( ) {
	return id;
}

string Comprobante_Pago::getFecha ( ) {
	return fecha;
}

double Comprobante_Pago::getSalario_bruto ( ) {
	return salario_bruto;
}

double Comprobante_Pago::getSalario_neto ( ) {
	return salario_neto;
}



void Comprobante_Pago::autoGuardar(ofstream & salida){
	
	string ID_Empleado = (empleado != nullptr) ? empleado->getid() : "-1";
	string Codigo_Departamento = (departamento != nullptr) ? departamento->getCodigo() : "-1";
	
	cout<< "<<Guardando>>" <<endl;
	cout<< toString() <<endl;
	salida << id  << endl
		<< fecha << endl
		<< salario_bruto << endl
		<< salario_neto << endl
		<< ID_Empleado << endl
		<< Codigo_Departamento << endl;
	

}

Comprobante_Pago* Comprobante_Pago::autoLeer(ifstream& entrada, Lista_Empleado &empleados, Lista_Departamento &departamentos){
	string fecha, ID_Empleado, Codigo_Departamento;
	int id;
	double salario_bruto, salario_neto;
	
	
	if (!(entrada >> id)) { return NULL; }
	if (!(entrada >> fecha)) { return NULL; }
	if (!(entrada >> salario_bruto)){ return NULL; }
	if (!(entrada >> salario_neto)){ return NULL; }
	if (!(entrada >> ID_Empleado)){ return NULL; }
	if (!(entrada >> Codigo_Departamento)){ return NULL; }
	
	Empleado *empleado= empleados.buscarEmpleado(ID_Empleado);
	Departamento *departamento= departamentos.buscar(Codigo_Departamento);
	
	cout << "   --Cargando registro" << endl;
	return new Comprobante_Pago(id, fecha, salario_bruto, salario_neto, empleado, departamento) ;
}



string Comprobante_Pago::toString(){
	stringstream s;
	s << "Comprobante de Pago\n";
	s << "ID: " << id << endl;
	s << "Fecha de emision: " << fecha << endl;
	
	(empleado!=nullptr)? s << "Empleado: " << empleado->toString() << endl :  s << "Empleado: N/A" << endl;
	(departamento!=nullptr)? s << "Departamento: " << departamento->toString() << endl : s << "Departamento: N/A" << endl;
	
	s << calculardeducciones(empleado);
	
	return s.str();
}


string Comprobante_Pago::calculardeducciones (Empleado * empleado) {
	//Datos Base
	double salarioBruto=empleado->getsalarioBruto();
	double salarioNeto=empleado->getsalarioNeto();
	
	//Bonificaciones y deducciones por ley
	float fcl=salarioBruto*0.015;
	float rop=salarioBruto*0.01;
	double ImpuestoSocial= salarioBruto * 0.1083;
	double impuestoRenta=0.0;
	
	
	
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
	
	cout << "--Salario bruto y slaario neto--" << endl;
	cout << "-Salario Bruto: " << salarioBruto << endl;
	cout << "-Salario Neto: " << salarioNeto << endl;
	cout << endl << "--Desglose de deducciones generales--" << endl;
	cout << "-Fondo de Capitalizacion 1.5%: " << fcl << endl;
	cout << "-Regimen Obligatorio de Pensiones Complementarias: " << rop << endl;
	cout << "-Impuesto Social CCSS (SEM 5.50%, IVM 4,33%, Banco Popular 1.00%): " << ImpuestoSocial << endl;
	cout << "-Impuesto de renta CCSS : " << impuestoRenta << endl;
	
	
}

