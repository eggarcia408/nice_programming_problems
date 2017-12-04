#include <stdio.h>
#include <stdlib.h>


/*
Context :

    Given a 6x6 2D Array, :

    1 1 1 0 0 0
    0 1 0 0 0 0
    1 1 1 0 0 0
    0 0 0 0 0 0
    0 0 0 0 0 0
    0 0 0 0 0 0

    We define an hourglass to be a subset of values with indices falling in
    this pattern in this  graphical representation:

    a b c
      d
    e f g
    There are 16  hourglasses in the 2d array , and an hourglass sum is the sum
    of an  hourglass' values.

    Task 

    Calculate the hourglass sum for every hourglass in , then print the maximum
    hourglass sum.

    Note: If you have already solved the Java domain's Java 2D Array challenge,
          you may wish to skip this challenge.

    Input Format

    There are  lines of input, where each line contains  space-separated
     integers describing 2D Array ; every value in  will be in the inclusive
    range of  to .

*/


int* computingSum(int myArray[][6]);
int findingLargestSum(int *myArray);


int main(){
    int arr[6][6];
    //int hourglassSum[16];
    int *hourglassSum;
    int counter = 0;
    int largestSum;
    int arr_i = 0;
    int arr_j = 0;    
    
    printf("Please start entering integers\n");
    printf("You will be inputting integers\n");
    for(arr_i = 0; arr_i < 6; arr_i++)
    {
       for(arr_j = 0; arr_j < 6; arr_j++)
       {   
          //entering the values for the 2d array 
          scanf("%d",&arr[arr_i][arr_j]);
       }
    }
    
    //computing sum of each hour glass and storing it in hourglassSum array
    hourglassSum = computingSum(arr); 
    
    for(counter = 0; counter < 16; counter++)
    {
        printf("Sum of hourglass %i: %i\n", counter + 1,hourglassSum[counter]);
    }
    
    printf("\n\nThe largest sum is: %i\n", findingLargestSum(hourglassSum));
    
    return 0;
}

//myarray dimentions arr myArray[6][6] (so 0-5 row and columns)
int* computingSum(int myArray[][6])
{
    int counter = 0;
    int *hourglassSum = (int *) malloc(sizeof(int)*16);
    int row = 0;
    int col = 0;

    for(row = 1; row < 5; row++)
    {
        for(col = 1; col < 5; col++)
        {
            hourglassSum[counter] = myArray[row][col] + myArray[row-1][col] + myArray[row-1][col-1] + myArray[row-1][col+1] + myArray[row+1][col] + myArray[row+1][col-1] + myArray[row+1][col+1];
            counter++;
        }
    } 
    //do not deallocate meory of hourglassSum since you will be returning the block of memory
    return hourglassSum;
}


//myArray has 16(0-15) elements
int findingLargestSum(int *myArray)
{
    int largestSum  = myArray[0];
    int i = 0;

    for (i = 1; i<16; i++)
    {
        if(largestSum < myArray[i])
           largestSum = myArray[i];
    }
    
    return largestSum;
}

