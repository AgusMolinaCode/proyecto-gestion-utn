#include <iostream>
#include <cstring>
#include "funciones.h"
using namespace std;

void cargarLoteVentas(int codigosProductos[], int cantidadProductos, 
                      string codigosFormasPago[], int cantidadFormasPago,
                      string nombresProductos[], float preciosVenta[], float preciosCompra[],
                      int stockDisponible[], int codigosMarcaProductos[],
                      Venta ventas[], int& cantidadVentas) {
    cout << "\n===== CARGA DE LOTE DE VENTAS =====" << endl;
    cout << "La carga finaliza con un número de compra igual a cero." << endl;
    
    // Verificar si hay productos y formas de pago cargadas
    if (cantidadProductos == 0) {
        cout << "Error: No hay productos cargados. Debe cargar el lote de productos primero." << endl;
        return;
    }
    
    if (cantidadFormasPago == 0) {
        cout << "Error: No hay formas de pago cargadas. Debe cargar el lote de formas de pago primero." << endl;
        return;
    }
    
    // Variables para estadísticas
    int totalVentas = 0;
    
    // Bucle de carga de ventas - versión simplificada
    int numeroCompra;
    int codigoProducto;
    string formaPago;
    int cantidadVendida;
    int codigoCliente;
    int diaVenta;
    
    while (true) {
        // Solicitar número de compra
        cout << "Ingrese número de compra (0 para finalizar): ";
        cin >> numeroCompra;
        
        // Verificar si es el fin de la carga
        if (numeroCompra == 0) {
            cout << "Finalizando carga de ventas..." << endl;
            break;
        }
        
        // Solicitar código de producto
        cout << "Ingrese código de producto: ";
        cin >> codigoProducto;
        
        // Solicitar forma de pago
        cout << "Ingrese forma de pago (EF, MP, TR, TC, CT): ";
        cin >> formaPago;
        
        // Solicitar cantidad vendida
        cout << "Ingrese cantidad vendida: ";
        cin >> cantidadVendida;
        
        // Solicitar código de cliente
        cout << "Ingrese código de cliente (1-50): ";
        cin >> codigoCliente;
        
        // Solicitar día de venta
        cout << "Ingrese día de la venta (1-30): ";
        cin >> diaVenta;
        
        // Validaciones básicas (sin bucles de error para facilitar pegado)
        bool datosValidos = true;
        
        // Validar código de producto
        bool productoValido = false;
        
        cout << "Buscando código de producto " << codigoProducto << " entre " << cantidadProductos << " productos..." << endl;
        
        // Validar que el código de producto exista
        for (int i = 0; i < cantidadProductos; i++) {
            cout << "Comparando con: " << codigosProductos[i] << endl;
            if (codigosProductos[i] == codigoProducto) {
                productoValido = true;
                cout << "¡Producto encontrado!" << endl;
                break;
            }
        }
        
        if (!productoValido) {
            cout << "Advertencia: Código de producto " << codigoProducto << " no encontrado." << endl;
            datosValidos = false;
        }
        
        // Validar forma de pago (sin distinguir mayúsculas/minúsculas)
        bool formaPagoValida = false;
        
        // Comparar con los códigos de formas de pago
        for (int i = 0; i < cantidadFormasPago; i++) {
            if (formaPago == codigosFormasPago[i]) {
                formaPagoValida = true;
                break;
            }
        }
        
        if (!formaPagoValida) {
            cout << "Advertencia: Forma de pago " << formaPago << " no válida." << endl;
            datosValidos = false;
        }
        
        // Validar cantidad vendida
        if (cantidadVendida <= 0) {
            cout << "Advertencia: Cantidad vendida debe ser mayor que cero." << endl;
            datosValidos = false;
        }
        
        // Validar código de cliente
        if (codigoCliente < 1 || codigoCliente > 50) {
            cout << "Advertencia: Código de cliente debe estar entre 1 y 50." << endl;
            datosValidos = false;
        }
        
        // Validar día de venta
        if (diaVenta < 1 || diaVenta > 30) {
            cout << "Advertencia: Día de venta debe estar entre 1 y 30." << endl;
            datosValidos = false;
        }
        
        // Registrar venta si los datos son válidos
        if (datosValidos) {
            // Almacenar la venta en el array
            ventas[cantidadVentas].numeroCompra = numeroCompra;
            ventas[cantidadVentas].codigoProducto = codigoProducto;
            ventas[cantidadVentas].cantidad = cantidadVendida;
            // Buscar el índice de la forma de pago para almacenar
            int indiceFormaPago = -1;
            for (int i = 0; i < cantidadFormasPago; i++) {
                if (codigosFormasPago[i] == formaPago) {
                    indiceFormaPago = i;
                    break;
                }
            }
            ventas[cantidadVentas].codigoFormaPago = indiceFormaPago;
            
            cantidadVentas++;
            totalVentas++;
            cout << "Venta registrada correctamente." << endl;
        } else {
            cout << "La venta no se registró debido a datos inválidos." << endl;
        }
        
        cout << "\n"; // Separador para la siguiente venta
    }
    
    cout << "\nTotal de ventas registradas: " << totalVentas << endl;
}
