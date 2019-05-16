#include <stdio.h>
#include <time.h>  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>//la añadí esta librería para poder hacerlo del cambio de color
#include <Windows.h>//la añadí esta librería para poder hacerlo del cambio de color
#define A 100
#define N 51
#define T 10

typedef struct
{
	char notas[N];
	int dia;
} Tfecha;
//declaro las funciones que voy a usar en el trabajo
//y para poder relacionar los programas con las funciones, en los programas pongo include<1.h>.
void generarCalendario (int dia, int mes, int anio, Tfecha pDias[A]);
void buscadorNota(int dia, int mes, int anio, char prueba[51], Tfecha nDias[A]);
int menu();
void preguntarFecha(int *diasTeclado, int *mes, int *anio);
void convertirAMes(int mes, char pMes[51]);
void Color(int Background, int Text); 
int mostrarNota (Tfecha lDias[A], int dias);
int existeDiaCalendario(int i, Tfecha eDias[A]);
void generadorSemana (int i, int semana);
