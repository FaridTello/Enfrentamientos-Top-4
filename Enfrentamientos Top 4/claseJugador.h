#ifndef CLASEJUGADOR_H_INCLUDED
#define CLASEJUGADOR_H_INCLUDED

#include "claseFecha.h"

class Jugadores{
private:
    int _idJugador;
    char _nombre[30];
    char _apellido[30];
    Fecha _FechaNacimiento;
    char _posicion[30];
    int _camiseta;
    int _idClub;
    bool _estado;
public:
    int getIdJugador();
    const char *getNombre();
    const char *getApellido();
    Fecha getFechaNacimiento();
    const char *getPosicion();
    int getCamiseta();
    int getIdClub();
    bool getEstado();
    void setIdJugador(int);
    void setNombre(const char *);
    void setApellido(const char *);
    void setFechaNacimiento(Fecha);
    void setPosicion (const char*);
    void setCamiseta (int);
    void setIdClub(int);
    void setEstado(bool);
    void cargarJugador();
    void mostrarJugador();
};

#endif // CLASEJUGADOR_H_INCLUDED
