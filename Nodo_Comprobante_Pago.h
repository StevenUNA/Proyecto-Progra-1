#ifndef NODO_COMPROBANTE_PAGO_H
#define NODO_COMPROBANTE_PAGO_H

#include "Comprobante_Pago.h"

class Nodo_Comprobante_Pago {
public:
	Nodo_Comprobante_Pago();
	Nodo_Comprobante_Pago(Comprobante_Pago *dato);
	
	void setDato(Comprobante_Pago *dato);
	void setSig(Nodo_Comprobante_Pago *sig);
	
	Comprobante_Pago* getDato();
	Nodo_Comprobante_Pago* getSig();
	
	~Nodo_Comprobante_Pago();
	
private:
	Comprobante_Pago *dato;
	Nodo_Comprobante_Pago *sig;
};

#endif

