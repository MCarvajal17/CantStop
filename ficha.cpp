#include <iostream>
#include <string>

class Ficha {
private:
    std::string nombre; // Nombre del jugador o identificador
    int posicion[11];   // Posición en las 11 columnas (inicialmente todas 0)
    char color;         // Color de la ficha (puedes eliminar esto si no es necesario)

public:
    // Constructor
    Ficha(std::string _nombre) : nombre(_nombre) {
        // Inicializar la posición de cada columna en 0
        for (int i = 0; i < 11; ++i) {
            posicion[i] = 0;
        }
    }

    // Método para avanzar en una columna específica
    void avanzar(int columna, int pasos) {
        if (columna >= 2 && columna <= 12) {
            posicion[columna - 2] += pasos; // Ajuste de índice
        } else {
            std::cout << "Columna inválida." << std::endl;
        }
    }

    // Método para mostrar la posición actual de la ficha
    void mostrarPosicion() const {
        std::cout << "Posición de " << nombre << ": ";
        for (int i = 0; i < 11; ++i) {
            std::cout << "Columna " << (i + 2) << ": " << posicion[i] << "  ";
        }
        std::cout << std::endl;
    }

    // Método para obtener el nombre del jugador
    std::string getNombre() const {
        return nombre;
    }

    // Método para verificar si ha ganado
    bool haGanado() const {
        for (int i = 0; i < 11; ++i) {
            if (posicion[i] >= 3) { // Supongamos que la meta es 3 en cada columna
                return true;
            }
        }
        return false;
    }
};
