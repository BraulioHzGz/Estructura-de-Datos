#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BTree.h"


struct BTree* startTree(bool is_leaf) {
	struct BTree* newNode = (struct BTree*)malloc(sizeof(struct BTree));
	if (newNode != NULL) {
		newNode->claves = 0;
		newNode->is_leaf = is_leaf;
		for (int i = 0; i < MAX_CAPACITY; i++) {
			newNode->child[i] = NULL;
		}
	}
	else {
		printf("\n\n No se puede asignar memoria para el %carbol B\n", 160);
	}
	return newNode;
}


void split_Child(struct BTree* parent, int indice) {
	struct BTree* child = parent->child[indice];
	struct BTree* newNode = startTree(child->is_leaf);
	newNode->claves = (MAX_CAPACITY / 2) - 1;

	for (int i = 0; i < MAX_CAPACITY / 2; ++i) {
		newNode->capacidad[i] = child->capacidad[i + MAX_CAPACITY / 2];
	}

	if (!child->is_leaf) {
		for (int i = 0; i < MAX_CAPACITY / 2; ++i) {
			newNode->child[i] = child->child[i + MAX_CAPACITY / 2];
		}
	}

	child->claves = (MAX_CAPACITY / 2) - 1;

	for (int i = parent->claves - 1; i > indice; i--) {
		parent->child[i + 1] = parent->child[i];
	}
	parent->child[indice + 1] = newNode;

	for (int i = parent->claves - 1; i >= indice; i--) {
		parent->capacidad[i + 1] = parent->capacidad[i];
	}
	parent->capacidad[indice] = child->capacidad[(MAX_CAPACITY / 2) - 1];
	parent->claves++;
}


void Insert_if_Non_Full(struct BTree* nodo, int numero) {
	int j = nodo->claves - 1;
	if (nodo->is_leaf) {
		while(j >= 0 && nodo->capacidad[j] > numero) {
			nodo->capacidad[j + 1] = nodo->capacidad[j];
			j--;
		}
		nodo->capacidad[j + 1] = numero;
		nodo->claves++;
	}
	else {
		while (j >= 0 && nodo->capacidad[j] > numero) {
			j--;
		}
		j++;

		if (nodo->child[j]->claves == MAX_CAPACITY - 1) {
			split_Child(nodo, j);
			if (nodo->capacidad[j] < numero) {
				j++;
			}
		}
		Insert_if_Non_Full(nodo->child[j], numero);

	}
}


void insertBT(struct BTree** root, int numero) {
	struct BTree* newNode = *root;
	if (newNode == NULL) {
		(*root) = startTree(true);
		(*root)->capacidad[0] = numero;
		(*root)->claves = 1;
	}
	else {
		if (newNode->claves == MAX_CAPACITY - 1) {
			struct BTree* aux = startTree(false);
			aux->child[0] = newNode;
			split_Child(aux, 0);
			*root = aux;
		}
		Insert_if_Non_Full(*root, numero);
	}
}


void printBTree(struct BTree* root) {
	int indice;
	if (root != NULL) {
		for (indice = 0; indice < root->claves; indice++) {
			printBTree(root->child[indice]);
			printf("%d\t", root->capacidad[indice]);
		}
		printBTree(root->child[indice]);
	}
}




/*
	// IMPLEMENTACIÓN EJEMPLIFICADA

	struct BTree *root = NULL;

	insert(&root, <value>);
	...

	printBTree(root);

*/