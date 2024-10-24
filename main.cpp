#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class celda {
public:
    char c_[4];
    celda(char a, char b, char c, char d) {
        c_[0] = a;
        c_[1] = b;
        c_[2] = c;
        c_[3] = d;
    }
    void mostrar() {
        cout << c_[0] << c_[1] << c_[2] << c_[3] << "|";
    }
};

class tablero {
private:
    int guia[11] = {3, 5, 7, 9, 11, 13, 11, 9, 7, 5, 3};
    string rotulo[11] = {"2 : ", "3 : ", "4 : ", "5 : ", "6 : ", "7 : ", "8 : ", "9 : ", "10: ", "11: ", "12: "};
    celda** ptr;

public:
    tablero() {
        ptr = (celda**)malloc(11 * 8);
        for (int j = 0; j < 11; j++) {
            ptr[j] = (celda*)malloc(guia[j]);
        }

        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < guia[i]; j++) {
                ptr[i][j] = celda('1', '2', '3', '4');
            }
        }
    }

    void mostrar() {
        cout << "                                 TABLERO" << endl;

        for (int i = 0; i < 11; i++) {
            cout << rotulo[i];
            for (int k = 0; k < ((13 - guia[i]) / 2); k++) {
                cout << "     ";
            }
            cout << "|";
            for (int j = 0; j < guia[i]; j++) {
                ptr[i][j].mostrar();
            }
            cout << endl;
        }
    }
};

class jugador {
private:
    string nombrej;
public:
    jugador(string _nombre) : nombrej(_nombre) {}

    void leer() {
        cout << "Jugador: " << nombrej << endl;
    }

    void correr() {
        cout << nombrej << " está corriendo!" << endl;
    }
};

class dado {
private:
    int valor;
public:
    dado() {
        lanzar();
    }

    void lanzar() {
        valor = rand() % 6 + 1;
    }

    int obtenerValor() const {
        return valor;
    }

    void mostrar(int numero) const {
        cout << "Dado " << numero << ": " << valor << endl;
    }
};

int main() {
    srand(time(0)); // Inicialización de la semilla para números aleatorios

    // Solicitar la cantidad de jugadores
    int cantidadJugadores;
    cout << "Ingrese la cantidad de jugadores (2-4): ";
    cin >> cantidadJugadores;
    cin.ignore();

    while (cantidadJugadores < 2 || cantidadJugadores > 4) {
        cout << "Cantidad inválida. Ingrese la cantidad de jugadores (2-4): ";
        cin >> cantidadJugadores;
        cin.ignore();
    }

    // Crear el tablero
    tablero t;
    t.mostrar();

    // Crear los jugadores
    vector<jugador> jugadores;
    for (int i = 1; i <= cantidadJugadores; i++) {
        string nombre;
        cout << "Ingrese el nombre del jugador " << i << ": ";
        getline(cin, nombre);
        jugadores.emplace_back(nombre);
    }

    // Crear los dados y lanzarlos
    dado d1, d2, d3, d4;
    d1.mostrar(1);
    d2.mostrar(2);
    d3.mostrar(3);
    d4.mostrar(4);

    // Opciones para que el usuario elija qué pares sumar
    int par1, par2, op;
    cout << "¿Qué parejas de dados quieres sumar?" << endl;
    cout << "1. Dado 1 + Dado 2 y Dado 3 + Dado 4" << endl;
    cout << "2. Dado 1 + Dado 3 y Dado 2 + Dado 4" << endl;
    cout << "3. Dado 1 + Dado 4 y Dado 2 + Dado 3" << endl;
    cin >> op;

    switch (op) {
        case 1:
            par1 = d1.obtenerValor() + d2.obtenerValor();
            par2 = d3.obtenerValor() + d4.obtenerValor();
            break;
        case 2:
            par1 = d1.obtenerValor() + d3.obtenerValor();
            par2 = d2.obtenerValor() + d4.obtenerValor();
            break;
        case 3:
            par1 = d1.obtenerValor() + d4.obtenerValor();
            par2 = d2.obtenerValor() + d3.obtenerValor();
            break;
        default:
            cout << "Opción inválida." << endl;
            return 1;
    }

    // Mostrar los resultados de las sumas
    cout << "La sumatoria de la pareja 1 es: " << par1 << endl;
    cout << "La sumatoria de la pareja 2 es: " << par2 << endl;

    return 0;
}
