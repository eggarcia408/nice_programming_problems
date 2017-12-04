#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
	This adds integer X to integer Y where all the digits of Integer Y 
	are stored in an array
	The integer X has less than or Equal digits than integer Y
*/

void inputIntegers(unsigned int **mynum_p, unsigned int numOfDigits_p);
void addinginteger(unsigned int **mynum_p,unsigned int num_p, unsigned int *numOfDigits_p);
void printresult(unsigned int *p, unsigned int numOfDigits_p);
void addingextradigit(unsigned **p, unsigned int *numOfDigits );

int main(int argc, char**argv)
{

	unsigned int *mynum;
	unsigned int numOfDigits;
	unsigned int addingInt;

	//this do while loop makes sure the number of digits of the integer is greater than 0	
	do
	{
		printf("Please enter the number of digits your integer will contain: ");	
		scanf("%i",&numOfDigits);
		
		if(numOfDigits<1)
			printf("Please make sure number of digits in integer is greater than 0\n\n");
	}
	while(numOfDigits<1);
	inputIntegers(&mynum,numOfDigits);

	//We are assuming the integer has less then or equal number of digits
	printf("Please enter you wish to add\n");
	printf("Please make the integer have less than or equal number if digits\n");
	scanf("%u",&addingInt);

	addinginteger(&mynum,addingInt,&numOfDigits);
	printresult(mynum,numOfDigits);

	return 0;
}






void inputIntegers(unsigned int **mynum_p, unsigned int numOfDigits_p)
{

	int i=0;

	char temp; //will be used to check if a digit is actually an integer

	*mynum_p = (int*) malloc(sizeof(unsigned int)*numOfDigits_p);

	printf("\nInput Digits starting from the right side first\n");
	while(i<numOfDigits_p)	
	{
		printf("Please input digit %i: ", i+1);
		scanf(" %c",&temp);
		printf("\n");
		

		//this will make sure user inpu is a valid digit
		if(!isdigit(temp)) 
		{
			printf("Please enter a valid digit\n\n");
			continue;
		}
		
		//this will assign digit in the character temp into the array
		(*mynum_p)[i] = temp - 48;

		i++;
	}
}



void addinginteger(unsigned int **mynum_p,unsigned int num_p, unsigned int *numOfDigits_p)
{

	int i = 0;
	int digit; 			//this will be used to extract each digit in the array
	int temp; 			//this will be used to extract each accumulating integer in the number
	int modd = 10;		//will be used in mod operation to get a specific integer in the 
	int carry = 0;  	//will be used for a carry


	do
	{
		digit = (*mynum_p)[i] + carry; //this will extract the integer in the nth place of array
		
		temp = (num_p % modd)/(modd/10); //thi will extract the integer in the nth place of your number

		//so if the digits are greater than 9, then I would have to worry about a carry on
		if( (digit + temp) >9 )
		{
			(*mynum_p)[i] = (digit+temp)%10;
			carry = 1;
		}
		else
		{
			(*mynum_p)[i] = digit + temp;
			carry = 0;
		}

		modd = modd * 10;
		i++;
	}while(i<(*numOfDigits_p));	

	//this is checking to see if last time you add has a carry
	//if it does, you must add another digit in front of array that hold the integer
	if(carry == 1)
	{
		addingextradigit(mynum_p, numOfDigits_p);
	}

}


void addingextradigit(unsigned **p, unsigned int *numOfDigits )
{	
	int *new;
	int i;	

	*numOfDigits = *numOfDigits + 1;
	new = (int*) malloc (sizeof(int) * (*numOfDigits) ); 

	for(i=0; i< (*numOfDigits)-1;i++)
	{
		new[i] = (*p)[i];
	}
	new[i] = 1;

	free(*p);
	*p = new;
	
}


void printresult(unsigned int *p, unsigned int numOfDigits_p)
{
	int i;
	
	for (i = numOfDigits_p - 1;i>=0;i--) 
	{
		printf("%u",p[i]);
	}

	printf("\n\n");
}





