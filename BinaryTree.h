#pragma once
#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

typedef struct NodoBT {
	float numero;
	struct NodoBT* left, * right;
} NodoBT;

NodoBT* startTree(float numero);
NodoBT* insertBinT(NodoBT* root, float numero);
void deleteLeaf(NodoBT* root, NodoBT* l_node);
NodoBT* deleteBinT(NodoBT* root, float numero);
void InOrden(NodoBT* root);
void PreOrden(NodoBT* root);
void PostOrden(NodoBT* root);

#endif // !_BINARY_TREE_H

