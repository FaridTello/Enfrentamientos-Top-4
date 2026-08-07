#include <iostream>
#include "menus.h"
#include "archivoClubes.h"
#include "archivoJugadores.h"
#include "archivoPartidos.h"
#include "claseArchivoClub.h"
#include "claseArchivoJugador.h"
#include "claseArchivoPartido.h"
#include "informes.h"

using namespace std;

void menu(){
    while(true){
        int opc;
        system("cls");
        cout<<"*** GESTION DE EQUIPOS ***"<<endl;
        cout<<"========================"<<endl;
        cout<<"1- MENU ADMIN"<<endl;
        cout<<"2- MENU LISTADOS"<<endl;
        cout<<"3- MENU CONSULTAS"<<endl;
        cout<<"4- MENU REPORTES"<<endl;
        cout<<"0- SALIR"<<endl;
        cout<<"========================"<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                menuAdmin();
                break;
            case 2:
                menuListados();
                break;
            case 3:
                menuConsultas();
                break;
            case 4:
                menuInformes();
                break;
            case 0:
                return;
        }
        system("pause");
    }
}

void menuAdmin(){
    while(true){
        int opc;
        system("cls");
        cout<<"*** MENU ADMIN ***"<<endl;
        cout<<"==================="<<endl;
        cout<<"1- SUB MENU CLUBES"<<endl;
        cout<<"2- SUB MENU JUGADORES"<<endl;
        cout<<"3- SUB MENU PARTIDOS"<<endl;
        cout<<"0- SALIR "<<endl;
        cout<<"==================="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                subMenuClubes();
                break;
            case 2:
                subMenuJugadores();
                break;
            case 3:
                subMenuPartidos();
                break;
            case 0:
                return;
                break;
        }
        system("pause");
    }
}

void subMenuClubes(){
    while(true){
        int opc;
        system("cls");
        cout<<"*** SUBMENU CLUBES *** "<<endl;
        cout<<"========================"<<endl;
        cout<<"1- AGREGAR CLUB"<<endl;
        cout<<"2- LISTAR TODOS LOS CLUBES"<<endl;
        cout<<"3- LISTAR CLUBES DADOS DE BAJA"<<endl;
        cout<<"4- MODIFICAR TORNEOS GANADOS"<<endl;
        cout<<"5- DAR DE BAJA A UN CLUB"<<endl;
        cout<<"6- DAR DE ALTA A UN CLUB"<<endl;
        cout<<"0- SALIR "<<endl;
        cout<<"========================"<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                agregarClub();
                break;
            case 2:
                listarClub();
                break;
            case 3:
                listarClubBaja();
                break;
            case 4:
                modificarTorneosGanados();
                break;
            case 5:
                bajaLogicaClub();
                break;
            case 6:
                darClubDeAlta();
                break;
            case 0:
                return;
                break;
        }
        system("pause");
    }
}

void subMenuJugadores(){
    while(true){
        int opc;
        system("cls");
        cout<<"****** SUBMENU JUGADORESS *******"<<endl;
        cout<<"================================"<<endl;
        cout<<"1- AGREGAR JUGADOR"<<endl;
        cout<<"2- LISTAR TODOS LOS JUGADORES"<<endl;
        cout<<"3- LISTAR JUGADORES DADOS DE BAJA"<<endl;
        cout<<"4- MODIFICAR NUMERO DE CAMISETA"<<endl;
        cout<<"5- DAR DE BAJA A UN JUGADOR"<<endl;
        cout<<"6- DAR DE ALTA A UN JUGADOR"<<endl;
        cout<<"0- SALIR "<<endl;
        cout<<"================================"<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                agregarJugador();
                break;
            case 2:
                listarJugador();
                break;
            case 3:
                listarJugadorBaja();
                break;
            case 4:
                modificarCamiseta();
                break;
            case 5:
                bajaLogicaJugador();
                break;
            case 6:
                darJugadorDeAlta();
                break;
            case 0:
                return;
                break;
        }
        system("pause");
    }
}

void subMenuPartidos(){
     while(true){
        int opc;
        system("cls");
        cout<<"******** SUBMENU PARTIDOS ********"<<endl;
        cout<<"==================================="<<endl;
        cout<<"1- AGREGAR PARTIDO"<<endl;
        cout<<"2- LISTAR TODOS LOS PARTIDOS"<<endl;
        cout<<"3- LISTAR PARTIDOS DADOS DE BAJA"<<endl;
        cout<<"4- MODIFICAR ARBITRO DE UN PARTIDO"<<endl;
        cout<<"5- DAR DE BAJA UN PARTIDO"<<endl;
        cout<<"6- DAR DE ALTA UN PARTIDO"<<endl;
        cout<<"0- SALIR "<<endl;
        cout<<"==================================="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                agregarPartido();
                break;
            case 2:
                listarPartido();
                break;
            case 3:
                listarPartidoBaja();
                break;
            case 4:
                modificarArbitro();
                break;
            case 5:
                bajaLogicaPartido();
                break;
            case 6:
                darPartidoDeAlta();
                break;
            case 0:
                return;
                break;
        }
        system("pause");
    }
}

void menuConsultas(){
    while(true){
        int opc;
        system("cls");
        cout<<"************** MENU CONSULTAS **************"<<endl;
        cout<<"================================================"<<endl;
        cout<<"1- CONSULTAR PARTIDOS POR ARBITRO"<<endl;
        cout<<"2- CONSULTAR PARTIDOS POR FECHA"<<endl;
        cout<<"3- CONSULTAR CLUBES POR ID"<<endl;
        cout<<"4- CONSULTAR JUGADORES POR ID"<<endl;
        cout<<"5- CONSULTAR JUGADOR POR FECHA DE NACIMIENTO"<<endl;
        cout<<"0- SALIR "<<endl;
        cout<<"================================================"<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                consultarPartidosPorArbitro();
                break;
            case 2:
                consultarPartidosPorFecha();
                break;
            case 3:
                consultarClubPorId();
                break;
            case 4:
                consultarJugadorPorId();
                break;
            case 5:
                consultarJugadorPorFecha();
                break;
            case 0:
                return;
                break;
        }
        system("pause");
    }
}

void menuListados(){
    ArchivoClub arcClub;
    while(true){
        int opc;
        system("cls");
        cout<<"********** MENU LISTADOS **********"<<endl;
        cout<<"======================================="<<endl;
        cout<<"1- LISTAR JUGADORES POR EQUIPO"<<endl;
        cout<<"2- LISTAR JUGADORES POR POSICION"<<endl;
        cout<<"3- LISTAR CLUBES POR LIGAS GANADAS"<<endl;
        cout<<"4- LISTAR CLUBES POR ANTIGUEDAD"<<endl;
        cout<<"5- LISTAR TODOS LOS ENFRENTAMIENTOS ENTRE DOS EQUIPOS"<<endl;
        cout<<"0- SALIR "<<endl;
        cout<<"======================================="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                subMenuListadoJugXClub();
                break;
            case 2:
                subMenuListadoJugXPos();
                break;
            case 3:
                arcClub.listarPorTorneos();
                break;
            case 4:
                arcClub.listarPorAntiguedad();
                break;
            case 5:
                subMenuListadoEnfrentamientos();
                break;
            case 0:
                return;
                break;
        }
        system("pause");
    }
}

void subMenuListadoJugXClub(){
    ArchivoJugador arcJug;
    while(true){
        int opc;
        system("cls");
        cout<<"*** SUBMENU LISTADO JUGADORES POR CLUB ***"<<endl;
        cout<<"============================================"<<endl;
        cout<<"1- LISTAR JUGADORES DEL MANCHESTER CITY"<<endl;
        cout<<"2- LISTAR JUGADORES DEL CHELSEA"<<endl;
        cout<<"3- LISTAR JUGADORES DEL MANCHESTER UNITED"<<endl;
        cout<<"4- LISTAR JUGADORES DEL LIVERPOOL"<<endl;
        cout<<"0- SALIR "<<endl;
        cout<<"============================================"<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                arcJug.listarJugadoresPorClub(1);
                break;
            case 2:
                arcJug.listarJugadoresPorClub(2);
                break;
            case 3:
                arcJug.listarJugadoresPorClub(3);
                break;
            case 4:
                arcJug.listarJugadoresPorClub(4);
                break;
            case 0:
                return;
                break;
        }
        system("pause");
    }
}

void subMenuListadoJugXPos(){
    ArchivoJugador arcJug;
    while(true){
        int opc;
        system("cls");
        cout<<"*** LISTADO JUGADORES POR POSICION ***"<<endl;
        cout<<"====================================="<<endl;
        cout<<"1- LISTAR TODOS LOS ARQUEROS"<<endl;
        cout<<"2- LISTAR TODOS LOS DEFENSORES"<<endl;
        cout<<"3- LISTAR TODOS LOS MEDIOCAMPISTAS"<<endl;
        cout<<"4- LISTAR TODOS LOS DELANTEROS"<<endl;
        cout<<"0- SALIR "<<endl;
        cout<<"====================================="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                arcJug.listarJugadoresPorPosicion(1);
                break;
            case 2:
                arcJug.listarJugadoresPorPosicion(2);
                break;
            case 3:
                arcJug.listarJugadoresPorPosicion(3);
                break;
            case 4:
                arcJug.listarJugadoresPorPosicion(4);
                break;
            case 0:
                return;
                break;
        }
        system("pause");
    }
}

void subMenuListadoEnfrentamientos(){
    int primerEquipo, segundoEquipo;
    ArchivoPartido arcPart;
        int opcUno;
        system("cls");
        cout<<"*** SELECCIONE AL PRIMER EQUIPO ***"<<endl;
        cout<<"====================================="<<endl;
        cout<<"1- MANCHESTER CITY"<<endl;
        cout<<"2- CHELSEA"<<endl;
        cout<<"3- MANCHESTER UNITED"<<endl;
        cout<<"4- LIVERPOOL"<<endl;
        cout<<"====================================="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opcUno;
        system("cls");
        switch(opcUno){
            case 1:
                primerEquipo=1;
                break;
            case 2:
                primerEquipo=2;
                break;
            case 3:
                primerEquipo=3;
                break;
            case 4:
                primerEquipo=4;
                break;
            case 0:
                return;
                break;
        }
        system("pause");
        int opcDos;
        system("cls");
        cout<<"*** SELECCIONA AL SEGUNDO EQUIPO ***"<<endl;
        cout<<"====================================="<<endl;
        cout<<"1- MANCHESTER CITY"<<endl;
        cout<<"2- CHELSEA"<<endl;
        cout<<"3- MANCHESTER UNITED"<<endl;
        cout<<"4- LIVERPOOL"<<endl;
        cout<<"====================================="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opcDos;
        system("cls");
        switch(opcDos){
            case 1:
                segundoEquipo=1;
                break;
            case 2:
                segundoEquipo=2;
                break;
            case 3:
                segundoEquipo=3;
                break;
            case 4:
                segundoEquipo=4;
                break;
            case 0:
                return;
                break;
        }
        system("pause");
    if(primerEquipo==segundoEquipo){
        cout<<"ERROR. DEBE ELEGIR DOS EQUIPOS DISTINTOS."<<endl;
        return;
    }
    arcPart.listarEnfrentamientosEntreEquipos(primerEquipo, segundoEquipo);
}

void menuInformes(){
    while(true){
        int opc;
        system("cls");
        cout<<"*************** MENU INFORMES ***************"<<endl;
        cout<<"=============================================="<<endl;
        cout<<"1- CANTIDAD DE CLASICOS JUGADOS EN UN AÑO"<<endl;
        cout<<"2- CANTIDAD DE JUGADORES POR CLUB"<<endl;
        cout<<"3- CANTIDAD DE CLASICOS JUGADOS POR ESTADIO"<<endl;
        cout<<"4- PROMEDIO DE GOLES POR CLASICO"<<endl;
        cout<<"0- SALIR "<<endl;
        cout<<"=============================================="<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                partidosPorAnio();
                break;
            case 2:
                cantJugadoresPorClub();
                break;
            case 3:
                partidosPorEstadio();
                break;
            case 4:
                promedioGolesPorPartido();
                break;
            case 0:
                return;
                break;
        }
        system("pause");
    }
}
