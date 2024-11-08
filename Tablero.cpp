#include "Tablero.h"
#include <iostream>
using namespace std;

Tablero::Tablero() {
    int guiaTemp[11] = {3, 5, 7, 9, 11, 13, 11, 9, 7, 5, 3};
    for (int i = 0; i < 11; i++) {
        guia[i] = guiaTemp[i];
        vector<Celda> columna(guia[i]);
        columnas.push_back(columna);
    }
}

void Tablero::mostrar() {
    for (int i = 0; i < 11; i++) {
        for (Celda& celda : columnas[i]) {
            celda.mostrar();
        }
        cout << endl;
    }
}

bool Tablero::colocarMarcador(int columna, int nivel, char jugador) {
    if (nivel < guia[columna] && !columnas[columna][nivel].ocupada) {
        columnas[columna][nivel].ocupante = jugador;
        return true;
    }
    return false;
}

void Tablero::confirmarAvance(int columna, int nivel, char jugador) {
    if (nivel < guia[columna]) {
        columnas[columna][nivel].ocupar(jugador);
    }
}

void Tablero::reiniciarMarcadores(char jugador) {
    for (auto& columna : columnas) {
        for (Celda& celda : columna) {
            if (celda.ocupante == jugador && !celda.ocupada) {
                celda.ocupante = '-';
            }
        }
    }
}

int Tablero::obtenerAlturaColumna(int columna) const {
    return guia[columna];
}

bool Tablero::columnaGanada(int columna, char jugador) const {
    return columnas[columna].back().ocupante == jugador;
}
