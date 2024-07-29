#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H

struct casillaQ {
    int numero;
    struct casillaQ* siguiente;
};


void enqueue(int numero);
void dequeue(void);
void showQ(void);
void sizeQ(void);
bool isEmptyQ(void);
int peekQ(void);


#endif // !_QUEUE_H

