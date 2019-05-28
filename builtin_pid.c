#include "minish.h"

int builtin_pid(int argc, char **argv) {
    printf("Id de proceso: %d\n",getpid());
    return getpid();
}
