#include "1.h"


int main()
{
	//declaro las variables
	int seleccion = 1, dia, anio, mes;
	char pMes[51];
	Tfecha mDias[A];
	
	time_t sisTime; //time_t es un typedef, asigno una varible de este tipo (sisTime);
	struct tm *tiempo; //Creo un puntero a la estructura tm, (ya definida en time.h).
	
	time(&sisTime);		//time obtiene el tiempo del sistema y se lo pasa a la direccion de sisTime.
	tiempo=localtime(&sisTime); //Convierte los valores de sisTime a compatibles con la estructura tm y luego asigno ese valor a tiempo.
	
	dia=tiempo->tm_mday;		//accedo al valor de dia de la estructura tm y se la asigno a dia
	mes=tiempo->tm_mon;	        //accedo a mes de la estrutura tm y se la asigno a mes
	anio = (tiempo->tm_year)+1900; //year es un contador a partir de 1900.
	
	//desarrollo del trabajo
	printf("Hoy es: %d/%d/%d \n\n\n", dia, mes+1, anio);
	do {
		preguntarFecha(&dia, &mes, &anio);
		convertirAMes(mes, pMes); 
		buscadorNota(dia ,mes ,anio ,pMes, mDias);
		generarCalendario(dia, mes, anio, mDias); 
		if (mostrarNota (mDias, dia) != 1){
			printf("\n\nNo hay ninguna nota en el d\241a que has pedido");
		}

		seleccion = menu();
	} while ((seleccion != 0));
	//fin del trabajo
}

