#pragma once
#ifndef _AVL_TREE_H
#define _AVL_TREE_H

struct NodoAVLT {
	char dato;
	struct NodoAVLT* left, * right;
	int altura;
};

int getAltura(struct NodoAVLT* nodo);
int getMax(int M, int m);
int getBalance(struct NodoAVLT* nodo);
struct NodoAVLT* addNodo(char dato);
struct NodoAVLT* rotarDerecha(struct NodoAVLT* nodo);
struct NodoAVLT* rotarIzquierda(struct NodoAVLT* nodo);
struct NodoAVLT* insertar(struct NodoAVLT* nodo, char dato);
void show_AVL_TREE(NodoAVLT* root);

#endif // !_AVL_TREE_H
