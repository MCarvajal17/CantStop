
#include "Progreso.h"
#include <iostream>
using namespace std;

// Constructor
RastreadorMovimientos::RastreadorMovimientos() : progresoPermanente(0), progresoTemporal(0) {}

// Avanzar temporalmente en una columna
void RastreadorMovimientos::avanzar() {
    progresoTemporal++;
    cout << "Progreso temporal: " << progresoTemporal << endl;
}

// Guardar el progreso temporal como permanente
void RastreadorMovimientos::hacerProgresoPermanente() {
    progresoPermanente += progresoTemporal;
    progresoTemporal = 0;
    cout << "Progreso permanente actualizado: " << progresoPermanente << endl;
}

// Resetear el progreso temporal
void RastreadorMovimientos::resetearProgresoTemporal() {
    progresoTemporal = 0;
    cout << "Progreso temporal reseteado" << endl;
}

// Obtener el progreso permanente
int RastreadorMovimientos::obtenerProgresoPermanente() const {
    return progresoPermanente;
}

// Verificar si la columna está completada
bool RastreadorMovimientos::estaCompletada(int longitudColumna) const {
    return progresoPermanente >= longitudColumna;
}
