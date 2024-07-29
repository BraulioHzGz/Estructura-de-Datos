#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "HashTable.h"


struct casillaHM* TOP = NULL;       // COMIENZO DEL HASH MAP VACÍO (CONDICIONES INICIALES)


/*
    @brief	Función que permite agregar cadenas de texto con un ID a la tabla hash
    @param	texto:  cadena que se va a almacenar en la tabla | Dato de tipo string (char[])
    @param  value:  ID del elemento | Dato de tipo entero (int)
*/
void addHM(const char* texto, int value) {
    struct casillaHM* nuevaCasilla = (struct casillaHM*)malloc(sizeof(struct casillaHM));
    strcpy_s(nuevaCasilla->texto, texto);
    nuevaCasilla->value = value;
    nuevaCasilla->siguiente = NULL;

    if (TOP == NULL) { TOP = nuevaCasilla; }    // Si no hay elementos, lo añadimos primero
    else {      // Si hay elementos, debemos añadirlo al final
        struct casillaHM* temp = TOP;
        while (temp->siguiente != NULL) { temp = temp->siguiente; }
        temp->siguiente = nuevaCasilla;
    }
    //printf("Elemento %s ha sido agregado\n", texto);
}


/*
    @brief	Función que permite eliminar cadenas de texto con su ID de la tabla hash
    @param	texto:  cadena que se va a borrar de la tabla | Dato de tipo string (char[])
    @param  value:  ID del elemento | Dato de tipo entero (int)
*/
void deleteHM(const char* texto, int value) {
    if (isEmptyHM()) {      // Si no hay elementos, no hacemos nada
        printf("No es posible eliminar elementos, la tabla est%c vac%ca\n", 160, 161);
        return;
    }
    
    // Apuntadores auxiliares para mover elementos si fuese necesario
    struct casillaHM* temp = TOP;
    struct casillaHM* anterior = NULL;

    // Recorremos elemento a elemento hasta encontrar el valor
    while (temp != NULL) {
        if (strcmp(texto, temp->texto) == 0 && value == temp->value) {
            if (anterior == NULL) {     // Si el elemento es el primero, debemos mover TOP
                TOP = temp->siguiente;
            }
            else {          // Si hay más elementos, los recorremos para no dejar espacios
                anterior->siguiente = temp->siguiente;
            }
            free(temp);
            printf("Se elimin%c a %s con valor %d\n", 162, texto, value);
            return;
        }
        anterior = temp;
        temp = temp->siguiente;
    }
    printf("El elemento indicado no existe\n");     // Si se ingresa ID o nombre erroneo, no existe
}


/*
    @brief	Función que permite obtener el tamaño de la tabla hash (elementos que hay en ella)
    @param	
    @return Tamaño de la tabla hash
*/
int sizeHM(void) {
    int cont = 0;
    if (TOP == NULL) {
        return cont;
    }
    else {
        struct casillaHM* temp = TOP;   // Auxiliar para recorrer los elementos
        while (temp != NULL) {
            cont++;
            temp = temp->siguiente;
        }
    }
    return cont;
}


/*
    @brief	Función que permite mostrar el contenido de la tabla hash
    @param
*/
void showHM(void) {
    struct casillaHM* temp = TOP;
    printf("\nCONTENIDO DE LA TABLA HASH: \n");
    while (temp != NULL) {
        printf("%-10s\tKEY: %d\n", temp->texto, temp->value);
        temp = temp->siguiente;
    }
    printf("\n");
}


/*
    @brief	Función que permite ver si la tabla está vacía o no
    @param
    @return Tope de la tabla hash
*/
bool isEmptyHM(void) {
    return TOP == NULL;
}


/*
    @brief	Función que obtiene el ID de un elemento | Getter
    @param  texto:  cadena que se va a buscar en la tabla | Dato de tipo string (char[])
    @return ID del elemento
*/
int getHM(const char* texto) {
    int value = -1;
    struct casillaHM* temp = TOP;
    while (temp != NULL) {
        if (strcmp(texto, temp->texto) == 0) {      // El elemento fue encontrado
            value = temp->value;
            return value;
        }
        temp = temp->siguiente;
    }
    return value;
}


/*
    @brief	Función que indica si un elemento está en la tabla con base en el texto asociado.
    @param  texto:  cadena que se va a buscar en la tabla | Dato de tipo string (char[])
*/
void containsKeyHM(const char* texto) {
    struct casillaHM* temp = TOP;
    bool encontrado = false;
    while (temp != NULL) {
        if (strcmp(texto, temp->texto) == 0) {
            encontrado = true;
            break;
        }
        temp = temp->siguiente;
    }
    if (encontrado) {
        printf("True\n");
    }
    else {
        printf("False\n");
    }
}


/*
    @brief	Función que indica si un elemento está en la tabla con base en el ID asociado
    @param  value:  ID del elemento | Dato de tipo entero (int)
*/
void containsValueHM(int value) {
    struct casillaHM* temp = TOP;
    bool encontrado = false;
    while (temp != NULL) {
        if (value == temp->value) {
            encontrado = true;
            break;
        }
        temp = temp->siguiente;
    }
    if (encontrado) {
        printf("True\n");
    }
    else {
        printf("False\n");
    }
}




/*
    // IMPLEMENTACIÓN EJEMPLIFICADA

    addHM("Alberto", 1);
    addHM("Braulio", 2);
    addHM("Johan", 3);
    addHM("Jorge", 4);
    addHM("Ximena", 5);
    addHM("Paulina", 6);

    showHM();
    printf("\nTamaño de Hash: %d", sizeHM());

    printf("\nGet: %d", getHM("Estefania"));
    printf("\nGet: %d", getHM("Paulina"));

    printf("\n\n");
    containsKeyHM("Juana");
    containsKeyHM("Jorge");

    printf("\n");
    containsValueHM(1);
    containsValueHM(10);

    printf("\n");
    deleteHM("Julian", 5);
    deleteHM("Johan", 3);
    showHM();

*/