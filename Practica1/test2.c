//jeje
#include <iostream>
#include <string>
using namespace std;
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
void mostrarLista(){
  Nodo *aux = cabeza;

  while(aux != NULL){
    cout << "[" << aux->nombre << "]->";
    aux = aux->sig;
  }
}
int main(int argc, char const *argv[]) {
  string nom;
  int longitud, op;

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
      break;
      case 3:
        cout << "Görüşürüz!" <<endl;
      break;
      default:
        cout << "Opcion incorrecta" << endl;
      break;
    }

  }while(op != 3);
  return 0;
}
