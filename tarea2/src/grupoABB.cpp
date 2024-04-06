#include "../include/grupoABB.h"

struct rep_grupoABB {
    int key;
    TVisitante vis;
    rep_grupoABB *izq, *der;
};

TGrupoABB crearTGrupoABBVacio(){
    TGrupoABB Arbolito = NULL;
    return Arbolito;
}

void insertarTVisitanteTGrupoABB(TGrupoABB &grupoABB, TVisitante visitante){
    TGrupoABB nuevoNodo = new rep_grupoABB;
    nuevoNodo -> vis = visitante;
    nuevoNodo -> key = idTVisitante(visitante);
    nuevoNodo -> izq = nuevoNodo -> der = NULL;
    
    if (grupoABB == NULL)
        grupoABB = nuevoNodo;
    else {
        TGrupoABB actual = grupoABB;
        while (true) {
            if (idTVisitante(visitante) < idTVisitante(actual -> vis))
                if (actual -> vis == NULL){
                    actual -> izq = nuevoNodo;
                    break;
                }
                else
                    actual = actual -> izq;
            else
                if (actual -> der ==NULL) {
                    actual -> der = nuevoNodo;
                    break;
                }
                else
                    actual = actual -> der;
        }
        
    }

}

void imprimirTGrupoABB(TGrupoABB grupoABB){
    if (grupoABB != NULL) {
        imprimirTGrupoABB(grupoABB -> izq);
        imprimirTVisitante(grupoABB -> vis);
        imprimirTGrupoABB (grupoABB -> der);
    }
}

bool existeTVisitanteTGrupoABB(TGrupoABB grupoABB, int idVisitante){
    while ((grupoABB != NULL) && (grupoABB -> key != idVisitante)){
        if (grupoABB -> key > idVisitante)
            grupoABB = grupoABB -> izq;
        else 
            grupoABB = grupoABB -> der;
    }
    return grupoABB != NULL;
}

TVisitante obtenerTVisitanteTGrupoABB(TGrupoABB grupoABB, int idVisitante){
    while ((grupoABB != NULL) && (grupoABB -> key != idVisitante)){
        if (grupoABB -> key > idVisitante)
            grupoABB = grupoABB -> izq;
        else 
            grupoABB = grupoABB -> der;
    }
    return grupoABB -> vis;
}

void removerTVisitanteTGrupoABB(TGrupoABB &grupoABB, int idVisitante){

    TGrupoABB reemplazo = new rep_grupoABB;
    reemplazo -> vis = NULL;
    reemplazo -> key = NULL;
    reemplazo -> izq = reemplazo -> der = NULL;
    
    TGrupoABB padre = NULL;
    TGrupoABB actual = grupoABB;

    if (idVisitante != idTVisitante(actual -> vis)) {
        padre = actual;
        while (idVisitante != idTVisitante(actual -> vis)) { //buscamos el visitante a remover
            if (idVisitante < idTVisitante(actual -> vis)) 
                actual = actual -> izq;
            else
                actual -> der;
        }
    }

    if (actual -> izq == NULL && actual -> der == NULL) { // Caso 1 Nodo sin hijos
        if (padre == NULL) 
            grupoABB = actual -> der;
        else {
            if (padre -> izq == actual)
                padre -> izq = actual -> der;
            else
                padre -> der = actual -> der;
        }
        delete actual;
    }
    else  
        if (actual -> izq == NULL) { // Caso 2: Nodo con un hijo derecho
            if (padre == NULL) 
                grupoABB = actual->der;
            else 
                if (padre -> izq == actual) 
                padre -> izq = actual -> der;
            else 
                padre -> der = actual -> der;
            
            delete actual;
        }
        else
            if (actual -> der == NULL) { // Caso 3: Nodo con un hijo izquierdo
                if (padre == NULL)
                    grupoABB -> izq;
                else 
                    if (padre -> izq == actual)
                        padre -> izq = actual -> izq;
                    else
                        padre -> der = actual -> izq;
            }
            else { // Caso 3: Nodo con dos hijos
                TGrupoABB temp = actual -> izq;
                TGrupoABB padreTemp = actual;
                while (temp -> der != NULL) {
                    padreTemp = temp;
                    temp = temp -> der;
                }

                actual -> vis = temp -> vis;

                if (padreTemp -> izq == temp)
                    padreTemp -> izq = temp -> izq;
                else
                    padreTemp -> der = temp -> izq;

                delete temp;
            }
}

nat alturaTGrupoABB(TGrupoABB grupoABB) {

}

int cantidadVisitantesTGrupoABB(TGrupoABB grupoABB){
    return 0;
}

float edadPromedioTGrupoABB(TGrupoABB grupoABB) {
    return 0.;
}

void liberarTGrupoABB(TGrupoABB &grupoABB){

}

TVisitante maxIdTVisitanteTGrupoABB(TGrupoABB grupoABB){
    while (grupoABB -> der != NULL) {
        grupoABB = grupoABB -> der;
    }
    
    return grupoABB -> vis;
}

TVisitante obtenerNesimoVisitanteTGrupoABB(TGrupoABB grupoABB, int n){
    return NULL;
}

