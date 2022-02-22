package practica3;

import java.io.File;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Scanner;

public class Main {

    static int tamDV, arreglo[] = new int[10000], j = 0;
    private static Scanner sn = new Scanner(System.in);

    public static int convertirBinarioDecimal(String binario) {
        int decimal = 0;
        int size = binario.length() - 1;
        tamDV = binario.length();
        String[] split = binario.split("");
        for (String split1 : split) {
            if ("0".equals(split1)) {
                size--;
            } else {
                decimal += (int) Math.pow(2, size);
                //System.out.println("decimal = " + decimal);
                size--;
            }
            System.out.println(split1);
        }

        return decimal;
    }

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

    public static void guardarArchivo() throws IOException {
        String cadena;
        FileReader f = new FileReader("prueba.txt");
        BufferedReader b = new BufferedReader(f);
        j = 0;
        while ((cadena = b.readLine()) != null) {
            System.out.println(cadena);
            arreglo[j] = Integer.valueOf(cadena);
            j++;
        }
        b.close();
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        boolean datoCorrecto, cantidad;
        int tam;
        int opcion;
        int tamPalabra = 0, bitsPrimero = 0, bitsSegundo = 0, bitsMarco = 0;
        boolean datos = false;
        int n;

        String linea;
        int i, num;

        String direccionVirtual;
        //archivo tabla de pagina    
        Scanner leer = new Scanner(System.in);
        //System.out.print("Linea: ");
        //num = leer.nextInt();

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
                    guardarArchivo();

                    for (int k = 0; k < j; k++) {
                        System.out.println("arreglo[k] = " + arreglo[k]);
                    }
                case 3: //Salir9
                    break;
                default:
                    throw new AssertionError();
            }
        } while (opcion != 3);

    }

}
