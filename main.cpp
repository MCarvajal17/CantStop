#include <iostream>  
#include "CantStop.h"

int main() {
    int numJugadores;
    std::cout << "Ingrese el número de jugadores (2-4): ";
    std::cin >> numJugadores;

    if (numJugadores < 2 || numJugadores > 4) {
        std::cout << "Número de jugadores no válido.\n";
        return 0;
    }

    CantStop juego(numJugadores);
    juego.jugar();

    return 0;
}
