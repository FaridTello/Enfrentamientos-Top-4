#include <iostream>
#include <cstring>
#include "clasePartido.h"
#include "claseFecha.h"
#include "cargarCadena.h"
#include "claseArchivoClub.h"

using namespace std;

int Partidos::getIdPartido(){
    return _idPartido;
}

int Partidos::getIdPartidoEquipoLocal(){
    return _idPartidoEquipoLocal;
}

int Partidos::getIdPartidoVisitante(){
    return _idPartidoEquipoVisitante;
}

Fecha Partidos::getFechaPartido(){
    return _fechaPartido;
}

int Partidos::getGolesLocales(){
    return _golesLocales;
}

int Partidos::getGolesVisitante(){
    return _golesVisitante;
}

const char *Partidos::getArbitro(){
    return _arbitro;
}

bool Partidos::getEstado(){
    return _estado;
}

void Partidos::setIdPartido(int idPartido){
    _idPartido = idPartido;
}

void Partidos::setIdPartidoEquipoLocal(int idLocal){
    _idPartidoEquipoLocal = idLocal;
}

void Partidos::setIdPartidoEquipoVisitante(int idVisitante){
    _idPartidoEquipoVisitante = idVisitante;
}

void Partidos::setFechaPartido(Fecha fp){
    _fechaPartido = fp;
}

void Partidos::setGolesLocales(int golesLocal){
    _golesLocales = golesLocal;
}

void Partidos::setGolesVisitantes(int golesVisitante){
    _golesVisitante = golesVisitante;
}

void Partidos::setArbitro(const char *arbitro){
    strcpy(_arbitro, arbitro);
}

void Partidos::setEstado(bool estado){
    _estado = estado;
}

void Partidos::cargarPartido(){
    ArchivoClub arcClub;
    int idLocal, idVisitante;
    bool localValido = false;
    do{
        cout<<"INGRESE EL ID DEL EQUIPO LOCAL: ";
        cin>>idLocal;
        int posLocal =arcClub.buscarRegistro(idLocal);
        if(posLocal < 0){
            cout<<"ERROR: NO EXISTE UN CLUB CON ESE ID" <<endl;
        }
        else{
            Clubes club = arcClub.leerRegistro(posLocal);
            if(!club.getEstado()){
                cout<<"ERROR: EL CLUB ESTA DADO DE BAJA"<<endl;
            }
            else{
                localValido = true;
            }
        }
    }
    while(!localValido);
    setIdPartidoEquipoLocal(idLocal);
    bool visitanteValido= false;
    do{
        cout<<"INGRESE EL ID DEL EQUIPO VISITANTE: ";
        cin>>idVisitante;
        if(idVisitante == idLocal){
            cout<<"ERROR: EL EQUIPO LOCAL Y VISITANTE NO PUEDEN SER EL MISMO"<<endl;
        }
        else{
            int posVisitante = arcClub.buscarRegistro(idVisitante);
            if(posVisitante<0){
                cout<<"ERROR: NO EXISTE UN CLUB CON ESE ID" <<endl;
            }
            else{
                Clubes club = arcClub.leerRegistro(posVisitante);
                if(!club.getEstado()){
                    cout<<"ERROR: EL CLUB ESTA DADO DE BAJA"<<endl;
                }
                else{
                    visitanteValido=true;
                }
            }
        }
    }
    while(!visitanteValido);
    setIdPartidoEquipoVisitante(idVisitante);
    cout<<"INGRESE LA FECHA DEL PARTIDO: ";
    _fechaPartido.cargarFecha();
    int goles;
    do{
        cout<<"INGRESE LA CANTIDAD DE GOLES DEL EQUIPO LOCAL: ";
        cin>>goles;
        if(goles < 0){
            cout<<"ERROR: LOS GOLES NO PUEDEN SER NEGATIVOS"<<endl;
        }
    }
    while(goles<0);
    setGolesLocales(goles);
    do{
        cout<<"INGRESE LA CANTIDAD DE GOLES DEL EQUIPO VISITANTE: ";
        cin>>goles;
        if(goles<0){
            cout<<"ERROR: LOS GOLES NO PUEDEN SER NEGATIVOS"<<endl;
        }
    }
    while(goles<0);
    setGolesVisitantes(goles);
    char vecAux[30];
    cout<<"INGRESE EL NOMBRE DEL ARBITRO: ";
    cargarCadena(vecAux,29);
    setArbitro(vecAux);
    setEstado(true);
    system("cls");
}

void Partidos::mostrarPartido(){
    int idAux;
    cout<<"=============================="<<endl;
    cout<<"ID DEL PARTIDO: "<<getIdPartido()<<endl;
    idAux = getIdPartidoEquipoLocal();
    switch(idAux){
            case 1:
                cout<<"EQUIPO LOCAL: MANCHESTER CITY"<<endl;
                break;
            case 2:
                cout<<"EQUIPO LOCAL: CHELSEA"<<endl;
                break;
            case 3:
                cout<<"EQUIPO LOCAL: MANCHESTER UNITED"<<endl;
                break;
            case 4:
                cout<<"EQUIPO LOCAL: lIVERPOOL"<<endl;
                break;
            case 0:
                return;
                break;
        }
    idAux= getIdPartidoVisitante();
    switch(idAux){
            case 1:
                cout<<"EQUIPO VISITANTE: MANCHESTER CITY"<<endl;
                break;
            case 2:
                cout<<"EQUIPO VISITANTE: CHELSEA"<<endl;
                break;
            case 3:
                cout<<"EQUIPO VISITANTE: MANCHESTER UNITED"<<endl;
                break;
            case 4:
                cout<<"EQUIPO VISITANTE: lIVERPOOL"<<endl;
                break;
            case 0:
                return;
                break;
        }
    cout<<"FECHA DEL PARTIDO: ";
    _fechaPartido.mostrarFecha();
    cout<<"RESULTADO: "<<getGolesLocales()<<"-"<<getGolesVisitante() << endl;
    cout<<"ARBITRO: " << getArbitro()<<endl;
    cout<<"=============================="<<endl;
    cout<<endl;
}
