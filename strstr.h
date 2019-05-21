#include <stdio.h>

char * my_strstr(char *pajar, char *aguja) {

	char *salida;
	int encontrado = 0;
	int counterInicio = 0;
	int counter = 0;

	while(*pajar != '\0' && encontrado != 1){
	
			
		while(*pajar == *aguja && *aguja != '\0'){
			counter++;	
			pajar++;
			aguja++;				
		}

		if(*aguja == '\0'){
			encontrado = 1;
		}else{
			pajar = pajar - counter;
			aguja = aguja - counter;
			counter = 0;	
		}	
		
		pajar++;
	}

	if(encontrado != 1){
		salida = NULL;
	}

	return salida;
}
