#pragma once
#ifndef _STACK_H
#define _STACK_H

struct casillaS {
    int numero;
    struct casillaS* siguiente;
};

void push(int numero);
void pop(void);
void showS(void);
void sizeS(void);
bool isEmptyS(void);
int stack_pointer(void);

#endif // ! _STACK_H
