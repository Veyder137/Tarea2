#include "../include/coleccionPiezas.h"

struct rep_coleccionpiezas{
    TPieza pieza;
    TColeccionPiezas * sig;
};

TColeccionPiezas crearColeccionPiezasVacia(){ 
    return NULL; 
}

void insertarPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, TPieza pieza){
    TColeccionPiezas aux = new rep_coleccionpiezas;
    aux -> pieza = pieza;
    aux -> sig = NULL;

    if (coleccionPiezas == NULL || (idTPieza(pieza) < idTPieza(coleccionPiezas -> pieza))) {
        *aux -> sig = coleccionPiezas;
        coleccionPiezas = aux;
    }
    else {
        TColeccionPiezas actual = coleccionPiezas;
        while (actual -> sig != NULL && idTPieza(pieza) > idTPieza(actual -> sig -> pieza)){
            actual = *actual -> sig;
        }
        aux -> sig = actual -> sig;
        *actual -> sig = aux;
    }
}

void imprimirColeccionPiezas(TColeccionPiezas coleccionPiezas){
    TColeccionPiezas actual = coleccionPiezas;
    if (esVaciaColeccionPiezas (coleccionPiezas) == false) {
        while (actual != NULL) {
            imprimirTPieza(actual -> pieza);
            actual = *actual -> sig;
    }
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
            return actual -> pieza;
        }
        actual = *actual -> sig;
    }
    return;
}

void removerPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, int idPieza){
    if (coleccionPiezas == NULL) { //caso coleccion vacio
        return;
    }
    if (idTPieza(coleccionPiezas -> pieza) == idPieza) { //caso pieza en primer lugar
        TColeccionPiezas temp = coleccionPiezas;
        coleccionPiezas = *coleccionPiezas -> sig;
        liberarTPieza(temp -> pieza);
        delete temp;
    }
    else {
        TColeccionPiezas temp;
        TColeccionPiezas actual = coleccionPiezas;
        while ((actual != NULL) && (idTPieza(actual -> pieza) < idPieza)) {
            if (idTPieza(actual -> sig -> pieza) == idPieza) {
                temp = actual -> sig;
                actual -> sig = temp -> sig;
                liberarTPieza(temp -> pieza);
                delete temp;
            }
            actual = actual -> sig;
        }
    }
}

void liberarColeccionPiezas(TColeccionPiezas &coleccionPiezas){
    TColeccionPiezas actual = coleccionPiezas;
    while (actual != NULL) {
        TColeccionPiezas siguiente = *actual -> sig;
        liberarTPieza(actual -> pieza);
        delete actual;2
        actual = siguiente;
    }
    coleccionPiezas = NULL;
}