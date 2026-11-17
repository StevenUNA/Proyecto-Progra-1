
#ifndef LISTA_PUESTO_H
#define LISTA_PUESTO_H

#include "Nodo_Puesto.h"
#include <string>

using namespace std;

class Lista_Puesto {
private:
    Nodo_Puesto* primero;

public:
    Lista_Puesto();
    ~Lista_Puesto();

    bool insertar(Puesto* puesto);
    Puesto* buscar(int codigo);
    bool eliminar(int codigo);

    string mostrar();
    string toString();

    bool estaVacia();
};

#endif
