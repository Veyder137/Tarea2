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
    return piezas == NULL;
}

bool existePiezaColeccionPiezas(TColeccionPiezas coleccionPiezas, int idPieza){
    TColeccionPiezas actual = coleccionPiezas;
    while (actual != NULL) {
        if (idTPieza(actual -> pieza) == idPieza) {
            return true;
        }
        actual = *actual -> sig;
    }
    return false;
}

TPieza obtenerPiezaColeccionPiezas(TColeccionPiezas coleccionPiezas, int idPieza){
    TColeccionPiezas actual = coleccionPiezas;
    while (actual != NULL) {
        if (idTPieza(actual -> pieza) == idPieza) {
            return actual->pieza;
        }
        actual = *actual -> sig;
    }
    return NULL;
}

void removerPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, int idPieza){
    if (coleccionPiezas == NULL) {
        return;
    }
    if (idTPieza(coleccionPiezas -> pieza) == idPieza) {
        TColeccionPiezas temp = coleccionPiezas;
        coleccionPiezas = *coleccionPiezas -> sig;
        liberarTPieza(temp -> pieza);
        delete temp;
        return;
    }
    TColeccionPiezas prev = coleccionPiezas;
    TColeccionPiezas current = *coleccionPiezas -> sig;
    while (current != NULL) {
        if (idTPieza(current -> pieza) == idPieza) {
            prev -> sig = current -> sig;
            liberarTPieza(current -> pieza);
            delete current;
            return;
        }
        prev = current;
        current = *current -> sig;
    }
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