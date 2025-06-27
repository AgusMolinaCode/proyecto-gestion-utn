#include <iostream>
#include "funciones.h"
using namespace std;

void mostrarMenu(Marca marcas[], int& cantidadMarcas, 
                 Producto productos[], int& cantidadProductos,
                 string nombresProductosGlobal[], int codigosProductosGlobal[],
                 FormaPago formasPago[], int& cantidadFormasPago,
                 Venta ventas[], int& cantidadVentas) {
    int opcion;
    bool programaActivo = true;

    while (programaActivo) {
        cout << "======= MENU PRINCIPAL =======" << endl;
        cout << "1. Cargar lote de marcas" << endl;
        cout << "2. Cargar lote de productos" << endl;
        cout << "3. Cargar lote de formas de pago" << endl;
        cout << "4. Cargar lote de ventas" << endl;
        cout << "5. Mostrar reportes" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            // Solo mostramos información básica ya que no podemos usar string ni matrices de char
            cout << "\n===== CARGA DE LOTE DE MARCAS =====" << endl;
            // Llamamos a la función de carga manual de marcas
            string nombresMarcas[10]; // Array temporal para nombres (aumentado a 10)
            int codigosMarcas[10]; // Array básico para códigos de marcas
            cargarLoteMarcas(codigosMarcas, nombresMarcas, cantidadMarcas);
            
            // Copiar los códigos al array de estructuras
            for (int i = 0; i < cantidadMarcas; i++) {
                marcas[i].codigo = codigosMarcas[i];
            }
            
            cout << "\nLote de marcas cargado exitosamente!" << endl;
            cout << "Total de marcas cargadas: " << cantidadMarcas << endl;
            
            cout << "\nPresione Enter para continuar...";
            cin.ignore(); // Limpiar el buffer de entrada para evitar problemas con getline
            cin.get();    // Esperar que el usuario presione Enter antes de continuar
        } else if (opcion == 2) {
            // Verificar si hay marcas cargadas
            if (cantidadMarcas == 0) {
                cout << "\n===== CARGA DE LOTE DE PRODUCTOS =====" << endl;
                cout << "Error: No hay marcas cargadas. Debe cargar el lote de marcas primero." << endl;
                cout << "\nPresione Enter para continuar...";
                cin.ignore(); // Limpiar el buffer de entrada para evitar problemas con getline
                cin.get();    // Esperar que el usuario presione Enter antes de continuar
                return;
            }
            
            // Llamamos a la función de carga manual de productos
            string nombresMarcas[10]; // Array para esperar nombres de marcas (aumentado a 10)
            // Usamos el array global para nombres de productos
            float preciosVenta[20];
            float preciosCompra[20];
            int stockDisponible[20];
            int codigosMarcaProductos[20];
            
            // Preparar los arrays para la función
            int codigosMarcas[10]; // Aumentado a 10 para todas las marcas
            for (int i = 0; i < cantidadMarcas; i++) {
                codigosMarcas[i] = marcas[i].codigo;
            }
            
            cargarLoteProductos(codigosMarcas, nombresMarcas, cantidadMarcas,
                              codigosProductosGlobal, nombresProductosGlobal,
                              preciosVenta, preciosCompra, stockDisponible,
                              codigosMarcaProductos, cantidadProductos);
            
            // Asignar correctamente los valores a la estructura de productos
            for (int i = 0; i < cantidadProductos; i++) {
                // Los códigos ya están en codigosProductosGlobal desde cargarLoteProductos
                productos[i].codigo = codigosProductosGlobal[i];
                productos[i].precioVenta = preciosVenta[i];
                productos[i].precioCompra = preciosCompra[i];
                productos[i].stock = stockDisponible[i];
                productos[i].codigoMarca = codigosMarcaProductos[i];
            }
            
            cout << "\nLote de productos cargado exitosamente!" << endl;
            cout << "Total de productos cargados: " << cantidadProductos << endl;
            
            cout << "\nPresione Enter para continuar...";
            cin.ignore(); // Limpiar el buffer de entrada para evitar problemas con getline
            cin.get();    // Esperar que el usuario presione Enter antes de continuar
        } else if (opcion == 3) {
            // Llamamos a la función de carga manual de formas de pago
            string codigosFormasPago[5]; // Array temporal para códigos (aumentado a 5)
            string nombresFormasPago[5]; // Array temporal para nombres (aumentado a 5)
            int porcentajesFormasPago[5]; // Aumentado a 5
            
            cargarLoteFormasPago(codigosFormasPago, nombresFormasPago, 
                                porcentajesFormasPago, cantidadFormasPago);
            
            cout << "\nLote de formas de pago cargado exitosamente!" << endl;
            cout << "Total de formas de pago cargadas: " << cantidadFormasPago << endl;
            
            cout << "\nPresione Enter para continuar...";
            cin.ignore(); // Limpiar el buffer de entrada para evitar problemas con getline
            cin.get();    // Esperar que el usuario presione Enter antes de continuar
        } else if (opcion == 4) {
            // Verificar si hay productos y formas de pago cargadas
            if (cantidadProductos == 0) {
                cout << "\n===== CARGA DE LOTE DE VENTAS =====" << endl;
                cout << "Error: No hay productos cargados. Debe cargar el lote de productos primero." << endl;
                cout << "\nPresione Enter para continuar...";
                cin.ignore(); // Limpiar el buffer de entrada para evitar problemas con getline
                cin.get();    // Esperar que el usuario presione Enter antes de continuar
                continue;
            }
            
            if (cantidadFormasPago == 0) {
                cout << "\n===== CARGA DE LOTE DE VENTAS =====" << endl;
                cout << "Error: No hay formas de pago cargadas. Debe cargar el lote de formas de pago primero." << endl;
                cout << "\nPresione Enter para continuar...";
                cin.ignore(); // Limpiar el buffer de entrada para evitar problemas con getline
                cin.get();    // Esperar que el usuario presione Enter antes de continuar
                continue;
            }
            
            // Preparar los arrays para la función
            float preciosVenta[20];
            float preciosCompra[20];
            int stockDisponible[20];
            int codigosMarcaProductos[20];
            
            // Preparar los arrays para la función de ventas
            // Usamos los arrays globales que ya contienen los nombres y códigos
            // correctos desde la función cargarLoteProductos
            for (int i = 0; i < cantidadProductos; i++) {
                // No necesitamos copiar los códigos, ya están en codigosProductosGlobal
                preciosVenta[i] = productos[i].precioVenta;
                preciosCompra[i] = productos[i].precioCompra;
                stockDisponible[i] = productos[i].stock;
                codigosMarcaProductos[i] = productos[i].codigoMarca;
            }
            
            // Preparar los códigos de formas de pago
            string codigosFormasPago[5];
            for (int i = 0; i < 5; i++) {
                // Asignar los códigos estándar
                if (i == 0) codigosFormasPago[i] = "EF";
                else if (i == 1) codigosFormasPago[i] = "MP";
                else if (i == 2) codigosFormasPago[i] = "TR";
                else if (i == 3) codigosFormasPago[i] = "TC";
                else if (i == 4) codigosFormasPago[i] = "CT";
            }
            
            // Llamar a la función de carga de ventas con todos los datos de productos
            cargarLoteVentas(codigosProductosGlobal, cantidadProductos, codigosFormasPago, cantidadFormasPago,
                           nombresProductosGlobal, preciosVenta, preciosCompra, stockDisponible, codigosMarcaProductos,
                           ventas, cantidadVentas);
            
            cout << "\nPresione Enter para continuar...";
            cin.ignore(); // Limpiar el buffer de entrada para evitar problemas con getline
            cin.get();    // Esperar que el usuario presione Enter antes de continuar
        } else if (opcion == 5) {
            // Mostrar submenú de reportes
            cout << "\n===== REPORTES =====" << endl;
            
            // Verificar si hay datos cargados
            if (cantidadProductos == 0) {
                cout << "Error: No hay productos cargados. Debe cargar el lote de productos primero." << endl;
                cout << "\nPresione Enter para continuar...";
                cin.ignore(); // Limpiar el buffer de entrada para evitar problemas con getline
                cin.get();    // Esperar que el usuario presione Enter antes de continuar
            } else if (cantidadVentas == 0) {
                cout << "Error: No hay ventas registradas. Debe cargar el lote de ventas primero." << endl;
                cout << "\nPresione Enter para continuar...";
                cin.ignore(); // Limpiar el buffer de entrada para evitar problemas con getline
                cin.get();    // Esperar que el usuario presione Enter antes de continuar
            } else {
                // Preparar arrays de formas de pago para los reportes
                FormaPago formasPagoArray[5];
                int cantidadFormasPagoArray = 5;
                
                // Inicializar formas de pago estándar (solo porcentajes)
                formasPagoArray[0].porcentaje = 0;   // EF
                formasPagoArray[1].porcentaje = 5;   // MP  
                formasPagoArray[2].porcentaje = -2;  // TR
                formasPagoArray[3].porcentaje = 10;  // TC
                formasPagoArray[4].porcentaje = -1;  // CT
                
                // Llamar al submenú de reportes
                mostrarMenuReportes(productos, cantidadProductos, nombresProductosGlobal, 
                                  ventas, cantidadVentas, marcas, cantidadMarcas, 
                                  formasPagoArray, cantidadFormasPagoArray);
            }
        } else if (opcion == 0) {
            cout << "Saliendo del programa..." << endl;
            programaActivo = false; // Cambiamos a false para salir del bucle.
            return;
        } else {
            cout << "Opcion no implementada aun." << endl;
        }
    }
}

// Las funciones de carga de lotes se han simplificado y se manejan directamente en mostrarMenu()
