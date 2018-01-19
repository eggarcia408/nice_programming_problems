#include <iostream>
#include <iomanip>      // to print in hex
using namespace std;


/*
    This program will reverse the bytes( of an integer
    Ex:
        integer will contain 0x 12 34 56 78
        After reversing bytes will be 0x 78 56 34 12
*/

int reverse(int x);

int main(int argc, char **argv)
{
    int num = 0x12345678;

    cout<<"New Number with reversed bytes is: "<< hex << setw(4) << reverse(num) << endl;
    
    return 0;
}


int reverse(int x)
{
    int newNum = 0x00;
    int byteSize = sizeof(int); //store size, in bytes, of an int
    unsigned char *bytes = new unsigned char [byteSize]; //will store each byte of integer

    for (int i = 0; i<byteSize; i++)
        bytes[i] = (x >> (i * 8) ) & 0xFF;

    for (int i = 0; i<byteSize; i++)
        newNum = newNum | ((int)bytes[i] << (((byteSize*8) - 8) - (i*8)));

    /*
    //BELOW FOR DEBUGGING PURPOSES ONLY TO OUTPUT RESULTS IN HEX
    cout << showbase // show the 0x prefix
         << internal // fill between the prefix and the number
         << setfill('0'); // fill with 0s

    for (int i = 0; i < byteSize; i++)
        cout << hex << setw(4) << (int)bytes[i]<<endl;
    */

    delete [] bytes;

    return newNum;
}
