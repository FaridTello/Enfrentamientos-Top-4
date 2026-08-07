#ifndef CLASEARCHIVOCLUB_H_INCLUDED
#define CLASEARCHIVOCLUB_H_INCLUDED

#include "claseClub.h"

class ArchivoClub{
private:
    char _nombre[30];
public:
    ArchivoClub(const char *nombre="clubes.dat");
    int contarRegistros();
    int buscarRegistro(int);
    Clubes leerRegistro(int);
    bool modificarRegistro (Clubes, int);
    bool grabarRegistro(Clubes);
    void listar();
    void listarbajas();
    void listarPorTorneos();
    void listarPorAntiguedad();
};

#endif // CLASEARCHIVOCLUB_H_INCLUDED
