#include "minish.h"

int builtin_help(int argc, char **argv) {
    int cmd=0;
    if(argv[1] == NULL) {
        for(int i=0; i<CANTCOMANDOS; i++) {
            printf("%s\n", builtin_arr[i].cmd);
        }

    } else {
        for(int i=0; i<CANTCOMANDOS; i++) {
            if(strcmp(argv[1], builtin_arr[i].cmd)==0) {
                cmd=i;
            }
        }
        printf("%s\n", builtin_arr[cmd].help_txt);
    }
    return 0;
}
