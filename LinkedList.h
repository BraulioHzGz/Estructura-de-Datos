#pragma once
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

struct casillaLL {
    char letra;
    struct casillaLL* siguiente;
};


void Add_NodoLL(char letra);
void Add_Nodo_PosicionLL(int pos, char letra);
void Eliminar_NodoLL(void);
void showLL(void);
void buscarLL(char letra);
int sizeLL(void);

#endif // !_LINKED_LIST_H
