#include <iostream>
#include <string>
#include <math.h>
using namespace std;
struct Nodo
{
  string nombre;
  //int inicio;
  int tam;
  struct Nodo *sig;
};

unsigned int mapa[32] = {0};
Nodo *cabeza = NULL;
Nodo *final = NULL;

int inicio = 0;
int tam_memoria = 1024;

int menu()
{
  int op;
  cout << "---MENU---" << endl;
  cout << "1.Agregar proceso" << endl;
  cout << "2.Eliminar proceso" << endl;
  cout << "3.Salir" << endl;
  cin >> op;
  return op;
}
bool estaVacia()
{
  return cabeza == NULL;
}
void insertarNodo(string nom, int longitud)
{
  Nodo *nuevo = new Nodo();
  nuevo->nombre = nom;
  nuevo->tam = longitud;
  if (!estaVacia())
  {
    final->sig = nuevo;
    final = final->sig;
  }
  else
  {
    cabeza = final = nuevo;
  }
}

void eliminarNodo(string nom)
{
  if (!estaVacia())
  {
    if (cabeza == final && nom == cabeza->nombre)
    {
      cabeza = final = NULL;
    }
    else if (nom == cabeza->nombre)
    {
      cabeza = cabeza->sig;
    }
    else
    {
      Nodo *ant = new Nodo();
      Nodo *tmp = new Nodo();
      ant = cabeza;
      tmp = cabeza->sig;

      while (tmp != NULL && tmp->nombre != nom)
      {
        ant = ant->sig;
        tmp = tmp->sig;
      }
      if (tmp != NULL)
      {
        ant->sig = tmp->sig;
        if (tmp == final)
        {
          final = ant;
        }
      }
    }
  }
}

void mostrarLista()
{
  Nodo *aux = cabeza;

  while (aux != NULL)
  {
    cout << "[" << aux->nombre << "]->";
    aux = aux->sig;
  }
  cout << '\n';
}
int main(int argc, char const *argv[])
{
  string nom;
  int longitud, op, i = 0,j, k = 0, aux;
  unsigned int value,potencia,suma, suma1 = 0;

  do
  {
    op = menu();

    switch (op)
    {
    case 1:
      cout << "Dame el nombre: " << '\n';
      cin >> nom;
      cout << "Dame la longitud (EN BYTES): " << '\n';
      cin >> longitud;

      longitud = longitud / 1024;
      if (longitud > tam_memoria)
      {
        cout << "Proceso muy grande para la memoria" << endl;
      }
      else
      {
        aux = inicio;
        inicio = inicio + longitud;
        tam_memoria = tam_memoria - longitud;
        suma = 0;
        cout << "Inicio:" <<inicio<<endl;
        cout << "Aux: "<<aux<<endl;
					for(i = aux; i < inicio; i++){
            suma += pow(2,i);
          }
          mapa[k] = mapa[k] + suma;

        insertarNodo(nom, longitud);
        mostrarLista();
        for(i=0;i<32;i++){
					value=mapa[i];
					for(j=0;j<32;j++){
						potencia=pow(2,j);
						if(value & potencia){
						printf("1 ");
						}
						else{
							printf("0 ");
						}
					}
					printf("\n");
			  }
      }

      break;
    case 2:
      mostrarLista();
      cout << "Dame el nombre a eliminar: " << '\n';
      cin >> nom;

      eliminarNodo(nom);
      mostrarLista();
      break;
    case 3:
      cout << "Görüşürüz!" << endl;
      break;
    default:
      cout << "Opcion incorrecta" << endl;
      break;
    }

  } while (op != 3);
  return 0;
}
