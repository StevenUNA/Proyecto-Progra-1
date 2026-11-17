#ifndef NODO_PUESTO_H
#define NODO_PUESTO_H

#include "Puesto.h"

class Nodo_Puesto {
private:
    Puesto* dato;
    Nodo_Puesto* siguiente;

public:
    Nodo_Puesto(Puesto* dato);
    ~Nodo_Puesto();

    Puesto* getDato();
    Nodo_Puesto* getSiguiente();

    void setSiguiente(Nodo_Puesto* siguiente);
};

#endif
