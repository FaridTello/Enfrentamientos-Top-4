#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED

class Fecha{
    private:
        int _dia;
        int _mes;
        int _anio;
    public:
        Fecha(int d=1, int m=1, int a=1900);
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        int getDia();
        int getMes();
        int getAnio();
        void cargarFecha();
        void mostrarFecha();
};

#endif // CLASEFECHA_H_INCLUDED
