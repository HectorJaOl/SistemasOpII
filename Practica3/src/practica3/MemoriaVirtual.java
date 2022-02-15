package practica3;

public class MemoriaVirtual {
    private int DireccionVirtual;
    private int TamanoPalabra;
    private int numeroBitsPagina1Nivel;
    private int numeroBitsPagina2Nivel;
    private int numeroBitsMarcoPagina;
    private int bitsReferida, bitsModificada, bitsPermisos, bitPresenteAusente;

    public MemoriaVirtual(int DireccionVirtual, int TamanoPalabra, int numeroBitsPagina1Nivel, int numeroBitsPagina2Nivel, int numeroBitsMarcoPagina) {
        this.DireccionVirtual = DireccionVirtual;
        this.TamanoPalabra = TamanoPalabra;
        this.numeroBitsPagina1Nivel = numeroBitsPagina1Nivel;
        this.numeroBitsPagina2Nivel = numeroBitsPagina2Nivel;
        this.numeroBitsMarcoPagina = numeroBitsMarcoPagina;
    }
    
    
}
