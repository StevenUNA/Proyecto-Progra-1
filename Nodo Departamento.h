
#ifndef NODO_DEPARTAMENTO_H
#define NODO_DEPARTAMENTO_H

#include "Departamento.h"

class Nodo_Departamento {
private:
    Departamento* dato;
    Nodo_Departamento* siguiente;

public:
    Nodo_Departamento(Departamento* dato);
    ~Nodo_Departamento();

    Departamento* getDato();
    Nodo_Departamento* getSiguiente();

    void setSiguiente(Nodo_Departamento* siguiente);
};

#endif
