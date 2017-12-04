#include <stdio.h>

// This will get the binary representation of a binary


void binaryrep(int num); //this prints out binary representation of integer

int main(int argc, char **argv)
{

	int num;


	printf("please input an integer greater than or equal to 0:  ");
	scanf("%i",&num);
	
	binaryrep(num);
	printf("\n");
}


void binaryrep(int num)
{
	if(num == 1)
		printf("1");
	else
	{
		binaryrep(num/2);
		printf("%i",num%2);
	}
}

