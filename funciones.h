#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
using namespace std;

// Definición de estructuras para simplificar el código
// Estructura para marcas
struct Marca {
    int codigo;
    // No almacenamos el nombre porque no podemos usar string ni matrices de char
};

// Estructura para productos
struct Producto {
    int codigo;
    // No almacenamos el nombre porque no podemos usar string ni matrices de char
    float precioVenta;
    float precioCompra;
    int stock;
    int codigoMarca;
};

// Estructura para formas de pago
struct FormaPago {
    // No almacenamos el código ni nombre porque no podemos usar string ni matrices de char
    int porcentaje;
};

// Estructura para ventas
struct Venta {
    int numeroCompra;
    int codigoProducto;
    int cantidad;
    int codigoFormaPago;
};

// Funciones principales
void mostrarMenu(Marca marcas[], int& cantidadMarcas, 
                 Producto productos[], int& cantidadProductos,
                 string nombresProductosGlobal[], int codigosProductosGlobal[],
                 FormaPago formasPago[], int& cantidadFormasPago,
                 Venta ventas[], int& cantidadVentas);

// Funciones de carga de lotes
void cargarLoteMarcas(int codigosMarcas[], string nombresMarcas[], int& cantidadMarcas);

void cargarLoteProductos(int codigosMarcas[], string nombresMarcas[], int cantidadMarcas, 
                       int codigosProductos[], string nombresProductos[], 
                       float preciosVenta[], float preciosCompra[], 
                       int stockDisponible[], int codigosMarcaProductos[], 
                       int& cantidadProductos);

void cargarLoteFormasPago(string codigosFormasPago[], string nombresFormasPago[], 
                        int porcentajesFormasPago[], int& cantidadFormasPago);

void cargarLoteVentas(int codigosProductos[], int cantidadProductos, 
                    string codigosFormasPago[], int cantidadFormasPago,
                    string nombresProductos[], float preciosVenta[], float preciosCompra[],
                    int stockDisponible[], int codigosMarcaProductos[],
                    Venta ventas[], int& cantidadVentas);

// Funciones de reportes
void mostrarMenuReportes(Producto productos[], int cantidadProductos,
                        string nombresProductos[], Venta ventas[], int cantidadVentas,
                        Marca marcas[], int cantidadMarcas, FormaPago formasPago[], int cantidadFormasPago);

void mostrarReporteRecaudacionPorProducto(Producto productos[], int cantidadProductos,
                                        string nombresProductos[], Venta ventas[], int cantidadVentas);

void mostrarReporteVentasPorMarca(Producto productos[], int cantidadProductos,
                                 string nombresProductos[], Venta ventas[], int cantidadVentas,
                                 Marca marcas[], int cantidadMarcas);

void mostrarReporteFormasPagoMasUsadas(Venta ventas[], int cantidadVentas,
                                      FormaPago formasPago[], int cantidadFormasPago);

void mostrarReporteProductosMasVendidos(Producto productos[], int cantidadProductos,
                                       string nombresProductos[], Venta ventas[], int cantidadVentas);

#endif
