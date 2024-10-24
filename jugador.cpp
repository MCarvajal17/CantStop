#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;
class jugador {
private:
    string nombrej;
    string color; // Color de la ficha
public:
    jugador(string _nombre, string _color) : nombrej(_nombre), color(_color) {}

    void leer() {
        cout << "Jugador: " << nombrej << ", Color de ficha: " << color << endl;
    }

    void correr() {
        cout << nombrej << " está corriendo!" << endl;
    }
};

string asignarColor(set<string>& coloresAsignados) {
    vector<string> colores = {"Rojo", "Verde", "Azul", "Amarillo", "Naranja"};
    string color;

    do {
        color = colores[rand() % colores.size()];
    } while (coloresAsignados.find(color) != coloresAsignados.end());

    coloresAsignados.insert(color);
    return color;
}

int main() {
    vector<jugador> jugadores;
    set<string> coloresAsignados; // Conjunto para colores ya asignados
    int cantJ;

    // Inicialización de los jugadores
    do {
        cout << "Señor usuario, digite la cantidad de Jugadores (2-4): ";
        cin >> cantJ;
        if (cantJ < 2 || cantJ > 4) {
            cout << "Cantidad de Jugadores no válida. Reintente por favor." << endl;
        }
    } while (cantJ < 2 || cantJ > 4);

    // Leer nombres de jugadores y asignar colores únicos
    for (int i = 0; i < cantJ; i++) {
        string nombre;
        cout << "Ingrese el nombre del jugador " << (i + 1) << ": ";
        cin >> nombre;
        string color = asignarColor(coloresAsignados); // Asignar un color único
        jugadores.emplace_back(nombre, color); // Crear jugador
    }

    // Mostrar información de los jugadores
    for (jugador& j : jugadores) {
        j.leer();
    }

    return 0;
}
