#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int matriz[25][2]; //[x,x],[x,x],,[x,x],[x,x],[x,x],[x,x],[x,x],[x,x],[x,x],[x,x],[x,x],[x,x],[x,x],[x,x],[x,x],[x,x]

typedef struct Nodo
{
    char nombreProceso[10];
    int numPaginas;
    int numReferencias;
    int desplazamiento[25][2];
    struct Nodo *siguiente;
} Nodo;

Nodo *cabeza = NULL;

Nodo *crearNodo(char *nombreProceso, int numPaginas, int referencias)
{
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));

    strcpy(nodo->nombreProceso, nombreProceso);
    nodo->numPaginas = numPaginas;

    nodo->numReferencias = referencias;

    // Agregar/Llenar la matriz
    for (int i = 0; i < 25; i++)
    {
        nodo->desplazamiento[i][0] = matriz[i][0];
        nodo->desplazamiento[i][1] = matriz[i][1];
    }

    nodo->siguiente = NULL;
    return nodo;
}

void insertarNodo(char *nombreProceso, int numPaginas, int referencias)
{
    Nodo *nodo = crearNodo(nombreProceso, numPaginas, referencias);
    if (cabeza == NULL)
        cabeza = nodo;
    else
    {
        Nodo *puntero = cabeza;

        while (puntero->siguiente)
            puntero = puntero->siguiente;

        puntero->siguiente = nodo;
    }
}

void mostrarLista()
{
    printf("Nombre | Paginas\n\n");

    Nodo *aux = cabeza;

    while (aux != NULL){
        printf("[%s | %d | %d]--", aux->nombreProceso, aux->numPaginas, aux->numReferencias);
        for (int i = 0; i < aux->numReferencias; i++){
            printf("[%d/%d]",aux->desplazamiento[i][0],aux->desplazamiento[i][1]);
        }
        printf("->");
        aux = aux->siguiente;
    }
    printf("\n\n");
}

int menu()
{
    int op;
    printf("\n----MENU----\n");
    printf("1. Proceso nuevo\n");
    printf("2. Despachar proceso\n");
    printf("3. Salir\n");
    printf("Opcion: ");
    scanf("%d", &op);

    return op;
}

int main()
{
    int opcion, cont;
    char nombreProceso[100], termina;
    int numPaginas, numPag, desplazamiento;
    int tamPagina, tamMemoriaVirtual, tamMemoriaFisica;

    // Nodo procesos;

    printf("Tamano de Pagina en bytes: ");
    scanf("%d", &tamPagina);

    printf("Tamano Memoria Virtual en bytes: ");
    scanf("%d", &tamMemoriaVirtual);

    printf("Tamano Memoria Fisica en bytes: ");
    scanf("%d", &tamMemoriaFisica);

    opcion = menu();
    switch (opcion)
    {
    case 1:
        printf("Nombre del proceso: \n");

        setbuf(stdin, NULL);
        scanf("%s", nombreProceso);

        do
        {
            printf("Numero de Paginas: \n");
            scanf("%d", &numPaginas);
        } while (numPaginas < 1);

        cont = 0;
        do
        {
            do
            {
                printf("Numero Pagina: ");
                scanf("%d", &numPag);

                if (numPag > numPaginas)
                {
                    printf("\nPagina no disponible\n");
                }

            } while (numPag > numPaginas);

            printf("Desaplazamiento: ");
            scanf("%d", &desplazamiento);

            // agregarMatriz(numPag,desplazamiento);
            matriz[cont][0] = numPag;
            matriz[cont][1] = desplazamiento;

            cont++;
            printf("Desea meter otro? [S/n]:    ");
            setbuf(stdin, NULL);
            scanf("%c", &termina);
            if (termina == 78 || termina == 110)
            {
                break;
            }
        } while (1);
        break;
    case 2:
        break;
    }

    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 1:
            printf("Nombre del proceso: \n");

            setbuf(stdin, NULL);
            scanf("%s", nombreProceso);

            do
            {
                printf("Numero de Paginas: \n");
                scanf("%d", &numPaginas);
            } while (numPaginas < 1);

            cont = 0;
            do
            {
                do
                {
                    printf("Numero Pagina: ");
                    scanf("%d", &numPag);

                    if (numPag > numPaginas)
                    {
                        printf("\nPagina no disponible\n");
                    }

                } while (numPag > numPaginas);

                printf("Desplazamiento: ");
                scanf("%d", &desplazamiento);

                // agregarMatriz(numPag,desplazamiento);
                matriz[0][cont] = numPag;
                matriz[1][cont] = desplazamiento;

                cont++;
                printf("Desea meter otro? [S/n]:    ");
                setbuf(stdin, NULL);
                scanf("%c", &termina);
                if (termina == 78 || termina == 110)
                {
                    break;
                }
            } while (1);
            insertarNodo(nombreProceso, numPaginas, cont);
            break;
        case 2:
            break;
        case 3:
            mostrarLista();
            break;
        }
    } while (opcion != 3);

    
    
    /*for (int i = 0; i < cont; i++)
    {
        printf("[%d][%d]--", matriz[i][0], matriz[i][1]);
    }*/

    return 0;
}