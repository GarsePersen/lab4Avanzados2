#ifndef _H_LISTA_
#define _H_LISTA_

#define lista_for_all(LISTA, ITER) for(ITER = LISTA->nodos; ITER != NULL; ITER = ITER->siguiente)
//Estructura NodoLista, almacena dos nodos, el grado y un puntero al siguiente
struct NodoLista{
	void *data;
	struct NodoLista *siguiente;
};
//Estructura Lista, almacena la estructura NodoLista
struct Lista{
	struct NodoLista *nodos;
    int tamanio;
};

void imprimirLista(struct Lista *l);

void agregarElemento(struct Lista *l, void *data);

struct Lista *crearLista();

#endif
