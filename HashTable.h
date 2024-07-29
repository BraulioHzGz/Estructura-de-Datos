#pragma once
#ifndef _HASH_MAP_H
#define _HASH_MAP_H

struct casillaHM {
    char texto[30];     // -> key
    int value;          // -> value
    struct casillaHM* siguiente;
};


void addHM(const char* texto, int value);
void deleteHM(const char* texto, int value);
int sizeHM(void);
void showHM(void);
bool isEmptyHM(void);
int getHM(const char* texto);
void containsKeyHM(const char* texto);
void containsValueHM(int value);

#endif // !_HASH_MAP_H

