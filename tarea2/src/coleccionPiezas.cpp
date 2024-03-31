#include "../include/coleccionPiezas.h"

struct rep_coleccionpiezas{
    TPieza pieza;
    TColeccionPiezas * sig;
};

TColeccionPiezas crearColeccionPiezasVacia(){ 
    return NULL; 
}

void insertarPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, TPieza pieza){
    TColeccionPiezas nuevoNodo = new rep_coleccionpiezas;
    nuevoNodo -> pieza = pieza;
    nuevoNodo -> sig = NULL;

    if (coleccionPiezas == NULL || idTPieza(pieza) < idTPieza(coleccionPiezas->pieza)) {
        *nuevoNodo -> sig = coleccionPiezas;
        coleccionPiezas = nuevoNodo;
    }
    else {
        TColeccionPiezas actual = coleccionPiezas;
        while (actual -> sig != NULL && idTPieza(pieza) < idTPieza(coleccionPiezas->pieza)){
            actual = *actual -> sig;
        }
        nuevoNodo -> sig = actual -> sig;
        *actual -> sig = nuevoNodo;
    }
}

void imprimirColeccionPiezas(TColeccionPiezas coleccionPiezas){
    TColeccionPiezas actual = coleccionPiezas;
    while (actual != NULL) {
        imprimirTPieza(actual -> pieza);
        actual = *actual -> sig;
    }
}

bool esVaciaColeccionPiezas(TColeccionPiezas piezas){
    return true;
}

bool existePiezaColeccionPiezas(TColeccionPiezas coleccionPiezas, int idPieza){
    return true;
}

TPieza obtenerPiezaColeccionPiezas(TColeccionPiezas coleccionPiezas, int idPieza){
    return NULL;
}

void removerPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, int idPieza){
    
}

void liberarColeccionPiezas(TColeccionPiezas &coleccionPiezas){
    TColeccionPiezas actual = coleccionPiezas;
    while (actual != NULL) {
        TColeccionPiezas siguiente = *actual -> sig;
        liberarTPieza(actual -> pieza);
        delete actual;
        actual = siguiente;
    }
    coleccionPiezas = NULL;
}