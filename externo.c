#include "minish.h"

int externo(int argc, char **argv) {
    int salida = 0;
    int stat;
    pid_t child_pid;

    child_pid = fork();

    if(child_pid == 0) {
        execvp(argv[0], argv);
        fprintf(stderr, "Comando desconocido\n");

    } else {
        pid_t pid = waitpid(child_pid, &stat, 0);
        if(WIFEXITED(stat)) {
            salida = WEXITSTATUS(stat);
        } else {
            salida = -1;
            perror("Funcion externo");
        }
    }

    return salida;
}

