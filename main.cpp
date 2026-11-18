#include <iostream>
#include <fstream>
#include <limits>
#include "Medico.h"
#include "Enfermero.h"
#include "Administrativo.h"
#include "Departamento.h"
#include "Puesto.h"
#include "Comprobante_Pago.h"
#include "Lista_Empleado.h"
#include "Lista Departamento.h"
#include "Lista_Comprobante_Pago.h"

using namespace std;

void cargarEmpleados(Lista_Empleado& empleados) {
    ifstream f("empleados.txt");
    char tipo;
    string id;

    while (f >> tipo) {
        if (tipo == 'X') {
            f >> id;
            if (empleados.buscarEmpleado(id))
                empleados.eliminarEmpleado(id);
            continue;
        }

        Empleado* e = nullptr;

        if (tipo == 'M') {
            Medico x("", "", 0, 0, false, "", 0);
            e = x.autoLeer(f);
        }
        if (tipo == 'E') {
            Enfermero x("", "", "", 0, 0, false);
            e = x.autoLeer(f);
        }
        if (tipo == 'A') {
            Administrativo x("", "", "", 0, 0, false);
            e = x.autoLeer(f);
        }

        if (e) empleados.insertarEmpleado(e);
    }
}

void guardarEmpleado(Empleado* e) {
    ofstream f("empleados.txt", ios::app);

    if (dynamic_cast<Medico*>(e)) f << "M\n";
    else if (dynamic_cast<Enfermero*>(e)) f << "E\n";
    else f << "A\n";

    e->autoGuardar(f);
}

void cargarDepartamentos(Lista_Departamento& departamentos) {
    ifstream f("departamentos.txt");
    char tipo;
    string codigo;

    while (f >> tipo) {
        if (tipo == 'D') {
            f.ignore(numeric_limits<streamsize>::max(), '\n');
            Departamento* d = Departamento::autoLeer(f);
            if (d) departamentos.insertar(d);
        }
        else if (tipo == 'P') {
            f >> codigo;
            f.ignore(numeric_limits<streamsize>::max(), '\n');
            Puesto* p = Puesto::autoLeer(f);
            Departamento* d = departamentos.buscar(codigo);

            if (d && p) d->agregarPuesto(p);
            else delete p;
        }
    }
}

void guardarDepartamento(Departamento* d) {
    ofstream f("departamentos.txt", ios::app);
    f << "D\n";
    d->autoGuardar(f);
}

void guardarPuesto(string codigo, Puesto* p) {
    ofstream f("departamentos.txt", ios::app);
    f << "P\n" << codigo << '\n';
    p->autoGuardar(f);
}

void cargarPlanilla(Lista_Comprobante_Pago& planilla,
                    Lista_Empleado& empleados,
                    Lista_Departamento& departamentos) {
    ifstream f("planilla.txt");

    while (f.peek() != EOF) {
        Comprobante_Pago* c =
            Comprobante_Pago::autoLeer(f, empleados, departamentos);

        if (!c) break;
        planilla.insertarComprobante_Pago(c);
    }
}

void registrarEmpleado(Lista_Empleado& empleados) {
    int op, extras, guardias = 0, seguro;
    string id, nombre, turno, especialidad;
    double salario;

    cout << "\n1. Medico\n2. Enfermero\n3. Administrativo\nTipo: ";
    cin >> op;

    if (op < 1 || op > 3) return;

    cout << "Identificacion: ";
    cin >> id;

    if (empleados.buscarEmpleado(id)) {
        cout << "Identificacion existente.\n";
        return;
    }

    cout << "Nombre (sin espacios): ";
    cin >> nombre;

    cout << "Salario bruto: ";
    cin >> salario;

    cout << "Horas extras: ";
    cin >> extras;

    cout << "Seguro (1=Si, 0=No): ";
    cin >> seguro;

    if (salario <= 0 || extras < 0 ||
        (seguro != 0 && seguro != 1)) {
        cout << "Datos invalidos.\n";
        return;
    }

    Empleado* e = nullptr;

    if (op == 1) {
        cout << "Especialidad: ";
        cin >> especialidad;

        cout << "Guardias: ";
        cin >> guardias;

        if (guardias < 0) return;

        e = new Medico(id, nombre, salario, extras,
                       seguro, especialidad, guardias);
    }
    else {
        cout << "Turno: ";
        cin >> turno;

        if (op == 2)
            e = new Enfermero(id, nombre, turno, salario, extras, seguro);
        else
            e = new Administrativo(id, nombre, turno, salario, extras, seguro);
    }

    empleados.insertarEmpleado(e);
    guardarEmpleado(e);

    cout << "\n" << e->toString();
}

void listarEmpleados(Lista_Empleado& empleados) {
    if (empleados.vacio()) cout << "No hay empleados.\n";
    else cout << empleados.ListarEmpleado();
}

void consultarEmpleado(Lista_Empleado& empleados) {
    string id;

    cout << "Identificacion: ";
    cin >> id;

    Empleado* e = empleados.buscarEmpleado(id);

    if (e) cout << e->toString();
    else cout << "Empleado no encontrado.\n";
}

void eliminarEmpleado(Lista_Empleado& empleados) {
    string id;

    cout << "Identificacion: ";
    cin >> id;

    if (empleados.eliminarEmpleado(id) == 1) {
        ofstream f("empleados.txt", ios::app);
        f << "X\n" << id << '\n';
        cout << "Empleado eliminado.\n";
    }
    else cout << "Empleado no encontrado.\n";
}

void registrarDepartamento(Lista_Departamento& departamentos) {
    string codigo, nombre;

    cout << "Codigo: ";
    cin >> codigo;

    if (departamentos.buscar(codigo)) {
        cout << "Codigo existente.\n";
        return;
    }

    cout << "Nombre (sin espacios): ";
    cin >> nombre;

    Departamento* d = new Departamento(codigo, nombre);
    departamentos.insertar(d);
    guardarDepartamento(d);

    cout << "Departamento registrado.\n";
}

void consultarDepartamento(Lista_Departamento& departamentos) {
    string codigo;

    cout << "Codigo: ";
    cin >> codigo;

    Departamento* d = departamentos.buscar(codigo);

    if (d) cout << d->toString();
    else cout << "Departamento no encontrado.\n";
}

void registrarPuesto(Lista_Departamento& departamentos) {
    string codigo, cp, nombre;

    cout << "Codigo del departamento: ";
    cin >> codigo;

    Departamento* d = departamentos.buscar(codigo);

    if (!d) {
        cout << "Departamento no encontrado.\n";
        return;
    }

    cout << "Codigo del puesto: ";
    cin >> cp;

    if (d->consultarPuesto(cp) != "Puesto no encontrado") {
        cout << "Puesto existente.\n";
        return;
    }

    cout << "Nombre del puesto (sin espacios): ";
    cin >> nombre;

    Puesto* p = new Puesto(cp, nombre);
    d->agregarPuesto(p);
    guardarPuesto(codigo, p);

    cout << "Puesto registrado.\n";
}

void procesarPlanilla(Lista_Empleado& empleados,
                      Lista_Departamento& departamentos,
                      Lista_Comprobante_Pago& planilla) {
    string id, codigo, fecha;
    int numero;

    cout << "Identificacion del empleado: ";
    cin >> id;

    Empleado* e = empleados.buscarEmpleado(id);

    if (!e) {
        cout << "Empleado no encontrado.\n";
        return;
    }

    cout << "Codigo del departamento: ";
    cin >> codigo;

    Departamento* d = departamentos.buscar(codigo);

    if (!d) {
        cout << "Departamento no encontrado.\n";
        return;
    }

    cout << "Numero de comprobante: ";
    cin >> numero;

    if (planilla.consultarComprobante_Pago(numero)) {
        cout << "Comprobante existente.\n";
        return;
    }

    cout << "Fecha: ";
    cin >> fecha;

    Comprobante_Pago* c = new Comprobante_Pago(
        numero, fecha, e->getsalarioBruto(),
        e->getsalarioNeto(), e, d
    );

    ofstream f("planilla.txt", ios::app);
    c->autoGuardar(f);
    f.close();

    planilla.insertarComprobante_Pago(c);

    cout << "Pago procesado.\n";
    cout << "Salario bruto: " << c->getSalario_bruto() << '\n';
    cout << "Salario neto: " << c->getSalario_neto() << '\n';
}

void listarPlanilla(Lista_Comprobante_Pago& planilla) {
    if (planilla.vacio()) {
        cout << "No hay comprobantes.\n";
        return;
    }

    ifstream f("planilla.txt");
    int id;
    string fecha, empleado, departamento;
    double bruto, neto;

    while (f >> id >> fecha >> bruto >> neto >> empleado >> departamento)
        cout << "Comprobante: " << id
             << " | Fecha: " << fecha
             << " | Empleado: " << empleado
             << " | Departamento: " << departamento
             << " | Bruto: " << bruto
             << " | Neto: " << neto << '\n';
}

void consultarComprobante(Lista_Comprobante_Pago& planilla) {
    int id;

    cout << "Numero: ";
    cin >> id;

    Comprobante_Pago* c = planilla.consultarComprobante_Pago(id);

    if (!c) {
        cout << "Comprobante no encontrado.\n";
        return;
    }

    cout << "ID: " << c->getId()
         << "\nFecha: " << c->getFecha()
         << "\nSalario bruto: " << c->getSalario_bruto()
         << "\nSalario neto: " << c->getSalario_neto() << '\n';
}

int main() {
    Lista_Empleado empleados;
    Lista_Departamento departamentos;
    Lista_Comprobante_Pago planilla;

    cargarEmpleados(empleados);
    cargarDepartamentos(departamentos);
    cargarPlanilla(planilla, empleados, departamentos);

    int op;

    do {
        cout << "\n=== SISTEMA DE PLANILLA HOSPITALARIA ===\n"
             << "1. Registrar empleado\n"
             << "2. Listar empleados\n"
             << "3. Consultar empleado\n"
             << "4. Eliminar empleado\n"
             << "5. Registrar departamento\n"
             << "6. Consultar departamento\n"
             << "7. Registrar puesto\n"
             << "8. Procesar planilla\n"
             << "9. Listar planilla\n"
             << "10. Consultar comprobante\n"
             << "0. Salir\n"
             << "Opcion: ";

        if (!(cin >> op)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            op = -1;
        }

        switch (op) {
            case 1: registrarEmpleado(empleados); break;
            case 2: listarEmpleados(empleados); break;
            case 3: consultarEmpleado(empleados); break;
            case 4: eliminarEmpleado(empleados); break;
            case 5: registrarDepartamento(departamentos); break;
            case 6: consultarDepartamento(departamentos); break;
            case 7: registrarPuesto(departamentos); break;
            case 8: procesarPlanilla(empleados, departamentos, planilla); break;
            case 9: listarPlanilla(planilla); break;
            case 10: consultarComprobante(planilla); break;
            case 0: cout << "Sistema finalizado.\n"; break;
            default: cout << "Opcion invalida.\n";
        }

    } while (op != 0);

    return 0;
}
