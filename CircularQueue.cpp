#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "CircularQueue.h"


struct nodoCQ* raiz = NULL;     // COMIENZO DE COLA VAC�A (CONDICIONES INICIALES)


/*
    @brief	Funci�n que permite agregar n�meros a la cola
    @param	numero: valor que se va a almacenar en la cola | Dato de tipo entero (int)
*/
void enqueueCQ(int numero) {
    struct nodoCQ* nuevoNodo = (struct nodoCQ*)malloc(sizeof(struct nodoCQ));
    nuevoNodo->numero = numero;

    // Caso en el que no hay nada en la cola
    if (raiz == NULL) {
        nuevoNodo->siguiente = nuevoNodo;
        nuevoNodo->anterior = nuevoNodo;
        raiz = nuevoNodo;
    }

    // Caso en el que hay otros elementos dentro
    else {
        // Se hace un movimiento de apuntadores y actualizaci�n de �ndices
        struct nodoCQ* ultimo = raiz->anterior;
        nuevoNodo->siguiente = raiz;
        nuevoNodo->anterior = ultimo;
        raiz->anterior = nuevoNodo;
        ultimo->siguiente = nuevoNodo;
    }
    printf("\nSe insert%c el elemento: %d\n", 162, numero);
}


/*
    @brief	Funci�n que permite saber el tama�o de cola (elementos que hay dentro de ella)
    @param
    @return Tama�o de cola
*/
int sizeCQ(void) {
    int cont = 0;
    if (!isEmptyCQ()) {
        struct nodoCQ* temp = raiz;     // Auxiliar para hacer el recorrido
        do {
            cont++;
            temp = temp->siguiente;
        } while (temp != raiz);
    }
    return cont;
}


/*
    @brief	Funci�n que permite eliminar un valor en una determinada posici�n
    @param
*/
void dequeueCQ(int posicion) {

    // Validamos que la posici�n ingresada est� dentro del tama�o actual de la cola
    if (posicion <= sizeCQ()) {
       
        // Caso en el que la posici�n que se elimina es la primera
        if (posicion == 1) {

            // Caso en el que solo hay un elemento
            if (sizeCQ() == 1) {
                free(raiz);
                raiz = NULL;
            }
            else {      // Debemos hacer un moviminto en posiciones y apuntadores
                struct nodoCQ* temp = raiz;
                struct nodoCQ* ultimo = raiz->anterior;
                raiz = raiz->siguiente;
                ultimo->siguiente = raiz;
                raiz->anterior = ultimo;
                free(temp);
            }
        }
        else {
            struct nodoCQ* temp = raiz;

            // Ciclo for para recorrer las posiciones hasta llegar a la posici�n establecida
            for (int i = 1; i <= posicion - 1; i++) {
                temp = temp->siguiente;
            }
            struct nodoCQ* aux = temp;
            struct nodoCQ* ant = temp->anterior;
            temp = temp->siguiente;
            ant->siguiente = temp;
            temp->anterior = ant;
            free(aux);
        }
        printf("\nSe elimin%c el elemento en la posici%cn: %d\n", 162, 162, posicion);
    }
    else {
        printf("\nLa posici%cn ingresada supera el tama�o de cola\n", 162);
    }
}


/*
    @brief	Funci�n que permite saber si la cola est� vac�a o no
    @param
    @return inicio de cola
*/
bool isEmptyCQ(void) {
    return (raiz == NULL);
}


/*
    @brief	Funci�n que permite visualizar el contenido de la cola
    @param
*/
void showCQ(void) {
    printf("\nLa lista es: ");
    if (!isEmptyCQ()) {
        struct nodoCQ* temp = raiz;     // Auxiliar para recorrer la cola
        do {
            printf("\n%d", temp->numero);
            temp = temp->siguiente;
        } while (temp != raiz);
    }
    printf("\n");
}



/*
    // IMPLEMENTACI�N EJEMPLIFICADA

    enqueueCQ(1);
    enqueueCQ(2);
    enqueueCQ(10);
    enqueueCQ(4);
    enqueueCQ(5);

    printf("\nTama�o de cola: %i\n", sizeCQ());
    showCQ();

    dequeueCQ(10);
    dequeueCQ(1);

    printf("\nTama�o de cola: %i\n", sizeCQ());
    showCQ();

*/