#pragma once
#include <iostream>
using namespace std;

const int filas=6;
const int columnas=7;

class Nodo {
    public:
        string tablero[filas][columnas];
        int valor;  // Puntuación asociada a este estado del tablero
        Nodo* hijos[columnas];  // Hijos del nodo representan los posibles movimientos
        Nodo();
        ~Nodo();
        void generarHijos(int jugador);
        void mostrarTablero();
};

Nodo::Nodo(){
    valor=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            tablero[i][j]=" ";
        }
    }
    for(int i=0;i<columnas;i++){
        hijos[i]=nullptr;
    }
}

Nodo::~Nodo(){
    for(int i=0;i<columnas;i++){
        delete hijos[i];
    }
}

// Método para imprimir el tablero del nodo
void Nodo::mostrarTablero() {
    for (int i = 0; i < filas; ++i) {
        cout << "|";
        for (int j = 0; j < columnas; ++j) {
            cout<<tablero[i][j]<< "|";
        }
        cout<<endl;
    }
}

void Nodo::generarHijos(int jugador) {
    // Implementa la lógica para generar los hijos del nodo (posibles movimientos)
    // Puedes modificar el tablero y asignar valores a la propiedad 'valor' según la evaluación
}
