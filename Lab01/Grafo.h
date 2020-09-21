#ifndef GRAFO_H
#define GRAFO_H
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <math.h>
#include <queue>
#include <list>
#include "Nodo.h"

class Grafo
{
    public:
        Nodo *aristas;
        int num_vertices;
        int num_aristas;
        bool **matriz_ady;
        int **tabla_pesos;
        Grafo();
        Grafo(int n_aristas , int n_relacion);
        void generar_grafo();
        void imprimir_vertices();
        void imprimir_tabla_pesos();
        void imprimir_tabla_ady();
        void ordenar(int i , int *b);
        void ordenar_pesos(int i , int llegada , int *b);
        void busqueda_amplitud();
        void busqueda_HC();
        virtual ~Grafo();

    protected:

    private:
};

#endif // GRAFO_H
