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

void removerTVisitanteTGrupoABB(TGrupoABB &grupoABB, int idVisitante){

    TGrupoABB reemplazo = new rep_grupoABB;
    reemplazo -> vis = NULL;
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
    if (grupoABB == NULL) {
        return 0;
    }
    int alturaIzquierda = alturaTGrupoABB(grupoABB->izq);
    int alturaDerecha = alturaTGrupoABB(grupoABB->der);
    return 1 + (alturaIzquierda > alturaDerecha ? alturaIzquierda : alturaDerecha);
}

int cantidadVisitantesTGrupoABB(TGrupoABB grupoABB){
    int cantVis;
    if (grupoABB != NULL) {
        cantVis = cantidadVisitantesTGrupoABB(grupoABB -> izq);
        cantVis = cantidadVisitantesTGrupoABB (grupoABB -> der);
    }
    else 
        return 0;

    return cantVis;
}

int sumarEdades(TGrupoABB grupoABB) {
    if (grupoABB == NULL) {
        return 0;
    }
    return edadTVisitante(grupoABB -> vis) + sumarEdades(grupoABB -> izq) + sumarEdades(grupoABB -> der);
}

float edadPromedioTGrupoABB(TGrupoABB grupoABB) {
    int sumaEdades = 0;
    int cantidadVisitantes = cantidadVisitantesTGrupoABB(grupoABB);
    if (cantidadVisitantes > 0) {
        sumaEdades = sumarEdades(grupoABB);
    }
    return cantidadVisitantes > 0 ? (float)sumaEdades / cantidadVisitantes : 0.0f;
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

TVisitante obtenerNesimoVisitanteTGrupoABB(TGrupoABB grupoABB, int n){
    // Verificamos si el árbol está vacío o si n es menor o igual a cero.
    if (grupoABB == NULL || n <= 0) {
        return NULL; // Si es así, retornamos NULL ya que no hay n-ésimo visitante.
    }

    // Contador para seguir el número de nodos visitados.
    int contador = 0;

    // Usamos un bucle para iterar a través del árbol en orden ascendente.
    while (grupoABB != NULL) {
        // Primero vamos a la izquierda.
        if (grupoABB -> izq != NULL) {
            grupoABB = grupoABB->izq;
        } else {
            // Si ya no hay más nodos a la izquierda, revisamos el nodo actual.
            contador++; // Incrementamos el contador.

            // Si el contador es igual a n, hemos encontrado el n-ésimo visitante.
            if (contador == n) {
                return copiarTVisitante(grupoABB -> vis); // Devolvemos una copia del visitante.
            }

            // Luego avanzamos al siguiente nodo.
            grupoABB = grupoABB -> der;
        }
    }

    // Si llegamos aquí, significa que no encontramos el n-ésimo visitante.
    return NULL;
}

