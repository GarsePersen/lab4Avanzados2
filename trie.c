#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "trie.h"

void agregarElementoNodo(int elemento, struct NodoArbol *a){
    if(a->siguiente == NULL){
       a->siguiente = crearLista();
    }
    struct NodoArbol *b = malloc(sizeof(struct NodoArbol));
    b->siguiente = NULL;
    b->resultado = NULL;
    b->numero = elemento;
    agregarElemento(a->siguiente, b);
}

struct Lista *crearSolucion(struct Lista *l){
    struct Lista *resultado = crearLista();
    struct NodoLista *aux = NULL;
    lista_for_all(l, aux) {
       if(!aux->siguiente){
            return;   
       }else{
            int elemento = *(int*)aux->data;
            int elemento2 = *(int*)aux->data;
            if(((elemento == 1) && (elemento == 2)) || ((elemento == 2 ) && (elemento == 1))){
                agregarElemento(resultado, 3);  
                
            }
       }

    };
    
}

struct Lista *buscarRamal(struct NodoArbol *a, struct NodoLista *consulta, struct NodoArbol **ramal){
    if(!consulta || !a) {
        *ramal = NULL;
        return NULL;
    }

    if(a->resultado) {
        return a->resultado;
    }

    int elemento = *(int*)consulta->data;

    struct NodoLista *siguiente = NULL;
    lista_for_all(a->siguiente, siguiente) {
        struct NodoArbol *arbol_siguiente = (struct NodoArbol*)siguiente->data;
        if(arbol_siguiente->numero == elemento) {
            if(!*ramal) {
                *ramal = arbol_siguiente;
            }
            return buscarRamal(arbol_siguiente, consulta->siguiente, ramal);
        }
    };
    *ramal = NULL;
    return NULL;
}


struct NodoArbol *crearArbol(){
	struct NodoArbol *a = malloc(sizeof(struct NodoArbol));
	a->siguiente = NULL;
    a->resultado = NULL;
	return a;

}
