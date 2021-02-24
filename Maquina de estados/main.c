#include "...\libreria\LIBRERIA_H.h"


int main() 
{
	datos_t config; //Declaro la estructura donde van a estar los datos que necesita la maquina 
	estados_t estado = okay; //inicializo la maquina con
    estados_t (*fsm[])(datos_t) = {f_espera, f_desconexion};/* Declaro el vector puntero a funciones que va a llamar a las funciones y pasarles la 
	estructura segun el estado en el que se encuentre la maquina */
    config=f_inicio(); // Llamo a la funcion inicio que será la que lea el archivo de configuracion y establezca el estado de la maquina
    while(1) estado = (*fsm[estado])(config);
	printf("%d \t %d \t %d \t %s\n", config.cables, config.tension_limite, config.tension, config.avisos);
	return 0;
}
