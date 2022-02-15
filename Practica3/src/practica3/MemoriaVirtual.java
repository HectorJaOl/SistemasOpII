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

    public int getDireccionVirtual() {
        return DireccionVirtual;
    }

    public void setDireccionVirtual(int DireccionVirtual) {
        this.DireccionVirtual = DireccionVirtual;
    }

    public int getTamanoPalabra() {
        return TamanoPalabra;
    }

    public void setTamanoPalabra(int TamanoPalabra) {
        this.TamanoPalabra = TamanoPalabra;
    }

    public int getNumeroBitsPagina1Nivel() {
        return numeroBitsPagina1Nivel;
    }

    public void setNumeroBitsPagina1Nivel(int numeroBitsPagina1Nivel) {
        this.numeroBitsPagina1Nivel = numeroBitsPagina1Nivel;
    }

    public int getNumeroBitsPagina2Nivel() {
        return numeroBitsPagina2Nivel;
    }

    public void setNumeroBitsPagina2Nivel(int numeroBitsPagina2Nivel) {
        this.numeroBitsPagina2Nivel = numeroBitsPagina2Nivel;
    }

    public int getNumeroBitsMarcoPagina() {
        return numeroBitsMarcoPagina;
    }

    public void setNumeroBitsMarcoPagina(int numeroBitsMarcoPagina) {
        this.numeroBitsMarcoPagina = numeroBitsMarcoPagina;
    }

    public int getBitsReferida() {
        return bitsReferida;
    }

    public void setBitsReferida(int bitsReferida) {
        this.bitsReferida = bitsReferida;
    }

    public int getBitsModificada() {
        return bitsModificada;
    }

    public void setBitsModificada(int bitsModificada) {
        this.bitsModificada = bitsModificada;
    }

    public int getBitsPermisos() {
        return bitsPermisos;
    }

    public void setBitsPermisos(int bitsPermisos) {
        this.bitsPermisos = bitsPermisos;
    }

    public int getBitPresenteAusente() {
        return bitPresenteAusente;
    }

    public void setBitPresenteAusente(int bitPresenteAusente) {
        this.bitPresenteAusente = bitPresenteAusente;
    }
    
    public int numPagina(){
       return (int) Math.pow(2, numeroBitsPagina1Nivel) * (int) Math.pow(2, numeroBitsPagina2Nivel);
       
    }
    public int tamMemoriaFisica(){
        int marcos = (int) Math.pow(2, numeroBitsMarcoPagina);
        marcos = marcos * tamPagina();
        return marcos;
    }
    public int tamPagina(){
        int desplazamiento;
        desplazamiento = numeroBitsPagina1Nivel - numeroBitsPagina2Nivel;
        desplazamiento = desplazamiento/TamanoPalabra;
        return (int) Math.pow(2, desplazamiento);
    }

    public int convertirBytes(int bt){
        
        return 0;
    }

    @Override
    public String toString(){
        return "Tam Memoria Virtual: "+"Tam Memoria Fisica"+"Tam de pagina: "+tamPagina();
    }
}
