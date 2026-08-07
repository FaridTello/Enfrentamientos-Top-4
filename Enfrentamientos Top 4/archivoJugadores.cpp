#include <iostream>
#include "claseArchivoJugador.h"
#include "cargarCadena.h"

using namespace std;

void agregarJugador(){
    Jugadores obj;
    ArchivoJugador arc;
    int idJugador;
    bool idValido = false;
    do{
        cout<<"INGRESE EL ID DEL JUGADOR: ";
        cin >> idJugador;
        if(idJugador <= 0){
            cout<<"ERROR: EL ID DEBE SER UN NUMERO POSITIVO"<<endl;
            continue;
        }
        int pos = arc.buscarRegistro(idJugador);
        if(pos >= 0){
            cout<<"ERROR: YA EXISTE UN JUGADOR CON ESE ID"<<endl;
        }
        else{
            idValido = true;
        }
    }
    while(!idValido);
    obj.setIdJugador(idJugador);
    obj.cargarJugador();
    if(arc.grabarRegistro(obj)){
        cout<<"JUGADOR AGREGADO EXITOSAMENTE"<<endl;
    }
    else{
        cout<<"ERROR AL GRABAR EL JUGADOR"<<endl;
    }
}

void listarJugador(){
    ArchivoJugador arc;
    arc.listar();
}

void listarJugadorBaja(){
    ArchivoJugador arc;
    arc.listarBajas();
}

void modificarCamiseta(){
    int idJugador;
    cout<<"INGRESE EL ID DEL JUGADOR AL QUE DESEA MODIFICAR LA CAMISETA: ";
    cin>>idJugador;
    ArchivoJugador arc;
    int pos = arc.buscarRegistro(idJugador);
    if(pos<0){
        cout<<"NO HAY JUGADOR CON ESE ID ";
        cout<<endl;
        return;
}
    Jugadores obj = arc.leerRegistro(pos);
    int aux;
    cout<<"INGRESE EL NUEVO NUMERO DE LA CAMISETA: ";
    cin>>aux;
    obj.setCamiseta(aux);
    arc.modificarRegistro(obj, pos);
}

void bajaLogicaJugador(){
    cout<<"INGRESE EL ID DEL JUGADOR A DAR DE BAJA: ";
    int idJugador;
    cin>>idJugador;
    ArchivoJugador arc;
    int pos = arc.buscarRegistro(idJugador);
    if(pos < 0){
        cout<<"NO EXISTE UN JUGADOR CON ESE ID EN EL ARCHIVO"<<endl;
        return;
    }
    Jugadores obj = arc.leerRegistro(pos);
    if(obj.getEstado() == false){
        cout<<"EL JUGADOR YA SE ENCUENTRA DADO DE BAJA"<<endl;
        return;
    }
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
    cout<<"EL JUGADOR DADO DE BAJA CORRECTAMENTE"<<endl;
}

void darJugadorDeAlta(){
    cout<<"INGRESE EL ID DEL JUGADOR A DAR DE ALTA: ";
    int idJugador;
    cin>>idJugador;
    ArchivoJugador arc;
    int pos = arc.buscarRegistro(idJugador);
    if(pos < 0){
        cout<<"NO EXISTE UN JUGADOR CON ESE ID EN EL ARCHIVO"<<endl;
        return;
    }
    Jugadores obj = arc.leerRegistro(pos);
    if(obj.getEstado() == true){
        cout<<"EL JUGADOR YA SE ENCUENTRA DADO DE ALTA"<<endl;
        return;
    }
    obj.setEstado(true);
    arc.modificarRegistro(obj, pos);
    cout<<"EL JUGADOR DADO DE ALTA CORRECTAMENTE"<<endl;
}

void consultarJugadorPorId(){
    int id;
    int pos;
    ArchivoJugador arc;
    cout<<"INGRESE EL ID DEL JUGADOR QUE DESEA BUSCAR: ";
    cin>>id;
    system("cls");
    pos = arc.buscarRegistro(id);
    if(pos<0){
        cout<<"NO EXISTE UN JUGADOR CON ESE ID EN EL REGISTRO"<<endl;
        return;
    }
    Jugadores obj=arc.leerRegistro(pos);
    if(obj.getIdJugador()<0){
        cout<<"NO EXISTE ESA POSICION EN EL ARCHIVO"<<endl;
        return;
    }
    obj.mostrarJugador();
}

void consultarJugadorPorFecha(){
    int dia;
    int mes;
    int anio;
    bool bandera= false;
    ArchivoJugador arc;
    Jugadores obj;
    cout<< "INGRESE EL DIA DE NACIMIENTO: ";
    cin>>dia;
    cout<< "INGRESE EL MES DE NACIMIENTO: ";
    cin>>mes;
    cout<< "INGRESE EL AÑO DE NACIMIENTO: ";
    cin>>anio;
    system ("cls");
    int cantRegistros;
    cantRegistros= arc.contarRegistros();
    if(cantRegistros<1){
        cout<<"NO HAY JUGADORES REGISTRADOS"<<endl;
        return;
    }
    for (int i=0;i<cantRegistros ;i++ ){
           obj= arc.leerRegistro(i);
        if (dia==obj.getFechaNacimiento().getDia() && mes== obj.getFechaNacimiento().getMes() && anio== obj.getFechaNacimiento().getAnio()){
            obj.mostrarJugador();
            bandera= true;
        }
    }
    if(bandera==false){
        cout<<"NO SE ENCONTRO UN JUGADOR CON ESA FECHA DE NACIMIENTO EN EL REGISTRO"<<endl;
    }
}
