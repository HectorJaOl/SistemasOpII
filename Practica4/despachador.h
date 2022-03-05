#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lista.h"

//Declaracion de funciones
void imprimirDatosProceso (struct Nodo* proceso);
void convertir(int decimal, int mem, int base);
void convertirDes(int decimal, int base);
int convMem(int decimal, int base);

void despacha() {

	int time0 = time(NULL);

	int numProcesos=cantProcesos();

	struct Nodo* proceso = NULL;
	struct Nodo* ultimo = NULL;
	
	srand(time(NULL));

	while (numProcesos > 0)
	{
		
		ultimo = proceso;
		proceso = pop ();

		if (ultimo != proceso && ultimo !=NULL)
		{
			printf ("\n*** CAMBIO DE CONTEXTO ***\n");
			sleep (1);
		}

		//aqui es donde se simula que esta en ejecucion el proceso
		proceso->cuantumRestante--;
		printf ("\nAhora ejecutando el proceso: %s\n", proceso->nombreProceso);
		
		//DirVir
		//Base 10
		printf ("Pagina | Desplazamiento: \n[%d|%d]\n", proceso->direccionV[proceso->numReferencias-proceso->refRestantes][0], proceso->direccionV[proceso->numReferencias-proceso->refRestantes][1]);
		//Base 2
		printf ("\nDireccion Virtual Base 2:\n");
		convertir(proceso->direccionV[proceso->numReferencias-proceso->refRestantes][0], pagMV, 2);
		convertirDes(proceso->direccionV[proceso->numReferencias-proceso->refRestantes][1], 2);
		//Base 16
		printf ("\n\nDireccion Virtual Base 16:\n");
		convertir(proceso->direccionV[proceso->numReferencias-proceso->refRestantes][0], pagMV, 16);
		convertirDes(proceso->direccionV[proceso->numReferencias-proceso->refRestantes][1], 16);
		
		//DirFis
		//Base 10
		printf ("\n\nMarco | Desplazamiento: \n[%d|%d]\n", proceso->direccionF[proceso->numReferencias-proceso->refRestantes][0], proceso->direccionF[proceso->numReferencias-proceso->refRestantes][1]);
		//Base 2
		printf ("\nDireccion Fisica Base 2:\n");
		convertir(proceso->direccionF[proceso->numReferencias-proceso->refRestantes][0], pagMF, 2);
		convertirDes(proceso->direccionF[proceso->numReferencias-proceso->refRestantes][1], 2);
		//Base 16
		printf ("\n\nDireccion Fisica Base 16:\n");
		convertir(proceso->direccionF[proceso->numReferencias-proceso->refRestantes][0], pagMF, 16);
		convertirDes(proceso->direccionF[proceso->numReferencias-proceso->refRestantes][1], 16);
		
		proceso->refRestantes--;
		printf ("\n\nNumero de Referencias: %d\n", proceso->numReferencias);
		printf ("Referencias restantes: %d\n", proceso->refRestantes);	
		sleep (1);
		
		if (proceso->refRestantes == 0)
		{
			eliminaPrimero ();
			numProcesos--;
			printf ("\nPROCESO TERMINADO.\n");
			imprimirDatosProceso (proceso);
			free (proceso);
		}
		else if (proceso->cuantumRestante == 0)
		{
			proceso->cuantumRestante = CUANTUM;
			eliminaPrimero ();
			pushLast (proceso);
		}
	}
	liberaEspacio ();
}

void imprimirDatosProceso (struct Nodo* proceso)
{
	printf ("Nombre: %s\n", proceso->nombreProceso);
	printf ("Numero de Paginas: %d\n", proceso->numPaginas);
	printf ("Numero de Referencias: %d\n", proceso->numReferencias);
}

//Convierte las paginas y marcos a base 2 y 16 
//Y agrega los 0's necesarios para llenar la 
//Cantidad de bits que usan las direcciones
void convertir(int decimal, int mem, int base)
{
	int cociente,residuo,cont, i,j;
    int conv [50];
    i=0;
    do{
        cociente = decimal/base;
        residuo = decimal%base;
        conv[i] = residuo;
        decimal = cociente;
        i+=1;
    }while (cociente>0);

	for (int j=1; j<convMem(mem, base)-i; j++)
	{
		printf("0");
	}

    for (cont=i-1; cont>=0; cont--)
    {
        printf("%x", conv [cont]);
    }
    printf(" ");
}

//Convierte el desplazamiento por separado
//Porque aqui no hacen falta 0's
void convertirDes(int decimal, int base)
{
	int cociente,residuo,cont, i,j;
    int conv [50];
    i=0;
    do{
        cociente = decimal/base;
        residuo = decimal%base;
        conv[i] = residuo;
        decimal = cociente;
        i+=1;
    }while (cociente>0);

    for (cont=i-1; cont>=0; cont--)
    {
        printf("%x", conv [cont]);
    }
    printf(" ");
}

//Convierte la cantidad de paginas de las 
//Memorias a binario para sacar la cantidad
//De bits necesarios
int convMem(int decimal, int base)
{
	int cont=0, cociente,residuo, i,j;
    int conv [50];
    i=0;
    do{
        cociente = decimal/base;
        residuo = decimal%base;
        conv[i] = residuo;
        decimal = cociente;
        i+=1;
		cont++;
    }while (cociente>0);
	
	return cont;
}
