#include "minish.h"

int builtin_setenv(int argc, char **argv) {
    int salida = -1;
    if(argc<3) {
        fprintf(stderr,"ERROR!! FALTAN ARGUMENTOS \n");
    } else if(argc>3) {
        fprintf(stderr, "ERROR!! DEMASIADOS ARGUMENTOS \n");
    } else {
        char *env;
        env=getenv(argv[1]);
        if(env==NULL) {
            setenv(argv[1], argv[2], 0);
        }
        else {
            setenv(argv[1], argv[2], 1);
        }
        salida = 0;
    }
    return salida;
}
