
 string getCodigo();
    string getNombre();

    void agregarPuesto(Puesto *dato);
    int eliminarPuesto(string codigo);

    string consultarPuesto(string codigo);
    string listarPuestos();

    string toString();

    void autoGuardar(ofstream &salida);
    static Departamento* autoLeer(ifstream &entrada);

private:
    string codigo;
    string nombre;
    Lista_Puesto listaPuestos;
};

#endif
