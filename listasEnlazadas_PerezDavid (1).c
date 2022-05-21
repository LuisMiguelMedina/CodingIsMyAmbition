#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Datos_Alumno{
    char *nombre;
    char *apellidoPaterno;
    char *apellidoMaterno;
}; 
typedef struct Datos_Alumno Alumno;


struct Node{
    Alumno *alumno;
    struct Node *siguiente;
}; 
typedef struct Node Nodo;
typedef Nodo* NodoPtr;


NodoPtr crearNodo();
Alumno* crearAlumnos(char *nombre, char *apellidoPaterno, char *apellidoMaterno);
void llenarAlumno(NodoPtr *lista);
void insertarAlInicio(NodoPtr *lista, NodoPtr datosAlumno);
void insertarOrdenado(NodoPtr *lista, NodoPtr datosAlumno);
int compararDatos(Alumno *apellido1 , Alumno *apellido2);
void imprimirLista(NodoPtr lista);
int eliminarNodo(NodoPtr lista, Alumno *alumno);
void solicitarNombreBorrar(NodoPtr inicioLista);
void liberarMemoria(NodoPtr nodoEliminado);
void solicitarActualizar(NodoPtr inicioLista);
void actualizarLista(NodoPtr inicioLista, NodoPtr alumnoEliminar, NodoPtr alumnoReemplazar);


int main(){
    
    NodoPtr lista;
    NodoPtr datosAlumno;

    lista = NULL;   

    llenarAlumno(&lista);
    imprimirLista(lista);
    solicitarNombreBorrar(lista);
    solicitarActualizar(lista);
    imprimirLista(lista);
    free(lista);

}

void solicitarNombreBorrar(NodoPtr inicioLista){
    
    NodoPtr nodoBorrar;
   
    nodoBorrar = crearNodo(crearAlumnos("Alan","Perez","Romero"));
    eliminarNodo(inicioLista, nodoBorrar->alumno);

    nodoBorrar = crearNodo(crearAlumnos("Alvaro","Xool","Canul"));
    eliminarNodo(inicioLista, nodoBorrar->alumno);

    nodoBorrar = crearNodo(crearAlumnos("Carlos","May","Vivas"));
    eliminarNodo(inicioLista, nodoBorrar->alumno);

}

void llenarAlumno(NodoPtr *lista){
       
    insertarOrdenado(lista, crearNodo(crearAlumnos("David Leobardo","Perez","Cruz")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Carlos","Calderon","Delgado")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Jose Angel","Magana","Garcia")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Carlos","May","Vivas")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Fernando","Joachin","Prieto")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Luis","Cruz","Inzunza")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Fernando","Villajuana","Saavedra")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Mariam Guadalupe","Moreno","Farah")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Jose Carlos","Leo","Fernandez")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Adrian","Fonseca","Loria")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Adjany","Armenta","Aguilar")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Andrea","Torres","Perez")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Kevin Alejandro","Medina","Padilla")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Luis Miguel","Medina","Avila")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Abraham","Espinosa","Mendoza")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Alan","Perez","Romero")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Elias","Madera","De Regil")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Reyna Valentina","Ortiz","Porras")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Juan","Ceballos","Medina")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Daniel","Vallado","Orozco")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Alvaro","Xool","Canul")));
    insertarOrdenado(lista, crearNodo(crearAlumnos("Cristian","Pan","Zaldivar")));
   
}

NodoPtr crearNodo(Alumno *alumno){
    
    NodoPtr nuevoElemento;

    nuevoElemento = (NodoPtr)malloc(sizeof(Nodo));
    nuevoElemento->alumno = alumno;
    nuevoElemento->siguiente = NULL;
    
    return nuevoElemento;
}


Alumno* crearAlumnos(char *nombre, char *apellidoPaterno, char *apellidoMaterno){

    Alumno *puntero;
    puntero = (Alumno*) malloc(sizeof(Alumno));

    puntero->nombre = (char*) malloc(strlen(nombre) * sizeof(char));
    strcpy(puntero->nombre, nombre);

    puntero-> apellidoPaterno = (char*) malloc(strlen(apellidoPaterno) * sizeof(char));
    strcpy(puntero->apellidoPaterno, apellidoPaterno);

    puntero->apellidoMaterno = (char*) malloc(strlen(apellidoMaterno) * sizeof(char));
    strcpy(puntero->apellidoMaterno, apellidoMaterno);

    return puntero;
}



void imprimirLista(NodoPtr lista){
    
    int i = 1;
        if(lista == NULL){
            printf("La lista está vacía");
        }
        else{
            printf("\n\nLos elementos de la lista son:\n\n");
            while(lista != NULL){
                printf("%i. %s " ,i, lista->alumno->nombre);
                printf("%s " , lista->alumno->apellidoPaterno);
                printf("%s " , lista->alumno->apellidoMaterno);
                printf("\n");
                lista= lista->siguiente;
                i++;
            }
        }   
}

void insertarAlInicio(NodoPtr *lista, NodoPtr datosAlumno){
    
    if(datosAlumno != NULL){
        datosAlumno->siguiente = *lista;
        *lista = datosAlumno;
    }
    
}



void insertarOrdenado(NodoPtr *lista, NodoPtr datosAlumno){
    
    int comparacion;
    NodoPtr nuevo, actual, anterior;
    nuevo = datosAlumno;
    anterior = NULL;

    if(*lista != NULL){
        actual = *lista;
        comparacion = compararDatos(datosAlumno->alumno, actual->alumno );

        while (actual != NULL && comparacion > 0){
            
            comparacion = compararDatos(datosAlumno->alumno, actual->alumno );
            if(comparacion>0){
                anterior = actual;                
                actual = actual->siguiente;
            }
        }
        //Meterlo al inicio
        if(anterior == NULL){
            nuevo->siguiente = *lista;
            *lista = nuevo;  
        }

        //Meterlo al último
        else if(actual == NULL){
            anterior->siguiente = nuevo;
            nuevo->siguiente = NULL;
        
        }
        //Meterno entre anterior y actual
        else if(actual != NULL){
            nuevo->siguiente = anterior->siguiente;
            anterior->siguiente = nuevo;
        }

    }else{
        
        *lista = nuevo;
    }            
}

int compararDatos(Alumno *apellido1 , Alumno *apellido2){
    
    int comparacion;
    comparacion = strcmp(apellido1->apellidoPaterno, apellido2->apellidoPaterno);

    if(comparacion == 0){
        comparacion = strcmp(apellido1->apellidoMaterno, apellido2->apellidoMaterno);

        if(comparacion == 0){
            comparacion = strcmp(apellido1->nombre, apellido2->nombre);
        }
    }
    return comparacion;
}


int eliminarNodo (NodoPtr inicioLista, Alumno *alumno){
    
    NodoPtr actual, anterior;
    int comparacion, banderaBorrar = 0;    
    anterior = NULL;
    actual = inicioLista;

    while(actual != NULL && banderaBorrar == 0){
        comparacion = compararDatos(alumno, actual->alumno );
        if(comparacion == 0){ 

            if(anterior == NULL){
                actual = actual->siguiente;
            }
            else {
                anterior->siguiente = actual->siguiente;
                liberarMemoria(actual);
            }
            banderaBorrar = 1;

        }else{
            anterior = actual;
            actual = actual->siguiente;
        }
    }

    return banderaBorrar;
}

void liberarMemoria(NodoPtr nodoEliminado){
    free(nodoEliminado->alumno->nombre);
    free(nodoEliminado->alumno->apellidoPaterno);
    free(nodoEliminado->alumno->apellidoMaterno);
    free(nodoEliminado->alumno);
    free(nodoEliminado);
}

void solicitarActualizar(NodoPtr inicioLista){
    
    NodoPtr nodoActualizar, nodoReemplazar;
   
    nodoActualizar = crearNodo(crearAlumnos("David Leobardo","Perez","Cruz"));
    eliminarNodo(inicioLista, nodoActualizar->alumno);

    nodoReemplazar = crearNodo(crearAlumnos("Josefino","Detal","Palo"));
    eliminarNodo(inicioLista, nodoActualizar->alumno);

    actualizarLista(inicioLista, nodoActualizar, nodoReemplazar);


    nodoActualizar = crearNodo(crearAlumnos("Adrian","Fonseca","Loria"));
    eliminarNodo(inicioLista, nodoActualizar->alumno);

    nodoReemplazar = crearNodo(crearAlumnos("Lucho","Portus","Casas"));
    eliminarNodo(inicioLista, nodoActualizar->alumno);

    actualizarLista(inicioLista, nodoActualizar, nodoReemplazar);


    nodoActualizar = crearNodo(crearAlumnos("Luis Miguel","Medina","Avila"));
    eliminarNodo(inicioLista, nodoActualizar->alumno);

    nodoReemplazar = crearNodo(crearAlumnos("Panfilo","Clodomiro","Urriaga"));
    eliminarNodo(inicioLista, nodoActualizar->alumno);

    actualizarLista(inicioLista, nodoActualizar, nodoReemplazar);
   
}

void actualizarLista(NodoPtr inicioLista, Nodo *alumnoEliminar, Nodo *alumnoReemplazar){

    NodoPtr actual, anterior;
    int comparacion, banderaBorrar = 0;    
    anterior = NULL;
    actual = inicioLista;

    while(actual != NULL && banderaBorrar == 0){
        comparacion = compararDatos(alumnoEliminar->alumno, actual->alumno );
        if(comparacion == 0){ 

            if(anterior == NULL){
                actual = actual->siguiente;
            }
            else {
                anterior->siguiente = actual->siguiente;
                liberarMemoria(actual);
            }
            banderaBorrar = 1;

        }else{
            anterior = actual;
            actual = actual->siguiente;
        }
    }

    insertarOrdenado(&inicioLista, alumnoReemplazar);
}