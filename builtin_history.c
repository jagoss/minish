#include "minish.h"
#define MAX 1024


int builtin_history(int argc, char **argv) {
          
            FILE *fh;
            char* my_home_dir = getenv("HOME");
            char* c;
            char* array = malloc(MAX);
            int i = 0;
            int n = 10;

            if (argc == 2) {
                n = atoi(argv[1]);
            }
            char* comandos[n];

            if(my_home_dir == NULL) {
                printf("No se guarda historial porque no hay Home \n");
                return 0;
            } else {
                char hist_filename[MAX];
                snprintf(hist_filename, MAX, "%s/.minish_history", my_home_dir);
                fh = fopen(  hist_filename, "r");
                if (fh == NULL) {
                    printf("ERROR ARCHIVO VACIO\n");
                    return 0;
                }
		int contador = 0;
                while((fgets(array, MAX, fh)) != NULL) {
                    comandos[i] = strdup(array);
                    i=(i+1)%n;
		    contador++;
		}
		int b;
		int lineas;
		if(contador<n){
		    lineas = contador;
		    i=0;
		}else{
		    lineas = n;
		}
		printf("\n");
		for(int j = 0; j<lineas; j++){
		    b = (i+j)%n;
		    printf("%s\n", comandos[b]);
		}
            }
            return 0;
       }

