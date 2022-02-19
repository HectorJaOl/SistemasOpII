package practica3;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;



public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        MemoriaVirtual memoria = new MemoriaVirtual("10101001010101110", 1, 5, 4, 4);
        System.out.println(memoria.toString());
        File doc = new File("prueba.txt");
        Scanner obj = new Scanner(doc);

        while (obj.hasNextLine())
            System.out.println(obj.nextLine());
        
        /*
        int a = 10, opcion=0;
        switch (opcion) {
            case 1:
                if (true) {
                    
                }
                break;
            case 2:
                
                break;
            case 3:
                //c sale
                break;
            default:
                throw new AssertionError();
        }
        */
    }

    
/*  
    int DireccionVirtual;
    int TamanoPalabra, numeroBitsPagina1Nivel, numeroBitsPagina2Nivel, numeroBitsMarcoPagina;
    int bitsReferida, bitsModificada, bitsPermisos, bitPresenteAusente;

    //archivo tabla de pagina    
*/
    
}
