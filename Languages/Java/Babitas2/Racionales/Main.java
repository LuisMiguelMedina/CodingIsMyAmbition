package Languages.Java.Babitas2.Racionales;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Racional[] array = new Racional[10];
    
        Racional racional = new Racional(2, 3);
    
        for (int i = 0; i < array.length; i++) {
            int numerador = (int) (Math.random()*100);
            int denominador = (int)((Math.random()*10)+1);
            array[i] = new Racional(numerador, denominador);
        }
    
        for(Racional r: array){
            System.out.println(r);
        }

        Arrays.sort(array);

        for(Racional r: array){
            System.out.println(r);
        }
    }
}
