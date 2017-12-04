#include <stdio.h>





int main(int argc, char *argv[])
{

	unsigned int x[2];
	unsigned char *p;
	int size = 0;

	x[0] = 0;
	x[1] = 1;

	printf("Size (in bytes) of an integer is: %li\n\n", sizeof(int));

	p = (unsigned char*)&x[0];
	
	while ((unsigned int)*p != 1)
	{
		size = size + 1;
		p=p+1;
	} 	
	
	printf("Size (in bytes) of an integer I calculated is: %u\n\n", size);

	return 0;
}
