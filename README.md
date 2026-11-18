# Proyecto-Progra-1
Integrantes:

Steven Rojas Palacios: 1-1984-0674
  
Matías Rodríguez Vargas: 2-0897-0104
  
Issac Benavides Umaña: 2-0890-0449


-----------Instrucciones de compilación-----------
Empleado: Se utiliza herencia para tres clases derivadas (Medico, Enfermero y Administrativo). En esta clase se calcula el salario neto de los empleados del hospital, considerando deducciones y bonificaciones
según el tipo de empleado. La clase Empleado tiene su respectiva lista enlazada.

Puesto: Clase utilizada para una colección de Puestos que forma parte de la clase Departamento (Composición). Tiene su propia lista enlazada.

Departamento: Divide al hospital en departamentos. Se compone de una lista de tipo Puesto. Cuenta con su lista enlazada.

Comprobante de pago: Clase usada para el proceso de pago para los empleados. Agrega por referencia un objeto de tipo Empleado y de Departamento (Agregación).

main: Cuenta con metodos tipo void para cargar los empleados, puestos, departamentos y comprobantes de pago desde los archivos txt. Usa diversas validaciones para determinar la forma adecuada para cargar cada objeto. 
Cuenta con un menu interactivo para realizar consultas, cargar o eliminar datos e insertar nuevos departamentos, empleados y demás.

Archivos txt: Cada clase tiene un método de autoGuardar y autoLeer para la gestión de este tipo de archivos.

Estructura de archivos C++: Cada archivo tiene una cabcera .h (Dónde se declaran métodos y atributos) y un archivo .cpp (Dónde se defienen los métodos y atributos). Cada archivo dee incluir las librerías necesarias para su funcionamiento.
