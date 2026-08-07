#include <iostream>
#include <cstring>
#include "claseArchivoPartido.h"

using namespace std;

ArchivoPartido::ArchivoPartido(const char *nombre){
    strcpy(_nombre,nombre);
}

int ArchivoPartido::contarRegistros(){
    FILE *pFile = fopen(_nombre,"rb");
    if(pFile==nullptr){
        return -1;
    }
    fseek(pFile, 0, 2);
    int bytes = ftell(pFile);
    fclose(pFile);
    return bytes/sizeof(Partidos); /// DEVUELVE CANTIDAD DE REGISTROS
}

int ArchivoPartido::buscarRegistro(int idpartido){
    Partidos obj;
    int cantReg = contarRegistros();
     for(int i=0;i<cantReg;i++){
        obj = leerRegistro(i);
        if(idpartido == obj.getIdPartido()){
            return i; /// posicion en el registro
        }
    }
    return -1;
}

Partidos ArchivoPartido::leerRegistro(int pos){
    FILE *p = fopen(_nombre, "rb");
    Partidos obj;
    if(p == nullptr){
        obj.setIdPartido(-1);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    obj.setIdPartido(-2);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj; /// DEVUELVE EL OBJ CARGADO CON EL REGISTRO QUE ESTOY BSUCANDO CON LA POSICION QUE LE MANDÉ
}

bool ArchivoPartido::grabarRegistro(Partidos obj){
    FILE *pFile;
    pFile = fopen(_nombre, "ab");
    if(pFile==nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);
    return escribio;
}

void ArchivoPartido::listar(){
    Partidos obj;
    int cantReg = contarRegistros();
    for(int i=0;i<cantReg;i++){
        obj = leerRegistro(i);
        if(obj.getEstado()){
        obj.mostrarPartido();
        cout<<endl;
        }
    }
}

void ArchivoPartido::listarBajas(){
    Partidos obj;
    int cantReg = contarRegistros();
    for(int i=0;i<cantReg;i++){
        obj = leerRegistro(i);
        if(obj.getEstado()==false){
        obj.mostrarPartido();
        cout<<endl;
        }
    }
}

bool ArchivoPartido::modificarRegistro (Partidos obj, int pos){
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

void ArchivoPartido::listarEnfrentamientosEntreEquipos(int equipoUno, int equipoDos){
    int cantReg= contarRegistros();
    Partidos* vec= nullptr;
    if(cantReg<=0){
        cout<<"NO HAY PARTIDOS REGISTRADOS"<<endl;
        return;
    }
    vec = new Partidos[cantReg];
    if(vec==nullptr){
        cout<<"NO SE PUDO RESERVAR LA MEMORIA";
        return;
    }
    Partidos obj;
    int cont= 0;
    for(int i=0;i<cantReg;i++){
        obj = leerRegistro(i);
        if((obj.getIdPartidoEquipoLocal()==equipoUno || obj.getIdPartidoEquipoLocal()==equipoDos) &&
           (obj.getIdPartidoVisitante()==equipoUno || obj.getIdPartidoVisitante()==equipoDos)){
            vec[cont] = obj;
            cont++;
        }
    }
    if(cont==0){
        cout<<"NO SE ENCONTRARON ENFRENTAMIENTOS"<<endl;
        delete[] vec;
        return;
    }
    for(int i=0;i<cont-1;i++){
        for(int j=0;j<cont-1-i;j++){
            Fecha f1 = vec[j].getFechaPartido();
            Fecha f2 = vec[j+1].getFechaPartido();
            if(f1.getAnio()>f2.getAnio() ||
               (f1.getAnio()==f2.getAnio() && f1.getMes()>f2.getMes()) ||
               (f1.getAnio()==f2.getAnio() && f1.getMes()==f2.getMes() && f1.getDia()>f2.getDia())){
                Partidos temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
    for(int i=0;i<cont;i++){
        vec[i].mostrarPartido();
    }
    delete[] vec;
}

int ArchivoPartido::contarPartidosPorAnio(int anio)
{
    int cantReg = contarRegistros();
    int contador = 0;
    for(int i=0; i<cantReg; i++)
    {
        Partidos obj = leerRegistro(i);
        if(obj.getFechaPartido().getAnio() == anio && obj.getEstado())
        {
            contador++;
        }
    }
    return contador;
}
