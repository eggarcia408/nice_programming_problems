#include <stdio.h>
#include <stdlib.h>
/*
    This program will print array in a reverse
    order using recursion

*/

void reverseOrderRecursion(int start, int size, int *array);

int main(int argc, char **argv)
{
    int size;
    int *arr;   //pointer used for the integer array
    int i;

    do
    {
        printf("Please enter size of array\n");
        scanf("%i",&size);
        if(size<0)
            printf("Please enter an integer greater than or equal tp zero\n");
    }
    while(size<0);
    
    arr =(int*) malloc(sizeof(int) * size);

    for(i = 0; i < size; i++)
    {
        printf("Enter integer %i\n", i+1);
        scanf("%i",&arr[i]);
    }
    printf("\n\n");

    printf("Array entered is:\n");
    for(i = 0; i < size; i++)
    {
        printf("%i ",arr[i]);
    }
    printf("\n\n");

    printf("Array printed in reverse order is:\n");
    reverseOrderRecursion(0, size, arr);
    printf("\n");

    return 0;
}

void reverseOrderRecursion(int start, int size, int *array)
{
    if(start<size)
    {
        reverseOrderRecursion(start+1, size, array);
        printf("%i ", array[start]);
    }
}
