**Coding FUNDAMENTALS**

Luis Miguel Medina Avila - luis.mm2@hotmail.com

# Variables in C

We are going to analize the following code:
``` C
#include <stdio.h>

main()
{
int fahr, celsius;
int lower, upper, step;

lower = 0; 
upper = 300; 
step = 20; 
fahr = lower;

    while (fahr <= upper) 
    {
        celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```


## While Loop
The while loop operates as follows: The condition in parentheses is tested. If it is true (fahr is less than or equal to upper), the body of the loop (the three statements enclosed in braces) is executed. Then the condition is re-tested, and if true, the body is executed again. When the test becomes false (fahr exceeds upper) the loop ends, and execution continues at the statement that follows the loop. There are no further statements in this program, so it terminates

The body of a while can be one or more statements enclosed in braces, as in the temperature converter, or a single statement without braces, as in
``` C
while (i < j)
    i = 2 * i;
```

## Variables
The type int means that the variables listed are integers; by contrast with **float**, which means **floating point**, numbers that may have a fractional part. The range of both int and float
depends on the machine you are using; 16-bits ints, which lie between -32768 and +32767,are common, as are 32-bit ints. A **float** number is typically a 32-bit quantity, with at least six
significant digits and magnitude generally between about 10^-38 and 10^38.

C provides several other data types besides int and float, including:

| Other variables |                       |
|------|----------------------------------|
| char | character - a single byte        |
| short | short integer                   |
| long | long integer                     |
| double | double-precision floating point|

The size of these objects is also machine-dependent. There are also arrays, structures and unions of these basic types, pointers to them, and functions that return them.

## Printf() - Arguments

printf is a general-purpose output formatting function.

``` C
printf("%d\t%d\n", fahr, celsius);
```
In this code its first argument is a string of characters to be printed, with each % indicating where one of the other (second, third,
14
...) arguments is to be substituted, and in what form it is to be printed. For instance, **%d** specifies an integer argument, so the statement causes the values of the two integers fahr and celsius to be printed, with a tab (\t) between them.

Each % construction in the first argument of **printf** is paired with the corresponding second argument, third argument, etc.; they must match up properly by number and type, or you will
get wrong answers

There are a couple of problems with the temperature conversion program. The simpler one is that the output isn't very pretty because the numbers are not right-justified. That's easy to fix; if we augment each **%d** in the printf statement with a width, the numbers printed will be right-justified in their fields. For instance, we might say

``` C
printf("%3d %6d\n", fahr, celsius);
```
to print the first number of each line in a field three digits wide, and the second in a field six digits wide, like this:

|  |          |
|--|----------|
|0 |ㅤ ㅤㅤ-17|
|40|ㅤ  ㅤㅤ-6|
|60|ㅤ  ㅤㅤ15|
|80|ㅤㅤ  ㅤ26|
|100|ㅤㅤ ㅤ37|
|...|ㅤㅤㅤ...|

## Notes

* ### **Some float-point rules in C:**
  If an arithmetic operator has integer operands, an integer operation is performed. If an arithmetic operator has one floating-point operand and one integer operand, however, the integer will be converted to floating point before the operation is done.

* ### **Some printf() rules in C:**
    The printf conversion specification %3.0f says that a floating-point number (here fahr) is to be printed at least three characters wide, with no decimal point and no fraction digits. %6.1f describes another number (celsius) that is to be printed at least six characters wide, with 1 digit after the decimal point. The output looks like this:
    
    | |     |
    |-|-----|
    |0|-17.8|
    |20|-6.7|
    |40| 4.4|
    |...|   |

    Among others, printf also recognizes **%o** for octal, **%x** for hexadecimal, **%c** for character, **%s** for character string and **%%** for itself.