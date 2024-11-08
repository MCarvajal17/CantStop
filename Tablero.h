#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include "Celda.h"

class Tablero {
private:
    int guia[11];  // Tamaño de cada columna
    std::vector<std::vector<Celda>> columnas;  // Tablero con las columnas

public:
    Tablero();
    void mostrar();
    bool colocarMarcador(int columna, int nivel, char jugador);
    void confirmarAvance(int columna, int nivel, char jugador);
    void reiniciarMarcadores(char jugador);
    int obtenerAlturaColumna(int columna) const;
    bool columnaGanada(int columna, char jugador) const;
};

#endif
