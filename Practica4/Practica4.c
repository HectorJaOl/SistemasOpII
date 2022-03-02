#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "despachador.h"

int menu()
{
    int opc;
    printf("\n----MENU----\n");
    printf("1. Proceso nuevo\n");
    printf("2. Despachar proceso\n");
    printf("3. Salir\n");
    printf("Opcion: ");
    scanf("%d", &opc);

    return opc;
}

int main()
{
	int tablaPag [100][2];
	int pagMF, pagMV;
    int opc;
    int tamPagina, tamMemoriaVirtual, tamMemoriaFisica;
	
	printf("Tamano de Pagina en kilobytes: ");
    scanf("%d", &tamPagina);

    printf("Tamano Memoria Virtual en kilobytes: ");
    scanf("%d", &tamMemoriaVirtual);

    printf("Tamano Memoria Fisica en kilobytes: ");
    scanf("%d", &tamMemoriaFisica);
	
	pagMV = tamMemoriaVirtual/tamPagina;
	pagMF = tamMemoriaFisica/tamPagina;
	
	do
	{
		opc = menu();
		
		switch(opc)
		{
		case 1:
			crearProceso();
			break;
		case 2:
			despacha();
			break;
		case 3:
			printf ("\nAdios");
			break;
		default:
			printf ("\nIngrese una opcion valida");
			break;
		}
	} while (opc != 3);	
	
	return 0;
}

