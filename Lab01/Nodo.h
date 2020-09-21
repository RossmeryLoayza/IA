#ifndef NODO_H
#define NODO_H
#include <iostream>

using namespace std;

class Nodo
{
    public:
        int x_pos;
        int y_pos;
        Nodo *padre;
        Nodo **hijos;
        Nodo();
        Nodo(int x , int y , int num_hijos);
        void imprimir_dato();
        void set_datos(int x , int y , int num_hijos);
        virtual ~Nodo();

    protected:

    private:
};

#endif // NODO_H
