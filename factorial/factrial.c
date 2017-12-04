#include <stdio.h>
#include <stdlib.h>

/*
    This program will calculate the factorial using recursion and 
    non-recursion calls
*/


int factorial_recursion(int a);
int factorial_nonrecursion(int a);

int main(int argc, char **argv)
{

    int number;

    printf("Please enter an integer: \n");
    scanf("%i", &number);

    if(number < 0)
    {
        printf("Entered a negatve integer\nExiting Program...\n");
        exit(0);
    }


    printf("THe factorial of %i using recursion is: %i\n", number,  factorial_recursion(number));
    printf("THe factorial of %i using recursion is: %i\n", number, factorial_nonrecursion(number));


    return 0;
}


int factorial_recursion(int a)
{

    if(a == 0)
        return 1;
    else
        return a * factorial_recursion(a - 1);
}

int factorial_nonrecursion(int a)
{

    int i, factorial;

    factorial = 1;

    for(i = a; i>0; i--)
        factorial = factorial * i;

    return factorial;
}
