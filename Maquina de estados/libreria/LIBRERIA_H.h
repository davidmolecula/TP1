#ifndef LIBRERIA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef enum {
	okay=0,
	notokay=1
}estados_t;

typedef enum{
	cables=0,
	tension_limite=1,
	tension=2,
	avisos=3
}claves_t;

typedef struct {
 estados_t cables;
 int tension_limite;
 int tension;
 char avisos[50];	
}datos_t;

datos_t f_inicio(void);
estados_t f_espera(datos_t);
estados_t f_desconexion(datos_t);
int f_medir_tension();
estados_t f_estados(int, int );
char *obtenerclave(char *clave);

#endif
