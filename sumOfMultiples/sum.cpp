#include <iostream>

using namespace std;


/*
    This program will find the sum of all the multiples 
    of 3 or 5 below 1000
*/

int sum(int last_num);

int main(int argc, char **argv)
{
    int last = 1000;
    int sumOfMultiples;
    

    sumOfMultiples = sum(last);

    cout<<"Sum of the all multiples of 3 or 5 below "<<last<<" is: "<<sumOfMultiples<<endl;


    return 0;
}

int sum(int last_num)
{

    int sum = 0;
    for(int i = 3; i<last_num;i++)
    {
        if(i%3 == 0 || i%5 == 0)
            sum = sum + i;
    }
    return sum;
}
