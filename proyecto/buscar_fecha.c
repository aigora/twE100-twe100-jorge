#include "1.h"


//funciones del programa (buscar y presentar una nota)

void buscadorNota(int dia, int mes, int anio, char prueba[N], Tfecha nDias[A])
{
	FILE *p_archivo;
	char anno[N], fecha[N], listo[2], m[N], pDias[N], notas[N], guion[N];
	int encontrado = 0, dias, cont = 0, cDias, i, a = 0, b, existe = 0;
	
	printf("\n");
	sprintf(anno, "%d", anio);
	for (a = 0; a < N; a++){
		nDias[a].dia = 0;
		memset(nDias[a].notas, 0, sizeof(N));		
	}
	memset(pDias, 0, sizeof(N));	
	p_archivo = fopen ("Calendario.txt", "r");
	cont = 0;
	i = 0;
	strcat(prueba, anno);
	//bucle para buscar si esta el mes que estas buscando, si no lo encuentra te presenta el mes, pero te dice que no existe nada para lo que pedistes
	while(cont != 2 && cont != 3){
		fgets(fecha, N, p_archivo);
		fecha[strcspn(fecha, "\n")] = 0;
		if(strcmp(fecha, prueba)== 0){cont = 2;}
		if(strcmp(fecha, ".end")== 0){cont = 3;}
	}
	//sirve para que no se pase de sección cuando pides un día, es decir, para que no te ponga una nota del mes siguiente
	while (strcmp(pDias,";") != 0 && cont !=3){
		dias = 0;
		encontrado = 0;
		fscanf (p_archivo, "%s", &pDias);
		sscanf(pDias, "%d", &dias );
		while (encontrado != 1){//sirve para que te lea lo de después del guión
			fscanf (p_archivo, "%s", &guion);
			if(strcmp(guion,"-") == 0 || strcmp(guion,".end") == 0){encontrado = 1;}		
		}
		fgets(notas, sizeof(notas), p_archivo);
		if (strcmp(pDias,";") != 0){
			nDias[i].dia = dias;
			strncpy(nDias[i].notas, notas, N);
			i++;
		}
	}
	fclose (p_archivo);
}
//esta función hace que a la hora de que se haya pedido un mes en generarCalendario, como manda un número, aquí pasa lo que sería el mes para que la función de buscadorNota funcione como es debido
void convertirAMes(int mes, char pMes[N]){
	memset(pMes, '\0', sizeof(pMes));
	switch (mes){
		case 0:
			strcpy (pMes, "Enero ");
			break;
		case 1:
			strcpy (pMes, "Febrero ");
			break;
		case 2:
			strcpy (pMes, "Marzo ");
			break;
		case 3:
			strcpy (pMes, "Abril ");
			break;
		case 4:
			strcpy (pMes, "Mayo ");
			break;
		case 5:
			strcpy (pMes, "Junio ");
			break;
		case 6:
			strcpy (pMes, "Julio ");
			break;
		case 7:
			strcpy (pMes, "Agosto ");
			break;
		case 8:
			strcpy (pMes, "Septiembre ");
			break;
		case 9:
			strcpy (pMes, "Octubre ");
			break;
		case 10:
			strcpy (pMes, "Noviembre ");
			break;
		case 11:
			strcpy (pMes, "Diciembre ");
			break;
	}
}
//función que se encarga de presentar las notas
int mostrarNota (Tfecha lDias[A], int dias){
	//declaro las variables
	int i = 0;
	int existe = 0;
	//esta parte sirve para que lea las notas relacionadas al mismo día
		for (i = 0; i < A; i++){
			if (lDias[i].dia == dias){
				printf("\nD\241a: %d", lDias[i].dia);
				printf("\nLa nota es: %s", lDias[i].notas);
				existe = 1;
			}
			else if (lDias[i].dia > dias || lDias[i].dia == 0) {
				i = A;
			}
		}
		return existe;
}
