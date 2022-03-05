/**
 * PRACTICA 4: ADministracion de memoria virtual. Paginacion
 * 
 * INTEGRANTES:
 * Jimena Paola CIlia Romero		201907066
 * David Uriel Ramirez Xochipa		201918749
 * Hector Javier Olivares			201938593
 * Alejandra Flores Santos			201917480
*/


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
    int opc;
    
	memorias();
	
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


