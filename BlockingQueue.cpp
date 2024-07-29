#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "BlockingQueue.h"


struct casillaBQ* inicial = NULL;       // COMIENZO DE LA COLA VACÍO (CONDICIONES INICIALES)


/*
    @brief	Función que permite cadenas de texto a la cola
    @param	texto:  cadena que se va a almacenar en la cola | Dato de tipo string (char[])
*/
void enqueueBQ(const char* texto) {
    struct casillaBQ* nuevaCasilla = (struct casillaBQ*)malloc(sizeof(struct casillaBQ));
    
    // Para algunos editores es:
    //strcpy(nuevaCasilla->texto, texto);

    // Para otros es: 
    strcpy_s(nuevaCasilla->texto, texto);
    nuevaCasilla->status = false;
    nuevaCasilla->siguiente = NULL;
    
    // Si no hay nada en la cola, metemos la cadena de texto en primera posición
    if (isEmptyBQ()) {
        inicial = nuevaCasilla;
    }

    // Si hay más elementos, debemos recorrer la cola hasta el último elemento
    else {
        struct casillaBQ* temp = inicial;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevaCasilla;
    }

    printf("\nSe encol%c el elemento: %s\n", 162, texto);
}


/*
    @brief	Función que permite eliminar un elemento dependiendo si no está bloqueado
            'status' es la que define si puede o no desencolarse
*/
void dequeueBQ() {
    if (isEmptyBQ()) {
        printf("\nLa cola est%c vac%ca, no se puede eliminar nada\n", 160, 161);
        return;
    }

    // Apuntadores para encontrar el comienzo y el elemento a eliminar
    struct casillaBQ* temporal = inicial;
    struct casillaBQ* anterior = NULL;

    // Debemos verificar que sea un elemento desbloqueado
    while (temporal != NULL && temporal->status == true) {
        anterior = temporal;
        temporal = temporal->siguiente;
    }

    // Si todos los elementos están bloqueados, no podemos desencolar
    if (temporal == NULL) {
        printf("\nNo hay elementos desbloqueados para desencolar\n");
        return;
    }

    // Si se eliminó el elemento desbloqueado, debemos mover los apuntadores
    if (anterior == NULL) {
        inicial = inicial->siguiente;
    }
    else {
        anterior->siguiente = temporal->siguiente;
    }

    printf("\nSe desencol%c el elemento: %s\n", 162, temporal->texto);
    free(temporal);
}


/*
    @brief	Función que permite cambiar el status de un elemento para bloquear o desbloquear
    @param	texto:  cadena que se va a buscar en la cola | Dato de tipo string (char[])
*/
void changeStatusBQ(const char* texto) {
    struct casillaBQ* temp = inicial;
    while (temp != NULL) {

        // Si el elemento existe, solamente cambiamos su status usando el operador !
        if (strcmp(temp->texto, texto) == 0) {
            temp->status = !temp->status;
            printf("\nEl elemento %s ha cambiado de status\n", texto);
            return;
        }
        temp = temp->siguiente;
    }
    printf("\nNo se encontr%c el elemento: %s\n", 162, texto);
}


/*
    @brief	Función que permite visualizar el contenido de la cola
    @param
*/
void showBQ(void) {
    struct casillaBQ* temporal = inicial;
    printf("\nLa cola es:\nTEXTO\t\tSTATUS\n\n");
    while (temporal != NULL) {
        if (temporal->status == false) {
            printf("%s\t\t'FALSE'\n", temporal->texto);
        }
        else {
            printf("%s\t\t'TRUE'\n", temporal->texto);
        }
        temporal = temporal->siguiente;
    }
    printf("\n");
}


/*
    @brief	Función que permite saber el tamaño de cola (elementos que hay dentro de ella)
    @param
*/
void sizeBQ(void) {
    int cont = 0;
    struct casillaBQ* temporal = inicial;
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
bool isEmptyBQ(void) {
    return (inicial == NULL);
}


/*
    @brief	Función que permite saber el elemento que está al inicio de la cola
    @param
    @return inicio de cola
*/
char* peekBQ(void) {
    if (isEmptyBQ()) { 
        printf("La cola est%c vac%ca: sin elementos al frente\n", 160, 161); 
        return NULL; 
    } else { return inicial->texto; }
}




/*
    // IMPLEMENTACIÓN EJEMPLIFICADA

    enqueueBQ("Jaime");
    enqueueBQ("Xochitl");
    enqueueBQ("Juan");
    enqueueBQ("Pedro");
    enqueueBQ("Alejandra");
    enqueueBQ("Edgar");
    enqueueBQ("Cristian");
    enqueueBQ("Pablo");
    enqueueBQ("Miguel");
    enqueueBQ("Ximena");
    enqueueBQ("Jenna");
    enqueueBQ("Johan");
    enqueueBQ("Fernando");
    enqueueBQ("Manuel");

    sizeBQ();
    //printf("Peek: %s", &peekBQ);
    showBQ();

    dequeueBQ();
    sizeBQ();
    showBQ();

    changeStatusBQ("Martin");
    changeStatusBQ("Juan");
    changeStatusBQ("Alejandra");
    changeStatusBQ("Jenna");
    changeStatusBQ("Manuel");

    for(int i=0; i < sizeBQ(); i++){
        dequeueBQ();
    }

    showBQ();

*/