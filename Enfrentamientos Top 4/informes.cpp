#include <iostream>
#include "informes.h"
#include "claseArchivoPartido.h"
#include "claseArchivoJugador.h"

using namespace std;

void promedioGolesPorPartido(){
    int sumaGoles=0;
    int sumaGolesLoc=0;
    int sumaGolesVis=0;
    float promedio=0;
    float promedioLoc=0;
    float promedioVis=0;
    Partidos obj;
    ArchivoPartido arc;
    int partidosTotales= arc.contarRegistros();
    if(partidosTotales<1){
        cout<<"NO HAY PARTIDOS REGISTRADOS"<<endl;
        return;
    }
    for(int i=0;i<partidosTotales;i++){
        obj = arc.leerRegistro(i);
        sumaGoles+= obj.getGolesLocales();
        sumaGoles+= obj.getGolesVisitante();
        sumaGolesLoc+= obj.getGolesLocales();
        sumaGolesVis+= obj.getGolesVisitante();
    }
    promedio=(float)sumaGoles/partidosTotales;
    promedioLoc=(float)sumaGolesLoc/partidosTotales;
    promedioVis=(float)sumaGolesVis/partidosTotales;
    cout<<"==================================================================================="<<endl;
    cout<<"EL PROMEDIO DE GOLES POR PARTIDO ES DE: "<<promedio<<endl;
    cout<<endl;
    cout<<"SIENDO QUE LOS EQUIPOS LOCALES PROMEDIAN UN TOTAL DE "<<promedioLoc<<" GOLES "<<endl;
    cout<<"POR PARTIDO, MIENTRAS QUE LOS VISITANTES PROMEDIAN "<<promedioVis<<endl;
    cout<<"==================================================================================="<<endl;
    cout<<endl;
}

void cantJugadoresPorClub(){
    int vec[4]{};
    int idClub;
    Jugadores obj;
    ArchivoJugador arc;
    int cantJugadores= arc.contarRegistros();
    if(cantJugadores<1){
        cout<<"NO HAY JUGADORES REGISTRADOS"<<endl;
        return;
    }
    for(int i=0;i<cantJugadores;i++){
        obj= arc.leerRegistro(i);
        idClub=obj.getIdClub();
        vec[idClub-1]++;
    }
    cout<<"===================================================================================="<<endl;
    cout<<"CANTIDAD DE JUGADORES QUE CONFORMAN EL PLANTEL ACTUAL DEL MANCHESTER CITY: "<<vec[0]<<endl;
    cout<<endl;
    cout<<"CANTIDAD DE JUGADORES QUE CONFORMAN EL PLANTEL ACTUAL DEL CHELSEA: "<<vec[1]<<endl;
    cout<<endl;
    cout<<"CANTIDAD DE JUGADORES QUE CONFORMAN EL PLANTEL ACTUAL DEL MANCHESTER UNITED: "<<vec[2]<<endl;
    cout<<endl;
    cout<<"CANTIDAD DE JUGADORES QUE CONFORMAN EL PLANTEL ACTUAL DEL LIVERPOOL: "<<vec[3];
    cout<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<endl;
}

void partidosPorEstadio (){
    int vec[4]{};
    int aux;
    ArchivoPartido arc;
    Partidos obj;
    int cantReg;
    cantReg= arc.contarRegistros();
    if(cantReg<1){
        cout<<"NO HAY PARTIDOS REGISTRADOS"<<endl;
        return;
    }
     for(int i=0;i<cantReg;i++){
        obj= arc.leerRegistro (i);
        aux= obj.getIdPartidoEquipoLocal();
        vec[aux-1]++;
     }
    cout<<"==============================================================="<<endl;
    cout<< "CLASICOS JUGADOS EN EL ETIHAD STADIUM (MANCHESTER CITY): "<<vec[0]<<endl;
    cout<<endl;
    cout<< "CLASICOS JUGADOS EN EL STAMFORD BRIDGE (CHELSEA): "<<vec[1]<<endl;
    cout<<endl;
    cout<< "CLASICOS JUGADOS EN EL  OLD TRAFFORD (MANCHESTER UNITED): "<<vec[2]<<endl;
    cout<<endl;
    cout<< "CLASICOS JUGADOS EN EL ANFIELD (LIVERPOOL): "<<vec[3]<<endl;
    cout<<"==============================================================="<<endl;
    cout<<endl;
}

void partidosPorAnio()
{
    int anio;
    cout << "INGRESE EL AÑO A CONSULTAR: ";
    cin >> anio;
    ArchivoPartido arc;
    int totalPartidos;
    totalPartidos = arc.contarPartidosPorAnio(anio);
    cout<<"========================================="<<endl;
    cout << "TOTAL: " << totalPartidos << " CLASICOS JUGADOS ESE AÑO" << endl;
    cout<<"========================================="<<endl;
    cout<<endl;
}
