package practica3;

import java.io.File;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Scanner;

public class Main {

    protected static int arreglo[], j = 0;
    private static Scanner sn = new Scanner(System.in);

    public static int menu() {
        int op;

        System.out.println("----MENU---");
        System.out.println("1) Transformar dirección virtul en física");
        System.out.println("2) Cambiar datos de entrada");
        System.out.println("3) Salir");
        System.out.print("Opcion: ");
        op = sn.nextInt();
        return op;
    }

    public static void guardarArchivo(int tam) throws IOException {
        String cadena;
        FileReader f = new FileReader("prueba.txt");
        BufferedReader b = new BufferedReader(f);
        arreglo = new int[tam];
        j = 0;
        while ((cadena = b.readLine()) != null && j < tam) {
            arreglo[j] = Integer.valueOf(cadena);
            j++;
        }
        b.close();
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        boolean datoCorrecto;
        int opcion;
        int tamPalabra = 0, bitsPrimero = 0, bitsSegundo = 0, bitsMarco = 0;
        boolean datos = false;

        String direccionVirtual;    
        Scanner leer = new Scanner(System.in);
        
        do {
            opcion = menu();
            switch (opcion) {
                case 1: //Transformar direccion virtual en fisica
                    if (datos) {
                        do {
                            System.out.println("Dame la dirección virtual en binario");
                            direccionVirtual = leer.nextLine();
                            datoCorrecto = direccionVirtual.matches("[0-1]*");
                        } while (!datoCorrecto);
                        MemoriaVirtual memoria = new MemoriaVirtual(direccionVirtual, tamPalabra, bitsPrimero, bitsSegundo, bitsMarco);

                        System.out.println(memoria.toString());
                    } else {
                        System.out.println("\nAun no hay datos de entrada, proporcionalos\n");
                    }
                    break;

                case 2: // Cambiar datos de entrada
                    do {
                        System.out.print("Tamaño de palabra: ");
                        tamPalabra = sn.nextInt();
                    } while (tamPalabra < 1);

                    do {

                        System.out.println("Numero de bits Página de Primer Nivel: ");
                        bitsPrimero = sn.nextInt();

                        System.out.println("Numero de bits Página de Segundo Nivel: ");
                        bitsSegundo = sn.nextInt();

                        System.out.println("Numero de bits Marco de Página: ");
                        bitsMarco = sn.nextInt();

                    } while (bitsPrimero < 1 || bitsSegundo < 1 || bitsMarco < 1 || (bitsPrimero * bitsSegundo) <= bitsMarco);
                    datos = true;
                    guardarArchivo((int)Math.pow(2, bitsPrimero)*(int)Math.pow(2, bitsSegundo));
                case 3: //Salir9
                    break;
                default:
                    throw new AssertionError();
            }
        } while (opcion != 3);

    }

}
