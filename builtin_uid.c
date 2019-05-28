#include "minish.h"

int builtin_uid(int argc, char **argv) {
    struct passwd *infouser = getpwuid(geteuid());
    printf("Nombre de usuario: %s\n",infouser->pw_name);
    printf("Id usuario: %d\n",infouser->pw_uid);
    return 0;
}
