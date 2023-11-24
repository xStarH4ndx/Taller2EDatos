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

// Función para realizar el movimiento de la máquina en el nivel fácil
void realizarMovimientoFacil(Nodo* nodo) {
    // Lógica para el nivel fácil
    // Por ejemplo, selección aleatoria de una columna disponible
    int columnaAleatoria;
    do {
        columnaAleatoria = rand() % columnas;
    } while (nodo->tablero[0][columnaAleatoria] != " ");
    
    // Realizar el movimiento en la columna seleccionada
    for (int i = 5; i >= 0; --i) {
        if (nodo->tablero[i][columnaAleatoria] == " ") {
            nodo->tablero[i][columnaAleatoria] = "O";
            cout<<"Maquina:"<<"\n"<<
            "<-------------->"<<endl;
            nodo->mostrarTablero();
            return;
        }
    }
}

// Función para realizar el movimiento de la máquina en el nivel medio
void realizarMovimientoMedio(Nodo* nodo) {
    // Lógica para el nivel medio
    // Aquí puedes implementar una estrategia más avanzada
    // Por ejemplo, evaluando las posibles jugadas y tomando una decisión
    // basada en el algoritmo Minimax
    // ...

    // En este ejemplo, se utiliza la estrategia fácil
    realizarMovimientoFacil(nodo);
}

// Función para realizar el movimiento de la máquina en el nivel difícil
void realizarMovimientoDificil(Nodo* nodo) {
    // Lógica para el nivel difícil
    // Aquí puedes implementar una estrategia más avanzada
    // que utilice el algoritmo Minimax para tomar la mejor decisión
    // ...

    // En este ejemplo, se utiliza la estrategia fácil
    realizarMovimientoFacil(nodo);
}


void movimientoMaquina(Nodo* nodo, int nivelDificultad) {
    // Lógica para la máquina según el nivel de dificultad
    switch (nivelDificultad) {
        case 1:  // Fácil
            realizarMovimientoFacil(nodo);
            break;
        case 2:  // Medio
            realizarMovimientoMedio(nodo);
            break;
        case 3:  // Difícil
            realizarMovimientoDificil(nodo);
            break;
        default:
            cerr << "Nivel de dificultad no válido." << endl;
    }
}


void realizarMovimiento(Nodo*nodo,int jugador){
    int col;
    cout<<"Elegir columna para insertar ficha (1-7):";
    cin>>col;
    while(col<1||col>7){
        cout<<"Ingrese columna valida (1-7): ";
        cin>>col;
    }
    col--;
    for(int i=5;i>=0;i--){
        if(i==0 && nodo->tablero[i][col]!=" "){
            cout<<"Error -> Columna llena"<<"\n"<<"<-------------->"<<endl;
            nodo->mostrarTablero();
            cout<<"<-------------->"<<endl;
            realizarMovimiento(nodo,jugador);
            return;
        }else if(nodo->tablero[i][col]==" " && jugador==1){
            nodo->tablero[i][col]="X";
            cout<<"Jugador:"<<"\n"<<"<-------------->"<<endl;
            nodo->mostrarTablero();
            cout<<"<-------------->"<<endl;
            return;
        }
    }
}

int OpcionesMenu(){
    int opcion;
    do{
        cout<<"---OPCIONES---"<<endl;
        cout<<"1) Realizar Movimiento"<<
        "\n"<<"2) Guardar Partida"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1:
                opcion= 1;
                break;
            case 2:
                opcion= 2;
                break;
            default:
                cout<<"Ingrese opcion valida"<<endl;
        }
    }while(opcion<1 || opcion>2);
    return opcion;
}

int menu() {
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
    return opcion;
}

int main(){
    int dificultad= menu();
    Nodo* raiz = new Nodo();//caso inicial (todo vacío)
    raiz->mostrarTablero();
    bool mov = true;
    int jugadorGanador = 0;
    while (mov) {
        // Realiza movimientos
        realizarMovimiento(raiz, 1);
        if (raiz->verificarVictoria(1)) {
            cout << "¡Jugador 1 ha ganado!" << endl;
            jugadorGanador = 1;
            break;
        } else {
            movimientoMaquina(raiz, dificultad);
            if (raiz->verificarVictoria(2)) {
                cout << "¡La máquina ha ganado!" << endl;
                jugadorGanador = 2;
                break;
            }else{
                if (OpcionesMenu() == 2) {
                    mov = false;
                }
            }
        }
    }
    // Generar hijos del nodo raíz
    raiz->generarHijos(1);//Supongamos que el jugador actual es el jugador 1
    // Mostrar el tablero del nodo raíz
    // Liberar la memoria
    delete raiz;
    cout << "¡Partida finalizada!" << endl;
    return 0;
};