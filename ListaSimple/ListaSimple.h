
typedef struct _Alumno{
    char nombre[50];
    char apellidos[50];
    int semestre;
}Alumno;

typedef struct _Nodo{
    Alumno *data;
    struct _Nodo *next;
}Nodo;

typedef struct _lista{
    Nodo *Head;
    Nodo *Tail;
    Nodo *Curr;
    int size;
} ListaSimple;



void InicializarListaSimple(ListaSimple *lista);
void PushFront(ListaSimple *lista, void *dato);
void PushBack(ListaSimple *lista, void *dato);
Nodo *GetNodoPos(ListaSimple *lista, int pos);
void PushPos(ListaSimple *lista,void *dato, int pos);

void ImprimirLista(ListaSimple lista, void (*func)(void *));

void LiberarLista(ListaSimple *lista);

void BorrarNodo(ListaSimple *lista,void *dato);

void generarNombreAleatorio();
void generarApellidoAleatorio();