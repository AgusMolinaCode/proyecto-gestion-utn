#include <iostream>
#include <cstring>
#include "funciones.h"
using namespace std;

// Definimos una estructura para manejar los datos de cada marca
struct MarcaTemp {
    int codigo;
    string nombre; // Volvemos a usar string simple
};

void cargarLoteMarcas(int codigosMarcas[], string nombresMarcas[], int& cantidadMarcas) {
    cout << "\n===== CARGA DE LOTE DE MARCAS =====" << endl;
    cout << "Se deben cargar 10 marcas en total." << endl;
    
    cantidadMarcas = 0;
    
    // Array para rastrear qué códigos ya se han utilizado (1-10)
    bool codigosUsados[11] = {false}; // Índice 0 no se usa, 1-10 para los códigos
    
    for (int i = 0; i < 10; i++) {
        cout << "\nMarca #" << (i + 1) << ":" << endl;
        
        // Usamos la estructura para almacenar temporalmente los datos
        MarcaTemp marca;
        bool codigoValido = false;
        
        while (!codigoValido) {
            cout << "Ingrese codigo de marca (1-10): ";
            
            // Verificar si la entrada es un número
            if (!(cin >> marca.codigo)) {
                cin.clear(); // Limpiar el estado de error
                cin.ignore(10000, '\n'); // Descartar la entrada inválida
                cout << "Error: Debe ingresar un número." << endl;
                continue;
            }
            
            if (marca.codigo <= 0 || marca.codigo > 10) {
                cout << "Error: El codigo debe estar entre 1 y 10." << endl;
            } else if (codigosUsados[marca.codigo]) {
                cout << "Error: Ya existe una marca con ese codigo." << endl;
            } else {
                codigoValido = true;
                codigosUsados[marca.codigo] = true;
            }
        }
        
        bool nombreValido = false;
        cin.ignore(10000, '\n'); // Limpiar el buffer antes de leer el nombre
        
        while (!nombreValido) {
            cout << "Ingrese nombre de la marca: ";
            getline(cin, marca.nombre);
            
            // Verificar si el nombre está vacío
            if (marca.nombre.empty()) {
                cout << "Error: El nombre no puede estar vacio." << endl;
            } else {
                nombreValido = true;
            }
        }
        
        // Transferimos los datos de la estructura a los arreglos
        // Usamos el índice i en lugar de cantidadMarcas para evitar problemas de acceso a memoria
        codigosMarcas[i] = marca.codigo;
        nombresMarcas[i] = marca.nombre;
        
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
        cout << "  " << codigosMarcas[i] << "    | " << nombresMarcas[i];
        cout << endl;
    }
    cout << "-------------------------" << endl;
}
