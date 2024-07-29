#pragma once
#ifndef _BLOCKING_QUEUE_H
#define _BLOQKING_QUEUE_H

struct casillaBQ {
    char texto[20];
    bool status;
    struct casillaBQ* siguiente;
};

void enqueueBQ(const char* texto);
void dequeueBQ(void);
void changeStatusBQ(const char* texto);
void showBQ(void);
void sizeBQ(void);
bool isEmptyBQ(void);
char* peekBQ(void);

#endif // !_BLOCKING_QUEUE_H

