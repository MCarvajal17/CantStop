#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>

class Jugador {
public:
    std::string nombre;
    char simbolo;  // 'A', 'B', 'C', 'D' Las letras representan a los jugadores 
    std::vector<int> progreso;  // Nivel actual en cada columna

    Jugador(std::string nombre, char simbolo);
};

#endif
