
#ifndef PUESTO_H
#define PUESTO_H

#include <string>

using namespace std;

class Puesto {
private:
    int codigo;
    string nombre;

public:
    Puesto();
    Puesto(int codigo, string nombre);
    ~Puesto();

    int getCodigo();
    string getNombre();

    void setCodigo(int codigo);
    void setNombre(string nombre);

    string toString();
};

#endif

