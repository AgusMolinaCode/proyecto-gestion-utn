#include <iostream>
#include "funciones.h"
using namespace std;

// Función para mostrar reporte de promociones especiales
void mostrarReportePromocionesEspeciales(Producto productos[], int cantidadProductos,
                                        string nombresProductos[], Venta ventas[], int cantidadVentas,
                                        Marca marcas[], int cantidadMarcas) {
    cout << "\n===== REPORTE DE PROMOCIONES ESPECIALES =====" << endl;
    cout << "Cantidad de ventas que aplicaron promocion por marca y dinero descontado:" << endl;
    cout << "\nCODIGO | MARCA | VENTAS CON PROMOCION | DINERO DESCONTADO" << endl;
    cout << "-------|-------|---------------------|------------------" << endl;
    
    float totalDescontadoGeneral = 0;
    int totalVentasConPromocion = 0;
    
    // Recorrer cada marca
    for (int m = 0; m < cantidadMarcas; m++) {
        int ventasConPromocionMarca = 0;
        float dineroDescontadoMarca = 0;
        
        // Verificar si la marca tiene días especiales
        bool tienePromociones = false;
        for (int d = 0; d < 5; d++) {
            if (marcas[m].diasEspeciales[d] > 0) {
                tienePromociones = true;
                break;
            }
        }
        
        if (tienePromociones) {
            // Recorrer todas las ventas
            for (int v = 0; v < cantidadVentas; v++) {
                // Buscar el producto de esta venta
                for (int p = 0; p < cantidadProductos; p++) {
                    if (productos[p].codigo == ventas[v].codigoProducto && 
                        productos[p].codigoMarca == marcas[m].codigo) {
                        
                        // Verificar si el día de venta coincide con día especial
                        bool esPromocion = false;
                        for (int d = 0; d < 5; d++) {
                            if (marcas[m].diasEspeciales[d] == ventas[v].diaVenta) {
                                esPromocion = true;
                                break;
                            }
                        }
                        
                        if (esPromocion) {
                            ventasConPromocionMarca++;
                            // Calcular el descuento del 15%
                            float totalVenta = productos[p].precioVenta * ventas[v].cantidad;
                            float descuento = totalVenta * 0.15;
                            dineroDescontadoMarca += descuento;
                        }
                        break;
                    }
                }
            }
        }
        
        // Mostrar información de la marca (solo si tiene promociones)
        if (tienePromociones) {
            cout << "   " << marcas[m].codigo << "   |       | ";
            cout.width(19);
            cout << ventasConPromocionMarca << " | $";
            cout.precision(2);
            cout << fixed << dineroDescontadoMarca << endl;
            
            totalVentasConPromocion += ventasConPromocionMarca;
            totalDescontadoGeneral += dineroDescontadoMarca;
        }
    }
    
    cout << "-------|-------|---------------------|------------------" << endl;
    cout << "TOTAL  |       | ";
    cout.width(19);
    cout << totalVentasConPromocion << " | $";
    cout.precision(2);
    cout << fixed << totalDescontadoGeneral << endl;
    
    cout << "\n===== RESUMEN DE PROMOCIONES =====" << endl;
    cout << "Total de ventas con descuento especial: " << totalVentasConPromocion << endl;
    cout << "Total de dinero descontado por promociones: $" << totalDescontadoGeneral << endl;
    cout << "Porcentaje de descuento aplicado: 15%" << endl;
    
    cout << "\n===== FIN DEL REPORTE =====" << endl;
}
