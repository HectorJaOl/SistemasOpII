//jeje
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

unsigned int mapa[32];

struct Nodo{
  string nombre;
  int inicio;
  int fila;
  int tam;
  struct Nodo *sig;
};

Nodo *cabeza = NULL;
Nodo *final = NULL;

int posicion_mapa = 0;
int tam_memoria = 1024;


int menu(){
  int op;
  cout << "---MENU---" << endl;
  cout << "1.Agregar proceso"<< endl;
  cout << "2.Eliminar proceso" << endl;
  cout << "3.Salir" << endl;
  cin >> op;
  return op;
}

bool estaVacia(){
  return cabeza == NULL;
}

void insertarNodo(string nom,int inicio,int fila,int longitud){
  Nodo *nuevo = new Nodo();
  nuevo->nombre = nom;
  nuevo->inicio = inicio;
  nuevo->fila = fila;
  nuevo->tam = longitud;
  if(!estaVacia()){
    final->sig = nuevo;
    final = final->sig;
  }else{
    cabeza = final = nuevo;
  }
}

void eliminarNodo(string nom){
  if(!estaVacia()){
    if(cabeza == final && nom == cabeza->nombre){
      cabeza = final = NULL;
    }else if(nom == cabeza->nombre){
      cabeza = cabeza->sig;
    }else{
      Nodo *ant = new Nodo();
      Nodo *tmp = new Nodo();
      ant = cabeza;
      tmp = cabeza->sig;

      while(tmp != NULL && tmp->nombre != nom){
        ant = ant->sig;
        tmp = tmp->sig;
      }
      if(tmp != NULL){
        ant->sig = tmp->sig;
        if(tmp == final){
          final = ant;
        }
      }
    }
  }
}

void mostrarLista(){
  cout << "Nombre | Inicio | Fila | Tamano" << endl;
  Nodo *aux = cabeza;

  while(aux != NULL){
    cout << "[" << aux->nombre << "|"<< aux->inicio << "|" << aux->fila << "|" << aux->tam <<"]->";
    aux = aux->sig;
  }
  cout << '\n';
}

void vaciarMapaBits(){
  for (int i = 0; i < 32; i++) {
    mapa[i]=0;
  }
}

void imprimirMapaBits(int numero){
    int potencia;
    for(int i=0;i<=31;i++){
        potencia=pow(2,i);
        if(numero & potencia){
            printf("1 ");
        }
        else{
            printf("0 ");
        }
    }
}

int calcularBits(int kiloByte){// 14= 0111
  int bits=-1,potencia;
  for(int i=0;i<32;i++){
      potencia=pow(2,i); // 1-2-4-8-16-32-64-128-...-2^32
      if(kiloByte & potencia){
          cout<<"1";
      }else{
          cout<<"0";
      }
      if(kiloByte>=potencia)
        bits++;
  }
  cout<<"\n";
  return bits;
}

int main(int argc, char const *argv[]) {
  string nom;
  int longitud, op;
  unsigned int value;
  int i, bits=0, auxbits, contador=0, j=0, fila=0;
  unsigned int potencia=0;
  vaciarMapaBits();

  do{
    op = menu();

    switch (op) {
      case 1:
        cout << "Dame el nombre: " << '\n';
        cin >> nom;
        cout << "Dame la longitud (EN BYTES): "<<'\n';
        cin >> longitud;

        longitud = longitud / 1024;
        //cout << "Longitud en kb: " << longitud << endl;

        if(longitud <= tam_memoria){
          tam_memoria -= longitud;
          for (i = 0; i < longitud; i++){
            potencia=pow(2,j);
            mapa[fila]+=potencia;
            //cout<<"\nmapa---"<<mapa[0]<<endl;
            j++;
            //cout<<"J: "<<j<<endl;
            if(j>=32){
              fila++;
              j=0;
            }
          }
          insertarNodo(nom,posicion_mapa,j,longitud);
          posicion_mapa += longitud;
          for (int i = 0; i < 32; i++) {
            imprimirMapaBits(mapa[i]);
            cout<<"\n";
          }
        }else{
          cout << "\nMemoria llena\n" << endl;
        }
      break;
      case 2:
        mostrarLista();
      break;
      case 3:
        cout << "Adios" <<endl;
      break;
      default:
        cout << "Opcion incorrecta" << endl;
      break;
    }

  }while(op != 3);
  return 0;
}
