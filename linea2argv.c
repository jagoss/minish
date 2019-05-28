#include "minish.h"

int linea2argv(char *linea, char **argv) {
    int numero_de_palabras = 0;
    enum {IN, OUT};
    int state = OUT;

    for(; *linea != '\0'; linea++) {

        if(*linea == ' ' || *linea == '\n' || *linea == '\t') {
            state = OUT;
            *linea='\0';
        } else if(state == OUT) {
            state = IN;
            numero_de_palabras++;
            *argv++ = linea;
        }

    }
    *argv = NULL;

    return numero_de_palabras;
}

