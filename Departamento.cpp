
    if (!getline(entrada, codigo)) {
        return NULL;
    }

    if (!getline(entrada, nombre)) {
        return NULL;
    }

    if (!(entrada >> cantidad)) {
        return NULL;
    }

    entrada.ignore(numeric_limits<streamsize>::max(), '\n');

    Departamento *nuevo = new Departamento(codigo, nombre);

    nuevo->listaPuestos.cargar(entrada, cantidad);

    return nuevo;
}
