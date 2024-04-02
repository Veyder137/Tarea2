#include "../include/pieza.h"

struct rep_pieza {
    int iden;
    char nPieza[MAX_NOMBRE_PIEZA];
    char nAutor[MAX_NOMBRE_AUTOR];
    char aAutor[MAX_APELLIDO_AUTOR];
    TFecha fecha;
    };

TPieza crearTPieza(int identificador, const char nombrePieza[MAX_NOMBRE_PIEZA], const char nombreAutor[MAX_NOMBRE_AUTOR], const char apellidoAutor[MAX_APELLIDO_AUTOR], TFecha fechaCreacion){
    TPieza nuevaPieza = NULL;

    nuevaPieza = new rep_pieza;
    nuevaPieza -> iden = identificador;
    strcpy(nuevaPieza -> nPieza, nombrePieza);
    strcpy(nuevaPieza -> nAutor, nombreAutor);
    strcpy(nuevaPieza -> aAutor, apellidoAutor);
    nuevaPieza -> fecha = fechaCreacion;
    
    return nuevaPieza;
}

int idTPieza(TPieza pieza){ 
    return pieza -> iden;
}

void imprimirTPieza(TPieza pieza){
    printf("Pieza: %d\n", idTPieza(pieza));
    printf ("%s-%s %s\n", pieza -> nPieza, pieza -> nAutor, pieza -> aAutor);
    printf("Creada en: ");
    imprimirTFecha(pieza -> fecha);
}

void liberarTPieza(TPieza &pieza){
    liberarTFecha(pieza -> fecha);
    delete pieza;
    pieza = NULL;
}


