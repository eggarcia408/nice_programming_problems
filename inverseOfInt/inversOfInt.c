#include <stdio.h>        
        
        
/*
    so you are trying to invert the bits of an integer between 0<N<=1000        
    this mean the max integer can be 1000, which is 0000 0011 1110 1000 in binary       
    so I have to worry about the least significant 2 bytes          
    invert in such a way such that the following:       
        example 1:      
                    integer is 5 = 101      
                    inverse is 010, which is 2 in decimal       
        
        example 2:      
                    integer is 50 = 110010 in binary        
                    inverse is 001101, which is 13      
        
        example 2:      
                    integer is 100 = 1100100 in binary      
                    inverse is 0011011, which is  27        
        
    so we must disregard all leading bits and focus on the ones that count      
                            
*/        
        
        
int toBin(int x);     
        
int main(int argc, char **argv)        
{     
    int res;        
    int _n;     
            
    printf("Please enter an integer\n");        
    scanf("%i",&_n);        
    printf("Integer in hex is : %04x\n",_n);          
    res = toBin(_n);        
    printf("result in: hex = 0x%04x    integer  = %i\n",res,res);     
            
    return 0;     
}     
        
        
int toBin(int x)      
{     
    //so condition is that 0<N<=1000        
    //this means that 1000 = 0000 0011 1110 1000 in binary      
    //so I will disregard all leading bytes. SO I will only focuse on the least significant two bytes of an N byte
    //integer      
            
    int shifter = 0x01; //This mask will be used to test if each bit is one or not      
    int i;      
    unsigned int position = 0;      
            
        
    //below is to find the bit position(starting from 1) where the last 1 appears at(from right to left) in the integer     
            
    for(i = 1;i<=16;i++) //up to 16 cause thats the last bit where Im am focusing at        
    {       
        
          /* Beloe is for debuggin purposes only        
            
             printf("for i = %i\n",i);       
             printf("x:       %04x\n",x);        
             printf("shifter: %04x\n",shifter);      
          */        
                
        //below determines the bit position if the bit is 1       
        if( (shifter & x) > 0 )     
        {       
            position = i;       
        }       
        
          /* For debugging purposes only        
             printf("position is: %i\n\n",position);     
          */                
               
        //shifting maske one bit to the left      
        shifter =  shifter << 1;                
    }       
        
    printf("Postion where the last 1 is at is: %i\n",position);     
        
    i = ~x;                                  //inverse bits of x        
    i = i<< (sizeof(int) * 8) - position;    //after I do inverse, want to make all bits        
                                             //that appear after the last 1 bit turn to zero     
       
    i = i>>(sizeof(int) * 8) - position;     //I want to get my result integer          
           
            
    printf("------------------------------\n");     
    return i;       
 }
