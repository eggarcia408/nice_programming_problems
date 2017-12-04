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
*/

void recursionPrint(int maxStep_p, int incrementingStep_p);
int main(int argc, char **argv)
{
    int maxStep;                    // max step inputted by the user
    int incrementingStep    =  1;   // will be used to increment step

    cout<<"Enter Max Step of your Half Pyramid: ";
    cin>>maxStep;
    cout<<endl;
    
    recursionPrint(maxStep, incrementingStep);

    return 0;
}

void recursionPrint(int maxStep_p, int incrementingStep_p)
{
    if(incrementingStep_p <= maxStep_p)
    {
        for(int i = 1; i <= incrementingStep_p; i++)
            cout<<"*";
        cout<<endl;
        recursionPrint(maxStep_p, incrementingStep_p + 1);
    }
}
