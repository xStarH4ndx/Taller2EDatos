#include <iostream>
#include <vector>
using namespace std;

void menu();
void imprimirTablero(const vector<vector<char>>& tablero);
int main(){
    int filas=6;
    int columnas=7;
    //menu();

    // Inicializar el tablero
    vector<vector<char>> tablero(filas, vector<char>(columnas, 'X'));
    imprimirTablero(tablero);
    return 0;
};

void imprimirTablero(const vector<vector<char>>& tablero) {
    for (const auto& fila : tablero) {
        for (char c : fila) {
            cout << c << '|';
        }
        cout << endl;
    }
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
