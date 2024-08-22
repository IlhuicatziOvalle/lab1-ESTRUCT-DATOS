#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "ListaSimple.h"

void InicializarListaSimple(ListaSimple *lista){
    lista->Head=NULL;
    lista->Tail=NULL;
    lista->Curr=NULL;
    lista->size=0;
}
void PushFront(ListaSimple *lista, void *dato){
    Nodo *nuevo=(Nodo *)malloc(sizeof(Nodo));
    nuevo->data=dato;
    if(lista->Head==NULL){
        lista->Tail=nuevo;
        nuevo->next=NULL;
   }
   else{
        nuevo->next=lista->Head;
   }
   lista->Head=nuevo;
   lista->size++;
}
void PushBack(ListaSimple *lista, void *dato){
       Nodo *nuevo=(Nodo *)malloc(sizeof(Nodo));
       nuevo->data=dato;
       if(lista->Tail==NULL){
        lista->Head=nuevo;
        nuevo->next=NULL;
   }
   else{
    lista->Tail->next=nuevo;
    nuevo->next=NULL;
   }
   lista->Tail=nuevo;
   lista->size++;

}
Nodo *GetNodoPos(ListaSimple *lista, int pos){
    Nodo *temp=lista->Head;

    while(temp!=NULL&&pos>0){
        temp=temp->next;
        pos--;
    }
    return temp;
}
void PushPos(ListaSimple *lista,void *dato, int pos){
    if(pos==0){
        PushFront(lista,dato);
        return;
    }
    else if(pos==lista->size){
        PushBack(lista,dato);
        return;
    }
    else{
        Nodo *nuevo=(Nodo *)malloc(sizeof(Nodo));
        nuevo->data=dato;

        Nodo *ant = GetNodoPos(lista,pos -1);
        nuevo->next=ant->next;
        ant->next=nuevo;
    }
    lista->size++;
}


void ImprimirLista(ListaSimple lista, void (*func)(void *)){     ///void(*func)(void*) se lo dejas al usario para que cree su funcion para el tipo de dato
    lista.Curr=lista.Head;
    while(lista.Curr!=NULL){
        func(lista.Curr->data);
        lista.Curr=lista.Curr->next;
    }
}

void LiberarLista(ListaSimple *lista){
    lista->Curr=lista->Head;
    while(lista->Curr!=NULL){
        Nodo* temp=lista->Curr;
        lista->Curr=lista->Curr->next;
        free(temp);
    }
}
Nodo *GetNodo(ListaSimple *lista, void *dato){
    lista->Curr=lista->Head;
    while(lista->Curr->data!=dato&&lista->Curr!=NULL){
        lista->Curr=lista->Curr->next;
    }
    return lista->Curr;
}
void BorrarNodo(ListaSimple *lista, void *dato) {
    Nodo *curr = lista->Head;
    Nodo *ant = NULL;

    while (curr != NULL && curr->data != dato) {
        ant = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        // El nodo no se encontró
        return;
    }

    if (ant == NULL) {
        // Si el nodo a eliminar es el primero de la lista
        lista->Head = curr->next;
    } else {
        // Eliminar el nodo enlazando el anterior con el siguiente
        ant->next = curr->next;
    }

    if (curr == lista->Tail) {
        // Si el nodo a eliminar es el último
        lista->Tail = ant;
    }

    free(curr->data);  // Liberar la memoria del dato del alumno
    free(curr);  // Liberar la memoria del nodo
    lista->size--;
}

void generarNombreAleatorio(char *nombre){
    const char *nombres[] = {"Ana","Juan","Julio","Febrero","Marzo","Carlos"};
    strcpy(nombre,nombres[rand() % 6]);
}
void generarApellidoAleatorio(char *apellido){
    const char *apellidos[] = {"Gomez","Hernandez","Huerta","Valenzuela","Madriz","Leon"};
    strcpy(apellido,apellidos[rand() % 6]);
}