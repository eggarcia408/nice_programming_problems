#include <stdio.h>

/*
    This program will find the largest integer in array using recursion
*/

int max(int *p, int size);

int main(int argc, char **argv)
{
    int nums[5];
    int i;

    for(i = 0; i<5; i++)
        scanf("%i",&nums[i]);


    printf("Largest integer in array is: %i\n", max(nums,5-1));

    return 0;
}


int max(int *p, int size)
{
    //when you reach the first element of array
    if(size == 0)
        return p[0];
    else
    {
        int potential_max;
        potential_max = max(p, size - 1);
        if (potential_max > p[size])
            return potential_max;
        else
            return p[size];
    }   

}
