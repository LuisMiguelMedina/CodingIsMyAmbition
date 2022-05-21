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
void llenarAlumno(NodoPtr lista, Alumno* alumno);
void insertarAlInicio(NodoPtr *lista, NodoPtr datosAlumno);
void insertarOrdenado(NodoPtr *lista, NodoPtr datosAlumno);
int compararDatos(Alumno *apellido1 , Alumno *apellido2);
void imprimirLista(NodoPtr lista);
int eliminarNodo(NodoPtr lista, Alumno *alumno);
void solicitarNombreBorrar(NodoPtr inicioLista);
void liberarMemoria(NodoPtr nodoEliminado);
void solicitarActualizar(NodoPtr inicioLista);
void actualizarLista(NodoPtr inicioLista, NodoPtr alumnoEliminar, NodoPtr alumnoReemplazar);
Alumno* leerArchivo(NodoPtr lista, Alumno* alumno);
Alumno* dividirDatos(char *data, int longitud, Alumno* alumno);




int main(){
    
    NodoPtr lista;
    NodoPtr datosAlumno;
    Alumno* alumno;
    alumno = (Alumno*)malloc(sizeof(Alumno));
    
    lista = NULL;   

    leerArchivo(&lista, alumno);
    imprimirLista(lista);
    // solicitarNombreBorrar(lista);
    // solicitarActualizar(lista);
    // imprimirLista(lista);
    free(lista);

}

Alumno* leerArchivo(NodoPtr lista, Alumno* alumno){
    FILE * listaDatos;
    char datos[100];
    int contadorCadena=0;
    int longitud, longitudNombre, longitudApellido;
    char *nombre;
    char *apellidoPaterno;

    

    listaDatos = fopen("lista.txt", "r");
    if(listaDatos == NULL){
        perror("Error 404 not found");    
    }

    while(!feof(listaDatos)){
        fgets(datos, sizeof(datos), listaDatos); //Investigar sobre la función de fscanf
        longitud = strlen(datos);
        alumno = dividirDatos(datos, longitud, alumno);
        llenarAlumno(lista, alumno);

    }
    fclose(listaDatos);
    return alumno;
}

Alumno* dividirDatos(char *data, int longitud, Alumno* alumno){
    
        int i=0, j=0, k=0;
        char *auxiliar;
        char nombre[20];
        char apellidoPaterno[20];
        char apellidoMaterno[20];

        memset(apellidoPaterno, 0, strlen(apellidoPaterno));
        memset(nombre, 0, strlen(nombre));
        memset(apellidoMaterno, 0, strlen(apellidoMaterno));


        auxiliar = data;

        int banderaNombre = 0, banderaApellidoPaterno = 0, banderaApellidoMaterno = 0;

            while(data[i] != '\0' && data[i] != ',' && banderaNombre == 0){
                *(nombre+i) = data[i];
                i++;
                if(data[i] == ','){
                    banderaNombre = 1;
                }
            }
           
            alumno->nombre = (char*) malloc(strlen(nombre) * sizeof(char));
            strcpy(alumno->nombre, nombre);
            // printf("NAME: %s\n" , alumno->nombre);

            i++;

            while(auxiliar[i] != '\0' && auxiliar[i] != ',' && banderaApellidoPaterno == 0){
                apellidoPaterno[j] = auxiliar[i];
                i++;
                j++;
                if(auxiliar[i] == ','){
                    banderaApellidoPaterno = 1;
                }
                
            }
            alumno->apellidoPaterno = (char*) malloc(strlen(apellidoPaterno) * sizeof(char));
            strcpy(alumno->apellidoPaterno, apellidoPaterno);
            // printf("AP: %s\n" , alumno->apellidoPaterno);

            i++;

            while(auxiliar[i] != '\0' && auxiliar[i] != ',' && banderaApellidoMaterno == 0){
                apellidoMaterno[k] = auxiliar[i];
                i++;
                k++;
                if(auxiliar[i] == '.' || auxiliar[i] == '.'){
                    banderaApellidoMaterno = 1;
                }
                
            }
            alumno->apellidoMaterno = (char*) malloc(strlen(apellidoMaterno) * sizeof(char));
            strcpy(alumno->apellidoMaterno , apellidoMaterno);
            // printf("AM: %s\n" , alumno->apellidoMaterno); 

    return alumno;   
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

void llenarAlumno(NodoPtr lista, Alumno* alumno){
    insertarOrdenado(lista, crearNodo(crearAlumnos(alumno->nombre, alumno->apellidoPaterno, alumno->apellidoMaterno)));
    
   
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