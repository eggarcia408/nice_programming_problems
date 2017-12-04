#include <stdio.h>

/*
    This program finds the sum of the digits in an integer
    Ex: 103679 --> 26
        12345  --> 15 
*/

int sum(int a);

int main(int argc, char **argv)
{
    int myNum;

    printf("Enter your integer value: ");
    scanf("%i", &myNum);

    //checking if user inputed a negative integer
    if (myNum < 0)
    {
        printf("User inputted a negative integer\n");
        printf("Using its positive integer...\n\n");
        myNum = myNum * -1;
    }
    printf("The sum of the digits in %i is: %i\n", myNum, sum(myNum));

    return 0;
}

int sum(int a)
{
    /*
        base case: when a == 0 because when a == 0,
                   you are done retrieving each digit in integer

        general case: a%10 will retrieve the last digit
                      a/10 will keep all the digits except the last digit
            
    */

    if (a == 0)
        return 0;
    else
        return (a%10) + sum(a/10); 

}
