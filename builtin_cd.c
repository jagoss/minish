#include "minish.h"
#define MAX 1024

static char last_dir[MAX];

int builtin_cd(int argc, char **argv) {
    int salida;
    char temp[MAX];

    if(argv[1] == NULL) {

        getcwd(last_dir, sizeof(last_dir));
        salida = chdir("/home");

    } else if(strcmp(argv[1],"-") == 0) {

        getcwd(temp, sizeof(temp));
        salida = chdir(last_dir);
        strcpy(last_dir, temp);

    } else {

        getcwd(last_dir,sizeof(last_dir));
        if( (salida = chdir(argv[1])) != 0)
            perror("cd failed");
    }

    return salida;
}

