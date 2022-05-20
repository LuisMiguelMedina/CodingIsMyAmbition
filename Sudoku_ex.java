/*
Autor: Luis Alejandro Cruz Inzunza
Fecha: 20/02/2022 --- 24/02/2022
Descripcion: Crear un sudoku a partir de numeros aleatorios y verificarlo hasta estar correcto o contar sus errores.
*/
public class Sudoku_ex {

    final static int DIMENSION=9; //Constante de la dimension 9x9 del Sudoku
    static int error_filas=0, error_colum=0, error_grid=0; //Cantidad de errores que contara el sudoku
    public static void main(String[]args){
        int tablero[][] = new int[DIMENSION][DIMENSION];
        
        RellenarSudoku(tablero);
        VerificarSudoku(tablero);
        DemostrarSudoku(tablero);
        if(error_colum==0 && error_filas==0 && error_grid==0){
            System.out.printf("Este Sudoku es valido");
        }
        else{
            System.out.printf("Este Sudoku es Invalido, cuenta con errores");
        }
        
    }//final de main


    //Funcion para crear el sudoku 9x9 a partir del arreglo
    static void RellenarSudoku(int[][]arreglo){
        int filas=0, columnas=0;

        for (filas = 0; filas < DIMENSION; filas++){
            for (columnas = 0; columnas < DIMENSION; columnas++) {
        
                arreglo[filas][columnas]= (int) Math.floor(Math.random()*9+1);

            }//final de columnas
        }//final de filas
    }//final de RellenarSudoku


    //Zona de verificacion ára el Sudoku
    static void VerificarSudoku(int[][]tablero){
        boolean correcto= true;
        while(correcto==true){
            correcto=Filas(tablero,correcto);
            correcto=Columnas(tablero,correcto);     
            correcto=Grid_3x3(tablero,correcto);
            if (correcto=true){
                break;
            }
        }

    }//final de VerificarSudoku



    //Verificacion por filas
    static boolean Filas(int[][] tablero, boolean correcto){
        int filas=0, columnas=0,n=0,error=0;
        for(filas=0;filas < DIMENSION; filas++){
            for(columnas=0;columnas < DIMENSION; columnas++){
                error=0;
                while(n<9 && correcto==true){
                    if(n==columnas){
                        n=n+1;
                    }
                    if(n!=9){
                        if(tablero[filas][columnas]==tablero[filas][n]){
                            if(error==0){
                                error_filas=error_filas + 1;
                                correcto= false;
                            }
                            error=1;
                        }
                        n=n+1;
                    }
                    else{
                        break;
                    }
                    
                }//final de while
                n=0;
            }//final de columnas
        }//final del for de filas
        return correcto;
    }//final de funcion Filas



    //Verificacion por columnas
    static boolean Columnas(int[][] arreglo, boolean correcto){
        int filas=0, columnas=0,n=0,error=0;
        for(columnas=0;columnas < DIMENSION; columnas++){
            for(filas=0;filas < DIMENSION; filas++){
                error=0;
                while(n<9){
                    if(n==filas){
                        n=n+1;
                    }
                    if(n!=9){
                        if(arreglo[filas][columnas]==arreglo[n][columnas]){
                            if(error==0){
                                error_colum=error_colum + 1;
                                correcto= false;
                            }
                            error=error + 1;
                        }
                        n=n+1;
                    }
                    else{
                        break;
                    }
                    
                }//final de while
                n=0;
            }//final de for filas
        }//final del for de columnas
        return correcto;
    }//filas de Columnas



    //Verificacion por grid 3x3
    static boolean Grid_3x3(int[][] arreglo, boolean correcto){
        int filas=0, columnas=0, x=0,y=0;

        for (filas = 0; filas <= DIMENSION; filas++){
            for (columnas = 0; columnas <= DIMENSION; columnas++) {
                if(x<=2){

                    if(y<=2){
                        correcto=Grid_1(arreglo,x,y,correcto);
                    }//1er grid
                    if(y>2 && y<=5){
                        correcto=Grid_2(arreglo,x,y,correcto);
                    }//2do grid
                    if(y>5 && y<=8){
                        correcto=Grid_3(arreglo,x,y,correcto);
                    }//3er grid
                }//Termino de 1,2y3 grid
                if(x>2 && x<=5){
                    if(y<=2){
                        correcto=Grid_4(arreglo,x,y,correcto);
                    }//4to grid
                    if(y>2 && y<=5){
                        correcto=Grid_5(arreglo,x,y,correcto);
                    }//5to grid
                    if(y>5 && y<=8){
                        correcto=Grid_6(arreglo,x,y,correcto);
                    }//6to grid
                }//Termino de 4,5y6 grid
                if(x>5 && x<=8){
                    if(y<=2){
                        correcto=Grid_7(arreglo,x,y,correcto);
                    }//7mo grid
                    if(y>2 && y<=5){
                        correcto=Grid_8(arreglo,x,y,correcto);
                    }//8vo grid
                    if(y>5 && y<=8){
                        correcto=Grid_9(arreglo,x,y,correcto);
                    }//9no grid
                }//termino de 7,8y9 grid
                y=y+1;
            }//final de columnas
            x=x+1;
        }//final de filas
        return correcto;
    }//Final de Grid_3x3



    //Funcion para verificar el grid por apartado
    static boolean Grid_1(int[][]arreglo,int x, int y, boolean correcto){
        int error=0,n=0,filas=x,columnas=y,dimension=3;

        for(filas=x;filas <= dimension; filas++){
            for(columnas=y;columnas <= dimension; columnas++){
                n=0;
                error=0;
                while(n<3 && correcto==true){
                    if(n==columnas){
                        n=n+1;
                    }
                    if(n!=3){
                        if(arreglo[filas][columnas]==arreglo[filas][n]){
                            if(error==0){
                                error_grid = error_grid + 1;
                                correcto= false;
                                error=1;
                            }
                        }
                    }
                    else{
                        break;
                    }
                    n=n+1;
                    
                }//final de while
            }//final de columnas
        }//final del for de filas
        return correcto;
    }//Final de VeriGrid




    //Funcion para verificar el grid por apartado
    static boolean Grid_2(int[][]arreglo,int x, int y, boolean correcto){
        int error=0,n=0,filas=x,columnas=y,dimension=6;

        for(filas=x;filas <= dimension; filas++){
            for(columnas=y;columnas <= dimension; columnas++){
                n=0;
                error=0;
                while(n>=3 && n<6 && correcto==true){
                    if(n==columnas){
                        n=n+1;
                    }
                    if(n!=6){
                        if(arreglo[filas][columnas]==arreglo[filas][n]){
                            if(error==0){
                                error_grid = error_grid + 1;
                                correcto=false;
                                error=1;
                            }
                        }
                    }
                    else{
                        break;
                    }
                    n=n+1;
                    
                }//final de while
            }//final de columnas
        }//final del for de filas
        return correcto;
    }//Final de VeriGrid




    //Funcion para verificar el grid por apartado
    static boolean Grid_3(int[][]arreglo,int x, int y, boolean correcto){
        int error=0,n=0,filas=x,columnas=y,dimension=8;

        for(filas=x;filas <= dimension; filas++){
            for(columnas=y;columnas <= dimension; columnas++){
                n=0;
                error=0;
                while(n>6 && n<=8 && correcto==true){
                    if(n==columnas){
                        n=n+1;
                    }
                    if(n!=8){
                        if(arreglo[filas][columnas]==arreglo[filas][n]){
                            if(error==0){
                                error_grid = error_grid + 1;
                                correcto=false;
                                error=1;
                            }
                        }
                    }
                    else{
                        break;
                    }
                    n=n+1;
                    
                }//final de while
            }//final de columnas
        }//final del for de filas
        return correcto;
    }//Final de VeriGrid




    //Funcion para verificar el grid por apartado
    static boolean Grid_4(int[][]arreglo,int x, int y, boolean correcto){
        int error=0,n=0,s=3,columnas=y,filas=x,dimension_colum=3,dimension_filas=6;

        for(filas=x;filas <= dimension_filas; filas++){
            while(s>2 && s<6){
                for(columnas=y;columnas <= dimension_colum; columnas++){
                    n=0;
                    error=0;
                     while(n<=0 && correcto==true){
                        if(n==columnas){
                            n=n+1;
                        }
                        if(n!=3){
                            if(arreglo[filas][columnas]==arreglo[filas][n]){
                                if(error==0){
                                    error_grid = error_grid + 1;
                                    correcto=false;
                                    error=1;
                                }
                            }
                        }
                        else{
                            break;
                        }
                        n=n+1;
                    
                    }//final de while
                }//final de columnas
                s=s+1;
            }//final while de s
        }//final del for de filas
        return correcto;
    }//Final de Grid_4




    //Funcion para verificar el grid por apartado
    static boolean Grid_5(int[][]arreglo,int x, int y, boolean correcto){
        int error=0,n=0,s=3,columnas=y,filas=x,dimension_colum=6,dimension_filas=6;

        for(filas=x;filas <= dimension_filas; filas++){
            while(s>2 && s<6 && correcto==true){
                for(columnas=y;columnas <= dimension_colum; columnas++){
                    n=0;
                    error=0;
                    while(n>2 && n<6){
                        if(n==columnas){
                            n=n+1;
                        }
                        if(n!=6){
                            if(arreglo[filas][columnas]==arreglo[filas][n]){
                                if(error==0){
                                    error_grid = error_grid + 1;
                                    correcto= false;
                                    error=1;
                                }
                            }
                        }   
                         else{
                            break;
                        }
                        n=n+1;
                
                    }//final de while
                }//final de columnas
                s=s+1;
            }//final while de s
        }//final del for de filas
        return correcto;
    }//Final de Grid_5




    //Funcion para verificar el grid por apartado
    static boolean Grid_6(int[][]arreglo,int x, int y, boolean correcto){
        int error=0,n=0,s=3,columnas=y,filas=x,dimension_colum=8,dimension_filas=6;

        for(filas=x;filas <= dimension_filas; filas++){
            while(s>2 && s<6 && correcto==true){
            for(columnas=y;columnas <= dimension_colum; columnas++){
                n=0;
                error=0;
                while(n>5 && n<=8){
                    if(n==columnas){
                        n=n+1;
                    }
                    if(n!=8){
                        if(arreglo[filas][columnas]==arreglo[filas][n]){
                            if(error==0){
                                error_grid = error_grid + 1;
                                correcto=false;
                                error=1;
                     }
                    }
                }
                else{
                    break;
                }
                n=n+1;
            
                }//final de while
            }//final de columnas
            s=s+1;
         }//final while de s
        }//final del for de filas
        return correcto;
    }//Final de Grid_6


    

    //Funcion para verificar el grid por apartado
    static boolean Grid_7(int[][]arreglo,int x, int y,boolean correcto){
        int error=0,n=0,s=3,columnas=y,filas=x,dimension_colum=3,dimension_filas=8;

        for(filas=x;filas <= dimension_filas; filas++){
            while(s>5 && s<=8 && correcto==true){
            for(columnas=y;columnas <= dimension_colum; columnas++){
                n=0;
                error=0;
                while(n<3){
                    if(n==columnas){
                        n=n+1;
                    }
                    if(n!=3){
                        if(arreglo[filas][columnas]==arreglo[filas][n]){
                            if(error==0){
                                error_grid = error_grid + 1;
                                correcto=false;
                                error=1;
                     }
                    }
                }
                else{
                    break;
                }
                n=n+1;
            
                }//final de while
            }//final de columnas
            s=s+1;
         }//final while de s
        }//final del for de filas
        return correcto;
    }//Final de Grid_6




    //Funcion para verificar el grid por apartado
    static boolean Grid_8(int[][]arreglo,int x, int y, boolean correcto){
        int error=0,n=0,s=3,columnas=y,filas=x,dimension_colum=6,dimension_filas=8;

        for(filas=x;filas <= dimension_filas; filas++){
            while(s>5 && s<=8 && correcto==true){
            for(columnas=y;columnas <= dimension_colum; columnas++){
                n=0;
                error=0;
                while(n>=3 && n<6){
                    if(n==columnas){
                        n=n+1;
                    }
                    if(n!=6){
                        if(arreglo[filas][columnas]==arreglo[filas][n]){
                            if(error==0){
                                error_grid = error_grid + 1;
                                correcto=false;
                                error=1;
                     }
                    }
                }
                else{
                    break;
                }
                n=n+1;
            
                }//final de while
            }//final de columnas
            s=s+1;
         }//final while de s
        }//final del for de filas
        return correcto;
    }//Final de Grid_6




    //Funcion para verificar el grid por apartado
    static boolean Grid_9(int[][]arreglo,int x, int y,Boolean correcto){
        int error=0,n=0,s=3,columnas=y,filas=x,dimension_colum=8,dimension_filas=8;

        for(filas=x;filas <= dimension_filas; filas++){
            while(s>5 && s<=8){
                for(columnas=y;columnas <= dimension_colum; columnas++){
                    n=0;
                    error=0;
                    while(n>=6 && n<=8){
                        if(n==columnas){
                            n=n+1;
                        }
                        if(n!=8){
                            if(arreglo[filas][columnas]==arreglo[filas][n]){
                                if(error==0){
                                    error_grid = error_grid + 1;
                                    correcto=false;
                                    error=1;
                                }
                            }
                        }
                        else{
                            break;
                        }
                        n=n+1;
            
                    }//final de while
                }//final de columnas
                s=s+1;
            }//final while de s
        }//final del for de filas
        return correcto;
    }//Final de Grid_6



    //Mostramos nuestro Sudoku
    static void DemostrarSudoku(int[][]arreglo){
        int filas=0, columnas=0, x=0;

        for (filas = 1; filas <= DIMENSION; filas++){
            for (columnas = 1; columnas <= DIMENSION; columnas++) {
                if((columnas)%3==0){
                    System.out.print("(" + arreglo[filas-1][columnas-1] + ")");
                    System.out.print(" | ");//agregado de lineas horizontales
                }
                else{
                    System.out.print("(" + arreglo[filas-1][columnas-1] + ")");
                }
            }//final de columnas
            System.out.println();
            if((filas)%3==0){
                while(x<12){
                    x= x+1;
                    System.out.print(" - ");
                }
                System.out.println();
                x=0;
            }//final de agregado de lineas horizontales
        }//final de filas
    }//final de DemostrarSudoku
}//Final de class