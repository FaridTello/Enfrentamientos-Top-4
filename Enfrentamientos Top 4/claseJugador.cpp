#include <iostream>
#include <cstring>
#include "cargarCadena.h"
#include "claseJugador.h"
#include "claseFecha.h"
#include "claseArchivoClub.h"

using namespace std;

int Jugadores::getIdJugador(){
    return _idJugador;
}

const char* Jugadores::getNombre(){
    return _nombre;
}

const char* Jugadores::getApellido(){
    return _apellido;
}

Fecha Jugadores::getFechaNacimiento(){
    return _FechaNacimiento;
}

const char* Jugadores::getPosicion(){
    return _posicion;
}

int Jugadores::getCamiseta(){
    return _camiseta;
}

int Jugadores::getIdClub(){
    return _idClub;
}

bool Jugadores::getEstado(){
    return _estado;
}

void Jugadores::setIdJugador(int idJugador){
    _idJugador = idJugador;
}

void Jugadores::setNombre(const char *nombre){
    strcpy(_nombre,nombre);
}

void Jugadores::setApellido(const char *apellido){
    strcpy(_apellido, apellido);
}

void Jugadores::setFechaNacimiento(Fecha fn){
    _FechaNacimiento = fn;
}

void Jugadores::setPosicion (const char* posicion){
    strcpy(_posicion,posicion);
}

void Jugadores::setCamiseta(int camiseta){
    _camiseta = camiseta;
}

void Jugadores::setIdClub(int idClub){
    _idClub=idClub;
}

void Jugadores::setEstado(bool estado){
    _estado = estado;
}

void Jugadores::cargarJugador(){
    char vecAux[30];
    cout<<"INGRESE EL NOMBRE: ";
    cargarCadena(vecAux, 29);
    setNombre(vecAux);
    cout<<"INGRESE EL APELLIDO: ";
    cargarCadena(vecAux,29);
    setApellido(vecAux);
    cout<<"INGRESE LA FECHA DE NACIMIENTO DEL JUGADOR ";
    _FechaNacimiento.cargarFecha();
    cout<<"INGRESE LA POSICION DEL JUGADOR: ";
    cargarCadena(vecAux, 29);
    setPosicion(vecAux);
    //VALIDACIÓN: NUMERO DE CAMISETA (1-99)
    int camiseta;
    do{
        cout<<"INGRESE EL NUMERO DE CAMISETA DEL JUGADOR (1-99): ";
        cin>>camiseta;
        if(camiseta < 1 || camiseta > 99){
            cout <<"ERROR: EL NUMERO DE CAMISETA DEBE ESTAR ENTRE 1 Y 99" << endl;
        }
    }
    while(camiseta<1 || camiseta>99);
    setCamiseta(camiseta);
    //VALIDACION: EL CLUB DEBE SER 1-4, EXISTIR Y ESTAR ACTIVO
    ArchivoClub arcClub;
    int idClub;
    bool clubValido = false;
    do{
        cout<<"INGRESE EL ID DEL CLUB (1-4): ";
        cin>>idClub;
        if(idClub<1 || idClub>4){
            cout<<"ERROR: SOLO HAY 4 CLUBES. EL ID DEBE ESTAR ENTRE 1 Y 4"<<endl;
            continue;
        }
        int posClub = arcClub.buscarRegistro(idClub);
        if(posClub < 0){
            cout<<"ERROR: NO EXISTE UN CLUB CON ESE ID. INTENTE NUEVAMENTE"<<endl;
        }
        else{
            Clubes club = arcClub.leerRegistro(posClub);
            if(!club.getEstado()){
                cout<<"ERROR: EL CLUB ESTA DADO DE BAJA. INTENTE CON OTRO"<<endl;
            }
            else{
                clubValido= true;
            }
        }
    }
    while(!clubValido);
    setIdClub(idClub);
    _estado = true;
    system("cls");
}

void Jugadores::mostrarJugador(){
    int idAux;
    cout<<"=========================================="<<endl;
    cout<<"ID DEL JUGADOR: "<<getIdJugador()<<endl;
    cout<<"NOMBRE DEL JUGADOR: "<<getNombre()<<endl;
    cout<<"APELLIDO DEL JUGADOR: "<<getApellido()<<endl;
    cout<<"FECHA DE NACIMIENTO DEL JUGADOR: ";
    _FechaNacimiento.mostrarFecha();
    cout<<"POSICION DEL JUGADOR: "<<getPosicion()<<endl;
    cout<<"NUMERO DE CAMISETA DEL JUGADOR: "<<getCamiseta()<<endl;
    idAux= getIdClub();
    switch(idAux){
            case 1:
                cout<<"CLUB DEL JUGADOR: MANCHESTER CITY"<<endl;
                break;
            case 2:
                cout<<"CLUB DEL JUGADOR: CHELSEA"<<endl;
                break;
            case 3:
                cout<<"CLUB DEL JUGADOR: MANCHESTER UNITED"<<endl;
                break;
            case 4:
                cout<<"CLUB DEL JUGADOR: lIVERPOOL"<<endl;
                break;
            case 0:
                return;
                break;
        }
    cout<<"=========================================="<<endl;
}

