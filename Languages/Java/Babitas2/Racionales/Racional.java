package Languages.Java.Babitas2.Racionales;

public class Racional implements Comparable<Racional> {
    private int numerador;
    private int denominador;
    
    public Racional(int numerador, int denominador){
        this.numerador = numerador;
        if (denominador != 0) {
            this.denominador = denominador;
        }else{
            this.denominador = 1;
        }
    }

    @Override
    public int compareTo(Racional racional) {
        int compare = (this.numerador+racional.denominador) - 
        (racional.numerador+this.denominador);

        return compare;
    }

    public String toString(){
            return numerador+"/"+denominador;
    }
}
