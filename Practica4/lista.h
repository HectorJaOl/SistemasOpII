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
    int direccion[25][2];
    struct Nodo* siguiente;
};

struct Nodo* cabeza = NULL;
struct Nodo* actual = NULL;

int direccion[100][2];
int numProcesos=0;

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
	int k=0;
    struct Nodo* nodo = malloc(sizeof(struct Nodo));

    strcpy(nodo->nombreProceso, nombreProceso);
    nodo->numPaginas = numPaginas;
    nodo->numReferencias = numReferencias;
	nodo->refRestantes = numReferencias;
	for(int i=0;i<numReferencias;i++)
	{
		nodo->direccion[i][0]=direccion[k][0];
		nodo->direccion[i][1]=direccion[k][1];
		k++;
	}
	nodo->cuantumRestante = CUANTUM;
    nodo->siguiente = NULL;
	numProcesos++;
	push(nodo);
}

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
    int numPaginas, numPag, desplazamiento, cont;
	
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
		
		direccion[cont][0]=numPag;
		direccion[cont][1]=desplazamiento;
		
		cont++;
		printf("Desea meter otro? [S/n]:    ");
		setbuf(stdin, NULL);
		scanf("%c", &termina);
		if (termina == 78 || termina == 110)
		{
			break;
		}
	} while (1);
	crearNodo(nombreProceso, numPaginas, cont);
}
