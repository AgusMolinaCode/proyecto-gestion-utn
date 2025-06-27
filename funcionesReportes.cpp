#include <iostream>
#include "funciones.h"
using namespace std;

void mostrarMenuReportes(Producto productos[], int cantidadProductos,
                        string nombresProductos[], Venta ventas[], int cantidadVentas,
                        Marca marcas[], int cantidadMarcas, FormaPago formasPago[], int cantidadFormasPago) {
    int opcion;
    bool menuActivo = true;
    
    while (menuActivo) {
        cout << "\n===== MENU DE REPORTES =====" << endl;
        cout << "1. Recaudacion por producto" << endl;
        cout << "2. Ventas por marca" << endl;
        cout << "3. Formas de pago mas usadas" << endl;
        cout << "4. Productos mas vendidos" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        if (opcion == 1) {
            mostrarReporteRecaudacionPorProducto(productos, cantidadProductos, nombresProductos, ventas, cantidadVentas);
        } else if (opcion == 2) {
            mostrarReporteVentasPorMarca(productos, cantidadProductos, nombresProductos, ventas, cantidadVentas, marcas, cantidadMarcas);
        } else if (opcion == 3) {
            mostrarReporteFormasPagoMasUsadas(ventas, cantidadVentas, formasPago, cantidadFormasPago);
        } else if (opcion == 4) {
            mostrarReporteProductosMasVendidos(productos, cantidadProductos, nombresProductos, ventas, cantidadVentas);
        } else if (opcion == 0) {
            menuActivo = false;
        } else {
            cout << "Opcion no valida. Intente nuevamente." << endl;
        }
        
        if (opcion != 0 && opcion >= 1 && opcion <= 4) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    }
}

void mostrarReporteRecaudacionPorProducto(Producto productos[], int cantidadProductos,
                                        string nombresProductos[], Venta ventas[], int cantidadVentas) {
    cout << "\n===== REPORTE DE RECAUDACION POR PRODUCTO =====" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "CODIGO | NOMBRE           | TOTAL RECAUDADO | CANTIDAD | STOCK" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    // Arrays para almacenar datos calculados por producto
    int codigosReporte[20];
    string nombresReporte[20];
    float totalRecaudado[20];
    int cantidadVendida[20];
    int stockRemanente[20];
    int productosConVentas = 0;
    
    // Inicializar arrays
    for (int i = 0; i < 20; i++) {
        codigosReporte[i] = 0;
        nombresReporte[i] = "";
        totalRecaudado[i] = 0.0;
        cantidadVendida[i] = 0;
        stockRemanente[i] = 0;
    }
    
    // Calcular datos por cada producto que tiene ventas
    for (int i = 0; i < cantidadProductos; i++) {
        int codigoProducto = productos[i].codigo;
        float precioVenta = productos[i].precioVenta;
        int stockActual = productos[i].stock;
        string nombreProducto = nombresProductos[i];
        
        // Calcular total vendido y recaudado para este producto
        int totalVendido = 0;
        float totalDinero = 0.0;
        
        for (int j = 0; j < cantidadVentas; j++) {
            if (ventas[j].codigoProducto == codigoProducto) {
                totalVendido += ventas[j].cantidad;
                totalDinero += ventas[j].cantidad * precioVenta;
            }
        }
        
        // Solo agregar productos que tienen ventas
        if (totalVendido > 0) {
            codigosReporte[productosConVentas] = codigoProducto;
            nombresReporte[productosConVentas] = nombreProducto;
            totalRecaudado[productosConVentas] = totalDinero;
            cantidadVendida[productosConVentas] = totalVendido;
            stockRemanente[productosConVentas] = stockActual;
            productosConVentas++;
        }
    }
    
    // Ordenamiento por cantidad vendida (de mayor a menor)
    for (int i = 0; i < productosConVentas - 1; i++) {
        for (int j = 0; j < productosConVentas - 1 - i; j++) {
            if (cantidadVendida[j] < cantidadVendida[j + 1]) {
                // Intercambiar todos los datos
                int tempCodigo = codigosReporte[j];
                codigosReporte[j] = codigosReporte[j + 1];
                codigosReporte[j + 1] = tempCodigo;
                
                string tempNombre = nombresReporte[j];
                nombresReporte[j] = nombresReporte[j + 1];
                nombresReporte[j + 1] = tempNombre;
                
                float tempRecaudado = totalRecaudado[j];
                totalRecaudado[j] = totalRecaudado[j + 1];
                totalRecaudado[j + 1] = tempRecaudado;
                
                int tempCantidad = cantidadVendida[j];
                cantidadVendida[j] = cantidadVendida[j + 1];
                cantidadVendida[j + 1] = tempCantidad;
                
                int tempStock = stockRemanente[j];
                stockRemanente[j] = stockRemanente[j + 1];
                stockRemanente[j + 1] = tempStock;
            }
        }
    }
    
    // Mostrar el reporte ordenado
    for (int i = 0; i < productosConVentas; i++) {
        cout << "  " << codigosReporte[i] << "   | " << nombresReporte[i];
        cout << " | $" << totalRecaudado[i];
        cout << "        | " << cantidadVendida[i];
        cout << "      | " << stockRemanente[i] << endl;
    }
    
    cout << "---------------------------------------------------------------" << endl;
    cout << "Total de productos con ventas: " << productosConVentas << endl;
    
    if (productosConVentas == 0) {
        cout << "No hay ventas registradas para mostrar el reporte." << endl;
    }
}

void mostrarReporteVentasPorMarca(Producto productos[], int cantidadProductos,
                                 string nombresProductos[], Venta ventas[], int cantidadVentas,
                                 Marca marcas[], int cantidadMarcas) {
    cout << "\n===== REPORTE DE VENTAS POR MARCA =====" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "MARCA | PRODUCTOS VENDIDOS | TOTAL RECAUDADO" << endl;
    cout << "-----------------------------------------------" << endl;
    
    // Arrays para datos por marca
    int codigosMarca[10];
    int productosVendidosPorMarca[10];
    float recaudadoPorMarca[10];
    int marcasConVentas = 0;
    
    // Inicializar arrays
    for (int i = 0; i < 10; i++) {
        codigosMarca[i] = 0;
        productosVendidosPorMarca[i] = 0;
        recaudadoPorMarca[i] = 0.0;
    }
    
    // Calcular ventas por marca
    for (int i = 0; i < cantidadMarcas; i++) {
        int codigoMarca = marcas[i].codigo;
        int totalProductosVendidos = 0;
        float totalRecaudado = 0.0;
        
        // Buscar productos de esta marca y sus ventas
        for (int j = 0; j < cantidadProductos; j++) {
            if (productos[j].codigoMarca == codigoMarca) {
                // Contar ventas de este producto
                for (int k = 0; k < cantidadVentas; k++) {
                    if (ventas[k].codigoProducto == productos[j].codigo) {
                        totalProductosVendidos += ventas[k].cantidad;
                        totalRecaudado += ventas[k].cantidad * productos[j].precioVenta;
                    }
                }
            }
        }
        
        // Solo agregar marcas con ventas
        if (totalProductosVendidos > 0) {
            codigosMarca[marcasConVentas] = codigoMarca;
            productosVendidosPorMarca[marcasConVentas] = totalProductosVendidos;
            recaudadoPorMarca[marcasConVentas] = totalRecaudado;
            marcasConVentas++;
        }
    }
    
    // Mostrar resultados
    for (int i = 0; i < marcasConVentas; i++) {
        cout << "  " << codigosMarca[i] << "   |        " << productosVendidosPorMarca[i];
        cout << "         | $" << recaudadoPorMarca[i] << endl;
    }
    
    cout << "-----------------------------------------------" << endl;
    cout << "Total de marcas con ventas: " << marcasConVentas << endl;
    
    if (marcasConVentas == 0) {
        cout << "No hay ventas registradas para mostrar el reporte." << endl;
    }
}

void mostrarReporteFormasPagoMasUsadas(Venta ventas[], int cantidadVentas,
                                      FormaPago formasPago[], int cantidadFormasPago) {
    cout << "\n===== REPORTE DE FORMAS DE PAGO MAS USADAS =====" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "FORMA DE PAGO | CANTIDAD DE USOS | PORCENTAJE" << endl;
    cout << "-----------------------------------------------" << endl;
    
    // Códigos de formas de pago estándar
    string codigosFormaPago[5] = {"EF", "MP", "TR", "TC", "CT"};
    string nombresFormaPago[5] = {"Efectivo", "MercadoPago", "Transferencia", "Tarjeta Credito", "Cuenta Corriente"};
    int usosPorFormaPago[5] = {0, 0, 0, 0, 0};
    
    // Contar usos de cada forma de pago
    for (int i = 0; i < cantidadVentas; i++) {
        int codigoFormaPago = ventas[i].codigoFormaPago;
        
        // Mapear código numérico a índice (1=EF, 2=MP, 3=TR, 4=TC, 5=CT)
        if (codigoFormaPago >= 1 && codigoFormaPago <= 5) {
            usosPorFormaPago[codigoFormaPago - 1]++;
        }
    }
    
    // Mostrar resultados
    for (int i = 0; i < 5; i++) {
        if (usosPorFormaPago[i] > 0) {
            float porcentaje = (float)usosPorFormaPago[i] / cantidadVentas * 100;
            cout << "     " << codigosFormaPago[i] << "      |        " << usosPorFormaPago[i];
            cout << "        |   " << porcentaje << "%" << endl;
        }
    }
    
    cout << "-----------------------------------------------" << endl;
    cout << "Total de ventas analizadas: " << cantidadVentas << endl;
    
    if (cantidadVentas == 0) {
        cout << "No hay ventas registradas para mostrar el reporte." << endl;
    }
}

void mostrarReporteProductosMasVendidos(Producto productos[], int cantidadProductos,
                                       string nombresProductos[], Venta ventas[], int cantidadVentas) {
    cout << "\n===== REPORTE DE PRODUCTOS MAS VENDIDOS =====" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "CODIGO | NOMBRE           | CANTIDAD VENDIDA" << endl;
    cout << "-----------------------------------------------" << endl;
    
    // Arrays para almacenar datos
    int codigosReporte[20];
    string nombresReporte[20];
    int cantidadVendida[20];
    int productosConVentas = 0;
    
    // Calcular cantidad vendida por producto
    for (int i = 0; i < cantidadProductos; i++) {
        int codigoProducto = productos[i].codigo;
        string nombreProducto = nombresProductos[i];
        int totalVendido = 0;
        
        // Contar ventas de este producto
        for (int j = 0; j < cantidadVentas; j++) {
            if (ventas[j].codigoProducto == codigoProducto) {
                totalVendido += ventas[j].cantidad;
            }
        }
        
        // Solo agregar productos con ventas
        if (totalVendido > 0) {
            codigosReporte[productosConVentas] = codigoProducto;
            nombresReporte[productosConVentas] = nombreProducto;
            cantidadVendida[productosConVentas] = totalVendido;
            productosConVentas++;
        }
    }
    
    // Ordenar por cantidad vendida (de mayor a menor)
    for (int i = 0; i < productosConVentas - 1; i++) {
        for (int j = 0; j < productosConVentas - 1 - i; j++) {
            if (cantidadVendida[j] < cantidadVendida[j + 1]) {
                // Intercambiar datos
                int tempCodigo = codigosReporte[j];
                codigosReporte[j] = codigosReporte[j + 1];
                codigosReporte[j + 1] = tempCodigo;
                
                string tempNombre = nombresReporte[j];
                nombresReporte[j] = nombresReporte[j + 1];
                nombresReporte[j + 1] = tempNombre;
                
                int tempCantidad = cantidadVendida[j];
                cantidadVendida[j] = cantidadVendida[j + 1];
                cantidadVendida[j + 1] = tempCantidad;
            }
        }
    }
    
    // Mostrar resultados
    for (int i = 0; i < productosConVentas; i++) {
        cout << "  " << codigosReporte[i] << "   | " << nombresReporte[i];
        cout << " |        " << cantidadVendida[i] << endl;
    }
    
    cout << "-----------------------------------------------" << endl;
    cout << "Total de productos con ventas: " << productosConVentas << endl;
    
    if (productosConVentas == 0) {
        cout << "No hay ventas registradas para mostrar el reporte." << endl;
    }
}
