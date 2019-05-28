#include "minish.h"

int builtin_getenv(int argc, char **argv) {
    int salida = 0;
    int error = 0;

    for(int i=1; i<argc; i++) {

        if(getenv(argv[i]) ==NULL) {
            printf("Esta variable no existe en el environment: %s \n", argv[i]);
            salida = -1;
            error = 1;
        }
        else {
            printf("%s = %s\n",argv[i], getenv(argv[i]));
        }
    }
    return salida ;

}
