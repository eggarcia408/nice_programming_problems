#include <stdio.h>
#include <stdlib.h>


void Quicksort(int *ptr, int i, int p); // ptr will be your array
                                        //i will be index of the first element of your list
                                        //p will be index value of your pivot

int Partition(int *ptr, int i, int p);  // ptr will be your array
                                        //i will be index of the first element of your list
                                        //p will be index value of your pivot


int main(int argc, char **argv)
{
    int *arr;
    int size;
    int i;

    printf("Please enter size of array: ");
    scanf("%i", &size);

    arr = (int*) malloc(sizeof(int)*size);

    for(i=0; i<size; i++)
    {
        printf("Please enter element %i: ",i+1);
        scanf("%i",&arr[i]);
    }

    printf("\n\n");

    printf("Unsorted Array is\n");
/*    for(i=0; i<size; i++)
    {
        printf("%i ",arr[i]);
    }
*/
    Quicksort(arr,0, size-1);

    printf("\n\nSorted array is\n");
    for(i=0; i<size; i++)
    {
        printf("%i ",arr[i]);
    }


    free(arr);

    return 0;
}

/*
    // ptr will be your array
    //i will be index of the first element of your list
    //p will be index value of your pivot    
*/

void Quicksort(int *ptr, int i, int p)
{
    int q;
    if(i<p)
    {
        q = Partition(ptr, i, p);  //does all the partition to create your sublists
        Quicksort(ptr, i, q-1);    //recursion call to lower sublist
        Quicksort(ptr, q+1, p);    //recursion call to upper sublist
    }
    //keep in mind that q returns the index location of the correctly placed pivot that was 
    //correctly placed in the Partition function
}

int Partition(int *ptr, int i, int p)
{
    int x = ptr[p]; // x will hold the value of your pivot which is last element
                    // of your sublist
    int y = i-1;    // y will always point to the last element of your lower sublist
    int j, temp;

    for(j = i; j < p; j++ ) // assign j with starting index of list
    {
        if(ptr[j]<= x)  //comparing element of array with pivot
                        //if this is true, increase y and swap a[j] with a[y]
        {
            y = y+1;
            temp = ptr[y];
            ptr[y] = ptr[j];
            ptr[j] = temp;
        }
    }
    
    temp = ptr[y+1];
    ptr[y+1] = ptr[p]; //swaps pivot to its correct location
    ptr[p] = temp;   
 
    return (y + 1); // returns position where pivot was correctly placed

}
