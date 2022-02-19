package practica3;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

    static int tamDV;

    public static int convertirBinarioDecimal(String binario) {
        int decimal = 0;
        //"10101"
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

    public static boolean isFileEmpty(File file) {
        return file.length() == 0;
    }

    public static void main(String[] args) throws FileNotFoundException {
        MemoriaVirtual memoria = new MemoriaVirtual("10101001010101110", 1, 5, 4, 4);
        System.out.println(memoria.toString());

        boolean datoCorrecto, cantidad;
        int tam;
        String tamanoPalabra, numeroBitsPagina1Nivel, numeroBitsPagina2Nivel, numeroBitsMarcoPagina, bitsReferida, bitsModificada, bitsPermisos, bitPresenteAusente;
        String direccionVirtual;
        //archivo tabla de pagina    

        Scanner leer = new Scanner(System.in);
        File doc = new File("prueba.txt");
        Scanner obj = new Scanner(doc);

//        // imprime el archivo
//        while (obj.hasNextLine())
//            System.out.println(obj.nextLine());
        int a = 10, opcion = 1;

        switch (opcion) {
            case 1: //Transformar direccion virtual en fisica
                if (isFileEmpty(doc)) {
                    System.err.println("no hay nada prro");
                } else {
                    do {
                        System.out.println("Escriba la direccion virtual en binario: ");
                        direccionVirtual = leer.nextLine();
                        datoCorrecto = direccionVirtual.matches("[0-1]*");
                    } while (!datoCorrecto);
                    System.out.println("direccionVirtual = " + direccionVirtual);
                    System.out.println("Decimal = " + convertirBinarioDecimal(direccionVirtual));

                    System.out.println("tamDV = " + tamDV);
                    tam = tamDV;

                    do {
                        System.out.println("Tamano de palabra: ");
                        tamanoPalabra = leer.nextLine();
                        datoCorrecto = tamanoPalabra.matches("[1-6]");
                    } while (!datoCorrecto);
                    System.out.println("tamanoPalabra = " + tamanoPalabra);
                    do {
                        do {
                            System.out.println("tamDV = " + tamDV);
                            System.out.println("Pagina de primer nivel\nDigite el numero de bits:");
                            numeroBitsPagina1Nivel = leer.nextLine();
                            datoCorrecto = numeroBitsPagina1Nivel.matches("[1-9]");
                        } while (!datoCorrecto);
                        tamDV -= Integer.valueOf(numeroBitsPagina1Nivel);
                        if (tamDV < 2) {
                            System.err.println("Te pasaste mijo!");
                            cantidad = false;
                            tamDV = tam;
                        } else {
                            cantidad = true;
                        }
                        System.out.println("numero de Bits de Pagina de 1er Nivel = " + numeroBitsPagina1Nivel);
                    } while (!cantidad);

                    do {
                        do {
                            System.out.println("tamDV = " + tamDV);
                            System.out.println("Pagina de segundo nivel\nDigite el numero de bits:");
                            numeroBitsPagina2Nivel = leer.nextLine();
                            datoCorrecto = numeroBitsPagina2Nivel.matches("[1-9]");
                        } while (!datoCorrecto);
                        System.out.println("numero de Bits de Pagina de 2do Nivel = " + numeroBitsPagina2Nivel);
                        tamDV -= Integer.valueOf(numeroBitsPagina2Nivel);
                        if (tamDV < 1) {
                            System.err.println("Te pasaste mijo!");
                            cantidad = false;
                            tamDV = tam;
                        } else {
                            cantidad = true;
                        }
                        System.out.println("numero de Bits de Pagina de 2do Nivel = " + numeroBitsPagina2Nivel);
                    } while (!cantidad);

                    do {
                        System.out.println("Marco de pagina\nDigite el numero de bits:");
                        numeroBitsMarcoPagina = leer.nextLine();
                        datoCorrecto = numeroBitsMarcoPagina.matches("[1-9]");
                    } while (!datoCorrecto);
                    System.out.println("numero de Bits del Marco de Pagina = " + numeroBitsMarcoPagina);
                }
                break;

            case 2: // Cambiar datos de entrada
                do {
                    System.out.println("Escriba la direccion virtual en binario: ");
                    direccionVirtual = leer.nextLine();
                    datoCorrecto = direccionVirtual.matches("[0-1]*");
                } while (!datoCorrecto);
                System.out.println("direccionVirtual = " + direccionVirtual);
                System.out.println("Decimal = " + convertirBinarioDecimal(direccionVirtual));

                System.out.println("tamDV = " + tamDV);
                tam = tamDV;

                do {
                    System.out.println("Tamano de palabra: ");
                    tamanoPalabra = leer.nextLine();
                    datoCorrecto = tamanoPalabra.matches("[1-6]");
                } while (!datoCorrecto);
                System.out.println("tamanoPalabra = " + tamanoPalabra);
                do {
                    do {
                        System.out.println("tamDV = " + tamDV);
                        System.out.println("Pagina de primer nivel\nDigite el numero de bits:");
                        numeroBitsPagina1Nivel = leer.nextLine();
                        datoCorrecto = numeroBitsPagina1Nivel.matches("[1-9]");
                    } while (!datoCorrecto);
                    tamDV -= Integer.valueOf(numeroBitsPagina1Nivel);
                    if (tamDV < 2) {
                        System.err.println("Te pasaste mijo!");
                        cantidad = false;
                        tamDV = tam;
                    } else {
                        cantidad = true;
                    }
                    System.out.println("numero de Bits de Pagina de 1er Nivel = " + numeroBitsPagina1Nivel);
                } while (!cantidad);

                do {
                    do {
                        System.out.println("tamDV = " + tamDV);
                        System.out.println("Pagina de segundo nivel\nDigite el numero de bits:");
                        numeroBitsPagina2Nivel = leer.nextLine();
                        datoCorrecto = numeroBitsPagina2Nivel.matches("[1-9]");
                    } while (!datoCorrecto);
                    System.out.println("numero de Bits de Pagina de 2do Nivel = " + numeroBitsPagina2Nivel);
                    tamDV -= Integer.valueOf(numeroBitsPagina2Nivel);
                    if (tamDV < 1) {
                        System.err.println("Te pasaste mijo!");
                        cantidad = false;
                        tamDV = tam;
                    } else {
                        cantidad = true;
                    }
                    System.out.println("numero de Bits de Pagina de 2do Nivel = " + numeroBitsPagina2Nivel);
                } while (!cantidad);

                do {
                    System.out.println("Marco de pagina\nDigite el numero de bits:");
                    numeroBitsMarcoPagina = leer.nextLine();
                    datoCorrecto = numeroBitsMarcoPagina.matches("[1-9]");
                } while (!datoCorrecto);
                System.out.println("numero de Bits del Marco de Pagina = " + numeroBitsMarcoPagina);

                break;
            case 3: //Salir9
                break;
            default:
                throw new AssertionError();
        }

    }

}
