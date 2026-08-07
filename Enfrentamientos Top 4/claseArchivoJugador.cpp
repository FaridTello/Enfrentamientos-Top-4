#include <iostream>
#include <cstring>
#include "claseArchivoJugador.h"

using namespace std;

ArchivoJugador::ArchivoJugador(const char *nombre){
    strcpy(_nombre,nombre);
}

int ArchivoJugador::contarRegistros(){
    FILE *pFile = fopen(_nombre,"rb");
    if(pFile==nullptr){
        return -1;
    }
    fseek(pFile, 0, 2);
    int bytes = ftell(pFile);
    fclose(pFile);
    return bytes/sizeof(Jugadores); /// DEVUELVE CANTIDAD DE REGISTROS
}

int ArchivoJugador::buscarRegistro(int idJugador){
    Jugadores obj;
    int cantReg = contarRegistros();
     for(int i=0;i<cantReg;i++){
        obj = leerRegistro(i);
        if(idJugador == obj.getIdJugador()){
            return i; /// posicion en el registro
        }
    }
    return -1;
}

Jugadores ArchivoJugador::leerRegistro(int pos){
    FILE *p = fopen(_nombre, "rb");
    Jugadores obj;
    if(p == nullptr){
        obj.setIdJugador(-1);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    obj.setIdJugador(-2);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj; /// DEVUELVE EL OBJ CARGADO CON EL REGISTRO QUE ESTOY BSUCANDO CON LA POSICION QUE LE MANDÉ
}

bool ArchivoJugador::grabarRegistro(Jugadores obj){
    FILE *pFile;
    pFile = fopen(_nombre, "ab");
    if(pFile==nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);
    return escribio;
}

void ArchivoJugador::listar(){
    Jugadores obj;
    int cantReg = contarRegistros();
    for(int i=0;i<cantReg;i++){
        obj = leerRegistro(i);
        if(obj.getEstado()){
        obj.mostrarJugador();
        cout<<endl;
        }
    }
}

void ArchivoJugador::listarBajas(){
    Jugadores obj;
    int cantReg = contarRegistros();
    for(int i=0;i<cantReg;i++){
        obj = leerRegistro(i);
        if(obj.getEstado()==false){
        obj.mostrarJugador();
        cout<<endl;
        }
    }
}

bool ArchivoJugador::modificarRegistro (Jugadores obj, int pos){
    FILE *pFile;
    pFile = fopen(_nombre, "rb+");
    if(pFile==nullptr){
        return false;
    }
    fseek(pFile, pos * sizeof(obj),0);
    bool escribio = fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);
    return escribio;
}

void ArchivoJugador::listarJugadoresPorClub(int opcion){
    Jugadores obj;
    int cantReg = contarRegistros();
    if(cantReg==0){
        cout<<"NO HAY JUGADORES REGISTRADOS"<<endl;
        return;
    }
    bool hayJugadores= false;
    switch(opcion){
            case 1:
                cout<<"JUGADORES DEL MANCHESTER CITY: "<<endl;
                break;
            case 2:
                cout<<"JUGADORES DEL CHELSEA: "<<endl;
                break;
            case 3:
                cout<<"JUGADORES DEL MANCHESTER UNITED: "<<endl;
                break;
            case 4:
                cout<<"JUGADORES DEL LIVERPOOL: "<<endl;
                break;
            case 0:
                return;
                break;
        }
    for(int i=0;i<cantReg;i++){
        obj = leerRegistro(i);
        if(obj.getIdClub()== opcion){
        obj.mostrarJugador();
        cout<<endl;
        hayJugadores= true;
        }
    }
    if(!hayJugadores){
        cout<<"NO SE ENCONTRARON JUGADORES PARA ESE CLUB."<<endl;
    }
}

void ArchivoJugador::listarJugadoresPorPosicion(int opcion){
    Jugadores obj;
    int cantReg = contarRegistros();
    char posABuscar[30];
    if(cantReg==0){
        cout<<"NO HAY JUGADORES REGISTRADOS"<<endl;
        return;
    }
    bool hayJugadores= false;
    switch(opcion){
            case 1:
                cout<<"ARQUEROS QUE SE ENCUNETRAN REGISTRADOS: "<<endl;
                strcpy(posABuscar,"Arquero");
                break;
            case 2:
                cout<<"DEFENSORES QUE SE ENCUNETRAN REGISTRADOS: "<<endl;
                strcpy(posABuscar,"Defensor");
                break;
            case 3:
                cout<<"MEDIOCAMPISTAS QUE SE ENCUNETRAN REGISTRADOS: "<<endl;
                strcpy(posABuscar,"Mediocampista");
                break;
            case 4:
                cout<<"DELANTEROS QUE SE ENCUNETRAN REGISTRADOS: "<<endl;
                strcpy(posABuscar,"Delantero");
                break;
            case 0:
                return;
                break;
        }
    for(int i=0;i<cantReg;i++){
        obj = leerRegistro(i);
        if(strcasecmp(posABuscar, obj.getPosicion())==0){
        obj.mostrarJugador();
        cout<<endl;
        hayJugadores= true;
        }
    }
    if(!hayJugadores){
        cout<<endl;
        cout<<"NO SE ENCONTRARON JUGADORES QUE JUEGUEN EN ESA POSICION DENTRO DEL REGISTRO."<<endl;
    }
}
