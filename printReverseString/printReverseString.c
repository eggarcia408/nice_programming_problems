#include <stdio.h>
#include <string.h>
#include <stdlib.h>


    /*  
        Prints an array of a defined size in reverse order
        without storing the value of c string
    */


int main(int argc, char **argv)
{

    char a[25];
    size_t size;
    int i;

    printf("Please enter a string with less than 25 characters\n");
    scanf("%24s",a);

    //returns size of c string in the array not including the null character
    size = strlen(a);

    for(i = size -1; i>=0; i--)
    {
        printf("%c",a[i]);
    }

    printf("\n"); 
    return 0;
} 

