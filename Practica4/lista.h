#include <stdlib.h>
#include <time.h>

#define CUANTUM 3

struct Nodo
{
    char nombreProceso[10];
    int numPaginas;
    int numReferencias;
	int refRestantes;
	int cuantumRestante;
    int direccionV[25][2];
	int direccionF[25][2];
    struct Nodo* siguiente;
};

struct Nodo* cabeza = NULL;
struct Nodo* actual = NULL;

int numProcesos=0;
int cont2=0;
int pagMF=0, pagMV=0, k=0;
int memoriaVirtual[100][2];
int memoriaFisica[100][2];
int tamPagina, tamMemoriaVirtual, tamMemoriaFisica;

/**
 * Funcion que recibe un nodo el cual lo ordena dentro de
 * la lista ligada sugun la cantidad de referencias.
 */
void push(struct Nodo* proceso)
{
    if (cabeza == NULL)
    {
        cabeza = proceso;
        proceso->siguiente = cabeza;
    }
    else if (proceso->numReferencias < cabeza->numReferencias)
    {
        if (cabeza->siguiente = cabeza)
        {
            actual = cabeza;
            proceso->siguiente = cabeza;
            cabeza = proceso;
            actual->siguiente = cabeza;
        }
        else
        {
            actual = cabeza;
            while(actual->siguiente != cabeza)
            {
                actual = actual->siguiente;
            }
            proceso->siguiente = cabeza;
            cabeza = proceso;
            actual->siguiente=cabeza;
        }
    }
    else
    {
        struct Nodo* actual = cabeza;

        while (proceso->numReferencias > actual->numReferencias && actual->siguiente != cabeza)
        {
            actual = actual->siguiente;
        }
        
        proceso->siguiente = actual->siguiente;
        actual->siguiente = proceso;
    }
}

void pushLast (struct Nodo* proceso) {
    actual = cabeza;

    if (cabeza == NULL)
    {
        cabeza = proceso;
    }
    else
    {
        while (actual->siguiente != cabeza)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = proceso;
        proceso->siguiente = cabeza;
    }
}

/**
 * Funcion que crea un nuevo nodo y lo retorna
 * en donde los tres primeros atributos se igualan a los 
 * valores pasados por parametro.
 * 
 * Parametros:
 * char *nombreProceso, int numPaginas, int numReferencias
 */
void crearNodo(char *nombreProceso, int numPaginas, int numReferencias)
{
    struct Nodo* nodo = malloc(sizeof(struct Nodo));

    strcpy(nodo->nombreProceso, nombreProceso);
    nodo->numPaginas = numPaginas;
    nodo->numReferencias = numReferencias;
	nodo->refRestantes = numReferencias;
	for(int i=0;i<numReferencias;i++)
	{
		nodo->direccionV[i][0]=memoriaVirtual[k][0];
		nodo->direccionV[i][1]=memoriaVirtual[k][1];
		nodo->direccionF[i][0]=memoriaFisica[k][0];
		nodo->direccionF[i][1]=memoriaFisica[k][1];
		k++;
	}
	nodo->cuantumRestante = CUANTUM;
    nodo->siguiente = NULL;
	numProcesos++;
	push(nodo);
}

void memorias()
{
	printf("Tamano de Pagina en kilobytes: ");
    scanf("%d", &tamPagina);

    printf("Tamano Memoria Virtual en kilobytes: ");
    scanf("%d", &tamMemoriaVirtual);

    printf("Tamano Memoria Fisica en kilobytes: ");
    scanf("%d", &tamMemoriaFisica);
	
	pagMV = tamMemoriaVirtual/tamPagina;
	pagMF = tamMemoriaFisica/tamPagina;

}

// Devuelve la cantidad de procesos para que asi el 
// despachador sepa cuantos hay
int cantProcesos()
{
	return numProcesos;
}


/**
 * Funcion que devuelve el nodo raiz que es el que
 * contiene el menor valor numerico en su campo "numReferencias"
 * no recibe parametros.
 */
struct Nodo* pop()
{
	return cabeza;
}

/**
 * Funcion que elimina el primer elemento de la lista,
 * guarda el "link" de la referencia y despues lo retorna.
 * 
**/
struct Nodo* eliminaPrimero()
{
	struct Nodo *temp = cabeza;
	
	if(cabeza->siguiente == cabeza)
	{
		cabeza = NULL;
		return temp;
	}
	
	actual = cabeza;
	while (actual->siguiente != cabeza)
	{
		actual = actual->siguiente;
	}
	actual->siguiente = cabeza->siguiente;
	cabeza = cabeza->siguiente;
	
	return temp;
}

/**
 * Funcion que libera la memoria utilizada por la lista ligada 
 * creada en la ejecucion del programa una vez que este halla 
 * finalizado.
 */
void liberaEspacio()
{
   if (cabeza != NULL)
   {
        struct Nodo *elimina;
        actual = cabeza->siguiente;

        while (actual != cabeza)
        {
            elimina = actual;
            actual = actual->siguiente;
            free (elimina);
        }
        free (cabeza);
    }
}

void crearProceso()
{
	char nombreProceso[100], termina;
    int numPaginas, numPag, desplazamiento, cont1;
	
	printf("Nombre del proceso: \n");
	setbuf(stdin, NULL);
	scanf("%s", nombreProceso);
	
	do
	{
		printf("Numero de Paginas: \n");
		scanf("%d", &numPaginas);
	} while (numPaginas < 1);
	
	cont1 = 0;
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
		
		memoriaVirtual[cont2][0]=numPag;
		memoriaVirtual[cont2][1]=desplazamiento;

		memoriaFisica[cont2][0]=numPag;
		memoriaFisica[cont2][1]=desplazamiento;
		
		cont2++;
		cont1++;
		printf("Desea meter otro? [S/n]:    ");
		setbuf(stdin, NULL);
		scanf("%c", &termina);
		if (termina == 78 || termina == 110)
		{
			break;
		}
	} while (1);
	crearNodo(nombreProceso, numPaginas, cont1);
}

