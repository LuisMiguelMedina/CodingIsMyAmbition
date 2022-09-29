public class WhatDoesItPrint_04 {
    //What does the following program print?

public static void main(String[] args) {
    int number = 3;
    modifyNumber(number);
    System.out.println(addAndReturn(number));
}

public static void modifyNumber(int number) {
    number = number + 2;
}

public static int addAndReturn(int number) {
    return number + 10;
}
}
