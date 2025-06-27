#include <iostream>
#include <cstring>
#include "funciones.h"
using namespace std;

// Definimos una estructura para manejar los datos de cada forma de pago
struct FormaPagoTemp {
    string codigo; // Volvemos a usar string simple
    string nombre; // Volvemos a usar string simple
    int porcentaje;
};

void cargarLoteFormasPago(string codigosFormasPago[], string nombresFormasPago[], 
                          int porcentajesFormasPago[], int& cantidadFormasPago) {
    cout << "\n===== CARGA DE LOTE DE FORMAS DE PAGO =====" << endl;
    cout << "Se deben cargar 5 formas de pago en total." << endl;
    
    // Resetear el contador de formas de pago
    cantidadFormasPago = 0;
    
    // Códigos válidos para formas de pago
    string codigosValidos[5] = {"EF", "MP", "TR", "TC", "CT"};
    string nombresCodigosValidos[5] = {
        "Efectivo", 
        "Mercado Pago", 
        "Transferencia", 
        "Tarjeta de Credito", 
        "Criptomoneda"
    };
    
    // Array para rastrear qué códigos ya se han utilizado
    bool codigosUsados[5] = {false, false, false, false, false};
    
    // Cargar las 5 formas de pago
    for (int i = 0; i < 5; i++) {
        cout << "\nForma de Pago #" << (i + 1) << ":" << endl;
        
        // Usamos el struct para almacenar temporalmente los datos
        FormaPagoTemp formaPago;
        bool datosValidos = false;
        
        // Validar código de forma de pago
        while (!datosValidos) {
            cout << "Ingrese codigo de forma de pago (EF, MP, TR, TC, CT): ";
            cin >> formaPago.codigo;
            
            
            // Verificar si es un código válido
            int indiceCodigoValido = -1;
            for (int j = 0; j < 5; j++) {
                // Comparar códigos
                if (formaPago.codigo == codigosValidos[j]) {
                    indiceCodigoValido = j;
                    break;
                }
            }
            
            if (indiceCodigoValido == -1) {
                cout << "Error: Codigo de forma de pago no valido." << endl;
                continue;
            }
            
            // Verificar si ya se ha utilizado este código
            if (codigosUsados[indiceCodigoValido]) {
                cout << "Error: Este codigo de forma de pago ya ha sido utilizado." << endl;
                continue;
            }
            
            // Marcar el código como utilizado
            codigosUsados[indiceCodigoValido] = true;
            
            datosValidos = true;
        }
        
        // Validar porcentaje (puede ser negativo para descuento o positivo para interés)
        datosValidos = false;
        
        while (!datosValidos) {
            cout << "Ingrese porcentaje de descuento (-) o interes (+): ";
            cin >> formaPago.porcentaje;
            
            datosValidos = true;
        }
        
        // Guardar los datos de la forma de pago
        codigosFormasPago[cantidadFormasPago] = formaPago.codigo;
        
        // Encontrar el índice del código para obtener el nombre predeterminado
        int indiceNombre = -1;
        for (int j = 0; j < 5; j++) {
            if (formaPago.codigo == codigosValidos[j]) {
                indiceNombre = j;
                break;
            }
        }
        
        // Asignar el nombre predeterminado
        formaPago.nombre = nombresCodigosValidos[indiceNombre];
        nombresFormasPago[cantidadFormasPago] = formaPago.nombre;
        
        // Guardar el porcentaje
        porcentajesFormasPago[cantidadFormasPago] = formaPago.porcentaje;
        
        cantidadFormasPago++;
        
        cout << "Forma de pago registrada correctamente." << endl;
    }
    
    cout << "\nLote de formas de pago cargado exitosamente!" << endl;
    cout << "Total de formas de pago cargadas: " << cantidadFormasPago << endl;
    
    // Mostrar listado de formas de pago cargadas
    cout << "\nListado de formas de pago cargadas:" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "CODIGO | NOMBRE                | PORCENTAJE" << endl;
    cout << "-----------------------------------------------" << endl;
    
    for (int i = 0; i < cantidadFormasPago; i++) {
        cout << "  " << codigosFormasPago[i] << "    | " << nombresFormasPago[i];
        
        // Mostrar el porcentaje con signo (- para descuento, + para interés)
        if (porcentajesFormasPago[i] > 0) {
            cout << " | +" << porcentajesFormasPago[i] << "% (interes)" << endl;
        } else if (porcentajesFormasPago[i] < 0) {
            cout << " | " << porcentajesFormasPago[i] << "% (descuento)" << endl;
        } else {
            cout << " | " << porcentajesFormasPago[i] << "%" << endl;
        }
    }
    cout << "-----------------------------------------------" << endl;
}
