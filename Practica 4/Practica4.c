#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int matriz[2][25];
typedef struct Nodo
{
  char nombreProceso[10];
  int numPaginas;
  int desplazamiento[2][25];
  struct Nodo *siguiente;
} Nodo;

Nodo *cabeza = NULL;

Nodo *crearNodo(char *nombreProceso, int numPaginas)
{

  Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));

  strcpy(nodo->nombreProceso, nombreProceso);
  nodo->numPaginas = numPaginas;

  // Agregar/Llenar la matriz
  /*for(int i=0; i<25; i++){
    matriz[0][i] = desplazamiento[0][i];
    matriz[0][i] = desplazamiento[0][i];
  }*/

  nodo->siguiente = NULL;
  return nodo;
}

void insertarNodo(char *nombreProceso, int numPaginas)
{
  Nodo *nodo = crearNodo(nombreProceso, numPaginas);
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

  while (aux != NULL)
  {
    printf("[%s | %d]->", aux->nombreProceso, aux->numPaginas);
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

int main(int argc, char const *argv[])
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
      do{
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
      }while(1);
      insertarNodo(nombreProceso, numPaginas);
      break;
    case 2:
      break;
    case 3:
      mostrarLista();
      break;
    }
  } while (opcion != 3);

  return 0;
}
