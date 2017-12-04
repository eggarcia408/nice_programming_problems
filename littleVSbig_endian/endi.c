//this programs determines if your computer is little or big endian

/*   32 bit(4byte) value:         x44332211

     little endian:                Large Adress    --      --    Small Adress
                                       44          33      22       11     
  
     big endian:                   Large Adress    --      --    Small Adress
                                       11          22      33       44 

    **NOTE**
        Keep in mind that an array is a continous block of memory such that
        &p[0]<&p[1] , &p[1]<&p[2], .... ,  &p[n-2]<&p[n-1] REGARDLESS of endianness
                            BUT
        for each location of an array element p[i], the data stored is stored according to
        its endianness

    **ANOTHER NOTE**
        A pointer always points to lowest memory address, regardless of endianness. So a char pointer
        points to LSB of data in little endian and MSB in big endian
*/

#include <stdio.h>

int main()
{

	unsigned int	x = 1;
	char *p;

/* Debugging only
    printf("%04x\n\n",x); //this just display intger x in hex
*/
	p	=	(char*)&x; // pointer p will point to first byte of integer x

	if( (unsigned int)*p == 1)
		printf("little endian\n");
	else
		printf("big endian\n");

    return 0;
}

