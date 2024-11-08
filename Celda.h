#ifndef CELDA_H
#define CELDA_H

class Celda {
public:
    char ocupante;  // 'A', 'B', 'C', 'D' o '-' si está vacía
    bool ocupada;   // Indica si la celda está ocupada permanentemente

    Celda();
    void ocupar(char jugador);
    void mostrar() const;
};

#endif
