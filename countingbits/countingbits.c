#include <stdio.h>


/* 
	This function will count how many 1 bits  an integer has
*/


int countingOnes(int x);

int main()
{
    int _n;

    printf("Please enter an integer\n");
    scanf("%i",&_n);

    printf("%li\n",sizeof(int));
    printf("Integer is: %i\n",_n);
    printf("Number of 1 bits in %i is %i \n",_n, countingOnes(_n));

    return 0;
}


int countingOnes(int x)
{

	int shifter = 0x01;
	int i;
	int numOfOnes = 0;

	for(i = 1; i<=( sizeof(int)*8 ); i++)
	{
		if( (shifter & x) != 0 )
			numOfOnes++;
	
		shifter = shifter <<  1;
	}		
	
	return numOfOnes;	
}
