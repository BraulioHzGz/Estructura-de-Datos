#pragma once
#ifndef _DOUBLE_LINKED_LIST_H
#define _DOUBLE_LINKED_LIST_H

struct casillaDLL {
    float numero;
    struct casillaDLL* siguiente;
};


void InsertarInicioDLL(float numero);
void InsertarFinalDLL(float numero);
void InsertarPosDLL(int pos, float numero);
void EliminarInicioDLL(void);
void EliminarFinalDLL(void);
void showDLL(void);
void buscarDLL(float numero);
int sizeDLL(void);

#endif // !_DOUBLE_LINKED_LIST_H

