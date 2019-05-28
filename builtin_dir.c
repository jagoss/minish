#include "minish.h"

int builtin_dir(int argc, char **argv) {
    int salida = 0;
    DIR *dir = opendir(".");
    struct dirent *dirent;

    if(argc >2) {
        salida = -1;
        fprintf(stderr, "ERROR. DEMASIADOS ARGUMENTOS");

    } else if(argc == 1) {
        while( (dirent = readdir(dir)) != NULL) {
            if(strcmp(dirent->d_name, ".") != 0 && strcmp(dirent->d_name, "..") != 0) {
                printf("%s\t", dirent->d_name);
            }
        }

    } else {
        while( (dirent =readdir(dir)) != NULL) {
            if(my_strstr(dirent->d_name, argv[1]) != NULL && strcmp(dirent->d_name, ".") != 0 && strcmp(dirent->d_name, "..") != 0) {
                printf("%s\t", dirent->d_name);
            }
        }
    }

    printf("\n");
    return salida;
}

