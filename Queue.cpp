#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "Queue.h"

// CONDICIONES INICIALES
struct casillaQ* inicial = NULL;    // COMIENZO DE COLA VAC�O
struct casillaQ* final = NULL;      // FIN DE COLA VAC�O


/*
    @brief	Funci�n que permite agregar n�meros a la cola
    @param	numero: valor que se va a almacenar en la cola | Dato de tipo entero (int)
*/
void enqueue(int numero) {
    struct casillaQ* nuevaCasilla = (struct casillaQ*)malloc(sizeof(struct casillaQ));
    nuevaCasilla->numero = numero;
    nuevaCasilla->siguiente = NULL;
    
    // Si es el primer elemento, inicio y final est�n en la misma posici�n
    if (isEmptyQ()) {
        inicial = nuevaCasilla;
        final = nuevaCasilla;
    }

    // Si hay m�s elementos, se debe actualizar el final de la cola
    else {
        final->siguiente = nuevaCasilla;
        final = nuevaCasilla;
    }
    printf("\nSe encol%c el elemento: %d\n", 162, numero);
}


/*
    @brief	Funci�n que permite eliminar un valor bajo la regla FIFO (First In First Out)
    @param
*/
void dequeue(void) {
    if (isEmptyQ()) {
        printf("\nLa cola est%c vac%ca, no se puede eliminar nada\n", 160, 161);
        return;
    }
    else {
        int numero = inicial->numero;
        struct casillaQ* temporal = inicial;
        
        // Si solo hay un elemento y se desencola, no hay nada en la cola
        if (inicial == final) {
            inicial = NULL;
            final = NULL;
        }

        // Al eliminar debemos mover el comienzo de cola a �ndice + 1
        else {
            inicial = inicial->siguiente;
        }
        printf("\nSe desencol%c el elemento: %d\n", 162, numero);
    }
}


/*
    @brief	Funci�n que permite visualizar el contenido de la cola
    @param
*/
void showQ(void) {
    struct casillaQ* temporal = inicial;    // apuntador auxiliar para el recorrido
    printf("\nLa cola es:\n");
    while (temporal != NULL) {
        printf("%d\t", temporal->numero);
        temporal = temporal->siguiente;
    }
    printf("\n");
}


/*
    @brief	Funci�n que permite saber el tama�o de cola (elementos que hay dentro de ella)
    @param
*/
void sizeQ(void) {
    int cont = 0;
    if (isEmptyQ()) {
        printf("\nTama%co de cola: %d\n", 164, cont);
    }
    else {
        struct casillaQ* temporal = inicial;    // apuntador auxiliar para el recorrido
        while (temporal != NULL) {
            cont++;
            temporal = temporal->siguiente;
        }
        printf("\nTama%co de cola: %d\n", 164, cont);
    }
    
}


/*
    @brief	Funci�n que permite saber si la cola est� vac�a o no
    @param
    @return inicio de cola
*/
bool isEmptyQ(void) {
    return (inicial == NULL);
}


/*
    @brief	Funci�n que permite saber el elemento que est� al inicio de la cola
    @param
    @return inicio de cola
*/
int peekQ(void) {
    if (isEmptyQ()) { 
        printf("La cola est%c vac%ca: sin elementos al frente\n", 160, 161); 
        return -1; 
    } else { return inicial->numero; }
}




/*
    // IMPLEMENTACI�N EJEMPLIFICADA

    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(100);
    enqueue(1);
    enqueue(2);

    peekQ();
    sizeQ();
    showQ();

    dequeue();
    peekQ();
    sizeQ();
    showQ();

*/