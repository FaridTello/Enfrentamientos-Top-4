#include <iostream>
#include "claseArchivoClub.h"
#include "cargarCadena.h"

using namespace std;

void agregarClub(){
    Clubes obj;
    ArchivoClub arc;
    int idClub;
    bool idValido = false;
    do{
        cout<<"INGRESE EL ID DEL CLUB (1-4): ";
        cin>>idClub;
        if(idClub<1 || idClub>4){
            cout<<"ERROR: EL ID DEBE ESTAR ENTRE 1 Y 4"<<endl;
            continue;
        }
        int pos =arc.buscarRegistro(idClub);
        if(pos>=0){
            cout<<"ERROR: YA EXISTE UN CLUB CON ESE ID"<<endl;
        }
        else{
            idValido= true;
        }
    }
    while(!idValido);
    obj.setIdClub(idClub);
    obj.cargarClub();
    if(arc.grabarRegistro(obj)){
        cout<<"CLUB AGREGADO EXITOSAMENTE"<<endl;
    }
    else{
        cout<<"ERROR AL GRABAR EL CLUB"<<endl;
    }
}

void listarClub(){
    ArchivoClub arc;
    arc.listar();
}

void listarClubBaja(){
    ArchivoClub arc;
    arc.listarbajas();
}

void modificarTorneosGanados(){
    int idClub;
    cout<<"INGRESE EL ID DEL CLUB AL QUE DESEA MODIFICAR LOS TORNEOS GANADOS: ";
    cin>>idClub;
    ArchivoClub arc;
    int pos = arc.buscarRegistro(idClub);
    if(pos<0){
        cout<<"NO HAY CLUB CON ESE ID ";
        cout<<endl;
        return;
    }
    Clubes obj = arc.leerRegistro(pos);
    int aux;
    cout<<endl;
    cout<<"INGRESE LA NUEVA CANTIDAD DE TROFEOS GANADOS POR EL CLUB: ";
    cin>>aux;
    obj.setTorneosGanados(aux);
    arc.modificarRegistro(obj, pos);
}

void bajaLogicaClub(){
    cout<<"INGRESE EL ID DEL CLUB A DAR DE BAJA: ";
    int idClub;
    cin>>idClub;
    ArchivoClub arc;
    int pos = arc.buscarRegistro(idClub);
    if(pos < 0){
        cout<<"NO EXISTE UN CLUB CON ESE ID EN EL ARCHIVO"<<endl;
        return;
    }
    Clubes obj = arc.leerRegistro(pos);
    if(obj.getEstado() == false){
        cout<<"EL ClUB YA SE ENCUENTRA DADO DE BAJA"<<endl;
        return;
    }
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
    cout<<"CLUB DADO DE BAJA CORRECTAMENTE"<<endl;
}

void darClubDeAlta()
{
    cout<<"INGRESE EL ID DEL CLUB A DAR DE ALTA: ";
    int idClub;
    cin>>idClub;
    ArchivoClub arc;
    int pos = arc.buscarRegistro(idClub);
    if(pos < 0){
        cout<<"NO EXISTE UN CLUB CON ESE ID EN EL ARCHIVO"<<endl;
        return;
    }
    Clubes obj = arc.leerRegistro(pos);
    if(obj.getEstado() == true){
        cout<<"EL ClUB YA SE ENCUENTRA DADO DE ALTA"<<endl;
        return;
    }
    obj.setEstado(true);
    arc.modificarRegistro(obj, pos);
    cout<<"CLUB DADO DE ALTA CORRECTAMENTE"<<endl;
}

void consultarClubPorId(){
    int id;
    int pos;
    ArchivoClub arc;
    cout<<"INGRESE EL ID DE CLUB QUE DESEA BUSCAR: ";
    cin>>id;
    system("cls");
    pos = arc.buscarRegistro(id);
    if(pos<0)
    {
        cout<<"NO EXISTE UN CLUB CON ESE ID EN EL REGISTRO"<<endl;
        return;
    }
    Clubes obj=arc.leerRegistro(pos);
    if(obj.getIdClub()<0){
        cout<<"NO EXISTE ESA POSICION EN EL ARCHIVO"<<endl;
        return;
    }
    cout<<"======================================="<<endl;
    obj.mostrarClub();
    cout<<"======================================="<<endl;
}
