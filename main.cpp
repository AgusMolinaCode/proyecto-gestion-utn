#include <iostream>
#include "funciones.h"

int main() {
    // Variables para el lote de marcas
    Marca marcas[10];
    int cantidadMarcas = 0;
    
    // Variables para el lote de productos
    Producto productos[20];
    int cantidadProductos = 0;
    // Arrays para mantener datos entre funciones
    string nombresProductosGlobal[20]; 
    int codigosProductosGlobal[20]; 
    
    // Variables para el lote de formas de pago
    FormaPago formasPago[5]; 
    int cantidadFormasPago = 0;
    
    // Variables para el lote de ventas
    Venta ventas[100]; 
    int cantidadVentas = 0;
    
    mostrarMenu(marcas, cantidadMarcas, productos, cantidadProductos,
                nombresProductosGlobal, codigosProductosGlobal,
                formasPago, cantidadFormasPago, ventas, cantidadVentas);
    
    return 0;
}
