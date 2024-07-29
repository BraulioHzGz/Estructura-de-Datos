#pragma once
#ifndef _MIN_HEAP_H
#define _MIN_HEAP_H

struct Heap {
    int* array;
    int size;
    int capacidad;
};
typedef struct Heap heap;

heap* crearHeap(int capacidad, int* array);
void insertarAux(heap* h, int index);   //Función privada y exclusiva
void heapify(heap* h, int index);       //Función privada y exclusiva
void insertarHeapValue(heap* h, int value);
void showHeap(heap* h);
int MinHeap(heap* h);

#endif // !_MIN_HEAP_H

