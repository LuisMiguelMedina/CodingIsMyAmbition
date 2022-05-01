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