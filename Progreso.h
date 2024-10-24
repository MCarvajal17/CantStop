
#ifndef PROGRESO_H
#define PROGRESO_H

class RastreadorMovimientos {
private:
    int progresoPermanente;  // Progreso permanente del jugador
    int progresoTemporal;    // Progreso temporal del jugador

public:
    RastreadorMovimientos();  // Constructor

    // Avanzar temporalmente en una columna
    void avanzar();

    // Guardar el progreso temporal como permanente
    void hacerProgresoPermanente();

    // Resetear el progreso temporal
    void resetearProgresoTemporal();

    // Obtener el progreso permanente
    int obtenerProgresoPermanente() const;

    // Verificar si la columna está completada
    bool estaCompletada(int longitudColumna) const;
};

#endif // PROGRESO_H
