#include "minish.h"
#define MAX 1024

int builtin_history(int argc, char **argv) {

    FILE *fh;
    char* my_home_dir = getenv("HOME");
    char* c;
    char* array = malloc(MAX);
    int i = 0;
    int n = 10;
    int llenado = 0;

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
        while((fgets(array, MAX, fh)) != NULL) {
            comandos[i] = strdup(array);
            i++;
            if(i > n) {
                i = 0;
                llenado = 1;
            }
        }
        int j = i+1;
        if(llenado == 0) {
            j = 0;
            while(j<=i-1) {
                printf("%s\n", comandos[j]);
                j++;
            }
        } else if (llenado == 1) {
            while (j!= i) {
                if(j >= n) {
                    j = 0;
                    printf("%s\n", comandos[j]);
                } else {
                    printf("%s\n", comandos[j]);
                    j++;
                }
			}
		}
	}
	return 0;
}
