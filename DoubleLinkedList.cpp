#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"


struct casillaDLL* START_DLL;   // COMIENZO DE LISTA VACÍA (CONDICIONES INICIALES)


/*
    @brief	Función que permite agregar un valor desde el comienzo
    @param	numero: valor que se va a almacenar en la lista | Dato de tipo decimal (float)
*/
void InsertarInicioDLL(float numero) {
    struct casillaDLL* temp = (struct casillaDLL*)malloc(sizeof(struct casillaDLL));
    temp->numero = numero;
    temp->siguiente = NULL;
    if (START_DLL == NULL) {
        START_DLL = temp;
        return;
    }
    else {
        temp->siguiente = START_DLL;
        START_DLL = temp;
    }
}


/*
    @brief	Función que permite agregar un valor desde el final
    @param	numero: valor que se va a almacenar en la lista | Dato de tipo decimal (float)
*/
void InsertarFinalDLL(float numero) {
    struct casillaDLL* temp = (struct casillaDLL*)malloc(sizeof(struct casillaDLL));
    temp->numero = numero;
    temp->siguiente = NULL;
    if (START_DLL == NULL) {
        START_DLL = temp;
        return;
    }
    else {
        struct casillaDLL* aux = START_DLL;
        while (aux->siguiente != NULL) { aux = aux->siguiente; }
        aux->siguiente = temp;
    }
}


/*
    @brief	Función que permite agregar un valor en una determinada posición
    @param	numero: valor que se va a almacenar en la lista | Dato de tipo decimal (float)
    @param  pos:    posición de la lista | Dato de tipo entero (int)
*/
void InsertarPosDLL(int pos, float numero) {
    struct casillaDLL* temp = (struct casillaDLL*)malloc(sizeof(struct casillaDLL));
    temp->numero = numero;
    temp->siguiente = NULL;
    if (START_DLL == NULL) {
        START_DLL = temp;
        return;
    }
    else {
        struct casillaDLL* prev = NULL;
        struct casillaDLL* aux = START_DLL;
        for (int i = 0; i < pos; i++) {
            prev = aux;
            aux = aux->siguiente;
        }
        temp->siguiente = aux;
        prev->siguiente = temp;
    }
}


/*
    @brief	Función que eliminar un valor al comienzo de la lista
    @param
*/
void EliminarInicioDLL(void) {
    if (START_DLL == NULL) {
        printf("\nLa lista est%c vac%ca: no se puede eliminar elemento\n", 160, 161);
        return;
    }
    else {
        struct casillaDLL* temp = START_DLL;
        START_DLL = START_DLL->siguiente;
        free(temp);
        printf("\nSe ha eliminado el nodo inicial\n");
    }
}


/*
    @brief	Función que eliminar un valor al final de la lista
    @param
*/
void EliminarFinalDLL(void) {
    if (START_DLL == NULL) {
        printf("\nLa lista est%c vac%ca: no se puede eliminar elemento\n", 160, 161);
        return;
    }
    else if (START_DLL->siguiente == NULL) {
        struct casillaDLL* temp = START_DLL;
        START_DLL = temp->siguiente;
        free(temp);
    }
    else {
        struct casillaDLL* temp = START_DLL;
        struct casillaDLL* prev = NULL;
        while (temp->siguiente != NULL) {
            prev = temp;
            temp = temp->siguiente;
        }
        prev->siguiente = NULL;
        free(temp);
        printf("\nSe ha eliminado el nodo final\n");
    }
}


/*
    @brief	Función que permite mostrar el contenido de la lista doblemente ligada
    @param
*/
void showDLL(void) {
    printf("\nContenido de la lista:\n");
    if (START_DLL == NULL) {
        printf("\nLa lista est%c vac%ca\n", 160, 161);
        return;
    }
    struct casillaDLL* temp = START_DLL;
    while (temp != NULL) {
        printf("%0.2f ->\t", temp->numero);
        temp = temp->siguiente;
    }
    free(temp);
    printf("\n");
}


/*
    @brief	Función que permite buscar un elemento en la lista
    @param  numero: valor que se va a buscar en la lista | Dato de tipo decimal (float)
*/
void buscarDLL(float numero) {
    printf("\nB%csqueda del valor: %0.2f\n", 163, numero);
    if (START_DLL == NULL) {
        printf("La lista est%c vac%ca\n", 160, 161);
        return;
    }
    struct casillaDLL* temp = START_DLL;
    while (temp != NULL) {
        if (numero == temp->numero) {
            printf("\nEl elemento si est%c en la lista\n", 160);
            break;
        }
        temp = temp->siguiente;
    }
    if (temp == NULL) {
        printf("\nEl elemento no est%c en la lista\n", 160);
    }
    free(temp);
}


/*
    @brief	Función que permite mostrar el tamaño de lista (cuántos elementos hay)
    @param
    @return Tamaño de lista
*/
int sizeDLL(void) {
    int cont = 0;
    if (START_DLL == NULL) { return cont; }
    struct casillaDLL* temp = START_DLL;
    while (temp != NULL) {
        cont++;
        temp = temp->siguiente;
    }
    free(temp);
    return cont;
}




/*
    // IMPLEMENTACIÓN EJEMPLIFICADA
    InsertarInicioDLL(50.0f);
    InsertarInicioDLL(25.2f);
    InsertarFinalDLL(13.5f);
    InsertarFinalDLL(14.4f);

    printf("\nTamaño de lista: %d\n", sizeDLL());
    showDLL();

    InsertarInicioDLL(10.0f);
    InsertarFinalDLL(2.7f);

    showDLL();

    buscarDLL(1.0f);
    buscarDLL(2.7f);

    InsertarPosDLL(1, 45.5f);
    InsertarPosDLL(3, 1.0f);

    printf("\nTamaño de lista: %d\n", sizeDLL());
    showDLL();

    EliminarFinalDLL();
    EliminarFinalDLL();

    printf("\nTamaño de lista: %d\n", sizeDLL());
    showDLL();

    EliminarInicioDLL();

    printf("\nTamaño de lista: %d\n", sizeDLL());
    showDLL();

*/