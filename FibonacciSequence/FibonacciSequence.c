#include <stdio.h>

//Find the first 50 Fibonacci Sequence numbers
//where the first two integers are 0,1

void Fibsequence(unsigned long int a[], int size);

int main(int argc, char **argv)
{
	unsigned long int x[50]; //I can use this since  

	Fibsequence(x,50);
	
	return 0;
}

void Fibsequence(unsigned long int a[], int size)
{
	int i;
	a[0] = 0;
	a[1] = 1;

    printf("F0: %lu\n",a[0]);
    printf("F1: %lu\n",a[1]);	

	for(i=2; i<size; i++)
	{
		a[i] = a[i-1] + a[i-2];
        printf("F%i: ",i);
        printf("%lu\n",a[i]);
	}
	
}
