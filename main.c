#include "minish.h"
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

#define CANTCOMANDOS 10
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

int builtin_cd(int argc, char **argv){
    
     
    return 0;
}

int builtin_dir(int argc, char **argv) {
    return 0;
}
int builtin_exit(int argc, char **argv) {
    /*int salida =0;
    if(argc > 2){
        salida = -1;
    }
    if(argv[1]!=NULL){
		 salida = *argv[1];
         int status = *argv[1];
         exit(status);
	}else{
	    exit(0);
	}
    
    return salida;
    */
    return 0;
}
int builtin_help(int argc, char **argv) {
    int cmd=0;
    if(argv[0==NULL]){
        for(int i=0; i<CANTCOMANDOS; i++){
            printf("%s/n", builtin_arr[i]); 
        }
    
    }else{
        for(int i=0; i<CANTCOMANDOS; i++){
            if(strcmp(argv[0], builtin_arr[i].cmd)==0){
                cmd=i;
            }
        }
        printf("%s", builtin_arr[cmd].help_txt);
    }
    return 0;
}
int builtin_history(int argc, char **argv) {
    return 0;
}
int builtin_status(int argc, char **argv) {
    return 0;
}
int builtin_getenv(int argc, char **argv) {
    return 0;
}
int builtin_setenv(int argc, char **argv) {
    return 0;
}
int builtin_uid(int argc, char **argv) {
    return 0;
}
int builtin_pid(int argc, char **argv) {
    return 0;
}

struct builtin_struct builtin_arr[] = {
    {"cd", builtin_cd, HELP_CD},
    {"dir", builtin_dir, HELP_DIR},
    {"exit", builtin_exit, HELP_EXIT},
    {"help", builtin_help, HELP_HELP},
    {"history", builtin_history, HELP_HISTORY},
    {"status", builtin_status, HELP_STATUS},
    {"getenv", builtin_getenv, HELP_GETENV},
    {"setenv", builtin_setenv, HELP_SETENV},
    {"uid", builtin_uid, HELP_UID},
    {"pid", builtin_pid, HELP_PID},
};


int externo(int argc, char **argv) {
    return 0;
}

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

int ejecutar(int argc, char **argv){
    
    int cmd = 0;

	if(argc != 0){
    		
		for(int i = 0;i < CANTCOMANDOS; i++){
			if(strcmp(argv[0], builtin_arr[i].cmd) == 0){
				cmd = i;
			}
		}

		switch(cmd){
		case 0:
		builtin_exit(argc, argv);	
		break;
		case 1:
			builtin_pid(argc, argv);
		break;
		case 2:
			/*struct passwd *infouser = getpwuid();
			printf("Nombre de usuario: %s\n",infouser->pw_name);
			printf("Id usuario: ",infouser->pw_uid); //pw_uid es una estructura, no se si esta bien */
			
			//Verificar errores, es comentado para poder probar otras cosas
		break;
		case 3:
			builtin_getenv(argc, argv);
		break;
		case 4:
			builtin_setenv(argc, argv);
		break;
		case 5:
			if(argv[1] == NULL){
				chdir("/home");
			}else if(strcmp(argv[1],"-")==0){
				chdir("..");
			}else{
				chdir(argv[1]);
			}
		break;

        }
	}
}

void
prompt()
{
    fprintf(stderr, "%s> ", "$USER");
}


int main(void) {
    char buf[MAX];
    char *input[MAX];
    int argc =0;
    exit(0);

    while(TRUE){
        fgets(buf, MAX, stdin);
        argc = linea2argv(buf, input);
    }
}
