#include <iostream>
#include <cstring>
#include "funciones.h"
using namespace std;

// Definimos una estructura para manejar los datos de cada producto
struct ProductoTemp {
    int codigo;
    string nombre; // Volvemos a usar string simple
    float precioVenta;
    float precioCompra;
    int stock;
    int codigoMarca;
};

void cargarLoteProductos(int codigosMarcas[], string nombresMarcas[], int cantidadMarcas, 
                         int codigosProductos[], string nombresProductos[], 
                         float preciosVenta[], float preciosCompra[], 
                         int stockDisponible[], int codigosMarcaProductos[], 
                         int& cantidadProductos) {
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
        
        // Usamos la estructura para almacenar temporalmente los datos
        ProductoTemp producto;
        bool datosValidos = false;
        
        // Limpiar el buffer de entrada antes de cada producto
        cin.ignore(0, '\n');
        
        // Validar código de producto (3 dígitos)
        while (!datosValidos) {
            cout << "Ingrese código de producto (3 dígitos): " << endl;
            
            cin >> producto.codigo;
            
            // Validar que sea un número de 3 dígitos
            if (producto.codigo < 100 || producto.codigo > 999) {
                cout << "Error: El código debe ser un número de 3 dígitos." << endl;
                continue;
            }
            
            // Validar que no exista ya
            bool codigoExiste = false;
            for (int j = 0; j < cantidadProductos; j++) {
                if (codigosProductos[j] == producto.codigo) {
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
        cin.ignore(10000, '\n'); // Limpiar el buffer antes de getline
        
        while (!datosValidos) {
            cout << "Ingrese nombre del producto:" << endl;
            getline(cin, producto.nombre);//encontrado en internet
            
            // Verificar si el nombre está vacío de forma simple
            if (producto.nombre == "") {
                cout << "Error: El nombre no puede estar vacio." << endl;
            } else {
                datosValidos = true;
            }
        }
        
        // Validar precio de venta
        datosValidos = false;
        
        while (!datosValidos) {
            cout << "Ingrese precio de venta:" << endl;
            cin >> producto.precioVenta; // Forma simple y directa
            
            // Validar que no sea cero o negativo
            if (producto.precioVenta <= 0) {
                cout << "Error: El precio de venta debe ser mayor que cero." << endl;
            } else {
                datosValidos = true;
            }
        }
        
        // Validar precio de compra
        datosValidos = false;
        
        while (!datosValidos) {
            cout << "Ingrese precio de compra:" << endl;
            cin >> producto.precioCompra; 
            
            if (producto.precioCompra <= 0) {
                cout << "Error: El precio de compra debe ser mayor que cero." << endl;
            } else {
                datosValidos = true;
            }
        }
        
        // Validar stock disponible
        datosValidos = false;
        
        while (!datosValidos) {
            cout << "Ingrese stock disponible:" << endl;
            cin >> producto.stock; // Forma simple y directa
            
            // Validar que no sea cero o negativo
            if (producto.stock <= 0) {
                cout << "Error: El stock debe ser mayor que cero." << endl;
            } else {
                datosValidos = true;
            }
        }
        
        // Validar código de marca
        datosValidos = false;
        
        while (!datosValidos) {
            cout << "Ingrese código de marca (1-10):" << endl;
            cin >> producto.codigoMarca; // Forma simple y directa
            
            // Validar que esté en el rango correcto
            if (producto.codigoMarca < 1 || producto.codigoMarca > 10) {
                cout << "Error: El código de marca debe estar entre 1 y 10." << endl;
            } else {
                // Validar que exista en el lote de marcas
                bool marcaExiste = false;
                for (int j = 0; j < cantidadMarcas; j++) {
                    if (codigosMarcas[j] == producto.codigoMarca) {
                        marcaExiste = true;
                        break;
                    }
                }
                
                if (!marcaExiste) {
                    cout << "Error: El código de marca no existe en el lote de marcas cargado." << endl;
                } else {
                    datosValidos = true;
                }
            }
        }
        
        // Guardar los datos del producto desde la estructura a los arreglos
        codigosProductos[cantidadProductos] = producto.codigo;
        nombresProductos[cantidadProductos] = producto.nombre;
        preciosVenta[cantidadProductos] = producto.precioVenta;
        preciosCompra[cantidadProductos] = producto.precioCompra;
        stockDisponible[cantidadProductos] = producto.stock;
        codigosMarcaProductos[cantidadProductos] = producto.codigoMarca;
        
        cantidadProductos++;
        
        cout << "Producto registrado correctamente." << endl;
        
        // Limpiar completamente el buffer de entrada después de cada producto
        cin.ignore(10000, '\n');
        cin.clear();
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
        int longitud = nombresProductos[i].length();
        
        for (int k = longitud; k < 22; k++) {
            cout << " ";
        }
        
        cout << "| " << preciosVenta[i] << "   | " << preciosCompra[i] << "    | " << stockDisponible[i] << "    | " << codigosMarcaProductos[i] << endl;
    }
    cout << "----------------------------------------------------------------------" << endl;
}
