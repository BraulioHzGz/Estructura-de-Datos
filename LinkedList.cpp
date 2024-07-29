#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


struct casillaLL* START;        // COMIENZO DE LA LISTA VAC�A (CONDICIONES INICIALES)


/*
    @brief	Funci�n que permite agregar letras a la lista ligada
    @param	letra:  valor que se va a almacenar en la lista | Dato de tipo car�cter (char)
*/
void Add_NodoLL(char letra) {
    struct casillaLL* temp = (struct casillaLL*)malloc(sizeof(struct casillaLL));
    temp->letra = letra;
    temp->siguiente = NULL;

    // Si no hay elementos en la lista, se actualiza el primer elemento en la lista
    if (START == NULL) {
        START = temp;
        return;
    }

    // Si hay m�s elementos, debemos recorrer hasta el �ltimo lugar para insertar
    else {
        struct casillaLL* aux = START;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = temp;
    }
}


/*
    @brief	Funci�n que permite agregar letras a la lista ligada en una determinada posici�n
    @param	letra:  valor que se va a almacenar en la cola | Dato de tipo car�cter (char)
    @param  pos:    posici�n de la lista | Dato de tipo entero (int)
*/
void Add_Nodo_PosicionLL(int pos, char letra) {
    struct casillaLL* temp = (struct casillaLL*)malloc(sizeof(struct casillaLL));
    temp->letra = letra;
    temp->siguiente = NULL;
    
    // Si no hay elementos en la lista, se actualiza el primer elemento en la lista
    if (START == NULL) {
        START = temp;
        return;
    }

    // Si hay m�s elementos, debemos recorrer hasta la posici�n ingresada
    else {
        struct casillaLL* prev = NULL;
        struct casillaLL* aux = START;
        for (int i = 0; i < pos; i++) {
            // Actualizamos apuntadores y recorremos elementos para meter el nuevo elemento
            prev = aux;
            aux = aux->siguiente;
        }
        temp->siguiente = aux;
        prev->siguiente = temp;
    }
}


/*
    @brief	Funci�n que eliminar el elemento al comienzo de la lista
    @param	
*/
void Eliminar_NodoLL(void) {
    if (START == NULL) {        // Si no hay nada en la lista, no eliminamos nada
        printf("\nLa lista est%c vac%ca\n", 160, 161);
        return;
    }
    else {          // Eliminamos el primer elemento y movemos el comienzo de la lista
        struct casillaLL* temp = START;
        START = START->siguiente;
        printf("\nSe ha eliminado el nodo\n");
    }
}


/*
    @brief	Funci�n que permite mostrar el contenido de la lista ligada
    @param
*/
void showLL(void) {
    printf("\nContenido de la lista:\n");
    if (START == NULL) {                // Si no hay nada en la lista, no mostramos nada
        printf("\nLa lista est%c vac%ca\n", 160, 161);
        return;
    }
    struct casillaLL* temp = START;     // Auxiliar para recorrer elemento por elemento
    while (temp != NULL) {
        printf("%c ->\t", temp->letra);
        temp = temp->siguiente;
    }
}


/*
    @brief	Funci�n que permite buscar un elemento en la lista
    @param  letra: valor que se va a buscar en la cola | Dato de tipo car�cter (char)
*/
void buscarLL(char letra) {
    printf("\nB%csqueda de la letra: %c", 163, letra);
    if (START == NULL) {
        printf("\nLa lista est%c vac%ca\n", 160, 161);
        return;
    }
    struct casillaLL* temp = START;     // Auxiliar para recorrer toda la lista
    while (temp != NULL) {
        if (letra == temp->letra) {     // Si est� la letra, indicamos que fue encontrado
            printf("\nEl elemento si est%c en la lista\n", 160);
            break;      // Dejamos de recorrer si ya fue encontrado
        }
        temp = temp->siguiente;
    }
    if (temp == NULL) {
        printf("\nEl elemento no est%c en la lista\n", 160);
    }
}


/*
    @brief	Funci�n que permite mostrar el tama�o de lista (cu�ntos elementos hay)
    @param  
    @return Tama�o de lista
*/
int sizeLL(void) {
    int cont = 0;
    if (START == NULL) {
        return cont;
    }
    struct casillaLL* temp = START;     // Auxiliar para recorrer la lista ligada
    while (temp != NULL) {
        cont++;
        temp = temp->siguiente;
    }
    return cont;
}




/*
    // IMPLEMENTACI�N EJEMPLIFICADA

    Add_NodoLL('A');
    Add_NodoLL('B');
    Add_NodoLL('C');
    Add_NodoLL('D');
    Add_NodoLL('E');

    printf("\nTama�o de lista: %d\n", sizeLL());
    showLL();

    Add_Nodo_PosicionLL(2, 'G');
    showLL();

    void buscarLL('M');
    void buscarLL('A');

    Eliminar_NodoLL();
    void buscarLL('A');

    printf("\nTama�o de lista: %d\n", sizeLL());
    showLL();

*/