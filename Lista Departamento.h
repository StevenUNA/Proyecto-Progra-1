
#ifndef LISTA_DEPARTAMENTO_H
#define LISTA_DEPARTAMENTO_H
#include "Nodo Departamento.h"

class Lista_Departamento {
private:
    Nodo_Departamento* primero;

public:
    Lista_Departamento();
    ~Lista_Departamento();

    bool estaVacia();
    void insertar(Departamento* departamento);
    Departamento* buscar(string codigo);
    bool eliminar(string id);
    void mostrar();
};

#endif
