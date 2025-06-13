#include <iostream>
#include "funciones.h"
using namespace std;

int codigosMarcas[10];
char nombres[500];
int cantidadMarcas = 0;
bool programaActivo = true;

void mostrarMenu() {
    int opcion;

    while (programaActivo) {
        cout << "======= MENU PRINCIPAL =======" << endl;
        cout << "1. Cargar lote de marcas" << endl;
        cout << "2. Cargar lote de productos (no implementado)" << endl;
        cout << "3. Cargar lote de formas de pago (no implementado)" << endl;
        cout << "4. Cargar lote de ventas (no implementado)" << endl;
        cout << "5. Mostrar reportes (no implementado)" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cargarLoteMarcas();
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
        char nombreTemp[50];
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
            cin.getline(nombreTemp, 50);
            
            
            if (nombreTemp[0] == '\0') {
                cout << "Error: El nombre no puede estar vacio." << endl;
            } else {
                nombreValido = true;
            }
        }
        
        
        codigosMarcas[cantidadMarcas] = codigo;
        
        
        int posicionInicial = cantidadMarcas * 50;
        
        
        int j = 0;
        while (nombreTemp[j] != '\0' && j < 49) {
            nombres[posicionInicial + j] = nombreTemp[j];
            j++;
        }
        nombres[posicionInicial + j] = '\0'; // \0 es un caracter nulo
        
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
        cout << "  " << codigosMarcas[i] << "    | ";
        
        
        int posicionInicial = i * 50;
        int j = 0;
        while (nombres[posicionInicial + j] != '\0' && j < 50) {
            cout << nombres[posicionInicial + j];
            j++;
        }
        
        cout << endl;
    }
    cout << "-------------------------" << endl;
}
