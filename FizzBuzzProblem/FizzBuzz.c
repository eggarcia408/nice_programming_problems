#include <stdio.h>

/*  
    This is the classic Fizz Buzz Problem
    Print the numbers 1..100
    For multiples of 3, print "Fizz" instead of the number
    For multiples of 5, print "Buzz" instead of the number
    For multiples of 3 and 5, print "FizzBuzz" instead of the number

*/

int divByFive(int data); //returns 1 if it data is devisible by Five. Otherwise returns 0
int divByThree(int data); //returns 1 if data is divisible by Three. Otherwise returns 0

int main(int argc, int **argv)
{

    int i;
    
    for(i=1; i<=100; i++)
    {
        if(divByFive(i) == 1 && divByThree(i) == 1)
        {
            printf("Fizz Buzz\n");
        }
        else if(divByFive(i)==1)
        {
            printf("Buzz\n");
        }
        else if(divByThree(i))
        {
            printf("Fizz\n");
        }
        else
            printf("%i\n",i);    
    }

    return 0;
}
int divByFive(int data)
{
    if(data%5 == 0) //divisible by 5
        return 1;
    else
        return 0;
}

int divByThree(int data)
{
    if(data%3 == 0) //divisible by 3
        return 1;
    else
        return 0;
}

/*
    Ather Way for the FizzBuzz Problem is to not write functions(more effecient)
    And use the clever 5*3 to see if an integer is divisible by 15. Example is Below

    int main(int argc, int **argv)
    {

        int i;

        for(i=1; i<=100; i++)
        {
            if(i%(5*3)==0 )         // clever way to see if an integer is divisibe by 3 and 5
            {
                printf("Fizz Buzz\n");
            }
            else if(i%5==0)
            {
                printf("Buzz\n");
            }
            else if(i%3==0)
            {
                printf("Fizz\n");
            }
            else
                printf("%i\n",i);
        }
    
        return 0;
    }    
*/

