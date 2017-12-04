#include <iostream>

using namespace std;


/*
    Problem Description:
        We need to print half of a pyrmaid

        Example:
            Sample input:  4
    
            Sample Output:
            
            *
            **
            ***
            ****
            ***
            **
            *
*/


void recursionPrintAscending(int maxStep_p, int incrementingStep_p);
/*
    recursionprintAscending prints out the ascending part of the pyramid
        Example:
            if pyramid is 5,  it would print out 
            *
            **
            ***
            ****
            *****
*/

void recursionPrintDescending(int maxStep_p);
/*
    recursionprintDescending prints out the descending part of the pyramid
        Example:
            if pyramid is 5,  it would print out 
            ****
            ***
            **
            *

        IMPORTANT: Notice that it first prints out 4 starts instead
                   of 5. This is because recursionPrintAsceding prints the 5 stars
                   in the end.
*/



int main(int argc, char **argv)
{
    int maxStep;                    // max step inputted by the user
    int incrementingStep    =  1;   // will be used to increment step

    cout<<"Enter Max Step of your Half Pyramid: ";
    cin>>maxStep;
    cout<<endl;
    
    recursionPrintAscending(maxStep, incrementingStep);
    recursionPrintDescending(maxStep - 1);

    return 0;
}

void recursionPrintAscending(int maxStep_p, int incrementingStep_p)
{
    if(incrementingStep_p <= maxStep_p)
    {
        for(int i = 1; i <= incrementingStep_p; i++)
            cout<<"*";

        cout<<endl;
        recursionPrintAscending(maxStep_p, incrementingStep_p + 1);
    }
}

void  recursionPrintDescending(int maxStep_p)
{
    if(maxStep_p >= 1)
    {
        for(int i = maxStep_p; i >= 1; i--)
            cout<<"*";
        cout<<endl;
        recursionPrintDescending(maxStep_p-1);
    }
}
