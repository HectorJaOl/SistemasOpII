/*                              Práctica 5
                            Sistema de archivos

Desarrollar un programa en lenguaje C bajo el sistema operativo Linux, que
permita ejemplificar las operaciones de archivos y de directorios.

El programa deberá proporcionar un prompt al usuario que le permita ejecutar los
siguientes comandos:

-> salir Con este comando el programa deberá terminar.

En todos los casos [ruta] indica que se puede acceder a un archivo del
directorio actual o acceder al directorio actual, o el que se encuente en ruta

* INTEGRANTES:
* Jimena Paola CIlia Romero		201907066
* David Uriel Ramirez Xochipa		201918749
* Hector Javier Olivares			201938593
* Alejandra Flores Santos			201917480
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include <errno.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>



int ChecaSiExisteArchivo(const char* filename){
    struct stat buffer;
    int exist = stat(filename,&buffer);
    if(exist == 0)
        return 1;
    else
        return 0;
}

int ChecaDatos(char datos[100]){
  if(strlen(datos) != 0){
    return 1;
  }
  return 0;
}

//Función que permite imprimir los permisos
void imprimirRutaPro (struct stat estru){
 printf( (S_ISDIR(estru.st_mode)) ? "d" : "-" );
 printf( (estru.st_mode & S_IRUSR) ? "r" : "-" );
 printf( (estru.st_mode & S_IWUSR) ? "w" : "-" );
 printf( (estru.st_mode & S_IXUSR) ? "x" : "-" );
 printf( (estru.st_mode & S_IRGRP) ? "r" : "-" );
 printf( (estru.st_mode & S_IWGRP) ? "w" : "-" );
 printf( (estru.st_mode & S_IXGRP) ? "x" : "-" );
 printf( (estru.st_mode & S_IROTH) ? "r" : "-" );
 printf( (estru.st_mode & S_IWOTH) ? "w" : "-" );
 printf( (estru.st_mode & S_IXOTH) ? "x" : "-" );
 printf ( " %ju", estru.st_ino );
 printf ( " %ju", estru.st_nlink );
 printf ( " %u", estru.st_uid );
 printf ( " %u", estru.st_gid );
 printf ( " %ld", estru.st_rdev );
 printf ( " %jd", estru.st_blksize );
 printf ( "%jd", estru.st_blocks );
 printf ( "\n%s", ctime(&estru.st_atime) );
 printf ( "%s", ctime(&estru.st_mtime) );
 printf ( "%s", ctime(&estru.st_ctime) );
}

/*
* CREAR ARCHIVO
* [ruta]/nombrearchivo
* Crea un archivo vacío en el directorio actual o en ruta.
*/
void crearArchivo(char ruta[100]){
  printf("%s\n", ruta);
  //if(ChecaDatos(ruta)){
    FILE *fp;
    fp = fopen ( ruta, "w" );
    if (fp == NULL) {
      printf("El archivo se creo correctamente\n");
    }else if(fp != NULL){
      printf("Ya existe, ups...\nIntenta con otro nombre.\n\n");
    }
    fclose ( fp );
  /*}else{
    printf("Error\n");
  }*/

}

/*
* ESCRIBIR ARCHIVO
* [ruta]/nombrearchivo
* Si el archivo ya esta creado entonces capturar cadenas que serán escritas al
* archivo, el usuario deberá escribir la palabra FIN en la última línea lo que
* permitirá terminar de leer y escribir las cadenas leídas (excepto FIN) en el
* archivo y luego cerrarlo. Si el archivo no existe, entonces crearlo y leer
* cadenas de la misma forma que se mencionó anteriormente.
*/
void escribirArchivo(char ruta[100]){
  FILE *fp;
  char cadena[150];
  system("clear");
  if((fp = fopen(ruta, "a"))  != NULL){
    printf("%s\n", ruta);
    while(1) {
      setbuf(stdin,NULL);
      gets(cadena);
      if(strcmp(cadena,"FIN") == 0){
        break;
      }
      strcat(cadena, "\n");
      fputs(cadena, fp);
    }
    fclose ( fp );
  }else{
    crearArchivo(ruta);

    if((fp = fopen(ruta, "a"))  != NULL){
      printf("%s\n", ruta);
      while(1) {
        setbuf(stdin,NULL);
        gets(cadena);
        if(strcmp(cadena,"FIN") == 0){
          break;
        }
        strcat(cadena, "\n");
        fputs(cadena, fp);
      }
      fclose ( fp );
    }else{
      printf("Ocurrio algo inesperado\n");
    }
  }


}

/*
* BORRAR ARCHIVO
* [ruta]/nombrearchivo
* Permite borrar un archivo.
*/
void borrarArchivo(char ruta[100]){
  if(ChecaSiExisteArchivo(ruta)){//Revisamos si existe el archivo
    if(remove(ruta) == 0) // Eliminamos el archivo
        printf("El archivo fue eliminado satisfactoriamente\n");
    else
        printf("No se pudo eliminar el archivo\n");
  }else{
    printf("El archivo no existe\n");
  }

}

/*
* MOSTRAR ARCHIVO
* [ruta]/nombrearchivo    posición
* Abre archivo y posiciona el apuntador en posición y muestra la información
* a partir de ahí.
*/
void mostrarArchivo(char ruta[100], int posicion){
    int i = 0;
    char c;
    if(ChecaSiExisteArchivo(ruta) && ChecaDatos(ruta)){
      FILE *archivo;
      archivo = fopen(ruta, "r");
      while((c = fgetc(archivo)) != EOF){
          if(i >= posicion){
              printf("%c", c);
          }
          i++;
      }
      fclose(archivo);
    }else{
printf("El archivo no existe\n");
    }
}

/*
* MOSTRAR ARCHIVO
* [ruta]/nombrearchivo
* Muestra el contenido del archivo.
*/
void mostrarArchivoCompleto(char ruta[100]){
  if(ChecaSiExisteArchivo(ruta)){
    FILE* input_file = fopen(ruta, "r");
    if (!input_file)
        exit(EXIT_FAILURE);

    char *contents = NULL;
    size_t len = 0;
    while (getline(&contents, &len, input_file) != -1){
        printf("%s", contents);
    }

    fclose(input_file);
    free(contents);
  }else{
    printf("El archivo no existe\n");
  }
}


/*
* renombrarArchivo
* [ruta]/nombreactual [ruta]/nombrenuevo
* Renombra el archivo
* nombreactual por nombrenuevo.
*/
void  renombrarArchivo(char ruta[100], char nombreNuevo[100]){
  printf("Nombre anterior: %s\n", ruta);
  printf("Nombre nuevo: %s\n", nombreNuevo);

  if(ChecaSiExisteArchivo(ruta)){
    if(rename(ruta,nombreNuevo)==0)// Renombramos el archivo
        printf("El archivo se renombro satisfactoriamente\n");
    else
        printf("No se pudo renombrar el archivo\n");
  }else{
    printf("El archivo no existe\n");
  }
}


/*
* CREAR DIRECTORIO
* [ruta]/nombredirectorio
* Crea un directorio en el directorio actual o en ruta.
*/
void crearDirectorio(char ruta[100], char nombre[100]){
  //const char *name = "Arbitrary Directory";
  const char *name = nombre;

  //DIR *dir = opendir("../");
  DIR *dir = opendir(ruta);
  int dfd = dirfd(dir);
  errno = 0;
  int ret = mkdirat(dfd, name, S_IRWXU);
  if (ret == -1) {
      switch (errno) {
          case EACCES :
              printf("the parent directory does not allow write");
              exit(EXIT_FAILURE);
          case EEXIST:
              printf("pathname already exists");
              exit(EXIT_FAILURE);
          case ENAMETOOLONG:
              printf("pathname is too long");
              exit(EXIT_FAILURE);
          default:
              perror("mkdir");
              exit(EXIT_FAILURE);
      }

  }
  closedir(dir);
}


/*
* mostrarDirectorio
* Muestra el contenido del directorio actual.
*/
void mostrarDirectorio(){
  struct stat estru;
  struct dirent *dt;
  DIR *dire;
  int bytes=0;
  dire=opendir(".");
  //Leer el directorio y recorrerlo
  //La función readdir, lee el directorio completo
  while((dt=readdir(dire)) != NULL){
    //Con la función stat podemos ver el estado de los ficheros
    //En este ejemplo, se muestra los permisos, nombre, y tamaño
    stat(dt->d_name, &estru);
    printf("%-20s %ld bytes\n",dt->d_name,estru.st_size);
    bytes=bytes+estru.st_size;
  }
  bytes=bytes/1024;
  printf("\nTotal en KB: %d",bytes);
  closedir(dire);
}

/*
* mostrarDirectorio
* ruta
* Muestra el contenido del directorio solicitado en ruta.
*/
void mostrarOtroDirectorio(char ruta[100]){
  struct stat estru;
  struct dirent *dt;
  DIR *dire;
  int bytes=0;
  dire=opendir(ruta);
  //Leer el directorio y recorrerlo
  //La función readdir, lee el directorio completo
  while((dt=readdir(dire)) != NULL){
    //Con la función stat podemos ver el estado de los ficheros
    //En este ejemplo, se muestra los permisos, nombre, y tamaño
    stat(dt->d_name, &estru);
    printf("%-20s %ld bytes\n",dt->d_name,estru.st_size);
    bytes=bytes+estru.st_size;
  }
  bytes=bytes/1024;
  printf("\nTotal en KB: %d",bytes);
  closedir(dire);
}

/*
* mostrarDirectorio
* [ruta] -l
* Muestra el contenido del directorio actual o el solicitado en ruta desplegando
* todos los atributos encontrados en la estructura struct stat (que se utiliza
* con la familia de fuciones stat).
*/
void mostrarDirectorioPro(char ruta[100]){
  struct stat estru;
  struct dirent *dt;
  DIR *dire;
  int bytes=0;
  dire=opendir(ruta);
  //Leer el directorio y recorrerlo
  //La función readdir, lee el directorio completo
  while((dt=readdir(dire)) != NULL){
    //Con la función stat podemos ver el estado de los ficheros
    //En este ejemplo, se muestra los permisos, nombre, y tamaño
    stat(dt->d_name, &estru);
    printf("\nName: %-20s %ld bytes\n",dt->d_name,estru.st_size);
    imprimirRutaPro(estru);
    bytes=bytes+estru.st_size;
  }
  bytes=bytes/1024;
  printf("\nTotal en KB: %d",bytes);
  closedir(dire);
}

/*
* borrarDirectorio
* [ruta]/nombredirectorio
* Borra el directorio que se encuentra en el directorio actual o en ruta.
*/
void borrarDirectorio(char ruta[100]){
  char op, op2[2];
  printf("Esta seguro de que desea eliminar? [S/n]");
  op = getchar();
  setbuf(stdin,NULL);
  if(op == 's' || op == 'S'){
    setbuf(stdin,NULL);
      char elim[100] = "rm -r ";
      strcat(elim,ruta);
      system(elim);
      printf("CARPETA ELIMINADA\n");
      return;
  }else if(op == 'n' || op == 'N'){}//else{}

}

/*
* renombrarDirectorio
* [ruta]/nombreactual [ruta]/nombrenuevo
* Renombra el directorio nombreactual por nombrenuevo.
*/
void renombrarDirectorio(char ruta[100], char nombre[100], char nombre2[100]){
  char aux[100] = "";
  strcpy(aux, ruta);
  strcat(ruta,nombre);
  strcat(aux,nombre2);
  printf("%s\n", ruta);
  printf("%s\n", aux);
  if (rename(ruta, aux) == -1){
    printf("Intentalo de nuevo\n");
  }
}

int comando(char entrada[100]){
  if(entrada[0]=='c'){
    if(entrada[1]=='a'){
      return 1;
    }else if(entrada[1]== 'd'){
      return 6;
    }else{
      return -1;
    }
  }else if(entrada[0]=='e'){
    if(entrada[1]=='a'){
      return 2;
    }else{
        return -1;
    }
  }else if(entrada[0]=='b'){
    if(entrada[1]=='a'){
      return 3;
    }else if(entrada[1]== 'd'){
      return 7;
    }else{
      return -1;
    }
  }else if(entrada[0]=='m'){
    if(entrada[1]=='a'){
      return 4;
    }else if(entrada[1]== 'd'){
      return 8;
    }else{
      return -1;
    }
  }else if(entrada[0]=='r'){
    if(entrada[1]=='a'){
      return 5;
    }else if(entrada[1]== 'd'){
      return 9;
    }else{
      return -1;
    }
  }else if(entrada[0] == 's'){
    return 10;
  }else{
    return -1;
  }
}


int main(void) {
  int j;
    char entrada[100];
    char nombre[100] = "";
    char ruta[100] = "";
    char nombre2[100] = "";
    char datos[3][100];

    printf("\n           .:Menu:.\n");
    printf("c-----crear        e-----escribir\n");
    printf("b-----borrar       m-----mostrar\n");
    printf("r-----renombrar\n");
    printf("a-----Archivo      d-----directorio\n");
    printf("\nEjemplo crear archivo:\n->ca\n");


    do {
      printf("\n\n->");
      setbuf(stdin,NULL);
      gets(entrada);
      setbuf(stdin,NULL);
      j = 0;
//      printf("Entrada:  \"%s\"\n", entrada);

      int i=0;
      //char cadena[] = "Hola,mundo,soy,una,cadena,separa,por,comas"
      char delimitador[] = " ";
      char *token = strtok(entrada, delimitador);
      if(token != NULL){
         while(token != NULL){
             // Sólo en la primera pasamos la cadena; en las siguientes pasamos NULL
             //printf("Token: %s", token);
             strcpy(datos[i++],token);
             token = strtok(NULL, delimitador);
         }
     }

      /*for (int i = 0; i < 4; i++) {
        printf("%s-_-_ ", datos[i]);
      }*/

        switch (comando(datos[0])) {
            case 1:
              //Crear Archivo
              printf("CrearA\n");
                if(ChecaDatos(datos[1])){
                  crearArchivo(datos [1]);
                }else{
                  printf("ca /ruta/nombre.extension\n");
                }
            break;
            case 2:
              //Escribir archivo
              printf("EscribirA\n");
              if(ChecaDatos(datos[1])){
                escribirArchivo(datos[1]);
              }else{
                printf("ea /ruta/nombre.extension\n");
              }
            break;
            case 3:
              //Borrar archivo
              printf("BorrarA\n");
              if(ChecaDatos(datos[1])){
                borrarArchivo(datos[1]);
              }else{
                printf("ba /ruta/nombre.extension\n");
              }
            break;
            case 4:
              //Mostrar archivo
              printf("MostrarA\n");
              if(ChecaDatos(datos[1])){
                if(ChecaDatos(datos[2])){
                  mostrarArchivo(datos[1],atoi(datos[2]));//si no mete numeros, va a ser un problema
                }else{
                  mostrarArchivoCompleto(datos[1]);
                }
              }else{
                strcpy(datos[1], "./");
                mostrarArchivoCompleto(datos[1]);
              }
            break;
            case 5:
              //Renombrar archivo
              printf("RenombrarA\n");
              if(ChecaDatos(datos[1]) && ChecaDatos(datos[2]) ){
                renombrarArchivo(datos[1], datos[2]);
              }else{
                printf("ra /ruta/nombre nombreNuevo\n");
              }
            break;
            case 6:
              //Crear Directorio
              printf("CrearD\n");
              if(ChecaDatos(datos[1]) && ChecaDatos(datos[2])){
                crearDirectorio(datos[1],datos[2]);
              }else{
                printf("cd /ruta/ nombre\n");
              }
            break;
            case 7:
              //Borrar Directorio
              printf("BorrarD\n");
              if(ChecaDatos(datos[1])){
                borrarDirectorio(datos[1]);
              }else{
                printf("bd /ruta/\n");
              }
            break;
            case 8:
              //Mostrar Directorio
              printf("MostrarD\n");
              // md  // md ruta  // md -l  // md -l ruta
              if(ChecaDatos(datos[1])){ //Datos 1 no esta vacio
                if(strcmp(datos[1],"-l") == 0){
                  if(ChecaDatos(datos[2])){ // Datos 2  no esta vacio
                    mostrarDirectorioPro(datos[2]);
                  }else{ //Esta vacio
                    strcpy(datos[2], "./");
                    mostrarDirectorioPro(datos[2]);
                  }
                }else{
                  mostrarOtroDirectorio(datos[1]);
                }
              }else{ //Esta vacio
                strcpy(datos[1], "./");
                mostrarDirectorio(datos[1]);
              }
            break;
            case 9:
              //Renombrar Directorio
              printf("RenombrarD\n");
              if(ChecaDatos(datos[1]) && ChecaDatos(datos[2]) && ChecaDatos(datos[3])){
                //                   ruta     nombre   nuevoNombre
                renombrarDirectorio(datos[1], datos[2], datos[3]);
              }else{
                printf("rd ruta nombreFichero nuevoNombreFichero\n");
              }
            break;
            case 10:
            //Salir
              printf("Salir\n");
              exit(1);
            break;
            default: printf("\tHas ingresado algo mal, intentalo de nuevo!\n");
        }
    } while(1);
    exit(EXIT_SUCCESS);//return(0);
}
//gatitos
