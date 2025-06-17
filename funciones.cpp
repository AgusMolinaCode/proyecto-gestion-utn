#include <iostream>
#include <string>
#include "funciones.h"
using namespace std;

// Variables para el lote de marcas
int codigosMarcas[10];
string nombresMarcas[10]; // Array de strings para los nombres de las marcas
int cantidadMarcas = 0;
bool programaActivo = true;

// Variables para el lote de productos
int codigosProductos[20];
string nombresProductos[20]; // Array de strings para los nombres de productos, lo cambiamos por los de char
float preciosVenta[20];
float preciosCompra[20];
int stockDisponible[20];
int codigosMarcaProductos[20];
int cantidadProductos = 0;

void mostrarMenu() {
    int opcion;

    while (programaActivo) {
        cout << "======= MENU PRINCIPAL =======" << endl;
        cout << "1. Cargar lote de marcas" << endl;
        cout << "2. Cargar lote de productos" << endl;
        cout << "3. Cargar lote de formas de pago (no implementado)" << endl;
        cout << "4. Cargar lote de ventas (no implementado)" << endl;
        cout << "5. Mostrar reportes (no implementado)" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cargarLoteMarcas();
        } else if (opcion == 2) {
            cargarLoteProductos();
        } else if (opcion == 0) {
            cout << "Saliendo del programa..." << endl;
            programaActivo = false; // Cambiamos a false para salir del bucle.
            return;
        } else {
            cout << "Opcion no implementada aun." << endl;
        }
    }
}

void cargarLoteMarcas() {
    cout << "\n===== CARGA DE LOTE DE MARCAS =====" << endl;
    cout << "Se deben cargar 10 marcas en total." << endl;
    
    
    cantidadMarcas = 0;
    
    
    for (int i = 0; i < 10; i++) {
        cout << "\nMarca #" << (i + 1) << ":" << endl;
        
        int codigo;
        string nombreTemp; // Ahora usamos string en lugar de char[]
        bool codigoValido = false;
        
        
        while (!codigoValido) {
            cout << "Ingrese codigo de marca (1-10): ";
            cin >> codigo;
            
            if (codigo <= 0 || codigo > 10) {
                cout << "Error: El codigo debe estar entre 1 y 10." << endl;
            } else {
                
                bool codigoExiste = false;
                for (int j = 0; j < cantidadMarcas; j++) {
                    if (codigosMarcas[j] == codigo) {
                        codigoExiste = true;
                        break;
                    }
                }
                
                if (codigoExiste) {
                    cout << "Error: Ya existe una marca con ese codigo." << endl;
                } else {
                    codigoValido = true;
                }
            }
        }
        
        
        bool nombreValido = false;
        cin.ignore();
        
        while (!nombreValido) {
            cout << "Ingrese nombre de la marca: ";
            getline(cin, nombreTemp); // Usamos getline para string
            
            if (nombreTemp.empty()) { // Verificamos si está vacío
                cout << "Error: El nombre no puede estar vacio." << endl;
            } else {
                nombreValido = true;
            }
        }
        
        
        codigosMarcas[cantidadMarcas] = codigo;
        nombresMarcas[cantidadMarcas] = nombreTemp; // Simplemente asignamos el string
        
        cantidadMarcas++;
        
        cout << "Marca registrada correctamente." << endl;
    }
    
    cout << "\nLote de marcas cargado exitosamente!" << endl;
    cout << "Total de marcas cargadas: " << cantidadMarcas << endl;
    
    
    cout << "\nListado de marcas cargadas:" << endl;
    cout << "-------------------------" << endl;
    cout << "CODIGO | NOMBRE" << endl;
    cout << "-------------------------" << endl;
    
    for (int i = 0; i < cantidadMarcas; i++) {
        cout << "  " << codigosMarcas[i] << "    | " << nombresMarcas[i]; // Imprimimos directamente el string
        
        cout << endl;
    }
    cout << "-------------------------" << endl;
}

void cargarLoteProductos() {
    cout << "\n===== CARGA DE LOTE DE PRODUCTOS =====" << endl;
    cout << "Se deben cargar 20 productos en total." << endl;
    
    // Verificar si hay marcas cargadas
    if (cantidadMarcas == 0) {
        cout << "Error: No hay marcas cargadas. Debe cargar el lote de marcas primero." << endl;
        return;
    }
    
    // Resetear el contador de productos
    cantidadProductos = 0;
    
    // Cargar los 20 productos
    for (int i = 0; i < 20; i++) {
        cout << "\nProducto #" << (i + 1) << ":" << endl;
        
        // Variables temporales
        int codigo;
        string nombreTemp; // Usamos string en lugar de char[]
        float precioVenta;
        float precioCompra;
        int stock;
        int codigoMarca;
        bool datosValidos = false;
        
        // Validar código de producto (3 dígitos, no consecutivos)
        while (!datosValidos) {
            cout << "Ingrese código de producto (3 dígitos): ";
            cin >> codigo;
            
            // Validar que sea un número de 3 dígitos
            if (codigo < 100 || codigo > 999) {
                cout << "Error: El código debe ser un número de 3 dígitos." << endl;
                continue;
            }
            
            // Validar que no exista ya
            bool codigoExiste = false;
            for (int j = 0; j < cantidadProductos; j++) {
                if (codigosProductos[j] == codigo) {
                    codigoExiste = true;
                    break;
                }
            }
            
            if (codigoExiste) {
                cout << "Error: Ya existe un producto con ese código." << endl;
                continue;
            }
            
            datosValidos = true;
        }
        
        // Validar nombre
        datosValidos = false;
        cin.ignore();
        
        while (!datosValidos) {
            cout << "Ingrese nombre del producto: ";
            getline(cin, nombreTemp); // Usamos getline para string
            
            datosValidos = true;
        }
        
        // Validar precio de venta
        datosValidos = false;
        
        while (!datosValidos) {
            cout << "Ingrese precio de venta: ";
            cin >> precioVenta;
            
            // Validar que no sea cero o negativo
            if (precioVenta <= 0) {
                cout << "Error: El precio de venta debe ser mayor que cero." << endl;
                continue;
            }
            
            datosValidos = true;
        }
        
        // Validar precio de compra
        datosValidos = false;
        
        while (!datosValidos) {
            cout << "Ingrese precio de compra: ";
            cin >> precioCompra;
            
            // Validar que no sea cero o negativo
            if (precioCompra <= 0) {
                cout << "Error: El precio de compra debe ser mayor que cero." << endl;
                continue;
            }
            
            datosValidos = true;
        }
        
        // Validar stock disponible
        datosValidos = false;
        
        while (!datosValidos) {
            cout << "Ingrese stock disponible: ";
            cin >> stock;
            
            // Validar que no sea cero o negativo
            if (stock <= 0) {
                cout << "Error: El stock debe ser mayor que cero." << endl;
                continue;
            }
            
            datosValidos = true;
        }
        
        // Validar código de marca
        datosValidos = false;
        
        while (!datosValidos) {
            cout << "Ingrese código de marca (1-10): ";
            cin >> codigoMarca;
            
            // Validar que esté en el rango correcto
            if (codigoMarca < 1 || codigoMarca > 10) {
                cout << "Error: El código de marca debe estar entre 1 y 10." << endl;
                continue;
            }
            
            // Validar que exista en el lote de marcas
            bool marcaExiste = false;
            for (int j = 0; j < cantidadMarcas; j++) {
                if (codigosMarcas[j] == codigoMarca) {
                    marcaExiste = true;
                    break;
                }
            }
            
            if (!marcaExiste) {
                cout << "Error: Código de marca no encontrado en el lote de marcas." << endl;
                return; // Interrumpir la carga y volver al menú principal
            }
            
            datosValidos = true;
        }
        
        // Guardar los datos del producto
        codigosProductos[cantidadProductos] = codigo;
        nombresProductos[cantidadProductos] = nombreTemp; // aca asignamos el string
        
        preciosVenta[cantidadProductos] = precioVenta;
        preciosCompra[cantidadProductos] = precioCompra;
        stockDisponible[cantidadProductos] = stock;
        codigosMarcaProductos[cantidadProductos] = codigoMarca;
        
        cantidadProductos++;
        
        cout << "Producto registrado correctamente." << endl;
    }
    
    cout << "\nLote de productos cargado exitosamente!" << endl;
    cout << "Total de productos cargados: " << cantidadProductos << endl;
    
    // Mostrar listado de productos cargados
    cout << "\nListado de productos cargados:" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "CÓDIGO | NOMBRE                | P.VENTA | P.COMPRA | STOCK | COD.MARCA" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    
    for (int i = 0; i < cantidadProductos; i++) {
        cout << "  " << codigosProductos[i] << "   | " << nombresProductos[i];
        
        // Rellenar con espacios para alinear la tabla
        for (int k = nombresProductos[i].length(); k < 22; k++) {
            cout << " ";
        }
        
        cout << "| " << preciosVenta[i] << "   | " << preciosCompra[i] << "    | " << stockDisponible[i] << "    | " << codigosMarcaProductos[i] << endl;
    }
    cout << "----------------------------------------------------------------------" << endl;
}
