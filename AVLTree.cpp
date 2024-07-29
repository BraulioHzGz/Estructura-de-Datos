#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"


/*
	@brief	Funci�n para obtener la altura de las ramificaciones 
	@param	nodo:	nodo del �rbol
	@return	altura total del nodo | Dato de tipo entero (int)
*/
int getAltura(struct NodoAVLT* nodo) {
	if (nodo == NULL) {
		return 0;
	}
	return nodo->altura;
}


/*
	@brief	Funci�n para obtener cual ramificaci�n hija de un nodo (derecha o izquierda) 
			tiene mayor altura y poder hacer rotaciones completas para lograr el balance
	@param	M: valor m�ximo
	@param	m: valor m�nimo
	@return	valor m�ximo obtenido | Dato
*/
int getMax(int M, int m) {
	return(M > m) ? M : m;
}


/*
	@brief	Funci�n para verificar que las ramificaciones izquierda y derecha de un nodo
			est�n balanceadas | Se usa para hacer rotaciones de nodos
	@param	nodo: nodo del �rbol
	@return	diferencia de alturas izquierdas y derechas
*/
int getBalance(struct NodoAVLT* nodo) {
	if (nodo == NULL) {
		return 0;
	}
	return getAltura(nodo->left) - getAltura(nodo->right);
}


/*
	@brief	Funci�n para hacer inserciones necesarias durante todo el proceso de
			reacomodo cuando se hace una rotaci�n por izquierda o derecha
	@param	dato: valor que se va a almacenar en el nodo | Dato de tipo car�cter (char)
	@return	nuevo nodo
*/
struct NodoAVLT* addNodo(char dato) {
	struct NodoAVLT* newNodo = (struct NodoAVLT*)malloc(sizeof(struct NodoAVLT));
	newNodo->dato = dato;

	// Se a�ade un nuevo nodo, los hijos izquierdos y derechos deben ser nulos
	newNodo->left = newNodo->right = NULL;

	// Dado que solo hay hijo izqueirdo y derecho, la altura es 1
	newNodo->altura = 1;
	return newNodo;
}


/*
	@brief	Funci�n para hacer una rotaci�n por la derecha de los nodos y balancear
			ramificaciones enteras
	@param	nodo: nodo del �rbol
	@return	nodo reacomodado tras la rotaci�n
*/
struct NodoAVLT* rotarDerecha(struct NodoAVLT* nodo) {
	struct NodoAVLT* left = nodo->left;
	struct NodoAVLT* right = left->right;

	left->right = nodo;
	nodo->left = right;

	nodo->altura = getMax(getAltura(nodo->left), getAltura(nodo->right) + 1);
	left->altura = getMax(getAltura(left->left), getAltura(left->right) + 1);

	return left;
}


/*
	@brief	Funci�n para hacer una rotaci�n por la izquierda de los nodos y balancear
			ramificaciones enteras
	@param	nodo: nodo del �rbol
	@return	nodo reacomodado tras la rotaci�n
*/
struct NodoAVLT* rotarIzquierda(struct NodoAVLT* nodo) {
	struct NodoAVLT* right = nodo->right;
	struct NodoAVLT* left = right->left;

	right->left = nodo;
	nodo->right = left;
 
	nodo->altura = getMax(getAltura(nodo->left), getAltura(nodo->right)) + 1;
	right->altura = getMax(getAltura(right->left), getAltura(right->right)) + 1;

	return right;
}


/*
	@brief	Funci�n para a�adir nodos al �rbol
	@param	nodo: nodo del �rbol
	@param	dato: valor que se va a almacenar en el nodo | Dato de tipo car�cter (char)
	@return	nodo reacomodado tras la rotaci�n
*/
struct NodoAVLT* insertar(struct NodoAVLT* nodo, char dato) {
	int balance;
	
	if (nodo == NULL) {			// Si el �rbol est� vac�o, dato ser� el comienzo
		return addNodo(dato);
	}

	// Las inserciones se hacen dependiendo si el dato a ingresar es mayor o menor en su
	// c�digo ASCII, con ese criterio, se ir�n haciendo inserciones a tramas derecha o izq.

	if (dato < nodo->dato) {
		nodo->left = insertar(nodo->left, dato);
	}
	else if (dato > nodo->dato) {
		nodo->right = insertar(nodo->right, dato);
	}
	else {
		return nodo;
	}

	nodo->altura = 1 + getMax(getAltura(nodo->left), getAltura(nodo->right));
	balance = getBalance(nodo);

	// El balance no debe pasar de 1, con 2 se debe hacer un reacomodo

	if (balance > 1 && dato < nodo->left->dato) {
		return rotarDerecha(nodo);
	}
	if (balance < -1 && dato > nodo->right->dato) {
		return rotarIzquierda(nodo);
	}
	if (balance > 1 && dato > nodo->left->dato) {
		nodo->left = rotarIzquierda(nodo->left);
		return rotarDerecha(nodo);
	}
	if (balance < -1 && dato < nodo->right->dato) {
		nodo->right = rotarDerecha(nodo->right);
		return rotarIzquierda(nodo);
	}
	return nodo;
}


/*
	@brief	Funci�n para mostrar todo el �rbol en preorden | Uso de recursividad
	@param	root: comienzo del �rbol
*/
void show_AVL_TREE(NodoAVLT* root) {
	if (root != NULL) {
		printf("%c\t", root->dato);
		show_AVL_TREE(root->left);
		show_AVL_TREE(root->right);
	}
}




/*
	// IMPLEMENTACI�N EJEMPLIFICADA
	
	struct NodoAVLT *root = NULL;

	root = insertar(root, 'A');
	root = insertar(root, 'B');
	root = insertar(root, 'C');
	root = insertar(root, 'D');
	root = insertar(root, 'E');
	root = insertar(root, 'F');
	root = insertar(root, 'G');
	root = ...;

	show_AVL_TREE(root);

*/