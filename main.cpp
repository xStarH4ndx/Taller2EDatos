#include <iostream>
#include <climits>
#include "Nodo.h"//acá estan las filas y columnas constantes
using namespace std;


/*
//MINIMAX SIN LA UTILIZACIÓN DE PODA ALFA-BETA
int miniMaxSIN(Nodo* nodo, int profundidad, bool esMaximizador) {
    if (profundidad == 0 //u otro criterio de parada) {
        // Calcula y asigna la puntuación del nodo
        return nodo->valor;
    }

    if (esMaximizador) {
        int maxEval = INT_MIN;
        for (int i = 0; i < columnas; ++i) {
            Nodo* hijo = nodo->hijos[i];
            int eval = miniMaxSIN(hijo, profundidad - 1, false);
            maxEval = max(maxEval, eval);
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;
        for (int i = 0; i < columnas; ++i) {
            Nodo* hijo = nodo->hijos[i];
            int eval = miniMaxSIN(hijo, profundidad - 1, true);
            minEval = min(minEval, eval);
        }
        return minEval;
    }
}
*/

//MINIMAX CON LA UTILIZACIÓN DE PODA ALFA-BETA
int minimax(Nodo* nodo, int profundidad, bool esMaximizador, int alpha, int beta) {
    if (profundidad == 0 /* u otro criterio de parada */) {
        // Calcula y asigna la puntuación del nodo
        return nodo->valor;
    }

    if (esMaximizador) {
        int maxEval = INT_MIN;
        for (int i = 0; i < columnas; ++i) {
            Nodo* hijo = nodo->hijos[i];
            int eval = minimax(hijo, profundidad - 1, false, alpha, beta);
            maxEval = max(maxEval, eval);
            alpha = max(alpha, eval);
            if (beta <= alpha) {
                break;  // Poda alfa-beta
            }
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;
        for (int i = 0; i < columnas; ++i) {
            Nodo* hijo = nodo->hijos[i];
            int eval = minimax(hijo, profundidad - 1, true, alpha, beta);
            minEval = min(minEval, eval);
            beta = min(beta, eval);
            if (beta <= alpha) {
                break;  // Poda alfa-beta
            }
        }
        return minEval;
    }
}



void mostrarTablero(string tablero[filas][columnas]) {
    for (int i = 0; i < filas; ++i) {
        cout<<"|";
        for (int j = 0; j < columnas; ++j) {
            cout << tablero[i][j] << "|";
        }
        cout<<endl;
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

int main(){
    Nodo* raiz = new Nodo();//caso inicial (todo vacío)

    // Acceder al tablero de la raíz
    raiz->tablero[0][0] = "X";
    // Generar hijos del nodo raíz
    raiz->generarHijos(1);  // Supongamos que el jugador actual es el jugador 1

    // Mostrar el tablero del nodo raíz
    raiz->mostrarTablero();

    // Liberar la memoria
    delete raiz;

    return 0;
};