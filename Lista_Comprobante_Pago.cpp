#include "Lista_Comprobante_Pago.h"

Lista_Comprobante_Pago::Lista_Comprobante_Pago() {
	this->cabeza = nullptr;
	this->actual = nullptr;
	this->cola = nullptr;
}

Lista_Comprobante_Pago::~Lista_Comprobante_Pago() {
	while (cabeza != nullptr) {
		actual = cabeza;
		cabeza = cabeza->getSig();
		delete actual;
	}
	cola = nullptr;
	actual = nullptr;
}

bool Lista_Comprobante_Pago::vacio() {
	return cabeza == nullptr;
}

// Insertar comprobante
void Lista_Comprobante_Pago::insertarComprobante_Pago(Comprobante_Pago *dato) {
	if (dato == nullptr) {
		return;
	}
	
	Nodo_Comprobante_Pago *nuevo = new Nodo_Comprobante_Pago(dato);
	
	if (vacio()) {
		cabeza = nuevo;
		cola = nuevo;
	} else {
		cola->setSig(nuevo);
		cola = nuevo;
	}
}

// Eliminar comprobante por ID
void Lista_Comprobante_Pago::eliminarComprobante_Pago(int id) {
	Nodo_Comprobante_Pago *anterior = nullptr;
	actual = cabeza;
	
	while (actual != nullptr) {
		if (actual->getDato()->getId() == id) {
			if (anterior == nullptr) {
				cabeza = actual->getSig();
			} else {
				anterior->setSig(actual->getSig());
			}
			
			if (actual == cola) {
				cola = anterior;
			}
			
			delete actual;
			actual = nullptr;
			cout << "Comprobante eliminado\n";
			return;
		}
		
		anterior = actual;
		actual = actual->getSig();
	}
	
	cout << "Comprobante no encontrado\n";
}

// Modificar comprobante
void Lista_Comprobante_Pago::modificarComprobante_Pago(int id) {
	Comprobante_Pago *dato = consultarComprobante_Pago(id);
	
	if (dato != nullptr) {
		string fecha;
		double salario_bruto;
		double deducciones;
		
		cout << "Nueva fecha: ";
		cin >> fecha;
		
		cout << "Nuevo salario bruto: ";
		cin >> salario_bruto;
		
		cout << "Nuevas deducciones: ";
		cin >> deducciones;
		
		dato->setFecha(fecha);
		dato->setSalario_bruto(salario_bruto);
		dato->setDeducciones(deducciones);
		
		cout << "Comprobante modificado\n";
	} else {
		cout << "Comprobante no encontrado\n";
	}
}

// Consultar comprobante
Comprobante_Pago* Lista_Comprobante_Pago::consultarComprobante_Pago(int id) {
	actual = cabeza;
	
	while (actual != nullptr) {
		if (actual->getDato()->getId() == id) {
			return actual->getDato();
		}
		
		actual = actual->getSig();
	}
	
	return nullptr;
}

// Listar comprobantes
void Lista_Comprobante_Pago::ListarComprobante_Pago() {
	actual = cabeza;
	
	if (vacio()) {
		cout << "Lista vacia\n";
		return;
	}
	
	while (actual != nullptr) {
		cout << actual->getDato()->toString() << endl;
		actual = actual->getSig();
	}
}

