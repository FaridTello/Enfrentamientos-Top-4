#ifndef CLASEARCHIVOJUGADOR_H_INCLUDED
#define CLASEARCHIVOJUGADOR_H_INCLUDED

#include "claseJugador.h"

class ArchivoJugador{
private:
    char _nombre[30];
public:
    ArchivoJugador(const char *nombre="jugadores.dat");
    int contarRegistros();
    int buscarRegistro(int);
    Jugadores leerRegistro(int);
    bool modificarRegistro (Jugadores, int);
    bool grabarRegistro(Jugadores);
    void listar();
    void listarBajas();
    void listarJugadoresPorClub(int);
    void listarJugadoresPorPosicion(int);
};

#endif // CLASEARCHIVOJUGADOR_H_INCLUDED
