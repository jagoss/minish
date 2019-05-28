#include "minish.h"

int builtin_exit(int argc, char **argv) {
    int salida =0;
    if(argc > 2) {
        fprintf(stderr, "ERROR. Demasiados parametros\n");
        return(-1);
    }
    if(argv[1]!=NULL) {
        salida = *argv[1];
        exit(salida);
    } else {
        exit(0);
    }
    return salida;
}

