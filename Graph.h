#pragma once
#ifndef _GRAPH_H
#define _GRAPH_H

// Estructura para los grafos no ponderados
struct adjNode {
	int destino;
	struct adjNode* siguiente;
};


// Estructura para los grafos ponderados
struct adjPNode {
	int destino;
	float peso;
	struct adjPNode* siguiente;
};


// Lista de adyacencia de los grafos no ponderados
struct adjArray {
	struct adjNode* head;
};


// Lista de adyacencia de los grafos ponderados
struct adjPArray {
	struct adjPNode* head;
};


// Estructura para la correcta creación de los grafos
struct Graph {
	int V;
	struct adjArray* array;
	struct adjPArray* parray;
};

void createGraph(int V);
void addEdgeSG(int origen, int destino);
void addEdgeDG(int origen, int destino);
void addEdgeSPG(int origen, int destino, float peso);
void addEdgeDPG(int origen, int destino, float peso);
void printGraph(void);
void printPGraph(void);

#endif // !_GRAPH_H

