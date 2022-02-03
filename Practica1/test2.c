//jeje
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

unsigned int mapa[32];

struct Nodo{
  string nombre;
  //int inicio;
  int tam;
  struct Nodo *sig;
};

Nodo *cabeza = NULL;
Nodo *final = NULL;
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
void insertarNodo(string nom,int longitud){
  Nodo *nuevo = new Nodo();
  nuevo->nombre = nom;
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
  Nodo *aux = cabeza;

  while(aux != NULL){
    cout << "[" << aux->nombre << "]->";
    aux = aux->sig;
  }
  cout << '\n';
}
void vaciarMapaBits(){
  for (int i = 0; i < 32; i++) {
    mapa[i]=0;
  }
}
void imprimirMapaBits(int bits){
    int potencia;
  for (int i = 0; i < 32 ; i++) {

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
  /*
  do{
    op = menu();

    switch (op) {
      case 1:
        cout << "Dame el nombre: " << '\n';
        cin >> nom;
        cout << "Dame la longitud (EN BYTES): "<<'\n';
        cin >> longitud;

        longitud = longitud / 1024;
        cout << "Longitud en kb: " << longitud << endl;
        insertarNodo(nom,longitud);
      break;
      case 2:
        mostrarLista();
        cout << "Dame el nombre a eliminar: " << '\n';
        cin >> nom;

        eliminarNodo(nom);
        mostrarLista();
      break;
      case 3:
        cout << "Görüşürüz!" <<endl;
      break;
      default:
        cout << "Opcion incorrecta" << endl;
      break;
    }

  }while(op != 3);
  */

  unsigned int value;

  int i, bits=0, auxbits, contador;
  unsigned int potencia=0;
  vaciarMapaBits();
  cout<<"Digite un valor: "; cin>>value;
  cout<<"\n";
  //auxbits = calcularBits(value);
  //cout<<"numero de bits: "<<auxbits<<endl;
  cout<<"Hola"<<endl;
  for (int i = 0; i < 32; i++){
    if(i<value){
      potencia=pow(2,i);
      mapa[0]+=potencia;
      cout<<"1 ";
    }else
      cout<<"0 ";

  }
  cout<<"\nmapa---"<<mapa[0]<<endl;
  return 0;
}
