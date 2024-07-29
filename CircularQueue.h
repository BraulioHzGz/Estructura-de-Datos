#pragma once
#ifndef _CIRCULAR_QUEUE_H
#define _CIRCULAR_QUEUE_H

struct nodoCQ {
    int numero;
    struct nodoCQ* siguiente;
    struct nodoCQ* anterior;
};


void enqueueCQ(int numero);
void dequeueCQ(int posicion);
void showCQ(void);
bool isEmptyCQ(void);
int sizeCQ(void);

#endif // !_CIRCULAR_QUEUE_H

