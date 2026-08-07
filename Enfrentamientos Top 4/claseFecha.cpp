#include <iostream>
#include "claseFecha.h"

using namespace std;

Fecha::Fecha(int d, int m, int a){
    _dia=d;
    _mes=m;
    _anio=a;
}

void Fecha::setDia(int d){
    _dia=d;
}

void Fecha::setMes(int m){
    _mes=m;
}

void Fecha::setAnio(int a){
    _anio=a;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

void Fecha::cargarFecha(){
    int aux;
    cout<<endl;
    cout<<"DIA: ";
    cin>>aux;
    setDia(aux);
    cout<<"MES: ";
    cin>>aux;
    setMes(aux);
    cout<<"AÑO: ";
    cin>>aux;
    setAnio(aux);
}

void Fecha::mostrarFecha(){
    cout<<getDia()<<"/"<<getMes()<<"/"<<getAnio()<<endl;
}
