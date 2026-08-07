#ifndef CLASEARCHIVOPARTIDO_H_INCLUDED
#define CLASEARCHIVOPARTIDO_H_INCLUDED

#include "clasePartido.h"

class ArchivoPartido{
private:
    char _nombre[30];
public:
    ArchivoPartido(const char *nombre="partidos.dat");
    int contarRegistros();
    int buscarRegistro(int);
    Partidos leerRegistro(int);
    bool modificarRegistro (Partidos, int);
    bool grabarRegistro(Partidos);
    void listar();
    void listarBajas();
    void listarEnfrentamientosEntreEquipos(int, int);
    int contarPartidosPorAnio(int anio);
};

#endif // CLASEARCHIVOPARTIDO_H_INCLUDED
