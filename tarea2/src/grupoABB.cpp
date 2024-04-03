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
    TGrupoABB hoja = new rep_grupoABB;
    hoja -> vis = visitante;
    hoja -> key = idTVisitante(visitante);
    hoja -> izq = hoja -> der =NULL;

    if (grupoABB == NULL)
        grupoABB = hoja;
    else 
        if (idTVisitante(visitante) < grupoABB -> key)
            insertarTVisitanteTGrupoABB (grupoABB -> izq, visitante);
        else if (idTVisitante(visitante) > grupoABB -> key)
            insertarTVisitanteTGrupoABB (grupoABB -> der, visitante);
}

void imprimirTGrupoABB(TGrupoABB grupoABB){
    
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

TGrupoABB minimo (TGrupoABB grupoABB){
    if (grupoABB == NULL) 
        return NULL;
    else {
        while(grupoABB -> izq != NULL){
            grupoABB = grupoABB -> izq;
        }
    return grupoABB;
    }
}

void removerTVisitanteTGrupoABB(TGrupoABB &grupoABB, int idVisitante){
    TGrupoABB gABB = grupoABB;
    if (gABB != NULL) {
        if ( idVisitante < gABB -> key)
            removerTVisitanteTGrupoABB(gABB, idVisitante);
        else if (idVisitante > gABB -> key)
            removerTVisitanteTGrupoABB(gABB, idVisitante);
        else { // idVisitante == gABB -> key
            if (gABB -> der == NULL){
                TGrupoABB aBorrar = gABB;
                gABB = gABB -> izq;
                delete aBorrar;
            }
            else {
                TGrupoABB min_t_der = minimo(gABB -> der);
                gABB -> key = min_t_der -> key;
                gABB -> vis = min_t_der -> vis;
                removerTVisitanteTGrupoABB(gABB, idVisitante);
            }
        }
    }
}

nat alturaTGrupoABB(TGrupoABB grupoABB) {
    if (grupoABB == NULL) 
        return 0;
    else {
        int altura_izq = alturaTGrupoABB(grupoABB->izq);
        int altura_der = alturaTGrupoABB(grupoABB->der);
        return 1 + (altura_izq > altura_der ? altura_izq : altura_der);
    }
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
    return NULL;
}

TVisitante obtenerNesimoVisitanteTGrupoABB(TGrupoABB grupoABB, int n){
    return NULL;
}

