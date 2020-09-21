#include "Grafo.h"

Grafo::Grafo()
{
    aristas = NULL;
    num_vertices = 0;
    num_aristas = 0;
    matriz_ady = NULL;
    tabla_pesos = NULL;
}

Grafo::Grafo(int n_vertices , int n_relacion)
{
    num_aristas = n_relacion;
    int arreglo[n_vertices*2];
    int aux = 0;
    int limite_inferior = 0;
    int limite_superior = 100;

    srand(time(0));

    for(int i = 0; i < 20; i++)
    {
        aux = (limite_inferior + rand() % (limite_superior));
        int aux2 = 0;
        while(aux2 < i)
        {
            if(aux != arreglo[aux2])
            {
                aux2++;
            }
            else
            {
                aux = (limite_inferior + rand() % (limite_superior));
                aux2 = 0;
            }
        }
        arreglo[i] = aux;
        //cout << arreglo[i] << " - ";
    }
    //cout << endl;
    int j = 0;
    aristas = new Nodo[n_vertices];
    for (int i = 0 ; i < n_vertices ; i++)
    {
        aristas[i].set_datos(arreglo[j],arreglo[j+1],n_relacion);
        j = j+2;
    }
    num_vertices = n_vertices;
    matriz_ady = new bool *[n_vertices];
    tabla_pesos = new int *[n_vertices];
    for (int i = 0 ; i < n_vertices ; i++)
    {
        matriz_ady[i] = new bool[n_vertices];
        tabla_pesos[i] = new int[n_vertices];
    }
}

void Grafo::generar_grafo()
{
    for (int i = 0 ; i < num_vertices ; i++)
    {
        for(int j = 0 ; j < num_vertices ; j++)
        {
            if (i == j)
            {
                tabla_pesos[i][j] = 0;
            }
            else
            {
                tabla_pesos[i][j] = sqrt(pow((aristas[i].x_pos-aristas[j].x_pos),2)+pow((aristas[i].y_pos-aristas[j].y_pos),2));
            }
            matriz_ady[i][j] = 0;
        }
    }
    int adyac[num_vertices];
    int cont[num_vertices];
    for(int i = 0 ; i < num_vertices ; i++)
    {
        adyac[i] = 0;
        cont[i] = 0;

    }
    for (int i = 0 ; i < num_vertices ; i++)
    {
        ordenar(i,adyac);
        for (int c = 0 ; c <= num_vertices ; c++)
        {
            int j = adyac[c];
            if(matriz_ady[i][c] == 0 && cont[i] < num_aristas && i != j)
            {
                /*matriz_ady[i][j] = matriz_ady[j][i] = 1;
                cont[i] = cont[i]+1;
                cont[j] = cont[j]+1;*/
                matriz_ady[i][j] = 1;
                cont[i] = cont[i]+1;
            }
        }
    }
}

void Grafo::imprimir_vertices()
{
    for (int i = 0 ; i < num_vertices ; i++)
    {
        aristas[i].imprimir_dato();
        cout << "---------------------------------" << endl;
    }
}

void Grafo::imprimir_tabla_pesos()
{
    cout << "TABLA DE PESOS: " << endl;
    for (int i = 0 ; i < num_vertices ; i++)
    {
        for(int j = 0 ; j < num_vertices ; j++)
        {
            cout << tabla_pesos[i][j] << "   ";
        }
        cout << endl;
    }
}

void Grafo::imprimir_tabla_ady()
{
    cout << "MATRIZ DE ADYACENCIA: " << endl;
    for (int i = 0 ; i < num_vertices ; i++)
    {
        for(int j = 0 ; j < num_vertices ; j++)
        {
            cout << matriz_ady[i][j] << "   ";
        }
        cout << endl;
    }
}

void Grafo::ordenar(int i , int *b)
{
    int a[num_vertices];
    for (int z = 0 ; z < num_vertices ; z++)
    {
        a[z] = tabla_pesos[i][z];
        b[z] = z;
    }
    cout << "Fila: " << i << endl;
    for(int z = 0 ; z < num_vertices ; z++)
    {
        cout << a[z] << "  ";
    }
    cout << endl;
    for(int z = 0 ; z < num_vertices ; z++)
    {
        cout << b[z] << "  ";
    }
    cout << endl;
    for (int x = 0 ; x < num_vertices ; x++)
    {
        for (int y = 0 ; y < num_vertices-x-1 ; y++)
        {
            if(a[y] > a[y+1])
            {
                int tmp = a[y+1];
                int tmp2 = b[y+1];
                a[y+1] = a[y];
                b[y+1] = b[y];
                a[y] = tmp;
                b[y] = tmp2;
            }
        }
    }
    cout << "Fila " << i << " ordenada " << endl;
    for(int z = 0 ; z < num_vertices ; z++)
    {
        cout << a[z] << "  ";
    }
    cout << endl;
    for(int z = 0 ; z < num_vertices ; z++)
    {
        cout << b[z] << "  ";
    }
    cout << endl;
}

void Grafo::ordenar_pesos(int i , int llegada , int *b)
{
    int distancias[num_aristas];
    for(int j = 0 ; j < num_vertices ; j++)
    {
        if(matriz_ady[i][j] == 1)
            b[i] = j;
    }
    for(int j = 0 ; j < num_aristas ; j++)
    {
        int a = b[j];
        distancias[j] = tabla_pesos[a][llegada];
    }
    for (int x = 0 ; x < num_aristas ; x++)
    {
        for (int y = 0 ; y < num_aristas-x-1 ; y++)
        {
            if(distancias[y] > distancias[y+1])
            {
                int tmp = distancias[y+1];
                int tmp2 = b[y+1];
                distancias[y+1] = distancias[y];
                b[y+1] = b[y];
                distancias[y] = tmp;
                b[y] = tmp2;
            }
        }
    }
    for(int k = 0; k < num_aristas ; k++)
        cout << distancias[k] << "  ";
    cout << endl;
    for(int k = 0; k < num_aristas ; k++)
        cout << b[k] << "  ";
    cout << endl;
}

void Grafo::busqueda_amplitud()
{
    int partida;
    int llegada;
    int fin = 0;
    cout << "Ingrese punto de partida: ";
    cin >> partida;
    cout << "Ingrese destino: ";
    cin >> llegada;
    int actual;
    queue<int> cola;
    list<int> visitados;
    list<int>::iterator it;
    cola.push(partida);
    actual = cola.front();
    while(!cola.empty() && cola.front() != llegada)
    {
        fin = 0;
        cola.pop();
        for(it = visitados.begin() ; it != visitados.end() ; it++)
        {
            if(*it == actual)
            {
                fin = 1;
            }
        }
        if (fin == 0)
        {
            cout << actual << "  ";
            visitados.push_back(actual);
            int nodo_rel[num_aristas];
            int cont = 0;
            for(int k = 0 ; k < num_vertices ; k++)
            {
                if(matriz_ady[actual][k] == 1)
                {
                    nodo_rel[cont] = k;
                    cont++;
                }
            }
            while(cont < num_aristas)
            {
                for(it = visitados.begin() ; it != visitados.end() ; it++)
                {
                    if(*it == nodo_rel[cont])
                    {
                        fin = 1;
                    }
                }
                if(fin == 0)
                {
                    cola.push(nodo_rel[cont]);
                }
                cont++;
                fin = 0;
            }
        }
        actual = cola.front();
    }
    cout << actual << endl;
}

void Grafo::busqueda_HC()
{
    int partida;
    int llegada;
    int fin = 0;
    cout << "Ingrese punto de partida: ";
    cin >> partida;
    cout << "Ingrese destino: ";
    cin >> llegada;
    int actual;
    queue<int> cola;
    list<int> visitados;
    list<int>::iterator it;
    cola.push(partida);
    actual = cola.front();
    while(!cola.empty() && cola.front() != llegada)
    {
        fin = 0;
        cola.pop();
        for(it = visitados.begin() ; it != visitados.end() ; it++)
        {
            if(*it == actual)
            {
                fin = 1;
            }
        }
        if (fin == 0)
        {
            cout << actual << "  ";
            visitados.push_back(actual);
            int nodo_rel[num_aristas];
            ordenar_pesos(actual,llegada,nodo_rel);
            for(int k = 0 ; k < num_aristas ; k++)
            {
                cout << nodo_rel[k] << "  ";
            }
            cout << endl;
            int cont = 0;
            while(cont < num_aristas)
            {
                fin = 0;
                for(it = visitados.begin() ; it != visitados.end() ; it++)
                {
                    if(*it == nodo_rel[cont])
                    {
                        fin = 1;
                    }
                }
                if(fin == 0)
                    cola.push(nodo_rel[cont]);
                cont++;
            }
        }
        actual = cola.front();
    }
    cout << actual << endl;
}

Grafo::~Grafo()
{
    //dtor
}
