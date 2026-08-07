#include <iostream>
#include "claseArchivoPartido.h"
#include "cargarCadena.h"
#include <cstring>

using namespace std;

void agregarPartido(){
    Partidos obj;
    ArchivoPartido arc;
    int idPartido;
    cout<<"INGRESE EL ID DEL PARTIDO: ";
    cin>>idPartido;
    int pos = arc.buscarRegistro(idPartido);
    if(pos >= 0){
        cout<<"ERROR: YA EXISTE UN PARTIDO CON ESE ID"<<endl;
        return;
    }
    obj.setIdPartido(idPartido);
    obj.cargarPartido();
    if(arc.grabarRegistro(obj)){
        cout<<"PARTIDO AGREGADO EXITOSAMENTE"<<endl;
    }
    else{
        cout<<"ERROR AL GRABAR EL PARTIDO"<<endl;
    }
}

void listarPartido(){
    ArchivoPartido arc;
    arc.listar();
}

void listarPartidoBaja(){
    ArchivoPartido arc;
    arc.listarBajas();
}

void modificarArbitro(){
    int idPartido;
    cout<<"INGRESE EL ID DEL PARTIDO AL QUE DESEA MODIFICARLE EL ARBITRO: ";
    cin>>idPartido;
    ArchivoPartido arc;
    int pos = arc.buscarRegistro(idPartido);
    if(pos<0){
        cout<<"NO HAY PARTIDO CON ESE ID ";
        cout<<endl;
        return;
}
    Partidos obj = arc.leerRegistro(pos);
    char vecAux[30];
    cout<<"INGRESE EL NUEVO ARBITRO DEL PARTIDO: ";
    cargarCadena(vecAux,29);
    obj.setArbitro(vecAux);
    arc.modificarRegistro(obj, pos);
}

void bajaLogicaPartido(){
    cout<<"INGRESE EL ID DEL PARTIDO A DAR DE BAJA: ";
    int idPartido;
    cin>>idPartido;
    ArchivoPartido arc;
    int pos = arc.buscarRegistro(idPartido);
    if(pos < 0){
        cout<<"NO EXISTE UN PARTIDO CON ESE ID EN EL ARCHIVO"<<endl;
        return;
    }
    Partidos obj = arc.leerRegistro(pos);
    if(obj.getEstado() == false){
        cout<<"EL PARTIDO YA SE ENCUENTRA DADO DE BAJA"<<endl;
        return;
    }
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
    cout<<"PARTIDO DADO DE BAJA CORRECTAMENTE"<<endl;
}

void darPartidoDeAlta(){
    cout<<"INGRESE EL ID DEL PARTIDO A DAR DE ALTA: ";
    int idPartido;
    cin>>idPartido;
    ArchivoPartido arc;
    int pos = arc.buscarRegistro(idPartido);
    if(pos < 0){
        cout<<"NO EXISTE UN PARTIDO CON ESE ID EN EL ARCHIVO"<<endl;
        return;
    }
    Partidos obj = arc.leerRegistro(pos);
    if(obj.getEstado() == true){
        cout<<"EL PARTIDO YA SE ENCUENTRA DADO DE ALTA"<<endl;
        return;
    }
    obj.setEstado(true);
    arc.modificarRegistro(obj, pos);
    cout<<"PARTIDO DADO DE ALTA CORRECTAMENTE"<<endl;
}

void consultarPartidosPorArbitro(){
    ArchivoPartido arc;
    Partidos* vec= nullptr;
    int cantReg= arc.contarRegistros();
    if(cantReg<=0){
        cout<<"NO HAY PARTIDOS REGISTRADOS"<<endl;
        return;
    }
    char arbitroBuscado[30];
    cout<<"INGRESE EL NOMBRE DEL ARBITRO A BUSCAR: ";
    cargarCadena(arbitroBuscado, 29);
    vec = new Partidos[cantReg];
    if(vec==nullptr){
        cout<<"NO SE PUDO RESERVAR LA MEMORIA";
        return;
    }
    int cont= 0;
    Partidos obj;
    for(int i=0; i<cantReg; i++){
        obj = arc.leerRegistro(i);
        if(strcasecmp(obj.getArbitro(), arbitroBuscado) == 0){
            vec[cont] = obj;
            cont++;
        }
    }
    system("cls");
    if(cont == 0){
        cout<<"NO SE ENCONTRARON PARTIDOS ARBITRADOS POR "<<arbitroBuscado<<endl;
        delete[] vec;
        return;
    }
    cout<<"=========================================="<<endl;
    cout<<" PARTIDOS ARBITRADOS POR "<<arbitroBuscado<<endl;
    cout<<"=========================================="<<endl;
    for(int i=0; i<cont-1; i++){
        for(int j=0; j<cont-1-i; j++){
            Fecha f1 = vec[j].getFechaPartido();
            Fecha f2 = vec[j+1].getFechaPartido();
            if(f1.getAnio()>f2.getAnio() ||
               (f1.getAnio()==f2.getAnio() && f1.getMes()>f2.getMes()) ||
               (f1.getAnio()==f2.getAnio() && f1.getMes()==f2.getMes() && f1.getDia()>f2.getDia()))
            {
                Partidos temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
    for(int i=0; i<cont; i++){
        vec[i].mostrarPartido();
    }
    delete[] vec;
}

void consultarPartidosPorFecha(){
    ArchivoPartido arc;
    int cantReg= arc.contarRegistros();
    if (cantReg<=0){
        cout<<"NO HAY PARTIDOS REGISTRADOS"<<endl;
        return;
    }
    Fecha fechaBuscada;
    cout<<"INGRESE LA FECHA A BUSCAR: "<<endl;
    fechaBuscada.cargarFecha();
    bool band= false;
    system("cls");
    cout<<"=========================================="<<endl;
    cout << "    PARTIDOS JUGADOS EL   ";
    fechaBuscada.mostrarFecha();
    cout<<"=========================================="<<endl;
    for (int i=0;i<cantReg;i++){
        Partidos obj= arc.leerRegistro(i);
        Fecha fechaPartido= obj.getFechaPartido();
        if (fechaPartido.getDia() == fechaBuscada.getDia() && fechaPartido.getMes() == fechaBuscada.getMes() && fechaPartido.getAnio() == fechaBuscada.getAnio()){
            obj.mostrarPartido();
            band = true;
        }
    }
    if(!band){
        cout<<endl;
        cout<<"NO SE ENCONTRARON PARTIDOS PARA LA FECHA: ";
        fechaBuscada.mostrarFecha();
        cout<<endl;
    }
}
