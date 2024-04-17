#include "../include/grupoABB.h"

struct rep_grupoABB {
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
    nuevoNodo -> izq = nuevoNodo -> der = NULL;
    
    if (grupoABB == NULL)
        grupoABB = nuevoNodo;
    else {
        TGrupoABB actual = grupoABB;
        while (true) {
            if (idTVisitante(visitante) < idTVisitante(actual -> vis))
                if (actual -> izq == NULL){
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
    while ((grupoABB != NULL) && (idTVisitante(grupoABB -> vis) != idVisitante)){
        if (idTVisitante(grupoABB -> vis) > idVisitante)
            grupoABB = grupoABB -> izq;
        else 
            grupoABB = grupoABB -> der;
    }
    return grupoABB != NULL;
}

TVisitante obtenerTVisitanteTGrupoABB(TGrupoABB grupoABB, int idVisitante){
    while ((grupoABB != NULL) && (idTVisitante(grupoABB -> vis) != idVisitante)){
        if (idTVisitante(grupoABB -> vis) > idVisitante)
            grupoABB = grupoABB -> izq;
        else 
            grupoABB = grupoABB -> der;
    }
    return grupoABB -> vis;
}


void removerTVisitanteTGrupoABB(TGrupoABB &grupoABB, int idVisitante) {
    if (grupoABB == NULL) {
        return; // No hay nada que eliminar si el árbol está vacío.
    }

    // Si el ID del visitante es menor que el ID del visitante actual, buscamos en el subárbol izquierdo.
    if (idVisitante < idTVisitante(grupoABB -> vis)) {
        removerTVisitanteTGrupoABB(grupoABB -> izq, idVisitante);
    }
    // Si el ID del visitante es mayor que el ID del visitante actual, buscamos en el subárbol derecho.
    else if (idVisitante > idTVisitante(grupoABB -> vis)) {
        removerTVisitanteTGrupoABB(grupoABB->der, idVisitante);
    }
    // Si encontramos el nodo con el ID del visitante a eliminar.
    else {
        // Caso 1: Nodo sin hijos o con un solo hijo.
        if (grupoABB -> izq == NULL) {
            TGrupoABB temp = grupoABB;
            grupoABB = grupoABB -> der;
            liberarTVisitante(temp -> vis);
            delete temp;
        } else if (grupoABB -> der == NULL) {
            TGrupoABB temp = grupoABB;
            grupoABB = grupoABB -> izq;
            liberarTVisitante(temp -> vis);
            delete temp;
        }
        // Caso 2: Nodo con dos hijos.
        else {
            // Encontramos el sucesor y mantenemos a su padre al tanto
            TGrupoABB padre_suc = grupoABB;
            TGrupoABB sucesor = grupoABB -> izq; // izq automatico porque tiene 2 hijos
            while (sucesor -> der != NULL) {
                padre_suc = sucesor;
                sucesor = sucesor -> der;
            }
            if (padre_suc == grupoABB)
                padre_suc -> izq = NULL;
            else
                padre_suc -> der = NULL;
            liberarTVisitante(grupoABB -> vis);
            grupoABB -> vis = copiarTVisitante(sucesor -> vis);
            liberarTVisitante(sucesor -> vis);
            delete sucesor;
        }
    }
}


nat alturaTGrupoABB(TGrupoABB grupoABB) {
    if (grupoABB == NULL) {
        return 0; // La altura de un árbol vacío es 0.
    } else {
        // Calculamos las alturas de los subárboles izquierdo y derecho
        nat alturaIzq = alturaTGrupoABB(grupoABB -> izq);
        nat alturaDer = alturaTGrupoABB(grupoABB -> der);

        // Comparamos las alturas y retornamos la mayor altura más 1 por el nodo actual
        if (alturaIzq > alturaDer) {
            return 1 + alturaIzq;
        } else {
            return 1 + alturaDer;
        }
    }
}


int cantidadVisitantesTGrupoABB(TGrupoABB grupoABB) {
    if (grupoABB == NULL) {
        return 0; // Si el árbol está vacío, retorna 0.
    } else {
        // La cantidad de visitantes en el árbol es la suma de los visitantes en los subárboles izquierdo y derecho, más 1 por el nodo actual.
        return 1 + cantidadVisitantesTGrupoABB(grupoABB -> izq) + cantidadVisitantesTGrupoABB(grupoABB -> der);
    }
}

int sumarEdades(TGrupoABB grupoABB) {
    if (grupoABB == NULL) {
        return 0;
    }
    return edadTVisitante(grupoABB -> vis) + sumarEdades(grupoABB -> izq) + sumarEdades(grupoABB -> der);
}

float edadPromedioTGrupoABB(TGrupoABB grupoABB) {
    int cantidad = cantidadVisitantesTGrupoABB(grupoABB);
    if (cantidad == 0) {
        return 0; // Si no hay visitantes en el grupo, devuelve 0.
    } else {
        float sumaEdades = sumarEdades(grupoABB);
        return sumaEdades / cantidad; // Retorna la suma de las edades dividida por la cantidad de visitantes.
    }
}


void liberarTGrupoABB(TGrupoABB &grupoABB){
    if (grupoABB != NULL) {
        liberarTGrupoABB(grupoABB -> izq);
        liberarTGrupoABB(grupoABB -> der);
        liberarTVisitante(grupoABB -> vis);
        delete grupoABB;
        grupoABB = NULL;
    }
}

TVisitante maxIdTVisitanteTGrupoABB(TGrupoABB grupoABB){
    while (grupoABB -> der != NULL) {
        grupoABB = grupoABB -> der;
    }
    
    return grupoABB -> vis;
}

TVisitante obtenerNesimoVisitanteTGrupoABB(TGrupoABB grupoABB, int n) {
    if (grupoABB == NULL || n <= 0) {
        return NULL; // Si el árbol está vacío o n es menor o igual a 0, retorna NULL.
    }

    int cantidadIzq = cantidadVisitantesTGrupoABB(grupoABB ->izq);
    if (n <= cantidadIzq) {
        // Si el n-ésimo visitante está en el subárbol izquierdo, buscamos recursivamente en ese subárbol.
        return obtenerNesimoVisitanteTGrupoABB(grupoABB -> izq, n);
    } else if (n == cantidadIzq + 1) {
        // Si el n-ésimo visitante es el nodo actual, lo retornamos.
        return grupoABB -> vis;
    } else {
        // Si el n-ésimo visitante está en el subárbol derecho, buscamos recursivamente en ese subárbol,
        // ajustando el valor de n para considerar los nodos ya procesados en el subárbol izquierdo y el nodo actual.
        return obtenerNesimoVisitanteTGrupoABB(grupoABB -> der, n - cantidadIzq - 1);
    }
}


