#include <iostream>
#include <cstring>
#include "funciones.h"
using namespace std;

// Definimos una estructura para manejar los datos de cada marca
struct MarcaTemp {
    int codigo;
    string nombre; // Volvemos a usar string simple
};

void cargarLoteMarcas(Marca marcas[], string nombresMarcas[], int& cantidadMarcas) {
    cout << "\n===== CARGA DE LOTE DE MARCAS =====" << endl;
    cout << "Se deben cargar 10 marcas en total." << endl;
    
    cantidadMarcas = 0;
    
    // Array para rastrear qué códigos ya se han utilizado (1-10)
    bool codigosUsados[11] = {false}; // Índice 0 no se usa, 1-10 para los códigos
    
    for (int i = 0; i < 10; i++) {
        cout << "\nMarca #" << (i + 1) << ":" << endl;
        
        bool codigoValido = false;
        
        while (!codigoValido) {
            cout << "Ingrese codigo de marca (1-10): ";
            
            // Verificar si la entrada es un número
            if (!(cin >> marcas[i].codigo)) {
                cin.clear(); // Limpiar el estado de error
                cin.ignore(10000, '\n'); // Descartar la entrada inválida
                cout << "Error: Debe ingresar un número." << endl;
                continue;
            }
            
            if (marcas[i].codigo <= 0 || marcas[i].codigo > 10) {
                cout << "Error: El codigo debe estar entre 1 y 10." << endl;
            } else if (codigosUsados[marcas[i].codigo]) {
                cout << "Error: Ya existe una marca con ese codigo." << endl;
            } else {
                codigoValido = true;
                codigosUsados[marcas[i].codigo] = true;
            }
        }
        
        bool nombreValido = false;
        cin.ignore(10000, '\n'); // Limpiar el buffer antes de leer el nombre
        
        while (!nombreValido) {
            cout << "Ingrese nombre de la marca: ";
            getline(cin, nombresMarcas[i]);
            
            // Verificar si el nombre está vacío
            if (nombresMarcas[i].empty()) {
                cout << "Error: El nombre no puede estar vacio." << endl;
            } else {
                nombreValido = true;
            }
        }
        
        // Preguntar si tiene promociones especiales
        char tienePromociones;
        cout << "¿Tiene promociones especiales? (s/n): ";
        cin >> tienePromociones;
        
        // Inicializar días especiales con ceros
        for (int j = 0; j < 5; j++) {
            marcas[i].diasEspeciales[j] = 0;
        }
        
        if (tienePromociones == 's' || tienePromociones == 'S') {
            int cantidadDias;
            cout << "¿Cuántos días especiales? (1-5): ";
            cin >> cantidadDias;
            
            if (cantidadDias > 0 && cantidadDias <= 5) {
                cout << "Ingrese los días especiales (1-30) separados por espacios: ";
                for (int j = 0; j < cantidadDias; j++) {
                    cin >> marcas[i].diasEspeciales[j];
                }
            }
        }
        
        cantidadMarcas++;
        
        cout << "Marca registrada correctamente." << endl;
    }
    
    cout << "\nLote de marcas cargado exitosamente!" << endl;
    cout << "Total de marcas cargadas: " << cantidadMarcas << endl;
    
    cout << "\nListado de marcas cargadas:" << endl;
    cout << "-------------------------" << endl;
    cout << "CODIGO | NOMBRE | PROMOCIONES" << endl;
    cout << "-------------------------" << endl;
    
    for (int i = 0; i < cantidadMarcas; i++) {
        cout << "  " << marcas[i].codigo << "    | " << nombresMarcas[i];
        
        // Mostrar días especiales si los tiene
        bool tienePromociones = false;
        for (int j = 0; j < 5; j++) {
            if (marcas[i].diasEspeciales[j] > 0) {
                tienePromociones = true;
                break;
            }
        }
        
        if (tienePromociones) {
            cout << " | Días: ";
            for (int j = 0; j < 5; j++) {
                if (marcas[i].diasEspeciales[j] > 0) {
                    cout << marcas[i].diasEspeciales[j] << " ";
                }
            }
        } else {
            cout << " | Sin promociones";
        }
        
        cout << endl;
    }
    cout << "-------------------------" << endl;
}
