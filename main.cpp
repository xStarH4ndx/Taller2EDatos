#include <iostream>

using namespace std;

const int filas=6;
const int columnas=7;

void mostrarTablero(int tablero[filas][columnas]) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << tablero[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void menu() {
    int opcion;
    do {
        cout << "------CONECTA 4-----" << endl;
        cout << "Escoja una dificultad:" << endl;
        cout << "1) Facil" << endl;
        cout << "2) Normal" << endl;
        cout << "3) Dificil" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Dificultad: Facil" << endl;
                break;
            case 2:
                cout << "Dificultad: Medio" << endl;
                break;
            case 3:
                cout << "Dificultad: Dificil" << endl;
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
        }
    } while (opcion < 1 || opcion > 3); //El bucle continuará mientras la opción sea inválida
}


int main(){
    const int filas=6;
    const int columnas=7;
    //menu();

    // Inicializar el tablero
    string tablero[filas*columnas];

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            tablero[i * columnas + j] = " ";
        }
    }

    // Acceder y mostrar los elementos de la matriz
    std::cout << "Matriz:" << std::endl;
    for (int i = 0; i < filas; ++i) {
        cout<<"|";
        for (int j = 0; j < columnas; ++j) {
            cout << tablero[i * columnas + j]<<"|";
        }
        cout <<endl;
    }
    return 0;
};