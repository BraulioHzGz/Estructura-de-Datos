#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"


struct Graph* graph;    // CREACIÓN DEL GRAFO


/*
    @brief	Estructura que permite crear un nodo con destino
    @param	destino: punto final del nodo/vértice | Dato de tipo entero (int)
    @return nuevo nodo
*/
struct adjNode* newAdjNode(int destino) {
    struct adjNode* newNode = (struct adjNode*)malloc(sizeof(struct adjNode));
    newNode->destino = destino;
    newNode->siguiente = NULL;
    return newNode;
}


/*
    @brief	Estructura que permite crear un nodo pondrado con destino 
    @param	destino: punto final del nodo/vértice | Dato de tipo entero (int)
    @param  peso:    peso que va a tener la arista | Dato de tipo decimal (float)
    @return nuevo nodo
*/
struct adjPNode* newAdjPNode(int destino, float peso) {
    struct adjPNode* newNode = (struct adjPNode*)malloc(sizeof(struct adjPNode));
    newNode->destino = destino;
    newNode->peso = peso;
    newNode->siguiente = NULL;
    return newNode;
}


/*
    @brief	Función que permite la creción del grafo con todos sus vértices
    @param	V: cantidad de nodos/vértices del grafo | Dato de tipo entero (int)
*/
void createGraph(int V) {
    graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct adjArray*)malloc(V * sizeof(struct adjArray));
    graph->parray = (struct adjPArray*)malloc(V * sizeof(struct adjPArray));

    // Ciclo for para poner todos los destinos y origenes en NULL
    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
        graph->parray[i].head = NULL;
    }
}




/*
    @brief	Función que permite la creción de una arista para un grafo simple
    @param	origen:  punto inicial del vértice | Dato de tipo entero (int)
    @param	destino: punto final del vértice | Dato de tipo entero (int)
*/
void addEdgeSG(int origen, int destino) {
    struct adjNode* newNode = newAdjNode(destino);
    newNode->siguiente = graph->array[origen].head;
    graph->array[origen].head = newNode;

    newNode = newAdjNode(origen);
    newNode->siguiente = graph->array[destino].head;
    graph->array[destino].head = newNode;

    // Estas líneas de código crean la conexión:  origen <-----> destino
}




/*
    @brief	Función que permite la creción de una arista para un grafo dirigido
    @param	origen:  punto inicial del vértice | Dato de tipo entero (int)
    @param	destino: punto final del vértice | Dato de tipo entero (int)
*/
void addEdgeDG(int origen, int destino) {
    struct adjNode* newNode = newAdjNode(destino);
    newNode->siguiente = graph->array[origen].head;
    graph->array[origen].head = newNode;

    // Estas líneas de código crean la conexión:  origen -----> destino
}




/*
    @brief	Función que permite la creción de una arista para un grafo ponderado simple
    @param	origen:  punto inicial del vértice | Dato de tipo entero (int)
    @param	destino: punto final del vértice | Dato de tipo entero (int)
    @param  peso:    peso que va a tener la arista | Dato de tipo decimal (float)
*/
void addEdgeSPG(int origen, int destino, float peso) {
    struct adjPNode* newNode = newAdjPNode(destino, peso);
    newNode->siguiente = graph->parray[origen].head;
    graph->parray[origen].head = newNode;

    newNode = newAdjPNode(origen, peso);
    newNode->siguiente = graph->parray[destino].head;
    graph->parray[destino].head = newNode;

    // Estas líneas de código crean la conexión:  origen <---(peso)---> destino
}




/*
    @brief	Función que permite la creción de una arista para un grafo ponderado dirigido
    @param	origen:  punto inicial del vértice | Dato de tipo entero (int)
    @param	destino: punto final del vértice | Dato de tipo entero (int)
    @param  peso:    peso que va a tener la arista | Dato de tipo decimal (float)
*/
void addEdgeDPG(int origen, int destino, float peso) {
    struct adjPNode* newNode = newAdjPNode(destino, peso);
    newNode->siguiente = graph->parray[origen].head;
    graph->parray[origen].head = newNode;

    // Estas líneas de código crean la conexión:  origen ----(peso)---> destino
}




/*
    @brief	Función que mostrará la lista de adyacencia de cada nodo/vértice en un grafo no ponderado
    @param	
*/
void printGraph(void) {
    for (int i = 0; i < graph->V; ++i) {
        struct adjNode* aux = graph->array[i].head;
        printf("\nLista de adyacencia del v%crtice %d es: \n", 130, i);
        while (aux) {
            printf("   %c>   %d", 196, aux->destino);
            aux = aux->siguiente;
        }
        printf("\n");
    }
}


/*
    @brief	Función que mostrará la lista de adyacencia de cada nodo/vértice en un grafo ponderado
    @param
*/
void printPGraph(void) {
    for (int i = 0; i < graph->V; ++i) {
        struct adjPNode* aux = graph->parray[i].head;
        printf("\nLista de adyacencia ponderada del v%crtice %d es: \n", 130, i);
        while (aux) {
            printf("   %c(PESO: %0.2f)%c>   %d", 196, aux->peso, 196, aux->destino);
            aux = aux->siguiente;
        }
        printf("\n");
    }
}




/*
    // IMPLEMENTACIÓN EJEMPLIFICADA

    int V = 5;

    createGraph(V);
    printf("\n\nGRAFO NO DIRIGIDO NO PONDERADO\n");
    addEdgeSG(0, 1);
    addEdgeSG(0, 4);
    addEdgeSG(1, 2);
    addEdgeSG(1, 3);
    addEdgeSG(1, 4);
    addEdgeSG(2, 3);
    addEdgeSG(3, 4);
    printGraph();


    createGraph(V);
    printf("\n\nGRAFO DIRIGIDO NO PONDERADO\n");
    addEdgeDG(0, 1);
    addEdgeDG(0, 4);
    addEdgeDG(1, 2);
    addEdgeDG(1, 3);
    addEdgeDG(1, 4);
    addEdgeDG(2, 3);
    addEdgeDG(3, 4);
    printGraph();


    createGraph(V);
    printf("\n\nGRAFO NO DIRIGIDO PONDERADO\n");
    addEdgeSPG(0, 1, 1.5);
    addEdgeSPG(0, 4, 2.0);
    addEdgeSPG(1, 2, 1.0);
    addEdgeSPG(1, 3, 0.5);
    addEdgeSPG(1, 4, 2.5);
    addEdgeSPG(2, 3, 1.2);
    addEdgeSPG(3, 4, 0.7);
    printPGraph();


    createGraph(V);
    printf("\n\nGRAFO DIRIGIDO PONDERADO\n");
    addEdgeDPG(0, 1, 1.5);
    addEdgeDPG(0, 4, 2.0);
    addEdgeDPG(1, 2, 1.0);
    addEdgeDPG(1, 3, 0.5);
    addEdgeDPG(1, 4, 2.5);
    addEdgeDPG(2, 3, 1.2);
    addEdgeDPG(3, 4, 0.7);
    printPGraph();

*/