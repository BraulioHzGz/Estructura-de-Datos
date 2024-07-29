#pragma once
#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

struct casillaPQ {
    char letra;
    int prioridad;
    struct casillaPQ* siguiente;
};

void enqueuePQ(char letra, int prioridad);
void dequeuePQ();
void dequeuePriorityPQ(int prioridad);
void showPQ();
void sizePQ();
char peekPQ();
bool isEmptyPQ();


#endif // !_PRIORITY_QUEUE_H

