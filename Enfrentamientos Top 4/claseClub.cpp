#include <iostream>
#include <cstring>
#include "cargarCadena.h"
#include "claseClub.h"
#include "claseFecha.h"

using namespace std;

int Clubes::getIdClub(){
    return _idClub;
}
const char* Clubes::getNombre(){
    return _nombre;
}
const char *Clubes::getPresidente(){
    return _presidente;
}
const char *Clubes::getCiudad(){
    return _ciudad;
}
const char *Clubes::getEstadio(){
    return _estadio;
}

int Clubes::getTorneosGanados(){
    return _torneosGanados;
}

Fecha Clubes::getFechaFundacion(){
    return _fechaFundacion;
}
bool Clubes::getEstado(){
    return _estado;
}

void Clubes::setIdClub(int idClub){
    _idClub = idClub;
}
void Clubes::setNombreClub(const char *nombre){
    strcpy(_nombre,nombre);
}
void Clubes::setPresidente(const char *presidente){
    strcpy(_presidente,presidente);
}
void Clubes::setCiudad(const char *ciudad){
    strcpy(_ciudad,ciudad);
}
void Clubes::setEstadio(const char *estadio){
    strcpy(_estadio,estadio);
}

void Clubes::setTorneosGanados(int torneosGanados){
    _torneosGanados = torneosGanados;
}

void Clubes::setFechaFundacion(Fecha ff){
    _fechaFundacion = ff;
}

void Clubes::setEstado(bool estado){
    _estado = estado;
}

void Clubes::cargarClub(){
    char vecAux[30];
    //VALIDACION: NOMBRE NO VACIO
    bool nombreValido = false;
    do{
        cout<<"INGRESE EL NOMBRE DEL CLUB: ";
        cargarCadena(vecAux,29);
        if(strlen(vecAux)== 0){
            cout<<"ERROR: EL NOMBRE NO PUEDE ESTAR VACIO"<<endl;
        }
        else{
            nombreValido= true;
        }
    }
    while(!nombreValido);
    setNombreClub(vecAux);
    //VALIDACION: PRESIDENTE NO VACIO
    bool presidenteValido = false;
    do{
        cout<<"INGRESE EL NOMBRE DEL PRESIDENTE DEL CLUB: ";
        cargarCadena(vecAux,29);
        if(strlen(vecAux) == 0){
            cout<<"ERROR: EL NOMBRE DEL PRESIDENTE NO PUEDE ESTAR VACIO"<<endl;
        }
        else{
            presidenteValido= true;
        }
    }
    while(!presidenteValido);
    setPresidente(vecAux);
    //VALIDACION: CIUDAD NO VACIA
    bool ciudadValida = false;
    do{
        cout<<"INGRESE LA CIUDAD DONDE SE UBICA EL CLUB: ";
        cargarCadena(vecAux,29);
        if(strlen(vecAux)== 0){
            cout<<"ERROR: LA CIUDAD NO PUEDE ESTAR VACIA"<<endl;
        }
        else{
            ciudadValida= true;
        }
    }
    while(!ciudadValida);
    setCiudad(vecAux);
    //VALIDACION: ESTADIO NO VACIO
    bool estadioValido= false;
    do{
        cout<<"INGRESE EL NOMBRE DEL ESTADIO DEL CLUB: ";
        cargarCadena(vecAux,29);
        if(strlen(vecAux) == 0){
            cout<<"ERROR: EL NOMBRE DEL ESTADIO NO PUEDE ESTAR VACIO"<<endl;
        }
        else{
            estadioValido= true;
        }
    }
    while(!estadioValido);
    setEstadio(vecAux);
    int torneos;
    do{
        cout<<"INGRESE LA CANTIDAD DE TORNEOS GANADOS: ";
        cin>>torneos;
        if (torneos<0){
            cout<<"ERROR LOS TORNEOS NO PUEDEN SER NEGATIVOS"<<endl;
        }
    }
    while(torneos<0);
    setTorneosGanados(torneos);
    cout<<"INGRESE LA FECHA DE FUNDACION DEL CLUB: ";
    _fechaFundacion.cargarFecha();
    _estado= true;
    system("cls");
}
void Clubes::mostrarClub(){
    cout<<"ID DEL CLUB: "<<getIdClub()<<endl;
    cout<<"NOMBRE DEL CLUB: "<<getNombre()<<endl;
    cout<<"PRESIDENTE DEL CLUB: "<<getPresidente()<<endl;
    cout<<"CIUDAD EN LA QUE SE UBICA EL CLUB: "<<getCiudad()<<endl;
    cout<<"NOMBRE DEL ESTADIO: "<<getEstadio()<<endl;
    cout<<"PREMIER LEAGUES GANADAS: "<<getTorneosGanados()<<endl;
    cout<<"FECHA DE FUNDACION DEL CLUB: ";
    _fechaFundacion.mostrarFecha();
}
