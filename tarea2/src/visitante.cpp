#include "../include/visitante.h"

struct rep_visitante {
    int id;
    char nVis[MAX_NOMBRE];
    char aVis[MAX_APELLIDO];
    int edad;

};

TVisitante crearTVisitante(int id, const char nombre[MAX_NOMBRE], const char apellido[MAX_APELLIDO], int edad){
    TVisitante nuevoVisitante = NULL;

    nuevoVisitante = new rep_visitante;
    nuevoVisitante -> id = id;
    strcpy(nuevoVisitante -> nVis, nombre);
    strcpy(nuevoVisitante -> aVis, apellido);
    nuevoVisitante -> edad = edad;
    
    return nuevoVisitante; 
}

void nombreTVisitante(TVisitante visitante, char nombre[MAX_NOMBRE]){
    strcpy(nombre, visitante -> nVis);
}

void apellidoTVisitante(TVisitante visitante, char apellido[MAX_APELLIDO]){
    strcpy(apellido, visitante -> aVis);
}

int idTVisitante(TVisitante visitante){
    return visitante -> id;
}

int edadTVisitante(TVisitante visitante){
    return visitante -> edad;
}

void liberarTVisitante(TVisitante &visitante){
    delete visitante;
}

TVisitante copiarTVisitante(TVisitante visitante){
    TVisitante copiaVis;
    copiaVis -> id = visitante -> id;
    strcpy(copiaVis -> nVis, visitante -> nVis);
    strcpy(copiaVis -> aVis, visitante -> aVis);
    copiaVis -> edad = visitante -> edad;

    return copiaVis;
}

void imprimirTVisitante(TVisitante visitante){
    printf ("Visitante %s %s\n", visitante -> nVis, visitante -> aVis);
    printf ("ID: %d\n", visitante -> id);
    printf ("Edad: %d", visitante -> edad);
}

