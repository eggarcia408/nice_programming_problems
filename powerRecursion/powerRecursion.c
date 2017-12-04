#include <stdio.h>

/*
    This program will compute the power of a number using recursion
    Base an exponent ust be real integers 
*/


float power(int base, int exponent);

int main(int argc, char **argv)
{
    int b,e;

    printf("Please enter the base: ");
    scanf("%i", &b);

    printf("Please enter the exponent: ");
    scanf("%i", &e);

    printf("The result of %i^%i is %0.5f\n",b,e,power(b,e));


    return 0;
}

float power(int base, int exponent)
{
    //if exponent is negative
    if (exponent < 0)
    {
        if (exponent == -1)
            return (float) 1/base;
        else
            return ((float) 1/base) * power(base, exponent + 1);
    }
    //if exponent is positive
    else if (exponent > 0)
    {
        if(exponent == 1)
            return (float) base;
        else
            return ((float) base) * power(base, exponent - 1);
    }
    //this else case is when exponent is 0
    else
        return (float) 1;

}

