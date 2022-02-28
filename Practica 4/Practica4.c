#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int matriz[2][25];
typedef struct Nodo{
  char nombreProceso[10];
  int numPaginas;
  int desplazamiento[25][2];
  int numReferencias;
  struct Nodo *sig;
} Nodo;

Nodo *crearNodo(char *nombreProceso, int numPaginas, int referencias, int nReferencias[referencias][2]){

  Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));

  strcpy(nodo->nombreProceso, nombreProceso);
  nodo->numPaginas = numPaginas;

  // Agregar/Llenar la matriz
  nodo->desplazamiento = nReferencias[referencias][2];

  nodo->numPaginas = referencias;

  nodo->sig = NULL;
  return nodo;
}

int menu(){
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

  opcion = menu();
  switch (opcion){
  case 1:
    printf("Nombre del proceso: \n");

    setbuf(stdin, NULL);
    scanf("%s", nombreProceso);

    do{
      printf("Numero de Paginas: \n");
      scanf("%d", &numPaginas);
    } while (numPaginas < 1);

    cont = 0;
    do{
      do{
        printf("Numero Pagina: ");
        scanf("%d", &numPag);

        if (numPag > numPaginas){
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
      if (termina == 78 || termina == 110){
        break;
      }
    } while (1);
    break;
  case 2:
    break;
  }

  for (int i = 0; i < cont; i++){
    printf("[%d][%d]--", matriz[i][0], matriz[i][1]);
  }

  return 0;
}