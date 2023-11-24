#include <iostream>
#include <climits>
#include "Nodo.h"//acá estan las filas y columnas constantes
using namespace std;



//MINIMAX CON LA UTILIZACIÓN DE PODA ALFA-BETA
int minimax(Nodo* nodo, int profundidad, bool esMaximizador, int alpha, int beta) {
    if (profundidad == 0 || nodo->esNodoTerminal()) {
        // Calcula y asigna la puntuación del nodo
        return nodo->valor;
    }

    if (esMaximizador) {
        int maxEval = INT_MIN;
        for (int i = 0; i < columnas; ++i) {
            if (nodo->esColumnaValida(i)) {
                Nodo* hijo = new Nodo(*nodo);
                hijo->realizarMovimiento(i, 2); // 2 representa al jugador máquina
                int eval = minimax(hijo, profundidad - 1, false, alpha, beta);
                maxEval = max(maxEval, eval);
                alpha = max(alpha, eval);
                delete hijo;
                if (beta <= alpha) {
                    break;  // Poda alfa-beta
                }
            }
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;
        for (int i = 0; i < columnas; ++i) {
            if (nodo->esColumnaValida(i)) {
                Nodo* hijo = new Nodo(*nodo);
                hijo->realizarMovimiento(i, 1); // 1 representa al jugador humano
                int eval = hijo->minimax(profundidad - 1, true, alpha, beta);
                minEval = min(minEval, eval);
                beta = min(beta, eval);
                delete hijo;
                if (beta <= alpha) {
                    break;  // Poda alfa-beta
                }
            }
        }
        return minEval;
    }
}


//LA MAQUINA REALIZARÁ MOVIMIENTOS ALEATORIOS
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

//LA MAQUINA REALIZARÁ MOVIMIENTOS SEGUIDOS (O-O-O-O)
void realizarMovimientoMedio(Nodo* nodo) {
    int mejorColumna = -1;
    int mejorPuntuacion = INT_MIN;

    // Explorar todas las columnas posibles
    for (int columna = 0; columna < columnas; columna++) {
        // Si la columna está llena, ignórala
        if (nodo->tablero[0][columna] != " ") {
            continue;
        }

        // Crear un nodo hijo para la posible jugada
        Nodo* hijo = new Nodo(*nodo);
        hijo->realizarMovimiento(columna, 2); // 2 representa al jugador máquina

        // Calcular la puntuación utilizando el algoritmo Minimax
        int puntuacion = minimax(hijo, profundidadMaxima, false, INT_MIN, INT_MAX);

        // Si la puntuación es mejor que la mejor puntuación actual, actualizar
        if (puntuacion > mejorPuntuacion) {
            mejorPuntuacion = puntuacion;
            mejorColumna = columna;
        }

        // Liberar memoria del nodo hijo
        delete hijo;
    }

    // Realizar el movimiento en la mejor columna encontrada
    nodo->realizarMovimiento(mejorColumna, 2);
    cout << "Maquina:" << "\n" << "<-------------->" << endl;
    nodo->mostrarTablero();
    cout << "<-------------->" << endl;
}





//LA MAQUINA SIEMPRE GANARA O EMPATE
void realizarMovimientoDificil(Nodo* nodo) {
    // Lógica para el nivel difícil
    // Aquí puedes implementar una estrategia más avanzada
    // que utilice el algoritmo Minimax para tomar la mejor decisión
    // ...

    // En este ejemplo, se utiliza la estrategia fácil
    realizarMovimientoFacil(nodo);
}


void movimientoMaquina(Nodo* nodo, int nivelDificultad) {
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


void movimientoJugador(Nodo*nodo,int jugador){
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

int main() {
    int dificultad = menu();
    Nodo* raiz = new Nodo();  // caso inicial (todo vacío)
    raiz->mostrarTablero();
    bool mov = true;
    int jugadorGanador = 0;
    while (mov) {
        // Realiza movimientos
        movimientoJugador(raiz, 1);
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
            } else {
                if (OpcionesMenu() == 2) {
                    mov = false;
                }
            }
        }
    }
    // Liberar la memoria
    delete raiz;
    cout << "¡Partida finalizada!" << endl;
    return 0;
}