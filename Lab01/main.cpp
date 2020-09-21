#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "Nodo.h"
#include "Grafo.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Prueba grafo" << endl;
    Grafo b(10,3);
    b.imprimir_vertices();
    b.generar_grafo();
    b.imprimir_tabla_ady();
    b.imprimir_tabla_pesos();
    b.busqueda_HC();
    b.busqueda_amplitud();
    return 0;
}
