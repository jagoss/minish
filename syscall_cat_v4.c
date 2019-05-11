/*
 * syscall_cat: ejercicio que muestra el comando 'cat' usando read y write
 * v4 - escribe un "prompt"
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <error.h>

#define MAXBUF 1024 // muy chico a propósito - lo lógico sería un número tipo 512, 1024, etc.

// Header para manejo de señales
#include <signal.h>

void
newline (int sig)   // solamente escribe un \n, usado cuando llega SIGINT
{           // el argumento sig no se usa pero sigaction declara así la función
    fputc('\n', stderr);
}

void
prompt()            // escribe en stderr un mensaje de 'prompt'
{
    fprintf(stderr, "> ");
}


int
main(void)
{
    char buf[MAXBUF]; // buffer para read/write
    ssize_t nr, nw; // nro de bytes leidos/escritos

    struct sigaction act; // la estructura definida en signal.h

    // guardar el estado es una buena práctica para inicializar act
    if ( sigaction (SIGINT, NULL, &act)) {  // guarda el estado actual en act (man sigaction)
        error (1, errno, "error sigaction");
    }

    act.sa_handler = newline;   // función que captura la señal

    if ( sigaction (SIGINT, &act, NULL)) {
        error (1, errno, "error sigaction");
    }

    for (prompt(); (nr = read(0, buf, MAXBUF)) > 0 ||
            (nr < 0 && errno == EINTR); prompt()) { // atrapa Control-C en read
        if ( (nw = write(1, buf, nr)) != nr) {
            if (nw < 0) {
                error(1, errno, "Error en syscall write");
            } else {
                error(0, errno, "Warning en syscall write, se escribieron %d bytes de %d", nw, nr);
            }
        }
    }
    if (nr < 0) {
        error(1, errno, "Error en syscall read");
    }

    return 0;
}
