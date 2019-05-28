minish:	main.o externo.o strstr.o builtin_history.o builtin_status.o builtin_setenv.o builtin_pid.o builtin_uid.o builtin_help.o builtin_getenv.o builtin_cd.o builtin_exit.o linea2argv.o builtin_dir.o
	cc main.o externo.o strstr.o builtin_history.o builtin_status.o builtin_setenv.o builtin_pid.o builtin_uid.o builtin_help.o builtin_getenv.o builtin_cd.o linea2argv.o builtin_exit.o builtin_dir.o -o minish

main.o: main.c minish.h
	cc -c main.c
builtin_cd.o: builtin_cd.c minish.h
	cc -c builtin_cd.c
linea2argv.o: linea2argv.c minish.h
	cc -c linea2argv.c
builtin_help.o: builtin_help.c minish.h
	cc -c builtin_help.c
builtin_exit.o: builtin_exit.c minish.h
	cc -c builtin_exit.c
builtin_uid.o: builtin_uid.c minish.h
	cc -c builtin_uid.c
builtin_pid.o: builtin_pid.c minish.h
	cc -c builtin_pid.c
builtin_getenv.o: builtin_getenv.c minish.h
	cc -c builtin_getenv.c
builtin_setenv.o: builtin_setenv.c minish.h
	cc -c builtin_setenv.c
builtin_status.o: builtin_status.c minish.h
	cc -c builtin_status.c
builtin_dir.o: builtin_dir.c minish.h
	cc -c builtin_dir.c
builtin_history.o: builtin_history.c minish.h
	cc -c builtin_history.c
externo.o: externo.c minish.h
	cc -c externo.c
strstr.o: strstr.c minish.h
	cc -c strstr.c
clean:
	rm -f *.o minish
