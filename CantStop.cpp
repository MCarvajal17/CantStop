#include "CantStop.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

CantStop::CantStop(int numJugadores) {
    srand(static_cast<unsigned>(time(0)));
    char simbolo = 'A';
    for (int i = 0; i < numJugadores; i++) {
        string nombre;
        cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        cin >> nombre;
        jugadores.emplace_back(nombre, simbolo++);
    }
}

vector<int> CantStop::lanzarDados() {
    vector<int> dados(4);
    for (int i = 0; i < 4; i++) {
        dados[i] = rand() % 6 + 1;
    }
    return dados;
}

vector<pair<int, int>> CantStop::calcularSumaDados(const vector<int>& dados) {
    vector<pair<int, int>> combinaciones;
    combinaciones.push_back({dados[0] + dados[1], dados[2] + dados[3]});
    combinaciones.push_back({dados[0] + dados[2], dados[1] + dados[3]});
    combinaciones.push_back({dados[0] + dados[3], dados[1] + dados[2]});
    return combinaciones;
}

void CantStop::jugar() {
    bool juegoEnCurso = true;
    while (juegoEnCurso) {
        for (auto& jugador : jugadores) {
            cout << "\nTurno de " << jugador.nombre << ":\n";
            tablero.mostrar();

            vector<int> dados = lanzarDados();
            cout << "Dados: ";
            for (int d : dados) cout << d << " ";
            cout << endl;

            vector<pair<int, int>> sumas = calcularSumaDados(dados);
            cout << "Combinaciones de sumas: ";
            for (const auto& par : sumas) cout << "(" << par.first << ", " << par.second << ") ";
            cout << endl;

            bool turnoActivo = true;
            while (turnoActivo) {
                int seleccion;
                cout << "Seleccione una de las combinaciones de suma (1-3): ";
                cin >> seleccion;

                if (seleccion < 1 || seleccion > 3) {
                    cout << "Selección no válida. Por favor, elige una opción válida.\n";
                    continue;
                }

                int suma1 = sumas[seleccion - 1].first;
                int suma2 = sumas[seleccion - 1].second;

                vector<int> selecciones = {suma1, suma2};
                for (int s : selecciones) {
                    int columna = s - 2;
                    if (jugador.progreso[columna] >= tablero.obtenerAlturaColumna(columna)) {
                        cout << "Ya has ganado la columna " << s << ", no puedes avanzar más en ella.\n";
                        tablero.reiniciarMarcadores(jugador.simbolo);
                        turnoActivo = false;
                        break;
                    }
                    if (jugador.progreso[columna] < tablero.obtenerAlturaColumna(columna)) {
                        jugador.progreso[columna]++;
                        if (!tablero.colocarMarcador(columna, jugador.progreso[columna] - 1, jugador.simbolo)) {
                            cout << "Ya alcanzaste el tope de la columna " << s << ". No puedes avanzar.\n";
                            tablero.reiniciarMarcadores(jugador.simbolo);
                            turnoActivo = false;
                            break;
                        }

                        cout << jugador.nombre << " avanza en la columna " << s << ".\n";

                        if (tablero.columnaGanada(columna, jugador.simbolo)) {
                            cout << jugador.nombre << " gana la columna " << s << "!\n";
                            tablero.confirmarAvance(columna, jugador.progreso[columna] - 1, jugador.simbolo);
                        }
                    }
                }

                char opcion;
                cout << "¿Deseas continuar (C) o terminar el turno (T)? ";
                cin >> opcion;
                if (opcion == 'T' || opcion == 't') {
                    for (int i = 0; i < 11; i++) {
                        if (jugador.progreso[i] > 0) {
                            tablero.confirmarAvance(i, jugador.progreso[i] - 1, jugador.simbolo);
                        }
                    }
                    tablero.reiniciarMarcadores(jugador.simbolo);
                    turnoActivo = false;
                }
            }

            int columnasGanadas = 0;
            for (int j = 0; j < 11; j++) {
                if (tablero.columnaGanada(j, jugador.simbolo)) columnasGanadas++;
            }

            if (columnasGanadas >= 3) {
                cout << jugador.nombre << " ha ganado el juego completando 3 columnas!\n";
                juegoEnCurso = false;
                break;
            }
        }
    }
}
