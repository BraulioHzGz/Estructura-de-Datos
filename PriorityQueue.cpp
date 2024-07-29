#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "PriorityQueue.h"


struct casillaPQ* inicial = NULL;   // COMIENZO DE LA COLA VACÍO (CONDICIONES INICIALES)


/*
    @brief	Función que permite agregar letra a la cola con una prioridad
    @param	letra:     valor que se va a almacenar en la cola | Dato de tipo carácter (char)
    @param  prioridad: prioridad del elemento | Dato de tipo entero (int)
*/
void enqueuePQ(char letra, int prioridad) {
    struct casillaPQ* nuevaCasilla = (struct casillaPQ*)malloc(sizeof(struct casillaPQ));
    nuevaCasilla->letra = letra;
    nuevaCasilla->prioridad = prioridad;
    nuevaCasilla->siguiente = NULL;

    // Si no hay elementos en la cola ponemos este elemento como comienzo de cola
    if (isEmptyPQ() || inicial->prioridad >= prioridad) {
        nuevaCasilla->siguiente = inicial;
        inicial = nuevaCasilla;
    }

    else {
        struct casillaPQ* temp = inicial;   // Auxiliar para buscar dónde se debe de insertar

        // Hacemos un recorrido hasta encontrar dónde añadir el elemento de acuerdo
        // con la prioridad que se la pasó
        while (temp->siguiente != NULL && temp->siguiente->prioridad < prioridad) {
            temp = temp->siguiente;
        }

        nuevaCasilla->siguiente = temp->siguiente;
        temp->siguiente = nuevaCasilla;
    }
    printf("\nSe encol%c el elemento: %c con prioridad: %d\n", 162, letra, prioridad);
}


/*
    @brief	Función que permite eliminar un valor bajo la regla FIFO (First In First Out)
            sin importar su prioridad
*/
void dequeuePQ() {
    if (isEmptyPQ()) {      // Si no hay nada en la cola no eliminamos nada
        printf("\nLa cola est%c vac%ca, no se puede eliminar nada\n", 160, 161);
        return;
    }
    struct casillaPQ* temporal = inicial;
    inicial = inicial->siguiente;
    printf("\nSe desencol%c el elemento: %c con prioridad: %d\n", 162, 
        temporal->letra, temporal->prioridad);
    free(temporal);
}


/*
    @brief	Función que permite eliminar un valor bajo la regla FIFO (First In First Out)
            dependiendo la prioridad seleccionada
    @param  prioridad: prioridad a buscar | Dato de tipo entero (int)
*/
void dequeuePriorityPQ(int prioridad) {
    // Si la cola está vacía no eliminamos nada
    if (isEmptyPQ()) {
        printf("\nLa cola est%c vac%ca, no se puede eliminar nada\n", 160, 161);
        return;
    }

    // Auxiliares para mover apuntadores de inicio y fin para desencolar elementos
    struct casillaPQ* temporal = inicial;
    struct casillaPQ* anterior = NULL;

    while (temporal != NULL && temporal->prioridad != prioridad) {  // Hacemos un recorrido
        anterior = temporal;
        temporal = temporal->siguiente;
    }

    // Si la prioridad pasada no existe
    if (temporal == NULL) {
        printf("\nNo se encontr%c un elemento con prioridad %d\n", 162, prioridad);
        return;
    }

    // Movemos la posición inicial solo si el elemento 0 se eliminó
    if (anterior == NULL) {
        inicial = temporal->siguiente;
    } else {
        // Movemos las posiciones de los elementos para no dejar espacios en blanco
        anterior->siguiente = temporal->siguiente;
    }
    printf("\nSe desencol%c el elemento: %c con prioridad: %d\n", 162, 
        temporal->letra, temporal->prioridad);
    free(temporal);
}


/*
    @brief	Función que permite visualizar el contenido de la cola
    @param
*/
void showPQ(void) {
    struct casillaPQ* temporal = inicial;
    printf("\nLa cola es:\n");
    while (temporal != NULL) {
        printf("%c\t", temporal->letra);
        temporal = temporal->siguiente;
    }
    printf("\n");
}


/*
    @brief	Función que permite saber el tamaño de cola (elementos que hay dentro de ella)
    @param
*/
void sizePQ(void) {
    int cont = 0;
    struct casillaPQ* temporal = inicial;
    while (temporal != NULL) {
        cont++;
        temporal = temporal->siguiente;
    }
    printf("\nTama%co de cola: %d\n", 164, cont);
}


/*
    @brief	Función que permite saber si la cola está vacía o no
    @param
    @return inicio de cola
*/
bool isEmptyPQ(void) {
    return (inicial == NULL);
}


/*
    @brief	Función que permite saber el elemento que está al inicio de la cola
    @param
    @return inicio de cola
*/
char peekPQ(void) {
    if (isEmptyPQ()) { 
        printf("La cola est%c vac%ca: sin elementos al frente\n", 160, 161); 
        return '\0'; 
    } else { return inicial->letra; }
}




/*
    // IMPLEMENTACIÓN EJEMPLIFICADA

    enqueuePQ('A', 1);
    enqueuePQ('B', 1);
    enqueuePQ('C', 2);
    enqueuePQ('D', 3);
    enqueuePQ('E', 5);
    enqueuePQ('F', 1);
    enqueuePQ('G', 4);

    printf("\nPeek: %c\n", peerPQ());
    sizePQ();
    showPQ();

    dequeuePQ()
    dequeuePriorityPQ(1);

    showPQ();

*/