#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ListaSimple/ListaSimple.h"

void ImprimirNumeros(void *dato){
    printf("%c", *(char *)dato);
}



int main(){

    ListaSimple milista;
    InicializarListaSimple(&milista);

    PushFront(&milista,"U");
    PushFront(&milista,"A");
    PushBack(&milista,"B");
    PushBack(&milista,"C");
    PushFront(&milista,"I");
    PushPos(&milista,"S",5);
    PushPos(&milista,"T",0);
    PushPos(&milista,"E",3);
    
    ImprimirLista(milista,ImprimirNumeros);
    
    pritnf("Impresion de la lista");
    LiberarLista(&milista);

    return 0;

}