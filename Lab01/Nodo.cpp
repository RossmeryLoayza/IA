#include "Nodo.h"

Nodo::Nodo()
{
    x_pos = 0;
    y_pos = 0;
    padre = NULL;
    hijos = NULL;
}

Nodo::Nodo(int x , int y , int num_hijos)
{
    x_pos = x;
    y_pos = y;
    padre = NULL;
    hijos = new Nodo *[num_hijos];
}

void Nodo::imprimir_dato()
{
    cout << "X: " << x_pos << endl;
    cout << "Y: " << y_pos << endl;
}

void Nodo::set_datos(int x , int y , int num_hijos)
{
    x_pos = x;
    y_pos = y;
    padre = NULL;
    hijos = new Nodo *[num_hijos];
}

Nodo::~Nodo()
{
    //dtor
}
