#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "CircularQueue.h"


struct nodoCQ* raiz = NULL;     // COMIENZO DE COLA VACÍA (CONDICIONES INICIALES)


/*
    @brief	Función que permite agregar números a la cola
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
        // Se hace un movimiento de apuntadores y actualización de índices
        struct nodoCQ* ultimo = raiz->anterior;
        nuevoNodo->siguiente = raiz;
        nuevoNodo->anterior = ultimo;
        raiz->anterior = nuevoNodo;
        ultimo->siguiente = nuevoNodo;
    }
    printf("\nSe insert%c el elemento: %d\n", 162, numero);
}


/*
    @brief	Función que permite saber el tamaño de cola (elementos que hay dentro de ella)
    @param
    @return Tamaño de cola
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
    @brief	Función que permite eliminar un valor en una determinada posición
    @param
*/
void dequeueCQ(int posicion) {

    // Validamos que la posición ingresada esté dentro del tamaño actual de la cola
    if (posicion <= sizeCQ()) {
       
        // Caso en el que la posición que se elimina es la primera
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

            // Ciclo for para recorrer las posiciones hasta llegar a la posición establecida
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
        printf("\nLa posici%cn ingresada supera el tamaño de cola\n", 162);
    }
}


/*
    @brief	Función que permite saber si la cola está vacía o no
    @param
    @return inicio de cola
*/
bool isEmptyCQ(void) {
    return (raiz == NULL);
}


/*
    @brief	Función que permite visualizar el contenido de la cola
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
    // IMPLEMENTACIÓN EJEMPLIFICADA

    enqueueCQ(1);
    enqueueCQ(2);
    enqueueCQ(10);
    enqueueCQ(4);
    enqueueCQ(5);

    printf("\nTamaño de cola: %i\n", sizeCQ());
    showCQ();

    dequeueCQ(10);
    dequeueCQ(1);

    printf("\nTamaño de cola: %i\n", sizeCQ());
    showCQ();

*/