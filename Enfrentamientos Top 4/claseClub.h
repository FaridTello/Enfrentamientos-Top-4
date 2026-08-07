#ifndef CLASECLUB_H_INCLUDED
#define CLASECLUB_H_INCLUDED

#include "claseFecha.h"

class Clubes{
private:
    int _idClub;
    char _nombre[30];
    char _presidente[30];
    char _ciudad[30];
    char _estadio[30];
    int _torneosGanados;
    Fecha _fechaFundacion;
    bool _estado;
public:
    int getIdClub();
    const char *getNombre();
    const char *getPresidente();
    const char *getCiudad();
    const char *getEstadio();
    int getTorneosGanados();
    Fecha getFechaFundacion();
    bool getEstado();
    void setIdClub(int);
    void setNombreClub(const char *);
    void setPresidente(const char *);
    void setCiudad(const char *);
    void setEstadio(const char *);
    void setTorneosGanados(int);
    void setFechaFundacion(Fecha);
    void setEstado(bool);
    void cargarClub();
    void mostrarClub();
};

#endif // CLASECLUB_H_INCLUDED
