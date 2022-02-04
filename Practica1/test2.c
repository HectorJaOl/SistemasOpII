/*EQUIPO 6

INTEGRANTES:

201907066 Cilia Romero Jimena Paola
201917480 Flores Santos Alejandra
201938593 Javier Olivares Hector
201918749 Ramirez Xochipa David Uriel

*/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct Nodo{
  string nombre;
  int inicio;
  int fila;
  int tam;
  struct Nodo *sig;
};

Nodo *cabeza = NULL;
Nodo *final = NULL;

int tam_memoria = 1024;
unsigned int mapa[32];
int fila = 0, j=0;



int menu(){
  int op;
  cout << "---MENU---" << endl;
  cout << "1.Agregar proceso"<< endl;
  cout << "2.Eliminar proceso" << endl;
  cout << "3.Salir" << endl;
  cin >> op;
  return op;
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

void insertarProceso(int longitud){
  int potencia;
  for (int i = 0; i < longitud; i++){
    potencia=pow(2,j);
    mapa[fila]+=potencia;
    j++;
    if(j>=32){
      fila++;
      j=0;
    }
  }
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
  int k, potencia, f;
  Nodo *ant = new Nodo();
  ant = cabeza;
  if(!estaVacia()){
    if(cabeza == final && nom == cabeza->nombre){ //unico nodo
      cout <<"i: "<< cabeza->inicio << "f: " << cabeza->fila <<endl;
      cabeza = final = NULL;
      delete ant;
      vaciarMapaBits();
      j = 0;
      fila = 0;
    }else if(nom == cabeza->nombre){ //elemento del inicio
      k=cabeza->inicio;
      f=cabeza->fila;
      for (int i = 0; i < cabeza->tam; i++){
        potencia=pow(2,k);
        mapa[f]-=potencia;
        k++;
        if(k>=32){
          f++;
          k=0;
        }
      }

      cabeza = cabeza->sig;
      delete ant;
    }else{ //mas elementos
      Nodo *tmp = new Nodo();
      tmp = cabeza->sig;

      while(tmp != NULL && tmp->nombre != nom){
        ant = ant->sig;
        tmp = tmp->sig;
      }
      if(tmp != NULL){
    
        k=tmp->inicio;
        f=tmp->fila;
        for (int i = 0; i < tmp->tam; i++){
          potencia=pow(2,k);
          mapa[f]-=potencia;
          k++;
          if(k>=32){
            f++;
            k=0;
          }
        }
        ant->sig = tmp->sig;
        
        if(tmp == final){
          final = ant;
        }
        delete tmp;
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


int main(int argc, char const *argv[]) {
  string nom;
  int longitud, op;
  unsigned int value;
  int i, bits=0, auxbits, contador=0;
  unsigned int potencia=0;
  vaciarMapaBits();

  do{
    op = menu();

    switch (op) {
      case 1:
        cout << "\nDame el nombre: " << '\n';
        cin >> nom;
        cout << "\nDame la longitud (EN BYTES): "<<'\n';
        cin >> longitud;

        longitud = longitud / 1024;
        cout << "\nLongitud en kb: " << longitud << endl;
        
        if(longitud <= tam_memoria){
          tam_memoria -= longitud;

          insertarNodo(nom,j,fila,longitud);

          insertarProceso(longitud);
                    
          for (int i = 0; i < 32; i++) {
            imprimirMapaBits(mapa[i]);
            cout<<"\n";
          }
        }else if(tam_memoria == 0){
          cout << "\nMemoria llena\n" << endl;
        }else{
          cout << "\nProceso demasiado grande\n" << endl;
        }
      break;
      case 2:
        mostrarLista();
        cout<< "Escriba el nombre del proceso a eliminar: ";
        cin>>nom;
        eliminarNodo(nom);
        for (int i = 0; i < 32; i++) {
          imprimirMapaBits(mapa[i]);
          cout<<"\n";
        }
      break;
      case 3:
        cout << "\nAdios\n" <<endl;
      break;
      default:
        cout << "Opcion incorrecta" << endl;
      break;
    }

  }while(op != 3);
  return 0;
} 