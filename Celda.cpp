#include "Celda.h"
#include <iostream>
using namespace std;

Celda::Celda() : ocupante('-'), ocupada(false) {}

void Celda::ocupar(char jugador) {
    ocupante = jugador;
    ocupada = true;
}

void Celda::mostrar() const {
    cout << (ocupada ? ocupante : '-') << "|";
}
