#ifndef CANTSTOP_H
#define CANTSTOP_H

#include "Tablero.h"
#include "Jugador.h"
#include <vector>

class CantStop {
private:
    Tablero tablero;
    std::vector<Jugador> jugadores;

public:
    CantStop(int numJugadores);
    void jugar();
    std::vector<int> lanzarDados();
    std::vector<std::pair<int, int>> calcularSumaDados(const std::vector<int>& dados);
};

#endif
