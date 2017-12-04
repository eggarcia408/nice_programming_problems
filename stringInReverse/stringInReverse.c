#include <stdio.h>
#include <stdlib.h>


void clean_stdin(void);

int main(int argc, char **argv)
{
    
    char         *string;
    char         *reversedString;
    unsigned int size;
    char         tempChar;
    int i,j;

    printf("Please enter size of string: ");
    scanf("%i",&size);
    clean_stdin();
    
    //added plus 1 to account for null character
    string          = (char*) malloc( (sizeof(char)*size) + 1 );
    reversedString  = (char*) malloc( (sizeof(char)*size) + 1 );

    printf("Please enter string: ");
    tempChar = getchar();


    //below while loop is to retrieve each character individualy
    //to store into array. Cant do simple scanf cause array is
    //a size chosen on runtime so wont be able to do scanf("%19s",string)
    //cause you dont know how many characters you should consume
    i = 0;
    while( tempChar != EOF  && i<size && tempChar !='\n')
    {
        string[i] = tempChar;
        i++;
        tempChar  = getchar();
    }    
    string[i] = '\0';
    printf("String entered was: %s\n",string);



    //at this point, i+1 hold the actual size of the array(including NUll),
    //which may or may not equal to the size chosen by the user at the 
    //beginning
    //Thats why I use i - 1 below because user may inputa string smaller
    //than the size that user inputted at the beginning
    
    j = i-1;
    i = 0;

    while(i<size && j>=0)
    {
        reversedString[i] = string[j];
        i++;
        j--;
    }
    reversedString[i] = '\0';
    printf("String in reversed order is: %s\n",reversedString);



    return 0;
}


void clean_stdin(void)
{
    char c;

    do
    {
        c = getchar();
    }
    while( c!='\n' &&  c!=EOF);    

}
