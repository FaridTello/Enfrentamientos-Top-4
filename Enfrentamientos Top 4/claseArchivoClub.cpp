#include <iostream>
#include <cstring>
#include "claseArchivoClub.h"

using namespace std;

ArchivoClub::ArchivoClub(const char *nombre){
    strcpy(_nombre,nombre);
}

int ArchivoClub::contarRegistros(){
    FILE *pFile = fopen(_nombre,"rb");
    if(pFile==nullptr){
        return -1;
    }
    fseek(pFile, 0, 2);
    int bytes = ftell(pFile);
    fclose(pFile);
    return bytes/sizeof(Clubes); /// DEVUELVE CANTIDAD DE REGISTROS
}

int ArchivoClub::buscarRegistro(int idClub){
    Clubes obj;
    int cantReg = contarRegistros();
     for(int i=0;i<cantReg;i++){
        obj = leerRegistro(i);
        if(idClub == obj.getIdClub()){
            return i; /// posicion en el registro
        }
    }
    return -1;
}

Clubes ArchivoClub::leerRegistro(int pos){
    FILE *p = fopen(_nombre, "rb");
    Clubes obj;
    if(p == nullptr){
        obj.setIdClub(-1);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    obj.setIdClub(-2);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj; /// DEVUELVE EL OBJ CARGADO CON EL REGISTRO QUE ESTOY BSUCANDO CON LA POSICION QUE LE MANDÉ
}

bool ArchivoClub::grabarRegistro(Clubes obj){
    FILE *pFile;
    pFile = fopen(_nombre, "ab");
    if(pFile==nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);
    return escribio;
}

void ArchivoClub::listar(){
    Clubes obj;
    int cantReg = contarRegistros();
    for(int i=0;i<cantReg;i++){
        obj = leerRegistro(i);
        if(obj.getEstado()){
        obj.mostrarClub();
        cout<<endl;
        }
    }
}

void ArchivoClub::listarbajas(){
    Clubes obj;
    int cantReg = contarRegistros();
    for(int i=0;i<cantReg;i++){
        obj = leerRegistro(i);
        if(obj.getEstado()==false){
        obj.mostrarClub();
        cout<<endl;
        }
    }
}

bool ArchivoClub::modificarRegistro (Clubes obj, int pos){
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

void ArchivoClub::listarPorTorneos(){
    int cantReg= contarRegistros();
    if (cantReg<=0){
        cout<<"NO HAY CLUBES REGISTRADOS"<<endl;
        return;
    }
    Clubes clubes[4];
    for (int i=0;i<cantReg;i++){
        clubes[i]= leerRegistro(i);
    }
    for(int i=0;i<cantReg-1;i++){
        for(int j=0;j<cantReg-1-i;j++){
            if(clubes[j].getTorneosGanados()<clubes[j+1].getTorneosGanados()){
                Clubes temp = clubes[j];
                clubes[j] = clubes[j+1];
                clubes[j+1] = temp;
            }
        }
    }
    cout<<"=========================================="<<endl;
    cout<<"    CLUBES ORDENADOS POR TORNEOS GANADOS   "<<endl;
    cout<<"=========================================="<<endl;
    cout<<endl;
    for(int i=0; i<cantReg; i++){
        if (clubes[i].getEstado()){
            clubes[i].mostrarClub();
            cout<<"=========================================="<<endl;
        }
    }
}

void ArchivoClub::listarPorAntiguedad(){
    int cantReg= contarRegistros();
    if (cantReg<=0){
        cout<<"NO HAY CLUBES REGISTRADOS"<<endl;
        return;
    }
    Clubes clubes[4];
    for (int i=0;i<cantReg;i++){
        clubes[i]= leerRegistro(i);
    }
    for(int i=0; i<cantReg-1;i++){
        for (int j=0; j<cantReg-1-i;j++){
            if (clubes[j].getFechaFundacion().getAnio() > clubes[j+1].getFechaFundacion().getAnio()){
                Clubes temp = clubes[j];
                clubes[j] = clubes[j+1];
                clubes[j+1] = temp;
            }
            else if (clubes[j].getFechaFundacion().getAnio() == clubes[j+1].getFechaFundacion().getAnio()){
                if (clubes[j].getFechaFundacion().getMes() > clubes[j+1].getFechaFundacion().getMes()){
                    Clubes temp = clubes[j];
                    clubes[j] = clubes[j+1];
                    clubes[j+1] = temp;
                }
                else if (clubes[j].getFechaFundacion().getMes() == clubes[j+1].getFechaFundacion().getMes()){
                    if (clubes[j].getFechaFundacion().getDia() > clubes[j+1].getFechaFundacion().getDia()){
                        Clubes temp = clubes[j];
                        clubes[j] = clubes[j+1];
                        clubes[j+1] = temp;
                    }
                }
            }
        }
    }
    cout<< "======================================"<<endl;
    cout<< "    CLUBES ORDENADOS POR ANTIGUEDAD   "<<endl;
    cout<< "======================================"<<endl;
    cout<<endl;
    for(int i=0;i<cantReg;i++){
        if(clubes[i].getEstado()){
            clubes[i].mostrarClub();
            cout << "=========================================" << endl;
        }
    }
}
