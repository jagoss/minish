#include "minish.h"
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <unistd.h>

#define TRUE 1
#define MAX 1024


#define HELP_CD     "cd [-|dir] - cambia de directorio corriente"
#define HELP_DIR    "dir [str]- muestra archivos en directorio corriente, que tengan 'str'"
#define HELP_EXIT   "exit [status] - finaliza el minish con un status de retorno (por defecto 0)"
#define HELP_HELP   "help [cd|dir|exit|help|history|getenv|pid|setenv|status|uid]"
#define HELP_HISTORY "history [N] - muestra los últimos N (10) comandos escritos"
#define HELP_GETENV "getenv var [var] - muestra valor de variable(s) de ambiente"
#define HELP_PID    "pid - muestra Process Id del minish"
#define HELP_SETENV "setenv var valor - agrega o cambia valor de variable de ambiente"
#define HELP_STATUS "status - muestra status de retorno de ultimo comando ejecutado"
#define HELP_UID    "uid - muestra nombre y número de usuario dueño del minish"

//FUNCIONES PENDIENTES ,dir,  history, EXTERNO ,

int status = SIN_STATUS;

struct builtin_struct builtin_arr[] = {
    {"exit", builtin_exit, HELP_EXIT},
    {"pid", builtin_pid, HELP_UID},
    {"uid", builtin_uid, HELP_PID},
    {"getenv", builtin_getenv, HELP_GETENV},
    {"setenv", builtin_setenv, HELP_SETENV},
    {"cd", builtin_cd, HELP_CD},
    {"status", builtin_status, HELP_STATUS},
    {"help", builtin_help, HELP_HELP},
    {"dir", builtin_dir, HELP_DIR},
    {"history", builtin_history, HELP_HISTORY},
};

int ejecutar(int argc, char **argv) {
	
    int cmd = -1;

    if(argc != 0) {

        for(int i = 0; i < CANTCOMANDOS; i++) {
            if(strcmp(argv[0], builtin_arr[i].cmd) == 0) {
                cmd = i;
            }
        }

        switch(cmd) {
        case -1:
            status = externo(argc, argv);
            break;
        case 0:
            status = builtin_exit(argc, argv);
            break;
        case 1:
            status = builtin_pid(argc, argv);
            break;
        case 2:
            status = builtin_uid(argc, argv);
            break;
        case 3:
            status = builtin_getenv(argc, argv);
            break;
        case 4:
            status = builtin_setenv(argc, argv);
            break;
        case 5:
            status = builtin_cd(argc, argv);
            break;
        case 6:
            status = builtin_status(argc, argv);
            break;
        case 7:
            status = builtin_help(argc, argv);
            break;
        case 8:
            status = builtin_dir(argc, argv);
            break;
        case 9:
            status = builtin_history(argc, argv);
            break;
		}
	}
	return 0;
}

void prompt()
{
    char cwd[MAX];
    getcwd(cwd, sizeof(cwd));
    fprintf(stderr, "%s:~%s>  ", getenv("USER"), cwd);
}

void main() {
    char buf[MAX];
    static char *argv[MAX];
    static int argc = 0;
    char *estado = "estado";
    char* my_home_dir = getenv("HOME");
    FILE *fh;

    if(my_home_dir == NULL) {
        printf("No se guarda historial porque no hay Home \n");
    } else {
        char hist_filename[MAX];
        snprintf(hist_filename, MAX, "%s/.minish_history", my_home_dir);
        fh = fopen( hist_filename, "a");
        if(fh == NULL) {
            printf("No se logro crear el archivo exitosamente \n");
        }
    }

    while( estado != NULL) {
        prompt();
        estado = fgets(buf, MAX, stdin);
        fprintf(fh, "%s", buf);
        fflush(fh);
        argc = linea2argv(buf, argv);
        ejecutar(argc, argv);
    }
}
