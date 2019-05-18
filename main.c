#include "minish.h"
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <unistd.h>

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


//FUNCIONES PENDIENTES pid, uid, arreglar prompt de getenv, cd,  status, dir,  history, EXTERNO ,


int status = -1;


int builtin_cd(int argc, char **argv){
	int salida;

    if(argv[1] == NULL){
        salida = chdir("/home");
    }else{
        if( (salida = chdir(argv[1])) != 0)
			perror("cd failed");
    } 
	        
    return salida;
}

int builtin_dir(int argc, char **argv) {
	int salida = 0;
	DIR *dir = opendir(".");
	struct dirent *dirent;
	if(argc >2){
		salida = -1;
		fprintf(stderr, "ERROR. DEMASIADOS ARGUMENTOS");
	}else if(argc == 1){

		while((dirent = readdir(dir)) != NULL){
			printf("%s\n", dirent->d_name);
		}
	}else{
	//fixme agregar funcion aguja en pajar para encontrar el primer parametro	
	}
	return salida;
}

int builtin_exit(int argc, char **argv) {
    int salida =0;
    if(argc > 2){
        fprintf(stderr, "ERROR. Demasiados parametros\n");
		return(-1);
    }
    if(argv[1]!=NULL){
		 salida = *argv[1];
         exit(salida);
	}else{
	    exit(0);
	}    
    return salida;
}

int builtin_help(int argc, char **argv) {
    int cmd=0;
    if(argv[1] == NULL){
        for(int i=0; i<CANTCOMANDOS; i++){
            printf("%s\n", builtin_arr[i].cmd); 
        }
    
    }else{
        for(int i=0; i<CANTCOMANDOS; i++){
            if(strcmp(argv[1], builtin_arr[i].cmd)==0){
                cmd=i;
            }
        }
        printf("%s\n", builtin_arr[cmd].help_txt);
    }
    return 0;
	}

int builtin_history(int argc, char **argv) {
    return 0;
}

int builtin_status(int argc, char **argv) {
	if(status == -1){
		printf("TODAVIA NO SE HA EJECUTADO NINGUNA FUNCION\n");	
	}else{
		printf("Stauts: %d\n", status);
	}
	
    return 0;
}

int builtin_getenv(int argc, char **argv) {
	char *env;
	env=getenv(argv[1]);
	if(env==NULL || strcmp(env, "") == 0){
		printf("Esta variable no existe en el environment \n");
	}
	else{
		printf("%s = %s\n",argv[1], getenv(argv[1]));
	}
	return 0 ;
}

int builtin_setenv(int argc, char **argv) {
	char *env;
	env=getenv(argv[1]);
	if(env==NULL){
		setenv(argv[1], argv[2], 0);
	}
	else{
		setenv(argv[1], argv[2], 1);
	}

    return 0;
}

int builtin_uid(int argc, char **argv) {
    struct passwd *infouser = getpwuid(geteuid());
	printf("Nombre de usuario: %s\n",infouser->pw_name);
	printf("Id usuario: %d\n",infouser->pw_uid);
	return 0;
}

int builtin_pid(int argc, char **argv) {
    printf("Id de proceso: %d\n",getpid());	
    return getpid();
}

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
    
    int cmd = -1;

	if(argc != 0){
    		
		for(int i = 0;i < CANTCOMANDOS; i++){
			if(strcmp(argv[0], builtin_arr[i].cmd) == 0){
				cmd = i;
			}
		}

		switch(cmd){
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
	}else{
		printf("No hay argumentos\n");
	}
}

void
prompt()
{
    char cwd[MAX];
    getcwd(cwd, sizeof(cwd));    
    fprintf(stderr, "%s:~%s>  ", getenv("USER"), cwd);
}


void main() {
    char buf[MAX];
    char *argv[MAX];
    int argc = 0;
    char *estado = "estado";

    while( estado != NULL){
	prompt();
       	estado = fgets(buf, MAX, stdin);
	argc = linea2argv(buf, argv);
	ejecutar(argc, argv);
	
	
    }
}
