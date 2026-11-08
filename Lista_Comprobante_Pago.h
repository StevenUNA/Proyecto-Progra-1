#ifndef LISTA_COMPROBANTE_PAGO_H
#define LISTA_COMPROBANTE_PAGO_H

#include "Nodo_Comprobante_Pago.h"

class Lista_Comprobante_Pago {
public:
	Lista_Comprobante_Pago();
	~Lista_Comprobante_Pago();
	
	bool vacio();
	
	void insertarComprobante_Pago(Comprobante_Pago *dato);
	void eliminarComprobante_Pago(int id);
	void modificarComprobante_Pago(int id);
	Comprobante_Pago* consultarComprobante_Pago(int id);
	void ListarComprobante_Pago();
	
private:
	Nodo_Comprobante_Pago *cabeza;
	Nodo_Comprobante_Pago *actual;
	Nodo_Comprobante_Pago *cola;
};

#endif
