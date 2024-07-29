#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

struct casillaS* tope = NULL;   // TOPE DE PILA VACÍO (CONDICIONES INICIALES)


/*
    @brief	Función que permite agregar números a la pila
    @param	numero: valor que se va a almacenar en la pila | Dato de tipo entero (int)
*/
void push(int numero) {
    struct casillaS* nuevaCasilla = (struct casillaS*)malloc(sizeof(struct casillaS));
    if (nuevaCasilla == NULL) {
        printf("\nError en la asignaci%cn de memoria -> Can't push on the stack\n", 162);
        return;
    }
    nuevaCasilla->numero = numero;
    nuevaCasilla->siguiente = tope;
    tope = nuevaCasilla;
    printf("\nSe agreg%c el elemento: %d\n", 162, numero);
}


/*
    @brief	Función que permite eliminar un valor bajo la regla LIFO (Last In First Out)
    @param	
*/
void pop(void) {
    if (tope != NULL) {
        struct casillaS* temporal = tope;
        tope = tope->siguiente;
        free(temporal);
        printf("\nSe elimin%c el %cltimo elemento\n", 162, 163);
    }
    else {
        printf("\n\nLa pila est%c vac%ca, no se puede eliminar nada\n", 160, 161);
    }
}


/*
    @brief	Función que permite visualizar el contenido de la pila
    @param
*/
void showS(void) {
    printf("\n\nLa pila es:\n");
    struct casillaS* temporal = tope;   // apuntador auxiliar para el recorrido
    while (temporal != NULL) {
        printf("%i\n", temporal->numero);
        temporal = temporal->siguiente;
    }
}


/*
    @brief	Función que permite saber el tamaño de pila (elementos que hay dentro de ella)
    @param
*/
void sizeS(void) {
    int cont = 0;
    struct casillaS* temporal = tope;   // apuntador auxiliar para el recorrido
    while (temporal != NULL) {
        cont++;
        temporal = temporal->siguiente;
    }
    printf("\nTamaño de pila: %d\n", cont);
}


/*
    @brief	Función que permite saber si la pila está vacía o no
    @param
    @return tope de pila
*/
bool isEmptyS(void) {
    return tope == NULL;
}


/*
    @brief	Función que permite saber el elemento que está al tope de la pila
    @param
    @return tope de pila
*/
int stack_pointer(void) {
    if (tope == NULL) {     // No hay nada en la pila
        return -1;
    }
    return tope->numero;
}




/*
    // IMPLEMENTACIÓN EJEMPLIFICADA

    push(5);
    push(9);
    push(13);
    push(2);
    push(8);
    push(100);

    sizeS();
    printf("\nStack pointer: %d\n", stack_pointer());
    showS();

    pop();

    sizeS();
    printf("\nStack pointer: %d\n", stack_pointer());
    showS();

*/