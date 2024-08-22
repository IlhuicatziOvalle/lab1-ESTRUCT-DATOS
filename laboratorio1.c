#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "ListaSimple/ListaSimple.h"


void ImprimirNumeros(void *dato){
    printf("%c", *(char *)dato);
}
void imprimirAlumno(void *data){
    Alumno *alumno = (Alumno*)data;
    printf("Nombre: %s %s, Semestre: %d\n", alumno->nombre, alumno->apellidos, alumno->semestre);
}


int main(){
     srand(time(0));

    ListaSimple salon;
    InicializarListaSimple(&salon);

    // Generar un número aleatorio de alumnos (entre 5 y 40)
    int numAlumnos = 5 + rand() % (40 - 5 + 1);
    printf("Número de alumnos a registrar: %d\n", numAlumnos);

    // Altas de alumnos
    for (int i = 0; i < numAlumnos; i++) {
        Alumno *nuevoAlumno = (Alumno *)malloc(sizeof(Alumno));
        generarNombreAleatorio(nuevoAlumno->nombre);
        generarApellidoAleatorio(nuevoAlumno->apellidos);
        nuevoAlumno->semestre = 1 + rand() % 10;

        int metodoInsercion = rand() % 3;

        if (metodoInsercion == 0) {
            PushFront(&salon, nuevoAlumno);
        } else if (metodoInsercion == 1) {
            PushBack(&salon, nuevoAlumno);
        } else {
            int pos = rand() % (salon.size + 1);
            PushPos(&salon, nuevoAlumno, pos);
        }
    }
    printf("\nPRIMERA EMISION");
    printf("\nLista de alumnos después de las altas:\n");
    ImprimirLista(salon, imprimirAlumno);

    // Generar un número aleatorio de bajas (entre 3 y 15)
    int numBajas = 3 + rand() % 13;
    printf("\nNúmero de alumnos a dar de baja: %d\n", numBajas);

    // Bajas de alumnos
    for (int i = 0; i < numBajas && salon.size > 0; i++) {
        int pos = rand() % salon.size;
        Nodo *nodoABorrar = GetNodoPos(&salon, pos);
        BorrarNodo(&salon, nodoABorrar->data);
    }
    printf("\nSEGUNDA EMISION");
    printf("\nLista de alumnos después de las bajas:\n");
    ImprimirLista(salon, imprimirAlumno);

    // Liberar memoria
    LiberarLista(&salon);

    return 0;
}