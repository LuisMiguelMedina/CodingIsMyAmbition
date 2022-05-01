**Coding FUNDAMENTALS**

Luis Miguel Medina Avila - luis.mm2@hotmail.com

# The First C program

Lets breakdown this C sample:

``` C
#include <stdio.h>
main()
{
    printf("hello, world\n");
}
```

The statements of a function are enclosed in braces **{ }**. The function main contains only one statement:
``` C
     printf("hello, world\n");
```
A function is called by naming it, followed by a parenthesized list of arguments, so this calls the function printf with the argument **"hello, world\n"**. printf is a library function that prints output, in this case the string of characters between the quotes.

A sequence of characters in double quotes, like "hello, world\n", is called a **character string** or **string constant**. For the moment our only use of character strings will be as arguments for printf and other functions.

The sequence **\n** in the string is C notation for the newline character, which when printed advances the output to the left margin on the next line. If you leave out the **\n** you will find that there is no line advance after the output is printed. You must use **\n** to include a newline character in the printf argument; if you try something like:

``` C
printf("hello, world
");
```
the C compiler will produce an error message.

printf never supplies a newline character automatically, so several calls may be used to build up an output line in stages. Our first program could just as well have been written
```C
#include <stdio.h>
main()
{
    printf("hello, ");
    printf("world");
    printf("\n");
}
```
to produce identical output.

Notice that **\n** represents only a single character. An escape sequence like **\n** provides a general and extensible mechanism for representing hard-to-type or invisible characters. Among the others that C provides are:

    \t for tab, \b for backspace, \" for the double quote and \\ for the backslash itself. 