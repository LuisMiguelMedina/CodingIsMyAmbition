#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Luis Miguel Medina Avila
    finished the 05/20/22
*/

struct data_Student{
    char *name;
    char *paternSurname;
    char *maternSurname;
}; 
typedef struct data_Student Student;

struct Node{
    Student *Student;
    struct Node *next;
}; 
typedef struct Node Node;
typedef Node* NodePtr;

NodePtr addNode();
Student* addStudents(char *name, char *paternSurname, char *maternSurname);
void fillStudent(NodePtr *list);
void InsertAndStart(NodePtr *list, NodePtr studentData);
void InsertOrganized(NodePtr *list, NodePtr studentData);
int comparedata(Student *surname1 , Student *surname2);
void printlist(NodePtr list);
int DeleteNode(NodePtr list, Student *Student);
void askNameDelete(NodePtr startlist);
void releaseMemory(NodePtr NodeDeleted);
void askUpdate(NodePtr startlist);
void Updatelist(NodePtr startlist, NodePtr StudentDelete, NodePtr StudentReplace);

int main(){
    
    NodePtr list;
    NodePtr studentData;

    list = NULL;   

    fillStudent(&list);
    printlist(list);
    askNameDelete(list);
    askUpdate(list);
    printlist(list);
    free(list);
}

void askNameDelete(NodePtr startlist){
    
    NodePtr NodeDelete;
   
    NodeDelete = addNode(addStudents("David","Perez","Cruz"));
    DeleteNode(startlist, NodeDelete -> Student);

    NodeDelete = addNode(addStudents("Luis","Cruz","Inzunza"));
    DeleteNode(startlist, NodeDelete -> Student);

    NodeDelete = addNode(addStudents("Luis","Medina","Avila"));
    DeleteNode(startlist, NodeDelete -> Student);

}

void fillStudent(NodePtr *list){
       
    InsertOrganized(list, addNode(addStudents("David Leobardo","Perez","Cruz")));
    InsertOrganized(list, addNode(addStudents("Carlos","Calderal","Delgado")));
    InsertOrganized(list, addNode(addStudents("Jose Angel","Magana","Garcia")));
    InsertOrganized(list, addNode(addStudents("Carlos","May","Vivas")));
    InsertOrganized(list, addNode(addStudents("Fernando","Joachin","Prieto")));
    InsertOrganized(list, addNode(addStudents("Luis","Cruz","Inzunza")));
    InsertOrganized(list, addNode(addStudents("Fernando","Villajuana","Saavedra")));
    InsertOrganized(list, addNode(addStudents("Mariam Guadalupe","Moreno","Farah")));
    InsertOrganized(list, addNode(addStudents("Jose Carlos","Leo","Fernalez")));
    InsertOrganized(list, addNode(addStudents("Adrian","Falseca","Loria")));
    InsertOrganized(list, addNode(addStudents("Adjany","Armenta","Aguilar")));
    InsertOrganized(list, addNode(addStudents("Andrea","Torres","Perez")));
    InsertOrganized(list, addNode(addStudents("Kevin alejandro","Medina","Padilla")));
    InsertOrganized(list, addNode(addStudents("Luis Miguel","Medina","Avila")));
    InsertOrganized(list, addNode(addStudents("Abraham","Espinosa","Mendoza")));
    InsertOrganized(list, addNode(addStudents("Alan","Perez","Romero")));
    InsertOrganized(list, addNode(addStudents("Elias","Madera","De Regil")));
    InsertOrganized(list, addNode(addStudents("Reyna Valentina","Ortiz","Porras")));
    InsertOrganized(list, addNode(addStudents("Juan","Ceballos","Medina")));
    InsertOrganized(list, addNode(addStudents("Daniel","Vallado","Orozco")));
    InsertOrganized(list, addNode(addStudents("Alvaro","Xool","Canul")));
    InsertOrganized(list, addNode(addStudents("Cristian","Pan","Zaldivar")));
   
}

NodePtr addNode(Student *Student){
    
    NodePtr newElement;

    newElement = (NodePtr)malloc(sizeof(Node));
    newElement -> Student = Student;
    newElement -> next = NULL;
    
    return newElement;
}


Student* addStudents(char *name, char *paternSurname, char *maternSurname){

    Student *pointer;
    pointer = (Student*) malloc(sizeof(Student));

    pointer -> name = (char*) malloc(strlen(name) * sizeof(char));
    strcpy(pointer -> name, name);

    pointer ->  paternSurname = (char*) malloc(strlen(paternSurname) * sizeof(char));
    strcpy(pointer -> paternSurname, paternSurname);

    pointer -> maternSurname = (char*) malloc(strlen(maternSurname) * sizeof(char));
    strcpy(pointer -> maternSurname, maternSurname);

    return pointer;
}


void printlist(NodePtr list){
    
    int i = 1;
        if(list == NULL){
            printf("Empty list");
        }
        else{
            while(list != NULL){
                printf("%i. %s " ,i, list -> Student -> name);
                printf("%s " , list -> Student -> paternSurname);
                printf("%s " , list -> Student -> maternSurname);
                printf("\n");
                list= list -> next;
                i++;
            }
        }   
}

void InsertAndStart(NodePtr *list, NodePtr studentData){
    
    if(studentData != NULL){
        studentData -> next = *list;
        *list = studentData;
    }
    
}

void InsertOrganized(NodePtr *list, NodePtr studentData){
    
    int compared;
    NodePtr new, actual, previous;
    new = studentData;
    previous = NULL;

    if(*list != NULL)
    {
        actual = *list;
        compared = comparedata(studentData -> Student, actual -> Student);

        while (actual != NULL && compared > 0)
        {
            compared = comparedata(studentData -> Student, actual -> Student);
            if(compared > 0){
                previous = actual;                
                actual = actual -> next;
            }
        }
        if(previous == NULL)
        {
            new -> next = *list;
            *list = new;  
        }
        else if(actual == NULL)
        {
            previous -> next = new;
            new -> next = NULL;
        
        }
        else if(actual != NULL)
        {
            new -> next = previous -> next;
            previous -> next = new;
        }
    }
    else
    {
        *list = new;
    }            
}

int comparedata(Student *surname1 , Student *surname2){
    
    int compared;
    compared = strcmp(surname1 -> paternSurname, surname2 -> paternSurname);

    if(compared == 0){
        compared = strcmp(surname1 -> maternSurname, surname2 -> maternSurname);

        if(compared == 0){
            compared = strcmp(surname1 -> name, surname2 -> name);
        }
    }
    return compared;
}


int DeleteNode (NodePtr startlist, Student *Student){
    
    NodePtr actual, previous;
    int compared, flagDelete = 0;    
    previous = NULL;
    actual = startlist;

    while(actual != NULL && flagDelete == 0){
        compared = comparedata(Student, actual -> Student );
        if(compared == 0){ 

            if(previous == NULL){
                actual = actual -> next;
            }
            else {
                previous -> next = actual -> next;
                releaseMemory(actual);
            }
            flagDelete = 1;

        }else{
            previous = actual;
            actual = actual -> next;
        }
    }

    return flagDelete;
}

void releaseMemory(NodePtr NodeDeleted){
    free(NodeDeleted -> Student -> name);
    free(NodeDeleted -> Student -> paternSurname);
    free(NodeDeleted -> Student -> maternSurname);
    free(NodeDeleted -> Student);
    free(NodeDeleted);
}

void askUpdate(NodePtr startlist){
    
    NodePtr NodeUpdate, NodeReplace;
   
    NodeUpdate = addNode(addStudents("David Leobardo","Perez","Cruz"));
    DeleteNode(startlist, NodeUpdate -> Student);

    NodeReplace = addNode(addStudents("Josefino","Detal","Pablo"));
    DeleteNode(startlist, NodeUpdate -> Student);

    Updatelist(startlist, NodeUpdate, NodeReplace);


    NodeUpdate = addNode(addStudents("Adrian","Fonseca","Loria"));
    DeleteNode(startlist, NodeUpdate -> Student);

    NodeReplace = addNode(addStudents("Lucho","Portus","Casas"));
    DeleteNode(startlist, NodeUpdate -> Student);

    Updatelist(startlist, NodeUpdate, NodeReplace);


    NodeUpdate = addNode(addStudents("Luis Miguel","Medina","Avila"));
    DeleteNode(startlist, NodeUpdate -> Student);

    NodeReplace = addNode(addStudents("Panfilo","Clodomiro","Urriaga"));
    DeleteNode(startlist, NodeUpdate -> Student);

    Updatelist(startlist, NodeUpdate, NodeReplace);
   
}

void Updatelist(NodePtr startlist, Node *StudentDelete, Node *StudentReplace){

    NodePtr actual, previous;
    int compared, flagDelete = 0;    
    previous = NULL;
    actual = startlist;

    while(actual != NULL && flagDelete == 0){
        compared = comparedata(StudentDelete -> Student, actual -> Student );
        if(compared == 0){ 

            if(previous == NULL){
                actual = actual -> next;
            }
            else {
                previous -> next = actual -> next;
                releaseMemory(actual);
            }
            flagDelete = 1;

        }else{
            previous = actual;
            actual = actual -> next;
        }
    }
    InsertOrganized(&startlist, StudentReplace);
}