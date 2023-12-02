#include <iostream>
using namespace std;

const int filas = 6;
const int columnas = 7;
const int profundidadMaxima = 4;

class Nodo {
public:
    string tablero[filas][columnas];//Tablero
    Nodo* hijos[columnas];  //Hijos del nodo representan los posibles movimientos
    int valor;
    Nodo();
    ~Nodo();
    bool verificarVictoria(int jugador);
    void generarHijos(int jugador);
    void realizarMovimiento(int columna, int jugador);
    void mostrarTablero();
    bool esColumnaValida(int columna);
    bool esNodoTerminal();
};

Nodo::Nodo() {
    for(int i=0;i<filas;i++) {
        for(int j=0;j<columnas;j++) {
            tablero[i][j]= " ";
        }
    }
    for(int i=0;i<columnas;i++) {
        hijos[i]= nullptr;
    }
}

Nodo::~Nodo() {
    for(int i=0;i<columnas;i++) {
        delete hijos[i];
    }
}

void Nodo::mostrarTablero() {
    for(int i=0;i<filas;i++) {
        cout<<"|";
        for(int j=0;j<columnas;j++) {
            cout<<tablero[i][j]<<"|";
        }
        cout<<endl;
    }
}

void Nodo::generarHijos(int jugador) {
    for(int i=0;i<columnas;i++) {
        if(tablero[0][i]==" ") {
            hijos[i]= new Nodo();
            for(int j=0;j<filas;j++) {
                for(int k=0;k<columnas;k++) {
                    hijos[i]->tablero[j][k]= tablero[j][k];
                }
            }
            hijos[i]->realizarMovimiento(i, jugador);
        }
    }
}

void Nodo::realizarMovimiento(int columna, int jugador) {
    for (int i= filas-1;i>=0;i--) {
        if (tablero[i][columna]==" ") {
            tablero[i][columna]=(jugador==1)?"X":"O";
            return;
        }
    }
}

bool Nodo::esColumnaValida(int columna) {
    return tablero[0][columna]==" ";
}

bool Nodo::esNodoTerminal() {
    return valor!=0 || verificarVictoria(1) || verificarVictoria(2);
}


bool Nodo::verificarVictoria(int jugador) {
    string ficha= (jugador== 1)?"X":"O";

    // DETECTAR VICTORIA EN FILAS
    for(int i=0;i<filas;i++) {
        for(int j=0;j<columnas-3;j++) {
            if (tablero[i][j]== ficha &&
                tablero[i][j+1]== ficha &&
                tablero[i][j+2]== ficha &&
                tablero[i][j+3]== ficha) {
                return true;
            }
        }
    }

    // DETECTAR VICTORIAS EN COLUMNAS
    for(int i=0;i<filas-3;i++) {
        for(int j=0;j<columnas;j++) {
            if (tablero[i][j]== ficha &&
                tablero[i+1][j]== ficha &&
                tablero[i+2][j]== ficha &&
                tablero[i+3][j]== ficha) {
                return true;
            }
        }
    }

    // DETECTAR VICTORIAS EN DIAGNOAL DERECHA
    for(int i=0;i<filas-3;i++) {
        for(int j=0;j<columnas-3;j++) {
            if (tablero[i][j]== ficha &&
                tablero[i+1][j+1]== ficha &&
                tablero[i+2][j+2]== ficha &&
                tablero[i+3][j+3]== ficha) {
                return true;
            }
        }
    }

    // DETECTAR VICTORIAS EN DIAGONAL IZQUIERDA
    for(int i=0;i<filas-3;i++) {
        for(int j=3;j<columnas;j++) {
            if (tablero[i][j]== ficha &&
                tablero[i+1][j-1]== ficha &&
                tablero[i+2][j-2]== ficha &&
                tablero[i+3][j-3]== ficha) {
                return true;
            }
        }
    }
    return false;
}
