#ifndef _H_ARBOL_
#define _H_ARBOL_
#include "lista.h"

struct NodoArbol{
	int numero;
    struct Lista *resultado;
	struct Lista *siguiente;
};


struct Lista *crearSolucion(struct Lista *l);

struct NodoArbol *crearArbol();

void agregarElementoNodo(int elemento, struct NodoArbol *a);
#endif
