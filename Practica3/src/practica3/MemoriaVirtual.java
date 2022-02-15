package practica3;

public class MemoriaVirtual {
    private String DireccionVirtual;
    private int TamanoPalabra;
    private int numeroBitsPagina1Nivel;
    private int numeroBitsPagina2Nivel;
    private int numeroBitsMarcoPagina;
    private int bitsReferida, bitsModificada, bitsPermisos, bitPresenteAusente;

    public MemoriaVirtual(String DireccionVirtual, int TamanoPalabra, int numeroBitsPagina1Nivel, int numeroBitsPagina2Nivel, int numeroBitsMarcoPagina) {
        this.DireccionVirtual = DireccionVirtual;
        this.TamanoPalabra = TamanoPalabra;
        this.numeroBitsPagina1Nivel = numeroBitsPagina1Nivel;
        this.numeroBitsPagina2Nivel = numeroBitsPagina2Nivel;
        this.numeroBitsMarcoPagina = numeroBitsMarcoPagina;
    }

    public String getDireccionVirtual() {
        return DireccionVirtual;
    }

    public void setDireccionVirtual(String DireccionVirtual) {
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
    public int numMarco(){
        int marcos = (int) Math.pow(2, numeroBitsMarcoPagina);
        marcos = marcos * tamPagina();
        return marcos;
    }
    public int tamPagina(){
        int desplazamiento;
        desplazamiento = DireccionVirtual.length() - (numeroBitsPagina1Nivel + numeroBitsPagina2Nivel);
        desplazamiento = desplazamiento/TamanoPalabra;
        return (int) Math.pow(2, desplazamiento);
    }

    public String convertirBytes(int bt){
        String cnt_size;
        double size_kb = bt /1024;
        double size_mb = bt / 1024;
        //double size_gb = bt / 1024 ;

        if(size_mb > 0){
            cnt_size = size_mb + " KB";
        }else{
            cnt_size = size_kb + " MB";
        }  
        return cnt_size;
    }

    @Override
    public String toString(){
        return "Tam Memoria Virtual: "+convertirBytes((numPagina()*tamPagina()))+"\nTam Memoria Fisica: "+convertirBytes(numMarco())+"\nTam de pagina: "+tamPagina() + " bytes";
    }
}
