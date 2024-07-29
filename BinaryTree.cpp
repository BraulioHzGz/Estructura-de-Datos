#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

#define MAX_QUEUE 50	// ELEMENTOS M�XIMO QUE PODEMOS ALMACENAR

/*
	@brief	Funci�n que inicializa el �rbol, es decir, mi punto de partida
	@param	numero: valor que se va a almacenar en el nodo | Dato de tipo decimal (float)
	@return	nuevo nodo
*/
NodoBT* startTree(float numero) {
	NodoBT* newNode = (NodoBT*)malloc(sizeof(NodoBT));
	newNode->numero = numero;
	newNode->left = newNode->right = NULL;
	return newNode;
}


/*
	@brief	Funci�n para a�adir nodos al �rbol
	@param	root:	punto de partida de mi �rbol
	@param  numero:	valor que se va a almacenar en el nodo | Dato de tipo decimal (float)
	@return	ra�z con nuevo nodo a�adido
*/
NodoBT* insertBinT(NodoBT* root, float numero) {
	if (root == NULL) {		// No hay elementos -> primer dato ser� la ra�z
		root = startTree(numero);
		return root;
	}

	// Cola en forma de arreglo para almacenar nodos que ya fueron visitados usando BFS
	NodoBT* queue[MAX_QUEUE];
	int front = 0, rear = 0;
	queue[rear++] = root;
	
	while (front != rear) {
		NodoBT* temp = queue[front++];
		if (temp->left == NULL) {	// Inicializamos el lado izquierdo si no hay hijo
			temp->left = startTree(numero);
			break;
		} else {
			queue[rear++] = temp->left;
		}

		if (temp->right == NULL) {	// Inicializamos el lado derecho si no hay hijo
			temp->right = startTree(numero);
			break;
		} else {
			queue[rear++] = temp->right;
		}
	}
	return root;
}


/*
	@brief	Funci�n para eliminar un nodo de un �rbol solo si, es un nodo hoja
	@param	root:	punto de partida de mi �rbol
	@param  l_node:	hoja que se debe eliminar eliminar
	@return	ra�z con nuevo nodo a�adido
*/
void deleteLeaf(NodoBT* root, NodoBT* l_node) {
	
	// Cola en forma de arreglo para almacenar nodos que ya fueron visitados usando BFS
	NodoBT* queue[MAX_QUEUE];

	int front = 0, rear = 0;
	queue[rear++] = root;
	NodoBT* temp;

	while (front != rear) {
		temp = queue[front++];
		if (temp == l_node) {	// Nodo hoja es igual al valor buscado, se elimina
			temp = NULL;
			free(l_node);
			return;
		}

		if (temp->left) {		// Hacemos una b�squeda izquierda hasta dar con el nodo
			if (temp->left == l_node) {
				temp->left = NULL;
				free(l_node);
				return;
			} else {
				queue[rear++] = temp->left;		// No existe el nodo
			}
		}

		if (temp->right) {		// Hacemos una b�squeda derecha hasta dar con el nodo
			if (temp->right == l_node) {
				temp->right = NULL;
				free(l_node);
				return;
			} else {
				queue[rear++] = temp->right;	// No existe el nodo
			}
		}
	}
}


/*
	@brief	Funci�n para eliminar un nodo del �rbol
	@param	root:	punto de partida de mi �rbol
	@param  n�mero: valor que se va a eliminar | Dato de tipo decimal (float)
	@return	ra�z con nodo eliminado
*/
NodoBT* deleteBinT(NodoBT* root, float numero) {
	if (root == NULL) {		// No hay nada en el �rbol, no podemos eliminar algo
		return NULL;
	}
	if (root->left == NULL && root->right == NULL) {
		if (root->numero == numero) {
			return NULL;
		} else {
			return root;
		}
	}

	// Cola en forma de arreglo para almacenar nodos que ya fueron visitados usando BFS
	NodoBT* queue[MAX_QUEUE];

	int front = 0, rear = 0;
	queue[rear++] = root;
	NodoBT* temp = NULL;
	NodoBT* val = NULL;

	while (front != rear) {
		temp = queue[front++];
		if (temp->numero == numero) {	// Encontramos que el nodo actual es el esperado
			val = temp;		// Almacenamos el valor para hacer correcta eliminaci�n
		}

		// Recorremos todo el �rbol hasta encontrar el nodo que queremos eliminar
		if (temp->left) {
			queue[rear++] = temp->left;
		}
		if (temp->right) {
			queue[rear++] = temp->right;
		}
	}

	/*
		Si existi� el nodo que queremos eliminar, reemplaza su valor con el valor 
		del �ltimo nodo (temp) para mantener siempre la estructura binaria esperada.
	*/
	if (val != NULL) {
		float aux = temp->numero;
		val->numero = aux;
		deleteLeaf(root, temp);
	} else {
		printf("No existe un nodo con el valor %0.3f", numero);
	}

	return root;
}


/*
	@brief	Funci�n para mostrar todo el �rbol en inorden | Uso de recursividad
	@param	root: comienzo del �rbol
*/
void InOrden(NodoBT* root) {
	if (root == NULL) {
		return;
	}
	InOrden(root->left);
	printf("%0.2f\t", root->numero);
	InOrden(root->right);
}


/*
	@brief	Funci�n para mostrar todo el �rbol en preorden | Uso de recursividad
	@param	root: comienzo del �rbol
*/
void PreOrden(NodoBT* root) {
	if (root == NULL) {
		return;
	}
	printf("%0.2f\t", root->numero);
	PreOrden(root->left);
	PreOrden(root->right);
}


/*
	@brief	Funci�n para mostrar todo el �rbol en postorden | Uso de recursividad
	@param	root: comienzo del �rbol
*/
void PostOrden(NodoBT* root) {
	if (!root) {
		return;
	}
	PostOrden(root->left);
	PostOrden(root->right);
	printf("%0.2f\t", root->numero);
}




/*
	// IMPLEMENTACI�N EJEMPLIFICADA

	NodoBT* root = NULL;

	root = insertBinT(root, 10.1f);
	root = insertBinT(root, 20.0f);
	...

	printf("\nRECORRIDO IN-ORDEN: ");
	InOrden(root);

	printf("\nRECORRIDO PRE-ORDEN: ");
	PreOrden(root);

	printf("\nRECORRIDO POST-ORDEN: ");
	PostOrden(root);

	root = deleteBinT(root, 20.0f);
	root = deleteBinT(root, 17.3f);

*/