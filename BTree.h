#pragma once
#ifndef _B_TREE_H
#define _B_TREE_H
#define MAX_CAPACITY 4

struct BTree {
	int claves;
	int capacidad[MAX_CAPACITY - 1];
	struct BTree* child[MAX_CAPACITY];
	bool is_leaf;
};

struct BTree* startTree(bool is_leaf);
void split_Child(struct BTree* parent, int indice);
void Insert_if_Non_Full(struct BTree* nodo, int numero);
void insertBT(struct BTree** root, int numero);
void printBTree(struct BTree* root);

#endif // !_B_TREE_H

