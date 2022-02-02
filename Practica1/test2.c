//jeje
#include <iostream>
#include <string>
using namespace std;
/*struct Nodo{
  String nom;
  //int inicio;
  int tam;
  struct Nodo *sig;
};*/
int menu(){
  int op;
  cout << "---MENU---" << endl;
  cout << "1.Agregar proceso"<< endl;
  cout << "2.Eliminar proceso" << endl;
  cout << "3.Salir" << endl;
  cin >> op;
  return op;
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

        longitud = longitud / 1024; //Longitud en kb

      break;
      case 2:
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
