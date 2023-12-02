#include <iostream>
#include <climits>
#include "Nodo.h"//acá estan las filas y columnas constantes
using namespace std;



int minimax(Nodo* nodo, int profundidad, bool esMaximizador, int alpha, int beta) {
    if (profundidad == 0 || nodo->esNodoTerminal()) {
        return nodo->valor;
    }

    if (esMaximizador) {
        int maxEval = INT_MIN;
        for (int i = 0; i < columnas; i++) {
            if (nodo->esColumnaValida(i)) {
                Nodo* hijo = new Nodo(*nodo);
                hijo->realizarMovimiento(i, 2);
                int eval = minimax(hijo, profundidad - 1, false, alpha, beta);
                maxEval = max(maxEval, eval);
                alpha = max(alpha, eval);
                delete hijo;
                if (beta <= alpha) {
                    break;
                }
            }
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;
        for (int i = 0; i < columnas; i++) {
            if (nodo->esColumnaValida(i)) {
                Nodo* hijo = new Nodo(*nodo);
                hijo->realizarMovimiento(i, 1);
                int eval = minimax(hijo, profundidad - 1, true, alpha, beta);
                minEval = min(minEval, eval);
                beta = min(beta, eval);
                delete hijo;
                if (beta <= alpha) {
                    break;
                }
            }
        }
        return minEval;
    }
}

//LA MAQUINA REALIZARÁ MOVIMIENTOS ALEATORIOS
void realizarMovimientoFacil(Nodo* nodo) {
    int columnaAleatoria;
    do {
        columnaAleatoria= rand()%columnas;
    } while (nodo->tablero[0][columnaAleatoria]!=" ");
    for (int i=5;i>=0;i--) {
        if (nodo->tablero[i][columnaAleatoria]==" ") {
            nodo->tablero[i][columnaAleatoria]="O";
            cout<<"Maquina:"<<"\n"<<
            "<-------------->"<<endl;
            nodo->mostrarTablero();
            return;
        }
    }
}

//LA MAQUINA REALIZARÁ MOVIMIENTOS SEGUIDOS (O-O-O-O)
void realizarMovimientoMedio(Nodo* nodo) {
    int mejorColumna= -1;
    int mejorPuntuacion= INT_MIN;
    for (int columna=0;columna<columnas;columna++) {
        if (nodo->tablero[0][columna]!= " ") {
            continue;
        }
        Nodo* hijo= new Nodo(*nodo);
        hijo->realizarMovimiento(columna, 2);
        int puntuacion= minimax(hijo, profundidadMaxima, false, INT_MIN, INT_MAX);
        if (puntuacion>mejorPuntuacion) {
            mejorPuntuacion= puntuacion;
            mejorColumna= columna;
        }
        delete hijo;
    }
    nodo->realizarMovimiento(mejorColumna, 2);
    cout<<"Maquina:"<<"\n"<<"<-------------->"<<endl;
    nodo->mostrarTablero();
    cout<<"<-------------->"<<endl;
}

//LA MAQUINA SIEMPRE GANARA O EMPATE
void realizarMovimientoDificil(Nodo* nodo) {
    int mejorColumna = -1;
    int mejorPuntuacion = INT_MIN;
    // Evaluar cada columna para determinar el mejor movimiento
    for (int columna = 0; columna < columnas; columna++) {
        if (nodo->tablero[0][columna] != " ") {
            continue;  // La columna está llena
        }
        Nodo* hijo = new Nodo(*nodo);
        hijo->realizarMovimiento(columna, 2);  // 2 representa al jugador máquina
        int puntuacion = minimax(hijo, profundidadMaxima, false, INT_MIN, INT_MAX);
        if (hijo->verificarVictoria(1)) {
            puntuacion = INT_MAX;  // Bloquear al jugador es una prioridad
        } else if (hijo->verificarVictoria(2)) {
            puntuacion = INT_MIN;  // Evitar que el jugador humano gane
        }
        if (puntuacion > mejorPuntuacion) {
            mejorPuntuacion = puntuacion;
            mejorColumna = columna;
        }
        delete hijo;
    }
    nodo->realizarMovimiento(mejorColumna, 2);
    cout << "Maquina:" << "\n" << "<-------------->" << endl;
    nodo->mostrarTablero();
    cout << "<-------------->" << endl;
}


void movimientoMaquina(Nodo* nodo, int nivelDificultad) {
    switch (nivelDificultad) {
        case 1:
            realizarMovimientoFacil(nodo);
            break;
        case 2:
            realizarMovimientoMedio(nodo);
            break;
        case 3:
            realizarMovimientoDificil(nodo);
            break;
        default:
            cerr<<"Nivel de dificultad no válido."<<endl;
    }
}

void movimientoJugador(Nodo*nodo,int jugador){
    int col;
    cout<<"Elegir columna para insertar ficha (1-7):";
    cin>>col;
    while(col<1 || col>7){
        cout<<"Ingrese columna valida (1-7): ";
        cin>>col;
    }
    col--;
    for(int i=5;i>=0;i--){
        if(i==0 && nodo->tablero[i][col]!=" "){
            cout<<"Error -> Columna llena"<<"\n"<<"<-------------->"<<endl;
            nodo->mostrarTablero();
            cout<<"<-------------->"<<endl;
            movimientoJugador(nodo,jugador);
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
        cout<<"------CONECTA 4-----"<<endl;
        cout<<"Escoja una dificultad:"<<endl;
        cout<<"1) Facil"<<endl;
        cout<<"2) Normal"<<endl;
        cout<<"3) Dificil"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        switch (opcion) {
            case 1:
                cout<<"Dificultad: Facil"<<endl;
                break;
            case 2:
                cout<<"Dificultad: Medio"<<endl;
                break;
            case 3:
                cout<<"Dificultad: Dificil"<<endl;
                break;
            default:
                cout<<"Ingrese una opcion valida"<<endl;
        }
    } while (opcion<1 || opcion>3); //El bucle continuará mientras la opción sea inválida
    return opcion;
}

int main() {
    int dificultad= menu();
    Nodo* raiz= new Nodo();
    raiz->mostrarTablero();
    bool mov= true;
    int jugadorGanador= 0;
    while (mov) {
        movimientoJugador(raiz,1);
        if (raiz->verificarVictoria(1)) {
            cout<<"¡Jugador 1 ha ganado!"<<endl;
            jugadorGanador= 1;
            break;
        } else {
            movimientoMaquina(raiz,dificultad);
            if (raiz->verificarVictoria(2)) {
                cout<<"¡La máquina ha ganado!"<<endl;
                jugadorGanador= 2;
                break;
            } else {
                if (OpcionesMenu()== 2) {
                    mov= false;
                }
            }
        }
    }
    delete raiz;
    cout<<"¡Partida finalizada!"<<endl;
    return 0;
}