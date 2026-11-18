#include "Lista_Empleado.h"

Lista_Empleado::Lista_Empleado() {
	cabeza=actual=NULL;
}

Lista_Empleado::~Lista_Empleado() {
	while (cabeza!=NULL){
		this->actual=cabeza;
		cabeza=cabeza->getSig();
		delete actual;
	}
}


bool Lista_Empleado::vacio ( ) {
	return cabeza==NULL;
}

void Lista_Empleado::insertarEmpleado (Empleado * dato) {
	Nodo_Empleado *aux=new Nodo_Empleado(dato); 
	if (vacio()){
		cabeza=aux; 
	} else {
		actual=cabeza;
		while (actual->getSig() !=NULL){
			actual=actual->getSig();
		}
		actual->setSig(aux);
		
	}
}

int Lista_Empleado::eliminarEmpleado (string id) {
	if (vacio()){
		return 0;
	} else {
		actual=cabeza;
		Nodo_Empleado *aux=cabeza;
		
		if (cabeza->getDato()->getid()==id){
			cabeza=cabeza->getSig();
			delete aux;
			return 1;
			
		} else {
			bool n=true; 
			while(actual->getSig()!=NULL && n==true){ 
				if (actual->getSig()->getDato()->getid()==id){
					
					
					aux=actual->getSig();
					actual->setSig(aux->getSig()); 
					delete aux;
					n=false;
					
					
				} else {
					actual=actual->getSig();
					
				}
			}
			return n? -1:1; 
		}
		
	}
}


int Lista_Empleado::modificarEmpleado (string id, Empleado * dato) {
	actual=cabeza; 
	if(vacio()){
		return 0;
	}
	
	while(actual!=NULL){ 
		if(actual->getDato()->getid()==id){ 
			if(actual->getDato()!=dato){
				delete actual->getDato();
			}
			actual->setDato(dato);
			return 1;
		}
		actual=actual->getSig(); 
	}
	
	return -1;
}

string Lista_Empleado::consultarEmpleado (string id) {
	actual=cabeza;
	if(vacio()){
		return "0"; 
	}
	else{
		bool n=true;
		while(actual != NULL && n==true){ 
			if(actual->getDato()->getid()==id){
				n=false;
				return actual->getDato()->toString(); 
			}
			actual = actual->getSig(); 		
		}
		if(actual == NULL) {
			return "-1";
		}
	}
	return "1";
}

string Lista_Empleado::ListarEmpleado ( ) {
	string cadena="";
	actual=cabeza; 
	if(vacio()){
		return "0";  
	}
	else{
		//cadena="";
		while(actual!=NULL){  
			cadena=cadena + actual->getDato()-> toString() + "\n"; 
			actual=actual->getSig(); 
		}
		return cadena;
	}
}

Empleado * Lista_Empleado::buscarEmpleado (string id) {
	actual=cabeza;
	if(vacio()){
		return nullptr; 
	}
	else{
		bool n=true;
		while(actual != NULL && n==true){ 
			if(actual->getDato()->getid()==id){
				n=false;
				return actual->getDato(); 
			}
			actual = actual->getSig(); 		
		}
		if(actual == NULL) {
			return nullptr;
		}
	}
}

