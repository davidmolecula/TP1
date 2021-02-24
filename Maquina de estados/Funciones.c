#include "...\libreria\LIBRERIA_H.h"


estados_t f_espera(datos_t config){
	config.tension=f_medir_tension();
	config.cables=f_estados(config.tension, config.tension_limite);
	return config.cables;
}

int f_medir_tension(){
	int tension;
	printf("\nTension: ");
	scanf("%d",&tension);
	return tension;
}

estados_t f_estados(int tension, int tension_limite)
{
	estados_t estado;
	if((tension> tension_limite)){
		estado=notokay;
		return estado;
	}else
		estado=okay;
		return estado;
	
}

estados_t f_desconexion(datos_t config){
	printf("\nPor seguridad de la instalacion electrica se interrumpe la corriente");
	config.tension=f_medir_tension();
	config.cables=f_estados(config.tension, config.tension_limite);
	if(config.cables==okay)
	{
		return okay;
	}else{
		return notokay;
	}
}

datos_t f_inicio() {
	
	FILE *config; 
	char cadena[50], *clave, *val; /* Con cadena voy a leer las lineas del archivo de config, clave y val van a ser los punteros con los que maneje la clave 
	y la posicion de memoria donde estara mi variable */
	char variables[4][50]={"cables","tension_limite","tension","avisos"}, i; /* Guardo estas cadenas con los nombres de mis variables para comparar mas adelante */
	datos_t configuracion; 
	claves_t claves;
 	if(!(config=fopen("Config.txt","rb"))){ /* Intento abrir el archivo config.txt, si no se puede lo avisa por pantalla y tira error */
 		printf("\nNo se encontro el archivo\n");
 		
	 }
	 fgets(cadena,50,config); 
	 do{
	 	clave=cadena; /* El puntero a char clave apunta en la direccion de cadena */
	 	if(*(clave) != '/' && strlen(clave)>=0){ /* Mientras que la linea del archivo de config sea distinto de '/' (que significa que es un comentario)
	 	y sea mayor que 0 (que no sea una linea vacia) lee el nombre de la variable en clave y deja la direccion del comienzo de la variable siguiente en val */
	 		val=obtenerclave(clave);
	 		for(i=0;i<4;i++)
	 		{
	 			if(!strcmp(clave, variables[i])){ // Acá es cuando compara, por eso lee el nombre de la variable en clave, los mismos nombres que guarda en variables
	 				switch(i)
	 				{
	 					case cables: configuracion.cables=atoi(val); // Guarda los datos en la estructura
	 							break;
	 					case tension_limite: configuracion.tension_limite=atoi(val);
	 							break;
	 					case tension: configuracion.tension=atoi(val);
	 							break;
	 					case avisos: strcpy(configuracion.avisos,val);
	 							break;
	 							
					 }
				 }
			 }
	 		
		 }
		 fgets(cadena,50,config);
	 }while(!feof(config));
	 
	 fclose(config);
	 
	return configuracion;
}

char *obtenerclave(char *clave){
	char i=0;
	
	while(*(clave+i)!=' '){
		i++;
	}
	*(clave+i)=0;
	return clave+i+1;
}
