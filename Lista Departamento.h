
#ifndef LISTA_DEPARTAMENTO_H
#define LISTA_DEPARTAMENTO_H

#include "Nodo_Departamento.h"

class Lista_Departamento {
private:
    Nodo_Departamento* primero;

public:
    Lista_Departamento();
    ~Lista_Departamento();

    bool estaVacia();
    void insertar(Departamento* departamento);
    Departamento* buscar(int id);
    bool eliminar(int id);
    void mostrar();
    void autoGuardar();
    void autoLeer();
};

#endif
