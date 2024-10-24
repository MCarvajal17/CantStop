#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class dado {
private:
    int valor; // Valor del dado (1-6)
public:
    dado() {
        lanzar();
    }

    void lanzar() {
        valor = rand() % 6 + 1; // Genera un número entre 1 y 6
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

    // Crear cuatro dados
    dado d1, d2, d3, d4;

    // Mostrar el valor de los dados
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
            return 1; // Termina el programa si la opción es inválida
    }

    // Mostrar los resultados de las sumas
    cout << "La sumatoria de la pareja 1 es: " << par1 << endl;
    cout << "La sumatoria de la pareja 2 es: " << par2 << endl;

    return 0;
}
