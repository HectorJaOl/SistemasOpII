#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lista.h"

void imprimirDatosProceso (struct Nodo* proceso);

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
		printf ("Pagina | Desplazamienta: [%d|%d]\n", proceso->direccion[proceso->numReferencias-proceso->refRestantes][0], proceso->direccion[proceso->numReferencias-proceso->refRestantes][1]);
		proceso->refRestantes--;
		printf ("Numero de Referencias: %d\n", proceso->numReferencias);
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