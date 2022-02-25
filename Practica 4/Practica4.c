#include <stdio.h>

struct Nodo
{
  char nombreProceso;
  int numPaginas;
  int desplazamiento[2][25];
  int numReferencias;
  struct Nodo *sig;
};

int menu()
{
  int op;
  printf("\n----MENU----\n");
  printf("1. Proceso nuevo\n");
  printf("2. Despachar proceso\n");
  printf("3. Salir\n");
  printf("Opcion: ");
  scanf("%d\n", &op);

  return op;
}

int main(int argc, char const *argv[])
{
  int opcion;
  char nombreProceso[100], termina;
  int numPaginas, numPag, desplazamiento;
  int tamPagina, tamMemoriaVirtual, tamMemoriaFisica;

  // Nodo procesos;

  printf("Tamano de Pagina: ");
  scanf("%d\n", &tamPagina);

  printf("Tamano Memoria Virtual: ");
  scanf("%d\n", &tamMemoriaVirtual);

  printf("Tamano Memoria Fisica: ");
  scanf("%d\n", &tamMemoriaFisica);

  opcion = menu();
  switch (opcion)
  {
  case 1:
    printf("Nombre del proceso: \n");

    fflush(stdin);
    gets(nombreProceso);

    do
    {
      printf("Numero de Paginas: \n");
      scanf("%d\n", &numPaginas);
    } while (numPaginas < 1);

    do
    {
      printf("Numero Pagina: ");
      scanf("%d\n", &numPag);

      printf("Desaplazamiento: ");
      scanf("%d\n", &desplazamiento);

      printf("Desea meter otro? [S/n]:    ");
      scanf("%c\n", termina);
      if (termina == 'n' && termina == 'N')
      {
        break;
      }
    } while (1);

    break;
  case 2:
    break;
  }

  return 0;
}
