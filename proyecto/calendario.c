#include "1.h"

//funciones del programa (para la estructura del mes, preguntar una fecha, repetir el programa y colores del programa)
void generarCalendario(int dia, int mes, int anio, Tfecha pDias[A])
{
	//declaro variables
	int i,j,k,m,l,cont;				
	int semana, moduloMes, febrero, total_mes;				
	i=j=k=m=l=cont=0; 				
	
	system ("cls");// pongo esto para que no se acumulen los distintos meses y las notas que se hayan buscado
	//presenta la fecha que te ha pedido el programa
	printf("\t=============================>CALENDARIO<=============================\n\n");
	printf("Fecha: %d/%d/%d \n\n\n", dia, mes+1, anio);
	//esto es una leyenda de los colores que se utilizan en el programa
		Color(0, 4); printf("\n\tEl rojo indica notas en otros d\241as");
		Color(0, 2); printf("\n\tEl verde infica el d\241a en que est\240s\n\n");
		Color(0, 15);//este sirve para hacer que lo que continue recobre el color normal de la consola
		
		// calcular los años que son bisiestos para el mes de febrero. 
		if ((anio%4==0) && (anio%100!=0) || anio%400==0) {febrero=29;}
		else {febrero=28;}
		
		switch (mes)
		{
		case 3: case 5: case 8: case 10: 
		total_mes=30; 
		break; 
		case 1: 
		total_mes=febrero; 
		break; 
		case 0: case 2: case 4: case 6: case 7: case 9: case 11: 
		total_mes=31; 
		break; 
		}
		
		
		
		switch (mes)
		{
		case 0:printf("\t\tENERO\t%d",anio);break;
		case 1:printf("\t\tFEBRERO\t%d",anio);break;
		case 2:printf("\t\tMARZO\t%d",anio);break;
		case 3:printf("\t\tABRIL\t%d",anio);break;
		case 4:printf("\t\tMAYO\t%d",anio);break;
		case 5:printf("\t\tJUNIO\t%d",anio);break;
		case 6:printf("\t\tJULIO\t%d",anio);break;
		case 7:printf("\t\tAGOSTO\t%d",anio);break;
		case 8:printf("\t\tSEPTIEMBRE\t%d",anio);break;
		case 9:printf("\t\tOCTUBRE\t%d",anio);break;
		case 10:printf("\t\tNOVIEMBRE\t%d",anio);break;
		case 11:printf("\t\tDICIEMBRE\t%d",anio);break;
		}
		
		
		
		if (febrero==29) 
		{
			switch (mes)
			{
				case 0:moduloMes=0;break;
				case 1:moduloMes=3;break;
				case 2:moduloMes=4;break;
				case 3:moduloMes=0;break;
				case 4:moduloMes=2;break;
				case 5:moduloMes=5;break;
				case 6:moduloMes=0;break;
				case 7:moduloMes=3;break;
				case 8:moduloMes=6;break;
				case 9:moduloMes=1;break;
				case 10:moduloMes=4;break;
				case 11:moduloMes=6;break;
			}
		
		}else
		{
			switch (mes)
			{
				case 0:moduloMes=0;break;
				case 1:moduloMes=3;break;
				case 2:moduloMes=3;break;
				case 3:moduloMes=6;break;
				case 4:moduloMes=1;break;
				case 5:moduloMes=4;break;
				case 6:moduloMes=6;break;
				case 7:moduloMes=2;break;
				case 8:moduloMes=5;break;
				case 9:moduloMes=0;break;
				case 10:moduloMes=3;break;
				case 11:moduloMes=5;break;
			}
		}
		
		
		semana=((anio-1)%7+ ((anio-1)/4 -(3*((anio-1)/100+1)/4))%7+moduloMes+1%7)%7;
		
		//Impresion de dias
		printf("\nDo\tLu\tMar\tMier\tJue\tVier\tSab\n");
		
			
				for(m=0;m<semana;m++)
				printf("\t");
		
				for(i=1;i<=total_mes;i++)
				{
					if (i == dia){
						Color(2 , 15);
						generadorSemana (i, semana);
						Color(0, 15);
					}
					else {
					if (i==existeDiaCalendario(i, pDias)){
						Color(4 , 15);
						generadorSemana (i, semana);
						Color(0, 15);
					}
					else generadorSemana (i, semana);
				}
						
				}
}
//función para buscar otra nota
int menu(){
	//declaro variables
		int opcion;
		printf("\n\n\250Desea Buscar otra Fecha? \n\t1=SI 0=NO\t>>> ");
		scanf("%d",&opcion);
		
		while (opcion<0 || opcion>1)
		{
			printf("\nLo siento, tienes que poner o 1 o 0\n");
			printf("\n\250Desea Buscar otra Fecha? \n\t1=SI 0=NO\t>>> ");
			scanf("%d",&opcion);
		}
		return opcion;
}
//función que pide el mes, día y año.
void preguntarFecha(int *diasTeclado, int *mes, int *anio){
	//declaro variables
			char mesP[51];
			//pido los valores de día, mes y año
			printf ("\nIngrese un d\241a: ");
			scanf("%d", diasTeclado); 
			
			printf("\nIngrese Mes: ");
			scanf ("%s", &mesP);
			fflush (stdin);
			//Ponemos if porque ponerlo en un switch sería más complicado de lo que sería necesario 
			if (strcmp(mesP, "enero")==0 || strcmp(mesP, "1")==0 || strcmp( mesP,"Enero")==0) *mes = 0;
			if (strcmp(mesP,"febrero")==0 || strcmp( mesP,"2")==0 || strcmp( mesP,"Febrero")==0) *mes = 1;
			if (strcmp(mesP,"marzo")==0 || strcmp( mesP,"3")==0 || strcmp( mesP,"Marzo")==0) *mes = 2;
			if (strcmp(mesP,"abril")==0 || strcmp( mesP,"4")==0 || strcmp( mesP,"Abril")==0) *mes = 3;
			if (strcmp(mesP,"mayo")==0 || strcmp( mesP,"5")==0 || strcmp( mesP,"Mayo")==0) *mes = 4;
			if (strcmp( mesP,"junio")==0 || strcmp( mesP,"6")==0 || strcmp( mesP,"Junio")==0) *mes = 5;
			if (strcmp( mesP,"julio")==0 || strcmp( mesP,"7")==0 || strcmp( mesP,"Julio")==0) *mes = 6;
			if (strcmp( mesP,"agosto")==0 || strcmp( mesP,"8")==0 || strcmp( mesP,"Agosto")==0) *mes = 7;
			if (strcmp( mesP,"septiembre")==0 || strcmp( mesP,"9")==0 || strcmp( mesP,"Septiembre")==0) *mes = 8;
			if (strcmp( mesP,"octubre")==0 || strcmp( mesP,"10")==0 || strcmp( mesP,"Octubre")==0) *mes = 9;
			if (strcmp( mesP,"noviembre")==0 || strcmp( mesP,"11")==0 || strcmp( mesP,"Noviembre")==0) *mes = 10;
			if (strcmp( mesP,"diciembre")==0 || strcmp( mesP,"12")==0 || strcmp( mesP,"Diciembre")==0) *mes = 11;
			printf ("\nIngrese A\244o: ");
			scanf("%d", anio); 
}
void Color(int Background, int Text){ // Función para cambiar el color del fondo y/o pantalla

	 HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); 
	 int    New_Color= Text + (Background * 16); 
	
	 SetConsoleTextAttribute(Console, New_Color); 
}
//función que busca las notas que hay para poder cambiar el color en el calendario del día que corresponde
int existeDiaCalendario(int i, Tfecha eDias[A]){
	//declaro variables
	int a = 0;
	//busca los dás que hay notas
	for (a = 0; a < A; a++){
			if (eDias[a].dia == i){
				return i;
			}
			else if (eDias[a].dia > i || eDias[a].dia == 0) {
				return 0;
			}
		}
}
//esta función sirve para que no se tenga que repetir esta misma estructura las tres veces que aparece, es decir, para hacer que quede más limpio
void generadorSemana (int i, int semana){
	if(i==8-semana||i==15-semana||i==22-semana||i==29-semana || i== 36-semana) printf("\n%d\t",i);
	else	printf("%d\t",i);
}
