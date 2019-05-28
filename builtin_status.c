#include "minish.h"

int builtin_status(int argc, char **argv) {
    int salida;
    if(status == SIN_STATUS) {
        printf("TODAVIA NO SE HA EJECUTADO NINGUNA FUNCION\n");
        salida=-1;
    } else {
        printf("Status: %d\n", status);
        salida=0;
    }

    return salida;
}
