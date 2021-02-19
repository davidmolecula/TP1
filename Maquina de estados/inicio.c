#include "C:\Users\user\Documents\Cursadas\Info II\2020\Maquina de estados\header.txt"

/* Puntero a funciones que carga en "clave" a la palabra clave y en "val" a la posicion de memoria siguiente, como val es un puntero este termina apuntando a la
variable siguiente */
char *obtenerclave(char *clave);



datos_t inicio() {
	
	FILE *config;
	char cadena[50], *clave, *val;
	char variables[4][30]={"cables","tension_limite","tension","avisos"}, i;
	datos_t configuracion;
 	if(!(config=fopen("Config.conf","rb"))){
 		printf("\nNo se encontro el archivo\n");
 	
	 }
	 fgets(cadena,50,config);
	 do{
	 	clave=cadena;
	 	if(*(clave) != '/' && strlen(clave)>0){
	 		val=obtenerclave(clave);
	 		for(i=0;i<3;i++)
	 		{
	 			if(!strcmp(clave, variables[i])){
	 				switch(i)
	 				{
	 					case 0: configuracion.cables=atoi(val);
	 							break;
	 					case 1: configuracion.tension_limite=atoi(val);
	 							break;
	 					case 2: configuracion.tension=atoi(val);
	 							break;
	 					case 3: strcpy(configuracion.avisos,val);
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
