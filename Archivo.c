#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "archivo.h"
#include "lista.h"

struct Lista *leerArchivo(){
	FILE *fp;
    struct Lista *polimoro = crearLista();
	int c;
	fp = fopen("entrada.in","r");
	if(fp == NULL) 
	{
		printf("Error, verifique que existe su archivo entrada.in");
		return crearLista();
	}
    while(c = fgetc(fp)){
        c -= 48;

        if(feof(fp)||c>3||c<1)
		{
			break;
		}
        void *ptr = malloc(sizeof(int));
        *(int*)ptr = c;
        agregarElemento(polimoro, ptr);
	}
	fclose(fp);
    return polimoro;
}
