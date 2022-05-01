#include <stdio.h> //tells the compiler to include information about the standard input/output library

int main() //This is a function named main. Normally you are at liberty to give functions whatever names you like, but ``main'' is special - your program begins executing at the beginning of main.
{
    printf("Hello, World\n");
}

/*
#include <stdio.h>          include information about standard
library
main()                                  define a function called main
                                        that received no argument values
{                                       statements of main are enclosed in braces
    printf("hello, world\n");           main calls library function printf
}                                       to print this sequence of characters
                                        \n represents the newline character
*/