#ifndef CLASEPARTIDO_H_INCLUDED
#define CLASEPARTIDO_H_INCLUDED

#include "claseFecha.h"

class Partidos{
private:
    int _idPartido;
    int _idPartidoEquipoLocal;
    int _idPartidoEquipoVisitante;
    Fecha _fechaPartido;
    int _golesLocales;
    int _golesVisitante;
    char _arbitro[30];
    bool _estado;
public:
    int getIdPartido();
    int getIdPartidoEquipoLocal();
    int getIdPartidoVisitante();
    Fecha getFechaPartido();
    int getGolesLocales();
    int getGolesVisitante();
    const char *getArbitro();
    bool getEstado();
    void setIdPartido(int);
    void setIdPartidoEquipoLocal(int);
    void setIdPartidoEquipoVisitante(int);
    void setFechaPartido (Fecha);
    void setGolesLocales(int);
    void setGolesVisitantes(int);
    void setArbitro(const char *);
    void setEstado(bool);
    void cargarPartido();
    void mostrarPartido();
};

#endif // CLASEPARTIDO_H_INCLUDED
