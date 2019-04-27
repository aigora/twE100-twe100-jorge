#include <stdio.h>
#include <time.h> 
#include <string.h>
#define T 10
#define N 51
int main()
{
	FILE *p_archivo;
	char mesP [T], anno [N], prueba [N] = "Febrero ", fecha[N], basura [N], notas [N];
	int encontrado = 0, dias, diasTeclado;
	//p_archivo = fopen ("Base3.txt", "r");	
	int i,j,k,m,l,cont;				
	int dia, mes, anio, semana, moduloMes, febrero, total_mes;
	int seleccion=1;					
	i=j=k=m=l=cont=0; 				
	
	time_t sisTime; 
	struct tm *tiempo;
	
	time(&sisTime);		
	tiempo=localtime(&sisTime);
	
	
	dia=tiempo->tm_mday;		//accedo al valor de dia de la estructura tm y se la asigno a dia
	mes=tiempo->tm_mon;		//accedo a mes de la estrutura tm y se la asigno a mes
	anno [N] = (tiempo->tm_year)+1900;	//year es un contador a partir de 1900.
	anio = (tiempo->tm_year)+1900;
	
	system ("cls");
	
	printf("\t=============================>CALENDARIO<=============================\n\n");
	printf("Hoy es: %d/%d/%d \n\n\n", dia, mes+1, anio);
	while(seleccion != 0)
	{
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
					if(i==8-semana||i==15-semana||i==22-semana||i==29-semana || i== 36-semana)
						printf("\n%d\t",i);
					else	
						printf("%d\t",i);
				}
		printf("\n\nDesea Buscar otra Fecha? \n\t1=SI 0=NO\t>>> ");
		scanf("%d",&seleccion);
		
		while (seleccion<0 || seleccion>1)
		{
			printf("\nLo siento, tienes que poner ó 1 ó 0\n");
			printf("Desea Buscar otra Fecha? \n\t1=SI 0=NO\t>>> ");
			scanf("%d",&seleccion);
		}
		
		if (seleccion == 1)
		{
			printf("\nIngrese Mes: ");
			scanf ("%s", &mesP);
			fflush (stdin);
			
			//Ponemos if porque ponerlo en un switch sería más complicado de lo que sería necesario 
			if (strcmp(mesP,"enero")==0 || strcmp(mesP,"1")==0 || strcmp(mesP,"Enero")==0) mes = 0;
			if (strcmp(mesP,"febrero")==0 || strcmp(mesP,"2")==0 || strcmp(mesP,"Febrero")==0) mes = 1;
			if (strcmp(mesP,"marzo")==0 || strcmp(mesP,"3")==0 || strcmp(mesP,"Marzo")==0) mes = 2;
			if (strcmp(mesP,"abril")==0 || strcmp(mesP,"4")==0 || strcmp(mesP,"Abril")==0) mes = 3;
			if (strcmp(mesP,"mayo")==0 || strcmp(mesP,"5")==0 || strcmp(mesP,"Mayo")==0) mes = 4;
			if (strcmp(mesP,"junio")==0 || strcmp(mesP,"6")==0 || strcmp(mesP,"Junio")==0) mes = 5;
			if (strcmp(mesP,"julio")==0 || strcmp(mesP,"7")==0 || strcmp(mesP,"Julio")==0) mes = 6;
			if (strcmp(mesP,"agosto")==0 || strcmp(mesP,"8")==0 || strcmp(mesP,"Agosto")==0) mes = 7;
			if (strcmp(mesP,"septiembre")==0 || strcmp(mesP,"9")==0 || strcmp(mesP,"Septiembre")==0) mes = 8;
			if (strcmp(mesP,"octubre")==0 || strcmp(mesP,"10")==0 || strcmp(mesP,"Octubre")==0) mes = 9;
			if (strcmp(mesP,"noviembre")==0 || strcmp(mesP,"11")==0 || strcmp(mesP,"Noviembre")==0) mes = 10;
			if (strcmp(mesP,"diciembre")==0 || strcmp(mesP,"12")==0 || strcmp(mesP,"Diciembre")==0) mes = 11;
			
			printf ("Ingrese Anio: ");
			scanf("%d",&anio); 
			
			system("cls");
			printf("\t=============================>CALENDARIO<=============================\n\n");
			
		}
	}

}

