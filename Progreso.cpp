#include "Progreso.h"
#include <iostream>
using namespace std;

// Constructor
Progreso::Progreso() : progresoPermanente(0), progresoTemporal(0) {}

// Avanzar temporalmente en una columna
void Progreso::avanzar() {
    progresoTemporal++;
    cout << "Progreso temporal: " << progresoTemporal << endl;
}

// Guardar el progreso temporal como permanente
void Progreso::hacerProgresoPermanente() {
    progresoPermanente += progresoTemporal;
    progresoTemporal = 0;
    cout << "Progreso permanente actualizado: " << progresoPermanente << endl;
}

// Resetear el progreso temporal
void Progreso::resetearProgresoTemporal() {
    progresoTemporal = 0;
    cout << "Progreso temporal reseteado" << endl;
}

// Obtener el progreso permanente
int Progreso::obtenerProgresoPermanente() const {
    return progresoPermanente;
}

// Verificar si la columna está completada
bool Progreso::estaCompletada(int longitudColumna) const {
    return progresoPermanente >= longitudColumna;
}
