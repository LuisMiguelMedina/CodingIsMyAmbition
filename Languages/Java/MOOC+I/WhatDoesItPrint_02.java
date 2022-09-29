public class WhatDoesItPrint_02 {
    //What does the program below print?

    public static void main(String[] args) {
        int number = 10;
        modifyNumber(number);
        System.out.println(number);
    }
    
    public static void modifyNumber(int number) {
        number = number - 4;
    }
}
