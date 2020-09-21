Integrantes:

- Rossmery Loayza

En la clase Grafo hay las siguientes funciones:

	- El constructor Grafo que recibe 2 parametros: numero de vertices y el numero de relaciones por aristas.
	- La funcion generar_grafo(), que genera 'n' vertices aleatorios en un plano (100 x 100), crea 'm' relaciones con los nodos mas cercanos, estas relaciones se guardan en una matriz de adyacencia y tambien se genera una tabla de pesos que almacena las distancias entre todos los nodos.
	- imprimir_vertices(), imprime los puntos 'X' y 'Y' de los nodos.
	- imprimir_tabla_pesos(), imprime la tabla de pesos creada entre nodos.
	- imprimir_tabla_ady(); imprime la tabla de las relaciones existentes entre los nodos.
	- ordenar(int, int*); esta funcion se usa al momento de generar las relaciones entre los nodos, recibe el numero de posicion del Nodo y ordena las distancias de menor a mayor y las distancias menores seran sus aristas a los demas nodos.
	- ordenar_pesos(int a, int b, int *c); ordena las distancias de los nodos adyacentes a 'a' segun su distancia con 'b' y las posiciones ordenadas son guardadas en 'c'. Esta funcion se usa en busqueda_HC
	- busqueda_amplitud(), busqueda por amplitud en el grafo
	- busqueda_HC(), busqueda Hill Climbing en el grafo